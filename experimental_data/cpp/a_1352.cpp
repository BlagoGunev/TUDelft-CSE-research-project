#include <bits/stdc++.h>
          
using namespace std;
          
#define ll long long
#define vi vector<int> 
#define pb push_back
#define sz(s) (int)s.size() 
#define all(v) v.begin(), v.end()
#define show(a) cerr << #a <<" -> "<< a <<"\n"
 
ll mn = 1000000, mx = -1000000000; 
ll cnt, cnt2, sum, x = 1, y = 10;
int t;
vi v;
			             
int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    for (int i = 1; i <= t; i++) {
    	int n; 
    	cin >> n;
		while (n > 0) {
			cnt = n % 10;
			n = n / 10;
			if (cnt > 0) {
				v.pb(x * cnt);
				x *= 10;
				sum++;
			}
			else {
				x *= 10;
			}
		}
		cout << sum << "\n";
		sort (all(v));
		reverse (all(v));
		for (int j = 0; j < sz(v); j++) {
			cout << v[j] << " ";
		}
		cout << "\n";
		sum = 0;
		cnt = 0;
		x = 1;
		v.clear();
	}
    return 0; 
}