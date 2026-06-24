#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

#define all(v) (v).begin(),(v).end()
#define mp make_pair
#define fs first
#define ss second

typedef pair<int,int> pi;
typedef pair<long long, long long> pll;
typedef long long ll;

const int INF=1e9;
const ll LINF=1e18;

void init()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    if(abs(n-m)>k || max(n,m)<k){
        cout<<-1<<endl;
        return;
    }
    if(n>m){
        for(int i=0;i<k;i++){
            cout<<0;
            n--;
        }
        while(n!=0 || m!=0){
            if(m>0){
                cout<<1;
                m--;
            }
            if(n>0){
                cout<<0;
                n--;
            }
        }
    }
    else{
        for(int i=0;i<k;i++){
            cout<<1;
            m--;
        }
        while(n!=0 || m!=0){
            if(n>0){
                cout<<0;
                n--;
            }
            if(m>0){
                cout<<1;
                m--;
            }
        }
    }
    cout<<endl;
}

int main()
{
    init();
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}