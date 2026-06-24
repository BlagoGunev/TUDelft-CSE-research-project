#include<bits/stdc++.h>
using std::cin;
using std::cout;
 
typedef long long lli;
const int F=1e9;
 
const int N=50,V=1e5;
int n,m,pe[N+5],va[N+5][N+5];
 
const int DC=3000,EC=20000;
int s,t,he[DC+5],to[EC+5],nx[EC+5],wg[EC+5],le[EC+5],ec=1,qu[DC+5],hd,tl,fd[DC+5],fe[DC+5],mf,nf;bool vs[DC+5];
lli ds[DC+5],mc,nc;
int se;
 
inline void wk1(int x,int y,int z,int w) {
	++ec,to[ec]=y,le[ec]=z,wg[ec]=w,nx[ec]=he[x],he[x]=ec;
}
inline void wk2(int x,int y,int z,int w) {
	wk1(x,y,z,w),wk1(y,x,0,-w);
}
inline int bm(int x,int y) {
	if(x==m+1)return t;
	return (x-1)*n+y;
}
inline void cons() {
	//write your construct code (s,t,e)
	s=n*m+m+1,t=s+1;
	for(int i=1;i<=m;++i)
		for(int j=1;j<=n;++j)if(j!=pe[i-1])
			wk2(n*m+i,bm(i,j),1,V-va[i][j]);
	for(int i=1;i<=m;++i)wk2(s,n*m+i,1,0);
	for(int i=1,mx=0,mw=0;i<=m;++i) {
		if(pe[i]<mw)mw=pe[i];
		else if(pe[i]>mw)mw=pe[i],++mx;
		se+=mx;
		for(int j=1;j<=n;++j)
			if(j<mw)wk2(bm(i,j),bm(i+1,j),mx-1,0);
			else if(j==mw)wk2(bm(i,j),bm(i+1,j),mx,-F);
			else wk2(bm(i,j),bm(i+1,j),mx,0);
	}
}
inline bool spfa(){
	std::fill(ds,ds+t+1,F);std::fill(vs,vs+t+1,0);
	ds[s]=0;
	hd=t-1,tl=0,qu[tl]=s,vs[tl]=1;
	while(hd!=tl){
		int x=qu[hd=(hd+1)%t];vs[x]=0;
		for(int i=he[x];i;i=nx[i]) {
			int y=to[i];
			if(le[i]&&ds[x]+wg[i]<ds[y]) {
				ds[y]=ds[x]+wg[i],fd[y]=x,fe[y]=i;
				if(!vs[y])qu[tl=(tl+1)%t]=y,vs[y]=1;
			}
		}
	}
	return ds[t]<F;
}
void mcmf(){
	while(spfa()){
		nf=F,nc=0;
		for(int i=t;i!=s;i=fd[i])nf=std::min(nf,le[fe[i]]),nc+=wg[fe[i]];
		mf+=nf,mc+=1ll*nf*nc;
		for(int i=t;i!=s;i=fd[i])le[fe[i]]-=nf,le[fe[i]^1]+=nf;
	}
}
 
int main() {
	std::ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
 
	cin>>n>>m;
	for(int i=1;i<=m;++i)cin>>pe[i];
	for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)cin>>va[j][i];
	cons();
	mcmf();
	if(mf!=m||(-mc-1+F)/F!=se) {
		cout<<-1<<'\n';
		return 0;
	}
	for(int i=1,ne=1;i<=m;++i)
		for(int j=1;j<=n;++j)if(j!=pe[i-1]) {
			++ne;
			if(le[ne]==0)cout<<j<<' ';
			++ne;
		}
	cout<<'\n';
 
	return 0;
}