#include<bits/stdc++.h>
using namespace std;
typedef long long lg;
typedef long double ld;
#define INF 500'000'000'000'000'000
#define pii pair<lg,lg>
#define ff first
#define ss second

lg n,m,k,t;
lg prefix[200005];
lg arr[200005];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--){
        cin >> n >> k;
        for(lg i=0;i<=n+1;i++) prefix[i] = 0;
        string s;
        cin >> s;
        for(lg i=1;i<=n;i++){
            arr[i] = s[i-1] - '0';
        }
        for(lg i=n;i>=1;i--){
            prefix[i] = prefix[i+1];
            if(arr[i] == 0) prefix[i]--;
            else prefix[i]++;
        }
        priority_queue<lg> q;
        for(lg i=2;i<=n;i++){
            q.push(prefix[i]);
        }
        lg sum = 0;
        lg ans = 0;
        while(!q.empty() && sum < k){
            sum += q.top();
            q.pop();
            ans++;
        }
        if(sum >= k) cout << ans+1 <<"\n";
        else cout <<"-1\n";
    }
}