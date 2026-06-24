/*Hey, What's up?*/

#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1.0)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
vector<long long>v;
int main()
{
    fastio;
    long long a=0,b=0,c,d,e,f=0,l,g,m,n,k,i,j,t,p,q;
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>a>>b>>c;
        c%=3;
        if(c==0)cout<<a<<'\n';
        else if(c==1)cout<<b<<'\n';
        else{
            a=a^b;
            cout<<a<<'\n';
        }

    }
    return 0;
}