#include <stdio.h>
#include <stdlib.h>  // malloc, free 함수
#define MAX_V 1010
#define MAX_E 10010

struct Node {
    // 다음 주소를 저장할 포인터
    struct Node* next;
    // 자신의 데이터를 저장할 변수
    int data;
};

// next와 data를 주었을때 그 값을 저장하는 Node형 구조체의 주소를 반환
struct Node* newNode(struct Node* next, int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->next = next;
    temp->data = data;
    return temp;
}

int main() {
    freopen("output.txt", "w", stdout);
    int v, e;
    struct Node* graph[MAX_V];
    scanf("%d %d", &v, &e);
    for (int i = 1; i <= v; i++) graph[MAX_V] = NULL;
    for (int i = 0; i < e; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        // 인접 행렬
        // graph[a][b] = 1;
        // graph[b][a] = 1;
        // 인접 리스트
        // graph[a][edge[a]++] = b;
        // graph[b][edge[b]++] = a;
        graph[a] = newNode(graph[a], b);
        graph[b] = newNode(graph[b], a);

        // 링크드 리스트를 순회하면서 출력
        for (int i = 1; i <= v; i++) {
            struct Node* current = graph[i];
            printf("%d : ", i);
            while (current != NULL) {
                printf("%d ", current->data);
                current = current->next;
            }
            printf("\n");
        }
        printf("=====\n");
    }

    // 링크드 리스트를 순회하면서 메모리를 해제
    for (int i = 1; i <= v; i++) {
        struct Node* current = graph[i];
        while(current != NULL){
            struct Node* next = current->next;
            free(current);
            current = next;
        }
    }

    return 0;
}