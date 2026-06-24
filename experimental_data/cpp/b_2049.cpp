#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<stack>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
#define ll long long
#define lowbit(x) x&-x
using namespace std;
int tt,n,a[500005];
char s[500005];
int main(){
	scanf("%d",&tt);
	while(tt--){
		scanf("%d%s",&n,s+1);
		int f1=0,f2=0;
		for(int i=1;i<=n;++i){
			if(i==1&&s[i]=='s') continue;
			if(i==n&&s[i]=='p') continue;
			if(s[i]=='s') f1=1;
			if(s[i]=='p') f2=1;
		}
		if(f1&&f2) printf("NO\n");
		else printf("YES\n");
	}
}