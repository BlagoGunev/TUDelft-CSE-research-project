#define _CRT_SECURE_NO_DEPRECATE
#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<assert.h>
#include<string>
#include<string.h>
#include<set>
#include<sstream>
#include<locale>
#include<bitset>
#include<stack>
#include<map>
#include<queue>
#include<functional>
#include<math.h>
#include<unordered_set>
#include<unordered_map>

using namespace std;
#define MAX 1000000000+7
#define SMX 100000+7
#define REP(i,a,b) for(int i=int(a);i<=int(b);i++)
#define TMAX 1e8+7
#define endl "\n"

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<long long> vl;



//void make_sieve(vector<bool> &sieve) { for (int p = 2; p*p < 1000001; p++)if (sieve[p])for (int i = p*p; i <= 1000001; i += p)sieve[i] = false; }
vector<int> inp[28];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
#ifdef SARATH
	assert(freopen("f://programming//test/temp.in", "r", stdin));
//	assert(freopen("f://programming//test/temp.out", "w", stdout));
#endif // SARATH
	int n;
	cin >> n;
	string s;
	cin >> s;
	for (int i = 0; i < n; i++) {
		inp[s[i] - 'a'].push_back(i + 1);
	}
	int m;
	cin >> m;
	while (m--) {
		string p;
		cin >> p;
		int mx = -1;
		int pl = p.length();
		vector<int> arr(28, 0);
		for (int i = 0; i < pl; i++) {
			int ind = (int)p[i] - 'a';
			if (inp[ind].size() < arr[ind])
				return 0;
			mx = max(mx, inp[ind][arr[ind]]);
			arr[ind]++;
		}
		cout << mx << endl;

	}

#ifdef SARATH
	cerr << "Time elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " s." << endl;
#endif


	return 0;

}