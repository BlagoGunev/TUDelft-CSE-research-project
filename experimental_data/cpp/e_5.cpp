#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

inline void rd(int &a){

	a=0;char c;

	while(c=getchar(),!isdigit(c));

	do a=a*10+(c^48);

		while(c=getchar(),isdigit(c));

}

const int M=(int)1e6+5;

int L[M],h[M],n;

inline bool check(int x,int y){

	return x==y||x==1&&y==n;

}

int main(){

	cin>>n;

	int Mx=0,p=-1;

	for(int i=1;i<=n;++i){

		rd(h[i]);

		if(h[i]>Mx)p=i,Mx=h[i];

	}

	int allc=0;

	for(int i=p;i<=n;++i)L[++allc]=h[i];

	for(int i=1;i<=p;++i)L[++allc]=h[i];

	for(int i=1;i<=n+1;++i)h[i]=L[i];

	//rotate

	++n;

	Mx=0,p=-1;

	static int que[M],pos[M],vec[M],cnt[M];

	memset(vec,0,sizeof(vec));

	memset(pos,0,sizeof(cnt));

	int tp=0;

	ll res=0;

	que[++tp]=h[1],pos[tp]=1;

	for(int i=2;i<n;++i){

		for(;que[tp]<=h[i]&&tp;--tp);

		L[i]=pos[tp];

		if(h[i]>vec[pos[tp]])vec[pos[tp]]=h[i],cnt[pos[tp]]=1;

		else res+=cnt[pos[tp]],++cnt[pos[tp]];

		que[++tp]=h[i],pos[tp]=i;

	}

	res+=n-2;

	que[tp=1]=h[1],pos[tp]=1;

	for(int i=n-1;i;--i){

		for(;que[tp]<=h[i]&&tp;--tp);

		if(tp&&!check(pos[tp],L[i]))++res;

		que[++tp]=h[i],pos[tp]=i;

	}

	cout<<res<<endl;

	return 0;

}