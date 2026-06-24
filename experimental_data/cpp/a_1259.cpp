#include<bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define int long long
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
#define SYS_IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pair<int,int>,int> piii;
const ll INF = 1e9;
const ll MAXN = 2*1e6;
main(){
    SYS_IOS;
    int q,ans=0;
    string s;
    cin >> q;
    while(q--){
        cin >> s;
        int cnt=0;
        FOR(i,1,s.size()-1){
        if(s[i] > s[0])
            break;
        if(s[i] < s[0])
            cnt=1;
        }
        cout << (s.size()-1)*9+(s[0]-'0'-cnt) << "\n";
    }
}