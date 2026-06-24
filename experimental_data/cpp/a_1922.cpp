#include <bits/stdc++.h>
using namespace std;

typedef  long long ll;
#define F first ;
#define S  second;
#define endl '\n' ;

void Fast(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cout.tie(0);
    cout.sync_with_stdio(0);
}

void solve(){
    /* تعزُّ عليَّ فِلسطين، تعزُّ عليَّ أحزانُها  بسم الله على فِلسطين حتى يطمَئن فؤادُها */
    int n;
    cin>>n;
    string a, b, c;
    cin>>a>>b>>c;
    for (int i=0;i<n;i++){
        if (a[i] != c[i] && b[i] != c[i]){
            cout<<"YES";
            return;
        }
    }
    cout<<"NO";
}
int main (){
    Fast();
    int t=1;
    cin>>t;
    while(t--){
       solve();
       if(t!=0) cout<<endl;
    }
}