#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    int count[10001] = {0, };
    // scanf("%d", &n);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int k;
        // scanf("%d", &k);
        cin >> k;
        count[k]++;
    }

    for(int i = 0; i < 10001; i++)
        for(int j = 0; j < count[i]; j++)
            //printf("%d\n", i);
            cout << i << '\n';
    
    return 0;
}