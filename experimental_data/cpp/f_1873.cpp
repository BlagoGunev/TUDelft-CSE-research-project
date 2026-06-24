/*
Konnitchiwa
*/

//The points P(x1, y1) and Q(x2, y2) will lie on the same side of the line ax + by + c = 0
    //if ax1+ by1 + c and ax2 + by2 + c have the same signs.
//The points P(x1, y1) and Q(x2, y2) will lie on the opposite sides of the line ax + by + c = 0
    //if ax1 +  by1 + c and ax2 + by2 + c have opposite signs.



#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;

#define endl "\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr);cout.tie(nullptr);
typedef priority_queue<int> PQI;


#define pl pair<ll,ll>
#define vi vector<int>
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vvi vector<vector<int>>
#define vpi vector<pair<int,int>>
#define vpl vector<pair<ll,ll>>
#define ll long long int
#define db double
#define ld long double
#define fl float
#define pb push_back
#define F first
#define S second
#define yes cout << "YES" << endl;
#define no cout<<"NO"<<endl;
#define affichi(v,n) for(int i=0;i<n;i++)cout<<v[i]<<'-';
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define MP(x,y) make_pair(x,y)

            #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
const double Pii = 3.14159265358979323846;
const ll mod=                    1e9+7;
const ll mod2=                    998244353;
const ll inf=                    1e16+7;
const int mxN=1000100;
const double eps=0.00000000000000001;





ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll i,ll mod) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i,mod)) % mod) % mod;}





//ll seg[mxN*4],lazy[mxN*4];
//ll a[mxN];
//vector<ll>vct;








//int nextS[mxN];
//int arr[mxN];
//int n;
//
//void findNextSmallerElement() {
//  // declaring a stack
//    stack<int> st;
//  // iterating through array
//    for (int i = 0; i <= n; ++i) {
//      // checking for next smaller element
//        while (!st.empty() && arr[i] < arr[st.top()]) {
//          // pushing the index of the next smaller element
//            nextS[st.top()] = i;
//            st.pop();
//        }
//        // pushing elements of array in stack
//        st.push(i);
//    }
//}



//
//void build(int level,int s,int e){
//    if(s==e){
//        seg[level]=arr[s];
//        return;
//    }
//    build(level*2,s,(s+e)/2);
//    build(level*2 + 1,(s+e)/2 + 1,e);
//    seg[level]=max(seg[level*2],seg[level*2+1]);
//}

//void unlazy(int level,int s,int e){
//        ll v=lazy[level];
//        if(v==0)return;
//        lazy[level]=0;
//        if(s!=e){
//            lazy[level*2]=v;
//            lazy[level*2 + 1]=v;
//        }
//        seg[level]=(e-s+1)*v;
//}

//void update(int l,int r,int level,int s,int e,ll v){
////    unlazy(level,s,e);
//    if(l>e || r <s )return;
//    if(s>=l && e<=r){
//        seg[level]=(e-s+1)*v;
//        if(s!=e){
//            lazy[level*2]=v;
//            lazy[level*2+1]=v;
//        }
//        return;
//    }
//    update(l,r,level*2,s,(s+e)/2,v);
//    update(l,r,level*2+1,(s+e)/2 + 1,e,v);
//    seg[level]=seg[level*2]+seg[level*2 + 1];
//}


//ll get(int l,int r,int level,int s,int e){
//    if(l>e || r<s)return -1e9;
////    unlazy(level,s,e);
//    if(s>=l && e<=r)return seg[level];
//    return max(get(l,r,level*2,s,(s+e)/2) ,get(l,r,level*2+1,(s+e)/2 +1 ,e));
//}

//int parent[300005];
//int sz[300005];
//
//
//struct DSU{
//
//    void init(int n){
//        for (int i = 1; i < n; i++){
//            parent[i] = i;
//            sz[i] = 1;
//        }
//    }
//
//    int get_rep(int a){
//        return (parent[a] == a ? a : parent[a] = get_rep(parent[a]));
//    }
//
//    void unite(int a, int b){
//        a = get_rep(a);
//        b = get_rep(b);
//        parent[b] = a;
//        sz[a] += sz[b];
//    }
//
//    bool same_set(int a, int b){
//        return get_rep(a) == get_rep(b);
//    }
//
//    ll size(int a){
//        return sz[get_rep(a)];
//    }
//};
//
//
//
//
//
//
//
//

int nextS[200005];
int arr[200005];


void findNextSmallerElement(int n) {
  // declaring a stack
    stack<int> st;
  // iterating through array
    for (int i = 1; i < n; ++i) {
      // checking for next smaller element
        while (!st.empty() && arr[i] < arr[st.top()]) {
          // pushing the index of the next smaller element
            nextS[st.top()] = i;
            st.pop();
        }
        // pushing elements of array in stack
        st.push(i);
    }
}



void solve(){
    ll n,k;
    cin>>n>>k;
    vector<ll>a(n),h(n);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>h[i];
    arr[0]=0;
    for(int i=1;i<n;i++){
        nextS[i]=-1;
        if(h[i-1]%h[i])arr[i]=0;
        else arr[i]=1;
    }
    arr[n]=-1;

    findNextSmallerElement(n+1);
    int ans=0;
    for(int i=0;i<n;i++)if(a[i]<=k){ans=1;break;}

    vector<ll> pref(n);
    pref[0]=a[0];
    for(int i=1;i<n;i++)pref[i]=pref[i-1]+a[i];

    for(int i=0;i+1<n;i++){
        int ind=i+1;
        if(h[i]%h[i+1] ==0)ind=nextS[i+1];
        int ub=upper_bound(all(pref),(i!=0)*pref[i-1]+k)-pref.begin();

        ub=min(ub,ind);
        ans=max(ans,ub-i);
    }
    cout<<ans<<endl;

}



int main(){
    fast
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
//    cout<<fixed<<setprecision(12);
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}



/*
Keeeeeeeeeep goiiiiiing gonnaaaa do it now or after it's just a matter of time inchallah
*/