#include <iostream>
using namespace std;

int main() {
    int n;
    int arr[1000];

    // scanf("%d", &n);
    cin >> n;
    for (int i = 0; i < n; i++)
        // scanf("%d", &arr[i]);
        cin >> arr[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
        // printf("%d\n", arr[i]);
        cout << arr[i] << '\n';
    return 0;
}