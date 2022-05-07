#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    int n;
    unordered_map<string, int> m;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;

        if (m.find(str) != m.end()) {
            m[str]++;
        }
        else {
            m[str] = 1;
        }
    }

    int res = 0;
    for (auto it = m.begin(); it != m.end(); it++) {
        res = (res > it->second) ? res : it->second;
    }
    cout << res << endl;
    return 0;
}