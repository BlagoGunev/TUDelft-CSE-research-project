#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

typedef long long LL;



void solve()

{

    int n;

    cin >> n;

    vector<LL>a(n), b(n);

    int sign = 0, f = 1;

    LL sum = 0;

    for(int i = 0; i < n; i ++)

    {

        cin >> a[i];

        if(!i) b[i] = a[i];

        else b[i] = a[i] + b[i - 1];

        sum += a[i];

    }

    for(int i = 0; i < n; i ++)

    {

        if(b[i] == 0) sign = 1;

        if(sign && b[i] > 0) f = 0;

        if(b[i] < 0) f = 0;

        if(!f) break;

    }

    if(sum) f = 0;

    if(f) puts("Yes");

    else puts("No");

}



int main()

{

    ios::sync_with_stdio(0);

    cin.tie(0), cout.tie(0);

    //freopen("in.txt", "r", stdin);

    //freopen("out.txt", "w", stdout);



    int t = 1;

    cin >> t;

    while(t --) solve();

}