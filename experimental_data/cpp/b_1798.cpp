#include<bits/stdc++.h>
using namespace std;
#define DEBUG
#define int long long
#define y1 vbjksfvnbhjaukjliksfmgnj
constexpr int inf=1000000007;
constexpr long long INF=4000000000000000000;
//constexpr long long mod=1000000007;
constexpr double eps=1e-9;
inline void YORN(bool f)
{
	if(f)
		puts("YES");
	else
		puts("NO");
}
inline void yorn(bool f)
{
	if(f)
		puts("yes");
	else
		puts("no");
}
inline void Yorn(bool f)
{
	if(f)
		puts("Yes");
	else
		puts("No");
}
inline void judgeoutput(bool f,string s1,string s2)
{
	if(f)
		cout<<s1<<endl;
	else
		cout<<s2<<endl;
}
constexpr int ___S1=1<<20;
char ___buf1[___S1],*___l1,*___r1;
#define getchar() ((___l1==___r1&&(___r1=(___l1=___buf1)+fread(___buf1,1,___S1,stdin)),___l1!=___r1)?*___l1++:EOF)
template<typename T=int>inline T read()
{
	T x=0,y=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			y=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*y;
}
constexpr int ___S2=1<<20;
char ___buf2[___S2],*___l2=___buf2,*___r2=___buf2+___S2;
#define putchar(c) (___l2==___r2&&(fwrite(___buf2,1,___S2,stdout),___r2=(___l2=___buf2)+___S2),*___l2++=(c))
int ___st[22];
template<typename T>inline void write(T x)
{
	if(x<0)
		putchar('-'),x=-x;
	int tp=0;
	do
		___st[++tp]=x%10,x/=10;
	while(x);
	while(tp)
		putchar(___st[tp--]+'0');
//	putchar('\n');
}
inline void fre()
{
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
}
int n[50005],ans[50005];
bool f[50005];
basic_string<int>a[50005];
void work()
{
	int m;
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>n[i];
		for(int j=0;j<n[i];j++)
		{
			int x;
			cin>>x;
			a[i]+=x;
		}
	}
	for(int i=m;i;i--)
	{
		int j;
		for(j=0;j<n[i];j++)
			if(!f[a[i][j]])
			{
				ans[i]=a[i][j];
				break;
			}
		if(j==n[i])
		{
			puts("-1");
			goto clr;
		}
		for(j=0;j<n[i];j++)
			f[a[i][j]]=1;
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<' ';
	cout<<endl;
	clr:
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<n[i];j++)
			f[a[i][j]]=0;
		a[i].clear();
	}
}
inline void cases()
{
	int T;
	cin>>T;
	while(T--)
		work();
}
signed main()
{
//	fre();
	cases();
//	work();
	fwrite(___buf2,1,___l2-___buf2,stdout);
	return 0;
}