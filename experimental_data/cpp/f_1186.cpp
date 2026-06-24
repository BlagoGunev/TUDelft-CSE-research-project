#include<bits/stdc++.h>
#define ll long long//17:15
#define R register
using namespace std;
const int N=5e6+10;
template <class nmsl> inline void read(nmsl &x)
{
    x=0;
    char ch=getchar(), w=0;
    while(!isdigit(ch))w=(ch=='-'), ch=getchar();
    while(isdigit(ch))x=(x<<1)+(x<<3)+(ch^48), ch=getchar();
    x=w?-x:x;
}
int n, m;
int rudu[N], lim[N], minn, visited[N], tot;
struct abc{
	int st, ed;
}qwq[N];
bool cmp(abc &a, abc &b)
{
	return min(rudu[a.st], rudu[a.ed]) < min(rudu[b.st], rudu[b.ed]);
}
int main()
{
	read(n), read(m); minn=(n+m+1)/2; tot=m;
	for(R int i=1; i<=m; i++)read(qwq[i].st), read(qwq[i].ed), rudu[qwq[i].st]++, rudu[qwq[i].ed]++;
	for(R int i=1; i<=n; i++)lim[i]=(rudu[i]+1)/2;
	sort(qwq+1, qwq+1+m, cmp);
	for(R int i=1; i<=m && tot>minn; i++)
	{
		if(rudu[qwq[i].st] > lim[qwq[i].st] && rudu[qwq[i].ed] > lim[qwq[i].ed])
		{
			tot--;
			visited[i]=1;
			rudu[qwq[i].st]--;
			rudu[qwq[i].ed]--;
		}
	}
	printf("%d\n", tot);
	for(R int i=1; i<=m; i++)
	{
		if(!visited[i])
		{
			printf("%d %d\n", qwq[i].st, qwq[i].ed);
		}
	}
	return 0;
}