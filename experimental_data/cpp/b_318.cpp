#include <stdio.h>
#define LL long long

char a[1000005];

int main()
{
    scanf("%s", a);
    int i = 0;
    LL ans = 0;
    LL tmp = 0;
    while(a[i] != 0)
    {
        if(a[i] == 'h')
        {
            i++;
            if(a[i] == 'e')
            {
                i++;
                if( a[i] == 'a')
                {
                    i++;
                    if(a[i] == 'v')
                    {
                        i++;
                        if(a[i] == 'y')
                        {
                            tmp++;
                            i++;
                        }
                    }
                }
            }
        }
        else if( a[i] == 'm')
        {
            i++;
            if( a[i] == 'e')
            {
                i++;
                if( a[i] == 't')
                {
                    i++;
                    if(a[i] == 'a')
                    {
                        i++;
                        if( a[i] == 'l')
                        {
                            i++;
                            ans += tmp;
                        }
                    }
                }
            }
        }
        else i++;
    }
    printf("%I64d\n", ans);
    return 0;
}