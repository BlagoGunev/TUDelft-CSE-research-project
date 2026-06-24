#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <int, ll> pil;

template <class T> using min_queue = priority_queue<T, vector<T>, greater<T>>;

template<typename Args>
void kill(Args args)
{
    cout << args << "\n";
    exit(0);
}

#define add(x) emplace_back(x)
#define pb(x) push_back(x)
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)x.size()
#define fill(a, v) memset(a, v, sizeof a)
#define debug1(x) cerr << "at line " << __LINE__ << ": " << #x << " = " << (x) << endl
#define debug2(x) cerr << #x << " = " << (x) << endl


const double PI = acos(-1);
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;

const int N=1010110;
int n;
string s;
pii arr[N],temp[N];
int tot;

void solve(){
    cin>>s;
    n=sz(s);
    s="#"+s;
    int curr=s[1];
    int c=0;
    for(int i=1;i<=n;i++){
        if(s[i]==curr){
            c++;
        }
        else{
            arr[++tot]={curr,c};
            curr=s[i];
            c=1;
        }
    }
    arr[++tot]={curr,c};
    int ans=0;
    while(tot>1){
        ans++;
        int siz=0;
        for(int i=1;i<=tot;i++){
               if(i==1||i==tot){
                if(arr[i].second>1)temp[++siz]={arr[i].first,arr[i].second-1};
            }
             else{
                    if(arr[i].second>2)temp[++siz]={arr[i].first,arr[i].second-2};
                }
            }
            tot=0;
            int curr=temp[1].first;
            int c=0;
            for(int i=1;i<=siz;i++){
                if(temp[i].first==curr){
                    c+=temp[i].second;
                }
                else{
                    arr[++tot]={curr,c};
                    curr=temp[i].first;
                    c=temp[i].second;
                }
            }
            arr[++tot]={curr,c};
    }
    cout<<ans<<endl;
}

void precompute(){

}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cout<<fixed<<setprecision(12);
    int testcase=1;
    clock_t zzzx=clock();
    //cin>>testcase;
    precompute();
    while(testcase--){
        solve();
    }
    double elapsed_time=(double)(clock()-zzzx)/CLOCKS_PER_SEC;
    debug2(elapsed_time);
    return 0;
}