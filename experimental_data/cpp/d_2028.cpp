#include <bits/stdc++.h>
using namespace std;
int seg[800001][3];
int arr[200001][3];
int rev[200001][3];

void build(int p,int l,int r){
    if(l==r){
        if(l==1){
            seg[p][0] = seg[p][1] = seg[p][2] = 1e9;
        }else{
            seg[p][0] = arr[l][0];
            seg[p][1] = arr[l][1];
            seg[p][2] = arr[l][2];
        }
        return ;
    }
    int md = (l+r)/2;
    build(p*2,l,md);
    build(p*2+1,md+1,r);
    seg[p][0] = min(seg[p*2][0],seg[p*2+1][0]);
    seg[p][1] = min(seg[p*2][1],seg[p*2+1][1]);
    seg[p][2] = min(seg[p*2][2],seg[p*2+1][2]);
}
int query(int p,int l,int r,int lq,int rq,int ty){
    if(l>=lq&&r<=rq)return seg[p][ty];
    if(r<lq||l>rq)return 1e9;
    int md = (l+r)/2;
    return min(query(p*2,l,md,lq,rq,ty),query(p*2+1,md+1,r,lq,rq,ty));
}
void update(int p,int l,int r,int idx){
    if(l==r){
        seg[p][0] = seg[p][1] = seg[p][2] = 1e9;
        return ;
    }
    int md = (l+r)/2;
    if(idx<=md)update(p*2,l,md,idx);
    else update(p*2+1,md+1,r,idx);
    seg[p][0] = min(seg[p*2][0],seg[p*2+1][0]);
    seg[p][1] = min(seg[p*2][1],seg[p*2+1][1]);
    seg[p][2] = min(seg[p*2][2],seg[p*2+1][2]);
}
vector<pair<int,int>> v;
int n;bool done = 0;
void dfs(int i){
    update(1,1,n,i);
    if(i==n&&done==0){
        done = 1;
        cout<<"YES"<<endl;
        cout<<v.size()<<endl;
        for(auto j:v){
            if(j.first==0)cout<<"q ";
            if(j.first==1)cout<<"k ";
            if(j.first==2)cout<<"j ";
            cout<<j.second<<endl;
        }
    }
    while(query(1,1,n,i+1,n,0)<=arr[i][0]){
        int x = rev[query(1,1,n,i+1,n,0)][0];
        v.push_back({0,x});
        dfs(x);
        v.pop_back();
    }
    while(query(1,1,n,i+1,n,1)<=arr[i][1]){
        int x = rev[query(1,1,n,i+1,n,1)][1];
        v.push_back({1,x});
        dfs(x);
        v.pop_back();
    }
    while(query(1,1,n,i+1,n,2)<=arr[i][2]){
        int x = rev[query(1,1,n,i+1,n,2)][2];
        v.push_back({2,x});
        dfs(x);
        v.pop_back();
    }
}
signed main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int j = 0;j<3;j++){
        for(int i = 1;i<=n;i++){
            cin>>arr[i][j];
            rev[arr[i][j]][j] = i;
        }
        }
        done = 0;
        v.clear();
        build(1,1,n);
        dfs(1);
        if(!done)cout<<"NO"<<endl;
    }
}