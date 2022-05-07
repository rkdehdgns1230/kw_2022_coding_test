#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;

int main() {
    vector<pair<int, int> > points = {
        {1, 7}, {3, 2}, {3, 1}, {6, 2}
    };
    int n = 4;

    priority_queue<tuple<int, int, int> > pq;
    for (int i = 0; i < n; i++) {
        int x = points[i].first, y = points[i].second;
        pq.push(make_tuple(x * y, x, y));           // priority_queue에 넣어줍니다.
        tuple<int, int, int> best_thing = pq.top(); // x * y, x, y 순으로 가장 우선순위 높은 경우를 찾아줍니다.

        int px, py;
        tie(ignore, px, py) = best_thing;  // 우리가 원하는 x, y 값만 tuple로부터 가져와줍니다.
        cout << px << " " << py << endl;
    }
    return 0;
}