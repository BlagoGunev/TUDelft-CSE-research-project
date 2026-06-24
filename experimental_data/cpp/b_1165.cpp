#include<stdio.h>
#include<algorithm>
#define MAXN 200005
using namespace std;
int a[MAXN];
int main()
{
    int n;
    int i;
    int j=0;
    int ans=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",a+i);
    sort(a,a+n);
    for(i=0;i<n;i++)
    {
        while((j<n)&&(a[j]<i+1))
            j++;
        if((j<n)&&(a[j]>=(i+1)))
            ans=i+1;
        j++;
        if(j>=n)
            break;
    }
    printf("%d",ans);
}