# PS Retrospective Template

## 1) 문제 기본 정보
- 문제 이름: 12933 오리
- 난이도: Silver II
- 핵심 조건:
	- 입력 크기: N < 2500
	- 시간 제한: 2s
	- 메모리 제한: 512MB

## 2) 나의 풀이
- 날짜: 260401
- 풀이 횟수: 1
### 아이디어
- 접근 전략
```text
크기가 작아서 이중반복문도 충분함을 확인.
q u a c k마다 자신이 올바른 순서에 왔는지 확인. 아니면 possible=false;
quack 한 덩어리 완성되면 다음 q는 기존 stack에 push.
```
- 왜 이 방법을 먼저 떠올렸는지
```text
입력크기가 작아서 별도의 알고리즘 생각 안하고 그리디로 해결.
```

### 구현 포인트
- 사용한 자료구조/알고리즘: Greedy
- 시간복잡도: O(N^2)
- 코드에서 실수하기 쉬운 부분: -1이 되는 조건 검사
- 까다로웠던 제약 또는 edge case: quack순서가 맞아야 함. quack 미완성조각 있으면 안됨.

### 결과
- 제출 횟수: 3
- 제출 결과(AC/WA/TLE/MLE/RE): WA - WA - AC
- 틀린 원인: 미완성조각에 대한 검사 로직 없음
- 수정 내용: s.size()%5로 검사


## 3) 표준 풀이
### 핵심 아이디어
- 정석 접근
```text
q u a c k의 각 상태를 int cnt[5]에 업데이트
quack 한 덩어리 완성되면 cnt[4]-- 해서 최소 오리 유지
```
```C++
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    cin >> s;

    string quack = "quack";
    int cnt[5] = {0};
    int ans = 0;

    for (char c : s) {
        int idx = quack.find(c);
        
        if (idx == 0) { 
            if (cnt[4] > 0)
                cnt[4]--;
            else
                ans++; 
        
            cnt[0]++;
        } 
        else { 
            if (cnt[idx - 1] > 0) { 
                cnt[idx - 1]--;
                cnt[idx]++;
            }
            else{
                cout << -1;
                return 0;
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        if (cnt[i] > 0){
            cout << -1;
            return 0;
        }
    }

    if(ans == 0) cout << -1;
    else cout << ans;

}
```
### 구현 포인트
- 필수 자료구조/기법: Greedy
- 시간복잡도: O(N)
- 구현 시 주의점: -

### 나와 다른 점
- 발상 차이: 동일
- 구현 차이: 
```text
나: 알파벳마다 경우 나누고 또 일일이 set에 저장하면서 오버헤드 발생. 실수하기 쉬움.
각 iter마다 c가 자신이 들어갈 위치 찾기 위해 다시한번 완탐.

정석: int[5] 배열로 한번의 반복만에 상태 업데이트
quack을 미리 string으로 저장해두어서 int[5]배열과 idx통일. 계산에 용이.
```
- 성능 차이: O(N^2) VS O(N)


## 4) 회고
- 이번 문제에서 얻은 핵심 1가지: 상태 업데이트는 int배열만으로 충분한지 생각해보기
- 다음에 비슷한 문제를 보면 확인할 체크리스트:
	-
	-
	-
