//Copyright(c)2017 Mstdream
#include<bits/stdc++.h>
using namespace std;

inline void splay(int &v){
	v=0;char c=0;int p=1;
	while(c<'0' || c>'9'){if(c=='-')p=-1;c=getchar();}
	while(c>='0' && c<='9'){v=(v<<3)+(v<<1)+c-'0';c=getchar();}
	v*=p;
}
const int N=100010;
int n,w,h;
int ansx[N],ansy[N];
struct Q{
	int fx,p,t,v,id;
	int x(){
		if(fx==1)return p;
		if(fx==2)return w;
	}
	int y(){
		if(fx==1)return h;
		if(fx==2)return p;
	}
}q[N];
bool cmp(const Q&a,const Q&b){
	if(a.v!=b.v)return a.v<b.v;
	if(a.fx!=b.fx)return a.fx<b.fx;
	if(a.fx==1)return a.p>b.p;
	return a.p<b.p;
}
int main(){
	splay(n),splay(w),splay(h);
	for(int i=1;i<=n;i++){
		splay(q[i].fx),splay(q[i].p),splay(q[i].t);
		q[i].v=q[i].t-q[i].p;q[i].id=i;
	}
	sort(q+1,q+n+1,cmp);
	q[n+1].v=10000001;
	for(int i=1;i<=n;i++){
		int lt=i;
		for(;;lt++){
			if(q[lt].v!=q[i].v)break;
		}
		lt--;int fir=i;
		for(;fir<=lt;fir++)if(q[fir].fx==2)break;
		if(fir>lt)fir=i;
		for(int j=i;j<=lt;j++){
			ansx[q[j].id]=q[fir].x();
			ansy[q[j].id]=q[fir].y();
			fir++;if(fir>lt)fir=i;
		}
		i=lt;
	}
	for(int i=1;i<=n;i++){
		printf("%d %d\n",ansx[i],ansy[i]);
	}
}