#include<bits/stdc++.h>

#define PII pair<int,int>

#define PLL pair<long long,long long>

#define fi first

#define se second

#define endl '\n'

#define bug printf("bug\n");

using namespace std;

const int N=2e5+10;

const int INF=0x3f3f3f3f;

const long long LNF=0x3f3f3f3f3f3f3f3f;

const long long mod=1e9+7;



void solve(){

	int n, k;

    cin >> n >> k;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {

        std::cin >> a[i];

    }

    int m = a.back();

    int min = a[0];

    

    vector<std::vector<int>> f(m + 1);

    for (int i = 0; i < n; i++) {

        f[a[i]].push_back(i);

    }

    int ans = m;

    for (int max = m; max >= 0; max--) {

        ans = std::min(ans, max - min);

        for (auto i : f[max]) {

            if (max == a[i] / k) {

                cout << ans << "\n";

                return;

            }

            int v = a[i] / (a[i] / max + 1);

            f[v].push_back(i);

            min = std::min(min, v);

        }

        f.pop_back();

    }

}



int main(){

	int t=1;

	scanf("%d",&t);

	while(t--){

		solve();

	}

	return 0 - 0;

}