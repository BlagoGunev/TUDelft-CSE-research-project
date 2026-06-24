#include <bits/stdc++.h>
using namespace std;
 
#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<
 
typedef long long ll;
typedef long double ld;

const int MaxN = 2e5 + 10;
int n;
vector<int> a;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    a.resize(n);

    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    int sol = 0;
    vector<int> v, basis;
    set<int> span = {0};

    for (int x : a) {
        if (span.count(x)) continue;

        basis.push_back(x);
        vector<int> new_elems;
        for (auto y : span) new_elems.push_back(y ^ x);
        span.insert(new_elems.begin(), new_elems.end());

        if ((int)basis.size() == 32 - (int)__builtin_clz(x)) {
            sol = basis.size();
            v = basis;
        }
    }

    cout << sol << "\n";

    vector<int> perm = {0};

    for (int i = 0; i < sol; i++) {
        vector<int> t = perm;
        reverse(t.begin(), t.end());
        for (int &x : t) x ^= v[i];
        perm.insert(perm.end(), t.begin(), t.end());
    }

    for (int x : perm) cout << x << " "; 

    return 0;
}