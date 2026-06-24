#include<bits/stdc++.h>

#define ll long long

using namespace std;

ll power(ll a,ll b)

{

    ll ans=1;

    for(ll i=1;i<=b;i++)

    {

        ans*=a;

    }

    return ans;

}



ll make(string p)

{

    ll sum=0,ck=1;

    for(ll i=p.size()-1;i>=0;i--)

    {

        sum+=(p[i]-'0')*ck;

        ck*=10;

    }

    return sum;

}

bool bo[105];

ll check(string a,string b)

{

    if(a.size()!= b.size())

        return 0;

    else

    {

        for(ll i=0;i<a.size();i++)

        {

            if(a[i]=='?')

                continue;

            else if(a[i]!=b[i])

                return 0;

        }

    }

    return 1;

}



int main()

{

   freopen("input.txt","r",stdin);

   freopen("output.txt","w",stdout);





   string s;

   cin>>s;

   ll n; cin>>n;

   if(s=="front") {

    if(n&1) cout<<"L";

    else cout<<"R";

   }

   else {

    if(!(n&1)) cout<<"L";

    else cout<<"R";

   }



}