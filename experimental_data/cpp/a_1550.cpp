#include "bits/stdc++.h"
using namespace std;
#define forn(i,n) for(int i=0;i<n;i++)
#define in(n) int n; cin>>n;
#define dbg(x) cerr << #x << "->" << x << "\n"
#define ll long long
#define int long long
#define endl "\n"
const int N=2e5+5;
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
int solve(int s){
    int sum=0,i=1,cnt=0;
    if(s==1) return 1;
 
            while(sum<s){
                sum+=i;
                i+=2;
                cnt++;
            }            
        return cnt;
 
}
 
int32_t main(){
        FAST;
        in(t);
        int sum=0,i=1,cnt=0;
        while(t--){
            in(s);
            cout<<solve(s)<<endl;
 
        }
       
       
 
 
 
 
 
 
       return 0;
    }