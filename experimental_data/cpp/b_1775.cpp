/*

 author : Mzx

*/

#include<bits/stdc++.h>



using namespace std;



#define endl '\n'

#define int long long

#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define x first

#define y second



typedef long long ll;

typedef pair<int,int> PII;

const ll mod=1e9+7;

const int INF=0x3f3f3f3f;

const int maxn = 1e5 + 10;



int read()

{

    int x = 0, f = 1;

    char c = getchar();

    while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}

    while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();

    return x * f;

}



int n;

map<long long,long long> st;



void solve(){

    st.clear();

    cin >> n;

    vector<vector<int>> a(n + 2);

    for(int i = 1;i <= n;i ++)

    {

        int x;

        cin >> x;

//        a[i].resize(x);

        for(int j = 1;j <= x;j ++)

        {

            int y;cin >> y;

            a[i].push_back(y);

            st[y] ++;

        }

    }



    for(int i = 1;i <= n;i ++)

    {

        bool ok = true;

        for(auto x : a[i])

        {

            if(st[x] == 1)

            {

                ok = false;

                break;

            }

        }

        if(ok)

        {

            cout << "Yes" << '\n';

            return ;

        }

    }



    cout << "No" << '\n';

}





signed main()

{

    ios;

    int t; cin >> t;

    while(t--)

    {

        solve();

    }

    return 0;

}