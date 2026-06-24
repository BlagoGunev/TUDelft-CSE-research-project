#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin >> n;
    struct node
    {
        int l, r;
        bool operator<(node b)const{
            if(r-l==b.r-b.l) return l>b.l;
            return r-l<b.r-b.l;
        }
    };
    
    priority_queue<node> pq;
    vector<int> ans(n+1);
    pq.push({1,n});
    for(int i = 1; i <= n; i++){
        int l = pq.top().l;
        int r = pq.top().r;
        int m = (l+r)/2;
        pq.pop();
        ans[m] = i;
        if(l<m) pq.push({l,m-1});
        if(m<r) pq.push({m+1,r});
    }
    for(int i = 1; i <= n; i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while(tt--){
        solve();
    }
    return 0;
}