#include<bits/stdc++.h>
using namespace std;
int a[3100000];
int n,w;
long long t;
inline int yy(int k){
	return (k==1 ? 2 : (k+1)/2);
}
int solve(){
	int o=0;
	for(int i=1;i<n;i++)if(a[i]==a[i+1])o=1;
	if(!o){
		t=0;
		for(int i=1;i<=n;i++)t+=a[i];
		return 0;
	}
	t=0;
	for(int i=1;i<=n;i++)t+=w-a[i];
	if(t<=1){
		t=1ll*n*w-t;
		return 0;
	}
	t=1ll*n*w-1;
	int j=1;
	while(a[j]==w)j++;
	int k=n;
	while(a[k]==w)k--;
	int ans=k-j;
	for(int i=j;i<k;i++){
		if(a[i]<w&&a[i+1]==w){
			int c=0;
			for(int ii=i+1;a[ii]==w;ii++)c++;
			ans+=yy(c);
		}
	}
	o=n+10;
	if(j>2||k<=n-2)o=2;
	int c=0;
	for(int i=j;i<k;i++){
		if(a[i]==a[i+1]){
			if(i+3<=k&&a[i+1]<w&&a[i+2]==w&&a[i+3]<w&&i>j&&a[i-1]<w)c--;
			o=min(o,c);
			break;
		}
		if(a[i]<w&&a[i+1]<w)c++;
	}
	c=0;
	for(int i=k;i>j;i--){
		if(a[i]==a[i-1]){
			if(i-3>=j&&a[i-1]<w&&a[i-2]==w&&a[i-3]<w&&i<k&&a[i+1]<w)c--;
			o=min(o,c);
			break;
		}
		if(a[i]<w&&a[i-1]<w)c++;
	}
	return ans+o;
}
int main(){
	int _;
	cin>>_;
	while(_--){
		scanf("%d%d",&n,&w);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		int ans=0; 
		if(w==2){
			t=2*n;
			a[0]=2;
			for(int i=1;i<=n;i++)if(a[i-1]==2&&a[i]==1)t--;
			for(int i=1;i<n;i++)if(a[i]==1&&a[i+1]==1)ans++;
		} 
		else ans=solve();
		printf("%lld %d\n",t,ans);
	}
	return 0;
}