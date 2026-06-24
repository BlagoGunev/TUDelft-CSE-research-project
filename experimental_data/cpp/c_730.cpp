#include <bits/stdc++.h>

using namespace std;

inline void Rd(int &res){

	res=0;char c;

	while(c=getchar(),c<48);

	do res=(res<<3)+(res<<1)+(c^48);

	while(c=getchar(),c>47);

}

static const int M=5005;

vector<int>G[M];

struct node{

	int c,k,p;

	void read(){Rd(c),Rd(k),Rd(p);}

	bool operator < (const node &cmp)

		const{return p<cmp.p;}

}W[M];

int dis[M];

void bfs(int st){

	memset(dis,-1,sizeof(dis));

	queue<int>q;

	q.push(st);dis[st]=0;

	while(!q.empty()){

		int u=q.front();q.pop();

		for(int j=0,sz=G[u].size();j<sz;j++){

			int v=G[u][j];

			if(!~dis[v]){

				dis[v]=dis[u]+1;

				q.push(v);

			}

		}

	}

}

int n,m,w;

bool chk(int d,int r,int a){//多次调用的考虑全局变量 

	long long sum=0;

	for(int i=0;i<=w;i++){

		if(!~dis[W[i].c]||dis[W[i].c]>d)continue;

		if(r<=W[i].k){

			sum+=1ll*r*W[i].p;

			r=0;break;

		}

		sum+=1ll*W[i].k*W[i].p;

		r-=W[i].k;

	}

	if(r||sum>a)return false;

	return true;

}

int bisection(int g,int r,int a){//city g,need r,val <=a

	int L=0,R=n,res=-1;

	while(L<=R){

		int mid=L+R>>1;

		if(chk(mid,r,a)){

			res=mid;

			R=mid-1;

		}else L=mid+1;

	}

	return res;

}

int main(){

	Rd(n),Rd(m);

	for(int i=1;i<=m;i++){

		int u,v;

		Rd(u),Rd(v);

		G[u].push_back(v);

		G[v].push_back(u);

	}

	Rd(w);

	for(int i=1;i<=w;i++)W[i].read();

	sort(W+1,W+w+1);

	int q;Rd(q);

	for(int i=1;i<=q;i++){

		int g,r,a;

		Rd(g),Rd(r),Rd(a);

		bfs(g);

		printf("%d\n",bisection(g,r,a));

	}

	return 0;

}