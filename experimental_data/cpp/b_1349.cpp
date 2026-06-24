// LUOGU_RID: 102232023
#include<bits/stdc++.h>



using namespace std;



void err() {cerr << '\n';}

template<typename T, typename... Args>

void err(T a, Args... args){cerr << a << ' '; err(args...);};



typedef long long ll ;

const int N = 2e5 + 5; 





void solve(){

    int n, k;

    cin >> n >> k;

    vector<int> a(n);

    for(int i = 0; i < n; ++i )cin >> a[i];

    bool ok = false;

    for(int i = 0; i < n; ++i){

        if(a[i] == k)ok = true;

    }

    if(!ok){

        cout << "no\n";

        return;

    }

    ok = false;

    if(n == 1)ok = a[0] == k;

    for(int i = 0; i < n; ++i){

        if(a[i] >= k){

            if(i && a[i - 1] >= k)ok = true;

            if(i < n - 1 && a[i + 1] >= k)ok = true;

        }

    }

    for(int i = 1; i < n - 1; ++i)

        if(a[i - 1] >= k && a[i + 1] >= k)ok = true;

    cout << (ok ? "yes\n" :"no\n");

}



int main(void) {

    ios_base::sync_with_stdio(0);

    cin.tie(nullptr), cout.tie(nullptr);

    int t = 1;

    cin >> t;

    while(t--) solve () ;

    return 0;

}