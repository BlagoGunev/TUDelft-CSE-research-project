#include<stdio.h>
#include<string.h>
#include <algorithm>
#include <map>
using namespace std;
int main()
{
    int i,j,n=3,sum=0;
    int c[20][20];
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&c[i][j]);
    c[1][1]=(c[1][0]+c[1][2])/2;
    sum=c[1][0]+c[1][2]+c[1][1];
    c[0][0]=sum-c[0][1]-c[0][2];
    c[2][2]=sum-c[2][0]-c[2][1];
    for(i=0;i<n;i++)
        printf("%d %d %d\n",c[i][0],c[i][1],c[i][2]);
    return 0;
}