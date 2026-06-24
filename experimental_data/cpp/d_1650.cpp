#include <bits/stdc++.h>  
using namespace std;

#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")

typedef long long ll;

#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,a,b) for(ll i=a;i>=b;i--)
#define trav(it,a) for(auto it=a.begin();it!=a.end();++it)
#define read(n) ll n; cin>>n
#define readarray(arr,n) ll arr[n]; rep(i,0,n){cin>>arr[i];}
#define readvector(arr,n) vector<ll> arr; arr.clear(); rep(i,0,n){read(temp); arr.push_back(temp);}
#define readmatrix(arr,m,n) ll** arr=new ll*[m];rep(i,0,m){arr[i]=new ll[n];} rep(i,0,m){rep(j,0,n) cin>>arr[i][j];}
#define printarray(arr,n) rep(i,0,n) {cout<<arr[i]<<" ";} cout<<endl;
#define printmatrix(arr,m,n) rep(i,0,m){rep(j,0,n) {cout<<arr[i][j]<<" ";} cout<<endl;}
#define maxi(v) *max_element(v.begin(),v.end())
#define mini(v) *min_element(v.begin(),v.end())
#define rev(v) reverse(v.begin(),v.end())
#define uniq(v) unique(v.begin(),v.end()) //removes duplicacy of all elements by replacing
#define mini3(a,b,c) min(min(a,b),c)
#define maxi3(a,b,c) max(max(a,b),c)
#define endl "\n"		//COMMENT OUT FOR INTERACTIVE Q coz FLUSH NHI HOGA
#define countSetBits(i) __builtin_popcount(i)
#define precision(x,y) std::fixed<<std::setprecision(y)<<x

const long long inf=LLONG_MAX;
const double pi=3.14159265358979323846264338327950288419716939937510;
const ll mod=1e9 + 7;
const ll mod2=998244353; //FOR EDUCATIONAL ROUNDS AND CODECHEF AND ATCODER TOO
const double eps=(0.00000000001);

// DEBUG FUNCTIONS 

/*

#ifndef ONLINE_JUDGE
 
template<typename T>
void __p(T a) {
    cout<<a;
}

template<typename T, typename F>
void __p(pair<T, F> a) {
    cout<<"{";
    __p(a.first);
    cout<<",";
    __p(a.second);
    cout<<"}";
}

template<typename T>
void __p(std::vector<T> a) {
    cout<<"{";
    for(auto it=a.begin(); it<a.end(); it++)
        __p(*it),cout<<",}"[it+1==a.end()];
}

template<typename T>
void __p(std::set<T> a) {
    cout<<"{";
    for(auto it=a.begin(); it!=a.end();){
        __p(*it); 
        cout<<",}"[++it==a.end()];
    }
 
}

template<typename T>
void __p(std::multiset<T> a) {
	cout<<"{";
	for(auto it=a.begin(); it!=a.end();){
		__p(*it); 
		cout<<",}"[++it==a.end()];
	}
}

template<typename T, typename F>
void __p(std::map<T,F> a) {
    cout<<"{\n";
    for(auto it=a.begin(); it!=a.end();++it)
    {
        __p(it->first);
        cout << ": ";
        __p(it->second);
        cout<<"\n";
    }
    cout << "}\n";
}

template<typename T, typename ...Arg>
void __p(T a1, Arg ...a) {
    __p(a1);
    __p(a...);
}

template<typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
    cout<<name<<" : ";
    __p(arg1);
    cout<<endl;
}

template<typename Arg1, typename ... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args) {
    int bracket=0,i=0;
    for(;; i++)
        if(names[i]==','&&bracket==0)
            break;
        else if(names[i]=='(')
            bracket++;
        else if(names[i]==')')
            bracket--;
    const char *comma=names+i;
    cout.write(names,comma-names)<<" : ";
    __p(arg1);
    cout<<" | ";
    __f(comma+1,args...);
}

#define trace(...) cout<<"Line:"<<__LINE__<<" ", __f(#__VA_ARGS__, __VA_ARGS__)
#else
#define trace(...)
#define error(...)
#endif

*/

// DEBUG FUNCTIONS END

