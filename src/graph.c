#include <stdio.h>
#include <stdlib.h> // malloc, free

#define MAX_V 1010

struct Node{
    struct Node* next;
    int data;
};

struct Node* newNode(struct Node* next, int data){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->next = next;
    temp->data = data;
    return temp;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int v, e;
    // 2차원배열로 하는 방법
    int matrix_graph[MAX_V][MAX_V] = { 0, };

    // 인접리스트로 하는 방법
    int edge_count[MAX_V] = { 0, };
    int list_graph[MAX_V][MAX_V] = { 0, };

    // 링크드리스트로 하는 방법
    struct Node* node_graph[MAX_V] = { 0, };

    scanf("%d %d", &v, &e);
    for(int i = 0; i < e; i++){
        int s, t;
        scanf("%d %d", &s, & t);
        // 2차원배열로 하는 방법
        matrix_graph[s][t] = 1;
        matrix_graph[t][s] = 1;

        // 인접리스트로 하는 방법
        list_graph[s][edge_count[s]++] = t;
        list_graph[t][edge_count[t]++] = s;

        // 링크드리스트로 하는 방법
        node_graph[s] = newNode(node_graph[s], t);
        node_graph[t] = newNode(node_graph[t], s);
    }

    // 2차원배열로 하는 방법 출력
    for(int i = 1; i <= v; i++){
        for(int j = 1; j <= v; j++)
            printf("%c ", (matrix_graph[i][j])?'O':'X');
        printf("\n");
    }
    printf("=====\n");

    // 인접리스트로 하는 방법 출력
    for(int i = 1; i <= v; i++){
        printf("%d : ", i);
        for(int j = 0; j < edge_count[i]; j++)
            printf("%d ", list_graph[i][j]);
        printf("\n");
    }
    printf("=====\n");

    // 링크드리스트로 하는 방법 출력
    for(int i = 1; i <= v; i++){
        printf("%d : ", i);
        struct Node* node = node_graph[i];
        while(node != NULL){
            printf("%d ", node->data);
            node = node->next;
        }
        printf("\n");
    }

    // 링크드리스트로 하는 방법 메모리 해제
    for(int i = 1; i <= v; i++){
        struct Node* node = node_graph[i];
        while(node != NULL){ 
            struct Node* next = node->next;
            free(node);
            node = next;
        }
    }
    return 0;
}