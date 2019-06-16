#include <stdio.h>
#define MAX_V 1010

int min(int a, int b){ return (a < b) ? a : b; }

int main(){
    const int INF = 1000000000;
    int n, m, s, t;
    int dist[MAX_V], visited[MAX_V];
    int graph[MAX_V][MAX_V];
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        dist[i] = INF;
        visited[i] = 0;
        for(int j = 1; j <= n; j++)
            graph[i][j] = INF;
    }

    for(int i = 0; i < m; i++){
        int u, v, d;
        scanf("%d %d %d", &u, &v, &d);
        graph[u][v] = min(graph[u][v], d);
    }
    scanf("%d %d", &s, &t);

    dist[s] = 0;
    while(1){
        int now, d = INF;
        for(int i = 1; i <= n; i++)
            if(!visited[i] && dist[i] < d){
                now = i;
                d = dist[i];
            }
        visited[now] = 1;
        if(now == t) break;
        for(int next = 1; next <= n; next++)
            dist[next] = min(dist[now] + graph[now][next], dist[next]);
    }

    printf("%d", dist[t]);
    return 0;
}