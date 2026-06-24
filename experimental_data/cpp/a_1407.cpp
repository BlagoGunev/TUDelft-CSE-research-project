#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define nl << '\n' 

#define sp << " " <<

#define forn(i,n)  for(int i=0;i<n;i++) 

#define all(x)         (x).begin(),(x).end()

#define debug(n) cout << #n << " : " << n << '\n'; 

#define debug2(n1,n2) cout << #n1 << " : " << n1 << "  " << #n2 << " : " << n2 << '\n';

#define debug3(n1,n2,n3) cout << #n1 << " : " << n1 << "  " << #n2 << " : " << n2 << "  " << #n3 << " : " << n3 << '\n';

#define gkick for(int i=1;i<=t;i++) googlekick(i);

const int M = 1e9+7;



void solve(){

    int n; cin >> n;

    int a[n];

    int cnt = 0;

    for(int i=0;i<n;i++) cin >> a[i], cnt += a[i];

    if(cnt>n/2){

        if(cnt%2) cnt--;

        cout << cnt nl;

        for(int i=1;i<=cnt;i++) cout << 1 << " ";

        cout nl;

    }

    else{

        cout << n-cnt nl;

        for(int i=1;i<=n-cnt;i++) cout << 0 << " ";

        cout nl;

    }

}





int main(){

    ios_base::sync_with_stdio(false);

    cin.tie(0);cout.tie(0);



    //freopen("input.txt", "r", stdin);

    //freopen("output.txt", "w", stdout);



    int t=1;

    cin >>t;



    while(t--)solve();



       

    return 0;

}