# 📌 Machine_Learning
## 1. 목적
>**Artificial Neural Networks(ANN)구조**를 **C언어**를 통해 설계하여 Learning 알고리즘을 통해 2차원 영역을 학습하고
최적의 학습 결과물을 만들며 **Machine Learing을 이해합니다.**
<br/>

## 2. 제작기간 & 참여인원
- 2022년 05월 18일 ~ 06월 06일
- 개인 프로젝트
<br/>

## 3. stack
### 사용 알고리즘
- **Perseptron**
- **DeltaRule**
- **EBP(Error Back Propagation)**
### 사용 언어 & 프로그램

- <img src="https://img.shields.io/badge/C-A8B9CC?style=flat-square&logo=C&logoColor=black"/></a> 
- <img src="https://img.shields.io/badge/MATLAB-A30701?style=flat-square&logo=MathWorks&logoColor=white"/></a>
- <img src="https://img.shields.io/badge/Visual Studio Code-007ACC?style=flat-square&logo=Visual Studio Code&logoColor=white"/></a> 
<br/>

## 4. 핵심기능
이 프로그램의 **핵심 기능은 Artificial Neural Networks(ANN)구조에서 Error Back Propagation(EBP) 알고리즘으로 컴퓨터가 학습을 하는 기능**입니다.<br/>
**architecture.dat**과 **parameter.dat** 파일로 입력받아 해당 layer 마다 Nuerons 들을 조절하며 학습을 진행할 수 있으며<br/>
학습시킬 inputdata의 **최적의 학습 속도와 학습 정확도**를 알 수 있습니다.<br/>

<details>
<summary> :mag_right: 핵심 기능 설명 펼치기 </summary>
<div markdown="1">  


### 4.1 구조
<br/>

