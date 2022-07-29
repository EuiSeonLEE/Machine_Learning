# Machine_Learning project 요약
## 1. 목적
>Artificial Neural Networks(ANN)구조를 C언어를 통해 설계하여 Learning 알고리즘을 통해 2차원 영역을 학습하고
최적의 학습 결과물을 만들며 Machine Learing을 이해한다.


## 2. 제작기간 & 참여인원
- 2022년 05월 18일 ~ 06월 06일
- 개인 프로젝트
## 3. stack
### 사용 알고리즘
- Perseptron
- DeltaRule
- EBP(Error Back Propagation)
### 사용 언어 & 프로그램

- <img src="https://img.shields.io/badge/C-A8B9CC?style=flat-square&logo=C&logoColor=black"/></a> 
- <img src="https://img.shields.io/badge/MATLAB-A30701?style=flat-square&logo=MathWorks&logoColor=white"/></a>
- <img src="https://img.shields.io/badge/Visual Studio Code-007ACC?style=flat-square&logo=Visual Studio Code&logoColor=white"/></a> 

## 4. 핵심기능
이 프로그램의 **핵심 기능은 Nuerons 개수 조절 기능**입니다.<br/>
**#Define**으로 해당 layer 마다 Nuerons 들을 조절하며 학습을 진행할 수 있으며<br/>
학습시킬 inputdata의 **최적의 학습 속도와 학습 정확도**를 알 수 있습니다.<br/>

<details>
<summary>핵심 기능 설명 펼치기</summary>
<div markdown="1">  


### 4.1 구조
<br/>

![뉴런 구조 : Neurons_Structure](https://user-images.githubusercontent.com/84891209/178103580-ec3f6c60-2e9a-4e2e-9a44-46922ab5f37e.png)

### 4.2 플로우 차트
![FlowChart](https://user-images.githubusercontent.com/84891209/179398552-d9e61152-d855-4a8c-a724-5eec469203c5.png)

### 4.3 학습 알고리즘 인자 설정
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
   - **W_Epoch** : 학습 중간중간에 격자화를 시키기 위해, 몇번의 학습횟수 마다 격자화할 것인지 정해둡니다.
 
### 4.4 EBP(Error Back Propagation) 알고리즘
- **구조를 보면 Layer의 Neurons 사이에 연결된 선들이 보이는데, 이 선들에게는 가중치(Weight)가 존재합니다. 이 가중치(Weight)를 1번 학습 할 때 마다 Delta값으로 갱신해줍니다.**
1. Layer가 넘어갈 때 마다 해당 Layer의 각 Neuron들은 연결된 Neuron들과 가중치에게 영향을 받게 되는데, 이에 대한 결과 값을 u라고 정의한다. :pin:
2. 최종 Output Neuron들의 u들을 모두 더한 값을 최종 결과값 y로 정의한다.
3. y로 해당학습의 Error율을 구한다.
4. y와 미리 설정된 target값으로 계산하여 Output Neuron의 Delta값을 구한다.
5. 그 후, Input layer를 제외한 모든 Layer의 Neuron들의 Delta값을 구한다.
6. 모두 구한 Delta값으로 연결된 각 Neuron들의 가중치(Weight)를 갱신한다.
7. 1~6번 과정을 inputdata의 좌표값이 모두 계산되야 1 epoch(학습 횟수)이다.

### 4.5 Grid Test
- **해당 프로그램의 학습 진행 과정을 볼 수 있게 격자화(시각화)하여 관찰할 수 있습니다.**
1. 몇번의 epoch(학습 횟수) 마다 격자화할 것인지 **W_Epoch**라는 정해진 인자로 결정한다.
2. EBP 알고리즘으로 학습된 W를 갖고 y값을 도출하여 Threshold값으로 해당 좌표가 0과 1인지 판단한다.
3. 판단이 되면 해당 좌표를 cmd창에 표현하기 위해 **0 이면 "."**, **1 이면 "O"** 으로 출력한다.

### 4.6 Evolution Test 
- Artificial Neural Networks(ANN)구조는 Layer마다 각기다른 Neuron개수로 설정됩니다.
해당 inputdata가 어떤 설정값에 효율적으로 학습하는지 보기 위해 Evolution Data를 기록합니다.
</div>
</details>
 
## 5. 핵심 트러블 슈팅
### 5.1 학습 설정값 셋팅 문제
- 이 프로그램은 설정값을 갖고 학습을 시키고 설정된 ANN구조에따라 진행되는 학습 능률을 관찰하기 위해 개발했습니다.<br/>
그래서 **#Define** 혹은 **전역변수**으로 설정값을 설정하는 방법을 적용시켰습니다.
   <details>
   <summary style="font-Weight : bold; font-size : 15px; color : #E43914;">기존 코드</summary>
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

- 하지만 학습 능률을 파악하는데 설정값을 여러번 바꿔주며 관찰해야합니다.
- **#Define** 으로만 설정값을 적용시키면 다른 설정값으로 바꿔 학습을 진행 시킬 때 Source Code를 다시 컴파일 시켜야하는 번거로움이 생깁니다.
- 그래서 설정값을 'architecture.dat'와 'parameter.dat' File에 입력하여 1행에 전부 설정값을 입력한 후, 1행마다 학습을 진행합니다.<br/> 그리고 File의 마지막 행이 전부 학습할 때까지 학습을 지속시켰습니다.
  - **architecture.dat** : ANN학습구조의 값을 기록할 파일 (Inputlayer Neurons, Hiddenlayer Neurons, Outputlayer Neurons)
  - **parameter.dat** : 학습 parameter값 혹은 학습 결과값을 저장할 epoch값들을 기록할 파일 (Learning Gain, epoch, error저장 epoch, W_epoch)
   <details>
   <summary style="font-Weight : bold; font-size : 15px; color : #E43914;"> 개선된 코드 </summary>
   <div markdown="1">  

   
   ```c
   int InputNUM = 2;
   int OutputNUM = 1;
   int HLnum = 10;
   int  bias = 0;
   double ETA = 0.9;
   int Epoch = 0;
   int ErrCount, WeightCount;
   int HLneurons[10] = { 15, 15, 15, 15, 15, 15, 15, 15, 15, 15};
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

## 6. 그 외 트러블 슈팅
## 7. 결과물

### 7.1 inputdata : X
<img src="https://user-images.githubusercontent.com/84891209/178103473-278c2023-b53d-4495-8867-a521288e7635.png" width="400px" height="400px" title="입력 데이터 : inputdata_X" alt="입력 데이터 : inputdata_X"></img><img src="https://user-images.githubusercontent.com/84891209/178103586-9b488a72-bd08-499b-a0be-8088406b63a8.gif" width="400px" height="400px" title="학습 과정 및 결과_X" alt="학습 과정 및 결과_X"></img><br/>

### 7.2 inputdata : Star
<img src="https://user-images.githubusercontent.com/84891209/178103578-1fb74ea7-f0e6-4c7a-9be3-9cfa357af961.png" width="400px" height="400px" title="입력 데이터 : inputdata_star" alt="입력 데이터 : inputdata_star"></img><img src="https://user-images.githubusercontent.com/84891209/178103590-790677c6-7232-4dd9-8fe7-f1c21c6ddbe4.gif" width="400px" height="400px" title="입력 데이터 : 학습 과정 및 결과_star" alt="입력 데이터 : 학습 과정 및 결과_star"></img><br/>

