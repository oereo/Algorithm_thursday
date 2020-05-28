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