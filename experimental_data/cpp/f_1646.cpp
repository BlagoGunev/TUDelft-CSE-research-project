#include<cstdio>
#include<cstring>
#define N 110
#define NN 11000
using namespace std;
int cnt[N][N];
int n;
int ans[NN][N],top;
inline int nex(int x){return x%n+1;}
inline bool check(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(cnt[i][j]!=1)return 0;
		}
	}
	return 1;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int x;scanf("%d",&x);
			cnt[i][x]++;
		}
	}
	while(!check()){
		top++;
		int idx=0,idy=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(cnt[i][j]>1){idx=i;idy=j;break;}
			}
			if(idx)break;
		}
		int x=idx;
		do{
			ans[top][x]=idy;
			x=nex(x);
			if(!cnt[x][idy] && x!=idx){
				for(int i=1;i<=n;i++){
					if(cnt[x][i]>1){idy=i;break;}
				}
			}
		}while(x!=idx);
		for(int i=1;i<=n;i++)cnt[i][ans[top][i]]--,cnt[nex(i)][ans[top][i]]++;
	}
	for(int i=2;i<=n;i++){
		int x=i;
		while(x!=1){
			top++;
			int y=x;
			for(int j=1;j<=n;j++)ans[top][y]=j,y=nex(y);
			x=nex(x);
		}
	}
	printf("%d\n",top);
	for(int i=1;i<=top;i++){
		for(int j=1;j<=n;j++)printf("%d ",ans[i][j]);
		printf("\n");
	}
	return 0;
}