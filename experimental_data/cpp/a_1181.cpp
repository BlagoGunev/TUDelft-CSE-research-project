#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int main()
{
    ll x, y, z;
    while(cin >> x >> y >> z){
    cout << (x + y) / z << ' ';
    if(x%z+y%z<z)
        cout << '0' << endl;
    else cout << min(z-x%z, z-y%z) << endl;
    }
    return 0;
}