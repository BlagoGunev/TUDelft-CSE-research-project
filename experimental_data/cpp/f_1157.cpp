#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
int num[N];
int main()
{
    int n,k;
    int l,r;
    int ansl=1,ansr=1;
    memset(num,0,sizeof(num));
    scanf("%d",&n);
    int a;
    for(int i=1;i<=n;i++)
        scanf("%d",&a),num[a]++;
    l=1,r=1,k=num[1];
    int sum=num[1];
    for(l=1;l<=200000;l++)
    {
        if(num[l]==0) continue;
        if(l>r)
        {
            sum=num[l];
            r=l;
        }
        while(num[r]>=2&&num[r+1]>=1) r++,sum+=num[r];
        if(num[l-1]==1)
        {
            if(sum+1>k)
            {
                k=sum+1;
                ansl=l-1;
                ansr=r;
            }
        }
        //cout<<l<<" "<<r<<" "<<sum<<endl;
        if(sum>k)
        {
            k=sum;
            ansl=l;ansr=r;
        }
        sum-=num[l];
    }
    cout<<k<<endl;
    for(int i=ansl;i<=ansr;i++)
        printf("%d ",i);
    for(int i=ansr;i>=ansl;i--)
        for(int j=0;j<num[i]-1;j++)
            printf("%d ",i);
    printf("\n");
    return 0;
}