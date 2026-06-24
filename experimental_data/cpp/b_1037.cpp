#include <bits/stdc++.h>
#define MP make_pair
#define PB emplace_back
using namespace std;
typedef long long ll;
template<typename T>
inline T read(T&x){
	x=0;int f=0;char ch=getchar();
	while (ch<'0'||ch>'9') f|=(ch=='-'),ch=getchar();
	while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x=f?-x:x;
}
const int N=2e5+10;
int n,s,i,a[N];
ll res;
int main(){
	read(n),read(s);
	for (i=1;i<=n;i++) read(a[i]);
	sort(a+1,a+1+n);
	res+=abs(s-a[n/2+1]);
	for (i=n/2+2;i<=n;i++){
		if (a[i]<s) res+=s-a[i];
		else break;
	}
	for (i=n/2;i>=1;i--){
		if (a[i]>s) res+=a[i]-s;
		else break;
	}
	cout<<res<<endl;
	return 0;
}