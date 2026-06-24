#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

const long long MOD = 1000000007;

map<pair<long long, long long>, int> stored_ans;

long long find_ans(long long a, long long b, long long c, long long d) {
    if ( b == 0 && d == 0 ) return 1;
    if ( b == 0 || d == 0 ) return 0;
    //cout << a << " " << b << " " << c << " " << d << endl;
    if (stored_ans.find(make_pair(b, d)) != stored_ans.end()) {
        return stored_ans[make_pair(b, d)];
    }
    long long ans = 0;
    for (int k = 0; k * c + d % c <= b; k++) {
        long long a0 = k * c + d % c;
        if ((b - a0) % a == 0 && a0 <= b)
            ans += find_ans(a, (b - a0) / a, c, (d - a0) / c);
    }
    stored_ans[make_pair(b, d)] = ans % MOD;
    //cout << a << " " << b << " " << c << " " << d << " " << ans << endl;
    return ans % MOD;
}

int main() {
    long long t, a, b;
    cin >> t >> a >> b;
    if (t == 1 && a == 1) {
        if (b == 1)
            cout << "inf\n";
        else
            cout << "0\n";
        return 0;
    }
    stored_ans.clear();
    cout << find_ans(t, a, a, b) << endl;
}