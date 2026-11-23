# PS Retrospective Template

## 1) 문제 기본 정보
- 문제 이름: 9009 피보나치
- 난이도: Silver I
- 핵심 조건:
	- 입력 크기: N < 10^9, T?
	- 시간 제한: 1s
	- 메모리 제한: 128MB

## 2) 나의 풀이
- 날짜: 260330
- 풀이 횟수: 1
### 아이디어
- 접근 전략
```text
피보나치 수열 미리 만들기. -> 정렬돼있음
lower_bound로 num보다 작은 수 중 가장 큰 수 찾고 내려가면서 큰 수만 선택
sum에 더하면서 합 계산, 선택된 수는 스택에 저장 후 출력. 

처음에 fibo만들때 for(int i=2; fibo[i]<1e9)로 했는데 계속 터짐..
그래서 조금씩 출력시켜보면서 1e9가 되는 개수 찾아감.
```
- 왜 이 방법을 먼저 떠올렸는지
```text
T의 범위가 안나와있어서 편하게 while문 돌려야겠다 생각
fibo개수가 46개밖에 안돼서 완탐 삽가능.
```

### 구현 포인트
- 사용한 자료구조/알고리즘: Greedy
- 시간복잡도: O(T)
- 코드에서 실수하기 쉬운 부분: -
- 까다로웠던 제약 또는 edge case: -

### 결과
- 제출 횟수: 2
- 제출 결과(AC/WA/TLE/MLE/RE): WA - AC
- 틀린 원인: fibo만들때 i<45로 함. 실수.
- 수정 내용: 45개 만드니까 됨.


## 3) 표준 풀이
### 핵심 아이디어
- 정석 접근
```c++
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 1부터 시작: 0은 합에 기여하지 않으므로 제외
    // 마지막 항이 10^9를 처음 넘을 때까지 생성 (센티널 역할)
    vector<int> fibo = {1, 2};
    while (fibo.back() < 1000000000) {
        fibo.push_back(fibo[fibo.size() - 1] + fibo[fibo.size() - 2]);
    }

    int t;
    cin >> t;

    while (t--) {
        int num;
        cin >> num;

        // 큰 수부터 그리디로 선택 (제켄도르프 표현)
        vector<int> res;
        for (int i = fibo.size() - 1; i >= 0; --i) {
            if (fibo[i] <= num) {
                res.push_back(fibo[i]);
                num -= fibo[i];
            }
        }

        // 선택은 내림차순, 출력은 오름차순
        for (int i = res.size() - 1; i >= 0; --i) {
            cout << res[i] << (i ? ' ' : '\n');
        }
    }
}
```

### 구현 포인트
- 필수 자료구조/기법: -
- 시간복잡도: 거의 동일
- 구현 시 주의점: -

### 나와 다른 점
- 발상 차이:
- 구현 차이: 
	- fibo배열이 작으므로 굳이 lower_bound사용 안함
	- 스택 쓸 필요없이 벡터에 넣고 출력은 반대로.
- 성능 차이: -


## 4) 회고
- 이번 문제에서 얻은 핵심 1가지:
- 다음에 비슷한 문제를 보면 확인할 체크리스트:
	-
	-
	-
