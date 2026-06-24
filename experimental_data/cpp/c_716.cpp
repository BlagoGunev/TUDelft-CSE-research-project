#include <cstdio>

using namespace std;
typedef long long ll;

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        ll t = i + 1;
        if (t == 1LL)
            printf("2\n");
        else
            printf("%lld\n", t * (t + 1) * (t + 1) - t + 1);
    }

    return 0;
}