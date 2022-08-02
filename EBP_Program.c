#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>      //time()
#include<Windows.h>
#include<string.h>

#pragma warning(disable : 4996)
#pragma warning(disable : 4244)
int InputNUM = 2;
int OutputNUM = 1;
int HLnum = 10;
int  bias = 0;
double ETA = 0.9;
int Epoch = 0;
int ErrCount, WeightCount;
int HLneurons[10] = { 15, 15, 15, 15, 15, 15, 15, 15, 15, 15};
double HLw[10][15][15];
double w_in[10][15];
double w_out[15][2]; // hidden layer - output layer w
double w_bias[10][15]; //bias - hidden layer1 w
double w_out_bias[2]; //bias - hidden layer2 w, bias - output layer w

void append(char *dst, char c); //문자열 끝에 문자를 붙이기 위한 함수
char * make_filename(char filename[]); //파일이름을 만들기 위한 함수
int get_parameter(FILE* fd_arch, FILE* fd_para); //ANN구조와 학습 인자값을 결정하기 위한 함수
int get_inputdata(FILE* fd_in, double u_in[], double target[]); //
void evoluation_test(double * evaErr);
void EBP(double u_in[], double u[][15], double u_out[], double Delta[][15], double Delta_out[], double *E, double target[]);

int main()
{
	double x[10] = {0.0,}, t = 0;
	time_t current;
	struct tm* timer;
	
	clock_t start_total, end_total, start_part, end_part;
   float res_total, res_part;
   start_total = clock();

   FILE* fd_arch;
	FILE* fd_para;
   if ((fd_arch = fopen("architecture.dat", "r")) == NULL) //학습구조의 값을 기록할 파일
	{
		printf("can't find file \n"); // 읽지 못하면 에러
		return -1;
	}
   if ((fd_para = fopen("parameter.dat", "r")) == NULL) //LG, error저장 epoch, weight저장 epoch
	{
		printf("can't find file \n"); // 읽지 못하면 에러
		return -1;
	}
   while(get_parameter(fd_arch, fd_para) != 1){
         start_part = clock();
         printf("%d : %d : %d : %d : %d : %d : %d \n", InputNUM, HLnum, HLneurons[0], HLneurons[1], HLneurons[2], HLneurons[3], OutputNUM);
         printf("%lf : %d : %d : %d : %d 학습시작\n", ETA, Epoch, ErrCount, WeightCount, bias);
         char errdata[] = "errdata_";
         char outputdata[] = "outputdata_";
         char evaerrdata[] = "evaerrdata_";

         FILE* fd_out;
         FILE* fd_err;
         FILE* fd_evaerr;
         if ((fd_err = fopen(make_filename(errdata), "w")) == NULL) //Error의 값을 기록할 파일
         {
            printf("can't find file \n"); // 읽지 못하면 에러
            return -1;
         }
         if ((fd_out = fopen(make_filename(outputdata), "w")) == NULL) //디테일한 Error의 값을 기록할 파일
         {
            printf("can't find file \n"); // 읽지 못하면 에러
            return -1;
         }
         if ((fd_evaerr = fopen(make_filename(evaerrdata), "w")) == NULL) //Error의 값을 기록할 파일
         {
            printf("can't find file \n"); // 읽지 못하면 에러
         }
         double target[2] = { 0.0, };
         double E = 0.0;
         int cnt = 0;
         int outputnum = OutputNUM;
         srand(time(NULL));
         for (int a = 0; a < InputNUM; a++) {
            for (int b = 0; b < HLneurons[0]; b++) {
               w_in[a][b] = (double)(((rand() % 31) - 15.0) / 10.0);
               //printf("w_in:%d:%d = %lf\n",a,b, w_in[a][b]);
            }
         }
         srand(time(NULL));
         for (int a = 0; a < HLnum - 1; a++) {
            for (int b = 0; b < 15; b++) {
               for (int c = 0; c < 15; c++) {
                  HLw[a][b][c] = (double)(((rand() % 31) - 15.0) / 10.0);
                  //printf("HLw:%d:%d:%d = %lf\n", a, b, c, HLw[a][b][c]);
               }
            }
         }
         srand(time(NULL));
         for (int a = 0; a < 15; a++) {
            for (int b = 0; b < OutputNUM; b++) {
               w_out[a][b] = (double)(((rand() % 31) - 15.0) / 10.0);
               //printf("w_out:%d:%d = %lf\n", a, b, w_out[a][b]);
            }
         }
         srand(time(NULL));
         for (int a = 0; a < HLnum; a++) {
            for (int b = 0; b < 15; b++) {
               w_bias[a][b] = (double)(((rand() % 31) - 15.0) / 10.0);
               //printf("w_bias:%d:%d = %lf\n", a, b, w_bias[a][b]);
            }
         }
         srand(time(NULL));
         for (int a = 0; a < OutputNUM; a++) {
            w_out_bias[a] = (double)(((rand() % 31) - 15.0) / 10.0);
            //printf("w_out_bias:%d = %lf\n", a, w_out_bias[a]);
         }
         while (cnt < Epoch) {
               double u_in[10] = { 0.0, };
               double u[10][15] = { 0.0, }; //(hidden layer1)output U
               double u_out[2] = { 0.0, };//(hidden layer2)output U

               double Delta[10][15] = { 0.0, }; // (hidden layer1)delta
               double Delta_out[2] = { 0.0, };// (hidden layer2, output layer) delta
               double E = 0.0; //error
               double evaErr = 0.0; //evoluation error
               E = 0.0;
               //evaErr = 0.0;
               cnt++;
               //printf("epoch : %d\n", cnt);
               FILE* fd_in;
               if ((fd_in = fopen("X2_data.txt", "r")) == NULL){
                  printf("can't find file \n"); // 읽지 못하면 에러
                  return -1;
               }

               while (get_inputdata(fd_in, u_in, target) != 1) {
                  EBP(u_in, u, u_out, Delta, Delta_out, &E, target);
               }
               current = time(NULL);
               timer = localtime(&current);

               fprintf(fd_out, "%lf\n", E);
               fprintf(fd_err, "%d %lf %d:%d:%d:%d:%d:%d\n",cnt ,E ,timer->tm_year + 1900, timer->tm_mon + 1, timer->tm_mday, timer->tm_hour,timer->tm_min,timer->tm_sec);
               fclose(fd_in);

               if(cnt % ErrCount == 0) {
                  evoluation_test(&evaErr);
                  fprintf(fd_evaerr, "%lf\n", evaErr);
               }
            }
            fclose(fd_evaerr);
            fclose(fd_out);
            fclose(fd_err);
            end_part = clock();
            printf("종료\n해당 부분 학습시간 : %.3f\n",(float)(end_part - start_part)/CLOCKS_PER_SEC);
            printf("==========================\n");
      }   
      fclose(fd_arch);
      fclose(fd_para);
		/*if (cnt % 500 == 0) { //w의 변화 100번의 1번씩 cmd창에 격자화
		   for (double x2 = 3.0; x2 >= -3.0; x2 -= 0.1) {
			  printf("\n");
			  for (double x1 = -3.0; x1 <= 3.0; x1 += 0.1) {
				  double s1[10][15] = { 0.0, };
				  double s_out1[2] = { 0.0, };
				  double u_in1[10] = { 0.0, };
				  u_in1[0] = x1;
				  u_in1[1] = x2;
				  target[0] = t;

				  // 만약 HLnum = 4
				  // HLneurons[HLnum] = {2, 3, 4, 5} 라고 한다면
				  for (int a = 0; a < HLneurons[0]; a++) {
					  s1[0][a] += bias * w_bias[0][a]; //바이어스 2개만 더해짐
					  for (int b = 0; b < InputNUM; b++) {
						  s1[0][a] += u_in1[b] * w_in[b][a];
						  //printf("s%d:%d = %lf\n", a, b, s[0][a]);
					  }
					  u[0][a] = 1.0 / (1.0 + exp(-s1[0][a]));
					  //printf("u%d = %lf\n",a, u[0][a]);
				  }

				  for (int a = 0; a < HLnum - 1; a++) {
					  for (int b = 0; b < HLneurons[a + 1]; b++) {
						  s1[a + 1][b] += bias * w_bias[a + 1][b];
						  for (int c = 0; c < HLneurons[a]; c++) {
							  s1[a + 1][b] += HLw[a][b][c] * u[a][c];
							  //printf("s%d:%d = %lf\n", a + 1, a, s[a + 1][b]);
						  }
						  u[a + 1][b] = 1.0 / (1.0 + exp(-s1[a + 1][b]));
						  //printf("u%d = %lf\n", a+1, u[a+1][b]);

					  }
				  }

				  for (int a = 0; a < OutputNUM; a++) {
					  s_out1[a] += bias * w_out_bias[a];
					  for (int b = 0; b < HLneurons[HLnum - 1]; b++) {
						  s_out1[a] += w_out[b][a] * u[HLnum - 1][b];
						  //printf("s_out%d = %lf\n", a, s_out[a]);
					  }
					  u_out[a] = 1.0 / (1.0 + exp(-s_out1[a]));
				  }
				 if (u_out[OutputNUM-1] >= 0.5)printf("O ");
				 else printf(". ");
			  }
		   }
		   printf("\n");
		   Sleep(150);
		   system("cls"); //영상으로 제작할시 사용
		}*/
	
	end_total = clock();
   printf("총 학습 시간 : %.3f\n", (float)(end_total - start_total)/CLOCKS_PER_SEC);
}

