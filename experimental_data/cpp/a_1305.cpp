#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first

#define se second

#define pb push_back

#define pii pair<int,int>



void solve(){

    int n;

    cin >> n;

    vector<int> a(n), b(n);

    for(int i = 0; i < n; i++ ){

        cin >> a[i];

    }

    for(int i = 0; i < n; i++ ){

        cin >> b[i];

    }

    sort(a.begin(), a.end());

    sort(b.begin(), b.end());

    for(int i = 0; i < n; i++ ){

        cout << a[i] << " \n"[i == n - 1];

    }

    for(int i = 0; i < n; i++ ){

        cout << b[i] << " \n"[i == n - 1];

    }

}

int main() 

{

    ios::sync_with_stdio(false);

    cin.tie(nullptr);

    int T;

    cin >> T;

    while(T--){

        solve();

    }

    return 0;

}