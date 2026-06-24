#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define fi "CF180_1_1.INP"
#define fo "CF180_1_1.OUT"
#define nmax 1000+5
#define INF 1000000000
using namespace std;

//VARIABLES
int m,n,a[nmax],b[nmax],S;
char s[nmax];
//FUNCTION PROTOTYPES

void Init();
void Process();

//MAIN
int main()
{
//       freopen(fi,"r",stdin);
//       freopen(fo,"w",stdout);
       Init();
       Process();
       return 0;
}

//FUNCTIONS AND PROCEDURES
void Init()
{
	scanf("%s",&s);n=strlen(s);
	for (int i=1;i<=n;++i) a[i]=int(s[i-1]-'0');
	scanf("%s",&s);m=strlen(s);
	for (int i=1;i<=m;++i) b[i]=int(s[i-1]-'0');
}
bool Comp(int k)
{
	if (n-k+1>m) return false;
	for (int i=k;i<=n;++i)
	if (a[i]!=b[i-k+1]) return false;
	return true;
}
bool Check(int k, int S)
{
	int t=n-k+1,x=1;
	if (k==n+1)
	{
		for (int i=1;i<=3;++i) a[++k]=S;
		S^=a[k];
	}
	for (int i=t+1;i<=m;++i)
	{
		while (b[i]!=S)
		{
			S^=a[x++];
			if (x>k) return false;
		}
		S^=b[i];
//		cout << i << " " << x << endl;
	}
	return true;
}
void Process()
{
	for (int i=1;i<=n;++i) S=(S+a[i])%2;
	for (int i=1;i<=n+1;++i)
	if (Comp(i))
	if (Check(i,S))
	{
		printf("YES\n");
		return;
	}
	printf("NO\n");
}