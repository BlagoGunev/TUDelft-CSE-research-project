#include<cstdio>

#include<cstring>

#include<iostream>

#include<algorithm>

#include<ctime>

#include<cstdlib>

#include<cmath>

#include<string>

#include<vector>

#include<map>

#include<queue>

#include<bitset>

#define ll long long

#define debug(x) cout<<#x<<"  "<<x<<endl;

#define db(x,y)cout<<#x<<" "<<#y<<" "<<x<<" "<<y<<endl;=

using namespace std;

inline void Rd(int &res){

	res=0;char c;

	while(c=getchar(),c<48);

	do res=(res<<1)+(res<<3)+(c^48);

	while(c=getchar(),c>=48);

}

inline void print(int x){

	if(!x)return ;

	print(x/10);

	putchar((x%10)^48);

}

inline void sc(int x){

	if(x<0){x=-x;putchar('-');}

	print(x);

	if(!x)putchar('0');

	putchar('\n');

}

inline void Max(int &x,int y){if(x<y)x=y;}

inline void Min(int &x,int y){if(x>y)x=y;}

int main(){

	int i,a,b;

	ll n,m,ans=1;

	cin>>n;

	m=n;

	for(i=2;1ll*i*i<=n;i++){

		int c=0;

		while(m%i==0){

			c++;m/=i;

		}

		if(c)ans=ans*i;

	}

	if(m!=1)ans=ans*m;

	cout<<ans<<endl;

	return 0;

}