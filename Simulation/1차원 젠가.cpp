/*
    simulation 문제로 직접 구현하는 문제이다.
    마찬가지로 시간 복잡도를 굳이 고려하지 않아도 완전 탐색 방식으로 해결 가능하다.
*/
#include <iostream>
#define MAX 101

using namespace std;

int arr[MAX];
int tmp[MAX];

int main() {
    int n;
    int i, j;

    cin.tie(NULL);
    cin >> n;

    int s1, e1;
    int s2, e2;

    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> s1 >> e1;
    cin >> s2 >> e2;

    int idx = 0;
    for (i = 0; i < n; i++) {
        if (i >= s1 - 1 && i <= e1 - 1)
            continue;
        tmp[idx++] = arr[i];
    }
    for (i = 0; i < idx; i++) {
        arr[i] = tmp[i];
    }
    n = idx;
    idx = 0;
    for (i = 0; i < n; i++) {
        if (i >= s2 - 1 && i <= e2 - 1)
            continue;
        tmp[idx++] = arr[i];
    }
    for (i = 0; i < idx; i++) {
        arr[i] = tmp[i];
    }

    cout << idx << "\n";
    for (i = 0; i < idx; i++) {
        cout << arr[i] << "\n";
    }

    return 0;
}