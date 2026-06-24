#include <bits/stdc++.h>

using namespace std;



#define lld long double

#define ll long long

#define inf 0x3f3f3f3f

#define linf 0x3f3f3f3f3f3f3f3fll

#define ull unsigned long long

#define PII pair<int, int>

#define fi first

#define se second

#define mod 1000000007

#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}

#define fire ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 100010;

int n;

int a[N], b[N], pos[N];

void solve(){

    cin >> n;

    for(int i = 1; i <= n; i++){

        cin >> a[i];

        pos[a[i]] = i;

    }

    for(int i = 1; i <= n; i++) cin >> b[i];

    int l1 = n;

    int cur = inf;

    while(l1 >= 1){

        if(pos[b[l1]] < cur){

            cur = pos[b[l1]];

            l1--;

        }

        else break;

    }



    cout << l1 << '\n';

    for(int i = 1; i <= n; i++) pos[i] = 0;

}



int main()

{

    fire;

    int t; cin >> t;

    while(t--) solve();

    return 0;

}



/*

    If get stucked, write down something, stay calm and organized

*/