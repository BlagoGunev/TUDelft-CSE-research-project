#include <bits/stdc++.h>
using namespace std;
#define ll long long


signed main() {
    ll n,a,b,e,s,ans=0,flag=1,i,k,curr;
    
    cin>>n>>k;
    if(k>=n)
    {
        cout<<1<<endl;
        cout<<1<<endl;
        return 0;
    }
    else
    {
        cout<<(n/(2*k+1)+ (n%(2*k+1)!=0))<<endl;
        curr=k+1;
        ll rem=n%(2*k+1);
        //cout<<rem<<endl;
        if(rem==0)
        {
            for(i=1;i<=n/(2*k+1);i++)
            {
                cout<<curr<<" ";
                curr+=(2*k+1);
            }
            return 0;
        }
        if(rem<=k && rem>0)
        {
            curr-=(k+1-rem);
            //cout<<curr<<endl;
            
            for(i=1;i<=n/(2*k+1);i++)
            {
                cout<<curr<<" ";
                curr+=(2*k+1);
            }
            if(rem!=0)
                cout<<n<<endl;
        }
        else{
           // cout
            for(i=1;i<=n/(2*k+1);i++)
            {
                cout<<curr<<" ";
                curr+=(2*k+1);
            }
            cout<<(n/(2*k+1))*(2*k+1)+k+1;
        }
    }
   
   
    return 0;
}