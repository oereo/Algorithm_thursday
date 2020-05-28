// TODO: Optimization

#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int> > adj;
vector<vector<bool> > visited;
vector<vector<int> > checked;


// Brute force && BFS
/*
 ******************************************************************************************************
 *                                      optimization part                                             *
 ******************************************************************************************************
 */
int visitCheck(int n, int vertex) {
    for(int i=1; i<=n; i++) {
        if(!visited[vertex][i])
            return i;
    }
    return 0;
}

bool isEliminated(int n, int vertex) {
    visited[vertex][vertex] = true;
    queue<int> q;
    
    int nextVertex=visitCheck(n, vertex);
    while(nextVertex) {
        q.push(nextVertex);
        visited[vertex][nextVertex] = true;

        while(!q.empty()) {
            int here = q.front();
            q.pop();
            checked[vertex].push_back(here);
            for(int i = 0; i < adj[here].size(); i++) {
                int there = adj[here][i];
                /*
                 ******************************************************************************************************
                 *                                      optimization part                                             *
                 ******************************************************************************************************
                 */
                if(there == vertex || find(checked[vertex].begin(), checked[vertex].end(), there) != checked[vertex].end())
                    continue;

                if(visited[vertex][there]) {
                    return false;
                }
                q.push(there);
                visited[vertex][there] = true;
            }
        }
        nextVertex = visitCheck(n, vertex);
    }
    return true;
    
}

int solution(int n, vector<vector<int>> edges) {
    int answer = 0;
    adj.assign(n+1, vector<int>());
    visited.assign(n+1, vector<bool>(n+1, false));
    checked.assign(n+1, vector<int>());
    
    for(auto edge:edges) {
        int start=edge[0];
        int end=edge[1];
        adj[start].push_back(end);
        adj[end].push_back(start);
    }
    
    for(int v=1; v<=n; v++) {
        if(isEliminated(n, v)){
            answer += v;
        }
    }
    
    return answer;
}