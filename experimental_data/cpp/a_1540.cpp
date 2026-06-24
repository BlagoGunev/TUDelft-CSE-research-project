#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;









void answer(){

    int n;

    cin>>n;

    vector<int> arr(n);

    for(int i = 0; i<n; i++){

        cin>>arr[i];

    }



    sort(arr.begin(), arr.end());



    vector<int> diff(n);



    ll ans = 0;



    for(int i = 1; i<n; i++){

        diff[i] = arr[i] - arr[i - 1];

        ans += diff[i];

    }



    for(int i = 1; i<n; i++){

        ans -= ((ll) diff[i]) * ((ll) i) * ((ll) (n - i));

    }

    cout<<ans<<"\n";

    return;







}





int main(){

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);



    int t;

    cin>>t;

    while(t--){

        answer();

    }

}