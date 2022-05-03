#include <iostream>
#define MAX 11

using namespace std;

int n, m;
int arr[MAX];

void dfs(int num, int cnt) {
    if (num == n + 1) {
        if (cnt == m) {
            for (int i = 0; i < cnt; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        return;
    }

    arr[cnt] = num;
    dfs(num + 1, cnt + 1);

    dfs(num + 1, cnt);

    return;
}

int main() {
    cin >> n >> m;

    dfs(1, 0);

    return 0;
}