#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define pb push_back
#define all(v) v.begin(),v.end() 
const int N =1e6+10;    
const double eps = 1e-7;  
typedef pair<int,int> PII;
int n,m,k;
int a[N];int b[N];
string s;
void solve(){   
    cin>>n;
    if(n<=4){
        cout<<"Bob"<<endl;
    }
    else{
        cout<<"Alice\n";
    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--)solve();
}