#include<bits/stdc++.h>

#pragma GCC optimize("Ofast")

using namespace std;

typedef long long ll;

int read() {

	int x=0,f=1;

	char c=getchar();

	while(c<'0'||c>'9') {

		if(c=='-')f=-1;

		c=getchar();

	}

	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();

	return x*f;

}

namespace tokidosaya {

	#define fi first

	#define sc second

#define lc(x) t[x].c[0]

#define rc(x) t[x].c[1]

	typedef pair<int,int> pi;

	const int maxn=2e5+5;

	struct node {

		int a,b,c,d;

		node() {}

		node(int a,int b,int c,int d) {

			this->a=a,this->b=b,this->c=c,this->d=d;

		}

		friend bool operator<(const node a,const node b) {

			return a.a>b.a;

		}

	} emp,ans;

	typedef vector<node>::iterator iter;

	struct tree {

		int c[2];

		node sum;

	} t[maxn*45];

	int a[maxn],n,m,b[maxn],rt[maxn],cnt,lst[maxn],st1[maxn],top1,st2[maxn],top2,book[maxn];

	set<int> s;

	void clr() {

		for(int i=1; i<=cnt; i++)lc(i)=rc(i)=0,t[i].sum=emp;

		cnt=0;

	}

	void addx(int &id,int l,int r,int v,node u) {

		t[++cnt]=t[id],id=cnt,t[id].sum=u;

		if(l==r)return;

		int mid=l+r>>1;

		v<=mid?addx(lc(id),l,mid,v,u):addx(rc(id),mid+1,r,v,u);

	}

	bool askx(int id,int l,int r,int v) {

		if(!id)return 0;

		if(r<=v)return ans=t[id].sum,1;

		int mid=l+r>>1,w=askx(lc(id),l,mid,v);

		if(!w&&v>mid)w=askx(rc(id),mid+1,r,v);

		return w;

	}

	int main() {

//		freopen("data.in","r",stdin);

//		freopen("data.out","w",stdout);

		int x,y;

		n=read(),m=read();

		for(int i=1; i<=n; i++)a[i]=read();

		for(int l=1,r=1; l<=n; l=r+1,r=l) {

			while(r<n&&a[r+1]>=a[r])r++;

			for(int i=l; i<=r; i++)lst[i]=l;

		}

		for(int l=1,r=1; l<=n; l=r+1,r=l) {

			while(r<n&&a[r+1]<=a[r])r++;

			for(int i=l; i<=r; i++)lst[i]=min(lst[i],l);

		}

		s.insert(n+2),st1[0]=st2[0]=n+1;

		for(int i=n; i; i--) {

			rt[i]=rt[i+1];

			while(top1&&a[st1[top1]]<a[i]) {

				x=st1[top1--];

				if(!--book[x])s.insert(x);

			}

			while(top2&&a[st2[top2]]>a[i]) {

				x=st2[top2--];

				if(!--book[x])s.insert(x);

			}

			int lp=0;

			st1[++top1]=i,st2[++top2]=i,book[i]=2;

			int x=top1;

			for(int j=18;j>=0;j--)if(x>(1<<j)&&a[st1[x-(1<<j)]]==a[i])x-=1<<j;

			lp=max(lp,st1[x-1]),x=top2;

			for(int j=18;j>=0;j--)if(x>(1<<j)&&a[st2[x-(1<<j)]]==a[i])x-=1<<j;

			lp=max(lp,st2[x-1]);

			int fst=*s.upper_bound(lp);

//			cout<<i<<' '<<lp<<' '<<fst<<'\n';

			if(fst!=n+2) {

				node u=node(i,0,0,fst);

//				cout<<i<<' '<<fst<<"*\n";

				int l=1,r=top1,w=0;

				while(l<=r) {

					int mid=l+r>>1;

					if(st1[mid]<=fst)w=mid,r=mid-1;

					else l=mid+1;

				}

				u.b=st1[w],l=1,r=top2,w=0;

				while(l<=r) {

					int mid=l+r>>1;

					if(st2[mid]<=fst)w=mid,r=mid-1;

					else l=mid+1;

				}

				u.c=st2[w];

				if(u.b>u.c)swap(u.b,u.c);

				addx(rt[i],1,n,fst,u);

			}

		}

		while(m--) {

			x=read(),y=read();

			if(lst[y]<=x) {

				puts("0");

				continue;

			}

			ans=emp;

			if(askx(rt[x],1,n,y))printf("4\n%d %d %d %d\n",ans.a,ans.b,ans.c,ans.d);

			else printf("3\n%d %d %d\n",lst[y]-1,lst[y],y);

		}

		return 0;

	}

}

int main() {

	return tokidosaya::main();

}

/*

4 1

2 4 1 3

1 4



*/