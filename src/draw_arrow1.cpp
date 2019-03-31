#include <iostream>
#include <algorithm>
using namespace std;

#define SIZE 100010
// Point 구조체
struct Point{
    int x;
    int y;
};
//Points 구조체의 비교 기준
bool compare(Point &p1, Point &p2){
    if(p1.y == p2.y) return p1.x < p2.x; 
    return p1.y < p2.y;
}

int main(){
    int n;
    long int result = 0;
    Point points[SIZE];
    cin >> n;
    for(int i = 0; i < n ;i++)
        cin >> points[i].x >> points[i].y;
    //points 배열을 compare함수(기준)을 통해서 정렬
    sort(points, points + n, compare);

    for(int i = 0; i < n; i++){
        int d1 = -1, d2 = -1;
        if(i - 1 > -1 && points[i - 1].y == points[i].y){
            // 오름차순 인덱스가 클수록 x좌표의 값이 더 크다 
            d1 = points[i].x - points[i - 1].x;
        }
        if(i + 1 < n && points[i].y == points[i + 1].y){
            // 오름차순 인덱스가 클수록 x좌표의 값이 더 크다 
            d2 = points[i + 1].x - points[i].x;
        }
        // 지금 점에서 색상이 같은 점이 없다
        if(d1 < 0 && d2 < 0) result += 0;
        // 지금 점에서 i + 1점만 같은 색상이다
        else if(d1 < 0) result += d2;
        // 지금 점에서 i - 1점만 같은 색상이다
        else if(d2 < 0) result += d1;
        // 둘다 같은 색상이므로 가까운 점을 선택한다
        else result += (d1 < d2) ? d1 : d2;
        // (조건) ? 참 : 거짓;
    }
    cout << result << '\n';

    return 0;
}