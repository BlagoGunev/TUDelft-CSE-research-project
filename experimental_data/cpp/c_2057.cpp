#include<bits/stdc++.h>
using namespace std;
#define int long long
int T, l, r;
signed main(){
    cin >> T;
    while(T--){
        cin >> l >> r;
        int a = 0, b = 0, c = 0;
        for(int i = 30; i >= 0; i--){
            if((l>>i&1) == (r>>i&1)){
                if(l>>i&1^1)continue;
                a += (1<<i);
                b += (1<<i);
                c += (1<<i);
            }else{
                a += (1<<i)-2;
                b += (1<<i)-1;
                c += (1<<i);
                if(a < l){
                a -= (1<<i)-2;
                b -= (1<<i)-1;
                c -= (1<<i);
                    a += (1<<i)-1;
                    b += (1<<i);
                    c += (1<<i)+1;
                }
                break;
            }
        }
        cout << a << " " << b << " " << c << '\n';
    }
    return 0;
}