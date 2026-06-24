#include <iostream>

#include <string>

#include <vector>

#include <algorithm>

#include <sstream>

#include <queue>

#include <deque>

#include <bitset>

#include <iterator>

#include <list>

#include <stack>

#include <map>

#include <set>

#include <functional>

#include <numeric>

#include <utility>

#include <limits>

#include <time.h>

#include <math.h>

#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#include <assert.h>

#include <iostream>

#include <string>

#include <vector>

#include <algorithm>

#include <sstream>

#include <queue>

#include <deque>

#include <bitset>

#include <iterator>

#include <list>

#include <stack>

#include <map>

#include <set>

#include <unordered_set>

#include <functional>

#include <numeric>

#include <utility>

#include <limits>

#include <time.h>

#include <math.h>

#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#include <iomanip>

#include <assert.h>

#include <iostream>

#include <string>

#include <vector>

#include <algorithm>

#include <sstream>

using namespace std;

using ll = long long;

using vi = vector<int>;

using vii = vector< vector <int>>;

using vl = vector<ll>;

using vll = vector< vector <ll>>;

using vpi = vector <pair <int, int>>;

using vpl = vector <pair <ll, ll>>;

#define pb push_back

#define rsz resize

#define all(x) begin(x), end(x)

#define sz(x) (int)(x).size()

#define loop(i,n) for(int i = 0;i<n;i++)

#define loop1(i,n) for(int i = 1;i<n;i++)

#define loopx(i, x, n) for(int i = x; i<n; i++);

using pi = pair<int, int>;

using pl = pair<ll, ll>;

#define mp make_pair

#define ff first

#define ss second

#define endl "\n"

#define yes cout << "Yes" << endl;

#define no cout << "No" << endl;









int main() {

#ifdef LOCAL

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif

    ios::sync_with_stdio(0);

    cin.tie(0);

    int t;



    int n;

    cin >> n;

    string s;

    cin >> s;

    int ans = 0;

    int l = 0;

    int c = 0;

    int f = 0;

    for (auto x : s) {

        l++;

        if (x == '(') c++;

        else c--;

        if (c < 0) f = 1;

        if (c == 0) {

            if (f)ans += l;

            l = 0;

            f = 0;

        }

    }

    if (c != 0) cout << -1 << endl;

    else cout << ans << endl;









    return 0;



}