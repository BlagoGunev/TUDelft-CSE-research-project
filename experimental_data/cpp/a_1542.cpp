#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define ll long long
#define ull long long
const int N = 3001 ;
void FAST()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
}
/*ll fact (ll x){
    if (x==0 || x==1)
        return 1 ;
    else
        return x*fact(x-1);
}
ll gcd(ll a , ll b){
   if(b==0)
    return a;
   return gcd(b,a%b);
}
ll lcm (ll a , ll b){
   return a/gcd(a,b)*b ;
}*/
int main()
{
    FAST();
    int t , n ;
    cin >> t ;
    while(t--){
        int x , ce=0, co=0;
        cin >> n ;
        for(int i=0 ; i<2*n ; i++){
            cin >> x ;
           if(x%2==0)
            ce++;
           else
            co++;
        }
        if(co==n && ce==n)
            cout << "Yes" << el ;
        else
            cout << "No" << el ;
    }

    return 0;
}