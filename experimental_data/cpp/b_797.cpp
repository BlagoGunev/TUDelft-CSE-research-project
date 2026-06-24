#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
#define LL long long

int n,k;
int a[200001];
LL ans=0;

inline void R(int &v)
{
	v=0;
	char ch=getchar();
	bool f=0;
	while(!isdigit(ch)){if(ch=='-')f=1;ch=getchar();}
	while(isdigit(ch)){v=(v<<3)+(v<<1)+ch-'0';ch=getchar();}
	if(f) v=-v;
}

int main()
{
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	
	int i,j;
	R(n);
	for(i=1;i<=n;++i)
	{
		R(a[i]);
		if(a[i]>0)ans+=a[i];
	}
	if(ans&1) {printf("%I64d",ans);return 0;}
	sort(a+1,a+n+1);	
	int x=1e9;
	for(i=1;i<=n;++i) if(a[i]&1&&a[i]>0) {x=a[i];break;}
	LL ans1=ans-x;
	x=-1e9;
	for(i=n;i>=1;--i) if(a[i]&1&&a[i]<0) {x=a[i];break;}
	LL ans2=ans+x;
	printf("%I64d",max(ans1,ans2));
	return 0;
}