#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

const long long mod = 1'000'000'007;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);

    int n;
    deque<int> d;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        d.push_back(x);
    }

    int prev = -1;
    queue<char> anus;
    while (!d.empty()) {
        int l = d.front();
        int r = d.back();
        if (l < r && l > prev) {
            anus.push('L');
            d.pop_front();
            prev = l;
        } else if (r > prev) {
            anus.push('R');
            d.pop_back();
            prev = r;
        } else if (l > prev) {
            anus.push('L');
            d.pop_front();
            prev = l;

        } else {
            break;
        }
    }
    cout << anus.size() << endl;
    while (!anus.empty()) {
        cout << anus.front();
        anus.pop();
    }
    cout << endl;

    return 0;
}