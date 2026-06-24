#include <bits/stdc++.h>
using namespace std;

// 💖 Hi, thanks for using ICIE! 💖
// 🔧 To use a custom code template, set it in Settings(Ctrl+,) in "Icie Template List" entry 🔧
// 📝 If you spot any bugs or miss any features, create an issue at https://github.com/pustaczek/icie/issues 📝

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;

    while(t--){
        long a,b,k;
        cin>>a>>b>>k;
        if(k==1){
            cout<<"REBEL"<<endl;
            continue;
        }
        long c,d;

        c = min(a,b);
        d = max(a,b);

        long gc = gcd(a,b);

        long planks = (d+(c-1-gc))/c;
        if(planks >= k){
            cout<<"REBEL"<<endl;
        }
        else{
            cout<<"OBEY"<<endl;
        }
    }
}