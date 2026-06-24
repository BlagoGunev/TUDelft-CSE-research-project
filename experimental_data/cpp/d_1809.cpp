#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

ifstream infile;
ofstream outfile;

ll mod = 1e9+7;
const ll MAXN = 1e18+1;
const ll C = 1e12;
string s;

void solve() {
    cin>>s;
    ll left, right, n = s.length();
    ll i;
    for (i=0;i<n;i++) {
        if (s[i]=='1') break;
    }
    left = i;
    for (i = n-1;i>=0;i--) {
        if (s[i]=='0') break;
    }
    right = i;
    if (right<=left) {
        cout<<"0\n";
        return;
    }

    vector<ll> pref0(n+1), pref1(n+1);
    pref0[0] = 0; pref1[0] = 0;
    for (i=0;i<n;i++) {
        pref0[i+1] = pref0[i];
        pref1[i+1] = pref1[i];
        if (s[i]=='0') pref0[i+1]++;
        else pref1[i+1]++;
    }

    vector<ll> prev0(n), next1(n);
    ll current = -1;
    for (i = left; i<=right; i++) {
        prev0[i] = current;
        if (s[i]=='0') current = i;
    }
    current = -1;
    for (i = right; i>=left; i--) {
        next1[i] = current;
        if (s[i]=='1') current = i;
    }

    /*
    cout<<left<<' '<<right<<'\n';
    for (i=left; i<= right; i++) cout<<prev0[i]<<' ';
    cout<<'\n';
    for (i=left; i<= right; i++) cout<<next1[i]<<' ';
    cout<<'\n';
    */
    ll a,b, cost, ans = MAXN;
    ll opswap = C, oprem = C+1, diff, toremove;
    if (next1[left]==-1) {
        diff = right-left;
        cost = opswap*diff;
    }
    else {
        diff = next1[left] - left - 1;
        cost = opswap*diff;
        toremove = pref0[right+1] - pref0[next1[left]];
        cost += toremove*oprem;
    }
    ans = min(cost, ans);
    //cout<<ans<<'\n';

    if (prev0[right]==-1) {
        diff = right-left;
        cost = opswap*diff;
    }
    else {
        diff = right - prev0[right] - 1;
        cost = opswap*diff;
        toremove = pref1[prev0[right]+1] - pref1[left];
        cost += toremove*oprem;
    }
    ans = min(cost, ans);
    //cout<<ans<<'\n';

    ll ontheleft, ontheright;
    for (i=left; i<right; i++) {
        a = i; b = i+1;
        cost = 0; ontheleft = 0; ontheright = 0;
        if (s[a]=='0' && s[b]=='1') {
            if (s[a]=='0' && prev0[a]!=-1) ontheleft = a - prev0[a] - 1;
            if (s[b]=='1' && next1[b]!=-1) ontheright = next1[b] - b - 1;
        }
        if (s[a]=='1' && s[b]=='0') cost += opswap;
        else if (s[a]=='1' && s[b] == '1') a = b;
        else b = a;
        if (ontheleft>ontheright) {
            cost += opswap * ontheleft;
            a -= ontheleft;
        }
        else {
            cost += opswap * ontheright;
            b += ontheright;
        }

        toremove = pref1[a] - pref1[left];
        cost += oprem*toremove;
        toremove = pref0[right+1] - pref0[b+1];
        cost += oprem*toremove;
        //cout<<cost<<'\n';
        ans = min(cost, ans);
    }
    cout<<ans<<'\n';
}
    

int main() {
    //infile.open("in.txt"); outfile.open("out.txt");
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    //t=1;
    cin >> t;
    while (t--) solve();
    //infile.close(); outfile.close();
}