#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
priority_queue<int,vector<int>,greater<int> > q;
int t;
int a,b,c,d;
inline char gc()
{
	static char buf[1 << 12], * p1 = buf, * p2 = buf;
	return (p1 == p2) && (p2 = (p1 = buf) + fread(buf, 1, 1 << 12, stdin), p1 == p2) ? EOF : *p1++;
}
inline ll read()
{
	ll x = 0, f = 1;
	char ch(gc());
	while (ch<'0' || ch>'9')
	{
		if (ch == '-')
			f = -1;
		ch = gc();
	}
	while (ch >= '0' && ch <= '9')
	{
		x = (x << 3) + (x << 1) + (ch ^ 48);
		ch = gc();
	}
	return x * f;
}
int main()
{
//	freopen("F.in","r",stdin);
	t=read();
	while(t--)
	{
		for(int i=1;i<=4;i++)
			q.push(read());
		a=q.top(),q.pop();
		b=q.top(),q.pop();
		c=q.top(),q.pop();
		d=q.top(),q.pop();
		cout<<a*c<<endl;
	}
	return 0;
}