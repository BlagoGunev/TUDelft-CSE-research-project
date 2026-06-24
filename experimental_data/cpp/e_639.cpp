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

#define Rep(x,a,b) for (int x=a;x<=(int)b;x++)

#define Drp(x,a,b) for (int x=a;x>=(int)b;x--)

#define Cross(x,a) for (int x=Hd[a];~x;x=Nx[x])

#define ll long long

#define INF (1<<29)

#define PII pair<int,int>

#define PDD pair<double,double>

#define mk(a,b) make_pair(a,b)

#define fr first

#define sc second

using namespace std;

inline ll Rd(){

	ll x=0;int ch=getchar(),f=1;

	while (!isdigit(ch)&&(ch!='-')&&(ch!=EOF)) ch=getchar();

	if (ch=='-'){f=-1;ch=getchar();}

	while (isdigit(ch)){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}

	return x*f;

}

inline void Rt(ll x){

	if (x<0) putchar('-'),x=-x;

	if (x>=10) Rt(x/10),putchar(x%10+'0');

		else putchar(x+'0');

}

const int N=150005;

ll T;

struct Prob{

	ll p,t,Mn,Mx;

}a[N];

ll n,Cnt;

bool cmp1(Prob a,Prob b){return a.p*b.t>b.p*a.t;}

bool cmp2(Prob a,Prob b){return a.p<b.p;}

int main(){

	n=Rd();

	Rep(i,1,n) a[i].p=Rd();

	Rep(i,1,n) a[i].t=Rd(),T+=a[i].t;

	sort(a+1,a+n+1,cmp1);

	ll nT=0,tT;

	for (int i=1,j=1;j<n;i=j+1){

		while (j<n&&a[i].p*a[j+1].t==a[j+1].p*a[i].t) j++;

		tT=nT;

		Rep(k,i,j) tT+=a[k].t;

		Rep(k,i,j) a[k].Mn=nT+a[k].t,a[k].Mx=tT;

		nT=tT;

	}

	sort(a+1,a+n+1,cmp2);

	Cnt=1;

	Rep(i,2,n){

		if (a[i].p==a[Cnt].p) a[Cnt].Mn=min(a[Cnt].Mn,a[i].Mn),a[Cnt].Mx=max(a[Cnt].Mx,a[i].Mx);

			else a[++Cnt]=a[i];

	}

	double c=1;

	Rep(i,1,Cnt-1){

		double Fz=1.0*T*(a[i+1].p-a[i].p),Fm=1.0*a[i+1].p*a[i+1].Mx-1.0*a[i].p*a[i].Mn;

		if (Fm<=0) continue;

		c=min(c,Fz/Fm);

	}

	printf("%.10lf\n",c);

}