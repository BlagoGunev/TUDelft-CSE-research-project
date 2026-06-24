#include<cmath>
#include<map>
#include<vector>
#include<math.h>
#include <algorithm>
#include <string>
#include<iostream>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;

    while (t--) {
        int n, a, b; cin >> n >> a >> b;
        string s; cin >> s;
        
        if (b >= 0)
            cout << n * (a + b) << '\n';
        else {
            int last,zeros=0,ones=0;
            while (!s.empty()) {
                last = s.back();
                while (!s.empty() && last == s.back())s.pop_back();
                 last == '0' ? zeros++ : ones++;
            }

            int u = min(zeros, ones) + 1;
            cout << a * n +  u* b << '\n';
        }
    }
    return 0;
}