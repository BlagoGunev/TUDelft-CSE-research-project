#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
#define int long long
#define maxn 100000
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
namespace fastIO{
	void read(int &x){
		int f=1;x=0;char ch=getchar();
		while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
		while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
		x*=f;
	}
	void fput(int x){if(x>=10) fput(x/10);putchar(x%10+'0');}
}
using namespace fastIO;
#undef int
int main(){
#define int long long
	int n,sum=0,maxx=-INF;read(n);
	for(int i=1;i<=n;i++){
		int x;read(x);
		sum+=x,maxx=max(maxx,x);
	}
	if((sum&1)||maxx>sum/2) puts("NO");
	else puts("YES");
}