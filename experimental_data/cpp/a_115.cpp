#include <bits/stdc++.h>

using namespace std;



const int N = 2001;



int n, par[N];



int main(){

   // freopen("1", "r", stdin);

    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) scanf("%d", par + i);

    int res = 0;

    for (int i = 1; i <= n; ++i) {

        int cnt = 0, p = i;

        while (p != -1) {

            cnt++;

            p = par[p];

        }

        res = max(res, cnt);

    }

    printf("%d", res);

    return 0;

}