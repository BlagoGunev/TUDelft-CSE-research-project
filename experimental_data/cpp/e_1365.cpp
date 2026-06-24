#include<iostream>

#include<algorithm>

#include<string.h>

#include<vector>

using namespace std;

// #define debug(x) cout<<"[debug]"#x<<"="<<x<<endl

typedef long long ll;

typedef long double ld;

typedef pair<int,int> pii;

const double eps=1e-8;

const int INF=0x3f3f3f3f,mod=998244353;



#ifndef ONLINE_JUDGE

#define debug(...)

#include<debug>

#else

#define debug(...)

#endif



const int N=502,M=61;

ll a[N];

// vector<vector<int>> id(M);

// bool st[M];

int main()

{

    int n;

    scanf("%d",&n);

    for(int i=1;i<=n;i++)

    {

        scanf("%lld",&a[i]);

        // for(int j=0;j<M;j++)

        // {

        //     if(a[i]>>j&1) id[j].push_back(i);

        // }

    }



    if(n==1)

    {

        printf("%lld\n",a[1]);

    }

    else if(n==2)

    {

        printf("%lld\n",a[2]|a[1]);

    }

    else

    {

        ll res=0;

        for(int i=1;i<=n;i++)

        {

            for(int j=i+1;j<=n;j++)

            {

                for(int k=j+1;k<=n;k++)

                {

                    ll ans=(a[i]|a[j]|a[k]);

                    res=max(res,ans);

                }

            }

        }

        printf("%lld\n",res);

    }



    

}