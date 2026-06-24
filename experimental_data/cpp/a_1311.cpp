#include<bits/stdc++.h>
using namespace std;

#define FastRead        ios_base::sync_with_stdio(0);cin.tie(0);
#define endl            "\n"
#define NUM             100005

typedef long long ll;

int main()
{

    FastRead

    ll t;

    cin>>t;

    while(t--)
    {
        ll a,b;

        cin>>a>>b;

        if(a==b)
            cout<<0<<endl;
        else if(a<b)
        {
            ll dif = b-a;
            if(dif%2)
                cout<<1<<endl;
            else
                cout<<2<<endl;
        }
        else
        {
            ll dif = a-b;
            if(dif%2)
                cout<<2<<endl;
            else
                cout<<1<<endl;
        }
    }
}