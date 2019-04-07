#include <iostream>
using namespace std;

struct Rect{
    // 왼쪽 아래 좌표
    long long bx, by;
    // 오른쪽 위 좌표
    long long tx, ty;
};

int main(){
    Rect r1, r2;
    bool x_meet, y_meet, x_intersect, y_intersect;
    // 입력
    cin >> r1.bx >> r1.by >> r1.tx >> r1.ty;
    cin >> r2.bx >> r2.by >> r2.tx >> r2.ty;

    // x축과 y축을 분리해서 생각한다.

    // x축이 점에서 만나는가?
    x_meet = (r1.bx == r2.tx) || (r1.tx == r2.bx);
    // y축이 점에서 만나는가?
    y_meet = (r1.by == r2.ty) || (r1.ty == r2.by);

    // 교차를 하는 경우 선분의 길이의 합이 구간의 길이 보다 크다.
    // x축이 교차하는가?
    x_intersect = (r1.tx - r1.bx + r2.tx - r2.bx) > max(r1.tx - r2.bx, r2.tx - r1.bx);
    // y축이 교차하는가?
    y_intersect = (r1.ty - r1.by + r2.ty - r2.by) > max(r1.ty - r2.by, r2.ty - r1.by);
    if(x_meet){
        // 둘다 점에서 만나는 경우
        if(y_meet)
            cout << "POINT";
        // x축은 점에서, y축은 교차하는 경우
        else if(y_intersect)
            cout << "LINE";
        // 만나지 않는 경우
        else
            cout << "NULL";
    }
    else if(x_intersect){
        // y축은 점에서, x축은 교차하는 경우
        if(y_meet)
            cout << "LINE";
        // 둘다 교차하는 경우
        else if(y_intersect)
            cout << "FACE";
        // 만나지 않는 경우
        else
            cout << "NULL";
    }
    // 만나지 않는 경우
    else
        cout << "NULL";
    return 0;
}