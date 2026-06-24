#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define A 0
#define B 1

long long int n;
long long int m;
long long int mod = -1;
long long int modmin;
long long int w[100][100];
long long int diff[2][100];
long long int a[100];
long long int b[100];
bool impossible;

long long int gcd(long long int a, long long int b) {
    long long int c;
    while (b != 0) {
        c = a%b;
        a = b;
        b = c;
    }
    return a;
}

int main() {
    memset(diff, -1, sizeof(diff));

    scanf("%lld %lld", &n, &m);
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            scanf("%lld", &w[i][j]);
            if (modmin < w[i][j]+1) modmin = w[i][j]+1; 
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m-1; j++) {
            if (i == 0) diff[B][j] = w[i][j+1] - w[i][j];
            else if (w[i][j+1] - w[i][j] == diff[B][j]) {
                //pass
            } else if (mod == -1) {
                mod = abs(w[i][j+1] - w[i][j] - diff[B][j]);
            } else {
                mod = gcd(mod, abs(w[i][j+1] - w[i][j] - diff[B][j]));
            }

            if (mod != -1 && mod < modmin) {
                puts("NO");
                return 0;
            }
        }
    }

    for (int j=0; j<m; j++) {
        for (int i=0; i<n-1; i++) {
            if (j == 0) diff[A][i] = w[i+1][j] - w[i][j];
            else if (w[i+1][j] - w[i][j] == diff[A][i]) {
                //pass
            } else if (mod == -1) {
                mod = abs(w[i+1][j] - w[i][j] - diff[A][i]);
            } else {
                mod = gcd(mod, abs(w[i+1][j] - w[i][j] - diff[A][i]));
            }

            if (mod != -1 && mod < modmin) {
                puts("NO");
                return 0;
            }
        }
    }

    if (mod == -1) mod = modmin;
    a[0] = 0;
    puts("YES");
    printf("%lld\n", mod);
    printf("%lld", a[0]);
    for (int i=1; i<n; i++) {
        a[i] = a[i-1] + diff[A][i-1];
        if (a[i] < 0) a[i] = mod * ((-a[i])/mod + ((-a[i])%mod != 0)) + a[i];
        else a[i] %= mod;
        printf(" %lld", a[i]);
    }
    puts("");

    for (int i=0; i<m; i++) {
        b[i] = w[0][i] - a[0];
        if (b[i] < 0) b[i] = mod * ((-b[i])/mod + ((-b[i])%mod != 0)) + b[i];
        else b[i] %= mod;
    }

    printf("%lld", b[0]);
    for (int i=1; i<m; i++) printf(" %lld", b[i]);
    puts("");
}