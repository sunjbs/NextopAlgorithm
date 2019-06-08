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

void bfs(int v, int edge_count[], int graph[][MAX_V]){
    int visited[MAX_V] = { 0, };
    int waiting[MAX_V] = { 0, };
    int a = -1, b = -1; // 현재 bfs를 위해 저장된 변수, a는 현재 위치, b는 배열에 저장된 원소 길이
    visited[v] = 1;
    waiting[++b] = v;
    while(a < b){
        int u = waiting[++a];
        printf("%d ", u);
        for(int i = 0; i < edge_count[u]; i++){
            int v = graph[u][i];
            if(!visited[v]){
                visited[v] = 1;
                waiting[++b] = v;
            }
        }
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
    printf("\n");
    bfs(v, edge_count, graph);
    return 0;
}