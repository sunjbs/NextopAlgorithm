#include <iostream>
#include <queue>
using namespace std;

#define SIZE 100010
#define CASE_SIZE 6

struct Bottle{
    int a;
    int b;
    Bottle(){};
    Bottle(int _a, int _b):a(_a), b(_b){};
};

int answer[CASE_SIZE][SIZE];

int getCase(int a, int b, int nowA, int nowB){
    if(nowA == 0) return 0;
    if(nowB == 0) return 1;
    if(nowA == a) return 2;
    if(nowB == b) return 3;
    return 4;
}

int getIndex(int nowA, int nowB, int nowCase){
    switch(nowCase){
    // A물통이 비어있다. 따라서 B의 물통의 양을 index로 가진다.
    case 0:
        return nowB;
    // B물통이 비어있다. 따라서 A의 물통의 양을 index로 가진다.
    case 1:
        return nowA;
    // A물통이 가득 차있다. 따라서 B의 물통의 양을 index로 가진다.
    case 2:
        return nowB;
    // B물통이 가득 차있다. 따라서 A의 물통의 양을 index로 가진다.
    case 3:
        return nowA;
    }
    return 0;
}

int main(){
    int a, b, c, d;
    for(int i = 0; i < CASE_SIZE; i++)
        for(int j = 0; j < SIZE; j++)
            answer[i][j] = -1;
    cin >> a >> b >> c >> d;
    answer[0][0] = 0;

    queue<Bottle> next;
    next.push(Bottle(0, 0));
    while(next.size() > 0){
        Bottle current = next.front();
        next.pop();
        Bottle next_pos;
        int currentCase, currentIndex;
        int nextCase, nextIndex;
        // 현재 상태의 case와 index를 구한다.
        currentCase = getCase(a, b, current.a, current.b);
        currentIndex = getIndex(current.a, current.b, currentCase);
        // F(A)
        next_pos.a = a;
        next_pos.b = current.b;
        nextCase = getCase(a, b, next_pos.a, next_pos.b);
        nextIndex = getIndex(next_pos.a, next_pos.b, nextCase);
        if(answer[nextCase][nextIndex] < 0){
            answer[nextCase][nextIndex] = answer[currentCase][currentIndex] + 1;
            next.push(next_pos);
        }
        // F(B)
        next_pos.a = current.a;
        next_pos.b = b;
        nextCase = getCase(a, b, next_pos.a, next_pos.b);
        nextIndex = getIndex(next_pos.a, next_pos.b, nextCase);
        if(answer[nextCase][nextIndex] < 0){
            answer[nextCase][nextIndex] = answer[currentCase][currentIndex] + 1;
            next.push(next_pos);
        }
        // E(A)
        next_pos.a = 0;
        next_pos.b = current.b;
        nextCase = getCase(a, b, next_pos.a, next_pos.b);
        nextIndex = getIndex(next_pos.a, next_pos.b, nextCase);
        if(answer[nextCase][nextIndex] < 0){
            answer[nextCase][nextIndex] = answer[currentCase][currentIndex] + 1;
            next.push(next_pos);
        }
        // E(B)
        next_pos.a = current.a;
        next_pos.b = 0;
        nextCase = getCase(a, b, next_pos.a, next_pos.b);
        nextIndex = getIndex(next_pos.a, next_pos.b, nextCase);
        if(answer[nextCase][nextIndex] < 0){
            answer[nextCase][nextIndex] = answer[currentCase][currentIndex] + 1;
            next.push(next_pos);
        }
        // M(A, B)
        next_pos.b = min(b, current.a + current.b);
        next_pos.a = max(0, current.a + current.b - b);
        nextCase = getCase(a, b, next_pos.a, next_pos.b);
        nextIndex = getIndex(next_pos.a, next_pos.b, nextCase);
        if(answer[nextCase][nextIndex] < 0){
            answer[nextCase][nextIndex] = answer[currentCase][currentIndex] + 1;
            next.push(next_pos);
        }
        // M(B, A)
        next_pos.a = min(a, current.a + current.b);
        next_pos.b = max(0, current.a + current.b - a);
        nextCase = getCase(a, b, next_pos.a, next_pos.b);
        nextIndex = getIndex(next_pos.a, next_pos.b, nextCase);
        if(answer[nextCase][nextIndex] < 0){
            answer[nextCase][nextIndex] = answer[currentCase][currentIndex] + 1;
            next.push(next_pos);
        }
    }

    int answerCase, answerIndex;
    answerCase = getCase(a, b, c, d);
    answerIndex = getIndex(c, d, answerCase);
    cout << answer[answerCase][answerIndex] << '\n';
    return 0;
}