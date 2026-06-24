#include<bits/stdc++.h>
using namespace std;
const int N=4e5+45;
int n,m,mx,a[N],pos[N][2];
bool func(){
	int tot=20;
	for(int i=mx;i;i--){
		basic_string<int> q;
		for(int j=i;j<=mx;j+=i){
			for(int k=0;k<=1;k++){
				if(pos[j][k]) q+=pos[j][k];
			}
		}
		for(auto x:q){
			for(auto y:q){
				if(x<y){
					tot--;
					int k=INT_MAX;
					for(int j=1;j<=n;j++) if(j!=x && j!=y) k&=a[j];
					k+=m;
					if(i>k){
						cout<<"YES"<<endl<<2<<" "<<a[x]<<" "<<a[y]<<endl<<n-2<<" ";
						for(int i=1;i<=n;i++) if(i!=x && i!=y) cout<<a[i]<<' ';
						cout<<endl;
						return 1;
					}
					if(tot<=0) return 0;
				}
			}
		}
	}
	return 0;
}
int main(){
	int T;
	cin>>T;
	while(T--){
		cin>>n>>m;
		mx=1;
		for(int i=1;i<=n;i++) cin>>a[i],mx=max(mx,a[i]);
		memset(pos,0,mx*8+50);
		for(int i=1;i<=n;i++) pos[a[i]][!!pos[a[i]][0]]=i;
		if(func()==0) cout<<"NO"<<endl;
	}
	return 0;
}