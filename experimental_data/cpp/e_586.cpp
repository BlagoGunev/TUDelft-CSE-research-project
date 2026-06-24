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

ll a,b;

ll Ans[10000],Cnt;

int lx[10000],flag;

int main(){

	a=Rd(),b=Rd();

	Cnt=0;

	flag=1;

	while (a>1ll||b>1ll){

		if (a>b){

			Ans[++Cnt]=(a-1)/b;

			a-=(a-1)/b*b;

			lx[Cnt]=0;

		}

		else if (b>a){

			Ans[++Cnt]=(b-1)/a;

			b-=(b-1)/a*a;

			lx[Cnt]=1;

		}

		else{

			flag=0;

			break;

		}

	}

	if (!flag) puts("Impossible");

		else for (int i=1;i<=Cnt;i++){

			Rt(Ans[i]);

			if (lx[i]) printf("B");

				else printf("A");

		}

}