#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

#define all(x) x.begin(), x.end()

struct MS {
    ll m;
    ll s;

    bool operator<(const MS& other) const {
        return m < other.m;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test = 1;
    cin >> test;
    while(test--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        s = "1" + s + "1";
        bool alice = false;
        for(int i = 0; i < n+1; ++i) {
            if(s[i] == '1' && s[i+1] == '1') alice = true;
        }
        if(alice) cout << "YES\n";
        else cout << "NO\n";
    }
}