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

    ll n;

    cin>>n;

    ll a[n];

    for(int i=0;i<n;i++)cin>>a[i];

    for(int i=1;i<n;i++)

    {

        if(a[i]!=a[i-1])

        {

            cout<<1<<endl;

            return;

        }

    }

    cout<<n<<endl;

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