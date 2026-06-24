// LUOGU_RID: 158366945
#include<bits/stdc++.h>
using namespace std;
const int maxm=55,maxN=105,maxM=505;
const long long inf=1e15;
int T,n,m,k,s,t,e,ok;
int xx[maxm],yy[maxm],aa[maxm],bb[maxm],ban[maxm],used[maxm],start[maxN],to[maxM],then[maxM],dep[maxN],cur[maxN];
long long ans;
long long limit[maxM],cnt[maxm];
queue<int>q;
inline void add(int x,int y,long long z){
	then[++e]=start[x],start[x]=e,to[e]=y,limit[e]=z;
}
inline void addedge(int x,int y,long long z){
	add(x,y,z),add(y,x,0);
}
void clr(){
	for(int i=1;i<=t;i++)
		cur[i]=start[i]=0;
}
int bfs(int s,int t){
	for(int i=1;i<=t;i++)
		cur[i]=start[i],dep[i]=1e9;
	dep[s]=0,q.push(s);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=start[x];i;i=then[i])
			if(limit[i]&&dep[to[i]]==1e9)
				dep[to[i]]=dep[x]+1,q.push(to[i]);
	}
	return dep[t]!=1e9;
}
int dfs(int x,int t,long long flw){
	if(x==t){
		ans+=flw;
		return flw;
	}
	long long rst=flw;
	for(int i=cur[x];i&&rst;i=then[i]){
		int y=to[i];
		cur[x]=i;
		if(limit[i]&&dep[y]==dep[x]+1){
			long long newflw=dfs(y,t,min(rst,limit[i]));
			if(newflw)
				rst-=newflw,limit[i]-=newflw,limit[i^1]+=newflw;
			else dep[y]=0;
		}
	}
	return flw-rst;
}
long long Dinic(int s,int t){
	ans=0;
	while(bfs(s,t))
		for(ok=1;ok;)
			ok=0,dfs(s,t,inf);
	return ans;
}
int check(long long mid){
	for(int X=1;X<=n;X++){
		e=1,s=n+m+1,t=n+m+2;
		for(int i=1;i<=n;i++)
			if(i!=X)
				addedge(i,t,k);
		long long sum=0,flg=0;
		for(int i=1;i<=m;i++){
			long long w;
			if(ban[i])
				w=cnt[i];
			else w=max((mid+used[i]+aa[i]-bb[i])/2/aa[i],0ll);
			flg|=w>k,sum+=w,addedge(s,n+i,w),addedge(n+i,xx[i],inf),addedge(n+i,yy[i],inf);
		}
		sum-=Dinic(s,t),clr();
		if(sum>0||flg)
			return 0;
	}
	return 1;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=m;i++)
			scanf("%d%d%d%d",&xx[i],&yy[i],&aa[i],&bb[i]);
		long long lst=0;
		for(int i=1;i<=m;i++){
			long long L=lst-1,R=inf;
			while(L+1<R){
				long long mid=(L+R>>1);
				if(check(mid))
					L=mid;
				else R=mid;
			}
			for(int j=1;j<=m;j++)
				if(ban[j]==0){
					used[j]=1;
					if(check(L)==0){
						used[j]=0;
						break;
					}
				}
			for(int j=1;j<=m;j++){
				if(ban[j]==0&&used[j]==0){
					cnt[j]=max((L+aa[j]-bb[j])/2/aa[j],0ll),ban[j]=1;
					//(aw^2+bw)-(a(w-1)^2+b(w-1))<=L
					break;
				}
				used[j]=0;
			}
			lst=L;
		}
		ans=0;
		for(int i=1;i<=m;i++)
			ans+=1ll*aa[i]*cnt[i]*cnt[i]+1ll*bb[i]*cnt[i],ban[i]=0;
		printf("%lld\n",ans);
	}
	return 0;
}