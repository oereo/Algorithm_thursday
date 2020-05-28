<h1 align="center">
  Graph Theory
</h1>

## Table of Contents

- [Definition](#definition)
- [Code Analysis](#code_analysis)



---

## Definition <a name = "definition"></a>
### Graph
    그래프 G는 (V,E) 쌍으로 이루어진 자료 구조
    V = vertices라 불리는 아이템들의 nonempty한 집합
    E = edges라 불리는 두개의 아이템으로 이루어진 부분 집합들의 집합
### 

---
## Code Analysis <a name = "code_analysis"></a>
### 가장먼노드.cpp
    #include <algorithm>
    #include <string>
    #include <vector>
    #include <queue>

    using namespace std;

    vector<vector<int> > adj;
    vector<bool> visited;
    vector<int> dist;

    int solution(int n, vector<vector<int>> edge) {
        int answer = 0;
        adj.assign(n+1, vector<int>());
        visited.assign(n+1, false);
        dist.assign(n+1, 0);
        for(int i = 0; i < edge.size(); i++) {
            adj[edge[i][0]].push_back(edge[i][1]);
            adj[edge[i][1]].push_back(edge[i][0]);
        }
        
        queue<int> q;
        q.push(1);
        visited[1] = true;
        while(!q.empty()) {
            int here = q.front();
            q.pop();
            for(int i = 0; i < adj[here].size(); i++) {
                int there = adj[here][i];
                if(!visited[there]) {
                    dist[there] = dist[here] + 1;
                    q.push(there);
                    visited[there] = true;
                }
            }
        }
        
        answer = count(dist.begin(), dist.end(), *max_element(dist.begin(), dist.end()));
        return answer;
    }