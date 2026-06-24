#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
#define M 200005
using namespace std;
int dp[1<<20],Lst[1<<20],ID[1<<20];
struct node{
	int id,val;
	bool operator <(const node &_)const{
		return val<_.val;
	}
}A[M];
int B[M];
int ST[25][M][20];
vector<int>way[M];
void Print(int x){
	if(x==0)return;
	int nxt=Lst[x];
//	printf("ID=%d [%d %d]\n",ID[x-nxt],dp[nxt]+1,dp[x]);
	bool flag=false;
	for(int i=dp[nxt]+1;i<=dp[x];i++){
		if(1ll*(dp[x]-i+1)*A[i].val>=B[ID[x-nxt]]||flag){flag=true;way[ID[x-nxt]].push_back(A[i].id);}
//		if(1ll*(i-dp[nxt])*A[i].val>=B[ID[x-nxt]])break;
	}
	Print(nxt);
}
int Lg2[M];
int Get_min(int x,int L,int R){
	int K=Lg2[R-L+1];
	return min(ST[x][L][K],ST[x][R-(1<<K)+1][K]);
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&A[i].val);
		A[i].id=i;
	}
	sort(A+1,A+n+1);
	for(int i=1;i<=m;i++)scanf("%d",&B[i]);
	
	for(int i=2;i<M;i++)Lg2[i]=Lg2[i>>1]+1;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			int x=ceil(1.0*B[i]/A[j].val);
//			printf("%d %d\n",B[j],A[i].val);
//			printf("ST[%d][%d][0]=%d\n",i,j,j+x-1);
			ST[i][j][0]=j+x-1;
		}
		for(int step=1;(1<<step)<=n;step++){
			for(int j=1;j+(1<<step)-1<=n;j++){
				ST[i][j][step]=min(ST[i][j][step-1],ST[i][j+(1<<(step-1))][step-1]);
			}
		}
	}
//	puts("@");
	
	for(int i=1;i<=m;i++)ID[1<<(i-1)]=i;
	memset(dp,63,sizeof(dp));
	dp[0]=0;
	int I=1<<m;I--;
	for(int chs=0;chs<I;chs++){
		if(dp[chs]>1e9)continue;
		if(dp[chs]==n)continue;
//		printf("chs=%d\n",chs);
		int cnt=dp[chs];
		for(int j=1;j<=m;j++){
			if((1<<(j-1))&chs)continue;
			int Lx=cnt+1,Rx=n;
			int x=Get_min(j,Lx,Rx);
//			while(Lx<=Rx){
//				int mid=(Lx+Rx)>>1;
//				printf("%lld ? %d\n",
//				if(1ll*(mid-cnt)*A[mid].val>=B[j]){
//					res=mid;
//					Rx=mid-1;
//				}else Lx=mid+1;
//			}
//			printf("[%d %d]\n",Lx,Rx);
//			printf("res=%d\n",res);
//			if(res==-1)continue;
//			x=res;
			int nxt_chs=chs|(1<<(j-1));
			if(x>n)continue;
			if(dp[nxt_chs]>x){
				dp[nxt_chs]=x;
				Lst[nxt_chs]=chs;
			}
		}
	}
	if(dp[I]>1e9){puts("NO");return 0;}
	Print(I);
	puts("YES");
	for(int i=1;i<=m;i++){
		printf("%d ",(int)way[i].size());
		for(int j=0;j<(int)way[i].size();j++)printf("%d ",way[i][j]);puts("");
	}
	return 0;
}