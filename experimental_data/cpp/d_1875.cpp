#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <functional>
#include <numeric>

#define quick std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)
#define please 0
#define AC return
#define ifY(flag) if (flag) std::cout << "YES\n"; else std::cout << "NO\n"
#define ifN(flag) if (flag) std::cout << "NO\n"; else std::cout << "YES\n"
#define PRINT(a, begin, end) for (int i = begin; i <= end; ++ i) std::cout << a[i] << " \n"[i == end]
#define PRINT_(a, begin, end) for (int i = begin; i <= end; ++ i) std::cout << a[i] << "\n"
#define IF(flag, y, n) { if (flag) std::cout << y << "\n"; else std::cout << n << "\n"; }
typedef unsigned long long ULL;
typedef long long LL;
using i64 = long long;
using ui64 = unsigned long long;
const double epx = 1e-6;
/****************
****************/

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++ i) {
    	std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    if (a[0] != 0) {
    	std::cout << "0\n";
    } else {
    	std::map<int, int> cnt;
    	for (auto & x : a) {
    		++ cnt[x];
    	}

    	int mex = 0;
    	while (cnt.count(mex)) {
    		++ mex;
    	}

    	std::vector<i64> f(mex + 1, 1e18);
    	f[mex] = 0;
    	for (int i = mex - 1; i >= 0; -- i) {
    		for (int j = i + 1; j <= mex; ++ j) {
    			f[i] = std::min(f[i], 1ll * (cnt[i] - 1) * j + f[j] + i);
    		}
    	}
    	std::cout << f[0] << "\n";
    }
}


int main() {
	quick;
	int T = 1; std::cin >> T;
	//scanf("%d", &T);
	while (T -- ) {
		solve();
	} 
	//system("pause");
	AC please;
}
/*******************************************
	
............................................
............................................
............................................
............................................
.............................1ffLf1.........
............................GGGGGGGC........
....................8CCCftCCCCC1;LLG,.......
..................:CC8CCC.CCCCCCii..........
.................CC88CCCC.CCCCCCC...........
................CC88CCCCC .8.:8CCC..........
................888 CCCCC.88888G;;,.........
,................888CC88.888888888,.........
:::...............CCC888.888888888..........
:::::............Gi1tC8f888888C88,..........
:::::::,........111tttfffffLG8888...........
:::::::::,....ii111ttttttfffttG.............
::::::::::::i111tttffffffffffttt............
::::::::::11tttttfff....fffffftt ...........
..:::::::1Lf1tff,..........fffff1...........
....,:::iiftG::::::.........,LLGtL..........
::::::;:i11t:;;;;;;::,,,,,,,,, f1ii,::,,,,,,
::::::::i11t:::::::::::::::::::f111:::::::::
::::::::111:::::::::::::::::::::t111::::::::
:::::::i1if::::::,,,,,,,,,,,,,,:i111::::::,:
,,,,,::,8G,,,,,,,,,,,,,,,,,,,,,,,tL1:,,,,,,,
,,,,,,:LGL;,,,,,,,,,,,,,,,,,,,,,,,CLf,,,,,,,
,,,,,;LGGG,,,,:,,,,,,,,,,,,,,,,,,,LGCG,,,,,,

*******************************************/