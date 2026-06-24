#include<bits/stdc++.h>

using namespace std;

#define ls LS[cur]

#define rs RS[cur]

const int N=200005;

typedef long long ll;

const ll Inf=1e13;



int n,Q,rt,node;

struct node {

	int sz;

	ll sum,suml,sumr;

} Tree[N*60];

int LS[N*60],RS[N*60];



void pushup(int cur) {

	Tree[cur].sz=Tree[ls].sz+Tree[rs].sz;

	Tree[cur].sum=Tree[ls].sum+Tree[rs].sum;

	Tree[cur].suml=Tree[ls].suml+Tree[rs].suml+Tree[ls].sum*Tree[rs].sz;

	Tree[cur].sumr=Tree[ls].sumr+Tree[rs].sumr+Tree[rs].sum*Tree[ls].sz;	

}

void Insert(int &cur,ll l,ll r,ll pos,int val) {

	if (!cur) cur=(++node);

	if (l==r) { 

		Tree[cur].sz+=val;

		Tree[cur].sum+=l*val;

		Tree[cur].suml+=l*val;

		Tree[cur].sumr+=l*val;

		return;

	}

	ll mid=(l+r)>>1;

	if (pos<=mid) Insert(ls,l,mid,pos,val);

	else Insert(rs,mid+1,r,pos,val);

	pushup(cur);	

}

	

ll query1(int cur,ll l,ll r,int k) {

	if (!cur || !k) return 0;

	if (l==r) return Tree[cur].sum;

	ll mid=(l+r)>>1;

	if (k>=Tree[ls].sz) return Tree[ls].sum+query1(rs,mid+1,r,k-Tree[ls].sz);

	else return query1(ls,l,mid,k);

}

ll query2(int cur,ll l,ll r,int k) {

	if (!cur || !k) return 0;

	if (l==r) return Tree[cur].sum;

	ll mid=(l+r)>>1;

	if (k>=Tree[rs].sz) return Tree[rs].sum+query2(ls,l,mid,k-Tree[rs].sz);

	return query2(rs,mid+1,r,k);

}

ll query3(int cur,ll l,ll r,int k) { 

	if (!cur || !k) return 0;

	if (l==r) return Tree[cur].suml;

	ll mid=(l+r)>>1;

	if (k>=Tree[ls].sz) return Tree[ls].suml+Tree[ls].sum*(k-Tree[ls].sz)+query3(rs,mid+1,r,k-Tree[ls].sz);

	return query3(ls,l,mid,k);

}

ll query4(int cur,ll l,ll r,int k) {

	if (!cur || !k) return 0;

	if (l==r) return Tree[cur].sumr;

	ll mid=(l+r)>>1;

	if (k>=Tree[rs].sz) return Tree[rs].sumr+Tree[rs].sum*(k-Tree[rs].sz)+query4(ls,l,mid,k-Tree[rs].sz);

	return query4(rs,mid+1,r,k);

}



int main() {

	scanf("%d%d",&n,&Q); Q++;

	for (int i=1; i<=n; i++) {

		ll x; scanf("%lld",&x);

		Insert(rt,1,Inf,x,1);

	}

	while (Q--) {

		int sz=Tree[rt].sz;

		int l=1,r=(sz+1)/2+1,pos=0;

		while (l<r) {

			int mid=(l+r)>>1;

			if (query1(rt,1,Inf,mid)-query2(rt,1,Inf,mid-1)>0) 

				l=mid+1,pos=mid;

			else r=mid;

		}

		ll ans=0;

		if (sz&1) ans-=max(0ll,query1(rt,1,Inf,(sz+1)/2)-query2(rt,1,Inf,(sz+1)/2-1));

		if (pos) ans+=(query3(rt,1,Inf,pos)-query4(rt,1,Inf,pos-1))<<1;

		printf("%lld\n",Tree[rt].sum-ans);

		if (Q) {

			int op; ll x; scanf("%d%lld",&op,&x); 

			Insert(rt,1,Inf,x,op==1?1:-1);

		}

	}

	return 0;

}