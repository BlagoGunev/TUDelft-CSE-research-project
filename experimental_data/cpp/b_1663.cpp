#include<bits/stdc++.h>

#define ios ios::sync_with_stdio(false);cin.tie(0)

#define zf(i,l,r) for(int i=l;i<=r;i++)

#define df(i,r,l) for(int i=r;i>=l;i--)

#define itf(it,container) for(auto it=container.begin();it!=container.end();it++)

#define all(container) container.begin(),container.end()

#define vtr vector

#define sz(container) ((ll)(container).size())

#define ft first

#define snd second

#define ton(x) (x-'0')

#define pb push_back

#define mst(container,val) memset(container,val,sizeof(container))

#define ll long long

#define f2 double

#define sf scanf

#define pf printf

#define gcd __gcd

#define mid ((r+l)>>1)

using namespace std;

const ll inf=0x3f3f3f3f,INF=0x3f3f3f3f3f3f3f3f;

typedef struct ND{

	

}NODE;

ll _=1;

void solve(){

    int r;

    cin >> r;

    vector v{1200, 1400, 1600, 1900, 2100, 2300, 2400, 2600, 3000};

    cout << *upper_bound(v.begin(), v.end(), r) << '\n';

    return ;

}

int main(void)

{

    ios;

    // cin>>_;

    while(_--){

        solve();

    }

    return 0;

}