#include<bits/stdc++.h>

using namespace std;

int n,m,f[211],g[211],x[211],y[211],cnt[411];

queue<int> px[411],py[411];

stack<int> qx[411],qy[411];

bool ban;

void insfront(int a,int u,int v){

	cnt[a]++;

	px[a].push(u);

	py[a].push(v);

}

void insback(int a,int u,int v){

	cnt[a]++;

	qx[a].push(u);

	qy[a].push(v);

}

void solve(int l,int r){

	if(l>r)return;

	if(l==r){

		insfront(x[l],l,l);

		insfront(n+y[l],l,l);

		return;

	}

	int u=0,v=0;

	for(int i=l;i<=r;i++){

		if(f[i]==x[l])u=i;

		if(f[i]==x[r])v=i;

		insfront(x[l],i,l);

		insfront(x[r],i,r);

	}

	for(int i=l+1;i<r;i++)insfront(x[i],l,i);

	for(int i=l+1;i<=u;i++)insfront(x[l],r,i);

	for(int i=r-1;i>=v;i--)insfront(x[r],r,i);

	if(u>v)swap(u,v);

	for(int i=u-1;i>=l;i--){

		insback(f[i],r,i);

		insback(f[i],r,i+1);

		f[i+1]=f[i];

	}

	for(int i=u+1;i<v;i++)insback(f[i],r,i);

	for(int i=v+1;i<=r;i++){

		insback(f[i],r,i);

		insback(f[i],r,i-1);

		f[i-1]=f[i];

	}

	if(y[l]==g[l]){

		u=r;

		v=0;

		for(int i=l;i<=r;i++)if(y[r]==g[i])v=i;

		for(int i=u;i>l;i--)insfront(n+y[u],i,l);

		for(int i=l;i<=r;i++){

			insfront(n+y[u],l,i);

			insfront(n+y[l],l,i);

		}

		for(int i=l+1;i<=v;i++)insfront(n+y[u],i,r);

	}else{

		u=0;

		v=0;

		for(int i=l;i<=r;i++){

			if(y[i]==g[l])u=i;

			if(y[l]==g[i])v=i;

		}

		for(int i=u;i>l;i--)insfront(n+y[u],i,l);

		for(int i=l;i<=r;i++){

			insfront(n+y[u],l,i);

			insfront(n+y[l],l,i);

		}

		for(int i=l+1;i<=v;i++)insfront(n+y[l],i,r);

	}

	for(int i=l+1;i<u;i++)insfront(n+y[i],i,l);

	for(int i=u+1;i<=r;i++){

		insfront(n+y[i],i,l);

		insfront(n+y[i],i-1,l);

		y[i-1]=y[i];

	}

	for(int i=l+1;i<v;i++)insback(n+g[i],i,r);

	for(int i=v+1;i<=r;i++){

		insback(n+g[i],i,r);

		insback(n+g[i],i-1,r);

		g[i-1]=g[i];

	}

	solve(l+1,r-1);

}

int main(){

	scanf("%d",&n);

	m=n+n;

	for(int i=1;i<=n;i++){

		scanf("%d",&x[i]);

		f[x[i]]=i;

		if(x[i]!=i)ban=1;

		x[i]=i;

	}

	for(int i=1;i<=n;i++){

		scanf("%d",&y[i]);

		g[y[i]]=i;

		if(y[i]!=i)ban=1;

		y[i]=i;

	}

	if(ban){

		solve(1,n);

	}else{

		for(int i=1;i<=n;i++){

			for(int j=1;j<=n;j++){

				insfront(i,j,i);

			}

		}

		for(int i=1;i<=n;i++){

			for(int j=1;j<=n;j++){

				insfront(n+i,i,j);

			}

		}

	}

	for(int i=1;i<=m;i++){

		printf("%d",cnt[i]);

		while(!px[i].empty()){

			printf(" %d %d",px[i].front(),py[i].front());

			px[i].pop();

			py[i].pop();

		}

		while(!qx[i].empty()){

			printf(" %d %d",qx[i].top(),qy[i].top());

			qx[i].pop();

			qy[i].pop();

		}

		printf("\n");

	}

}