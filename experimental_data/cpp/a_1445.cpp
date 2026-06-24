///       ______        __________                    _____   _____        _____

///      ///  \\\      ||__||   \\\    |||     |||  ||     || |||\\\      ///|||

///     ///    \\\     ||__||    \\\   |||_____|||  ||     || ||| \\\    /// |||

///    ///______\\\    ||__||     \\\  |||_____|||  ||     || |||  \\\  ///  |||

///   ///________\\\   ||__||     ///  |||_____|||  ||     || |||   \\\///   |||

///  ///          \\\  ||__||    ///   |||     |||  ||     || |||            |||

/// ///            \\\ ||__||___///    |||     |||  ||_____|| |||            |||



#include<bits/stdc++.h>

#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

typedef long long ll;

typedef long double ld;

void test_case()

{

    ll n,x;

    cin>>n>>x;

    ll a[n],b[n];

    for(int i=0;i<n;i++)cin>>a[i];

    for(int i=0;i<n;i++)cin>>b[i];

    sort(a,a+n);

    sort(b,b+n);

    for(int i=0;i<n;i++)

    {

        if(a[i]+b[n-i-1]>x)

        {

            cout<<"No"<<endl;

            return;

        }

    }

    cout<<"Yes"<<endl;

}

int main()

{

    FIO

    ll t;

    t=1;

    cin>>t;

    while(t--)

    {

        test_case();

    }

}