#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<string>
#include<cctype>
#include<algorithm>
#include<complex>
#include<vector>
#include<queue>
#include<set>
#include<map>

using namespace std;

const int MaxN = 500000 + 5, MaxM = MaxN;
const int Mod = 1000003;

int N, M;
int tx[MaxN], ty[MaxM];

const int tmpx[4] = {1, 0, 0, 1};
const int tmpy[4] = {1, 1, 0, 0};

int main() {

    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    
    memset(tx, -1, sizeof(tx)); memset(ty, -1, sizeof(ty));
    scanf("%d%d ", &N, &M); char ch;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j){
            scanf("%c", &ch);
            if (ch == '.') continue;
            int tt = (j & 1) ^ tmpy[ch - '1'];
            if (tx[i] == -1) tx[i] = tt;
            else {
                 if (tx[i] != tt) {puts("0"); return 0;}
            }
            tt = (i & 1) ^ tmpx[ch - '1'];
            if (ty[j] == -1) ty[j] = tt;
            else {
                 if (ty[j] != tt) {puts("0"); return 0;}
            }
        }
        getchar();
    }
    int ans = 1;
    for (int i = 1; i <= N; ++i) if (tx[i] == -1) ans = (long long)ans * 2 % Mod;
    for (int j = 1; j <= M; ++j) if (ty[j] == -1) ans = (long long)ans * 2 % Mod;

    cout << ans << endl;

    return 0;

}