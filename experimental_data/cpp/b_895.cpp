#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
int n,k,x,a[100007],l,r;
long long ans=0;
int cal(int z){
	return z/x;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>x>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	l=1;
	r=1;
	for(int i=1;i<=n;i++){
		while(r<=n){
			if(a[r]<a[i] || cal(a[r])-cal(a[i]-1)<=k){
				r++;
				continue;
			}
			else break;
		}
		while(l<=n){
			if(a[l]<a[i] || cal(a[l])-cal(a[i]-1)<k){
				l++;
				continue;
			}
			else break;
		}
		if(l>n) break;
		ans+=r-l;
	}
	cout<<ans;
}