#include<bits/stdc++.h>
using namespace std;
#define int long long 

int n,k,m;
vector<pair<int,int> >st;

void update(int idx,int l,int r,int c,int p){
    if(l==r){
        st[idx].first+=c;
        st[idx].second+=c*p;
        return;
    }
    int mid=(l+r)/2;
    if(mid>=p)update(2*idx,l,mid,c,p);
    else update(2*idx+1,mid+1,r,c,p);
    st[idx].first=st[2*idx].first+st[2*idx+1].first;
    st[idx].second=st[2*idx].second+st[2*idx+1].second;
}

int query(int idx,int l,int r,int bny){
    if(l==r){
        return l*min(st[idx].first,bny);
    }
    int mid=(l+r)/2;
    if(st[2*idx].first>=bny)return query(2*idx,l,mid,bny);
    else return st[2*idx].second+query(2*idx+1,mid+1,r,bny-st[2*idx].first);
}

signed main(){
    cin>>n>>k>>m;
    vector<pair<int,int> >idx[n+2];
    for(int q=1;q<=m;q++){
        int l,r,c,p;
        cin>>l>>r>>c>>p;
        idx[l].push_back({c,p});
        idx[r+1].push_back({-c,p});
    }
    st=vector<pair<int,int> >(4*1000000+1,{0,0});
    int ans=0;
    for(int q=1;q<=n;q++){
        for(auto r : idx[q]){
            update(1,1,1000000,r.first,r.second);
        }
        ans+=query(1,1,1000000,k);
       // cout<<ans<<endl;
    }
    cout<<ans<<endl;
}