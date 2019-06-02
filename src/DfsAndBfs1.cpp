// 인접행렬을 통한 DFS
#include <stdio.h>
#define MAX_V 1010

void dfs(int v, int n, int graph[][MAX_V], int visited[]){
    // 값을 1을 주면서 방문을 체크
    visited[v] = 1;
    printf("%d ", v);
    for(int u = 1; u <= n; u++)
        if(graph[v][u] && !visited[u])
            dfs(u, n, graph, visited);
}

int main(){
    int n, m, v;
    int visited[MAX_V] = { 0, };
    int graph[MAX_V][MAX_V] = { 0, };
    scanf("%d %d %d", &n, &m, &v);
    for(int i = 0; i < m; i++){
        int s, t;
        scanf("%d %d", &s, &t);
        graph[s][t] = 1;
        graph[t][s] = 1;
    }
    dfs(v, n, graph, visited);
    return 0;
}