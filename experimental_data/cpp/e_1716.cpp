#include<bits/stdc++.h>

#define x first

#define y second

#define mem(a,b) memset(a,b,sizeof(a))

#define F(i,l,r) for(int i=l;i<=r;i++)

#define int long long

using namespace std;



typedef long long ll;

typedef pair<int,int> pii;



const int N=(1<<18)+10;



struct node

{

    int sum,lm,rm,tm;

};



int n,m,a[N];

vector<node> tr[4*N];

int cnt=0;

void pushup(node &u,node &l,node &r)

{

    u.sum=l.sum+r.sum;

    u.lm=max(l.lm,l.sum+r.lm);

    u.rm=max(r.rm,l.rm+r.sum);

    u.tm=max({l.tm,r.tm,l.rm+r.lm});

}



void build(int u,int l,int r)

{

    tr[u].resize(r-l+1);

    if(l==r)

    {

        tr[u][0].sum=a[l];

        tr[u][0].lm=tr[u][0].rm=tr[u][0].tm=max(0ll,a[l]);

        return;

    }

    int mid=(l+r)/2;

    build(u*2,l,mid);

    build(u*2+1,mid+1,r);

    for(int i=l;i<=r;i++)

    {

        if(i<=mid)

            pushup(tr[u][i-l],tr[u*2][i-l],tr[u*2+1][i-l]);

        else

            pushup(tr[u][i-l],tr[u*2+1][i-mid-1],tr[u*2][i-mid-1]);

        //cout<<i-l<<tr[u][i-l].lm<<tr[u][i-l].rm<<tr[u][i-l].sum<<tr[u][i-l].tm<<endl;

    }

}



signed main()

{

    ios::sync_with_stdio(false);

    cin.tie(0);

    cout.tie(0);

    cin>>n;

    n=(1<<n);

    for(int i=0;i<n;i++)

        cin>>a[i];

    build(1,0,n-1);



    cin>>m;

    int now=0;

    while(m--)

    {

        int k;

        cin>>k;

        now^=(1<<k);

        cout<<tr[1][now].tm<<'\n';

    }



    return 0;

}