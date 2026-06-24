#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <set>
#include <stack>
#include <map>
#include <vector>
#include <queue>
#include <cstring>
#include <array>
#include <bitset>

using namespace std;

void solve(){
	string s;
	cin >> s;
	int n=s.size();
	int l;
	for(int i=0; i<n; i++){
		if(s[i]=='?'){
			l=i;
			while(i+1<n && s[i+1]=='?'){
				i++;
			}
			if(l){
				for(int j=l; j<=i; j++){
					s[j]=s[l-1];
				}
			}
			else if(i<n-1){
				for(int j=l; j<=i; j++){
					s[j]=s[i+1];
				}
			}
			else{
				for(int j=l; j<=i; j++){
					s[j]='0';
				}
			}
		}
	}
	cout << s << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}