#include <iostream>

using namespace std;

long long int a;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>a;
    ++a;
    if(a==1) cout<<0;
    else{
        a%2 == 0 ? a/=2 : a;
        cout<<a;
    }
    return 0;
}