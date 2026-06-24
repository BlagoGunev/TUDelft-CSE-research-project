#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>

#define ABS(a) ((a>0)?a:-(a))
#define MIN(a,b) ((a<b)?(a):(b))
#define MAX(a,b) ((a<b)?(b):(a))
#define FOR(i,a,n) for (int i=(a);i<(n);++i)
#define FI(i,n) for (int i=0; i<(n); ++i)
#define pnt pair <int,int>
#define mp make_pair
#define PI 3.14159265358979
#define MEMS(a,b) memset(a,b,sizeof(a))
#define LL long long
#define U unsigned
using namespace std;
#define DOUT(a) cerr << a << endl;
char a[1010][1010];
int cnt1[1010],cnt2[1010];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	FOR(i,0,n)
		scanf("%s",&a[i]);
	MEMS(cnt1,0);
	MEMS(cnt2,0);
	FOR(i,0,n)
		FOR(j,0,m)
			if (a[i][j]=='*')
			{
				cnt1[i]++;
				cnt2[j]++;
			}
	LL res=0;
	FOR(i,0,n)
		FOR(j,0,m)
			if (a[i][j]=='*')
			{
				res+=(cnt1[i]-1)*1ll*(cnt2[j]-1);
			}
	cout<<res<<endl;
	return 0;
}