/*** remain true to the original aspiration ***/
#include<bits/stdc++.h>

using namespace std;

typedef bool                   boo;
typedef int                    li;
typedef long                   il;
typedef unsigned long          ul;
typedef long long int          ll;
typedef unsigned long long     ull;
typedef double                 dd;
typedef string                 str;

#define vli 					vector<li>
#define vll 					vector<ll>
#define sli 					set<li>
#define sll 					set<ll>
#define pli 					pair < li , li >
#define pll 					pair < ll , ll >
#define vpi 					vector < pair < li , li > >
#define vpl 					vector < pair < ll , ll > >
#define mpi						map < li , li >
#define mpl 					map < ll , ll >

#define Test  				   	ll t; std :: cin >> t; while(t--)
#define input(a , n)            for( int i = 0 ; i < n ; i++ ) std :: cin >> a[i];
#define output(a , n)			for( int i = 0 ; i < n ; i++ ) std :: cout << a[i] << " ";
#define rep(i,a,n) 				for (int i=a;i<n;i++)
#define per(i,a,n) 				for (int i=n-1;i>=a;i--)
#define pb 						push_back
#define mp 						make_pair
#define all(x) 					(x).begin(),(x).end()
#define fi 						first
#define se 						second
#define Yes 					cout << "Yes" << endl
#define No 						cout << "No" << endl
#define YES 					cout << "YES" << endl
#define NO 						cout << "NO" << endl
#define Faster                	ios_base :: sync_with_stdio( 0 ); cin.tie( 0 ); cout.tie( 0 );

#define sz(x) 					((int)(x).size())
#define gcd(a , b)             	__gcd( a , b )
#define lcm(a , b)             	( a * ( b / gcd( a , b ) ) )
#define clz(x)					__builtin_clz(x)
#define ctz(x)					__builtin_ctz(x)
#define popcount(x)				__builtin_popcount(x)
#define ffs(x)					__builtin_ffs(x)
#define string(x)				to_string(x)
#define tolower(s)				transform(s.begin(),s.end(),s.begin(),(int (*)(int))tolower);
#define toupper(s)				transform(s.begin(),s.end(),s.begin(),(int (*)(int))toupper);
int dx[] = { -1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
int dx1[] = { -1, -1, -1, 0, 0, 0, 1, 1, 1};
int dy1[] = { -1, 0, 1, -1, 0, 1, -1, 0, 1};

const double eps =             1e-9;
const int inf =                2000000000;
const ll infLL =               9000000000000000000;
const ll mod =                 1e+7;
const double PI =              3.141592653589793238462643383279;

ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll intersection_region(ll x1,ll y1,ll x2,ll y2,ll x3,ll y3,ll x4,ll y4){return (min(x2,x4)-max(x1,x3))>=0&&(min(y2,y4)-min(y1,y3)>=0)?(min(x2,x4)-max(x1,x3))*(min(y2,y4)-max(y1,y3)):0;}
ll square(ll x1,ll y1,ll x2,ll y2){return abs(x2-x1)*abs(y2-y1);}
ll union_region(ll x1,ll y1,ll x2,ll y2,ll x3,ll y3,ll x4,ll y4){return square(x1,y1,x2,y2)+square(x3,y3,x4,y4)-intersection_region(x1,y1,x2,y2,x3,y3,x4,y4);}
template <class T>
inline T min(T a, T b, T c){ return min(min(a, b), c); }
template <class T>
inline T max(T a, T b, T c) { return max(max(a, b), c); }
template <class T>
inline T min(T a, T b, T c, T d) { return min(min(a, b), min(c, d)); }
template <class T>
inline T max(T a, T b, T c, T d) { return max(max(a, b), max(c, d)); }

///_____________________________________________ L E T ' S  B E G I N ____________________________________________________________
const int N=2e5+10;
int  arr[N];
int main()
{
	Faster;
	int n;
	cin>> n;
	rep(i,0,2*n)
	{
		char x;
		cin>>x;
		if(x=='+')arr[i]=-1;
		else 
		{
			int b;
			cin>>b;
			arr[i]=b;
		}
	}
	int flag=1;
	stack<int>srr;
	int brr[N];
	int k=0;
	for(int i=2*n-1;i>=0;i--)
	{
		
		if(srr.size())
		{
			if(arr[i]==-1)brr[k++]=srr.top(),srr.pop();
			else if(arr[i]<srr.top())srr.push(arr[i]);
			else flag=0;
		}else{
			if(arr[i]==-1)flag=0;
			else srr.push(arr[i]);
		}
	}
	if(flag)
	{
		YES;
		for(int i=k-1;i>=0;i--)cout<<brr[i]<<" ";
	}else NO;
}