#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

#define LL long long
#define fgx cerr<<"----------------"<<endl;
#define dgx cerr<<"================"<<endl;

inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	return x*f;
}
const int MAXN = 200010;

int N; LL A[MAXN+1],B[MAXN+1],C[MAXN+1],cntB0[MAXN+1],cntB1[MAXN+1],cntC0[MAXN+1],cntC1[MAXN+1];
int Node[MAXN<<1],Next[MAXN<<1],Root[MAXN+1],cnt; bool Flag[MAXN+1]; LL ans;
inline void insert(int u,int v){
	Node[++cnt]=v; Next[cnt]=Root[u]; Root[u]=cnt; return ;
}

inline void DFS1(int k,int Fa){
	if(Fa&&A[Fa]<A[k]) A[k]=A[Fa];
	for(int x=Root[k];x;x=Next[x]){
		int v=Node[x]; if(v==Fa) continue;
		DFS1(v,k);
	}
}
inline void DFS2(int k,int Fa){
	if(B[k]!=C[k]){
		if(!B[k]) ++cntB0[k]; else ++cntB1[k];
		if(!C[k]) ++cntC0[k]; else ++cntC1[k];
	} //else Flag[k]=1;
	for(int x=Root[k];x;x=Next[x]){
		int v=Node[x]; if(v==Fa) continue;
		DFS2(v,k); if(Flag[v]) continue;
		cntB0[k]+=cntB0[v],cntB1[k]+=cntB1[v];
		cntC0[k]+=cntC0[v],cntC1[k]+=cntC1[v];
	} //cerr<<"k: "<<k<<' '<<cntB0[k]<<' '<<cntC0[k]<<' '<<cntB1[k]<<' '<<cntC1[k]<<endl;
	if(cntB0[k]==cntC0[k]&&cntB1[k]==cntC1[k]){
		Flag[k]=1; ans+=(LL)(cntB0[k]+cntB1[k])*A[k];
		cntB0[k]=cntC0[k]=cntB1[k]=cntC1[k]=0;
	} else{
		LL all=0,tmp=min(cntB0[k],cntC0[k]);
		cntB0[k]-=tmp,cntC0[k]-=tmp,all+=tmp;
		tmp=min(cntB1[k],cntC1[k]);
		cntB1[k]-=tmp,cntC1[k]-=tmp,all+=tmp;
		ans+=(LL)all*A[k];
	}
}

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	N=read();
	for(int i=1;i<=N;i++) A[i]=read(),B[i]=read(),C[i]=read();
	for(int i=1;i<N;i++){
		int u=read(),v=read();
		insert(u,v); insert(v,u);
	} DFS1(1,0); DFS2(1,0);
	if(!Flag[1]){
		printf("-1\n");
		return 0;
	}
	printf("%lld\n",ans);
	return 0;
}