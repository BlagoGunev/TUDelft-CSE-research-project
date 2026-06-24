#include <bits/stdc++.h>
#include <bits/stdc++.h>

using namespace std;

#define N 1010



long long a[3];

long long l;

long long gan(long long a,long long b,long long c,long long add){

	long long x=min(a-b-c+add,l-add);

	if(x<0) return 0;

	return (x+1)*(x+2)/2;

}

	

int main(){

	//freopen("in.txt","r",stdin);

	while(~scanf("%lld%lld%lld%lld",&a[0],&a[1],&a[2],&l)){

		sort(a,a+3);

		long long ans=(l+1)*(l+2)*(l+3)/6;

		if(a[0]+a[1]+l<=a[2]) printf("0\n");

		else {

			for(long long i=0;i<=l;i++){

				ans-=gan(a[0],a[1],a[2],i);

			}

			for(long long i=0;i<=l;i++){

				ans-=gan(a[1],a[0],a[2],i);

			}

			for(long long i=0;i<=l;i++){

				ans-=gan(a[2],a[0],a[1],i);

			}

			printf("%lld\n",ans);

		}

	}

	return 0;

}