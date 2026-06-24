#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
    int i,j,x,i0,j0;
    for(i=0;i<5;++i)
        for(j=0;j<5;++j)
        {
            scanf("%d",&x);
            if(x==1){i0=i;j0=j;break;}
        }
    printf("%d",abs(2-i0)+abs(2-j0));
    //system("pause");

    return 0;
}