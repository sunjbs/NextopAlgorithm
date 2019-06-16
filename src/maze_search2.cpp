#include <iostream>
#include <vector>
#include <queue>
using namespace std;

using point = pair<int, int>;

point operator+(const point &p1, const point &p2){
    return point(p1.first + p2.first, p1.second + p2.second);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    queue<point> que;
    vector<point> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<vector<bool> > maze;
    vector<vector<int> > dist;
    cin >> n >> m;
    maze.resize(n + 2, vector<bool>(m + 2));
    dist.resize(n + 2, vector<int>(m + 2));
    for(int r = 1; r <= n; r++)
        for(int c = 1; c <= m; c++){
            char tf;
            cin >> tf;
            maze[r][c] = tf == '1';
        }
    
    que.push(point(1, 1));
    dist[1][1] = 1;
    while(!que.empty()){
        point now = que.front();
        que.pop();
        for(point dir : direction){
            point next = now + dir;
            if(maze[next.first][next.second] && !dist[next.first][next.second]){
                dist[next.first][next.second] = dist[now.first][now.second] + 1;
                que.push(next);
            }
        }
    }
    cout << dist[n][m] << endl;
    return 0;
}