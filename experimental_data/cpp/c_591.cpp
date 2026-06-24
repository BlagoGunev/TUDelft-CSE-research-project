#include <bits/stdc++.h>

using namespace std;

#define X first

#define Y second

#define mp make_pair

#define pb push_back

#define mset(a,b) memset(a,b,sizeof a)

#define mcpy(a,b) memcpy(a,b,sizeof a)

#define R(i,s,t) for(register int i=s;i<=t;++i)

#define Rd(i,s,t) for(register int i=s;i>=t;--i)

#define __ puts("")

#define _ putchar(' ')

#define all(T) T.begin(),T.end()

typedef long long ll;

typedef pair<int,int> pii;

typedef vector<int> vi;

typedef vector<pii> vii;

template <class T> T abs(T a){return a>=0?a:-a;}

template <class T> T gcd(T a,T b){return b?gcd(b,a%b):a;}

template <class T> T mod(T a,T b){T ret=a%b;if(ret<0)ret+=b;return ret;}

ll mulmod(ll a,ll b,ll c){if(b==0LL)return 0LL;ll ret=mulmod(a,b>>1,c);ret=(ret+ret)%c;if(b&1LL)ret=(ret+a)%c;return ret;}

ll powmod(ll a,ll b,ll c){if(b==0LL)return 1LL;ll ret=powmod(a,b>>1,c);ret=ret*ret%c;if(b&1LL)ret=ret*a%c;return ret;}

template <class T> inline void write(T x){if (x<0)putchar('-'),x=-x;if (x<10)putchar(x + '0');else write(x / 10), putchar(x % 10 + '0');}

template <class T> inline void read(T&x){bool f=0; char ch;for(ch=getchar();ch<=32;ch=getchar());if (ch=='-')f=1,ch=getchar();for(x=0;ch>32;ch=getchar()) x =(x<<3)+(x<<1)+ch-'0';if(f) x=-x;}

//===========================================================================================

int a[500005],n,ans,L,R;

inline int gan(int L,int R){

	int len=R-L-1;

	if(len<=0)return 0;

	if(len&1){

		R(i,L+1,R-1)a[i]=a[L];

		return (len+1>>1);

	}

	else{

		R(i,L+1,L+(len>>1))a[i]=a[L];

		R(i,R-(len>>1),R-1)a[i]=a[R];

		return (len>>1);

	}

}

int main(){

	read(n);

	R(i,1,n)read(a[i]);

	for(L=1;L<=n;L=R+1){

		for(R=L;R+1<=n&&a[R+1]!=a[R];R++);

		ans=max(ans,gan(L,R));

	}

	write(ans),__;

	R(i,1,n-1)write(a[i]),_;

	write(a[n]),__;

	return 0;

}