#include <bits/stdc++.h>

using namespace std;

void solve();

int main(){

ios_base::sync_with_stdio(false);

cin.tie(NULL);

     int t;

     cin >> t;

     while (t--) {

         solve();

        cout<<endl;

    }

    return 0;

}

void solve(){

    int n, k,score=0;

    cin >> n >> k;

    vector<int> a(n);

    for (int i = 0; i < n; i++)

    {

        cin >> a[i];

    }

    sort(a.begin(), a.end());

    for (int i = 0; i < k; i++)

    {

        score += (a[((n - (2 * k)) + i)] / a[(n-k) + i]); //pairing for making the divison of num 0

    }

    //adding the remaining elements directly after pairing , if any left

    for (int i = 0; i < n-(2*k); i++)

    {

        score += a[i];

    }

    cout << score;

}