/*

double ternary_search_min(double l,double r){

    while(r-l>eps){
        double m1=l+(r-l)/3;
        double m2=r-(r-l)/3;

        double f1=f(m1);
        double f2=f(m2);

        if(f1<=f2) r=m2;
        else l=m1;
    }

    return f(l);

}

double ternary_search_max(double l,double r){

    while(r-l>eps){
        double m1=l+(r-l)/3;
        double m2=r-(r-l)/3;

        double f1=f(m1);
        double f2=f(m2);

        if(f1<=f2) l=m1;
        else r=m2;
    }

    return f(l);

}

*/

ll gcd(ll a,ll b){
    if(b==0) return a;

    a%=b;
    return gcd(b,a);
}

ll modInverse(ll a,ll m){
    //exists only if a and m are co-prime

    if(gcd(a,m)!=1) return LLONG_MIN;

    ll m0=m;
    ll y=0;
    ll x=1;

    if(m==1) return 0;

    while(a>1){
        ll q=a/m;
        ll t=m;
        m=a%m;
        a=t;
        t=y;

        y=x-q*y;
        x=t;
    }

    if(x<0) x+=m0;

    return x;
}

ll nCr(ll n, ll r){
    if(r>n) return 0;
    if(r>n-r) r=n-r;

    ll ans=1;

    rep(i,1,r+1){
        ans*=(n-i+1);   
    }

    rep(i,1,r+1) ans/=i;

    return ans;
}

ll lcm(ll a,ll b){
    return (a/gcd(a,b))*b;
}

ll binpowM(ll a,ll b) {

    if(b==0) return 1;
    if(b==1) return a%mod;

    ll res=binpowM(a,b/2)%mod;

    if (b%2==1) return (((res*res)%mod)*a)%mod;
    else return (res*res)%mod;
}

/* CSES EXPONENTIATION 2

a^p==a modp;

ll temp=binpowM(b,c,1e9 + 6);
cout<<binpowM(a,temp,1e9 + 7)<<endl;

*/

ll binpow(ll a,ll b) {

    if(b==0) return 1;
    if(b==1) return a;

    ll res=binpow(a,b/2);

    if (b%2==1) return (((res*res))*a);
    else return (res*res);
}

vector<bool> sieve(ll n){
    vector<bool> isPrime(n+1,true);

    isPrime[0]=false;
    isPrime[1]=false;

    rep(i,2,1+(ll)(sqrt(n))){
        if(isPrime[i]){
            rep(j,i*i,1+n){
                isPrime[j]=false;

                j--;
                j+=i;
            }
        }
    }

    return isPrime;
}

ll phi(ll n){
    ll ans=n;

    for(ll i=2;i*i<=n;i++){
        if(n%i==0){
            while(n%i==0) n/=i;
            ans-=ans/i;
        }
    }

    if(n>1) ans-=ans/n;

    return ans;
}

vector<ll> phi_1_to_n(ll n){
    vector<ll> phi(n+1);

    phi[0]=0;
    phi[1]=1;

    rep(i,2,n+1) phi[i]=i;

    rep(i,2,n+1){
        if(phi[i]==i){
            for(ll j=i;j<=n;j+=i) phi[j]-=phi[j]/i;
        }
    }

    return phi;
}

ll binary_search(ll arr[],ll n,ll elem) {

    ll l=0,r=n-1;

    while (r>=l){

        ll mid=(l+r)/2;

        if(arr[mid]>elem) r=mid-1;
        else if(arr[mid]<elem) l=mid+1;
        else return mid;

    }

    return -1;
}

ll binary_search_vector(vector<ll> &arr,ll elem) {

    ll n=arr.size();
    ll l=0,r=n-1;

    while (r>=l){

        ll mid=(l+r)/2;

        if(arr[mid]>elem) r=mid-1;
        else if(arr[mid]<elem) l=mid+1;
        else return mid;

    }

    return -1;
}

/* nCrM initial code, main mein likh diyo

ll t1=binpow(10,6);

ll fact[1+t1];
fact[0]=1;

rep(i,1,1+t1) fact[i]=(fact[i-1]*i)%mod;

*/

