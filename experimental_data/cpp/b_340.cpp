//

//  Created by Running Photon on 2016-06-06

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

#define lson rt<<1

#define rson rt<<1|1

#define CLR(x) memset(x, 0, sizeof x)

using namespace std;

const int inf = 0x3f3f3f3f;

const int MOD = 1e9 + 7;

const int maxn = 1e3 + 10;

const int maxv = 1e3 + 10;

const double eps = 1e-9;



struct Point {

    int x, y;

    Point(int _x = 0, int _y = 0) : x(_x), y(_y){}

    void read() {

        scanf("%d%d", &x, &y);

    }

    void print() {

        printf("%d %d\n", x, y);

    }

    Point operator+ (Point rhs) {

        return Point(x + rhs.x, y + rhs.y);

    }

    Point operator- (Point rhs) {

        return Point(x - rhs.x, y - rhs.y);

    }

    int operator^ (Point rhs) {

        return x * rhs.y - y * rhs.x;

    }

    bool operator< (const Point& rhs) const {

        if(x == rhs.x) return y < rhs.y;

        return x < rhs.x;

    }

    bool operator== (const Point& rhs) const {

        return x == rhs.x && y == rhs.y;

    }

};

vector <Point> Gh(vector <Point>& a) {

    vector <Point> res;

    int m = 0;

    sort(ALL(a));

    for(int i = 0; i < a.size(); i++) {

        while(m > 1 && ((res[m-1] - res[m-2]) ^ (a[i] - res[m-2])) <= 0) {

            m--;

            res.pop_back();

        }

        m++;

        res.push_back(a[i]);

    }

    int k = m;

    for(int i = a.size() - 2; i >= 0; i--) {

        while(m > k && ((res[m-1] - res[m-2]) ^ (a[i] - res[m-2])) <= 0) {

            m--;

            res.pop_back();

        }

        m++;

        res.push_back(a[i]);

    }

    res.pop_back();

    return res;

}

int getthree(Point p1, Point p2, Point p3) {

//    p1.print(); p2.print(); p3.print();

//    cout << abs((p2 - p1) ^ (p3 - p1)) / 2.0 << " debug" << endl;

    return abs((p2 - p1) ^ (p3 - p1));

}

int getarea(Point p1, Point p2, Point p3, Point p4) {

//    p1.print(); p2.print(); p3.print(); p4.print();

    return getthree(p2, p4, p1) + getthree(p2, p4, p3);

}

int main() {

#ifdef LOCAL

	freopen("in.txt", "r", stdin);

//	freopen("out.txt","w",stdout);

#endif

//	ios_base::sync_with_stdio(0);

    int n;

    scanf("%d", &n);

    vector <Point> p;

    for(int i = 1; i <= n; i++) {

        Point x; x.read();

        p.push_back(x);

    }

    int area = 0;

    vector <Point> q = Gh(p);

    if(q.size() == 3) {

        area = getthree(q[0], q[1], q[2]);

        int small = inf;

        for(int i = 0; i < p.size(); i++) {

            if(p[i] == q[0] || p[i] == q[1] || p[i] == q[2]) continue;

            small = min(getthree(p[i], q[0], q[1]), getthree(p[i], q[1], q[2]));

            small = min(small, getthree(p[i], q[0], q[2]));

        }

        area -= small;

    }

    else {

        for(int i = 0; i < q.size(); i++) {

            for(int j = i + 1; j < q.size(); j++) {

                for(int k = j + 1; k < q.size(); k++) {

                    for(int l = k + 1; l < q.size(); l++) {

                        area = max(area, getarea(q[i], q[j], q[k], q[l]));

                    }

                }

            }

        }

    }

    printf("%.10f\n", area / 2.0);

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

         ·ð×æ±£ÓÓ       ÓÀÎÞBUG

*/