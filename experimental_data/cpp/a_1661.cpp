#include<bits/stdc++.h>

#define x first

#define y second



using namespace std;

typedef long long LL;

typedef unsigned long long ull;

typedef pair<int,int> pii;

typedef pair<LL,int> pli;



const int N = 200010,mod = 998244353;

const LL INF = 1e18;

LL a[N],b[N];

int n,m,t;



void solve()

{

    cin>>n;

    for(int i = 0;i < n;i++) cin>>a[i];

    for(int i = 0;i < n;i++) cin>>b[i];



    for(int i = 0;i < n;i++)

    {

        if(a[i] > b[i]) swap(a[i],b[i]);

    }

    LL res = 0;

    for(int i = 1;i < n;i++) res += abs(a[i] - a[i - 1]),res += abs(b[i] - b[i - 1]);

    cout<<res<<endl;

}



int main()

{

    ios::sync_with_stdio(false);

    cin.tie(0);

    cout.tie(0);

    

    cin>>t;

    while (t--)

    {

        solve();

    }

    return 0;   

}