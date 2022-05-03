#include <iostream>
#define MAX 21

using namespace std;

int dx[8] = { -1, 1, 0, 0, -1, 1, -1, 1 };
int dy[8] = { 0, 0, -1, 1, -1, 1, 1, -1 };

int n, m;
int arr[MAX][MAX];

bool checkRange(int x, int y) {
    return (0 <= x && x < n && 0 <= y && y < n);
}

int main() {
    int i, j, k;
    cin >> n >> m;

    int x, y;
    // initialize array with input elements
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    while (m--) {
        for (k = 1; k <= n * n; k++) {
            int max = 0;
            pair<int, int> maxPos;

            int x, y;
            for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++) {
                    if (arr[i][j] == k) {
                        x = i; y = j;
                    }
                }
            }

            for (i = 0; i < 8; i++) {
                int next_x = x + dx[i];
                int next_y = y + dy[i];

                if (!checkRange(next_x, next_y))
                    continue;

                if (max < arr[next_x][next_y]) {
                    max = arr[next_x][next_y];
                    maxPos = make_pair(next_x, next_y);
                }
            }
            // change two elements with tmp
            int tmp = arr[x][y];
            arr[x][y] = arr[maxPos.first][maxPos.second];
            arr[maxPos.first][maxPos.second] = tmp;

            // update x, y value with index directing maximum value
            x = maxPos.first; y = maxPos.second;
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}