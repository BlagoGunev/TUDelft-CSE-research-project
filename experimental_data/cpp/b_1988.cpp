#include <bits/stdc++.h>
#include <queue>
#include <set>
#include <map>  
#include <vector>
#include <cmath>
using namespace std;
#define ll long long
#define ull unsigned long long
#define yes cout << "YES" << '\n'
#define mk make_pair
#define f first
#define s second
#define pb push_back
#define no cout << "NO" << '\n'
#define cin(x, N) for(int i = 1; i <= N; i ++) cin >> x[i]
#define reverse(x, N) for(int i = 1; i <= N / 2; i ++) swap(x[i], x[N - i + 1]);
#define sortm(x, N) sort(x + 1, x + N + 1)
#define sortvec(x) sort(x.begin(), x.end())
#define matrix vector <vector <ll> >
void solve(){
    int n; cin >> n;
    int a[n + 1], q0 = 0, q1 = 0;
    for(int i = 1; i <= n; i ++){
        char c; cin >> c;
        a[i] = c - '0';
        q1 += a[i];
    }
    if(a[1] == 0) q0 ++;
    for(int i = 2; i <= n; i ++){
        if(a[i] == 0 && a[i - 1] == 1) q0 ++;
    }
    if(q1 > q0) yes;
    else no;
}
int main(){
    // freopen("rvq.in","r",stdin);
    // freopen("rvq.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);    
    int T = 1;
    cin >> T;
    while(T --) solve();
}
//2147483647   -   2^31 - 1   =   maxINT
//9223372036854775807  -  2^63 - 1  =  maxL