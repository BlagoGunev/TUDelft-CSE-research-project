#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long n;
    cin>>n;
    vector<pair<long long,long long> >a;
    long long mod=998244353;
    for(long long i=0; i<n; i++)
    {
        char c;
        cin>>c;
        long long x=0;
        if(c=='+')cin>>x;
        a.push_back({c=='+',x});
    }
    long long ans=0;
    for(long long i=0; i<a.size(); i++)
    {
        long long counter=1;
        if(a[i].first==1)
        {
            long long x=a[i].second;
            vector<long long>b;
            b.push_back(1);
            for(long long j=0; j<i; j++)
            {
                if(a[j].first==0)
                {
                    b[0]*=2;
                    b[0]%=mod;
                    for(long long k=0; k+1<b.size(); k++)b[k]+=b[k+1],b[k]%=mod;
                }
                else
                {
                    if(a[j].second<=x)
                    {
                        b.push_back(0);
                        for(long long k=b.size()-1; k>=1; k--)
                        {
                            b[k]+=b[k-1];
                            b[k]%=mod;
                        }
                    }
                    else counter*=2,counter%=mod;
                }
            }

            for(long long j=i+1; j<n; j++)
            {
                if(a[j].first==0)
                {
                    for(long long k=0; k+1<b.size(); k++)b[k]+=b[k+1],b[k]%=mod;
                }
                else
                {
                    if(a[j].second<x)
                    {
                        b.push_back(0);
                        for(long long k=b.size()-1; k>=1; k--)
                        {
                            b[k]+=b[k-1];
                            b[k]%=mod;
                        }
                    }
                    else counter*=2,counter%=mod;
                }
            }
            for(long long k:b)ans+=((k*x)%mod)*counter,ans%=mod;
            //cout<<endl;
        }
        ans%=mod;
    }
    cout<<ans<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long t;
    t=1;
    while(t--)
    {
        solve();
    }
    return 0;
}