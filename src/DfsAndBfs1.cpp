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

void bfs(int v, int n, int graph[][MAX_V]){
    int visited[MAX_V] = { 0, };
    int waiting[MAX_V] = { 0, };
    int a = -1, b = -1; // 현재 bfs를 위해 저장된 변수, a는 현재 위치, b는 배열에 저장된 원소 길이
    visited[v] = 1;
    waiting[++b] = v;
    while(a < b){
        int u = waiting[++a];
        printf("%d ", u);
        for(int v = 1; v <= n; v++)
            if(!visited[v] && graph[u][v] == 1){
                visited[v] = 1;
                waiting[++b] = v;
            }
    }
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
    printf("\n");
    bfs(v, n, graph);
    return 0;
}