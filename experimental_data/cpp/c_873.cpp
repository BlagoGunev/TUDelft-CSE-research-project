#include<stdio.h>
#define min(x,y) ((x)<(y)?(x):(y))
int n,m,k;
int mat[105][105];
int score;
int gai;
void solve(int y){
	int i;int max=-1;int cnti=0;int mini=0;
	for(i=1;i<=n;i++){
		if(mat[i][y]==1){
			cnti++;
			int j=min(k,n-i+1);
			int cnt=0;
			for(int k=i;k<=i+j-1;k++){
				if(mat[k][y]==1)cnt++;
			}
			if(cnt>max){
				max=cnt;
				mini=cnti;
			}
		}		
		
	}
	if(cnti==0){
		max=0;mini=1;
	}
	score+=max;
	gai+=(mini-1);
}
int main(){
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&mat[i][j]);
		}
	}
	score=0;gai=0;
	for(int j=1;j<=m;j++){
		solve(j);
	}
	printf("%d %d\n",score,gai);
}