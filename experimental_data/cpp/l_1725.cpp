#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rnd(int l,int r)

{

    return l+rng()%(r-l+1);

}

#define fasty ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

#define fori(x,a,b) for(int x=a;x<=b;x++)

#define ford(x,a,b) for(int x=a;x>=b;x--)

#define iii pair<ii,int>

#define fi first

#define se second

#define ii pair<int,int>

#define all(x) x.begin(),x.end()

#define int long long

#define getbit(x,i) ((x>>(i))&1)

#define batbit(x,i) (x|(1ll<<(i)))

#define tatbit(x,i) (x&~(1<<(i)))

using namespace std;

const int N=1e5+10,mod=998244353;

int a[N],b[N],n;

int c[N],bit[N];

void up(int pos)

{

    while(pos)

    {

        bit[pos]++;

        pos-=(pos&(-pos));

    }

}

int get(int pos)

{

    int res=0;

    while(pos<=n)

    {

        res+=bit[pos];

        pos+=(pos&(-pos));

    }

    return res;

}

main()

{

    fasty;

    if(fopen("task.inp","r"))

    {

        freopen("task.inp","r",stdin);

        freopen("task.out","w",stdout);

    }

    cin>>n;

    vector<int> vt;

    fori(i,1,n) {

        cin>>a[i];

        b[i]=b[i-1]+a[i];

        vt.push_back(b[i]);

    }

    fori(i,1,n) if(b[i]<b[0]||b[i]>b[n]) return cout<<-1,0;

    sort(all(vt));

    vt.resize(unique(all(vt))-vt.begin());

    fori(i,1,n) b[i]=upper_bound(all(vt),b[i])-vt.begin();

    int ans=0;

//    fori(i,1,n) cout<<b[i]<<" ";cout<<"\n";

    fori(i,1,n)

    {

//        cout<<get(b[i]+1)<<" ";

        ans+=get(b[i]+1);

        up(b[i]);

    }

//    cout<<"\n";

    cout<<ans<<"\n";

}