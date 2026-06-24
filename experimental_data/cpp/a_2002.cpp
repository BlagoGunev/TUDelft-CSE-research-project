#include<bits/stdc++.h>
using namespace std;
int T, n, i, j, k, a, b, A[100010];
main()
{
    for(scanf("%d", &T);T--;)
    {
        scanf("%d %d %d", &a, &b, &k);
        printf("%d\n", min(a, k)*min(b, k));
    }
}