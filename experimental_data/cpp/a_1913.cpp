#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <stack>
#include <map>
#include <queue>
#include <cstring>
#include <array>
#include <bitset>

using namespace std;

void solve(){
	string s;
	cin >> s;
	int s1, s2=0;
	s1=s[0]-'0';
	int ind=1;
	while(ind<s.size() && s[ind]=='0'){
		s1*=10;
		s1+=s[ind]-'0';
		ind++;
	}
	while(ind<s.size()){
		s2*=10;
		s2+=s[ind]-'0';
		ind++;
	}
	if(s1<s2){
		cout << s1 << ' ' << s2 <<  '\n';
	}
	else{
		cout << -1 << '\n';
	}
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