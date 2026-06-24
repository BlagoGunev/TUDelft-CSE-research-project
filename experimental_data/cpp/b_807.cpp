#include <sstream>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <map>
#include <string>
#include <queue>
#include <bitset>

using namespace std;

#define fto(i,a,b) for (int i = (a); i <= b; i++)
#define fdw(i,a,b) for (int i = (a); i >= b; i--)
#define rep(i,a) for(int i = 0; i < a; i++) 
#define read(a) cin >> a
#define read2(a, b) cin >> a >> b
#define read3(a, b, c) cin >> a >> b >> c
#define read4(a, b, c, d) cin >> a >> b >> c >> d
#define write(a) cout << a << " "
#define writeln(a) cout << a << "\n"

#define PI 3.14159265
#define oo 1000000000
#define debug(a) cout << #a << " = " << a << endl

#define sz(a) int((a).size())
#define all(c) (c).begin(), (c).end()
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define next thongdeptrai
#define prev thongbachuthegioi
#define y1 thongsieucapvutru
#define y0 thongnotgay

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;

#define maxn 100005

using namespace std;

ll p, x, y;
ll succ, fail;
vector<long long> res;

void encode(ll s) {
	res.clear();
	ll ii = (s / 50) % 475;
	fto(j, 1, 25) {
		//debug(ii);
    	ii = (ii * 96 + 42) % 475;
    	//debug(ii);
    	res.pb(ii + 26);    	
    }
}

bool inThere(int succ, int fail) {
	ll t = x + 100 * succ - 50 * fail;
	encode(t);
	
	fto(i, 0, res.size() - 1)
		if (res[i] == p) return true;
	return false;
}

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("in.inp", "r", stdin);
    #endif

    read3(p, x, y);

    int cnt = -1;
    for(ll point = x; point >= y; point -= 50) {
    	cnt++;
    	//debug(point);
    	if (inThere(0, cnt)) {
    		cout << 0 << endl;
    		return 0;
    	}
    }

    succ = 1, fail = 1;
    while (1) {
    	if (inThere(succ, 1)) {
    		cout << succ << endl;
    		return 0;
    	}
    	if (inThere(succ, 0)) {
    		cout << succ << endl;
    		return 0;
    	}
    	fail += 2;
    	succ += 1;
    }

 	#ifndef ONLINE_JUDGE
    	cout << endl;
    	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	#endif
}