#include<bits/stdc++.h>
using namespace std;
inline void read(int &x)
{
	char c=getchar();x=0;
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
}
typedef long long ll;
const int N=2e5+5;
int n, b[N], have[N*3], lst[N];
ll f[N], ans;
int main(){
	read(n);
	for(int i=1; i<=n; i++)
	{
		read(b[i]);
		lst[i]=have[b[i]+n-i];
		have[b[i]+n-i]=i;
	}
	for(int i=1; i<=n; i++)
	{
		f[i]=f[lst[i]]+b[i];
		ans=max(ans, f[i]);
	}
	printf("%lld\n", ans);
	return 0;
}