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
        // ã�� �� �ִ� ���: ���� A, B�� �����տ� ���ԵǴ� ����
        // �̴� ��Ī �������� ���Ұ� �ƴϱ� ������ �������� �����ش�.
        if (set.find(B[i]) != set.end()) {
            ans -= 2;
        }
    }

    cout << ans << endl;

    return 0;
}