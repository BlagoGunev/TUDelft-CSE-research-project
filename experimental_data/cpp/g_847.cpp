#include <cstdio>
#include <iostream>
#include <string.h>
#include <string> 
#include <map>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <stack>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
const int maxn=15,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int f[maxn];
char s[maxn];

int main() {
	int n,i,j,ans;
	scanf("%d",&n);
	mem0(f);
	for (i=1;i<=n;i++) {
		scanf("%s",s);
		for (j=0;j<7;j++) {
			if (s[j]=='1') f[j]++;
		}
	}
	ans=-1;
	for (i=0;i<7;i++) ans=max(ans,f[i]);
	printf("%d\n",ans);
	return 0;
}