#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,Max=0;
    bool flag = true;
    scanf("%d",&n);
    int left[n],right[n],ans[n];
    for(int i=0; i<n;i++)
    {
        scanf("%d",&left[i]);
        if(left[i] > i)
        {
            flag=false;
        }
    }
    for(int i=0; i<n;i++)
    {
        scanf("%d",&right[i]);
        if(left[i]+right[i] >Max)
        {
            Max = left[i]+right[i] ;
        }
    }
    for(int i=0; i<n;i++)
    {
        ans[i]=1+Max-(left[i]+right[i]);
    }
    for(int i =0; i<n; i++)
    {
        int greater=0, lesser = 0;
        for(int j=i+1; j<n; j++)
        {
            if(ans[j] > ans[i])
            {
                greater++;
            }

        }
        if(greater != right[i])
        {
            flag=false;
        }
        greater=0;
        for(int j =0; j<i;j++)
        {
            if(ans[j] > ans[i])
            {
                greater++;
            }

        }
        if(greater != left[i])
        {
            flag=false;
        }
    }
    if(flag == false)
    {
         cout <<"NO";
         return 0 ;
    }
    cout <<"YES"<<endl;
    for(int i=0; i<n;i++)
    {
        cout<<ans[i]<<" ";
    }

    return 0;
}