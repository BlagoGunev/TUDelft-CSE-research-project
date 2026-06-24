#include<cstdio>
#include<algorithm>
using namespace std;
inline int read(){
	int x=0; char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	return x;
}
const int maxn=2e5+10;
const int inf=1e9+10;
struct fri{
	int h,w,id;
	bool operator<(const fri &x)const{
		return h<x.h;
	}
}f[maxn],ff[maxn];
int ans[maxn],minw[maxn],pos[maxn],pre[maxn]; 
inline void Init(int n){
	for(int i=1;i<=n;i++) ans[i]=-1,
	f[i].h=f[i].w=f[i].id=0,
	minw[i]=0,pos[i]=0;
	
}
int n;
bool check(){
	for(int i=1;i<=n;i++){
		int p=ans[i];//printf("  %d  ",i);
		if(p!=-1){
			if(ff[p].h<ff[i].h&&ff[p].w<ff[i].w
				||ff[p].h<ff[i].w&&ff[p].w<ff[i].h
			) continue;printf("   %d %d    ",p,i);
			{//printf("   %d  %d %d %d   ",f[p].h,f[i].w,f[p].w,f[i].h);
			}
		return false;
		}
		for(int p=1;p<=n;p++){
			if(ff[p].h<ff[i].h&&ff[p].w<ff[i].w
				||ff[p].h<ff[i].w&&ff[p].w<ff[i].h
			){return false;
			}
		}
		
	}
	return true;
}
int main(){
	int t=read();
	minw[0]=inf,pos[0]=0;
	while(t--){
		n=read();
		Init(n);
		for(int i=1;i<=n;i++) ff[i].h=f[i].h=read(),ff[i].w=f[i].w=read(),f[i].id=i;
		sort(f+1,f+n+1);
		for(int i=1;i<=n;i++){
			if(f[i-1].h==f[i].h) pre[i]=pre[i-1];
			else pre[i]=i-1;
			minw[i]=minw[i-1],pos[i]=pos[i-1];
			
				if(minw[pre[i]]<f[i].w) ans[f[i].id]=pos[pre[i]];
				if(f[i].w<minw[i-1]) minw[i]=f[i].w,pos[i]=f[i].id;
		}
		for(int i=1;i<=n;i++){
			fri temp; temp.h=f[i].w;
			int k=lower_bound(f+1,f+n+1,temp)-f-1;
			if(minw[k]<f[i].h) ans[f[i].id]=pos[k];
		}
	//	if(check()) puts("OK"); else puts("ERROR");
		for(int i=1;i<=n;i++) printf("%d ",ans[i]);
		puts("");
	}
	return 0;
}