#include <bits/stdc++.h>


using namespace std;
typedef long long ll;
#define endl "\n"
#define int long long
#define log(x) (31^__builtin_clz(x))
const ll MOD = 998244353;
#define goeee ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
#define log(x) (31^__builtin_clz(x)) // Easily calculate log2 on GNU G++ compilers



void solve(){

    int n;
    cin>>n;
    vector<int> a(n);
    map<int,int> cnt;
    int sum =0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        cnt[(a[i]%3)]++;
        sum+=a[i];
    }

    if(sum%3==0){
        cout<<0<<endl;
        return;
    }
    if(sum%3==2){
        cout<<1<<endl;
        return;
    }
    if(sum%3==1){
        if(cnt[1]){
            cout<<1<<endl;
        }else{
            cout<<2<<endl;
        }
        return;
    }



}



int32_t main() {
    goeee;
    //freopen("sum_41_chapter_1_input.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    ll t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}