#include<bits/stdc++.h>
using namespace std;
inline void Read(int &x)
{
	int f=1;x=0;char ch=getchar();
	while (!isdigit(ch)){if (ch=='-') f=-1;ch=getchar();}
	while (isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int main()
{
	int t;
	Read(t);
	while (t--)
	{
		int n,x[200005];
		bool f=0;
		Read(n);
		for (int i=1;i<=n;i++) Read(x[i]);
		for (int i=2;i<=n;i++) if (abs(x[i]-x[i-1])>=2) {f=1;cout<<"YES"<<endl<<i-1<<" "<<i<<endl;break;}
		if (f==0) cout<<"NO"<<endl;
	}
	return 0;
}