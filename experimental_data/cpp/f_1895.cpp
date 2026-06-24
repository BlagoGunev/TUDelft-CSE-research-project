#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
using std::cout;
using std::cin;
using std::endl;
using ll=long long;
using ld=long double;
const ll ILL=2167167167167167167;
const int INF=2100000000;
const int mod=1e9+7;
#define rep(i,a,b) for (int i=(int)(a);i<(int)(b);i++)
#define all(p) p.begin(),p.end()
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
void yneos(bool a,bool upp=0){if(a) cout<<(upp?"YES\n":"Yes\n"); else cout<<(upp?"NO\n":"No\n");}
template<class T> void vec_out(vector<T> &p,int ty=0){
if(ty==2){cout<<'{';for(int i=0;i<(int)p.size();i++){if(i){cout<<",";}cout<<'"'<<p[i]<<'"';}cout<<"}\n";}
else{if(ty==1){cout<<p.size()<<"\n";}for(int i=0;i<(int)(p.size());i++){if(i) cout<<" ";cout<<p[i];}cout<<"\n";}}
template<class T> T vec_min(vector<T> &a){assert(!a.empty());T ans=a[0];for(auto &x:a) chmin(ans,x);return ans;}
template<class T> T vec_max(vector<T> &a){assert(!a.empty());T ans=a[0];for(auto &x:a) chmax(ans,x);return ans;}
template<class T> T vec_sum(vector<T> &a){assert(!a.empty());T ans=a[0]-a[0];for(auto &x:a) ans+=x;return ans;}
int pop_count(long long a){int res=0;while(a){res+=(a&1),a>>=1;}return res;}

ll jyo(ll x,ll y,ll z){
  ll H=y; //ここから
       ll a=1,b=(x%z+z)%z,c=1;
       while(H>0){
         a*=2;
         if(H%a!=0){
           H-=a/2;
           c*=b;
           c%=z;
         }
        b*=b;
         b%=z;
      } //ここまで
 return c;
}



template<class T>
using square_matrix=std::vector<std::vector<T>>;
template<class T,T (*add_op)(T,T),T(*add_e)(),T (*mul_op)(T,T),T(*mul_e)()>
square_matrix<T> mul_matrix(square_matrix<T> l,square_matrix<T> r){
    int n=l.size();
    assert((int)l[0].size()==n&&(int)r.size()==n&&(int)r[0].size()==n);
    square_matrix<T> val(n,std::vector<T>(n,add_e()));
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) for(int k=0;k<n;k++){
        val[i][k]=add_op(val[i][k],mul_op(l[i][j],r[j][k]));
    }
    return val;
}
template<class T,T (*add_op)(T,T),T(*add_e)(),T (*mul_op)(T,T),T(*mul_e)()>
square_matrix<T> pow_matrix(square_matrix<T> l,long long times){
    int n=l.size();
    square_matrix<T> val(n,std::vector<T>(n,add_e()));
    square_matrix<T> tmp(n,std::vector<T>(n,add_e()));
    for(int i=0;i<n;i++) val[i][i]=mul_e();
    while(times){
        if(times&1){
            for(int i=0;i<n;i++) for(int j=0;j<n;j++){
                tmp[i][j]=add_e();
            }
            for(int i=0;i<n;i++) for(int j=0;j<n;j++) for(int k=0;k<n;k++){
                tmp[i][k]=add_op(tmp[i][k],mul_op(val[i][j],l[j][k]));
            }
            swap(tmp,val);
        }
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) tmp[i][j]=add_e();
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) for(int k=0;k<n;k++){
            tmp[i][k]=add_op(tmp[i][k],mul_op(l[i][j],l[j][k]));
        }
        swap(tmp,l);
        times>>=1;
    }
    return val;
}

using mat_F=ll;
mat_F add_op(mat_F a,mat_F b){
    return (a+b)%mod;
}
mat_F add_e(){
    return 0;
}
mat_F mul_op(mat_F a,mat_F b){
    return (a*b)%mod;
}
mat_F mul_e(){
    return 1;
}
#define calc mat_F,add_op,add_e,mul_op,mul_e



void solve();
// oddloop
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t=1;
    cin>>t;
    rep(i,0,t) solve();
}

void solve(){
    ll N,K,X;
    cin>>N>>X>>K;
    ll ans=jyo(2*K+1,N-1,mod)*K%mod;
    if(X==0){
        cout<<ans<<"\n";
        return;
    }
    ans=jyo(2*K+1,N-1,mod)*(X+K)%mod;
    vector p(X,vector<ll>(X));
    rep(i,0,X) rep(j,0,X){
        if(abs(i-j)<=K) p[i][j]=1;
    }
    p=pow_matrix<calc>(p,N-1);
    for(auto x:p) for(auto y:x) ans=(ans-y)%mod;
    cout<<(ans%mod+mod)%mod<<"\n";
}