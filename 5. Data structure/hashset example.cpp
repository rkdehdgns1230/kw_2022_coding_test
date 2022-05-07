#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    unordered_set<int> set;
    set.insert(3);
    set.insert(9);
    set.insert(5);

    if (set.find(3) != set.end()) {
        cout << "exist!!" << endl;
    }
    set.erase(3);
    if (set.find(3) == set.end()) {
        cout << "not exist!" << endl;
    }

    return 0;
}