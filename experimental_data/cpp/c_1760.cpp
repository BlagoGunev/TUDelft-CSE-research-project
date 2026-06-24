#include <bits/stdc++.h>



using namespace std;

#define el "\n"

#define ll long long

#define TxtIO  freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);

#define $3asfour_Codes ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);



void solve()

{

    int n; cin>>n;

    ll a[n+1] , b[n+1];

    for(int i=0;i<n;i++)

    {

        cin>>a[i]; b[i]=a[i];

    }

    sort(b,b+n,greater<>());

    for(int i=0;i<n;i++)

    {

        if(a[i] == b[0])

        {

            cout<<a[i]-b[1]<<" ";

        }

        else cout<<a[i]-b[0]<<" ";

    }

    cout<<el;

}



int main()

{

    $3asfour_Codes;

    int t; cin >> t;

    while (t--)

        solve();

}