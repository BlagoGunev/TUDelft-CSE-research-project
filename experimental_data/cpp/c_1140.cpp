#include<bits/stdc++.h>
#define sz(x) ((int)x.size())
#define mp(x, y) make_pair(x, y)
using namespace std;

typedef long long ll;
const int MAXN = 300010;

inline int read(){
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9'){if(ch == '-') f = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0'; ch = getchar();}
    return x * f;
}

int n, k;
pair<int, int> a[MAXN];
priority_queue<int, vector<int>, greater<int> > pq;
ll ans, sum;

int main(){
    n = read(); k = read();
    for(int i = 1; i <= n; i ++){
        a[i].second = read();
        a[i].first = read();
    }
    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);
    for(int i = 1; i <= n; i ++){
        if(pq.size() < k){
            pq.push(a[i].second);
            sum += a[i].second;
        }
        else if(a[i].second > pq.top()){
            int tmp = pq.top();
            sum -= tmp;
            pq.pop();
            pq.push(a[i].second);
            sum += a[i].second;
        }
        ans = max(ans, sum * a[i].first);
    }
    cout << ans;
    return 0;
}