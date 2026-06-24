#include <bits/stdc++.h>
#define ll long long
#define lli long long int
#define ulli unsigned long long int
#define vi vector<int>
#define pii pair<int,int>
#define vlli vector<lli>
#define vpii vector<pii>
#define vvi vector<vector<int> > 
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define rev(i,a,b) for(int i=a;i>=b;i--)
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz(a)  (int)a.size()
#define ld  long double
#define ff  first
#define ss  second

using namespace std;
//ctrl + B to compile and run
//ctrl + Q to stop infinite loop
//Here is one interesting fact. There always exists a power of prime p in the range [x,p*x] for any positive integer x
//With any positive integer x, there is at least one square number in [x,2x]

template<typename T> istream& operator>>(istream &in, vector<T>& a) { for(auto &x:a) in >> x; return in; }
template<typename T> ostream& operator<<(ostream &out, vector<T>& a) { for(auto &x:a) out << x << " "; return out; }
template<typename T> void print(T to_print){cout << to_print << '\n';return;}
template<typename T1,typename T2> ostream& operator<<(ostream &out,vector<pair<T1,T2> > &v){for(auto &p:v){cout << "(" << p.first << "," << p.second<<") ";}return out;}

const lli MOD = 998244353;
const lli N=2e5+10;


// lli gcd(lli a,lli b){
//     if(b==0)return a;
//     else return gcd(b,a%b);
// }
lli lcm(lli a,lli b){
    return 1ll*(a*b)/__gcd(a,b);
}

// lli pw(lli x,lli n){
//     lli ans=1;
//     while(n>0){
//         if(n&1) ans = (ans*x)%MOD;
//         x = (x*x)%MOD;
//         n>>=1;
//     }
//     ans%=MOD;
//     return ans;
// }



// class Point{
// public:
//     double x,y;
//     Point(double x,double y){
//         this->x = x;
//         this->y = y;
//     }
//     Point(){}
// };
// double dist(Point a,Point b){
//     double xdist = abs(a.x-b.x);
//     double ydist = abs(a.y-b.y);
//     return sqrtl(xdist*xdist+ydist*ydist);
// }


// bool is_perfect_square(int64_t n) {
//     int64_t s = int64_t(round(sqrt(n)));
//     return s * s == n;
// }
// bool binary(int n){
//     while(n>0){
//         if(n%10==0 || n%10==1){
//             n/=10;
//         }
//         else return false;
//     }
//     return true;
// }
// bool help(int n){
//     if(binary(n))return true;
//     for(int i=2;i*i<=n;i++){
//         if(n%i==0){
//             if(help(i) && help(n/i)){
//                 return true;
//             }
//         }
//     }
//     return false;
// }

void solve(){

    


    

    



    // int n;cin >> n;
    // string s;cin >> s;
    // lli ans=n;
    // for(int l=1;l*l<=n;l++){
    //     if(n%l==0){
    //         for(lli L:{l,n/l}){
    //             lli cnt1=0,cnt2=0;
    //             for(int i=0;i<L;i++){
    //                 for(int j=i+L;j<n;j+=L){
    //                     cnt1+=(s[i]!=s[j]);
    //                 }
    //             }
    //             for(int i=n-L;i<n;i++){
    //                 for(int j=i-L;j>=0;j-=L){
    //                     cnt2+=(s[i]!=s[j]);
    //                 }
    //             }
    //             if(cnt1<=1 || cnt2<=1){
    //                 ans = min(ans,L);
    //             }
    //         }
    //     }
    // }
    // cout << ans << '\n';

    // string s;cin >> s;
    // lli n = sz(s);
    // lli l=0,cnt=0;
    // for(int i=1;i<n;i++){
    //     if(s[i]==s[l])cnt++;
    //     else l=i;
    // }
    
    // l=0;
    // lli op=1;
    // lli num=0;
    // while(l<n){
    //     int cnt1=0,cnt2=0;
    //     while(l<n && s[l]==s[0]){
    //         cnt1++;
    //         l++;
    //     }
    //     while(l<n && s[l]!=s[0]){
    //         cnt2++;
    //         l++;
    //     }
    //     if(cnt1){
    //         num+=cnt1-1;
    //     }
    //     if(cnt2){
    //         num+=cnt2-1;
    //     }
    //     op= (op*((max(1,cnt1)*max(1,cnt2)))%MOD)%MOD;
    // }
    // lli fact=1;
    // for(int i=1;i<=num;i++){
    //     fact = (fact*i)%MOD;
    // }
    // cout << cnt << " " << (((fact)%MOD)*((op)%MOD))%MOD << '\n';







    // lli n,k;cin >> n >> k;
    // vector<int> a(n),h(n);
    // lli ans=0;
    // for(int i=0;i<n;i++){
    //     cin >> a[i];
    //     if(a[i]<=k)ans=1;
    // }

    // for(int i=0;i<n;i++){
    //     cin >> h[i];
    // }

    // lli l=0,r=0,sum=a[0];
    // vector<pair<int,int> > rg;
    // while(r<n-1){
    //     bool ent=0;
    //     rg.pb({l,r});
    //     while(r<n-1 && h[r]%h[r+1]==0){
    //         r++;
    //         ent=1;
    //     }
    //     if(ent==0){
    //         r++;
    //         l = r;
    //     }
        
    // }
    // rg.pb({l,r});
    // for(auto p:rg){
    //     l=p.first;r=p.first;sum=0;
    //     while(r<=p.second){
    //         sum+=a[r];
    //         while(l<=r && sum>k){
    //             sum-=a[l];
    //             l++;
    //         }
    //         ans = max(ans,r-l+1);
    //         r++;
    //     }
    // }
    // cout << ans << '\n';


    int n,k;cin >> n >> k;
    vector<vector<int> > v(k+1);
    int x;
    for(int i=1;i<=n;i++){
        cin >> x;
        v[x].push_back(i);
    }
    int l=n+1,r=0;
    vector<int> ans(k+1);
    for(int i=k;i>=1;i--){
        if(!v[i].empty()){
            for(int j=0;j<v[i].size();j++){
                l = min(l,v[i][j]);
                r = max(r,v[i][j]);
            }
            ans[i] = 2*(r-l+1);
        }
        else{
            ans[i] = 0;
        }
    }
    rep(i,1,k)cout << ans[i] << " \n"[i==k];








































































    //cout << "\n-------------------------\n";
    return;
    
}




int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);


    int t;cin >> t;
    while(t--) 
        solve();
    


    return 0;
}