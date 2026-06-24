#include<stdio.h>
int sum[10005];
int a[100005];
int getsum(int i,int e)
{
    if(i==0)return sum[e];else
    return sum[e]-sum[i-1];
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(i==0)sum[i]=a[i];else sum[i]=a[i]+sum[i-1];
    };
    int ct=0;
    for(int i=0;i<n-1;i++)
    {
     if(getsum(0,i)==getsum(i+1,n-1))ct++;
    }
    printf("%d\n",ct);



}