bool checkPrime(ll n){
    ll count=0;

    rep(i,2,1+(ll)sqrt(n)) if(n%i==0) count++;

    if(count>0) return false;
    else return true;
}

ll fibonacciHelper(ll n,map<ll,ll>& m){
    if(m.count(n)) return m[n];

    ll k=n/2;

    if(n%2==0) return m[n]=(fibonacciHelper(k,m)*fibonacciHelper(k,m) + fibonacciHelper(k-1,m)*fibonacciHelper(k-1,m))%mod;
    else return m[n]=(fibonacciHelper(k,m)*fibonacciHelper(k+1,m) + fibonacciHelper(k-1,m)*fibonacciHelper(k,m))%mod;
}

ll fibonacci(ll n){
    // A number is a fibonacci no if atleast one of (5*n*n +4) , (5*n*n -4) is a perfect square
    map<ll,ll> m;
    m[0]=1;
    m[1]=1;

    if(n==0) return 0;
    else return fibonacciHelper(n-1,m);
}

/*

ll nCrM(ll n,ll r){
    if(r>n) return 0;

    return ((fact[n]%mod)*(modInverse(((fact[r]%mod)*(fact[n-r]%mod))%mod,mod)%mod))%mod;
}

*/

ll factorial(ll n){
    ll res=1;
    rep(i,2,n+1) res*=i;

    return res;
}

ll factorialM(ll n){
    ll res=1;
    rep(i,2,n+1) res=(res*i)%mod;

    return res%mod;
}

void bfs(vector<ll> adj[],ll curr,vector<bool>& visited){
    queue<ll> q;
    q.push(curr);

    while(!q.empty()){
        ll temp=q.front();
        q.pop();

        visited[temp]=true;

        rep(i,0,adj[temp].size()){
            if(!visited[adj[temp][i]]){
                q.push(adj[temp][i]);
                visited[adj[temp][i]]=true;
            }
        }

    }

    return;
}

void dfs(vector<ll> adj[],ll curr,vector<bool>& visited){
    if(visited[curr]) return;
 
    visited[curr]=true;

    // path.push_back(curr);
 
    rep(i,0,adj[curr].size()){
        dfs(adj,adj[curr][i],visited);
    }
 
    return;
}

void dfs1(vector<ll> adj[],ll curr,vector<ll> &state,vector<ll> &ans){
    if(state[curr]==2) return;

    state[curr]=1;

    rep(i,0,adj[curr].size()){
        dfs1(adj,adj[curr][i],state,ans);
    }

    state[curr]=2;
    ans.push_back(curr);

    return;
}

vector<ll> topologicalSort(vector<ll> adj[],ll n){
    vector<ll> ans;
    ans.clear();

    vector<ll> state(n+1,0);

    rep(i,1,n+1){
        if(state[i]==0) dfs1(adj,i,state,ans);
    }

    rep(i,0,ans.size()/2) swap(ans[i],ans[ans.size()-1-i]);

    return ans;
}

ll divCount(ll n){
    ll ans=0;

    rep(i,1,1+(int)(sqrt(n))) if(n%i==0) ans++;

    ans*=2;

    if((int)(sqrt(n))*(int)(sqrt(n))==n) ans--;

    return ans;
}

/*

Pythagorean triplet is of the form (n*n-m*m,2*n*m,n*n+m*m);

*/

ll catalan(ll n){
    // 1. valid parenthesis consisting of n left and n right 
    // 2. possible binary tree with n nodes
    // 3. possible rooted tress with n+1 nodes

    ll ans=nCr(2*n,n);

    return ans/(n+1);
}

vector<ll> getDivisors(ll n){
    vector<ll> ans;
    ans.clear();

    vector<ll> temp1;
    temp1.clear();

    vector<ll> temp2;
    temp2.clear();

    rep(i,1,1+(int)(sqrt(n))){
        if(n%i==0){
            if(n/i==i){
                temp1.push_back(i);
            } else {
                temp1.push_back(i);
                temp2.push_back(n/i);
            }
        }
    }

    rep(i,0,temp1.size()) ans.push_back(temp1[i]);
    rrep(i,temp2.size()-1,0) ans.push_back(temp2[i]);

    return ans;
}

