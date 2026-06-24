#include<cstdio>
using namespace std;
const int NN=101111;
int n,i,ans;
char a[NN],b[NN];
bool flag1,flag2;
void dfs(int i,int j)
{
	if (i==n+1&&j==n+1)
	{
		if (flag1&&flag2) ans++;
		return;
	}
	if (a[i]==b[j]) {dfs(i+1,j+1);return;}
	if (!flag1&&(a[i]==b[j+1]||b[j+1]=='?'))
	{
		flag1=true;
		dfs(i,j+1);
		flag1=false;
	}
	if (!flag2&&(b[j]==a[i+1]||a[i+1]=='?'))
	{
		flag2=true;
		dfs(i+1,j);
		flag2=false;
	}
	if (!flag1&&!flag2)
	{
		flag1=flag2=true;
		if (a[i]!=b[j+1]&&b[j+1]!='?') dfs(i+1,j+1);
		if (b[j]!=a[i+1]&&a[i+1]!='?') dfs(i+1,j+1);
		flag1=flag2=false;
	}
}
int main()
{
	//freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	scanf("%d\n",&n);
	scanf("%s\n%s",a+1,b+1);
	a[n+1]=b[n+1]='?';
	dfs(1,1);
	printf("%d\n",ans);
	return 0;
}