#include <bits/stdc++.h>

#define int long long

#define pb push_back

#define endl "\n"

#define ff first

#define ss second

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(__null);

#define md 998244353 

 

using namespace std;



signed main()

{

    fastio()

    

    int t;

    cin >> t;

    

    while(t--)

    {

        int n,x;

        cin >> n >> x;

        

        int a[n];

        map<int,int> m;

        for(int i=0;i<n;i++) cin >> a[i];

        

        sort(a,a+n);

        for(int i=0;i<n;i++) m[a[i]]++;

        

        int c=0;

        for(int i=0;i<n;i++) if(m[a[i]] && m[x*a[i]]) m[a[i]]--,m[x*a[i]]--,c++;

        

        cout << n-2*c << endl;

    }

    

    return 0;

}