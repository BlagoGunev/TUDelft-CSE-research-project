#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#define maxn 100010

int T,n,c;
char s[maxn],ans[maxn];
bool tf;

int main()
{
	scanf("%d",&T);while(T--)
	{
		scanf("%s",s+1);n=strlen(s+1);
		scanf("%d",&c);tf=false;
		for(int i=1;i<=n;i++)ans[i]='1';
		for(int i=1;i<=n;i++)if(s[i]=='0'){
			if(i-c>=1)ans[i-c]='0';
			if(i+c<=n)ans[i+c]='0';
		}
		for(int i=1;i<=n;i++)if(s[i]=='1'){
			int tot=0;
			if(i-c>=1)tot|=(ans[i-c]=='1');
			if(i+c<=n)tot|=(ans[i+c]=='1');
			if(!tot)tf=true;
		}
		if(tf)printf("-1\n");
		else{
			for(int i=1;i<=n;i++)printf("%c",ans[i]);
			printf("\n");
		}
	}
}