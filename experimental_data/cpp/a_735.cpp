#include <stdio.h>

using namespace std;

int main()
{
    long n,k,i,g,t;
    char a[101],pom;
    scanf("%ld%ld%c",&n,&k,&pom);
    for (i=1; i<=n; i++)
    {
        scanf("%c",&a[i]);
        if (a[i]=='G')
            g=i;
        if (a[i]=='T')
            t=i;
    }

    bool moze=0;
    for (i=g; i<=n; i+=k)
        if (a[i]=='#')
            break;
        else
            if (i==t)
            {
                moze=1;
                break;
            }

    if (moze)
    {
        printf("YES");
        return 0;
    }

    moze=0;
    for (i=g; i>=1; i-=k)
        if (a[i]=='#')
            break;
        else
            if (i==t)
            {
                moze=1;
                break;
            }

    if (moze)
    {
        printf("YES");
        return 0;
    }

    printf("NO");

    return 0;
}