![뉴런 구조 : Neurons_Structure](https://user-images.githubusercontent.com/84891209/178103580-ec3f6c60-2e9a-4e2e-9a44-46922ab5f37e.png)

### 4.2 플로우 차트
![FlowChart](https://user-images.githubusercontent.com/84891209/179398552-d9e61152-d855-4a8c-a724-5eec469203c5.png)

### 4.3 학습 알고리즘 인자 설정 :pushpin:[코드 확인](https://github.com/EuiSeonLEE/Machine_Learning/blob/e0f799fd11437b1e4ee8273b52eb1b2f1f551720/EBP_Program.c#L192)
- 학습 알고리즘 인자를 설정하기 전, Artificial Neural Networks(ANN)을 구조적으로 설정 해주어야 합니다.
  -  **Hidden Layer 개수** : Hidden Layer는 1 ~ 10개 사이로 설정 가능합니다.
  -  **Hidden Neurons 개수** : Hidden Neurons는 1 ~ 15개 사이로 설정 가능합니다.
  -  **Input Neurons 개수** : Input Neurons는 1 ~ 10개 사이로 설정 가능합니다.
  -  **Output Neurons 개수** :  Output Neurons는 1 ~ 2개 사이로 설정 가능합니다.
  -  **Bias Neuron 존재 유무** : Bias Neurons을 사용할 것인지 정할 수 있습니다.
     -  Bias Neuron이 존재하게 된다면, sigmoid 함수에 의해 미분을 하며 학습을 할 수 있습니다. 즉, 논리식 中 XOR연산이 가능하게 되어 2차원 학습 연산을 완벽하게 수행할 수 있게 됩니다.
-  **학습 알고리즘 인자**들을 설정해 줍니다.
   - **Learning Gain** : 간단하게 학습율이라는 단위입니다. inputdata와 맞게 적당하게 설정해주어야 학습이 잘됩니다.
   - **Epoch** : 최대 학습 횟수입니다. 얼마나 학습할 것인지 미리 정해둡니다.
   - **W_Epoch** : 학습 중간중간에 격자화를 시키기 위해, 몇 번의 학습횟수 마다 격자화할 것인지 정해둡니다.
 
### 4.4 EBP(Error Back Propagation) 알고리즘 :pushpin:[코드 확인](https://github.com/EuiSeonLEE/Machine_Learning/blob/e0f799fd11437b1e4ee8273b52eb1b2f1f551720/EBP_Program.c#L280)
- **구조를 보면 Layer의 Neurons 사이에 연결된 선들이 보이는데, 이 선들에게는 가중치(Weight)가 존재합니다. 이 가중치(Weight)를 1번 학습 할 때 마다 Delta값으로 갱신해줍니다.**
1. Layer가 넘어갈 때 마다 해당 Layer의 각 Neuron들은 연결된 Neuron들과 가중치에게 영향을 받게 되는데, 이에 대한 결과 값을 u라고 정의한다.
2. 최종 Output Neuron들의 u들을 모두 더한 값을 최종 결과값 y로 정의한다.
3. y로 해당학습의 Error율을 구한다.
4. y와 미리 설정된 target값으로 계산하여 Output Neuron의 Delta값을 구한다.
5. 그 후, Input layer를 제외한 모든 Layer의 Neuron들의 Delta값을 구한다.
6. 모두 구한 Delta값으로 연결된 각 Neuron들의 가중치(Weight)를 갱신한다.
7. 1~6번 과정을 inputdata의 좌표값이 모두 계산되야 1 epoch(학습 횟수)이다.

### 4.5 Grid Test :pushpin:[코드 확인](https://github.com/EuiSeonLEE/Machine_Learning/blob/e0f799fd11437b1e4ee8273b52eb1b2f1f551720/EBP_Program.c#L384)
- **해당 프로그램의 학습 진행 과정을 볼 수 있게 격자화(시각화)하여 관찰할 수 있습니다.**
1. 몇번의 epoch(학습 횟수) 마다 격자화할 것인지 **W_Epoch**라는 정해진 인자로 결정한다.
2. EBP 알고리즘으로 학습된 W를 갖고 y값을 도출하여 Threshold값으로 해당 좌표가 0과 1인지 판단한다.
3. 판단이 되면 해당 좌표를 cmd창에 표현하기 위해 **0 이면 "."**, **1 이면 "O"** 으로 출력한다.

### 4.6 Evolution Test :pushpin:[코드 확인](https://github.com/EuiSeonLEE/Machine_Learning/blob/e0f799fd11437b1e4ee8273b52eb1b2f1f551720/EBP_Program.c#L218)
- Artificial Neural Networks(ANN)구조는 Layer마다 각기다른 Neuron개수로 설정됩니다.
해당 inputdata가 어떤 설정값에 효율적으로 학습하는지 보기 위해 Evolution Data를 기록합니다.
  #### MATLAB 시각화 :pushpin:[코드 확인](https://github.com/EuiSeonLEE/Machine_Learning/blob/d14519c798145f432ae16f1108d0fe888683962f/4%EB%B6%84%ED%95%A0_Learning_curve.m#L1)
  ![err_biasO](https://user-images.githubusercontent.com/84891209/184341330-6c18d2c5-f557-49d4-98f0-00d7bc024058.jpg)
  ![err_biasX](https://user-images.githubusercontent.com/84891209/184341369-ec584830-96dc-4547-b739-2445fb041f56.jpg)

  <br/>
</div>
</details>
<br/>

## 5. 핵심 트러블 슈팅
### 5.1 학습 설정값 셋팅 문제
- 이 프로그램은 설정값을 갖고 학습을 시키고 설정된 ANN구조에따라 진행되는 학습 능률을 관찰하기 위해 개발했습니다.<br/>
그래서 **#Define** 혹은 **전역변수**으로 설정값을 설정하는 방법을 적용시켰습니다.
   <details>
   <summary style="font-Weight : bold; font-size : 15px; color : #E43914;"> :confused: 기존 코드</summary>
   <div markdown="1">  

   ```c
   #define InputNUM 2
   #define OutputNUM 1
   #define hlnum 1
   #define Bias 0
   #define eta 0.9
   int HLneurons[10] = { 15, 15, 15, 15, 15, 15, 15, 15, 15, 15};
   double target[2] = { 0.0, };
   int ErrCount = 0, WeightCount = 0;
   ```
   </div>
   </details>
<br/>

- 하지만 학습 능률을 파악하는데 설정값을 여러번 바꿔주며 관찰해야합니다.
- **#Define** 으로만 설정값을 적용시키면 다른 설정값으로 바꿔 학습을 진행 시킬 때 Source Code를 **다시 컴파일 시켜야하는 번거로움**이 생깁니다.
- 그래서 설정값을 'architecture.dat'와 'parameter.dat' File에 입력하여 1행에 전부 설정값을 입력한 후, 1행마다 학습을 진행합니다.<br/> 그리고 File의 마지막 행이 전부 학습할 때까지 학습을 지속시켰습니다.
  - **architecture.dat** : ANN학습구조의 값을 기록할 파일 (Inputlayer Neurons, Hiddenlayer Neurons, Outputlayer Neurons)
  - **parameter.dat** : 학습 parameter값 혹은 학습 결과값을 저장할 epoch값들을 기록할 파일 (Learning Gain, epoch, error저장 epoch, W_epoch)
    
   <details>
   <summary style="font-Weight : bold; font-size : 15px; color : #E43914;"> :smile: 개선된 코드 </summary>
   <div markdown="1">  


   ```c
   int InputNUM = 0;
   int OutputNUM = 0;
   int HLnum = 0;
   int  bias = 0;
   double ETA = 0.0;
   int Epoch = 0;
   int ErrCount, WeightCount;
   int HLneurons[10] = {0, };
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
   
   ```
   </div>
   </details>
<br/>

## 6. 그 외 트러블 슈팅
<br/>
<details>
<summary>문자열 끝에 ASCII문자를 붙이는 문제</summary>
<div markdown="1">  

- 아무래도 **C언어**이다보니 문자열의 편의성이 떨어지는 편입니다.
- Test되는 여러 조건을 보기 위해 대표적인 조건으로 (Hiddenlayer개수, Learning Gain값, Bias 존재유무)를 file이름으로 구분 지었습니다. 
- 학습조건이 바뀔 때 마다 자동으로 파일이름도 다르게 이름을 저장시키기 위해 **문자열 처리**는 필수였습니다.
- 위 조건의 인자는 자료형 int의 영향을 받아 char로 표현을 하였고 ASCII코드의 영어대문자, 숫자를 갖고 인자값을 표현하였습니다.
```c
void append(char *dst, char c) {//문자열 끝에 문자를 붙이기 위한 함수
    char *p = dst;
    while (*p != '\0') p++; // 문자열 끝 탐색
    *p = c;
    *(p+1) = '\0'; 
}
char * make_filename(char filename[]){//file이름을 만들기 위한 함수
   char str_HLn = 64 + HLnum; // ABCD...YZ
   char str_ETA = 48 + (int)(ETA * 10);//1234...9
   char str_bias = 48 + bias; // 0 or 1

   append(filename, str_HLn);
   append(filename, str_ETA);
   append(filename, str_bias);
   strcat(filename,".txt");

   printf("파일이름2 : %s\n", filename);

   return filename;
}
```
</div>
</details>
<br/>
<details>
<summary>Inputdata를 file로 얻기 위한 문제</summary>
<div markdown="1">  

- cmd_Grid_test를 하기 위한 2차원 inputdata는 2개 밖에 존재하지 않지만
- 이 프로그램의 최대 inputdata개수는 10개입니다.
- architecture.dat 파일에서 inputdata 개수는 정해지고 이 개수대로 실제 inputdata 파일의 개수만큼 읽습니다.
- 이를 inputdata 파일이 전부 읽힐 때 까지 **while문으로 EBP알고리즘을 반복 학습**을 시킵니다.
```c
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
```

</div>
</details>
<br/>
<details>
<summary>2차원 학습 과정을 시각화</summary>
<div markdown="1"> 

- 2차원 학습 과정을 시각화하기 위해 학습 중간중간 학습 결과가 2차원 좌표의 영역을 구분시켜 우리가 원하는 영역대로 학습을 하고 있는지 관찰 할 수 있어야 합니다.
- 저는 cmd창에 **(x, y)좌표**를 **(-3.0 ~ 3.0, -3.0 ~ 3.0)** 영역만 **0.1칸 씩** 표현하였습니다.
- 각 좌표의 학습 결과값인 0과 1을 표현하였습니다.
  - **0 이면 '.'**
  - **1 이면 'O'**
```c
void cmd_Grid_test(double u[][15], double u_out[], double target[]){
   for (double x2 = 3.0; x2 >= -3.0; x2 -= 0.1) {
      printf("\n");
      for (double x1 = -3.0; x1 <= 3.0; x1 += 0.1) {
         double s1[10][15] = { 0.0, };
         double s_out1[2] = { 0.0, };
         double u_in1[10] = { 0.0, };
         u_in1[0] = x1;
         u_in1[1] = x2;
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
}
```
</div>
</details>
<br/>

## 7. 결과물

### 7.1 inputdata : X
<img src="https://user-images.githubusercontent.com/84891209/178103473-278c2023-b53d-4495-8867-a521288e7635.png" width="400px" height="400px" title="입력 데이터 : inputdata_X" alt="입력 데이터 : inputdata_X"></img><img src="https://user-images.githubusercontent.com/84891209/178103586-9b488a72-bd08-499b-a0be-8088406b63a8.gif" width="400px" height="400px" title="학습 과정 및 결과_X" alt="학습 과정 및 결과_X"></img><br/>

### 7.2 inputdata : Star
<img src="https://user-images.githubusercontent.com/84891209/178103578-1fb74ea7-f0e6-4c7a-9be3-9cfa357af961.png" width="400px" height="400px" title="입력 데이터 : inputdata_star" alt="입력 데이터 : inputdata_star"></img><img src="https://user-images.githubusercontent.com/84891209/178103590-790677c6-7232-4dd9-8fe7-f1c21c6ddbe4.gif" width="400px" height="400px" title="입력 데이터 : 학습 과정 및 결과_star" alt="입력 데이터 : 학습 과정 및 결과_star"></img><br/>

