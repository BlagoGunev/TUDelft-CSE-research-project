#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
#include<map>
#include<stack>
#include<string>
#include<algorithm>
#include<cmath>
#define rg register
#define il inline
using namespace std;
typedef long long ll;
ll read() {
	ll ans = 0, flag = 1; char ch;
	while((ch=getchar())<'0'||ch>'9') if(ch =='-') flag=-1;
	ans = ch ^ 48;
	while((ch=getchar())>='0'&&ch<='9') ans=(ans<<3)+(ans<<1)+(ch^48);
	return flag*ans;
}
void WRI(ll x) {
	if (x<0) { putchar('-');x=-x;}
	if (x>9) WRI(x/10);
	putchar(x%10+'0');
}
void write(int x, char o) {WRI(x),putchar(o);}
int pre[200005];
int main(){
	int n=read();
	for(rg int i=0;i<n;i++)
		pre[i]=read();
	sort(pre,pre+n);
	int ans=0,last=0;
	for(rg int i=0;i<n;i++){
		while(pre[i]-pre[last]>5){
			last++;
		}
		ans=max(ans,i-last+1);
	}
	cout<<ans<<endl;
	return 0;
}