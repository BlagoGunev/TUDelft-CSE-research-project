#include <bits/stdc++.h>

using namespace std;

#define lp(i,a,b) for(int i=a;i<b;i++)

#define lpi(i,a,b) for( int i=a ;i>=b;i--)

#define ll long long

map<string ,int>mp;

int main() {

	string s; cin>>s;

	lp(i,0,10){

		string ss; cin>>ss;

		mp[ss]=i;

	}

	lp(i,0,8){

		string ss= s.substr(i*10,10);

		cout<<mp[ss];

	}

	return 0;

}