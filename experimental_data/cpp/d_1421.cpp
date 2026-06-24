/*

⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿

⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿

⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿

⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠿⠿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿

⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⢛⣉⣥⣤⣶⣶⣶⣶⣶⣶⣤⣬⣉⡛⠿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿

⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⣩⣴⣾⣿⣿⣿⣿⣿⣿⡿⠟⠛⠛⠻⢿⣿⣿⣷⣦⣍⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿

⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⣡⣾⣿⣿⣿⣿⣿⣿⣿⡿⢃⣴⣾⣿⠋⣁⣀⠙⣿⣿⣿⣿⣷⣌⠹⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿

⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⢡⣾⣿⣿⣿⣿⣿⣿⣿⣿⡿⠇⣼⣿⣿⣿⣷⠸⣿⣿⣿⣿⣿⣿⣿⣿⣷⣌⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿

⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⣰⣿⣿⣿⣿⣿⣿⣿⡿⡋⢑⣤⣤⡙⢿⣿⡿⠟⣠⣈⠝⠻⣿⣿⣿⣿⣿⣿⣿⣆⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿

⣿⣿⣿⣿⣿⣿⣿⣿⡟⢰⣿⣿⣿⣿⣿⣿⡿⡃⣠⣾⣿⣿⣿⣷⣶⣶⣶⣾⣿⣿⣷⣄⢈⢿⣿⣿⣿⣿⣿⣿⣆⢻⣿⣿⣿⣿⣿⣿⣿⣿

⣿⣿⣿⣿⣿⣿⣿⣿⠃⣿⣿⣿⣿⣿⣿⡟⠀⣴⣿⣿⣿⣿⡿⠟⠛⠛⠻⢿⣿⣿⣿⣿⣧⠉⢻⣿⣿⣿⣿⣿⣿⡈⣿⣿⣿⣿⣿⣿⣿⣿

⣿⣿⣿⣿⣿⣿⣿⡿⢸⣿⣿⣿⣿⣿⣿⢣⢰⣿⣿⣿⣿⠏⣠⣾⣿⣿⣷⣦⠹⣿⣿⣿⣿⡇⡌⣿⣿⣿⣿⣿⣿⡇⢻⣿⣿⣿⣿⣿⣿⣿

⣿⣿⣿⣿⣿⣿⣿⡇⢸⣿⣿⣿⢿⣿⣿⠸⢸⣿⣿⣿⣿⠀⣿⣿⣿⣿⣿⣿⠄⣿⣿⣿⣿⡇⠀⣿⣿⣿⣿⣿⣿⡇⢸⣿⣿⣿⣿⣿⣿⣿

⣿⣿⣿⣿⣿⣿⣿⣿⢸⣿⣿⡇⡀⣿⠋⣤⣤⣤⡙⢿⣿⣆⠹⣿⣿⣿⣿⠟⣰⣿⣿⠟⠛⠃⠢⣿⣿⣿⣿⣿⣿⡇⣾⣿⣿⣿⣿⣿⣿⣿

⣿⣿⣿⣿⣿⣿⣿⣿⡈⣿⣿⡇⢳⣤⣼⣿⣿⣿⣿⢘⣿⣿⣷⣦⣬⣤⣴⣾⣿⡿⢡⣾⣿⣿⣷⡌⢻⣿⣿⣿⣿⢁⣿⣿⣿⣿⣿⣿⣿⣿

⣿⣿⣿⣿⣿⣿⣿⣿⢧⠸⣿⣿⣄⠻⠿⣿⣿⠿⠋⢼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⠸⣿⣿⣿⣿⣿⠘⣿⣿⣿⠏⣼⣿⣿⣿⣿⣿⣿⣿⣿

⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⠹⣿⣿⣿⣶⣶⣶⣶⣦⣄⡉⣛⠿⠿⠿⠿⠿⠿⠛⠉⣂⣤⣉⡉⢹⠟⣰⣿⣿⠏⣰⣿⣿⣿⣿⣿⣿⣿⣿⣿

⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⡘⢿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣦⣭⣥⣤⣤⣴⣶⣿⣿⡿⠋⢀⣡⣴⣿⡿⢋⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿

⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣆⡙⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠋⣠⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿

⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⣉⠻⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠟⣋⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿

⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⣬⣉⡛⠻⠿⠿⠿⠿⠿⠿⠟⢛⣋⣥⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿

⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣶⣶⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿

⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿

⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿

⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿

*/



#pragma GCC optimize("Ofast")

#pragma GCC target("avx2")



#define _CRT_SECURE_NO_WARNINGS



#include <iostream>

#include <vector>

#include <string>

#include <algorithm>

#include <cmath>

#include <stack>

#include <iomanip>

#include <fstream>

#include <string>

#include <set>

#include <deque>

#include <queue>

#include <map>

#include <bitset>

#include <random>

#include <list>

#include <unordered_map>

#include <unordered_set>

#include <cassert>



using namespace std;



typedef long long ll;

typedef unsigned long long ull;

typedef long double ld;

typedef string str;

//typedef __int128 ultraint;

#define endl "\n"

#define sqrt sqrtl

//#define pow fast_pow



const ll inf = (ll)1e18 + 7;

ld eps = 1e-6;

ld Pi = 3.1415926535897932384;



signed main() {

#ifdef _DEBUG

    freopen("in.txt", "r", stdin);

    freopen("out.txt", "w", stdout);

#endif

    ios_base::sync_with_stdio(0);

    cin.tie(NULL);

    cout.tie(NULL);

    ll t = 1;

    cin >> t;

    while (t--) {

        ll x, y, k;

        cin >> x >> y;

        ll c1, c2, c3, c4, c5, c6, c7, c8, ans = 0;

        cin >> c1 >> c2 >> c3 >> c4 >> c5 >> c6;

        c1 = min(c1, c2 + c6);

        c2 = min(c2, c1 + c3);

        c3 = min(c3, c2 + c4);

        c4 = min(c4, c3 + c5);

        c5 = min(c5, c4 + c6);

        c6 = min(c6, c5 + c1);

        c7 = c2 + c3;

        c8 = c5 + c6;

        if (x >= 0 && y >= 0) {

            k = min(x, y);

            ans += k * c1 + (y - k) * c2 + (x - k) * c6;

        }

        else if (x <= 0 && y >= 0) {

            k = min(abs(x), y);

            ans += k * c7 + (y - k) * c2 + (abs(x) - k) * c3;

        }

        else if (x <= 0 && y <= 0) {

            k = min(abs(x), abs(y));

            ans += k * c4 + (abs(y) - k) * c5 + (abs(x) - k) * c3;

        }

        else {

            // x >= 0 && y <= 0

            k = min(x, abs(y));

            ans += k * c8 + (abs(y) - k) * c5 + (x - k) * c6;

        }

        cout << ans << endl;

    }

}

//痛みを受け入れる。 痛みを知っています。 痛みを感じる。 痛みを参照してください。 真の痛みを知らなければ、真の世界を理解することは不可能です。 今、あなたは痛みを知るでしょう。 神の罰!