#include <bits/stdc++.h>



using namespace std;

#define rep(i,n) for(int i = 0; i < n; ++i)

#define Rep(i,n) for(int i = 1; i <= n; ++i)

#define lowbit(x) ((x)&(-x))

//#pragma comment(linker,"/STACK:1024000000,1024000000")

#define eps 1e-6

#define sqr(x) ((x)*(x))

#define pb(x) push_back(x)

typedef long long ll;

typedef long double ld;

typedef pair<int, int> pii;

typedef pair<ll, ll> pll;

typedef pair<ld, ld> pdd;

template<class T>inline void rread(T&num){

    num=0;T f=1;char ch=getchar();

    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}

    while(ch>='0'&&ch<='9')num=num*10+ch-'0',ch=getchar();

    num*=f;

}

const int inf = 2e9, mod = 1e9 + 7;

const int maxn = 2e5 +10;

const ld PI = acos(-1.0);

ll gcd (ll a, ll b)

{return ( a ? gcd(b%a, a) : b );}

void exgcd(ll a,ll b,ll &d,ll& x,ll& y)

{

    if(!b){d=a;x=1;y=0;}

    else {exgcd(b,a%b,d,y,x);y-=x*(a/b);}

}

ll power(ll a, ll n)

{ll p = 1;while (n > 0) {if(n%2) {p = p * a;} n >>= 1; a *= a;} return p;}

ll power(ll a, ll n, ll mod)

{ll p = 1;while (n > 0) {if(n%2) {p = p * a; p %= mod;} n >>= 1; a *= a; a %= mod;} return p % mod;}

//head



int n,m;

int a[maxn],b[maxn];

vector<int>pa[maxn],pb[maxn];

pair<ll,int>pp;

vector< pair<ll,int> >ss;

set<ll>fl,gl;

ll phi(ll x)

{

    ll gs=sqrt(x+0.5);

    ll ans=x;

    for(int i=2;i<=gs;i++)

        if(x%i==0)

    {

        ans=ans/i*(i-1);

        while(x%i==0)

            x/=i;

    }

    if(x!=1)

    {

        ans=ans/x*(x-1);

    }

    return ans;

}

int main()

{

    while(~scanf("%d%d",&n,&m))

    {

        int x,y;

        scanf("%d",&x);

        for(int i=1;i<=x;i++)

            scanf("%d",&a[i]);

        scanf("%d",&y);

        for(int i=1;i<=y;i++)

            scanf("%d",&b[i]);

        ll d=gcd(n,m);

        if(d>x+y)

        {

            cout<<-1<<endl;continue;

        }

        for(int i=0;i<d;i++)

            pa[i].clear(),pb[i].clear();

        for(int i=1;i<=x;i++)

        {

            pa[a[i]%d].pb(a[i]/d);

        }

        for(int i=1;i<=y;i++)

            pb[b[i]%d].pb(b[i]/d);

        for(int i=0;i<d;i++)

            if(pa[i].size()==0&&pb[i].size()==0)

        {

            cout<<-1<<endl;return 0;

        }

        ll ans=0;

        ll g=n/d,s=m/d;

        ll px=phi(g),py=phi(s);

        for(int i=0;i<d;i++){

            sort(pa[i].begin(),pa[i].end());

            sort(pb[i].begin(),pb[i].end());

            if(pa[i].size()!=g&&pb[i].size()!=s)

        {



            ss.clear();

            gl.clear();fl.clear();

            ll sum=0;

            for(int j=0;j<pb[i].size();j++)

            {

                fl.insert(pb[i][j]);

                ll cur=pb[i][j];

                cur=power(g%s,py-1,s)*cur%s;

                pp.first=cur;pp.second=pb[i][j];

                ss.pb(pp);

            }

            for(int j=0;j<pa[i].size();j++)

                if(fl.count(pa[i][j]%s)==0)

            {

                fl.insert(pa[i][j]%s);

                ll cur=pa[i][j]%s;

                cur=power(g%s,py-1,s)*cur%s;

                pp.first=cur;pp.second=pa[i][j];

                ss.pb(pp);

            }

            sort(ss.begin(),ss.end());

            ss.pb(ss[ss.size()-1]);

            ll maxx=0,id=0,cc;

            for(int j=1;j<ss.size();j++)

            {

                cc=ss[j].first-ss[j-1].first-1;

                if(cc*g+ss[j-1].second>maxx)

                    maxx=cc*g+ss[j-1].second;

            }

            cc=ss[0].first+s-ss[ss.size()-1].first-1;

            if(cc*g+ss[ss.size()-1].second>maxx)

                maxx=cc*g+ss[ss.size()-1].second;

            sum=maxx*d+i;





            ss.clear();fl.clear();gl.clear();

            for(int j=0;j<pa[i].size();j++)

            {

                fl.insert(pa[i][j]);

                ll cur=pa[i][j];

                cur=power(s%g,px-1,g)*cur%g;

                pp.first=cur;pp.second=pa[i][j];

                ss.pb(pp);

            }

            for(int j=0;j<pb[i].size();j++)

                if(fl.count(pb[i][j]%g)==0)

            {

                fl.insert(pb[i][j]%g);

                ll cur=pb[i][j]%g;

                cur=power(s%g,px-1,g)*cur%g;

                pp.first=cur;pp.second=pb[i][j];

                ss.pb(pp);

            }

            sort(ss.begin(),ss.end());

            ss.pb(ss[ss.size()-1]);

            maxx=0,id=0;

         for(int j=1;j<ss.size();j++)

            {



                cc=ss[j].first-ss[j-1].first-1;

                if(cc*s+ss[j-1].second>maxx)

                    maxx=cc*s+ss[j-1].second;

            }

            cc=ss[0].first+g-ss[ss.size()-1].first-1;

            if(cc*s+ss[ss.size()-1].second>maxx)

                maxx=cc*s+ss[ss.size()-1].second;

            sum=max(sum,maxx*d+i);

            ans=max(ans,sum);

        }

        else if(pa[i].size()==g)

            {

                ll cur=s-1;

                for(int j=pb[i].size()-1;j>=0;j--)

                    if(pb[i][j]!=cur)

                    break;

                else {cur--;}

                ans=max(ans,cur*d+i);

            }

        else if(pb[i].size()==s)

            {

                ll cur=g-1;

                for(int j=pa[i].size()-1;j>=0;j--)

                    if(pa[i][j]!=cur)

                    break;

                else {cur--;}

                ans=max(ans,cur*d+i);

            }

        }

        cout<<ans<<endl;

    }





    return 0;

}