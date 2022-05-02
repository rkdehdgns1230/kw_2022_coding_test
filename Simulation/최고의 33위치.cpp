/*
    완전탐색문제
*/
#include <iostream>
#define MAX 21

using namespace std;

int arr[MAX][MAX];
int n;

bool checkRange(int x, int y) {
    if (x < 0 || x + 2 >= n || y < 0 || y + 2 >= n)
        return false;
    else
        return true;
}

int calSum(int x, int y) {
    int i, j;
    int res = 0;
    for (i = x; i <= x + 2; i++) {
        for (j = y; j <= y + 2; j++) {
            res += arr[i][j];
        }
    }
    return res;
}

int main() {
    int i, j;
    cin >> n;

    cin.tie(NULL);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    int res = 0;
    int tmp = 0;
    for (i = 0; i < n - 2; i++) {
        for (j = 0; j < n - 2; j++) {
            tmp = calSum(i, j);
            // res is bigger one
            res = (res > tmp) ? res : tmp;
        }
    }
    cout << res << "\n";

    return 0;
}