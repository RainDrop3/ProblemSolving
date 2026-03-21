# PS Retrospective Template

## 1) 문제 기본 정보
- 문제 이름: 2644 촌수계산
- 난이도: Silver II
- 핵심 조건:
	- 입력 크기: 100
	- 시간 제한: 1s
	- 메모리 제한: 128MB

## 2) 나의 풀이
- 날짜: 260320
- 풀이 횟수: 1
### 아이디어
- 접근 전략
```text
트리의 최소공통조상 구하기 문제로 해석
두 노드의 LCA구하고 그까지의 길이 더하면 되니까.
근데 구현을 어떻게 할지 모르겠었음. Node 구조체 만드는건 아닌거같고.
gemini를 통해 구현방법 배움.
```
- 왜 이 방법을 먼저 떠올렸는지
```text
하나의 부모만 가짐 -> 트리
촌수 구하기 -> 거리 구하기
```
- 코드
```C++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> adj[101];
int parent[15][101];
int depth[101];
bool visited[101];

void dfs(int curr, int d){
    visited[curr] = true;
    depth[curr] = d;
    for(int next : adj[curr]){
        if(!visited[next]){
            parent[0][next] = curr;
            dfs(next, d+1);
        }
    }
}

void set_parent(int n){
    for(int k=1; k<15; ++k)
        for(int i=1; i<=n; ++i)
            parent[k][i] = parent[k-1][parent[k-1][i]];
}

int lca(int u, int v){
    if(depth[u] > depth[v]) swap(u, v);

    for(int k=14; k>=0; --k)
        if(depth[v] - depth[u] >= (1<<k))
            v = parent[k][v];

    if(u == v) return u;

    for (int k = 14; k >= 0; k--) {
        if (parent[k][u] != parent[k][v]) {
            u = parent[k][u];
            v = parent[k][v];
        }
    }
    return parent[0][u];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, p1, p2, m;
    cin >> n >> p1 >> p2 >> m;
    
    while(m--){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i, 0); 
        }
    }

    set_parent(n);

    int common = lca(p1, p2);
    if (common == 0 || !visited[p1] || !visited[p2]) 
        cout << -1;
    else 
        cout << depth[p1] + depth[p2] - 2 * depth[common];
    

}
```

### 구현 포인트
- 사용한 자료구조/알고리즘: tree, DFS, DP
- 시간복잡도: O(Nlog N)
- 코드에서 실수하기 쉬운 부분: 구현
- 까다로웠던 제약 또는 edge case:

### 결과
- 제출 횟수: 1
- 제출 결과(AC/WA/TLE/MLE/RE): AC
- 틀린 원인:
- 수정 내용:


## 3) 표준 풀이
### 핵심 아이디어
- 정석 접근
```text
입력크기가 작아서 BFS로 가능하다.
인접리스트 만들고 dist벡터 만들어둠.
큐에 p1넣고 bfs로 1칸씩 이동하며 거리+1.
p2를 만나면 종료, 못만나고 끝나면 -1 출력.
```
- 코드
```C++
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, p1, p2, m;
    cin >> n >> p1 >> p2 >> m;

    vector<int> adj[101];
    for(int i=0; i<m; ++i){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dist(n+1, -1);
    queue<int> q;

    q.push(p1);
    dist[p1] = 0;

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        if(curr == p2) break;

        for(int next : adj[curr]){
            if(dist[next] == -1){
                dist[next] = dist[curr] + 1;
                q.push(next);
            }
        }
    }

    cout << dist[p2];
}
```

### 구현 포인트
- 필수 자료구조/기법: BFS
- 시간복잡도: O(V+E)
- 구현 시 주의점: 

### 나와 다른 점
- 발상 차이: 
	- 나: LCA구해서 LCA와 두 노드간의 거리 합 구하기
	- 정석: p1에서부터 bfs로 p2까지 이동
- 구현 차이: LCA구하기는 점화식 설정, lca함수 구현 등 훨씬 복잡.
- 성능 차이: 


## 4) 회고
- 이번 문제에서 얻은 핵심 1가지: 쿼리가 작을때는 무조건 lca구하기 보다 bfs가 빠름. 거리에 가중치가 없을 때는 bfs사용이 훨씬 좋음.
- 다음에 비슷한 문제를 보면 확인할 체크리스트: lca구하는 방법
	1) 인접리스트 생성
	2) 모든 노드에 대해 dfs로 부모-자식 관계 연결
	3) 점화식으로 조상까지 미리 저장해둔 희소테이블 생성
	4) lca 구하기
		1) 두 노드 깊이 같게 만들기
		2) 조상 다르면 점프하면서 공통조상 찾기
		
