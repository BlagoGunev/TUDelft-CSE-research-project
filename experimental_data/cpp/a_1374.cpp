#include<bits/stdc++.h>
using namespace std;

using ll  = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

#define PI    acos(-1.0)
#define INF32 0x3f3f3f3f
#define INF64 0x3f3f3f3f3f3f3f3f 

#define NL '\n'
#define xx first
#define yy second
#define mp make_pair
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define mem(a, b) memset(a, b, sizeof(a))
#define rep(i,a,b) for(ll i = (ll)a; i < (ll)b; ++i)
#define fastIO() ios_base::sync_with_stdio(0),cin.tie(NULL)
 
template<class T>void read(T &x){int q=1;char ch;x=0;for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar()); 
if(ch == '-')ch=getchar(),q =-1;for(;'0'<=ch&&ch<='9';ch=getchar()) x=x*10 + ch-'0'; x*=q;} template<class T>  
void write(T x){if(x<0)putchar('-'),write(-x);else if(x<10)putchar(x+'0');else write(x/10),putchar(x%10+'0');}

#define _yyz 
void dbg(){cerr<<NL;}template<typename H,typename... T> void dbg(H h,T... t){cerr<<' '<<h;dbg(t... );}
#ifdef  _yyz
#define debug(...) cerr<<"("<<#__VA_ARGS__<<"):",dbg(__VA_ARGS__)
#else
#define debug(...) 
#endif
 


 
 
void absinthe(){
	int x, y, n;
	read(x); read(y); read(n);
	int k = (n-y)%x;
	k = n - k;
	write(k), putchar(NL);
}
 
int main(){
	int Tx = 1; read(Tx);  
	//fastIO();   cin >> Tx;
	while(Tx--) absinthe();
}