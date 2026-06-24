#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define deg( x ) cout<<""#x"="<<x<<endl
const int N=2e5+10;
int a[N];
void solve(){
	string s;
	cin>>s;
	int n;
	cin>>n;
	int len=(int)s.size();
	int num=len;
	s="?"+s;
	while(num<n){
		n-=num;
		num--;
	}
	int shan=len-num;
	vector<char>ans;
	for(int i=1;i<=len;i++){
		while(shan&&(!ans.empty()&&ans.back()>s[i])){
			shan--;
			ans.pop_back();
		}
		ans.emplace_back(s[i]);
	}
	cout<<ans[n-1];
}
signed main(  ){
	ios::sync_with_stdio( 0 );
	cin.tie( 0 ); cout.tie( 0 );
	int T=1;
	cin>>T;
	while( T-- ){
		solve( );
	}
	return 0;
}