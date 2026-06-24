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

#define Rep(x,a,b) for (int x=a;x<=b;x++)

#define Drp(x,a,b) for (int x=a;x>=b;x--)

#define Cross(x,a) for (int x=head[a];~x;x=next[x])

#define ll long long

#define oo (1<<29)

#define mk(a,b) make_pair(a,b)

#define fr first

#define sc second

using namespace std;

inline ll IN(){

	ll x=0;int ch=getchar(),f=1;

	while (!isdigit(ch)&&(ch!='-')&&(ch!=EOF)) ch=getchar();

	if (ch=='-'){f=-1;ch=getchar();}

	while (isdigit(ch)){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}

	return x*f;

}

inline void OUT(ll x){

	if (x<0) putchar('-'),x=-x;

	if (x>=10) OUT(x/10),putchar(x%10+'0');

		else putchar(x+'0');

}

const int N=150005;

int Ans,n,a[N],Xg[N],Cnt;

int main(){

	n=IN();

	Rep(i,1,n) a[i]=IN();

	Rep(i,1,n-1){

		if (i&1){

			if (a[i]>=a[i+1]) Xg[++Cnt]=i;

		}

		else if (a[i]<=a[i+1]) Xg[++Cnt]=i;

	}

	if (Cnt>4) return puts("0"),0;

	Ans=0;

	int cnt=Cnt;

	Rep(i,1,cnt) if (Xg[i]!=Xg[i+1]-1) Xg[++Cnt]=Xg[i]+1;

	sort(Xg+1,Xg+Cnt+1);

	Rep(i,1,Cnt) Rep(j,1,n){

		bool cont=0;

		Rep(k,1,i) if (j==Xg[k]){cont=1;break;}

		if (cont) continue;

		bool f=1;

		if (abs(j-Xg[i])>=2){

			if (j&1){

				if (j>1&&a[Xg[i]]>=a[j-1]) f=0;

				if (j<n&&a[Xg[i]]>=a[j+1]) f=0;

			}

			else{

				if (j>1&&a[Xg[i]]<=a[j-1]) f=0;

				if (j<n&&a[Xg[i]]<=a[j+1]) f=0;

			}

			if (Xg[i]&1){

				if (Xg[i]>1&&a[j]>=a[Xg[i]-1]) f=0;

				if (Xg[i]<n&&a[j]>=a[Xg[i]+1]) f=0;

			}

			else{

				if (Xg[i]>1&&a[j]<=a[Xg[i]-1]) f=0;

				if (Xg[i]<n&&a[j]<=a[Xg[i]+1]) f=0;

			}

		}

		else{

			if (Xg[i]&1){

				if (a[Xg[i]]<=a[j]) f=0;

				if (j<Xg[i]&&j>1&&a[Xg[i]]<=a[j-1]) f=0;

				if (j>Xg[i]&&Xg[i]>1&&a[j]>=a[Xg[i]-1]) f=0;

			}

			else{

				if (a[Xg[i]]>=a[j]) f=0;

				if (j<Xg[i]&&j>1&&a[Xg[i]]>=a[j-1]) f=0;

				if (j>Xg[i]&&Xg[i]>1&&a[j]<=a[Xg[i]-1]) f=0;

			}

		}

		if (!f) continue;

		swap(a[j],a[Xg[i]]);

		Rep(k,1,Cnt){

			if (Xg[k]==n) continue;

			if (Xg[k]&1){

				if (a[Xg[k]+1]<=a[Xg[k]]) f=0;

			}

			else if (a[Xg[k]+1]>=a[Xg[k]]) f=0;

		}

		swap(a[j],a[Xg[i]]);

		if (f) Ans++;

	}

	OUT(Ans);

}