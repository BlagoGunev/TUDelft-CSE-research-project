#include <bits/stdc++.h>
#include <bits/stdc++.h>

using namespace std;

typedef  long long ll;

double pi=3.1415926535898;

#define speed      ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

#define scarr(a,s,e) for(int i=s;i<=int(e);i++) scanf("%d ",&a[i]);

#define prarr(a,s,e) for(int i=s;i<=int(e);i++) printf("%d ",a[i]);

#define rng(i,a,b) for(int i=a;i>=int(b);i--)

#define rep(i,a,b) for(int i=a;i<=int(b);++i)

#define lop(i,n)   for(int i=0;i<int(n);i++)

#define ms(x,a)    memset(x,a,sizeof(x))

#define all(x)     (x).begin(),(x).end()

#define sz(x)      x.size()

#define pb         push_back

#define mp         make_pair

#define fi         first

#define se         second

#define sc(x)      scanf("%d",&x)

#define pr(x)      printf("%d ",x)

#define scl(x)     scanf("%lld",&x)

#define prl(x)     printf("%lld ",x)

#define prln(x)    printf("%d\n",x)

#define r0         return 0;

#define odd(x) (x&1)

#define evn(x) (!(x&1))

#define get getchar

#define max(a,b) a<b?b:a

/*

typedef pair<int,int> ii;

typedef vector <int>  vi;

freopen("output.txt","w",stdout);

freopen("input.txt","r",stdin);



for (int i=0;i<n;i++)            Hi    ^_^  hack me if you can :P

*/

inline ll inp()

{

    ll n=0,s=1;

    char p=get();

    if(p=='-')

    s=-1;

    while((p<'0'||p>'9')&&p!=EOF)

    p=get();

    while(p>='0'&&p<='9')

    {

    n = (n<< 3) + (n<< 1) + (p - '0');

    p=get();

    };

    return n*s;

}

const ll M   = 1<<30 ;

const int ss = 100100 ;

ll h;

ll a[100001];

ll n,q,x,y;

int main()

{

    n=inp();

    rep(i,1,n){

    a[i]=inp();

    }

    q=inp();

    while(q--){

        x=inp();

        y=inp();

        h = max (h , (ll)a[x]);

        printf("%lld\n",h);

        h+=1LL*y;

    }



    r0;

}

/*

ll pwmod(ll a, ll n, ll mod) {

    ll ret = 1;

    while (n) {

        if (n & 1) ret = ret * a % mod;

        a = a * a % mod;

        n >>= 1;

    }

    return ret;

}

*/