vector<ll> zArray(string str){
    ll n=str.length();

    vector<ll> ans(n,0);

    ll x=0;
    ll y=0;

    rep(i,1,n){
        ans[i]=max(0LL,min(ans[i-x],y-i+1));

        while(i+ans[i]<n && str[ans[i]]==str[i+ans[i]]){
            x=i;
            y=i+ans[i];
            ans[i]++;
        }
    }

    return ans;
}

ll lis(ll arr[],ll n){
    vector<ll> ans;
    ans.clear();

    rep(i,0,n){
        vector<ll>::iterator it=upper_bound(ans.begin(), ans.end(), arr[i]); //NON DECREASING
        //vector<ll>::iterator it=lower_bound(ans.begin(), ans.end(), arr[i]); //STRICT INCREASING

        if(it==ans.end()) ans.push_back(arr[i]);
        else *it=arr[i];
    }

    return ans.size();
}

/* SEGMENT TREE

void build(ll arr[],ll v,ll lower,ll upper,ll* segTree){
    if(lower==upper){
        segTree[v]=arr[lower];
        return;
    }

    ll mid=lower+(upper-lower)/2;

    build(arr,2*v+1,lower,mid,segTree);
    build(arr,2*v+2,mid+1,upper,segTree);

    segTree[v]=min(segTree[2*v+1],segTree[2*v+2]);

    return;
}

ll sum(ll* segTree,ll v,ll l,ll r,ll l1,ll r1){
    if(l1>r1 || l>r) return INT_MAX;
    if(l1==l && r1==r) return segTree[v];

    ll mid=l1+(r1-l1)/2;

    return min(sum(segTree,2*v+1,l,min(r,mid),l1,mid),sum(segTree,2*v+2,max(l,mid+1),r,mid+1,r1));
}

void update(ll* segTree,ll v,ll l1,ll r1,ll pos,ll newVal){
    if(l1==r1){
        segTree[v]=newVal;
        return;
    }

    ll mid=l1+(r1-l1)/2;

    if(pos<=mid){
        update(segTree,2*v+1,l1,mid,pos,newVal);
    } else update(segTree,2*v+2,mid+1,r1,pos,newVal);

    segTree[v]=min(segTree[2*v+1],segTree[2*v+2]);

    return;
}

*/

bool cmp(pair<pair<ll,ll>,ll> a,pair<pair<ll,ll>,ll> b){
    if(a.first.first<b.first.second) return true;
    else return false;
}

signed main() {
    
    /*#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt","w",stderr);
    #endif*/
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    srand(time(NULL));
    
    read(t);

    // ll t=1;
    
    for(ll tc=1;tc<=t;tc++){

    // cout<<endl<<endl<<"New Test Case"<<endl<<"New Test Case"<<endl<<endl;

    //code for a test case starts

    read(n);
    readarray(arr,n);

    ll ans[n];

    rrep(i,n,2){
        ll n1=i;
        ll index=-1;

        rep(j,0,n1){
            if(arr[j]==i) index=j;
        }

        index++;

        ans[i-1]=index%i;

        ll temp[n1];
        ll l=0;

        rep(j,index,n1){
            temp[l]=arr[j];
            l++;
        }

        rep(j,0,index){
            temp[l]=arr[j];
            l++;
        }

        rep(j,0,n1) arr[j]=temp[j];
    }

    ans[0]=0;

    rep(i,0,n) cout<<ans[i]<<" ";
    cout<<endl;

    







    

    







    

    

    
    









    


    

    




    

    

    

    
    
    


    

    





    
    

    





    































    


















    // code for a test case ends

    }
    
    return 0;

}

/*
1. always prefer long long to avoid overflow, agar memory hagde; then go for int
2. 1 sec mein 10^8 operations ho sakte hai
3. kabhi 50 length ka integral value input lena pade, toh usko string ki form mein lo input, long long bhi time/memory mein hag dega
4. variable you are dividing by should not be 0
5. 10^5 waale case mein 1+10^5 ka array declare karna
6. Dont erase from set while you are iterating it
*/