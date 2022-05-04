#include <iostream>
#include <queue>

#define MAX 101

using namespace std;

int arr[MAX][MAX];
int step[MAX][MAX];
bool visited[MAX][MAX];
int n, m;

bool inRange(int x, int y) {
    return (0 <= x && x < n && 0 <= y && y < m);
}

void bfs() {
    int dx[4] = { -1, 1, 0, 0 };
    int dy[4] = { 0, 0, -1, 1 };
    queue<pair<int, int>> q;
    q.push({ 0, 0 });
    visited[0][0] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int next_x = x + dx[i];
            int next_y = y + dy[i];

            if (!inRange(next_x, next_y))
                continue;

            if (!visited[next_x][next_y] && arr[next_x][next_y] == 1) {
                visited[next_x][next_y] = true;
                q.push(make_pair(next_x, next_y));
                step[next_x][next_y] = step[x][y] + 1;
            }
        }
    }
    return;
}

int main() {
    int i, j;
    cin >> n >> m;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    bfs();

    if (step[n - 1][m - 1] == 0) {
        cout << "-1\n";
        return 0;
    }
    else {
        cout << step[n - 1][m - 1] << "\n";
    }

    return 0;
}