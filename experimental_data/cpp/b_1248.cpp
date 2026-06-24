#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
#define ll long long
int n;
int a[100005];
int main()
{
    scanf("%d",&n);
    ll sum1=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        sum1+=a[i];
    }
    sort(a,a+n);
    int t=n/2;
    ll sum=0;
    for(int i=0;i<t;i++)
        sum+=a[i];
    ll ans=sum*sum+(sum1-sum)*(sum1-sum);
    printf("%lld\n",ans);
    return 0;
}