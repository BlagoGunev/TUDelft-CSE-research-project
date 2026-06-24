#include <iostream>
#include <algorithm>
#include <limits>
#define ll long long
using namespace std;

int main(){
    int t;
    cin >> t;
    
    while(t--){
        ll n;
        cin >> n;
        
        ll as=0, bs=0;
        ll mina=1e9, minb=1e9;
        ll x, y;
        
        for(int i=0; i<n; i++){
            cin >> x;
            as += x;
            mina = min(mina, x);
        }
        for(int i=0; i<n; i++){
            cin >> y;
            bs += y;
            minb = min(minb, y);
        }
        
        cout << min(mina*n+bs, minb*n+as) << endl;
    }
}