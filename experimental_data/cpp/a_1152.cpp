#include <bits/stdc++.h>

using namespace std;

#define INF 100005
#define inf 1000000007
#define rep(i,l,r) for(i=l;i<=r;i++)
#define ser(i,r,l) for(i=r;i>=l;i--)

typedef long long ll;

int read()
{
	int k=0,f=1;
	char ch;
	while(ch<'0' || ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		k=(k<<1)+(k<<3)+ch-'0';
		ch=getchar();
	}
	return k*f;
}
int main()
{
	int i,j,k,t1=0,t2=0,m1=0,m2=0,n,m,x;
	n=read(),m=read();
	rep(i,1,n){
		x=read();
		if(x%2)t1++;
		else t2++;
	}
	rep(i,1,m){
		x=read();
		if(x%2)m1++;
		else m2++;
	}
	printf("%d\n",min(t1,m2)+min(t2,m1));
	return 0;
}