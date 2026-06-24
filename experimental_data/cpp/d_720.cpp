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

#define y1 fjksdlfkasdj

#define y2 fkjaskfsdfkasdlkf

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

const int maxn=1000005;

vector<PII>pi[maxn],po[maxn];

set<PII>mt;

int n,m,q;

bool zr[maxn<<2];

int sum[maxn<<2];

void pushdown(int i){

	if (zr[i]){

		sum[i<<1]=sum[i<<1|1]=0;

		zr[i<<1]=zr[i<<1|1]=1;

		zr[i]=0;

	}

}

void pushup(int i){

	sum[i]=sum[i<<1]+sum[i<<1|1],sum[i]-=sum[i]>=mod?mod:0;

}

void modify(int i,int l,int r,int ps,int v){

	if (l==r) return void(sum[i]=v);

	pushdown(i);

	int mid=l+r>>1;

	if (ps<=mid) modify(i<<1,l,mid,ps,v);

		else modify(i<<1|1,mid+1,r,ps,v);

	pushup(i);

}



int query(int i,int l,int r,int fr,int bh){

	if (fr>bh) return 0;

	if (l==fr&&r==bh) return sum[i];

	pushdown(i);

	int mid=l+r>>1;

	if (bh<=mid) return query(i<<1,l,mid,fr,bh);

	else if (fr>mid) return query(i<<1|1,mid+1,r,fr,bh);

	else return (query(i<<1,l,mid,fr,mid)+query(i<<1|1,mid+1,r,mid+1,bh))%mod;

}

void clear(int i,int l,int r,int fr,int bh){

	if (l==fr&&r==bh){

		zr[i]=1;sum[i]=0;

		return;

	}

	pushdown(i);

	int mid=l+r>>1;

	if (bh<=mid) clear(i<<1,l,mid,fr,bh);

	else if (fr>mid) clear(i<<1|1,mid+1,r,fr,bh);

	else clear(i<<1,l,mid,fr,mid),clear(i<<1|1,mid+1,r,mid+1,bh);

	pushup(i);

}

int main(){

	n=rd(),m=rd(),q=rd();

	rep(i,1,q){

		int x1=rd(),y1=rd(),x2=rd(),y2=rd();

		pi[x1].pb(mk(y1,y2));

		po[x2+1].pb(mk(y1,y2));

	}

	modify(1,1,m,1,1);

	mt.insert(mk(0,0));

	rep(j,0,pi[1].size()-1) mt.insert(pi[1][j]);

	rep(i,2,n){

		sort(pi[i].begin(),pi[i].end());

		drp(j,pi[i].size()-1,0){

			int k=j;

			while (k>0&&pi[i][k].sc==pi[i][j].fs-1) k--;

			int bot=pi[i][k].fs,top=pi[i][j].sc;

			if (top<m){

				PII low=(*--mt.lower_bound(mk(top+2,0)));

				modify(1,1,m,top+1,query(1,1,m,low.sc+1,top+1));

			}

			j=k;

		}

		rep(j,0,po[i].size()-1) mt.erase(po[i][j]);

		rep(j,0,pi[i].size()-1){

			mt.insert(pi[i][j]);

			clear(1,1,m,pi[i][j].fs,pi[i][j].sc);

		}

	}

	PII low=(*--mt.end());

	rt(query(1,1,m,low.fs+1,m));

}