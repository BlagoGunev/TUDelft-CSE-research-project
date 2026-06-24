//
//  main.cpp
//  nik string typing
//
//  Created by PREEYADARSHEE DEV on 01/04/18.
//  Copyright ? 2018 PREEYADARSHEE DEV. All rights reserved.
//

#include <stdio.h>
#include <string.h>
int main()
{
    int n;
    scanf("%d",&n);
    char a[102];
    scanf("%s",a);
    int count=0,temp=n,kemp=0;
    for(int i=1;i<strlen(a);i++)
    {
        if(a[0]==a[i])
        {
            if(i<=strlen(a)/2)
            {
                kemp=0;
               for(int j=0;j<i;j++)
               {
                  if(a[j]!=a[j+i])
                  {
                      kemp=kemp+1;
                  }
               }
                if(kemp==0)
               {
                  count=1;
                  temp=n-i;
               }
            }
        }
    }
    printf("%d\n",temp+count);
}