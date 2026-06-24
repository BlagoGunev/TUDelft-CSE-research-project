#include<cstdio>

using namespace std;

int main()
{
    int n,sum=0,i,mx=-1;
    scanf("%d",&n);
    int arr[n+3];
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        if(arr[i]>mx)
            mx=arr[i];
    }
    for(i=0;i<n;i++)
    {
        sum+=(mx-arr[i]);
    }
    printf("%d\n",sum);
    return 0;
}