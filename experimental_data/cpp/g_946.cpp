#include<bits/stdc++.h>
using namespace std;
int val[200005];
int a[200005];
int cnt1[200005];
int cnt2[200005];
int val1[200005];
int val2[200005];
int main()
{

    int n;
    scanf("%d",&n);
    int i;
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        a[i]-=i;
    }
    int now=0;
    for (i=0;i<n;i++)
    {
        int t=upper_bound(val,val+now,a[i])-val;
        if (t==now) now++;
        val[t]=a[i];
        cnt1[i]=now;
        val1[i]=val[now-1];
    }
    now=0;
    for (i=n-1;i>=0;i--)
    {
        int t=upper_bound(val,val+now,-a[i])-val;
        if (t==now) now++;
        val[t]=-a[i];
        cnt2[i]=now;
        val2[i]=-val[now-1];
    }
    int ans=max(cnt1[n-2],cnt2[1])+1;
    for (i=1;i<n-1;i++)
    {
        //i is deleted
        if (val1[i-1]<=val2[i+1]+1)
        {
            ans=max(ans,cnt1[i-1]+cnt2[i+1]+1);
        }
    }
    printf("%d\n",max(0,n-ans));
    return 0;
}