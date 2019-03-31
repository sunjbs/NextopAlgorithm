#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using lint = long long int;
using point = pair<int, int>;

int distance(point &p1, point &p2){
    if(p1.first != p2.first) return 0;
    return abs(p1.second - p2.second);
}

int main(){
    int n;
    lint answer = 0;
    vector<point> points;
    cin >> n;
    points.resize(n + 2);
    for(int i = 0; i < n; i++)
        cin >> points[i].second >> points[i].first;
    points[n].first = n + 1;
    sort(points.begin(), points.end());
    for(int i = 1; i <= n; i++){
        int d, dl = distance(points[i - 1], points[i]), dr = distance(points[i], points[i + 1]);
        if((lint)dl * dr) d = min(dl, dr);
        else d = max(dl, dr);
        answer += (lint)d;
    }
    cout << answer << endl;
    return 0;
}