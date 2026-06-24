#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>

using namespace std;

int main()
{
    int n, lowest;
    int arr[100000];
    scanf("%d", &n);
    for(int i=0; i<n; ++i) scanf("%d", &arr[i]);
    lowest=arr[0];
    for(int i=1; i<n; ++i) if(arr[i]<lowest) lowest=arr[i];
    for(int i=0; i<n; ++i) if(arr[i]%lowest) {printf("-1"); return 0;}
    printf("%d",lowest);
    return 0;
}