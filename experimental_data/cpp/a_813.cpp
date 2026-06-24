#include <stdio.h>
int main(){
	int n,m;
	scanf("%d",&n);
	int t,t1,t2,ans=0;
	for(int i=0;i<n;i++){
		scanf("%d",&t);
		ans+=t;
	}
	scanf("%d",&m);
	if(!m){
		printf("-1\n");
		return 0;
	}
	for(int i=0;i<m;i++){
		scanf("%d %d",&t1,&t2);
		if(ans<=t1){
			printf("%d\n",t1);
			return 0;
		}
		else if(ans<=t2){
			printf("%d\n",ans);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}