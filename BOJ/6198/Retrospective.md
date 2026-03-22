# PS Retrospective Template

## 1) 문제 기본 정보
- 문제 이름: 6198 옥상 정원 꾸미기
- 난이도: Gold V
- 핵심 조건:
	- 입력 크기: N<80000
	- 시간 제한: 1s
	- 메모리 제한: 128MB

## 2) 나의 풀이
- 날짜: 260322
- 풀이 횟수: 1
### 아이디어
- 접근 전략
```text
펄스 1주차. 
스택을 활용한 완탐으로 접근했으나 시간초과.
스택을 모노토닉 스택으로서 써야 했는데 걍 완탐을 해버림.
```
- 왜 이 방법을 먼저 떠올렸는지
```text
완탐이 제일 직관적이어서
```
-코드
```C++
#include<iostream>
#include <vector>
#include <stack>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v(n);
    for(int& i : v)
        cin >> i;

    stack<int> s;
    int ans = 0;
    for(int i=0; i<n-1; ++i){
        int j = i+1;
        s.push(i);
        while(j<n && v[s.top()] > v[j]){
            ans++;
            j++;
        }
        s.pop();
    }
    cout << ans;
}
```

### 구현 포인트
- 사용한 자료구조/알고리즘: Brute Force
- 시간복잡도: O(N^2)
- 코드에서 실수하기 쉬운 부분: 인덱스 범위
- 까다로웠던 제약 또는 edge case: -

### 결과
- 제출 횟수: 2
- 제출 결과(AC/WA/TLE/MLE/RE): WA(사실상 TLE) - AC
- 틀린 원인: 최악의 경우 시간 초과 발생
- 수정 내용: 접근법 변경


## 3) 표준 풀이
### 핵심 아이디어
- 정석 접근
```text
모노토닉 스택 사용.
관점을 '내가 볼 수 있는 건물의 수'에서 '나를 볼 수 있는 건물의 수'로 변경.
스택에 현재 입력 높이를 볼 수 있는 건물만 남기고 볼 수 없으면 pop.
각 iter마다 ans += stk.size()
```
-코드
```C++
#include<iostream>
#include <stack>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    stack<int> s;
    long long ans = 0;
    for(int i=0; i<n; ++i){
        int h;
        cin >> h;

        while(!s.empty() && s.top()<=h)
            s.pop();

        ans += s.size();
        s.push(h);
    }
    cout << ans;
}
```

### 구현 포인트
- 필수 자료구조/기법: Monotonic Stack
- 시간복잡도: O(N)
- 구현 시 주의점: -

### 나와 다른 점
- 발상 차이: '내가 볼 수 있는 건물의 수' -> '나를 볼 수 있는 건물의 수'
- 구현 차이: 모든 원소가 stack에 딱 한 번 push, pop 되며 전체 연산 2N.
- 성능 차이: O(N^2) -> O(N)


## 4) 회고
- 이번 문제에서 얻은 핵심 1가지: 선형 배열 탐색법 중 O(N)만에 되는 모노토닉 스택이 있다.
- 다음에 비슷한 문제를 보면 확인할 체크리스트: 모노토닉 스택 사용 문제 유형
	1. 선형 배열에서
		- 단방향으로 이동하며 특정 조건의 값 찾기
		- 기준값보다 큰/작은 원소의 개수 구하기
		- 어떤 값이 최소/최대로 유지되는 구간의 길이 구하기
	2. 이차원에서(1차원의 집합으로 분리하여 생각)
		- 가장 큰 '직사각형' 구하기(정사각형은 DP가 베스트)
		- 장애물을 피해 최대 넓이 구하기