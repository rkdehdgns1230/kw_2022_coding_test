#include <iostream>
#include <climits>
#include <algorithm>

#define MAX 100001
using namespace std;

int n;
int arr[MAX];
int dp[MAX];
void initialize() {
    for (int i = 0; i < n; i++) {
        arr[i] = INT_MIN;
    }
}

int main() {
    cin >> n;

    initialize();

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int max_val = arr[0];
    dp[0] = arr[0];
    for (int i = 1; i < n; i++) {
        dp[i] = max(dp[i - 1] + arr[i], arr[i]);
        max_val = max(max_val, dp[i]);
    }

    cout << max_val << endl;

    return 0;
}