#include <iostream>
#include <unordered_set>
#define MAX 200000

using namespace std;

int n, m;
int A[MAX];
int B[MAX];
int ans;

unordered_set<int> set;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> B[i];
    }

    ans = n + m;

    for (int i = 0; i < n; i++) {
        set.insert(A[i]);
    }

    for (int i = 0; i < m; i++) {
        // 찾을 수 있는 경우: 수열 A, B의 교집합에 포함되는 원소
        // 이는 대칭 차집합의 원소가 아니기 때문에 개수에서 지워준다.
        if (set.find(B[i]) != set.end()) {
            ans -= 2;
        }
    }

    cout << ans << endl;

    return 0;
}