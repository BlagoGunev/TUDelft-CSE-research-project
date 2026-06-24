#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
ostream& operator<<(ostream& out, vector <int>& v) {
    for (auto x : v) {
        cout << x << " ";
    }
    return out;
}

istream& operator>>(istream& in, vector <int>& v) {
    for (int i = 0; i < v.size(); i++) in >> v[i];
    return in;
}

bool comp (string a, string b) {return a.size() < b.size();}
void solve () {
    int n; cin >> n;
    vector<int> a(n);
    cin >> a;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) a[i]++;
    }
    for (int i = 1; i < n; i++) {
        if (a[i] % a[i - 1] == 0) {
            a[i]++;
        }
    }
    cout << a << endl;
}
int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}