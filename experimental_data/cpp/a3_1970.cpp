#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500102;

const int mod=1e9+7;
string ans;
vector<int>mp[N];
void dfs(int x){
    ans+='(';
    for(auto i:mp[x])dfs(i);
    ans+=')';
}
void solve(){
    string s;
    cin>>s;
    s=')'+s;
    int tot=0;
    queue<int>q;
    q.push(++tot);
    for(int i=0;i<s.size();i++){
        if(s[i]==')'){
            int j=i+1;
            int cnt=0;
            while(s[j]=='(')cnt++,j++;
            int x=q.front();
            q.pop();
            i=j-1;
            while(cnt--)mp[x].push_back(++tot),q.push(tot);
        }
    }
    for(int i=1;i<=tot;i++)std::reverse(mp[i].begin(), mp[i].end());
    dfs(1);
    for(int i=1;i+1<ans.size();i++)cout<<ans[i];
}

int main(){
    ios::sync_with_stdio(false);
    int T=1;
   // cin>>T;
    while(T--)solve();
}