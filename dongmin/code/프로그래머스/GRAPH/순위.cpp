// 각 노드의 연결 여부
#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int> > adj;
vector<int> connected;
vector<vector<bool> > visited;

void bfs(int v) {
    queue<int> q;
    q.push(v);
    connected[v]++;
    visited[v][v] = true;
    while(!q.empty()) {
        int here = q.front();
        q.pop();
        for(int i=0; i<adj[here].size(); i++) {
            int there = adj[here][i];
            if(!visited[v][there]){
                connected[there]++;
                connected[v]++;
                visited[v][there] = true;
                q.push(there);
            }
        }
    }
    
}

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    adj.assign(n+1, vector<int>());
    connected.assign(n+1, 0);
    visited.assign(n+1, vector<bool>(n+1, false));
    
    for(auto result:results) {
        int winner = result[0];
        int loser = result[1];
        adj[winner].push_back(loser);
    }
    
    for(int v=1; v<=n; v++)
        bfs(v);
    answer = count(connected.begin(), connected.end(), n);
    return answer;
}