char * make_filename(char filename[]){
   char str_HLn = 64 + HLnum; // ABCD...YZ
   char str_ETA = 48 + (int)(ETA * 10);//1234...9
   char str_bias = 48 + bias;

   append(filename, str_HLn);
   append(filename, str_ETA);
   append(filename, str_bias);
   strcat(filename,".txt");

   printf("파일이름2 : %s\n", filename);

   return filename;
}
void append(char *dst, char c) {
    char *p = dst;
    while (*p != '\0') p++; // 문자열 끝 탐색
    *p = c;
    *(p+1) = '\0'; 
}
int get_parameter(FILE* fd_arch, FILE* fd_para){
	if(fscanf(fd_arch, "%d ", &InputNUM) != EOF) {
      fscanf(fd_arch, "%d ", &HLnum);
		for(int a = 0; a < HLnum; a++){
			fscanf(fd_arch, "%d ", &HLneurons[a]);
		}
		fscanf(fd_arch, "%d\n", &OutputNUM);
      fscanf(fd_para, "%lf %d %d %d %d\n", &ETA, &Epoch, &ErrCount, &WeightCount, &bias);
      return 0;
   }
	else return 1;
}
int get_inputdata(FILE* fd_in, double u_in[], double target[]){
   if(fscanf(fd_in, "%lf ", &u_in[0]) != EOF) {
      for(int a = 1; a < InputNUM; a++){
         fscanf(fd_in, "%lf ", &u_in[a]);
      }
      for(int b = 0; b < OutputNUM - 1; b++){
         fscanf(fd_in, "%lf", &target[b]);
      }
      fscanf(fd_in, "%lf\n", &target[OutputNUM - 1]);
      return 0;
   }
   else return 1; 
}

