#include <bits/stdc++.h>
#define ld long double
#define ll long long int
#define st first
#define nd second
#define pb push_back
#define pii pair<int,int>
#define mp make_pair

using namespace std;

const int N = 3e5 + 5;
int a[N];
int n, k;

int pref[N];
int suf[N];

bool can(ll bound){
    priority_queue<int> taken;
    priority_queue<int, vector<int>, greater<int>> nonTaken;
    ll sumTaken = 0;
    for(int i=1;i<=n;i++){
        nonTaken.push(a[i]);
        if(!taken.empty() && !nonTaken.empty()){
            if(taken.top() > nonTaken.top()){
                int s1 = taken.top();
                int s2 = nonTaken.top();
                taken.pop();
                nonTaken.pop();
                sumTaken += (s2 - s1);
                taken.push(s2);
                nonTaken.push(s1);
            }
        }
        while(!nonTaken.empty() && nonTaken.top() + sumTaken <= bound){
            int s = nonTaken.top();
            taken.push(s);
            nonTaken.pop();
            sumTaken += s;
        }
        pref[i] = taken.size();
    }

    while(!taken.empty()) taken.pop();
    while(!nonTaken.empty()) nonTaken.pop();
    sumTaken = 0;

    for(int i=n;i>=1;i--){
        nonTaken.push(a[i]);
        if(!taken.empty() && !nonTaken.empty()){
            if(taken.top() > nonTaken.top()){
                int s1 = taken.top();
                int s2 = nonTaken.top();
                taken.pop();
                nonTaken.pop();
                sumTaken += (s2 - s1);
                taken.push(s2);
                nonTaken.push(s1);
            }
        }
        while(!nonTaken.empty() && nonTaken.top() + sumTaken <= bound){
            int s = nonTaken.top();
            taken.push(s);
            nonTaken.pop();
            sumTaken += s;
        }
        suf[i] = taken.size();
    }

    int ans = 0;
    pref[0] = suf[n + 1] = 0;
    for(int i=0;i<=n;i++) ans = max(ans, pref[i] + suf[i + 1]);
    return (ans >= k);
}

void solve(){
    cin >> n >> k;
    for(int i=1;i<=n;i++) cin >> a[i];
    ll atLeast = 0;
    vector<int> b;
    for(int i=1;i<=n;i++) b.pb(a[i]);
    sort(b.begin(), b.end());
    for(int i=0;i<k;i++) atLeast += b[i];
    ll low = (atLeast + 1) / 2;
    ll high = low + 1e9;
    while(low < high){
        ll mid = (low + high) / 2;
        if(can(mid)) high = mid;
        else low = mid + 1;
    }
    cout << low << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}