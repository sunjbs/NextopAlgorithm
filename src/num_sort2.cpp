#include <iostream>
#include <queue>
using namespace std;

int arr[3000001];

int main() {
    // ====================================
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // cin과 cout이 scanf와 printf처럼 빨라진다.
    int n;
    cin >> n;
    priority_queue<int> pq; // heap sort 구현해놓은 자료형
    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        arr[k + 1000000] = 1;
        pq.push(k);
    }

    pq.size();
    pq.top();
    pq.pop();
    for(int i = 0; i < 3000001; i++){
        if(arr[i] == 1)
            cout << i - 1000000 << '\n';
    }
    

    return 0;
}