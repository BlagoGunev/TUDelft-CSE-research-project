#include <bits/stdc++.h>

#define FOR(a, b, c) for (int a = (b), _for = (c); a < _for; ++a)
#define REP(a, n) FOR(a, 0, n)
#define x first
#define y second
#define pb push_back
#define pii pair<int, int>
#define ll long long
#define lf double

using namespace std;

const int MAX = 1000 + 5;

int n;
int c[MAX];

vector<pii>v[MAX];

int dfs0(int cx,int par){
	if (v[cx].size()==1 && cx){
		return c[cx]=cx;
	}
	for (auto nx:v[cx]){
		if (nx.x==par) continue;
		int tmp=dfs0(nx.x,cx);
		c[cx]=tmp;
	}
	return c[cx];
}

vector<pair<pii,int> >qwer;

void out(int a,int b,int c){
	if (a==b) return;
	qwer.pb({{a+1,b+1},c});
//	printf ("%d %d %d\n",a+1,b+1,c);
}

void dfsc(int cx, int par,int cost,int z,int u){
	int p1,p2,p3;
	if (cx==0){
		if (v[0].size()==1){
			p1=0;
			p2=0;
			p3=0;
		}
		else{
			p1=c[v[0][0].x];
			p2=c[v[0][1].x];
			p3=c[v[0][2].x];
		}
		for (auto nx:v[cx]){
			int d1=p1,d2=p2;
			if (d1==c[nx.x]) d1=p3;
			if (d2==c[nx.x]) d2=p3;
			dfsc(nx.x,cx,nx.y,d1,d2);
		}
		return;
	}
	if (v[cx].size()==1){
		out(z,cx,cost/2);
		out(u,cx,cost/2);
		out(z,u,-cost/2);
		return;
	}
	p1=c[v[cx][0].x];
	p2=c[v[cx][1].x];
	p3=c[v[cx][2].x];
//	printf ("%d %d %d\n",p1,p2,p3);
	if (v[cx][0].x==par) p1=p3;
	if (v[cx][1].x==par) p2=p3;
//	printf ("%d %d %d\n",p1,p2,p3);
	
	out(z,p1,cost/2);
	out(u,p2,cost/2);
	out(z,u,-cost/2);
	out(p1,p2,-cost/2);

	p1=c[v[cx][0].x];
	p2=c[v[cx][1].x];
	p3=c[v[cx][2].x];
	if (v[cx][0].x==par) p1=z;
	if (v[cx][1].x==par) p2=z;
	if (v[cx][2].x==par) p3=z;
	
	for (auto nx:v[cx]){
		if (nx.x==par) continue;
		int d1=p1,d2=p2;
		if (d1==c[nx.x]) d1=p3;
		if (d2==c[nx.x]) d2=p3;
		dfsc(nx.x,cx,nx.y,d1,d2);
	}
}

int main(){
	scanf ("%d",&n);
	REP(i,n-1){
		int a,b,c;
		scanf ("%d%d%d",&a,&b,&c);
		a--;b--;
		v[a].pb({b,c});
		v[b].pb({a,c});
	}
	REP(i,n){
		if (v[i].size()==2){
			puts ("NO");
			return 0;
		}
	}
	puts ("YES");
	dfs0(0,-1);
	dfsc(0,-1,-1,-1,-1);
	
	printf ("%d\n",(int)qwer.size());
	for (auto x:qwer){
		printf ("%d %d %d\n",x.x.x,x.x.y,x.y);
	}
	
	return 0;
}