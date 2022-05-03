/*
    격자 안에서 단일 객체를 이동

    dx, dy technique에 대한 설명
    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]
    이용해서 격자의 상, 하, 좌, 우를 손쉽게 접근할 수 있도록 구현하는 팁
*/
#include <iostream>
#define MAX 101

using namespace std;

// size of the matrix
int n;
// start coordinate (row, column)
int r, c;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int mat[MAX][MAX];

bool checkRange(int r, int c) {
    if (0 > r || r >= n || 0 > c || c >= n)
        return false;
    else
        return true;
}

bool simulate() {
    int i;

    for (i = 0; i < 4; i++) {
        // calculate adjacent coordinate.
        int next_r = r + dx[i];
        int next_c = c + dy[i];

        if (checkRange(next_r, next_c) && mat[r][c] < mat[next_r][next_c]) {
            // update r and c with saved index information indicating max value
            r = next_r;
            c = next_c;

            return true;
        }
    }
    // couldn't find the bigger one
    return false;
}

int main() {
    int i, j;

    cin.tie(NULL);
    cin >> n >> r >> c;
    r -= 1;
    c -= 1;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    cout << mat[r][c] << " ";
    while (1) {
        // repeat until there is no bigger one.
        if (!simulate()) break;
        else
            cout << mat[r][c] << " ";
    }

    return 0;
}