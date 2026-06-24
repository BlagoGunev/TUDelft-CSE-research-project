#include <cstdio>
#include <algorithm>
#include <cstring>
#include <ctype.h>
using namespace std;
const int maxn=200005;
typedef long long LL;
typedef pair<int,int> pairs;
int a[maxn],n,ans;
bool vis[maxn];
inline int read(){
	int ret=0; char ch=getchar(); bool fl=0;
	while (!isdigit(ch))
		fl^=!(ch^'-'),ch=getchar();
	while (isdigit(ch))
		ret=(ret<<3)+(ret<<1)+ch-'0',ch=getchar();
	if (fl) ret=-ret; return ret;
}
int main(){
	// freopen("data.in","r",stdin);
	// freopen("data.out","w",stdout);
	n=read();
	for (int i=1;i<=n;i++)
		a[i]=read();
	for (int i=n;i;i--){
		if (!vis[a[i]])
			ans=a[i];
		vis[a[i]]=1;
	}
	printf("%d\n",ans);
	return 0;
}