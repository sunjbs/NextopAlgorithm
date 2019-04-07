#include <iostream>
using namespace std;

int main(){
    int n, minimum = 1000, maximum = 0, answer;
    cin >> n;
    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        //지금까지 입력받은 학생중 최댓값을 구한다
        maximum = max(maximum, k);
        //지금까지 입력받은 학생중 최솟값을 구한다
        minimum = min(minimum, k);
    }
    answer = maximum - minimum;
    cout << answer << endl;
    return 0;
}