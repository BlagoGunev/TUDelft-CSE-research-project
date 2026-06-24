#include<bits/stdc++.h>
using namespace std;
int n,m,a[50];
void solve(){
	scanf("%d%d",&n,&m);
	for (int p=0;p<n;p+=m){
		int q=min(p+m,n),len=q-p,mid=len>>1;
		for (int i=0;i<mid;i++) a[p+i]=p+mid-i;
		for (int i=mid;i<len;i++) a[p+i]=q-i+mid;
	}
	for (int i=0;i<n;i++) printf("%d%c",a[i]," \n"[i==n-1]);
	printf("%d\n",(n-1)/m+1);
	for (int i=0;i<n;i++) printf("%d%c",i/m+1," \n"[i==n-1]);
}
int main(){
	int T;scanf("%d",&T);while (T--) solve();	
	return 0;
}