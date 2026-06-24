#include<iostream>
#include<cstdio>
using namespace std;

#define MIN(x,y) (((x)<(y))?(x):(y))
int n;
long long ans=0;
long long minn=1e10+7;
bool pos=0,neg=0;

long long read()
{
	long long x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	if(f==1)pos=1;
	if(f==-1)neg=1;
	return x;
}

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		long long tmp;
		tmp=read();
		minn=MIN(minn,tmp);
		ans+=tmp;
	}
	if((pos==0||neg==0)&&n!=1)ans=ans-2*minn;
	if(n==1&&neg==1)ans=-ans;
	cout<<ans<<endl;
}