#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <list>
#include <cstdlib>
#include <string.h>
#include <algorithm>
//#define   vector list
using namespace std;

int main()
{
    int n,test,arr[100]={0};
    char str[100];
    scanf("%s",str);
    int l=strlen(str);
   // printf("%d",l
             int j=0;
    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i]!='+')
         arr[j++]=str[i]-48;

    }
    n=(l-1)/2;
   /* for(int i=0;i<=n;i++)
    {
        printf("%d\t",arr[i]);
    }*/

    sort(arr,arr+n+1);
    for(int i=0;i<=n;i++)
    {
        if(i!=n)
        printf("%d+",arr[i]);
        else printf("%d",arr[i]);

    }

    return 0;

}