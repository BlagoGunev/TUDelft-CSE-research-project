#include <bits/stdc++.h>

using namespace std;
const int c=6000005, mod=1e9+7;
const long long maxval=2e9;
long long n, sum, par[c], db[c], po[c], po2[c];
vector<int> sor;
long long calc(long long a) {
    return par[a]*po2[db[a]];
}
long long val(long long a) {
    return par[a]*po[db[a]]%mod;
}
void solve() {
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        while (x%2==0) {
            db[i]++;
            x/=2;
        }
        par[i]=x;


        while (sor.size()>0 && calc(i)>=par[sor.back()]) {
            int ut=sor.back();
            sum-=val(ut);
            db[i]+=db[ut];
            db[ut]=0;
            sum+=val(ut);
            sor.pop_back();
        }
        sum+=val(i);
        sor.push_back(i);
        sum=((sum%mod)+mod)%mod;
        cout << sum << " ";
    }
    cout << "\n";

    sum=0;
    sor.clear();
    for (int i=0; i<=n; i++) {
        par[i]=0, db[i]=0;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    po[0]=1, po2[0]=1;
    for (int i=1; i<c; i++) {
        po[i]=po[i-1]*2%mod;
        po2[i]=min(po2[i-1]*2, maxval);
    }
    int w;
    cin >> w;
    while (w--) {
        solve();
    }
    return 0;
}
/*
1
10
1 2 3 4 5 6 7 8 9 10
*/