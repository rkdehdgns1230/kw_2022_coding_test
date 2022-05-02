/*
    마찬가지로 모든 원소를 탐색하는 방식의 문제 풀이가 가능한 문제

    배열의 차원을 다르게 구현했으면 훨씬 간단하게 풀이 가능했을 것.

    Time complexity: O(TN)
    Space complexity: O(N)
*/
#include <iostream>
#define MAX 201

using namespace std;

int arr[MAX][2];

int main() {
    int n, t;
    int i, j;

    cin.tie(NULL);
    cin >> n >> t;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < n; j++) {
            cin >> arr[j][i];
        }
    }

    while (t--) {
        int tmp = arr[n - 1][0];

        for (i = n - 1; i > 0; i--) {
            arr[i][0] = arr[i - 1][0];
        }
        arr[0][0] = arr[n - 1][1];

        for (i = n - 1; i > 0; i--) {
            arr[i][1] = arr[i - 1][1];
        }
        arr[0][1] = tmp;
    }

    for (i = 0; i < 2; i++) {
        for (j = 0; j < n; j++) {
            cout << arr[j][i] << " ";
        }
        cout << "\n";
    }

    return 0;
}