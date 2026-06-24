#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=2e5+9;
const int mod=1e9+7;
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(int i=0;i<n;i++){
        s[i]=tolower(s[i]);
    }
    // sort(s.begin(),s.end());
    s.erase(unique(s.begin(),s.end()),s.end());
    // cout<<s<<'\n';
    cout<<(s=="meow"?"YES":"NO")<<'\n';
}
int main(){
    int q;
    cin>>q;
    while(q--){
        solve();
    }
    return 0;
}