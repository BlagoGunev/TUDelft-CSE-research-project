#include <bits/stdc++.h>

using namespace std;

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char a[30], pr = ' ';
    int n, i;
    fgets(a, sizeof(a), stdin);
    for(i = 0; i < strlen(a); i ++)
    {
            //printf("%d %c",i, a[i]);
            if (a[i] == ' ')
            {
               n = i;
               break;
            }
    }
    printf("%c",a[0]);
    for(i = 1; i < n; i ++)
    {
            if(a[i] < a[n + 1])
                    printf("%c",a[i]);
            else
            {
                printf("%c",a[n + 1]);
                break;
            }
 
    }
    if(i == n)
         printf("%c",a[n+ 1]);

    return 0;
}