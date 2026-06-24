#include<iostream>
#include <forward_list>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cctype>
#include <climits>
#include <fstream>
#include <random>
#include<list>
#include<iomanip>
#include<numeric>
#include<map>
#include<bitset>
#include<unordered_map>
#include<string>
#include<set>
#include<stack>
#include<queue>
#include<functional>
#include<deque>
#include<utility>
#include <chrono>
using namespace std::chrono;
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fo(i, a, b) for (ll i = a; i < b; i++)
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define no cout << "NO" << "\n"
#define yes cout << "YES" << "\n"

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n; cin>>n;
        vector<char> c(n);
        fo(i,0,n){
            cin>>c[i];
        }
        vector<int> v(n);
        bool zero = false;
        bool other = false;
        fo(i,0,n){
            v[i] = c[i] - '0';
            if(v[i] == 0) zero = true;
            else if(v[i] != 1) other = true;
        }
        ll ans = 0;
        if(n == 2) cout<<(v[0]*10 + v[1])<<endl;
        else if(zero && n>3) cout<<ans<<endl;
        else if(zero && n == 3 && (v[0] == 0 || v[2]==0)) cout<<"0"<<endl;
        else if(n == 3 && zero && v[0] == 1 && v[2] == 1) cout<<"1"<<endl;
        else if(!other) cout<<"11"<<endl;
        else{
            ans = INT_MAX;
            ll sum = 0;
            fo(i,0,n){
                if(v[i] != 1) sum += v[i];
            }
            ll num = 0;
            ll temp = 0;
            fo(i,1,n){
                temp = sum;
                num = v[i-1]*10 + v[i];
                if(v[i] != 1) temp -= v[i];
                if(v[i-1] != 1) temp -= v[i-1];
                if(num == 1) temp *= num;
                else temp += num;
                ans = min(ans, temp);
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}