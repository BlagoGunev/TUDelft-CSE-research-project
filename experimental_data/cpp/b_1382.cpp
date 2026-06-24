#include<bits/stdc++.h>
using namespace std;
inline int R()
{
	char c;int res,sign=1;
	while((c=getchar())>'9'||c<'0') if(c=='-') sign=-1;res=c-'0';
	while((c=getchar())>='0'&&c<='9') res=res*10+c-'0';
	return res*sign;
}
const int Maxn=1e5+5;;
int n,t,m,a[Maxn];
bool win[Maxn];
int main()
{
	t=R();
	while(t--)
	{
		n=R();
		int res1=0,res2=0;
		for(int i=1;i<=n;i++)
		a[i]=R();
		win[n]=1;
		for(int i=n-1;i>=1;i--)
		{
			if(a[i]==1)
			win[i]=1-win[i+1];
			else win[i]=1;
		}
		if(win[1])puts("First");
		else puts("Second");
	} 
}