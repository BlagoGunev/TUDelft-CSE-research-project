#include<cstdio>

#define int long long

using namespace std;

int t,n,a,b,da,db;

char c[15],d[15];

signed main(){

	scanf("%lld",&t);

	for(;t--;){

		scanf("%lld%lld%lld",&n,&a,&b);

		scanf("%s%s",c+1,d+1);

		da=(c[1]=='r');

		db=(d[1]=='r');

		if(!a)da=0;

		else if(a==n-1)da=1;

		if(!b)db=0;

		else if(b==n-1)db=1;

		if(a==b&&da==db)printf("%lld\n",(1-da)*(n-1));

		else printf("%lld\n",((a<b)!=(((a-b)%2+2)%2))*(n-1));

	}

	return (0^0);

}