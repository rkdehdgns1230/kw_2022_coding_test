#include <iostream>
#define MAX 46

using namespace std;

int n;
int dp[MAX];

int fibonacci(int x) {
    if (x == 1 || x == 2) return 1;
    else if (dp[x] != 0) return dp[x];
    else return dp[x] = fibonacci(x - 1) + fibonacci(x - 2);
}

int main() {
    dp[1] = 1, dp[2] = 1;

    cin >> n;

    cout << fibonacci(n) << "\n";


    return 0;
}