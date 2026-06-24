//a+b=(a XOR b)+(a&b)*2

#include<stdio.h>

#include<algorithm>

#include<iostream>

#define LL long long

using namespace std;

inline LL read( )

{

  LL sum=0;char c=getchar( );bool f=0;

  while(c<'0' || c>'9') {if(c=='-') f=1;c=getchar( );}

  while(c>='0' && c<='9') {sum=sum*10+c-'0';c=getchar( );}

  if(f) return -sum;

	return sum;

}

LL s,m,t,ans=1;

bool x[70],y[70];

int len,ler;

int main( )

{

	int i,j;

	s=read( );m=read( );

	bool f=(s==m);

	t=s-m;

	if((t<0)||(t&1)) {printf("0");return 0;}

	t>>=1;

	while(m) {x[++len]=(m&1);m>>=1;}

	while(t) {y[++ler]=(t&1);t>>=1;}

	for(i=1;i<=len;i++)

		{

			//if((!x[i])&(!y[i])); //(0,0)

			//if((!x[i])&(y[i])); //(1,1)

			if((x[i])&(!y[i])) ans<<=1; //(0,1),(1,0)

			if((x[i])&(y[i])) {printf("0");return 0;}

		}

	if(f) ans-=2; //illegal:(0,x),(x,0) 

	cout<<ans;

	return 0;

}