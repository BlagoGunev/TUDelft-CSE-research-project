#include<cstdio>

#include<cstring>

#include<algorithm>

#include<cctype>

#include<ctime>

#include<cstdlib>

#include<string>

#include<queue>

#include<cmath>

#include<set>

#include<map>

#include<bitset>

#include<vector>

#define rep(x,a,b) for (int x=a;x<=(int)b;x++)

#define drp(x,a,b) for (int x=a;x>=(int)b;x--)

#define cross(x,a) for (int x=hd[a];~x;x=nx[x])

#define ll long long

#define inf (1<<29)

#define PII pair<int,int>

#define PDD pair<double,double>

#define mk(a,b) make_pair(a,b)

#define fr first

#define sc second

#define pb push_back

using namespace std;

inline ll rd(){

	ll x=0;int ch=getchar(),f=1;

	while (!isdigit(ch)&&(ch!='-')&&(ch!=EOF)) ch=getchar();

	if (ch=='-'){f=-1;ch=getchar();}

	while (isdigit(ch)){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}

	return x*f;

}

inline void rt(ll x){

	if (x<0) putchar('-'),x=-x;

	if (x>=10) rt(x/10),putchar(x%10+'0');

		else putchar(x+'0');

}

int n,px,py;

ll a[505][505];

int main(){

	n=rd();

	rep(i,1,n) rep(j,1,n){a[i][j]=rd();if (!a[i][j]) px=i,py=j;}

	if (n==1) return puts("1"),0;

	ll sum=0;

	if (px!=1) rep(j,1,n) sum+=a[1][j];

		else rep(j,1,n) sum+=a[2][j];

	ll ts=0,ans;

	rep(j,1,n) ts+=a[px][j];

	ans=sum-ts;

	if (ans<=0) return puts("-1"),0;

	a[px][py]=ans;

	rep(i,1,n){

		ll ns=0;

		rep(j,1,n) ns+=a[i][j];

		if (ns!=sum) return puts("-1"),0;

	}

	rep(j,1,n){

		ll ns=0;

		rep(i,1,n) ns+=a[i][j];

		if (ns!=sum) return puts("-1"),0;

	}

	ll ns=0;

	rep(i,1,n) ns+=a[i][i];

	if (ns!=sum) return puts("-1"),0;

	ns=0;

	rep(i,1,n) ns+=a[i][n-i+1];

	if (ns!=sum) return puts("-1"),0;

	rt(ans);

}