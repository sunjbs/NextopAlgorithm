#include <iostream>
using namespace std;

#define SIZE 2010
int sit[SIZE][SIZE] = {0};

// 최대공약수를 구하는 함수
int gcd(int a, int b){
    // a가 b의 배수이면 최대공약수는 b가 된다
    if(a % b == 0) return b;
    // gcd(a, b)와 gcd(b, a % b)는 같다.
    return gcd(b, a % b);
}

int main(){
    int d1, d2, answer = 1;
    cin >> d1 >> d2;
    for(int r = d1; r <= d2; r++){
        for(int i = 1; i < r; i++){
            int g = gcd(r, i);
            // 현재 좌표의 원형이 되는 좌표
            int x = r / g, y = i / g;
            // 좌석이 사용되지 않은 경우 answer을 증가
            if(sit[x][y] == 0) answer++;
            // 좌석을 놓는다
            sit[x][y] = 1;
        }
    }
    cout << answer << endl;
    return 0;
}