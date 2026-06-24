#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int arr[5],i,j,k,count=1;
    for(i=0;i<4;i++)
    scanf("%d",&arr[i]);
    sort(arr,arr+4);
    for(i=0;i<3;i++)
    if(arr[i]!=arr[i+1])
    count++;
    printf("%d\n",4-count);
}