#include <stdio.h>
#define MAX_V 810

int min(int x, int y){ return (x < y) ? x : y; }

// n : 정점의 개수
// s : 출발을 할 정점의 번호
// graph : 간선의 길이를 저장한 배열
// dist : 정점 s에서 출발을 해서 특정 정점까지의 최단 경로를 저장한 배열
void dijkstra(int n, int s, int graph[][MAX_V], int dist[MAX_V]){
    const int INF = 2400000;
    int visited[MAX_V] = { 0, };
    int now = s;
    dist[s] = 0;
    while(now){
        for(int next = 1; next <= n; next++)
            dist[next] = min(dist[next], dist[now] + graph[now][next]);
        visited[now] = 1;
        int d = INF;
        now = 0;
        for(int i = 1; i <= n; i++)
            if(!visited[i] && dist[i] < d){
                now = i;
                d = dist[i];
            }
    }
}

int main(){
    const int INF = 2400000;
    int n, m;
    int p, q;
    int graph[MAX_V][MAX_V];
    int distFrom1[MAX_V], distFromP[MAX_V], distFromN[MAX_V];

    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        distFrom1[i] = distFromP[i] = distFromN[i] = INF;
        for(int j = 1; j <= n; j++)
            graph[i][j] = INF;
    }
    for(int i = 0; i < m; i++){
        int u, v, d;
        scanf("%d %d %d", &u, &v, &d);
        graph[u][v] = graph[v][u] = min(graph[u][v], d);
    }
    scanf("%d %d", &p, &q);
    dijkstra(n, 1, graph, distFrom1);
    dijkstra(n, p, graph, distFromP);
    dijkstra(n, n, graph, distFromN);

    int Answer = distFrom1[p] + distFromP[q] + distFromN[q];
    Answer = min(distFrom1[q] + distFromP[q] + distFromN[p], Answer);
    if(Answer > INF)
        Answer = -1;
    printf("%d", Answer);
    return 0;
}