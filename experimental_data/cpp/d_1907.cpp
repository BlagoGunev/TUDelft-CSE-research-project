#include <bits/stdc++.h>
using namespace std;
#define rd(x) int x; cin >> x;
#define read(x,y) int x,y; cin >> x >> y;
#define fr(i,n) for(int i= 0; i < (n); i++) 
#define arrin(a,n)  for(int i=0;i<(n);i++) cin>>a[i];
#define printv(k) for(auto& i:k) cout<<i<<" "; cout<<endl;
#define printmp(k) for(auto& i:k) cout<<i.first<<" "<<i.second<<endl;
#define pb push_back
#define all(x)  x.begin(), x.end()
#define int long long
#define inf (1LL<<60)
#define in insert
#define endl '\n'
#define nl cout<<endl;
const int mod=1000000007;
// priority_queue <pair <int , int> , vector <pair <int , int>> , greater <pair <int , int>>> pq;
string getBinary(int n) {
bitset<64> b(n);
return b.to_string();
}

bool check(vector<pair<int,int> > &v,int mid){
    int last_min = 0 , last_max = 0;
    int n = v.size();
    for(int i=0;i<n;i++){
        last_max += mid;
        last_min -= mid;
        if(last_max < v[i].first || last_min > v[i].second){
            return false;
        }
        last_max = min(v[i].second, last_max);
        last_min = max(v[i].first, last_min);
    }
    return true;
}

//ayushmittal007
void solve() {
    int n;
    cin>>n;
    vector<pair<int,int> > v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].first>>v[i].second;
    }

    int low = 0 , high = 1e9; 
    int ans = 0;
    while(low <= high){
        int mid = (low + high)/2;
        if(check(v,mid)){
            ans = mid;
            high = mid - 1;
        }else {
            low = mid + 1;
        }
    }
    cout<<ans<<endl;
}


signed main() {
ios::sync_with_stdio(0), cin.tie(0);
cout.tie(0);
int T = 1;
cin >> T;
while (T--) {
solve();
}
}