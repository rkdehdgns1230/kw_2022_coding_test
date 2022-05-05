#include <iostream>
#define MAX 20

using namespace std;

int dp[MAX];

int main() {
    int n;
    cin >> n;

    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            dp[i] += (dp[j] * dp[i - 1 - j]);
        }
    }

    cout << dp[n] << endl;

    return 0;
}

/*
    각 개수에 대해서 만들어질 수 있는 이진 트리의 모든 모양의 케이스가
    현재 개수에 대해서 만들어 낼 수 있는 dp 배열의 값이 되야한다.

    이전에 만든 트리 자체를 하나의 노드로 생각하고 풀면 되는듯?
    n = 2: 2
    n = 3: n=2 * n=0 + n=1 * n=1 = 3
    결국 트리의 모양의 경우의 수만 세면 된다. -> 모양이 형성되기 위한 노드의 숫자는 알아서 삽입되는 느낌

    루트 또한 알아서 정해지는건 마찬가지기 때문에, 루트를 기준으로 왼쪽과 오른쪽의 트리 노드의 개수에 따라서
    모양을 판단할 수 있게 된다.

*/