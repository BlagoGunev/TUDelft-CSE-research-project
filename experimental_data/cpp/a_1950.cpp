///       ______        __________                    _____   _____        _____
///      ///  \\\      ||__||   \\\    |||     |||  ||     || |||\\\      ///|||
///     ///    \\\     ||__||    \\\   |||_____|||  ||     || ||| \\\    /// |||
///    ///______\\\    ||__||     \\\  |||_____|||  ||     || |||  \\\  ///  |||
///   ///________\\\   ||__||     ///  |||_____|||  ||     || |||   \\\///   |||
///  ///          \\\  ||__||    ///   |||     |||  ||     || |||            |||
/// ///            \\\ ||__||___///    |||     |||  ||_____|| |||            |||

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl "\n"
using namespace std;
typedef unsigned long long ll;
typedef long double ld;
void test_case()
{
    ll a,b,c;
    cin>>a>>b>>c;
    if(a<b && b<c)cout<<"STAIR";
    else if(a<b && b>c)cout<<"PEAK";
    else cout<<"NONE";
    cout<<endl;
}
int main()
{
    FIO
//  freopen("input.txt","rt",stdin);
//  freopen("output.txt","wt",stdout);
    int t;
    t=1;
    cin>>t;
    while(t--)
    {
        test_case();
    }
}