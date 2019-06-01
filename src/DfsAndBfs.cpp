#include <algorithm>
#include <iostream>
using namespace std;
#define MAX_V 1010

void dfs(int u, int edge[], int graph[][MAX_V], int visited[]) {
    printf("%d ", u);
    // 현재 정점에 방문했음을 체크
    visited[u] = 1;
    for (int i = 0; i < edge[u]; i++) {
        int v = graph[u][i];
        // 방문을 한 적이 있으면 건너뜀
        if (visited[v]) continue;
        dfs(v, edge, graph, visited);
    }
}

int main() {
    freopen("output.txt", "w", stdout);
    int n, m, v;
    // 현재 정점에 연결된 간선의 개수
    int edge[MAX_V] = { 0, };
    // 현재 정점에 방문 여부를 저장
    int visited[MAX_V] = { 0, };
    // 그래프를 저장
    int graph[MAX_V][MAX_V] = { 0, };
    scanf("%d %d %d", &n, &m, &v);
    for (int i = 0; i < m; i++) {
        int s, t;
        scanf("%d %d", &s, &t);
        graph[s][edge[s]++] = t;
        graph[t][edge[t]++] = s;
    }
    for(int i = 1; i <= n; i++)
        sort(graph[i], graph[i] + edge[i]);
    dfs(v, edge, graph, visited);
    return 0;
}