#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define xx first
#define yy second

#ifndef _WIN32
#define gc getchar_unlocked
#else
#define gc getchar
#endif // _WIN32
void ri(int &a) {
    a = 0;
    register int x = gc();
    bool neg = false;
    while (x < '0' || x > '9') {
        if (x == '-') neg = true;
        x = gc();
    }
    while (x >= '0' && x <= '9') {
        a = (a << 3) + (a << 1) + (x-'0');
        x = gc();
    }
    if (neg) a = -a;
}

const int maxn = 1001000, INF = (1 << 30)-1;

int n;
int arr[maxn];
int loc[maxn];
int swaps;

int main() {
    ri(n);
    for (int i = 0; i < n; i++) {
        ri(arr[i]);
        arr[i]--;
        loc[arr[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] != i) {
            int temp = arr[i];
            int l = loc[i];
            arr[i] = i;
            loc[i] = i;
            arr[l] = temp;
            loc[temp] = l;
            swaps++;
        }
    }
    if (swaps%2 == n%2) {
        cout << "Petr\n";
    } else {
        cout << "Um_nik\n";
    }
    return 0;
}