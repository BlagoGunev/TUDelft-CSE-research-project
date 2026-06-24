#include<bits/stdc++.h>
using namespace std;
char s[25],t[25],p[450];
int gcd(int a,int b);
int main(){
	int T,n1,n2,d,f1,f2,ff,x,k;
	cin >> T;
	while (T--){
		f1=f2=1;
		scanf("%s",s+1);n1=strlen(s+1);
		scanf("%s",t+1);n2=strlen(t+1);
		if (n1<n2){
			int temp=n1;n1=n2;n2=temp;
			strcpy(p,s+1);strcpy(s+1,t+1);strcpy(t+1,p);
		}
		x=n1*n2/gcd(n1,n2);
		for (k=1;k<=x;k+=n1){
			for (int i=1;i<=n1;++i){
				p[k+i-1]=s[i];
			}
		}
		p[k]='\0';
		ff=1;
		for (int i=1;i<=x;i+=n2){
			for (int j=1;j<=n2;++j){
				if (p[j+i-1]!=t[j]) {
					ff=0;
					break;
				}
			}
			if (ff==0) break;
		}
		if (ff==0) printf("-1\n");
		else printf("%s\n",p+1);
	}
	return 0;
}
int gcd(int a,int b){
	return !b?a:gcd(b,a%b);
}