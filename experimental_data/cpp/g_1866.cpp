#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define pi pair<int,int>
#define vi vector<int>
#define vpi vector<pi>
#define vvi vector<vi>
#define ff first
#define ss second
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
using namespace std ;
int mod=998244353;
//int mod = 1e9 +7;
long long inf= 1e14;

int mul(int x,int y){
x%=mod;
y%=mod;

return (x*y)%mod;
}

int power(int x,int n){
if(n==0) return 1;
if(n==1) return x%mod;
if(n%2==0) return power(mul(x,x),n/2);
return mul(x,power(mul(x,x),n/2));
}

class LCA{

int n, l;
vector<vector<pi>> adj;
int timer;
vector<int> tin, tout;
vector<vector<int>> up;

LCA(int a,vector<vector<pi>> g){
a=n;
adj=g;
tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    dfs(0,-1);
}

void dfs(int v, int p)
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (auto u : adj[v]) {
        if (u.ff != p)
            dfs(u.ff, v);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}
};
class DSU {
private:
    vi rnk;
vi par;
    public:
DSU(int n){
rnk=vi(n,1);
par=vi(n);
for(int i=0;i<n;i++) par[i]=i;
}

int find_par(int a){
if(a==par[a]) return a;
return par[a]=find_par(par[a]);
}
void make_union(int a,int b){
 a=find_par(a);
 b=find_par(b);
 if(a==b) return ;
 if(rnk[b]>rnk[a]) swap(a,b);
 rnk[a]+=rnk[b];
 par[b]=a;
}

};



bool pos(int mid,vi a,vi d,int n){
set<pi> extra;
set<pi>req;
for(int i=0;i<n;i++){
    auto it = req.lower_bound({max((int)0,i-d[i]),0});

    while(it!=req.end()){
        if((*it).ss > a[i]){
            pi p=*it;
            req.erase(it);
            p.ss-=a[i];
            a[i]=0;
            req.insert(p);
        }
        else {
           pi p=*it;
            req.erase(it);
            a[i]-=p.ss;
        }

        if(a[i]==0) break;

        it=req.lower_bound({max((int)0,i-d[i]),0});
    }

    int comes_from=0;

   if(!extra.empty() && (*extra.begin()).ff <i) return false;
    while(!extra.empty() && comes_from<mid && (*extra.begin()).ff <=min(i+d[i],n-1)){
        if((*extra.begin() ).ss +comes_from <=mid){

           comes_from+=(*extra.begin()).ss;
           extra.erase(extra.begin());
           }
        else {
            int left= (*extra.begin()).ss - (mid -comes_from);
            int idx=(*extra.begin()).ff;
            extra.erase(extra.begin());
            extra.insert({idx,left});
            comes_from=mid;
            break;
        }
    }

    if(a[i]+comes_from <=mid){
        int left=mid-a[i] -comes_from;
        while(!extra.empty() &&left!=0 && (*extra.begin()).ff>=i){
            if((*extra.begin()).ss >=left){
                left=(*extra.begin()).ss - left;
                int idx = (*extra.begin()).ff;
                extra.erase(extra.begin());
                extra.insert({idx,left});
                left=0;
            }
            else {
                left-=(*extra.begin()).ss;
                extra.erase(extra.begin());
            }
        }
       if(left!=0) req.insert({i,left});
    }
    else {
            int mid2=mid-comes_from;
        int mov=a[i]-mid2;

        if(d[i]==0 && mov !=0) return false;
        auto it=extra.lower_bound({min(i+d[i],n-1),0});
        if(it!=extra.end() && (*it).ff ==min(i+d[i],n-1) ){
             mov+=(*it).ss;
             extra.erase(it);
            extra.insert({min(i+d[i],n-1),mov});
        }
        else extra.insert({min(i+d[i],n-1),mov});
    }
}


return extra.empty();

}



void solve(){
 int n;
 cin>>n;
 vi a(n);
 for(auto &i:a) cin>>i;
 vi d(n);
 for(auto &i:d) cin>>i;

 int l=1;
 int r=*max_element(a.begin(),a.end());

 if(r==0){
    cout<<0<<"\n";
    return ;
 }
 int ans=r;
// cout<<pos(4,a,d,n)<<"\n";
// for(int i=4;i<=9;i++) cout<<pos(i,a,d,n)<<"\n";
 while(l<=r){
    int mid=(l+r)/2;
    if(pos(mid,a,d,n)){
        ans=mid;
        r=mid-1;
    }
    else l=mid+1;
 }

 cout<<ans<<"\n";
  return ;
}

int32_t main() {
   ios_base::sync_with_stdio(false); cin.tie(0);
   cout.tie(0);
   int t=1;
//   cin>>t;
   while(t--){
  solve();
   }


    return 0;
}