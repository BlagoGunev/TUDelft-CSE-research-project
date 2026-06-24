/*لو أنكم تتوكلون على الله حق توكله

 لرزقكم كما يرزق الطير

 تغدو خماصاً وتروح بطاناً

 Author: AHMED KASHKOUSH

 */

#include<bits/stdc++.h>

#define el '\n'

#define ll long long

#define all(s)  s.begin(), s.end()

#define pi      pair<int, int>

using namespace std;

bool cmp(pi &a, pi &b){

    return a.second<b.second;

}

void solve(){

    int n; cin>>n;

    vector<int> v(n);

    for(auto &i:v)cin>>i;

    sort(v.rbegin(), v.rend());

    if(n==1)

       cout<<(v[0]<=1?"YES":"NO");

    else

        cout<<(v[0]-v[1]<=1?"YES":"NO");







}









int main(){



//   freopen("input.txt","r",stdin);

//   freopen("output.txt","w",stdout);

   ios_base::sync_with_stdio(0), cin.tie(0),cout.tie(0);

    int t=1;

    cin>>t;

    while(t--){

      solve();

      cout<<el;

    }

}



// Notes

//upper_bound(all(arr), val) returns--->arr[id]>val;

//lower_bound(all(arr), val) returns--->arr[id]>=val;