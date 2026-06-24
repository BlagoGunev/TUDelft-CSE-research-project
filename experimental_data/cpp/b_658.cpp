#include <bits/stdc++.h>

using namespace std;

#define MAXN 150005
#define MAXK 10

int T[MAXN];
int best[MAXK];

inline
int readInt() {
    char c;
    int q = 0;
    do {
        c = getchar();
    } while(!isdigit(c));
    do {
        q = (q << 1) + (q << 3) + (c - '0');
        c = getchar();
    } while(isdigit(c));
    return q;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif // ONLINE_JUDGE

    int n, k, q;
    int numDisplay = 0;

    n = readInt(); k = readInt(); q = readInt();
    for(int i = 0; i < n; ++ i)
        T[i] = readInt();

    while(q--) {
        int qType = readInt(), id = readInt() - 1;
        if(qType == 1) {
            int i = 0;
            while(i < numDisplay && T[best[i]] > T[id])
                ++ i;
            if(i == numDisplay && numDisplay < k)
                best[numDisplay++] = id;
            else if(i < numDisplay) {
                if(numDisplay == k) {
                    for(int j = k - 1; j > i; -- j)
                        best[j] = best[j - 1];
                } else {
                    for(int j = numDisplay++; j > i; -- j)
                        best[j] = best[j - 1];
                }
                best[i] = id;
            }
        } else {
            int i = 0;
            while(i < numDisplay && best[i] != id)
                ++ i;
            if(i < numDisplay) {
                puts("YES");
            } else {
                puts("NO");
            }
        }
    }

    return 0;
}