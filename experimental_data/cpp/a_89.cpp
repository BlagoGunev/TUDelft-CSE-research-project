//

//  Created by Running Photon on 2016-07-12

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

#include <cassert>

#include <stack>

#define ALL(x) x.begin(), x.end()

#define INS(x) inserter(x, x,begin())

#define ll long long

#define CLR(x) memset(x, 0, sizeof x)

using namespace std;

const ll inf = 0x3f3f3f3f3f3f3f3f;

const int MOD = 1e9 + 7;

const int maxn = 1e6 + 10;

const int maxv = 1e3 + 10;

const double eps = 1e-9;



int main() {

#ifdef LOCAL

	freopen("in.txt", "r", stdin);

//	freopen("out.txt","w",stdout);

#endif

//	ios_base::sync_with_stdio(0);

    ll n, m, k;

    vector <ll> v;

    scanf("%lld%lld%lld", &n, &m, &k);

    for(int i = 0; i < n; i++) {

        ll x;

        scanf("%lld", &x);

        v.push_back(x);

    }

//    assert(n != 1);

    ll res = inf;

    for(int i = 0; i < v.size(); i += 2) {

        res = min(res, v[i]);

    }

    ll step = (n + 1) / 2;

    step = m / step;

    res = min(res, k * step);

    if(n % 2 == 0) {

        res = 0;

    }

    if(n == 1) {

        res = min(v[0], k*m);

    }

    printf("%lld\n", res);

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