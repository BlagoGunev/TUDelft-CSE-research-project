//

//  Created by Running Photon on 2016-06-08

//  Copyright (c) 2015 Running Photon. All rights reserved.

//

#include <algorithm>

#include <cctype>

#include <cmath>

#include <cstdio>

#include <cstdlib>

#include <cstring>

#include <iomanip>

#include <iostream>

#include <map>

#include <queue>

#include <string>

#include <sstream>

#include <set>

#include <vector>

#include <stack>

#define ALL(x) x.begin(), x.end()

#define INS(x) inserter(x, x,begin())

#define ll long long

#define CLR(x) memset(x, 0, sizeof x)

using namespace std;

const ll inf = 0x3f3f3f3f3f3f3f3f;

const int MOD = 1e9 + 7;

const int maxn = 1024 * 1024 + 1;

const int maxv = 1e2 + 10;

const double eps = 1e-9;





struct P {

    ll x, k;

    int state;

    bool operator< (const P& rhs) const {

        return k < rhs.k;

    }

}a[maxv];

ll dp[maxn];

int main() {

#ifdef LOCAL

	freopen("in.txt", "r", stdin);

//	freopen("out.txt","w",stdout);

#endif

//	ios_base::sync_with_stdio(0);

    int n, m;

    ll b;

    cin >> n >> m >> b;

    for(int i = 0; i < n; i++) {

        ll x, k, mi;

        cin >> x >> k >> mi;

        a[i].x = x;

        a[i].k = k;

        a[i].state = 0;

        for(int j = 0; j < mi; j++) {

            int tmp;

            cin >> tmp;

            tmp--;

            a[i].state |= (1 << tmp);

        }

    }

    ll ans = inf;

    sort(a, a+n);

    memset(dp, 0x3f, sizeof dp);

    dp[0] = 0;

    for(int i = 0; i < n; i++) {

        for(int j = 0; j < 1 << m; j++) {

            if(dp[j] == inf || (j | a[i].state) == j) continue;

            dp[j|a[i].state] = min(dp[j|a[i].state], dp[j] + a[i].x);

        }

        ans = min(ans, dp[(1<<m)-1] + a[i].k * b);

    }

    if(ans == inf) ans = -1;

    cout << ans << endl;

	return 0;

}





/*

                   _ooOoo_

                  o8888888o

                  88" . "88

                  (| -_- |)

                  O\  =  /O

               ____/`---'\____

             .'  \\|     |//  `.

            /  \\|||  :  |||//  \

           /  _||||| -:- |||||-  \

           |   | \\\  -  /// |   |

           | \_|  ''\---/''  |   |

           \  .-\__  `-`  ___/-. /

         ___`. .'  /--.--\  `. . __

      ."" '<  `.___\_<|>_/___.'  >'"".

     | | :  `- \`.;`\ _ /`;.`/ - ` : | |

     \  \ `-.   \_ __\ /__ _/   .-` /  /

======`-.____`-.___\_____/___.-`____.-'======

                   `=---='

^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

         佛祖保佑       永无BUG

*/