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

const int N=100005,M=100005;

int Fa[N],Val[N],Dep[N];

int n,m,Ans1,Ans2;

int GetFa(int x){

	if (x==Fa[x]) return x;

	int F=Fa[x];

	Fa[x]=GetFa(Fa[x]);

	Val[x]=Val[x]^Val[F];

	return Fa[x];

}

int main(){

	n=Rd(),m=Rd();

	Rep(i,1,n) Fa[i]=i,Val[i]=0,Dep[i]=1;

	Rep(i,1,m){

		int u=Rd(),v=Rd();

		int Fu=GetFa(u),Fv=GetFa(v);

		if (Fu==Fv){

			if (Val[u]==Val[v]) return puts("-1"),0; 

		}

		else{

			if (Dep[Fv]==Dep[Fu]){

				Fa[Fv]=Fu,Dep[Fu]++;

				Val[Fv]=Val[u]^Val[v]^1;

				continue;

			}

			if (Dep[Fv]>Dep[Fu]) swap(Fu,Fv);

			Fa[Fv]=Fu;

			Val[Fv]=Val[u]^Val[v]^1;

		}

	}

	Rep(i,1,n) GetFa(i);

	Rep(i,1,n) if (Val[i]) Ans1++;else Ans2++;

	Rt(Ans1),putchar('\n');

	Rep(i,1,n) if (Val[i]) Rt(i),putchar(' ');

	putchar('\n');

	Rt(Ans2),putchar('\n');

	Rep(i,1,n) if (!Val[i]) Rt(i),putchar(' ');

}