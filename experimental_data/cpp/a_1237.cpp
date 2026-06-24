#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define flash ios_base::sync_with_stdio(false); cin.tie(NULL),cout.tie(NULL);

int main()
{
    flash
    ll n;
    cin>>n;
    ll i=0,j=0;
    while(n--)
    {
        ll a,k;
        cin>>a;
        if(a%2==0)
        k=a/2;
        else
        {
            if(a<0)
            {
                if(i%2==0)
                k=a/2-1;
                else
                k=a/2;
                i++;
            }
            else
            {
                if(j%2==0)
                k=a/2+1;
                else
                k=a/2;
                j++;
            }
        }
        cout<<k<<"\n";
    }
    return 0;
}