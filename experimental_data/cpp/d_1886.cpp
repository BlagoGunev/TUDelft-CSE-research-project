#include <bits/stdc++.h>
#define int long long 
using namespace std;
int simo(int x, int y,int z){
	if (y>0) {
		if (y%2 == 0){
			return simo(((x%z)*(x%z))%z, y/2, z)%z;
		}
		
		else {
			return ((x%z)*simo(((x%z)*(x%z))%z, (y-1)/2, z))%z;
		}
	}
	else if (y==0){
		return 1;
	}
}
bool goof(char x){
	if(x=='?') return false;
	else return true;
}
void solve(){
	int n,m;
	cin >> n >> m;
	int first,last=1;
	int mod=998244353;
	string s="";
	char x;
	cin >> x;
	if(x=='>'||x=='<') first=1;
	else first=0;
	s+=x;
	for(int i=1;i<=n-2;i++){
		cin >> x;
		s+=x;
		if(x=='?') last*=i;
		last%=mod;
	}
	cout << (first*last)%mod << "\n";
	for(int i=0;i<m;i++){
		int a;
		cin >> a >> x;
		a--;
		if(a==0){
			if(goof(s[a])!=goof(x)){
				if(goof(s[a])) first=0;
				else first=1;
				s[a]=x;
			}
		}
		else{
			if(goof(s[a])!=goof(x)){
				if(goof(s[a])) last*=a;
				else{
					//cout << last << "\n";
					//cout << "YES \n";
					last*=simo(a,mod-2,mod);
					//cout << last << "\n";
				}
				last%=mod;
				//cout << "HI! \n";
				s[a]=x;
			}
		}
		cout << (first*last)%mod << "\n";
	} 
}
signed main(){
	int T=1;
	//cin >> T;
	while(T--){
		solve();
						
					
			
	}
}