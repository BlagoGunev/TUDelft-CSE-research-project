#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int cnt=0,f=1;char c;
	c=getchar();
	while(!isdigit(c)){
		if(c=='-')f=-f;
		c=getchar();
	}
	while(isdigit(c)){
		cnt=cnt*10+c-'0';
		c=getchar();
	}
	return cnt*f;
}
int n,m;
int flag[100005];
int sum[100005];
int ans[100005];
int tot;
int x;
int main(){
	n=read();m=read();
	tot=0;
	flag[0]=n;
	for(register int i=1;i<=m;i++){
		x=read();
		sum[x]++;
		flag[sum[x]]++;flag[sum[x]-1]--;
//		for(register int j=0;j<=n;j++)printf("%d ",flag[j]);
//		printf("\n");
		
		if(flag[tot]==0){
			tot++;
			printf("1");
		}
		else printf("0");
	}
	return 0;
}