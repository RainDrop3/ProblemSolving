# PS Retrospective Template

## 1) 문제 기본 정보
- 문제 이름: 2493 탑
- 난이도: Gold V
- 핵심 조건:
	- 입력 크기: N < 5*10^5
	- 시간 제한: 1.5s
	- 메모리 제한: 128MB

## 2) 나의 풀이
- 날짜: 260328
- 풀이 횟수: 1
### 아이디어
- 접근 전략
```text
모노톤 스택.
v[s.top()]이 현재값보다 작으면 pop.
처음엔 무조건 0인거 때문에 케이스 계속 나눠야 되는줄 앎.
근데 그럴 필요 없었음.
```
- 왜 이 방법을 먼저 떠올렸는지
```text
모노톤 스택이 알아서 다 해주는데 케이스 나눠야 된다 생각.
```
- 코드
```C++
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> v(n+1);
    v[0] = -1;
    for(int i=1; i<=n; ++i)
        cin >> v[i];

    stack<int> s;
    for(auto it=v.begin()+1; it!=v.end(); it++){
        const int idx = it - v.begin();
        while(!s.empty()){
            //s.top의 높이가 나보다 작으면 pop
            //크면 그대로 push
            if(*(it-1) > *it){
                s.push(idx - 1);
                break;
            }
            else if(v[s.top()] > *it){
                s.push(s.top());
                break;
            }
            else if(s.top() == 0){
                s.push(0);
                break;
            }
            else{
                s.push(0);
                break;
            }
        }
        if(s.empty())
            s.push(0);
    }
    
    stack<int> s2;
    while(!s.empty()){
        s2.push(s.top());
        s.pop();
    }
    while(!s2.empty()){
        cout << s2.top() << " ";
        s2.pop();
    }
}
```

### 구현 포인트
- 사용한 자료구조/알고리즘: Monotonic Stack
- 시간복잡도: O(N)
- 코드에서 실수하기 쉬운 부분: -
- 까다로웠던 제약 또는 edge case: -

### 결과
- 제출 횟수: 3
- 제출 결과(AC/WA/TLE/MLE/RE): WA - WA - AC
- 틀린 원인: 케이스 나누다 보니까 점점 꼬임.
- 수정 내용: 핵심 로직 빼고 전부 제거


## 3) 표준 풀이
### 핵심 아이디어
- 정석 접근
```text
처음 기존 로직만 남기고 다 제거.
```
- 코드
```C++
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> v(n+1);
    v[0] = -1;
    for(int i=1; i<=n; ++i)
        cin >> v[i];

    stack<int> s;
    for (int i = 1; i <= n; ++i) {
        while (!s.empty() && v[s.top()] < v[i])
            s.pop();

        if (s.empty()) 
            cout << 0 << " ";
        else 
            cout << s.top() << " ";
        
        s.push(i);
    }
}
```

### 구현 포인트
- 필수 자료구조/기법: Monotonic Stack
- 시간복잡도: O(N)
- 구현 시 주의점:

### 나와 다른 점
- 발상 차이: 동일
- 구현 차이: 자꾸 if문으로 경우를 나눔
- 성능 차이: 동일


## 4) 회고
- 이번 문제에서 얻은 핵심 1가지: 모노톤 스택은 핵심 로직과 pop만 잘 구현하면 된다.
- 다음에 비슷한 문제를 보면 확인할 체크리스트:
	-
	-
	-
