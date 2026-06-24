#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define MAXN 100010
typedef pair<int,int> PII;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
int n,m1,m2,ans,sz1,sz2,u,v,Max,now;
bool flag;
char opt;
int b[MAXN],Tag1[MAXN],Tag2[MAXN];
vector<PII> aa,bb;
char getopt()
{
	char ch=getchar();
	for (;ch!='C'&&ch!='D';ch=getchar());
	return ch;
}

inline int min(int a, int b)
{
	if(a < b) return a;
	return b;
}

int main()
{
	n = read();
	m1 = read();
	m2 = read();
	for (int i = 1; i <= n; i ++)
	{
		u = read();
		v = read();
		opt = getopt();
		if (opt == 'C') aa.push_back(make_pair(v,u));
		else bb.push_back(make_pair(v,u));
	}
	sort(aa.begin(),aa.end());
	sort(bb.begin(),bb.end());
	sz1 = aa.size();
	sz2 = bb.size();
	ans=0;
	Max=0;
	for (int i=0;i<sz1;i++)
		if (aa[i].X<=m1)
			Max=max(Max,aa[i].Y);
	if (Max==0) flag=1;
	ans+=Max;
	Max=0;
	for (int i=0;i<sz2;i++)
		if (bb[i].X<=m2)
			Max=max(Max,bb[i].Y);
	if (Max==0) flag=1;
	ans+=Max;
	if (flag) ans=0;
	for (int i=0;i<sz1;i++) Tag1[i]=aa[i].Y;
	for (int i=0;i<sz2;i++) Tag2[i]=bb[i].Y;
	for (int i=1;i<sz1;i++) Tag1[i]=max(Tag1[i-1],Tag1[i]);
	for (int i=1;i<sz2;i++) Tag2[i]=max(Tag2[i-1],Tag2[i]);
	now=0;
	for (int i=sz1-1;i>=0;i--)
	{
		while (now<sz1&&aa[now].X+aa[i].X<=m1) now++;
		if (min(i-1,now-1)>=0) ans=max(ans,aa[i].Y+Tag1[min(i-1,now-1)]);
	}
	now=0;
	for (int i=sz2-1;i>=0;i--)
	{
		while (now<sz2&&bb[now].X+bb[i].X<=m2) now++;
		if (min(i-1,now-1)>=0) ans=max(ans,bb[i].Y+Tag2[min(i-1,now-1)]);
	}
	printf("%d",ans);
	return 0;
}