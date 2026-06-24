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

#define fs first

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

#define mod 1000000007

int p,k;

int qpow(int a,int b,int p){

	int ret=1;

	for (;b;b>>=1,a=(ll)a*a%p) if (b&1) ret=(ll)ret*a%p;

	return ret;

}

int main(){

	p=rd(),k=rd();

	if (!k) return rt(qpow(p,p-1,mod)),0;

	if (k==1) return rt(qpow(p,p,mod)),0;

	int x=k,l=1;

	while (x!=1) x=(ll)x*k%p,l++;

	if (qpow(k,l,p)==1) rt(qpow(p,(p-1)/l,mod));

		else rt(1);

}