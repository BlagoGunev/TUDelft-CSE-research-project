// LUOGU_RID: 154632505
#include<bits/stdc++.h>
using namespace std;
int t,n,k;
int a[200005];

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		int i=1,j=n,t1=k,t2=k;
		for(;i<=n;i++){
			if(a[i]==a[1]) t1--;
			if(!t1) break;
		}
		for(;j>=1;j--){
			if(a[j]==a[n]) t2--;
			if(!t2) break;
		}
		if((!t1)&&(!t2)&&(i<=j||a[1]==a[n])) printf("YES");
		else printf("NO");
		printf("\n");
	}
	return 0;
}
/*
它以1开始索引为n的瓷砖结束
路径被划分为长度恰好为k的块
p(长度)可以被k整除
每个块中的瓷砖颜色相同，相邻块中的颜色不一定不同
*/