void evoluation_test(double * evaErr){
   double u_in[10] = { 0.0, };
   double s[10][15] = { 0.0, };
	double s_out[2] = { 0.0, };
	double u[10][15] = { 0.0, }; //(hidden layer1)output U
	double u_out[2] = { 0.0, };//(hidden layer2)output U
   double target[2] = { 0.0, };
   //*evaErr = 0.0;
   
   FILE* fd_evain;
   if ((fd_evain = fopen("X2_evadata.txt", "r")) == NULL) //학습구조의 값을 기록할 파일
	{
		printf("can't find file \n"); // 읽지 못하면 에러
	}
   printf("evol_test함수 진입");
   
   
   while (get_inputdata(fd_evain, u_in, target) != 1) {
      // 만약 HLnum = 4
      // HLneurons[HLnum] = {2, 3, 4, 5} 라고 한다면
      for (int a = 0; a < HLneurons[0]; a++) {
         s[0][a] += bias * w_bias[0][a]; //바이어스 2개만 더해짐
         for (int b = 0; b < InputNUM; b++) {
            s[0][a] += u_in[b] * w_in[b][a];
            //printf("s%d:%d = %lf\n", a, b, s[0][a]);
         }
         u[0][a] = 1.0 / (1.0 + exp(-s[0][a]));
         //printf("u%d = %lf\n",a, u[0][a]);
      }

      for (int a = 0; a < HLnum - 1; a++) {
         for (int b = 0; b < HLneurons[a + 1]; b++) {
            s[a + 1][b] += bias * w_bias[a + 1][b];
            for (int c = 0; c < HLneurons[a]; c++) {
               s[a + 1][b] += HLw[a][b][c] * u[a][c];
               //printf("s%d:%d = %lf\n", a + 1, a, s[a + 1][b]);
            }
            u[a + 1][b] = 1.0 / (1.0 + exp(-s[a + 1][b]));
            //printf("u%d = %lf\n",a+1, u[a+1][b]);
         }
      }
      for (int a = 0; a < OutputNUM; a++) {
         s_out[a] += bias * w_out_bias[a];
         for (int b = 0; b < HLneurons[HLnum - 1]; b++) {
            s_out[a] += w_out[b][a] * u[HLnum - 1][b];
            //printf("s_out%d = %lf\n", a, s_out[a]);
         }
         u_out[a] = 1.0 / (1.0 + exp(-s_out[a]));
         //printf("u_out%d = %lf\n", a, u_out[a]);
      }
      /*========================E의 변화==========================*/
      if (OutputNUM == 1) {
         //evaErr += fabs(target[0] - u_out[0]);
         *evaErr += (((target[0] - u_out[0]) * (target[0] - u_out[0]))/2);
      }
      else if (OutputNUM == 2) {
         //evaErr += (fabs(target[0] - u_out[0]) + fabs(target[1] - u_out[1])) / 2;
         *evaErr += (((target[0] - u_out[0]) * (target[0] - u_out[0]) + (target[1] - u_out[1]) * (target[1] - u_out[1]))/2);
      }
   }
   fclose(fd_evain);
}
void EBP(double u_in[], double u[][15], double u_out[], double Delta[][15], double Delta_out[], double *E, double target[]){
      double s[10][15] = { 0.0, };
      double s_out[2] = { 0.0, };
      
      // 만약 HLnum = 4
      // HLneurons[HLnum] = {2, 3, 4, 5} 라고 한다면
      for (int a = 0; a < HLneurons[0]; a++) {
         s[0][a] += bias * w_bias[0][a]; //바이어스 2개만 더해짐
         for (int b = 0; b < InputNUM; b++) {
            s[0][a] += u_in[b] * w_in[b][a];
            //printf("s%d:%d = %lf\n", a, b, s[0][a]);
         }
         u[0][a] = 1.0 / (1.0 + exp(-s[0][a]));
         //printf("u%d = %lf\n",a, u[0][a]);
      }

      for (int a = 0; a < HLnum - 1; a++) {
         for (int b = 0; b < HLneurons[a + 1]; b++) {
            s[a + 1][b] += bias * w_bias[a + 1][b];
            for (int c = 0; c < HLneurons[a]; c++) {
               s[a + 1][b] += HLw[a][b][c] * u[a][c];
               //printf("s%d:%d = %lf\n", a + 1, a, s[a + 1][b]);
            }
            u[a + 1][b] = 1.0 / (1.0 + exp(-s[a + 1][b]));
            //printf("u%d = %lf\n",a+1, u[a+1][b]);
         }
      }

      for (int a = 0; a < OutputNUM; a++) {
         s_out[a] += bias * w_out_bias[a];
         for (int b = 0; b < HLneurons[HLnum - 1]; b++) {
            s_out[a] += w_out[b][a] * u[HLnum - 1][b];
            //printf("s_out%d = %lf\n", a, s_out[a]);
         }
         u_out[a] = 1.0 / (1.0 + exp(-s_out[a]));
         //printf("u_out%d = %lf\n", a, u_out[a]);
      }
      /*========================E의 변화==========================*/
      if (OutputNUM == 1) {
         //E += fabs(target[0] - u_out[0]);
         *E += (((target[0] - u_out[0]) * (target[0] - u_out[0]))/2);
      }
      else if (OutputNUM == 2) {
         //E += (fabs(target[0] - u_out[0]) + fabs(target[1] - u_out[1])) / 2;
         *E += (((target[0] - u_out[0]) * (target[0] - u_out[0]) + (target[1] - u_out[1]) * (target[1] - u_out[1]))/2);
      }
      /*========================Delta 구하기=========================*/
      for (int a = 0; a < OutputNUM; a++) {
         Delta_out[a] = u_out[a] * (1.0 - u_out[a]) * (target[a] - u_out[a]);
         //printf("Delata_out %d = %lf\n",a, Delta_out[a]);
      }


      for (int a = 0; a < HLneurons[HLnum - 1]; a++) {
         double sum = 0.0;
         for (int b = 0; b < OutputNUM; b++) {
            sum += w_out[a][b] * Delta_out[b];
         }
         Delta[HLnum - 1][a] = u[HLnum - 1][a] * (1.0 - u[HLnum - 1][a]) * sum;
         //printf("Delata %d:%d = %lf\n",HLnum-1,a, Delta[HLnum-1][a]);
      }

      for (int a = HLnum - 1; a > 0; a--) {
         for (int b = 0; b < HLneurons[a - 1]; b++) {
            double sum = 0.0;
            for (int c = 0; c < HLneurons[a]; c++) {
               sum += Delta[a][c] * HLw[a - 1][c][b];
            }
            Delta[a - 1][b] = u[a - 1][b] * (1.0 - u[a - 1][b]) * sum;
            //printf("Delata %d:%d = %lf\n",a-1,b, Delta[a-1][b]);
         }
      }
      /*========================w의 변화==========================*/
      for (int a = 0; a < InputNUM; a++) {
         for (int b = 0; b < HLneurons[0]; b++) {
            w_in[a][b] += u_in[a] * Delta[0][b] * ETA;
            //printf("w_in %d:%d = %lf\n", a, b, w_in[a][b]);
         }
      }
      for (int a = HLnum - 1; a > 0; a--) {
         for (int b = 0; b < HLneurons[a - 1]; b++) {
            for (int c = 0; c < HLneurons[a]; c++) {
               HLw[a - 1][c][b] += u[a - 1][b] * Delta[a][c] * ETA;
               //printf("HLw %d:%d:%d = %lf\n", a, b, c, HLw[a][b][c]);
            }
         }
      }
      for (int a = 0; a < HLneurons[HLnum - 1]; a++) {
         for (int b = 0; b < OutputNUM; b++) {
            w_out[a][b] += u[HLnum - 1][a] * Delta_out[b] * ETA;
            //printf("w_out %d:%d = %lf\n", a,b, w_out[a][b]);
         }
      }
      for (int a = HLnum - 1; a >= 0; a--) {
         for (int b = 0; b < HLneurons[a]; b++) {
            w_bias[a][b] += Delta[a][b] * bias * ETA;
            //printf("w_bias %d:%d = %lf\n", a, b, w_bias[a][b]);
         }
      }
      for (int a = 0; a < OutputNUM; a++) {
         w_out_bias[a] += Delta_out[a] * bias * ETA;
         //printf("w_out_bias %d = %lf\n", a, w_out_bias[a]);
      }
   }

