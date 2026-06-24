#include<bits/stdc++.h>

using namespace std;

const int N=5e3+20;

int n,i,j,a[N],ans[N],val,mxf;

int main()

{

    scanf("%d",&n);

    for(i=0;i<n;i++) scanf("%d",&a[i]);

    for(i=0;i<n;i++)

    {

        int m[N]={};

        mxf=0;

        for(j=i;j<n;j++)

        {

            m[a[j]]++;

            if(mxf<m[a[j]])

            {

                mxf=m[a[j]];

                val=a[j];

            }

            else if(mxf==m[a[j]]) val=min(val,a[j]);

            ans[val]++;

        }

    }

    for(i=1;i<=n;i++) printf("%d ",ans[i]);

    return 0;

}