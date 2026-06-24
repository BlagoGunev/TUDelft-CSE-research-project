#define range(i,low,high) for(register int i=(low);i<(high);++i)
#define dange(i,high,low) for(register int i=(high);i>(low);--i)
using namespace std;

//quick_io {
#include <cctype>
#include <cstdio>

inline long long getint()
{
	char c=getchar(); for(;!isdigit(c)&&c!='-';c=getchar());
	short s=1; for(;c=='-';c=getchar()) s*=-1; long long r=0;
	for(;isdigit(c);c=getchar()) r=(r<<3)+(r<<1)+c-'0'; return s*r;
}
//} quick_io

int fat[150000],cnt[150000]={0},tot[150000]={0};

int getfa(const int&x) {return x==fat[x]?x:fat[x]=getfa(fat[x]);}

int main()
{
	int n=getint(); range(i,1,n+1) fat[i]=i;
	for(register int m=getint();m--;)
	{
		int fr=getfa(getint()),to=getfa(getint());
		fr!=to?(fat[fr]=to,cnt[to]+=cnt[fr]+1,cnt[fr]=0):++cnt[fr];
	}
	range(i,1,n+1) ++tot[getfa(i)];
	range(i,1,n+1) if(1ll*tot[i]*(tot[i]-1)>>1!=cnt[i])
	{
		return puts("NO"),0;
	}
	return puts("YES"),0;
}