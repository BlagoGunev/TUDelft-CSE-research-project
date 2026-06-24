#include<bits/stdc++.h>

using namespace std;

typedef __int128 Li;

const int N=1005;

#define ls now<<1

#define rs now<<1|1

Li a[N],b[N],tmp[N];

int _,n,m,cnt0,cnt1,inq[N<<1],del[2][N];

queue<int> q;

Li Get(){

	char ch=getchar(); Li num=0;

	while (ch<'0' || ch>'9') ch=getchar();

	while (ch>='0' && ch<='9') num=num*10+ch-'0',ch=getchar();

	return num;

}

void Print(Li x){ if (!x) return; Print(x/10); putchar(x%10+'0'); }

struct SGT{

	Li tr[N<<2];

	void build(int now, int l, int r){

		if (l==r) return tr[now]=tmp[l],void();

		int mid=(l+r)>>1;

		build(ls,l,mid); build(rs,mid+1,r);

		tr[now]=__gcd(tr[ls],tr[rs]);

	}

	void update(int now, int l, int r, int x){

		if (l==r) return tr[now]=0,void();

		int mid=(l+r)>>1;

		mid>=x?update(ls,l,mid,x):update(rs,mid+1,r,x);

		tr[now]=__gcd(tr[ls],tr[rs]);

	}

} T[N<<1];

void solve(){

	scanf("%d%d",&n,&m); cnt0=cnt1=0;

	for (int i=1; i<=n; i++) a[i]=Get();

	for (int i=1; i<=m; i++) b[i]=Get();

	for (int i=1; i<=n; i++){

		for (int j=1; j<=m; j++) tmp[j]=a[i]/__gcd(a[i],b[j]);

		T[i].build(1,1,m);

		if (T[i].tr[1]>1) q.push(i),inq[i]=1;

	}

	for (int i=1; i<=m; i++){

		for (int j=1; j<=n; j++) tmp[j]=b[i]/__gcd(b[i],a[j]);

		T[n+i].build(1,1,n);

		if (T[n+i].tr[1]>1) q.push(i+n),inq[i+n]=1;

	}

	while (!q.empty()){

		int u=q.front(); q.pop(); inq[u]=0;

		if (u<=n){

			del[0][u]=1,cnt0++;

			for (int i=1; i<=m; i++)

				if (!del[1][i]){

					T[i+n].update(1,1,n,u);

					if (T[i+n].tr[1]>1 && !inq[i+n]) q.push(i+n),inq[i+n]=1;

				}

		} else {

			del[1][u-=n]=1,cnt1++;

			for (int i=1; i<=n; i++)

				if (!del[0][i]){

					T[i].update(1,1,m,u);

					if (T[i].tr[1]>1 && !inq[i]) q.push(i),inq[i]=1;

				}

		}

	}

	if (cnt0==n || cnt1==m) puts("NO");

	else {

		printf("YES\n%d %d\n",n-cnt0,m-cnt1);

		for (int i=1; i<=n; i++) if (!del[0][i]) Print(a[i]),putchar(' '); puts("");

		for (int i=1; i<=m; i++) if (!del[1][i]) Print(b[i]),putchar(' '); puts("");

	}

	for (int i=1; i<=n; i++) del[0][i]=0;

	for (int i=1; i<=m; i++) del[1][i]=0;

}

int main(){

	for (cin>>_; _; _--) solve();

	return 0;

}