#include<bits/stdc++.h>
#define ll long long
#define fu(i,a,b) for(ll i=a;i<=b;i++)
#define fd(i,a,b) for(ll i=a;i>=b;i--)
using namespace std;
ll q , x , y , z;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>q;
    while(q--)
    {
        ll kq = 0;
        cin>>x>>y>>z;
        ll k = min(x , min(y , z));
        x -= k;
        y -= k;
        z -= k;
        kq += k;
        if(x < y) swap(x,y);
        if(x >= y*2)
        {
            kq += y;
        }
        else{
            k = x-y;
            ll y1 = y - k;
            ll x1 = x - k*2;

            y = k;
            x = k*2;

            kq += (y1/3)*2;
            if(y1 % 3 == 2) kq++;

            kq += y;
        }
        cout<<kq<<"\n";
    }
}