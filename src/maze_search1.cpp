#include <stdio.h>
#define SIZE 110
#define QUEUE_SIZE 10010

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m;
    int maze[SIZE][SIZE] = { 0, };
    int dist[SIZE][SIZE] = { 0, };

    int a = 0, b = 0;
    int queue[QUEUE_SIZE][2] = { 0, };
    scanf("%d %d", &n, &m);
    for(int r = 1; r <= n; r++)
        for(int c = 1; c <= m; c++){
            char in;
            scanf(" %c", &in);
            maze[r][c] = in == '1';
        }

    queue[b][0] = 1;
    queue[b++][1] = 1;
    dist[1][1] = 1;

    int R[4] = {0, 1, 0, -1};
    int C[4] = {1, 0, -1, 0};
    while(a < b){
        int r = queue[a][0];
        int c = queue[a++][1];

        for(int d = 0; d < 4; d++){
            int nr = r + R[d];
            int nc = c + C[d];
            if(maze[nr][nc] == 1 && dist[nr][nc] == 0){
                dist[nr][nc] = dist[r][c] + 1;
                queue[b][0] = nr;
                queue[b++][1] = nc;
            }
        }
    }

    printf("%d\n", dist[n][m]);
    return 0;
}