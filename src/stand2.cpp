#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b){
    if(a % b == 0) return b;
    return gcd(b, a % b);
}

int main(){
    int d1, d2, answer = 1;
    vector<vector<bool> > check;
    cin >> d1 >> d2;
    for(int r = 0; r <= d2; r++){
        check.push_back(vector<bool>(r, true));
        for(int c = 1; c < r && r >= d1; c++){
            int g = gcd(r, c);
            answer += check[r / g][c / g];
            check[r / g][c / g] = false;
        }
    }
    cout << answer << endl;
    return 0;
}