#include<cstdio>
using namespace std;
char c[200005];
int n,k;
int main(){
	scanf("%d%d",&n,&k);
	scanf("%s",c);
	if(n==1){
		if(k==0) printf("%s",c);
		else printf("0");
	}
	else{
		for(int i=0;i<n;++i){
			if(k>0){
				if(i==0){
					if(c[i]!='1'){
						c[i]='1';
						--k;
					}
				}
				else{
					if(c[i]!='0'){
						c[i]='0';
						--k;
					}
				}
			}
			else break;
		}
		printf("%s",c);
	}
	return 0;
}