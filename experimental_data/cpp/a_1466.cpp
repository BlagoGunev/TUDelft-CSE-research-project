#include <bits/stdc++.h>

#define int long long

#define endl '\n'

#define pi acos(-1)

using namespace std;

int binpow(int a,int n)

{

    if(n==0)return 1;

    if(n%2==0)return binpow(a*a,n/2);

    return a*binpow(a,n-1);

}

bool prime(int n)

{

    for(int i=2;i*i<=n;i++){

        if(n%i==0)return false;

    }

    return true;

}



void solve()

{

    int n;

    cin>>n;

    int a[n];

    for(int i=0;i<n;i++)cin>>a[i];

    set<int>s;

    for(int i=0;i<n;i++){

        for(int j=i+1;j<n;j++){

            s.insert(abs(a[i]-a[j]));

        }

    }

    cout<<s.size();

}

int32_t main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(nullptr);

    cout.tie(nullptr);

    //freopen("input.txt", "r", stdin);

    //freopen("output.txt", "w", stdout);



    int tc=1;

    cin>>tc;

    while(tc--){

        solve();

        cout<<endl;

    }

    return 0;

}