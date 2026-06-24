#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<cstdio>
#include<vector>
#include<cctype>
#include<cstdlib>
#include<utility>
#include<string.h>
#include<algorithm>

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define For(i,x,y) for(int i=((int)x);i<=((int)y);i++)
#define Dep(i,y,x) for(int i=((int)y);i>=((int)x);i--)
#define Rep(i,x) for (int y,i=head[x];i;i=E[i].nxt) if ((y=E[i].to)!=fa[x])
using namespace std;

typedef double db;
typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> pii;

int rd() {
    char c=getchar(); int t=0;
    while (!isdigit(c)) c=getchar();
    while (isdigit(c)) t=t*10+c-48,c=getchar(); return t;
}
void wt(int x) {
    if (x<0) putchar('-'),wt(-x);
    else { if (x>9) wt(x/10); putchar(x%10+48); }
}

const int N=1e5+35;
const int mod=1e9+7;

char c[N];
LL n,q,pw[N],s[N],l,r,A,B,num[N],ans;

int main() {
	n=rd(),q=rd();
	scanf("%s",c+1),pw[0]=1,s[0]=1;
	For (i,1,n) {
		pw[i]=2LL*pw[i-1]%mod;
		s[i]=(s[i-1]+pw[i])%mod;
		num[i]=num[i-1]+(c[i]=='1');
	}
	while (q--) {
		l=rd(),r=rd();
		A=num[r]-num[l-1],B=r-l+1-A;
		if (!A) { puts("0"); continue; }
		ans=(s[A-1]+(pw[A]-1+mod)*s[B-1]%mod)%mod;
		printf("%I64d\n",ans);
	}
	
	return 0;
}
/*
3 1
010
1 3

*/