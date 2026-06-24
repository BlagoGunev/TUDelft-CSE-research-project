#include<iostream>

#include<cstdio>

#include<algorithm>

#define MAXN 101

using namespace std;

typedef long long ll;

int t,n,minn,sum,a[MAXN];

inline int read(){

	int xx=0,ff=1;char ch=getchar();

	while(ch<'0'||ch>'9'){if(ch=='-')ff=-1;ch=getchar();}

	while(ch>='0'&&ch<='9'){xx=(xx<<1)+(xx<<3)+(ch^48);ch=getchar();}

	return xx*ff;

}

int main(){

	t=read();

	while(t--){

		n=read();sum=0;minn=100000000;

		for(int i=1;i<=n;i++){

			a[i]=read();

			minn=min(minn,a[i]);

			sum+=a[i];

		}

		sum-=minn*n;

		printf("%d\n",sum);

	}

	return 0;

}