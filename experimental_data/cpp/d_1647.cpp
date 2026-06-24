#include<cstdio>

using namespace std;

int T,x,d,k;

bool check(int n){

	if(n<4) return 1;

	if(n%2==0||n%3==0) return 0;

	for(int i=5;i*i<=n;i+=6)

		if(n%i==0||n%(i+2)==0) return 0;

	return 1;

}

int main(){

	scanf("%d",&T);

	while(T--){

		scanf("%d%d",&x,&d);

		for(k=0;x%d==0;x/=d,++k);

		if(k<2) printf("NO\n");

		else if(!check(x)) printf("YES\n");

		else if(check(d)) printf("NO\n");

		else printf(k>(x*x==d)+2?"YES\n":"NO\n");

	}

	return 0;

}//////