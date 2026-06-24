#include<bits/stdc++.h>
using namespace std;

// #pragma GCC optimize("Ofast,no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #pragma GCC optimize("unroll-loops")

typedef unsigned long long ull;
typedef long long          ll;
typedef long double        lld;
typedef vector<int>        vi;
typedef vector<ll>         vll;
typedef vector<vi>         vvi;
typedef pair<int,int >     pii;
typedef vector< pii >      vpii;
typedef set<int>           sti;

#define sc                 scanf
#define pf                 printf
#define sci(n)             scanf("%d",&n)
#define scii(n,m)          scanf("%d %d",&n,&m)
#define scl(n)             scanf("%lld",&n)
#define scd(n)             scanf("%lf",&n)
#define scs(s)             scanf("%s",s)
#define pfi(n)             printf("%d",n)
#define pfl(n)             printf("%lld",n)
#define pff(n)             cout<<n
#define spc                printf(" ")
#define line               printf("\n")
#define loop(i,x,y)        for(int i=int(x); i<=int(y); i++)
#define rloop(i,y,x)       for(int i=int(y); i>=int(x); i--)
#define cspf(i)            printf("Case %d: ", i)
#define vout(v)            for(int w=0;w<v.size();w++){if(w) cout<<' '; cout<<v[w];}
#define clr(a,x)           memset(a,x,sizeof(a))
#define tp(v,j)            get<j>(v)
#define pb                 push_back
#define mp                 make_pair
#define mt                 make_tuple
#define ff                 first
#define ss                 second
#define all(v)             v.begin(),v.end()
#define rall(v)            v.rbegin(),v.rend()
#define read()             freopen("input.txt", "r", stdin)
#define write()            freopen("output.txt", "w", stdout)
#define fastIO()           ios_base::sync_with_stdio(false); cin.tie(NULL);
/// Constants
#define eps                1e-6
#define PI                 acos(-1.0)  // 3.1415926535897932
#define MAX                (ll)1000000000009

int GCD(int a, int b) { return b == 0 ? a : GCD(b , a % b); }
ll LCM(ll a, ll b) { return a * (b/GCD(a, b)); }

char s[200005];

int main()
{
    #ifdef VAMP
        clock_t tStart = clock();
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n,k;
    scii(n,k);
    scs(s);
    bool f=false;
    int x = n;
    for(int i=0,j=k;j<n;i++,j++){
    	if(s[i]>s[j]){
    		if(x==n) x=j;
    		s[j]=s[i];
    	}
    	else if(s[i]<s[j]){
    		if(x<j) s[j]=s[i];
    		else{
    			for(int p=k-1;p>=0;p--){
    				if(s[p]=='9'){
    					s[p]='0';
    				}
    				else{
    					s[p]=s[p]+1;
    					break;
    				}
    			}
    			break;
    		}
    	}
    }
    for(int i=0,j=k;j<n;i++,j++){
    	s[j]=s[i];
    }
    pf("%d\n%s\n",n,s);

    #ifdef VAMP
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    #endif

    return 0;
}