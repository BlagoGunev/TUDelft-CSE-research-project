#include <bits/stdc++.h>

using namespace std;



#define DEBUG(x)    cerr << #x << " = " << x << endl

#define INPUT       freopen("Data.inp", "r", stdin)

#define OUTPUT      freopen("Data.out", "w", stdout)



typedef long long LL;

typedef pair<int, int> II;



const int N = (int) 5e3 + 10;

int n, k, f[N];

char S[N];

bool dp[N][N];



int TSize;

int nxt[N * N][2], cnt[N * N];



int main() {

    #ifdef LOCAL

        INPUT;

        OUTPUT;

    #endif



    scanf("%s", S + 1); n = strlen(S + 1);

    scanf("%d", &k);



    for (int i = n; i >= 1; --i) {

        dp[i][i] = true;

        for (int j = i + 1; j <= n; ++j) {

            if (S[i] == S[j]) dp[i][j] = (i + 2 <= j - 2) ? dp[i + 2][j - 2] : true;

            else dp[i][j] = false;

        }

    }



    for (int i = 1; i <= n; ++i) {

        for (int j = n; j >= i; --j) f[j] = f[j + 1] + dp[i][j];

        int p = 0;

        for (int j = i; j <= n; ++j) {

            int c = S[j] - 'a';

            if (nxt[p][c] == 0) nxt[p][c] = ++TSize;

            p = nxt[p][c]; cnt[p] += f[j];

        }

    }



    /*for (int i = 1; i <= n; ++i) {

        for (int j = i; j <= n; ++j) if (dp[i][j]) {

            for (int k = i; k <= j; ++k) cout << S[k];

            cout << endl;

        }

    }*/



    int p = 0;

    while (1) {

        int L = nxt[p][0];

        int R = nxt[p][1];

        int cM = p == 0 ? 0 : (cnt[p] - cnt[L] - cnt[R]);

        if (k <= cM) break;

        k -= cM;

        if (L > 0 && k <= cnt[L]) {

            putchar('a');

            p = L;

        }

        else {

            k -= cnt[L];

            putchar('b');

            p = R;

        }

    }

    return 0;

}