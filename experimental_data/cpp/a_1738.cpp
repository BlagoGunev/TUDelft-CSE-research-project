#include <iostream>

#include <cstdio>

#include <fstream>

#include <iomanip>

#include <algorithm>

#include <cmath>

#include <deque>

#include <vector>

#include <queue>

#include <string>

#include <cstring>

#include <map>

#include <stack>

#include<list>

#include <set>

#include <ctime>

#include<unordered_map>

#include <bitset>

#include<random>

#include<regex>

#include <chrono>



using namespace std;

typedef long long ll;

#define  int  long long 

#define endl "\n"

#define pb push_back

#define pr pair<int,int>

#define all(a) a.begin(),a.end()

#define fr first

#define se second

#define mk make_pair

#define lowbit(x) x&(-x)

const int N = 2e5 + 57;

const int mod = 1e9 + 7;







inline void solve()

{

    int n;

    cin >> n;

    vector<int> a(n);

    vector<int> b;

    vector<int> c;

    int ans = 0;

    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; i++)

    {

        int v;

        cin >> v;

        ans += v;

        if (a[i]) c.push_back(v);

        else b.push_back(v);

    }

    sort(c.begin(), c.end(), greater<int>());

    sort(b.begin(), b.end(), greater<int>());

    int sz = min(c.size(), b.size());

    int mi = 1e9 + 7;

    if (!sz) cout << ans << endl;

    else {

        for (int i = 0; i < sz; i++) ans += b[i] + c[i];

        if(b.size()==c.size())   ans -= min(b.back(), c.back());

        cout << ans << endl;

    }

}



signed main() {

    cin.sync_with_stdio(false);

    cin.tie(0);

    cout.tie(0);

    //cout << fixed << setprecision(9);

    int t = 1;

    cin >> t;

    while (t--)

        solve();

}

/*



*/