#include <stdio.h>
#include <stdlib.h>
#define MAX_V 1010
#define MAX_E 100010

const int INF = 1 << 30;

struct Node{
    struct Node* link;
    int v;
    int d;
};

struct Pair{
    int v;
    int d;
};

struct Node* newNode(int v, int d, struct Node* link){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->v = v;
    temp->d = d;
    temp->link = link;
    return temp;
}

void swap(int x, int y, struct Pair arr[]){
    struct Pair temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}

void downHeap(int n, struct Pair heap[]){
    int x = n;
    while(x * 2 < n){
        int y;
        int l = x * 2;
        int r = l + 1;
        if(r > n || heap[l].d <= heap[r].d)
            y = l;
        else
            y = r;
        if(heap[x].d <= heap[y].d) break;
        swap(x, y, heap);
        x = y;
    }
}

void upHeap(int x, struct Pair heap[]){
    while(x > 1){
        int y = x / 2;
        if(heap[x].d > heap[y].d) break;
        swap(x, y, heap);
        x = y;
    }
};

int dijkstra(int n, int s, int t, struct Node* graph[]){
    int h = 0;
    int dist[MAX_V];
    struct Pair heap[MAX_E];
    for(int i = 1; i <= n; i++)
        dist[i] = INF;
    dist[s] = 0;
    heap[++h].d = dist[s];
    heap[h].v = s;

    while(h > 0){
        int now = heap[1].v;
        swap(1, h--, heap);
        downHeap(h, heap);
        for(struct Node* ptr = graph[now]; ptr != NULL; ptr = ptr->link){
            if(dist[ptr->v] > dist[now] + ptr->d){
                dist[ptr->v] = dist[now] + ptr->d;
                heap[++h].d = dist[ptr->v];
                heap[h].v = ptr->v;
                upHeap(h, heap);
            }
        }
    }
    return dist[t];
}

int main(){
    int n, m, s, t;
    struct Node* graph[MAX_V];
    scanf("%d %d %d %d", &n, &m, &s, &t);
    for(int i = 1; i <= n; i++)
        graph[i] = NULL;
    
    for(int i = 0 ; i < m; i++){
        int u, v, d;
        scanf("%d %d %d", &u, &v, &d);
        graph[u] = newNode(v, d, graph[u]);
    }

    int answer = dijkstra(n, s, t, graph);

    // 동적으로 받은 메모리를 해제
    for(int i = 1; i <= n; i++){
        struct Node* now = graph[i];
        while(now != NULL){
            struct Node* next = now-> link;
            free(now);
            now = next;
        }
    }
    return 0;
}