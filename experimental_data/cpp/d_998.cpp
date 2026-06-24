#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define ld long double
using namespace std;

ll num[]={1,5,10,50},ans,n;
vector<ll> r;
map< ll, vector<ll> > use;

void fn(ll pos,ll falta){
    if(pos>3){
        ///use.insert(r[0]+5LL*r[1]+10LL*r[2]+50LL*r[3]);
        ll val=r[0]+5LL*r[1]+10LL*r[2]+50LL*r[3];
        /*if(use.find(val)!=use.end()){
            cout << val << ":\n";
            cout << r[0] << " " << r[1] << " " << r[2] << " " << r[3] << "\n";
            cout << use[val][0] << " " << use[val][1] << " " << use[val][2] << " " << use[val][3] << "\n";
        }*/
        use[val]=r;
        ans++;
        return;
    }

    if(pos==3) { r[3]=falta; fn(pos+1,0); return; }
    for(ll i=0; i<=falta; i++){
        r[pos]=i;
        fn(pos+1,falta-i);
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    r.resize(4);

    if(n<=11){
        fn(0,n);
        cout << use.size();
        return 0;
    }

    fn(0,11);
    cout << use.size()+49LL*(n-11);

    return 0;
}