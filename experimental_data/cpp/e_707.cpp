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

const int maxn=2005;

PII bulb[maxn][maxn],poi[maxn][maxn],t;

int len[maxn],n,m,c;

ll val[maxn][maxn];

bool turn[maxn];

#define y1 orz_rxd

#define y2 orz_szj

char s[10];

int main(){

	n=rd(),m=rd(),c=rd();

	rep(i,1,c){

		len[i]=rd();

		rep(j,1,len[i]){

			int x=rd(),y=rd(),v=rd();

			poi[i][j]=mk(x,y);

			bulb[x][y]=mk(i,j);

			val[i][j]=val[i][j-1]+v;

		}

	}

	rep(i,1,c) turn[i]=1;

	ll ans;

	for (int q=rd();q--;){

		scanf("%s",s);

		if (s[0]=='S') turn[rd()]^=1;

		else{

			int x1=rd(),y1=rd(),x2=rd(),y2=rd(),tmp;

			ans=0;

			if (y1!=1) rep(i,x1,x2){

				if (turn[tmp=bulb[i][y1].fs]&&bulb[i][y1-1].fs==tmp&&abs(bulb[i][y1-1].sc-bulb[i][y1].sc)==1)

					if (bulb[i][y1-1].sc<bulb[i][y1].sc) ans-=val[tmp][bulb[i][y1-1].sc];

						else ans+=val[tmp][bulb[i][y1].sc];

			}

			if (x1!=1) rep(i,y1,y2){

				if (turn[tmp=bulb[x1][i].fs]&&bulb[x1-1][i].fs==tmp&&abs(bulb[x1-1][i].sc-bulb[x1][i].sc)==1)

					if (bulb[x1-1][i].sc<bulb[x1][i].sc) ans-=val[tmp][bulb[x1-1][i].sc];

						else ans+=val[tmp][bulb[x1][i].sc];

			}

			if (y2!=m) rep(i,x1,x2){

				if (turn[tmp=bulb[i][y2].fs]&&bulb[i][y2+1].fs==tmp&&abs(bulb[i][y2+1].sc-bulb[i][y2].sc)==1)

					if (bulb[i][y2+1].sc<bulb[i][y2].sc) ans-=val[tmp][bulb[i][y2+1].sc];

						else ans+=val[tmp][bulb[i][y2].sc];

			}

			if (x2!=n) rep(i,y1,y2){

				if (turn[tmp=bulb[x2][i].fs]&&bulb[x2+1][i].fs==tmp&&abs(bulb[x2+1][i].sc-bulb[x2][i].sc)==1)

					if (bulb[x2+1][i].sc<bulb[x2][i].sc) ans-=val[tmp][bulb[x2+1][i].sc];

						else ans+=val[tmp][bulb[x2][i].sc];

			}

			rep(i,1,c) if (turn[i]&&(t=poi[i][len[i]]).fs>=x1&&t.fs<=x2&&t.sc>=y1&&t.sc<=y2) ans+=val[i][len[i]];

			rt(ans),putchar('\n');

		}

	}

}