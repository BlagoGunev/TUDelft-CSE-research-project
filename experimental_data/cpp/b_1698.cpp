#pragma GCC optimize(3)

#include<bits/stdc++.h>

using namespace std;

#define ri int

#define INF 1e18

#define inf -1e18

#define fi first

#define se second

#define sz(x) ((int)(x).size())

#define pb push_back

#define YES printf("YES\n")

#define NO printf("NO\n")

#define debug puts("\n--------------------\n")

#define DEBUG printf("Passing [%s] in LINE %d\n", __FUNCTION__, __LINE__)

#define int long long

typedef double db;

typedef long long ll;

typedef unsigned long long ull;

const int mod=1000000007;

const int N =2e5+10;

ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}



//head

template <typename T>inline void read(T& t)

{

    ri rc = getchar(); t = 0;

	ri rf=1;

    while (!isdigit(rc))

	{

		if(rc=='-')rf=-1;

		rc = getchar();

	}

    while (isdigit(rc))t = t * 10 + rc - 48, rc = getchar();

	t*=rf;

}

template <typename T, typename... Args> inline void read(T& t, Args&... args)

{

    read(t); read(args...);

}

template < typename T > inline void write ( T x ) 

{

    if ( x < 0 ) x = -x, putchar ( '-' );

    if ( x > 9 ) write ( x / 10 );

    putchar ( x % 10 + 48 );

}

template < typename T > inline void write_ ( T x ) 

{

    write(x);putchar(' ');

}

template < typename T > inline void writen ( T x ) 

{

    write(x);puts("");

}

template <typename T, typename... Args> inline void write(T x, Args&... args)

{

    write(x);putchar(' ');write(args...);

}

//speed

int a[N];

void solve()

{

	int n,k;read(n,k);

    for(int i=1;i<=n;++i) read(a[i]);

    if(k==1){

        int res=0;

        if(n%2)res=n/2;

        else res=n/2-1;

        writen(res);

        return ;

    }

    int res=0;

    for(int i=2;i<n;++i)

    {

        if(a[i]>a[i-1]+a[i+1])res++;

    }

    writen(res);

}

signed main()

{

	int t=1;

	read(t);

	while(t--)solve();

	return 0;

}