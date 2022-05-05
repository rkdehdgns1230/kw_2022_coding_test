#include <iostream>
#include <string>
#include <algorithm>

#define MAX 1001

using namespace std;

int c[MAX][MAX];

int initLCS(string a, string b) {
    int i, j;
    int a_length = a.length();
    int b_length = b.length();

    for (i = 0; i < a_length; i++) {
        c[i][0] = 0;
    }
    for (j = 0; j < b_length; j++) {
        c[0][j] = 0;
    }
}

int calLCS(string a, string b) {
    int i, j;
    int a_length = a.length();
    int b_length = b.length();

    for (i = 1; i <= a_length; i++) {
        for (j = 1; j <= b_length; j++) {
            if (a[i - 1] == b[j - 1]) {
                // last two elements are same
                c[i][j] = c[i - 1][j - 1] + 1;
            }
            else {
                // c[i][j] is bigger one
                c[i][j] = max(c[i - 1][j], c[i][j - 1]);
            }
        }
    }

    return c[a_length][b_length];
}

void getLCS(string a, string b) {
    string res;

    int i = a.length();
    int j = b.length();

    while (i > 0 && j > 0) {
        if (c[i][j] == c[i - 1][j]) {
            i--;
        }
        else if (c[i][j] == c[i][j - 1]) {
            j--;
        }
        else {
            i--;
            j--;
            res += a[i];
        }
    }

    for (int k = res.length() - 1; k >= 0; k--) {
        cout << res[k];
    }
    cout << endl;

    return;
}

int main() {
    string x, y;

    cin >> x;
    cin >> y;

    initLCS(x, y);
    cout << calLCS(x, y) << endl;

    return 0;
}