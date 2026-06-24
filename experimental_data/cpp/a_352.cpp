#include <bits/stdc++.h>



using namespace std;



int n, d[6], a;

string s;

bool check = true;

int main() {

    //freopen("codef.inp", "r", stdin);

    //freopen("codef.out", "w", stdout);

    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) scanf("%d", &a), ++d[a];

    if (d[0] == 0) {

        printf("-1\n");

        return 0;

    }

    if (d[0] != 0 && d[5] < 9) {

        printf("0\n");

        return 0;

    }

    if (d[0] != 0) {

        for (int i = 1; i <= d[5] / 9; ++i) {

            for (int j = 1; j <= 9; ++j) printf("5");

        }

        for (int i = 1; i <= d[0]; ++i)printf("0");

        printf("\n");

        return 0;

    }



    return 0;

}