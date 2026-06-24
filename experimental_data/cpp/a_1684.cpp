#include <iostream>

#include <cstdio>

#include <cstring>

#include <algorithm>

#include <cmath>

#include <map>

#define ll long long

#define N 200010

using namespace std;

ll read(){

	char cc;

	while(1){cc=getchar();if((cc>='0'&&cc<='9')||cc=='-')break;}

	ll sum=0,flag=1;

	cc=='-'?flag=-1:sum=(cc^48);

	while(1){cc=getchar();if(!(cc>='0'&&cc<='9'))break;sum=(sum<<1)+(sum<<3)+(cc^48);}

	return sum*flag;

}

void write(ll x){

	if(!x)putchar('0');

	if(x<0){x=-x;putchar('-');}

	ll cc[25],cntt=0;

	while(x){cc[++cntt]=x%10;x/=10;}

	for(ll i=cntt;i>=1;i--)putchar(cc[i]+'0');

	putchar('\n');

}



ll t,n,minn;

char a[15];





















int main(){

	t=read();

	while(t--){

		scanf("%s",a+1);

		n=strlen(a+1);

		if(n==2){

			putchar(a[2]);

			putchar('\n');

			continue;

		}

		minn=10;

		for(ll i=1;i<=n;i++)minn=min(minn,(ll)a[i]-'0');

		cout<<minn<<endl;

		

	}

	

	

	

	

	

	

	

	

	return 0;

} 

/*





*/