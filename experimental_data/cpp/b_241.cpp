#include <cstdio>

#include <cstring>

#include <algorithm>

using namespace std;

typedef long long ll;

#define N 50010

#define M 1000010

const ll mod=1e9+7;

struct rec{

    int s[2];

    int num,c[30][2];

}t[M];

int n,cnt=1,num;

int a[N];

ll m,tmp;

void updata(int &x,int k,int dep)

{

    if(!x) x=++cnt;

    if(dep<0){++t[x].num;return;}

    updata(t[x].s[(k>>dep)&1],k,dep-1);

    t[x].num=t[t[x].s[0]].num+t[t[x].s[1]].num;

}

void doing(int x,int k,int dep)

{

    if(!x) return;

    if(dep==0){t[x].c[0][k]=t[x].num;return;}

    for(int kk=0;kk<=1;++kk)

    {

        doing(t[x].s[kk],kk,dep-1);

        for(int i=0;i<dep;++i)

            for(int j=0;j<=1;++j)

                t[x].c[i][j]+=t[t[x].s[kk]].c[i][j];

    }

    if(dep<30) t[x].c[dep][k]+=t[x].num;

}

int Find(int x,int w,int dep,int z)

{

    if(!x) return 0;

    if(dep==z) return x;

    return Find(t[x].s[(w>>dep)&1],w,dep-1,z);

}

void calc(int w,int dep)

{

    int y;

    for(int i=1;i<=n;++i)

    {

        y=Find(1,a[i]^w,29,dep-1);

        if(!y) continue;

        num+=t[y].num;

        tmp+=(ll)w*t[y].num;

        for(int j=0;j<dep;++j)

            tmp+=(ll)t[y].c[j][(a[i]>>j)&1^1]<<j;

    }

}

int main()

{

    int root=1;

    scanf("%d%I64d",&n,&m);

    m<<=1;

    for(int i=1;i<=n;++i)

    {

        scanf("%d",&a[i]);

        updata(root,a[i],29);

    }

    doing(root,0,30);

    int k=0;

    ll ans=0;

    for(int i=29;i>=0;--i)

    {

        k|=1<<i;

        tmp=0;num=0;

        calc(k,i);

        if(num<=m)

        {

            m-=num;

            ans+=tmp;

            k^=1<<i;

        }

    }

    calc(k,0);ans+=tmp/num*m;

    printf("%I64d\n",(ans>>1)%mod);

    return 0;

}