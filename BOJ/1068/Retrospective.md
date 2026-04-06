# PS Retrospective Template

## 1) 문제 기본 정보
- 문제 이름: 1068 트리
- 난이도: Gold V
- 핵심 조건:
	- 입력 크기: N < 50
	- 시간 제한: 2s
	- 메모리 제한: 128MB

## 2) 나의 풀이
- 날짜: 260406
- 풀이 횟수: 1
### 아이디어
- 접근 전략
```text
n=50으로 굉장히 작다.
따라서 한 노드를 지울 때 그 자식들까지 지우는 것을 재귀로 하였다.
재귀로 인덱스 계속 타고들어가며 지우기.
트리 자체는 벡터로 표현 -> 모든 트리 표현 가능

이후 노드지우기를 끝내고 v를 쭉 돌면서 freq에 나를 부모로 하는 노드의 개수를 저장. 나를 부모로 하는 노드 개수가 0이면 내가 리프노드라는 뜻이므로 freq[i]==0인 개수 출력.
```
- 왜 이 방법을 먼저 떠올렸는지
```text
노드 개수가 최대 50이라 재귀로 충분하다 판단.
```

### 구현 포인트
- 사용한 자료구조/알고리즘: Recursion
- 시간복잡도: O(N^2)
- 코드에서 실수하기 쉬운 부분: 
- 까다로웠던 제약 또는 edge case: root를 지울 때는 별도로 빼서 함수 돌기 전에 처리

### 결과
- 제출 횟수: 4
- 제출 결과(AC/WA/TLE/MLE/RE): WA - MLE - MLE - AC
- 틀린 원인:
```text
처음 WA는 그냥 잘못짠거.
근데 이후 MLE 원인 찾는데 꽤 걸림.
1. depth50의 편향트리에서 재귀가 터지나? -> 잘 됨.
2. 노드가 1개 뿐일 때? -> 잘 됨.
3. root에게 49개의 자식? -> 잘 됨.

예외케이스 못찾고 testcase.ac 돌려보니 root가 꼭 0번노드로 들어오는게 아니었음.
-1이 다른 인덱스로 들어오면 freq[v[i]]가 freq[-1]이 되면서 터짐..
순서도 뒤죽박죽 들어올 수 있음.
```
- 수정 내용:
```C++
//root문제 해결: for문에 -1에 대한 탈출조건 추가
if(v[i] == -1)  //root는 부모가 없음
    continue;

//순서 뒤죽박죽: i=n+1부터 시작하던걸 0부터 시작으로 수정
for(int i=0; i<v.size(); ++i)
```


## 3) 표준 풀이
### 핵심 아이디어
- 정석 접근
```text
gemini에게 물어보니 다음의 코드 제공
입력받을때 인접리스트 adj에 미리 부모-자식 관계 저장
이후 root부터 들어가면서 리프 카운트. 단, 삭제할 노드는 애초에 방문X.
리프 판정: 더 이상 들어갈 곳이 없으면 그게 리프.
```
```C++
#include <iostream>
#include <vector>

using namespace std;

int N, delete_node, root_node;
vector<int> adj[51];
int leaf_count = 0;

// DFS를 통해 리프 노드 개수를 세는 함수
void countLeaf(int current) {
    bool is_leaf = true;
    int child_count = 0;

    for (int next : adj[current]) {
        // 삭제할 노드는 방문하지 않음
        if (next == delete_node) continue;
        
        child_count++;
        countLeaf(next);
        is_leaf = false;
    }

    // 자식이 없거나, 있던 자식이 삭제되어 child_count가 0인 경우
    if (is_leaf) {
        leaf_count++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        int parent;
        cin >> parent;
        if (parent == -1) {
            root_node = i; // 루트 노드 번호 저장
        } else {
            adj[parent].push_back(i); // 부모 -> 자식 인접 리스트
        }
    }

    cin >> delete_node;

    // 예외 처리: 루트 노드를 삭제하는 경우 리프 노드는 0개
    if (delete_node == root_node) {
        cout << 0 << "\n";
        return 0;
    }

    // 루트부터 탐색 시작
    countLeaf(root_node);

    cout << leaf_count << "\n";

    return 0;
}
```

### 구현 포인트
- 필수 자료구조/기법: DFS, Adjacency List
- 시간복잡도: O(N)
- 구현 시 주의점: -

### 나와 다른 점
- 발상 차이:  
나: 지워야 할 노드부터 해서 그 자식까지를 실제로 지우고 리프 셈.
정석: 지워야 할 노드는 걍 접근을 안하고 리프 셈.
- 구현 차이: 재귀 vs dfs, 인접리스트
- 성능 차이: O(N^2) vs O(N)


## 4) 회고
- 이번 문제에서 얻은 핵심 1가지: 트리 문제에서 순회/탐색할 때는 항상 인접리스트 생각하기
- 다음에 비슷한 문제를 보면 확인할 체크리스트: 인접리스트/인접행렬
	- DFS/BFS, 트리, 정점>간선: 인접리스트
	- 플로이드, 정점<간선: 인접행렬
	-
