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
-  학습 알고리즘 인자들을 설정해 줍니다.
   - **Learning Gain** : 간단하게 학습율이라는 단위입니다. inputdata와 맞게 적당하게 설정해주어야 학습이 잘됩니다.
   - **Epoch** : 최대 학습 횟수입니다. 얼마나 학습할 것인지 미리 정해둡니다.
   - **W_Epoch** : 학습 중간중간에 격자화를 시키기 위해, 몇번째 학습횟수 마다 격자화할 것인지 정해둡니다.
 
### 4.4 EBP(Error Back Propagation) 알고리즘
</div>
</details>

## 5. 핵심 트러블 슈팅
## 6. 그 외 트러블 슈팅
## 7. 결과물
### inputdata : X
<img src="https://user-images.githubusercontent.com/84891209/178103473-278c2023-b53d-4495-8867-a521288e7635.png" width="400px" height="400px" title="입력 데이터 : inputdata_X" alt="입력 데이터 : inputdata_X"></img><img src="https://user-images.githubusercontent.com/84891209/178103586-9b488a72-bd08-499b-a0be-8088406b63a8.gif" width="400px" height="400px" title="학습 과정 및 결과_X" alt="학습 과정 및 결과_X"></img><br/>
### inputdata : Star
<img src="https://user-images.githubusercontent.com/84891209/178103578-1fb74ea7-f0e6-4c7a-9be3-9cfa357af961.png" width="400px" height="400px" title="입력 데이터 : inputdata_star" alt="입력 데이터 : inputdata_star"></img><img src="https://user-images.githubusercontent.com/84891209/178103590-790677c6-7232-4dd9-8fe7-f1c21c6ddbe4.gif" width="400px" height="400px" title="입력 데이터 : 학습 과정 및 결과_star" alt="입력 데이터 : 학습 과정 및 결과_star"></img><br/>

