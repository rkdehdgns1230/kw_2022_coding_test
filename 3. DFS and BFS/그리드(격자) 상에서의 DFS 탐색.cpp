#include <iostream>
#define MAX 101

using namespace std;

int n, m;

int arr[MAX][MAX];
bool visited[MAX][MAX];

// 아래와 오른쪽 방향으로만 움직일 수 있다.
int dx[2] = { 1, 0 };
int dy[2] = { 0, 1 };

bool inRange(int x, int y) {
    return (x >= 0 && x < n&& y >= 0 && y < m);
}

void dfs(int x, int y) {
    for (int i = 0; i < 2; i++) {
        int next_x = x + dx[i];
        int next_y = y + dy[i];

        if (!inRange(next_x, next_y))
            continue;

        if (arr[next_x][next_y] == 1 && !visited[next_x][next_y]) {
            visited[next_x][next_y] = true;
            dfs(next_x, next_y);
        }
    }
}

int main() {
    int i, j;
    cin >> n >> m;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    dfs(0, 0);

    if (visited[n - 1][m - 1])
        cout << 1 << "\n";
    else
        cout << 0 << "\n";


    return 0;
}