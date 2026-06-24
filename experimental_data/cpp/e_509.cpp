#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define maxn 543232

double ans;
double l[maxn], d[maxn];
char in[maxn];
int n;

int main() {
	scanf("%s", in + 1); 
	n = strlen(in + 1);
    for (int i = 1; i <= n; ++i) {
        l[i] = l[i - 1] + 1. / i;
        d[i] = d[i - 1] + double(n - i + 1) / i;
    }
    for (int i = 1; i <= n; ++i)
    {
        register int k = in[i];
        if ((k == 'A') || (k == 'E') || (k == 'I') || (k == 'O') || (k == 'Y') || (k == 'U'))
        {
            k = min(i - 1, n - i);
            ans += k; 
            ans += d[n] - d[n - k]; 
            ans += (l[n - k] - l[k]) * (k + 1);
        }
    }
    printf("%.12lf\n", ans);
	return 0;
}