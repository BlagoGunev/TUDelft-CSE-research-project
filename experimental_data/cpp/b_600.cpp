#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <ctime>
#include <utility>
#include <functional>
#include <numeric>
#include <stack>
#include <sstream>
#include <iomanip>
#include <memory.h>
#include <cassert>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
const db pi=acos(-1);
inline void gn(int &x){
    int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');
    if(c=='-')sg=-1,x=0;else x=c-'0';
    while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';
    x*=sg;
}
inline void gn(ll &x){
    int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');
    if(c=='-')sg=-1,x=0;else x=c-'0';
    while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';
    x*=sg;
}

int qq,n,m,i,j,l,r,mid;
int a[1<<20],b[1<<20];

int main()
{
	//freopen("input.txt","r",stdin);

	gn(n); gn(m);
	for (int i=1;i<=n;i++) gn(a[i]);
	for (int i=1;i<=m;i++) gn(b[i]);
	sort(a+1,a+n+1);

	for (int i=1;i<=m;i++){
		l=1; r=n; qq=0;
		for (int j=0;j<20;j++){
			mid=(l+r)>>1;
			if (a[mid]<=b[i]){
				qq=max(qq,mid);
				l=mid+1;
			} else r=mid;
		}
		printf("%d ",qq);
	}
	
	return 0;
}