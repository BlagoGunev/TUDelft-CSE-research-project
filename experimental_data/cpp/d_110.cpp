#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

vector<LL> luck;

void dfs(LL x)

{

    if(x > 1000000000) return;

    luck.push_back(x);

    dfs(x * 10 + 4);

    dfs(x * 10 + 7);

}



LL gao(LL x1, LL x2, LL y1, LL y2)

{

    return max(min(y2, y1) - max(x1, x2), 0LL);

}

int main()

{

    dfs(0);

    luck.push_back(1000000000 + 10);

    sort(luck.begin(), luck.end());

    LL pl, pr, vl, vr, k;

    cin >> pl >> pr >> vl >> vr >> k;

    LL Y = (pr - pl + 1) * (vr - vl + 1);

    LL X = 0;

    for(int i = 1; i + k < luck.size(); i++) {

        X += gao(luck[i - 1], pl - 1, luck[i], pr) * gao(luck[i + k - 1], vl, luck[i + k], vr + 1);

        X += gao(luck[i - 1], vl - 1, luck[i], vr) * gao(luck[i + k - 1], pl, luck[i + k], pr + 1);

        if(k == 1 && luck[i] >= vl && luck[i] <= vr && luck[i] >= pl && luck[i] <= pr) {

            X -= 1;

        }

    }

    printf("%.12f\n", (double)X/(double)Y);

    return 0;

}