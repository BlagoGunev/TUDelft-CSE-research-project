/*
 
@author
_      _          _                 _      _
\\    // /\    | | \  |     |    /\ \\    //     
 \\  // /__\   | |_/  |_____|   /__\ \\  //
  \\// /    \  | | \  |     |  /    \ \\//
   \/ /      \ | |_/  |     | /      \ \/
@ Indian Institute of Technology Bhilai
*/
 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long int ul;
#define fr(i,start,end, inc) for(ll i=(start); i<(end); i+=inc)
#define rf(i,start,end, dec) for(ll i=(end-1); i>=(start); i-=dec)
#define rep(i,n) for(ll i=0; i<n; i++)
#define rep1(i,n) for(ll i=1; i<=n; i++)
#define varr(k) vector<array<ll, k> > 
#define vec vector<ll> 
#define fato(v,i) for(auto &i : v)
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define mp make_pair
#define pl pair<ll, ll>
#define pi pair<int,int>
#define fi first
#define se second
#define pq priority_queue
#define all(v) v.begin(), v.end()
#define alla(arr,n) arr, arr+n
#define fsync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const ll maxx =  1e9+7;
 
 
bool mysort(const ll &b, const pl &a) { 
    return a.fi>b; 
}
bool sortbyboth(const pl &a, const pl &b){
    return a.fi<b.fi || (a.fi==b.fi && a.se<b.se);
}
ll inline power(ll a, ll b, ll p){
    a %= p;
    ll ans = 1;
    while(b>0){
        if(b & 1)
            ans = (ans*a)%p;
        a = (a*a)%p;
        b >>= 1;
    }
    return ans;
}
ll inv(ll n, ll p){
    return power(n,p-2, p);
}
inline vector<ll> allinv(ll n, ll p){
    vector<ll> arr(n);
    arr[1]=1;
    fr(i,2,n,1){
        arr[i] = (p - (p/i)*arr[p%i]%p)%p;
    }
    return arr;
}
vector<ll> inline allncr(ll n, ll p){
    vector<ll> nci(n+1);
    nci[0]=1;
    nci[n]=1;
    vector<ll> v = allinv(n,maxx);
    fr(i,1,n,1){
        nci[i]=(((nci[i-1]*(n+1-i))%maxx)*v[i])%maxx;
    }
    return nci;
}
ll max3(ll a, ll b, ll c){
    return max(max(a,b),c);
}
ll gcd(ll a, ll b){ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);      
}  
ll lcm(ll a, ll b) { 
    return (a*b)/gcd(a, b); 
}
bool inline isPrime(ll n) { 
    if (n <= 1)  return false; 
    if (n <= 3)  return true; 
    if (n%2 == 0 || n%3 == 0) return false; 
    for (ll i=5; i*i<=n; i=i+6) 
        if (n%i == 0 || n%(i+2) == 0) 
           return false; 
    return true; 
}
void prt(int i){   
    i ? cout << "Yes\n" : cout << "No\n" ;
}
ll getSum(ll n) {  
    ll sum = 0; 
    while (n != 0) { 
        sum = sum + n % 10; 
        n = n/10; 
    }  
 return sum; 
}
// struct node {
//     ll value;
//     node *left=NULL;
//     node *right=NULL;
// };
// ll ans=1;
// void inline addNode(ll value, struct node* first){
//     node *itr = first;
//     while(true){
//         if(value==itr->value)
//             break;
//         if(value < itr->value){
//             if(itr->left == NULL){
//                 node* x = new node();
//                 x->value = value;
//                 itr->left = x;
//                 ans++;
//                 break;
//             }
//             else{
//                 itr = itr->left;
//                 continue;
//             }
//         }
//         if(itr->right == NULL){
//             node* x = new node();
//             x->value = value;
//             itr->right = x;
//             ans++;
//             break;
//         }
//         else
//             itr = itr->right;
//     }
// }
// vector<ll> arr,v;
// void build(int start, int end, int node){
//     if(start==end)
//         seg[node]=arr[start];
//     else{
//         build(start, (start+end)/2, 2*node+1);
//         build((start+end)/2+1, end, 2*node+2);
//         seg[node]=seg[2*node+1]+seg[2*node+2];
//     }
// }
// void update(int x, int pos){
//     arr[pos]=x;

// // }
// vector<ll> v[maxx];
// vector<ll> hg(maxx,0);
// ll ans=0;

// vector<ll> arr(maxx);
// vector<bool> vis(maxx,{false});
// vector<pl> bound(maxx);
// vector<ll> ch(maxx);
// ll start=0;
// class SegTree{
// public:
//     SegTree(ll n){
//         n = n;
//         // v = vector<ll>(4*n,0);
//         lazy = new nd[4*n];
//     }
//     void update(ll time, ll val,ll ht, ll l, ll r, ll start, ll end, ll node){
//         if(start>=l && end<=r){
//             (lazy)[node].mp[time-ht]+=val;
//             ll idx=time-ht+500000;
//             while(idx<=1000000){
//                 (lazy)[node].tre[idx]+=val;
//                 idx+=(idx & -idx);
//             }
//             return;
//         }
//         if(r<=(start+end)/2)
//             update(time,val,ht,l,r,start,(start+end)/2,2*node+1);
//         else if(l>=(start+end)/2+1)
//             update(time,val,ht,l,r,(start+end)/2+1,end,2*node+2);
//         else{
//             update(time,val,ht,l,r,start,(start+end)/2,2*node+1);
//             update(time,val,ht,l,r,(start+end)/2+1,end,2*node+2);
//         }   
//     }
//     void query(ll time, bool leaf, ll ht,ll idx, ll start, ll end, ll node){
//         if(!leaf)
//             ans += (lazy)[node].mp[time-ht];
//         else{
//             ll id=time-ht+500000;
//             while(id>0){
//                 ans+=(lazy)[node].tre[id];
//                 id -= (id & -id);
//             }
//         }
//         if(start==end)
//             return;
//         if(idx>=start&&idx<=(start+end)/2)
//             query(time,leaf,ht,idx,start,(start+end)/2,2*node+1);
//         else
//             query(time,leaf,ht,idx,(start+end)/2+1,end,2*node+2);
//     }
// private:
//     ll n;
//     struct nd{
//         map<ll,ll> mp;
//         ll tre[2*maxx]={0};
//     };
//     nd *lazy;
// };
// void dfs(ll node){
//     vis[node]=1;
//     bound[node].fi=start;
//     ch[node]=start;
//     for(auto i:v[node]){
//         if(!vis[i]){
//             hg[i]=hg[node]+1;
//             start++;
//             dfs(i);
//         }
//     }
//     bound[node].se=start;
// }
int main(){
    fsync
    ll test=1;
    // cin >> test;
    while(test--){
        ll n;
        cin >> n;
        if(n==1)
            cout << 1 << "\n";
        else if(isPrime(n)){
            cout << n << "\n";
        }
        else{
            ll ans;
            for(ll i=2; i*i<=n; i++){
                if(n%i == 0){
                    ans = i;
                    break;
                }
            }
            ll ans1=ans;
            while(ans < n)
                ans *= ans1;
            if(n==ans)
                cout << ans1 << "\n";
            else
                cout << 1 << "\n";
        }
    }
}