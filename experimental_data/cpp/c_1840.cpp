#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,a,b) for(long long i=a;i<b;i++)

#define vpiin vector<pair<int,int>>v(n);
#define vf(i) v[i].first
#define vs(i) v[i].second
#define vvi vector<vector<int>>v;

 string removeDuplicates(string s, int n)
{
    unordered_map<char, int> exists;
 
    string ans = "";
    for (int i = 0; i < n; i++) {
        if (exists.find(s[i]) == exists.end()) {
            ans.push_back(s[i]);
            exists[s[i]]++;
        }
    }
    return ans;
}
int main(){
        ll t;
        cin>>t;
        while(t--){
        ll n,k,q;
        cin>>n>>k>>q;
        ll a[n];
        rep(i,0,n){
            cin>>a[i];
        }ll p=0,j=0;
        ll ans=0;
        while(j<n){
            if(a[j]>q){
                if((j-p)>=k){
                    ans+=((j-p-k+1)*(j-p-k+2))/2;
                    //cout<<j-p+1<<" ";
                }
                j++;
                 p=j;
            }else{
                j++;
            }
        }if((j-p)>=k){
                    ans+=((j-p-k+1)*(j-p-k+2))/2;}
        cout<<ans<<endl;
        
        }
    return 0;}