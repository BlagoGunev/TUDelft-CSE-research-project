/*

	Training Contest 15 : Last day in Next to Farid's Gallery!

	http://vjudge.net/contest/131916#overview

*/



#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;



int main()

{

	int n , m;

	cin>>n>>m;

	

	string s;

	for ( int i=1 ; i<=n ; i++ )

		cin>>s;

	s = '.' + s;

	

	int ans = 0;

	for ( int i=0 ; i<m ; i++ )

		ans += (s[i]=='.' && s[i+1]=='B');

	

	cout<<ans<<"\n";

	return 0;

}