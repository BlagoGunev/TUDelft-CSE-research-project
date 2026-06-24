#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <set>
#define fi "A.INP"
#define fo "A.OUT"
#define nmax 100000+5
using namespace std;
typedef long long ll;
typedef set<char> SC;
int n,cnt;
ll res=1ll;
bool ok=false;
SC my_set;
char s[nmax];
//MAIN
int main()
{
	//freopen(fi,"r",stdin);
	//freopen(fo,"w",stdout);
	scanf("%s",s);n=strlen(s);
	for (int i=0;i<n;++i)
	if (isalpha(s[i])) 
	{
		my_set.insert(s[i]); 
		if (i==0) ok=true;
	} else
	if (!isdigit(s[i])) 
	{
		if (i!=0) ++cnt; else res*=9ll;
	}
	n=int(my_set.size());
	for (int i=1;i<=n;++i) 
	{
		if ((i==1) && (ok)) res*=9ll; else res*=ll(11-i);
	}
 	cout << res;
 	for (int i=1;i<=cnt;++i) putchar('0');putchar('\n');
	return 0;
}