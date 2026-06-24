/*
 _     _                             
| |__ | |__   __ _  __ _ _   _  __ _ 
| '_ \| '_ \ / _` |/ _` | | | |/ _` |
| |_) | | | | (_| | (_| | |_| | (_| |
|_.__/|_| |_|\__,_|\__, |\__, |\__,_|
                   |___/ |___/       
*/
#include<bits/stdc++.h>

#define ll          long long
#define pb          push_back
#define ppb         pop_back
#define BigInt      __int128
#define endl        '\n'
#define mii         map<ll int,ll int>
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define hell        1000000007

using namespace std;

#define N  100005

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int TESTS=1;
    cin>>TESTS;
    cerr << "---" << endl;
    while(TESTS--)
    {
        ll int n, m;
		cin >> n >> m;
		vi v = {n};
		bool fnd = false;
		while(!v.empty()) {
			ll int curr = v.back();
			v.pop_back();
			if(curr == m) fnd = true;
			if(curr % 3 == 0) {
				v.pb(curr / 3);
				v.pb(2 * curr / 3);
			}
		}
		if(fnd) cout << "YES" << endl;
		else cout << "NO" << endl;
    }
    return 0;
}