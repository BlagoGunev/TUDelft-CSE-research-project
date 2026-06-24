// #pragma GCC optimize(2)
// #pragma GCC optimize("Ofast","inline","-ffast-math")
// #pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include<iostream>
#include<cstdio>
#include<string>
#include<ctime>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<stack>
#include<climits>
#include<queue>
#include<map>
#include<set>
#include<sstream>
#include<cassert>
#include<bitset>
#include<unordered_map>
using namespace std;
typedef long long LL;
typedef unsigned long long ull;
template<typename T>
inline void read(T &x)
{
	T f=1;x=0;
	char ch=getchar();
	while(0==isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(0!=isdigit(ch)) x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	x*=f;
}
template<typename T>
inline void write(T x)
{
	if(x<0){x=~(x-1);putchar('-');}
    if(x>9)write(x/10);
    putchar(x%10+'0');
}
const int inf=0x3f3f3f3f;
const int N=1e6+100;
int main()
{
#ifndef ONLINE_JUDGE
//  freopen("data.in.txt","r",stdin);
//  freopen("data.out.txt","w",stdout);
#endif
//  ios::sync_with_stdio(false);
	int w;
	cin>>w;
	while(w--)
	{
		int n;
		read(n);
		int ans=0,sum=0,mmax=0;
		for(int i=1;i<=n;i++)
		{
			int x;
			read(x);
			sum+=x;
			mmax=max(mmax,sum);
		}
		ans+=mmax;
		sum=0,mmax=0;
		read(n);
		for(int i=1;i<=n;i++)
		{
			int x;
			read(x);
			sum+=x;
			mmax=max(mmax,sum);
		}
		ans+=mmax;
		write(ans),putchar('\n');
	}
    return 0;
}
/*
ctrl+G:转到指定行,ctrl+R:转到指定函数
ctrl+X:删除当前行
ctrl+M:跳转到括号尾部,ctrl+shift+M:选中当前括号内的元素
ctrl+shift+up/down:移动当前行
*/