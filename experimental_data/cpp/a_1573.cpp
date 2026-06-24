// Problem: A. Countdown
// Contest: Codeforces - Codeforces Round #743 (Div. 2)
// URL: https://codeforces.com/contest/1573/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
typedef long long ll ;
#define int ll 
using namespace std ;

////////// *****Hey bhagwan rakshya karna !!***** //////////

signed main( )
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    int t = 1;
	cin>>t;
    while(t--){
		int n;
		cin>>n;
		string s;
		cin>>s;
		int cnt = 0;
		if(s[n-1]!='0'){
				cnt+=(s[n-1]-'0');
		}
		for(int i = 0;i<s.size()-1;i++){
			
			
			if(s[i]!='0'){
					cnt+=(s[i]-'0')+1;
				}
			
		}
		cout<<cnt<<endl;
    }
    return 0 ;
}  


/////////// melomane //////////////