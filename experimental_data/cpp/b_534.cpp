#include <bits/stdc++.h>



using namespace std;



typedef long long ll;



int main()

{

    ios_base::sync_with_stdio(false);

    int v1,v2,t,d,k,ans=0;

    cin>>v1>>v2>>t>>d;

    ans=v1;

    t--;

    while(abs(v1+d-v2)<=((t-1)*d) && t>0)

    {

        v1+=d;

        t--;

        ans+=v1;

    }

    if(t!=0)

    {

        v1=(t-1)*d+v2;

        t--;

        ans+=v1;

        while(v1>v2)

        {

            v1-=d;

            ans+=v1;

            t--;

        }

    }

    cout<<ans;

    return 0;

}