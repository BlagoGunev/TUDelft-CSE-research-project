#include<bits/stdc++.h>

#define int long long

#define gmax(x,y) x=max(x,y)

#define gmin(x,y) x=min(x,y)

#define F first

#define S second

#define P pair

#define FOR(i,a,b) for(int i=a;i<=b;i++)

#define rep(i,a,b) for(int i=a;i<b;i++)

#define V vector

#define RE return

#define ALL(a) a.begin(),a.end()

#define MP make_pair

#define PB emplace_back

#define PF push_front

#define FILL(a,b) memset(a,b,sizeof(a))

#define lwb lower_bound

#define upb upper_bound

#define lc (x<<1)

#define rc ((x<<1)|1)

#define sz(x) ((int)x.size())

using namespace std;

int n,a[200005];

int tot=(1<<18)-1; 

struct DSU{

	int fa[200005];

	void init(int n){

		FOR(i,1,n)fa[i]=i;

	}

	int get(int x){

		RE (fa[x]==x)?x:(fa[x]=get(fa[x]));

	}

	void merge(int x,int y){

		x=get(x);y=get(y);

		fa[x]=y;

	}

}T;

P<int,int> mx1[1<<18],mx2[1<<18];

int mx[200005],ed[200005];

void update(int x,int val,int fr){

	if(a[val]>a[mx1[x].F]){

		if(fr!=mx1[x].S)mx2[x]=mx1[x];

		mx1[x]=MP(val,fr);

	}else if(fr!=mx1[x].S&&a[val]>a[mx2[x].F]){

		mx2[x]=MP(val,fr);

	}

}

signed main(){

	ios::sync_with_stdio(0);

	cin.tie(0);

	cin>>n;

	int ans=0;

	FOR(i,1,n)cin>>a[i],ans-=a[i];

	n++;

	T.init(n);

	a[0]=-1e18;

	while(1){

		rep(i,0,1<<18)mx1[i]=mx2[i]=MP(0,-1);

		FOR(i,1,n)update(a[i],i,T.get(i));

		rep(i,0,18)rep(mask,0,1<<18)if(!(mask&(1<<i))){

			update(mask|(1<<i),mx1[mask].F,mx1[mask].S);

			update(mask|(1<<i),mx2[mask].F,mx2[mask].S);

		}

		FOR(i,1,n)mx[i]=-1e18;

		FOR(i,1,n){

			int fr=T.get(i),res=tot^a[i];

			int to=0,now=a[i];

			if(mx1[res].S!=fr){

				if(mx1[res].F>0)now+=a[mx1[res].F],to=mx1[res].S;

			}else if(mx2[res].F>0)now+=a[mx2[res].F],to=mx2[res].S;

			if(now>mx[fr]&&to){

				mx[fr]=now;

				ed[fr]=to;

			}

		}

		V<P<int,P<int,int> > > v;

		FOR(i,1,n)if(mx[i]>=0){

			v.PB(MP(mx[i],MP(i,ed[i])));

		}

		sort(ALL(v));reverse(ALL(v));

		for(auto u:v){

			if(T.get(u.S.F)!=T.get(u.S.S)){

				T.merge(u.S.F,u.S.S);

				ans+=u.F;

			}

		}

		int cnt=0;

		FOR(i,1,n)cnt+=T.get(i)==i;

		if(cnt==1)break;

	}

	cout<<ans;

	RE 0;

}