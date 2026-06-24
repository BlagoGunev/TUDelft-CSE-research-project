#include <cstdio>

const int maxN = 2001;

char T[maxN];

int main()
{
    int n;
    scanf ("%d", &n);
    scanf ("%s", T);

    for (int i=n-2; i>=0; i-=2)
        printf("%c", T[i]);

    for (int i=1-(n%2); i<n; i+=2)
        printf("%c", T[i]);

    printf("\n");
    return 0;
}