#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=2e5+5;
inline int read(){
    char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1; c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0'; c=getchar();}
    return x*f;
}
int n,t[N],m;
char a[N],b[N];
bool check(int g){
	int now=1;
	for(int i=1;i<=n;i++) if(t[i]<=g){
		if(a[i]==b[now]) now++;
		if(now>m) return true;
	}
	return false;
}
void solve(){
	int l=1,r=n,ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d",n-ans);
}
int main(){
	//freopen("in","r",stdin);
	scanf("%s%s",a+1,b+1);
	n=strlen(a+1);
	m=strlen(b+1);
	for(int i=1;i<=n;i++) t[read()]=n-i+1;
	solve();
}