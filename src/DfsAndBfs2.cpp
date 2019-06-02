// 인접리스트를 통한 DFS
#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX_V 1010

void dfs(int v, int edge_count[], int graph[][MAX_V], int visited[]){
    visited[v] = 1;
    printf("%d ", v);
    for(int i = 0; i < edge_count[v]; i++){
        int u = graph[v][i];
        if(!visited[u])
            dfs(u, edge_count, graph, visited);
    }
}

int main(){
    int n, m, v;
    int edge_count[MAX_V] = { 0, };
    int visited[MAX_V] = { 0, };
    int graph[MAX_V][MAX_V] = { 0, };
    scanf("%d %d %d", &n, &m, &v);
    for(int i = 0; i < m; i++){
        int s, t;
        scanf("%d %d", &s, &t);
        graph[s][edge_count[s]++] = t;
        graph[t][edge_count[t]++] = s;
    }
    // 인접리스트는 입력 순서에 따라
    // 저장되는 순서가 달라지므로
    // 정렬을 실행해준다.
    for(int i = 1; i <= n; i++)
        sort(graph[i], graph[i] + edge_count[i]);
    dfs(v, edge_count, graph, visited);
    return 0;
}