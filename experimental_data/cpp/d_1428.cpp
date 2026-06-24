#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define ii pair<int,int>
#define name ""
const int N = 1e5 + 7;
const int mod = 1e9 + 7;
const int INF = 1e9;
int n;
int a[2 * N],dd[2 * N];
ii res[2 * N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }

    int down = n;

    set< pair<int,ii> >s1,s2;
    int cnt = 0;
    for(int i = n;i >= 1;i--){
        if(a[i] == 1){
            res[++cnt] = {down,i};
            s1.insert({1,{down,i}});
            s2.insert({1,{down,i}});
            down--;
        }
        if(a[i] == 2){
            if(s1.empty())return cout << -1,0;
            auto k = *s1.begin();
            s1.erase(k);
            s2.erase(k);
            res[++cnt] = {k.se.fi,i};
            s2.insert({0,{k.se.fi,i}});
        }
        if(a[i] == 3){
            if(s2.empty())return cout << -1,0;
            auto k = *s2.begin();
            s1.erase(k);
            s2.erase(k);
            res[++cnt] = {down,i};
            res[++cnt] = {down,k.se.se};
            s2.insert({0,{down,i}});
            down--;
        }
    }
    if(cnt > 2 * n){
        cout << -1;
        return 0;
    }
    cout << cnt << '\n';
    for(int i = 1;i <= cnt;i++){

        cout << res[i].fi << ' ' << res[i].se << '\n';
    }

    return 0;
}
/*
5
2 3 1 2 1
*/