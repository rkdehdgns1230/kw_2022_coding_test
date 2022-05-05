#include <iostream>
#define MAX 101

using namespace std;

int n;
int arr[MAX][MAX];
int d[MAX][MAX];

bool inRange(int x, int y) {
    return (0 <= x && x < n && 0 <= y && y < n);
}

int dp(int x, int y) {
    if (!inRange(x, y)) return 0;
    if (x == 0 && y == 0) return arr[0][0];
    else if (d[x][y] != 0) return d[x][y];
    else return d[x][y] = max(dp(x - 1, y) + arr[x][y], dp(x, y - 1) + arr[x][y]);
}

int main() {
    int i, j;
    cin >> n;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    cout << dp(n - 1, n - 1) << endl;

    return 0;
}