#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

int main()
{
    int k,d;
    scanf("%d%d",&k,&d);
    if(k>1&&!d)
    {
        puts("No solution");
        return 0;
    }
    if(k==1&&!d)
    {
        puts("0");
        return 0;
    }
    printf("%d",d);
    for(int i=1;i<k;i++)putchar('0');
    puts("");
    return 0;
}