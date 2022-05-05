#include <iostream>
#include <algorithm>
#define MAX 1001

using namespace std;

int arr[MAX];
int dp[MAX];
int n;

void initialize() {
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
    }
}

int main() {
    int i, j;

    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }

    initialize();

    int max_val = 1;

    for (i = 1; i < n; i++) {
        for (j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                dp[i] = max(dp[j] + 1, dp[i]);
            }
            max_val = max(max_val, dp[i]);
        }
    }

    cout << max_val << endl;

    return 0;
}