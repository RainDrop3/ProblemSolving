# PS Retrospective Template

## 1) 문제 기본 정보
- 문제 이름: 2110 공유기 설치
- 난이도: Gold IV
- 핵심 조건:
	- 입력 크기: N < 2e5
	- 시간 제한: 2s
	- 메모리 제한: 128MB

## 2) 나의 풀이
- 날짜: 260409
- 풀이 횟수: 1
### 아이디어
- 접근 전략
```text
처음에 어떻게 접근할 지 감이 안잡혔음
gemini에게 힌트 요청: 가능한 '거리'를 이진탐색. 
가능한지 판별: v.front()에서 시작해서 다음 집까지 최대 '거리'이하가 되게하는 집 개수 탐색
거리 배열이 TTTTTFFF일때 바뀌는 경계점의 T가 답.
```
- 왜 이 방법을 먼저 떠올렸는지
```text
못떠올림.
```

### 구현 포인트
- 사용한 자료구조/알고리즘: Parametric Search
- 시간복잡도: O(log(MaxDist) * NlogN)
- 코드에서 실수하기 쉬운 부분: -
- 까다로웠던 제약 또는 edge case: -

### 결과
- 제출 횟수: 2
- 제출 결과(AC/WA/TLE/MLE/RE): WA - AC
- 틀린 원인: `high = front-back;`으로 설정했더니 n=2, c=2인 케이스에서 경계값에 걸림
- 수정 내용: `high = front-back+1;`로 수정


## 3) 표준 풀이
### 핵심 아이디어
- 정석 접근
```text
기존엔 내부 루프를 lower_bound를 사용해서 NlogN이 됨
정석은 그냥 완탐 돌리면서 찾으면 N만에 됨. 괜히 다돌면서 lower_bound까지 쓰니까 NlogN이 됨.
```
```C++
//while문만
while(low+1 < high){
        int mid = (low+high) / 2;
        int cnt = 1, last_pos = v[0];
        
        for(int i=0; i<n; ++i){
            if(v[i] - last_pos >= mid){
                cnt++;
                last_pos = v[i];
            }
        }

        if(cnt < c)
            high = mid;
        else
            low = mid;
    }
```

### 구현 포인트
- 필수 자료구조/기법: 동일
- 시간복잡도: O(log(MaxDist) * N)
- 구현 시 주의점:

### 나와 다른 점
- 발상 차이:
- 구현 차이:
- 성능 차이:


## 4) 회고
- 이번 문제에서 얻은 핵심 1가지: 매개변수탐색은 값을 구하긴 어렵지만 경계점을 찾기 용이할 때 사용.
- 다음에 비슷한 문제를 보면 확인할 체크리스트: Parametric Search를 떠올릴만한 로직
	- 최소값의 최대값
	- 최대값의 최소값
	-
