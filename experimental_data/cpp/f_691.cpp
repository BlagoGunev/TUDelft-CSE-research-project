//暴力的复杂度更优

#include<bits/stdc++.h>

#define N 3000005

using namespace std;

int v[N],n,m;long long ans[N];

inline int read(){

	int ret=0;char ch=getchar();

	while(ch<'0'||ch>'9') ch=getchar();

	while(ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();

	return ret;

}

int main(){

	scanf("%d",&n);

	for(int i=1;i<=n;i++) v[read()]++;

	for(int i=1;i<=3000000;i++)

		if(v[i]) for(int j=3000000/i;j;j--) ans[i*j]+=v[i]*v[j];

	for(int i=1;i*i<=3000000;i++) ans[i*i]-=v[i];

	for(int i=1;i<=3000000;i++) ans[i]+=ans[i-1];

	m=read();

	long long n2=(long long)n*(n-1);

	for(int i=1;i<=m;i++) printf("%I64d\n",n2-ans[read()-1]);

	return 0;

}