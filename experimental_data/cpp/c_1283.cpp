#include<bits/stdc++.h>
#define ll long long int
#define trace(x) cerr<<#x<<" : "<<x<<endl;
#define jaldi ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
ll gcd(ll a,ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
int main()
{
    jaldi
    int n;
    cin>>n;
    vector<int> v(n);
    vector<bool> visited(n,false);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        if(v[i]!=0) visited[v[i]-1]=true;
    }
    vector<int> rem;
    for(int i=0;i<n;i++)
    {
        if(!visited[i]) rem.push_back(i);
    }
    int j=0;
    vector<int> extra;
    extra=rem;
    for(int i=0;i<rem.size();i++)
    {
        int nm = rem[i];
        if(v[nm]==0)
        {
            while(extra[j]==nm || extra[j]==-1)
            {
                j++;
                if(j==extra.size()) j=0;
            }
            v[nm]=rem[j]+1;
            extra[j]=-1;
        }
    }
    j=0;
    for(int i=0;i<n;i++)
    {
        if(v[i]==0)
        {
            while(extra[j]==-1)
            {
                j++;
                if(j==extra.size()) j=0;
            }
            v[i]=extra[j]+1;
            extra[j]=-1;
        }
    }
    for(int x:v) cout<<x<<" ";
    return 0;
}