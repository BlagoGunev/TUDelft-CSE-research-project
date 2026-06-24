#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
using namespace std;
char a[1010];
int main()
{
    
    int t=0;
    scanf("%d",&t);
    for(int qwe=0;qwe<t;qwe++)
    {

        scanf("%s",&a);
        if(strlen(a)==1)
        {
            printf("-1\n");
            continue;
        }
        
        bool flag=false;
        char p=a[strlen(a)-1];
        for(int i=0;i<(strlen(a)-1);i++)
        {
            if(a[i]!=p)
            {
                char p2=a[0];
                a[0]=a[i];
                a[i]=p2;
                printf("%s\n",a);
                flag=true;
                break;
            }
        }
        if(flag)
            continue;
        printf("-1\n");
    }
    return 0;
}