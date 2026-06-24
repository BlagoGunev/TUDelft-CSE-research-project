#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll gcd(ll a,ll b)
{
if(b==0)
return a;
return gcd(b,a%b);
}
int main()
{
    ll lcm,hcf,l,r;
    cin>>l>>r>>hcf>>lcm;
    if(lcm%hcf!=0)
    {
    cout<<"0";
    return 0;
    }
    ll val=lcm/hcf;
    if(l%hcf!=0)
    {
    l/=hcf;
    l++;
    }
    else
    l/=hcf;

    r/=hcf;
    ll pr=1;
    ll cnt=0;
    for(ll i=1;i*i<=val;i++)
    {
   if(val%i==0)
   {
   pr=val/i;
   if((i>=l&&i<=r)&&(pr>=l&&pr<=r)&&gcd(max(i,pr),min(i,pr))==1)
   {
   if(i!=pr)
   cnt+=2;
   else
   cnt++;
   }
   }
    }


    cout<<cnt;



    return 0;
}