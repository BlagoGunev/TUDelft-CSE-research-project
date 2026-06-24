#include <bits/stdc++.h>
using namespace std;
typedef long long int64;

int cnt[10];
int cur[10];

int64 fact(int x) {
    int64 ans = 1LL;
    for (int i = 1; i <= x; i++) ans *= i;
    return ans;
}

int64 calc() {
    int digits = 0;
    for (int i = 0; i < 10; i++) digits += cur[i];

    int64 val = fact(digits);
    for (int i = 0; i < 10; i++) {
        val /= fact(cur[i]);
    }


    if (cur[0] > 0) {
        int64 over = fact(digits-1);
        cur[0]--;
        for (int i = 0; i < 10; i++) {
            over /= fact(cur[i]);
        }
        cur[0]++;
        val -= over;
    }
    
    return val;
}

int main() {
    int64 n;
    cin >> n;

    while (n > 0) {
        cnt[n % 10]++;
        n /= 10;
    }

    for (int i = 0; i < 10; i++) {
        cur[i] = cnt[i] < 0;
    }

    int64 ans = 0;

    for (int v0 = cnt[0] > 0; v0 <= cnt[0]; v0++)
    for (int v1 = cnt[1] > 0; v1 <= cnt[1]; v1++)
    for (int v2 = cnt[2] > 0; v2 <= cnt[2]; v2++)
    for (int v3 = cnt[3] > 0; v3 <= cnt[3]; v3++)
    for (int v4 = cnt[4] > 0; v4 <= cnt[4]; v4++)
    for (int v5 = cnt[5] > 0; v5 <= cnt[5]; v5++)
    for (int v6 = cnt[6] > 0; v6 <= cnt[6]; v6++)
    for (int v7 = cnt[7] > 0; v7 <= cnt[7]; v7++)
    for (int v8 = cnt[8] > 0; v8 <= cnt[8]; v8++)
    for (int v9 = cnt[9] > 0; v9 <= cnt[9]; v9++) {
        cur[0] = v0;
        cur[1] = v1;
        cur[2] = v2;
        cur[3] = v3;
        cur[4] = v4;
        cur[5] = v5;
        cur[6] = v6;
        cur[7] = v7;
        cur[8] = v8;
        cur[9] = v9;
        ans += calc();
    }

    cout << ans << endl;
    return 0;
}