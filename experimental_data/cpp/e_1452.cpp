#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int maxx = 2e3 + 10;

//预处理1开始的时候 每段的值和每段最小后后面的数组；

 

struct node {

    int l, r;

    bool operator <(const node w) const{

        return l + r < w.l + w.r;

    }

}se[maxx];

 

LL ct ( int x1, int y1, int x2, int y2 ) {

    return max ( 0 , ( min ( y1, y2 ) - max ( x1, x2 ) + 1 ) );

}

 

int main () {

    ios::sync_with_stdio(false);

    cin.tie(0);

 

    int n, m, k, pre[maxx] = {0}, suf[maxx] = {0};

    cin >> n >> m >> k;

    for ( int i = 1; i <= m; i ++ ) cin >> se[i].l >> se[i].r ;

    sort( se + 1, se + 1 + m );

    int res = 0;

 

    for ( int i = 1; i + k - 1 <= n; i ++ ) {

        int sum = 0;

        for ( int j = 1; j <= m; j ++ ) {

            sum += ct ( i, i + k - 1, se[j].l, se[j].r );

            pre[j] = max( pre[j], sum );

        }

    }

 

    for ( int i = 1; i + k - 1 <= n; i ++ ) {

        int sum = 0;

        for ( int j = m; j >= 1; j -- ) {

            sum += ct ( i, i + k - 1, se[j].l, se[j].r );

            suf[j] = max( suf[j], sum );

        }

    }

    for ( int i = 1; i <= m ; i ++ ) {

        res = max ( res , pre[i] + suf[i + 1] );

    }

    cout << res << endl;

}