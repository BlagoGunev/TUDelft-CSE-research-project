#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n,k;
    cin >> n >>k;
    ll ans = 1000000000,yi;
    
    int y = 1;
    while(y < k){
        if(n%y == 0){
            yi = n/y;
            ans = min(ans, yi*k + y);
        }
        y++;
    }
    cout << ans << endl;
    //system("pause");
}