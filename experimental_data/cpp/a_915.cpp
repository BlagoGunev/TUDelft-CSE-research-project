#include <stdio.h>
int main ()
{
    int n, k, i, dem, kq;
    dem = 0;
    scanf ("%d %d", &n, &k);
    kq = n;
    int arrayA[n];
    for (i = 0; i < n; ++i)
    {
        scanf ("%d", &arrayA[i]);
    }
    for (i = 0; i < n ; ++i)
    {
        if (arrayA[i] > 0 && arrayA[i] < 101)
        {
            dem = dem + 1;
        }
    }
    if (dem == n && n > 0 && n < 101 && k > 0 && k < 101)
    {
        for (i = 0; i < n; i++)
        {
            if (k % arrayA[i] == 0)
            {
                kq = i;
            }
        }
        for (i = 0; i < n; i++)
        {
            if (k % arrayA[i] == 0 && arrayA[i] > arrayA[kq])
            {
                kq = i;
            }
        }
    }
    printf("\n%d\n", k / arrayA[kq]);
    return 0;
}