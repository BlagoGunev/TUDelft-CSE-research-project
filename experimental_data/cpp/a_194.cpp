#include <cstdio>

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    for(int a=0; 2*a <= k; a++)
        for(int b=0; 2*a+3*b <= k; b++)
            for(int c=0; 2*a+3*b+4*c <= k; c++)
                if((k-2*a-3*b-4*c) % 5 == 0 && (k-2*a-3*b-4*c) / 5 + a + b + c == n)
                {
                    printf("%d\n", a);
                    return 0;
                }
    return 0;
}