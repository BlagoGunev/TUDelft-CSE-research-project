// LUOGU_RID: 100550444
#include<bits/stdc++.h>

#define mid ((l+r)>>1)

using namespace std;

inline int read(){

	int s=0;

	char ch=getchar();

	while(ch<'0'||ch>'9')ch=getchar();

	while(ch>='0'&&ch<='9')s=(s<<3)+(s<<1)+(ch^48),ch=getchar();

	return s; 

}

const int N=200501;

int n,m,Q;

set<int>L[N],R[N];

map<pair<int,int>,int>mp;

struct node{

	int maxn[N<<2],minn[N<<2],lz[N<<2];

	inline void upd(int rt){

		maxn[rt]=max(maxn[rt<<1],maxn[rt<<1|1]);

		minn[rt]=min(minn[rt<<1],minn[rt<<1|1]);

		lz[rt]=lz[rt<<1]|lz[rt<<1|1]|(maxn[rt<<1|1]>=minn[rt<<1]);

	}

	inline void build(int rt,int l,int r){

		if(l==r){

			maxn[rt]=0,minn[rt]=m+1;

			return;

		}

		build(rt<<1,l,mid),build(rt<<1|1,mid+1,r);

		upd(rt); 

	}

	inline void modify(int rt,int l,int r,int x){

		if(l==r){

			maxn[rt]=R[l].size()?*R[l].rbegin():0;

			minn[rt]=L[l].size()?*L[l].begin():m+1;

			lz[rt]=(maxn[rt]>=minn[rt]);

			return;

		}

		if(x<=mid)modify(rt<<1,l,mid,x);

		else modify(rt<<1|1,mid+1,r,x);

		upd(rt); 

	} 

	inline int check(){

		return lz[1];

	}

}T;

int main(){

	n=read(),m=read(),Q=read();

	T.build(1,1,n);

	while(Q--){

		int x=read(),y=read();

		x++;y++;

		if(mp[make_pair(x,y)]){

			if(y&1)R[x>>1].erase(y>>1);

			else L[x>>1].erase(y>>1);

		}

		else{

			if(y&1)R[x>>1].insert(y>>1);

			else L[x>>1].insert(y>>1);

		} 

		mp[make_pair(x,y)]^=1;

		T.modify(1,1,n,x>>1);

		if(T.check())puts("NO");

		else puts("YES");

	} 

	return 0;

}