#include <iostream>
#include <unordered_set>
#define MAX 100001

using namespace std;

int n, m;
int arr1[MAX], arr2[MAX];

int main() {
    unordered_set<int> s;
    int i;

    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> arr1[i];
        s.insert(arr1[i]);
    }

    cin >> m;

    for (i = 0; i < m; i++) {
        cin >> arr2[i];
    }

    for (i = 0; i < m; i++) {
        if (s.find(arr2[i]) == s.end()) {
            cout << 0 << " ";
        }
        else {
            cout << 1 << " ";
        }
    }

    return 0;
}