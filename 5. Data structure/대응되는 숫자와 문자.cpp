#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int n, m;
    unordered_map<string, int> map;
    string strs[100001];
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> strs[i];
        map[strs[i]] = i;
    }

    for (int i = 0; i < m; i++) {
        string str;
        cin >> str;

        if ('0' <= str[0] && str[0] <= '9') {
            cout << strs[stoi(str)] << endl;
        }
        else {
            cout << map[str] << endl;
        }
    }

    return 0;
}