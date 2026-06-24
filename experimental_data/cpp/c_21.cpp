#include <bits/stdc++.h>
#include<bits/stdc++.h>

#define LL  int64_t

using namespace std;

LL sum[100005];

int main()

{

    int n;

    scanf("%d",&n);

    //LL sum=0;

    for(int i=1;i<=n;i++)

    {

        LL x;

        scanf("%lld",&x);

        sum[i]=sum[i-1]+x;

    }

    LL ans=0;

    if(sum[n]%3==0)

    {

        LL summ=sum[n]/3;

        LL temp=0;

        for(int i=1;i<=n-1;i++)

        {

            if(sum[i]==2*summ)

            {

                temp++;//有多少个前缀和=2*summ

            }

        }

        for(int i=1;i<=n-1;i++)

        {

            if(sum[i]==2*summ)//如果当前位置前缀和为2*summ,那么这个位置之后的前缀和等于summ的数目-1，

                temp--;

            if(sum[i]==summ)//因为这个位置为summ,后面有temp个前缀和等于2*summ，i到这temp个位置之间的元素和就为2*summ-summ,这些位置之后的数和就为summ

            {

                ans+=temp;//所以能够分成三份

            }

        }

    }

    printf("%lld\n",ans);

    return 0;

}