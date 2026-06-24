#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define endl '\n'


#define file(in, out)                                                        \
  freopen(in, "r", stdin);                                                     \
  freopen(out, "w", stdout)

#define FIn                                                                    \
  cin.tie(0);                                                                  \
  cout.tie(0);                                                                 \
  ios_base::sync_with_stdio(false)

int tc;
const bool MULTI_TESTS = true;
const string IN = "input.txt";
const string OUT = "output.txt";
const int N = 3e5 + 10;
const int MOD = 1e9 + 7;


void pre();
// check MAX_N
int l, r;
void solve() {
    cin >> l >> r;
    int ops = 0;
    while(l + 2 <= r){
        if(~l & 1)l++;
        else  l += 3, ops++;
    }
    cout<<ops<<'\n';
}

int main() {
    FIn;
#ifndef ONLINE_JUDGE
    file(IN.c_str(), OUT.c_str());
#endif

    tc = 1;
    if (MULTI_TESTS) cin >> tc;
    pre();

    for (int i = 1; i <= tc; i++) {
        // cout << "Case " << i <<": \n";
        solve();
    }
}

void pre() {

}