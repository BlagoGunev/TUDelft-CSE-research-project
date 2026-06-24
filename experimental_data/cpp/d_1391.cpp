#include<bits/stdc++.h>
using namespace std;

char str[5][1000010];

int now[1000010],noww[2][1000010];

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	if (n>3 && m>3) {
		printf("-1");
		return 0;
	}
	if (n==1){
		printf("0");
		return 0;
	}
	if (n==2){	
		for (int i=1;i<=n;i++){
			scanf("%s",str[i]);
		}
		for (int i=0;i<m;i++){
			now[i+1]=str[1][i]^str[2][i];
		}
		int c1=0,c2=0,b=1;
		for (int i=1;i<=m;i++){
		//	printf("now:%d b:%d\n",now[i],b);
			if (now[i]==b) c1++;
			if (now[i]!=b) c2++;
			b^=1;
		}
		printf("%d",min(c1,c2));
		return 0;
	}
	if (n==3){
		for (int i=1;i<=n;i++){
			scanf("%s",str[i]);
		}
		for (int i=0;i<m;i++){
			noww[0][i+1]=str[1][i]^str[2][i];
			noww[1][i+1]=str[2][i]^str[3][i];
		}
		/*
		for (int i=0;i<=1;i++){
			for (int j=1;j<=m;j++) printf("%d ",noww[i][j]);
			puts("");
		}
		*/
		int c11=0,c12=0,c21=0,c22=0;
		int b1=1,b2=1;
		for (int i=1;i<=m;i++){
		//	printf("haha: %d %d b:%d %d\n",noww[0][i],noww[1][i],b1,b2);
			if (noww[0][i]==b1 || noww[1][i]==b2) c11++;
			if (noww[0][i]==b1 || noww[1][i]!=b2) c12++;
			if (noww[0][i]!=b1 || noww[1][i]==b2) c21++;
			if (noww[0][i]!=b1 || noww[1][i]!=b2) c22++;
			b1^=1;
			b2^=1;
		}
		//printf("%d %d %d %d\n",c11,c12,c21,c22);
		printf("%d",min(min(c11,c12),min(c21,c22)));
		return 0;
	}
}