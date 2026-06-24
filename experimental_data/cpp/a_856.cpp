//created by missever

#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> P;

const int mod = 1e9 + 7;
const int maxn = 1e6 + 5;

int a[105],b[105],n;
bitset<maxn> v;

bool check(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(v[abs(b[j] - b[i])]) return false;
        }
    }
    return true;
}

int get_rand() {
    return 1LL * rand() * rand() % 1000000 + 1;
}

void solve() {
    int i,j;
    scanf("%d",&n);
    for(i = 0; i < n; i++) scanf("%d",&a[i]);
    sort(a,a + n);
    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++) v[a[j] - a[i]] = 1;
    }
    for(i = 1;i < 10000; i++) {
        for(j = 1;j < n; j++) {
            if(v[i * j]) break;
        }
        if(j == n) break;
    }
    if(i == 10000) printf("NO\n");
    else {
        printf("YES\n");
        b[0] = 1;
        for(j = 1; j < n; j++) b[j] = b[j - 1]+ i;
        for(i = 0; i < n; i++) printf("%d%c",b[i]," \n"[i + 1 == n]);
    }
    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++) v[a[j] - a[i]] = 0;
    }
}

int main() {
    int t;
    srand(time(NULL));
    scanf("%d",&t);
    while(t--) solve();
    return 0;
}