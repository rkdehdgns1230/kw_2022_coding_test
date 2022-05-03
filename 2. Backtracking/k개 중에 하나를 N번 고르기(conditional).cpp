#include <iostream>
#define MAX 9

using namespace std;

int n, k;
int arr[MAX];

void choose(int num) {
    if (num == n + 1) {
        for (int i = 1; i <= n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        return;
    }

    if (num <= 2) {
        for (int i = 1; i <= k; i++) {
            arr[num] = i;
            choose(num + 1);
        }
        return;
    }
    else {
        for (int i = 1; i <= k; i++) {
            if (arr[num - 2] == arr[num - 1] && arr[num - 1] == i)
                continue;
            arr[num] = i;
            choose(num + 1);
        }
        return;
    }

}

int main() {
    cin >> k >> n;

    choose(1);

    return 0;
}