// 인접리스트(링크드리스트)를 통한 DFS
#include <iostream>
#include <vector> // 배열
#include <list> // 링크드 리스트
#include <queue> // 큐
#include <algorithm> // sort
using namespace std;

void dfs(int v, vector<list<int> > &graph, vector<bool> &visited){
    visited[v] = true;
    cout << v << ' ';
    for(int u : graph[v])
        if(!visited[u])
            dfs(u, graph, visited);
}

void bfs(int v, vector<list<int> > &graph){
    vector<bool> visited(graph.size());
    queue<int> waiting;
    waiting.push(v);
    visited[v] = true;
    while(waiting.size()){
        int u = waiting.front();
        cout << u << ' ';
        waiting.pop();
        for(int v : graph[u])
            if(!visited[v]){
                visited[v] = true;
                waiting.push(v);
            }
    }
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
    cout << endl;
    bfs(v, graph);
    return 0;
}