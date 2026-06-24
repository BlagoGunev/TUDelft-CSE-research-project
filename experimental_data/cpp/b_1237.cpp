#include<set>
#include<map>
#include<cmath>
#include<deque>
#include<stack>
#include<ctime>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<climits>
#include<iostream>
#include<algorithm>
#define LL long long
#define ULL unsigned long long
using namespace std;
int read(){
	int f=1,x=0;char c=getchar();
	while(c<'0'||'9'<c){if(c=='-')f=-1;c=getchar();}
	while('0'<=c&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return f*x;
}
#define MAXN 100000
#define INF 0x3f3f3f3f
int a[MAXN+5],b[MAXN+5];
int main(){
	int n=read();
	for(int i=1;i<=n;i++)
		a[read()]=i;
	for(int i=1;i<=n;i++)
		b[a[read()]]=i;
	int cnt=0,Max=0;
	for(int i=1;i<=n;i++){
		if(b[i]<Max)
			cnt++;
		Max=max(Max,b[i]);
	}
	printf("%d\n",cnt);
	return 0;
}