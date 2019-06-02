// 인접리스트(링크드리스트)를 통한 DFS
#include <iostream>
#include <vector> // 배열
#include <list> // 링크드 리스트
#include <algorithm> // sort
using namespace std;

void dfs(int v, vector<list<int> > &graph, vector<bool> &visited){
    visited[v] = true;
    cout << v << ' ';
    for(int u : graph[v])
        if(!visited[u])
            dfs(u, graph, visited);
}

int main(){
    int n, m, v;
    vector<bool> visited;
    vector<list<int> > graph;
    cin >> n >> m >> v;
    visited.resize(n + 1);
    graph.resize(n + 1);
    for(int i = 0; i < m; i++){
        int s, t;
        cin >> s >> t;
        graph[s].push_back(t);
        graph[t].push_back(s);
    }
    for(int i = 1; i <= n; i++)
        graph[i].sort();
    dfs(v, graph, visited);
    return 0;
}