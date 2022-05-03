#include <iostream>
#define MAX 9

using namespace std;

int k, n;
int arr[MAX];

void dfs(int cnt) {
    if (cnt == n + 1) {
        for (int i = 1; i <= n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = 1; i <= k; i++) {
        arr[cnt] = i;
        dfs(cnt + 1);
    }
    return;
}

int main() {
    cin >> k >> n;

    dfs(1);


    return 0;
}