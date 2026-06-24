#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ff first
#define ss second

using namespace std;

const double pi = acos(-1);
const int N = 1e6 + 6, mod = 998244353, M = 1e7 + 7;
const ll MAX = 5e18;

int c, t;
string s, ans;
vector<pii> v, p;
vector<int> m;

void add(int c, char t, bool b){
    for(int i = 0; i < c; i++){
        ans += t;
        m.pb(b);
    }
}

int main()
{
    cin >> s;
    t = s[0] - '0';
    for(char i : s){
        if(i - '0' != t){
            v.pb({c, t});
            t = i - '0';
            c = 1;
        }
        else
            c++;
    }
    v.pb({c, t});
    c = v.size();
    for(int i = 0; i < c; i++){
        if(v[i].ss == 0)
            add(v[i].ff, '0', 0);
        else if(i == c - 1)
            add(v[i].ff, '0', 0);
        else{
            if(v[i + 1].ff >= v[i].ff){
                add(v[i].ff, '1', 0);
                p.pb({v[i + 1].ff - v[i].ff, ans.size()});
            }
            else{
                add(v[i].ff - v[i + 1].ff, '0', 1);
                add(v[i + 1].ff, '1', 0);
            }
        }
    }
    c = s.size();
    t = 0;
    for(int i = c - 1; i >= 0; i--){
        if(p.size() && i == p.back().ss){
            t += p.back().ff;
            p.pop_back();
        }
        if(m[i] && t)
            t--, ans[i] = '1';
    }
    cout << ans;
    return 0;
}