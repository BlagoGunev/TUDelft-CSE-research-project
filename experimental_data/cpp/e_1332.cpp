// *YUVA*

    #include<bits/stdc++.h>

    using namespace std;

 

    #define double long double

    #define pb push_back

    #define int long long

    typedef vector<int> vi;

    #define all(a) a.begin(),a.end()

    typedef pair<int,int> pi;

    const int z=0;

    const long long N = 998244353;

    #define f first

    #define s second

//



long long binpow(long long a, long long b, long long m) {

    a %= m;

    long long res = 1;

    while (b > 0) {

        if (b & 1)

            res = res * a % m;

        a = a * a % m;

        b >>= 1;

    }

    return res;

}



void get()

{

    int l,r,n,m; cin>>n>>m>>l>>r;

    if(n*m%2==1)

    {

        int ans=binpow(r-l+1,n*m,N);

        cout<<ans;

        return;

    }



    int o=(r-l+1)/2;

    int e=r-l+1-o;



    int ans=binpow(o+e,m*n,N);

    ans+=binpow(o-e,m*n,N);

    ans%=N;

    ans*=binpow(2,N-2,N);

    ans%=N;

    cout<<ans;

}



int32_t main()

{

    #ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

    #endif // ONLINE_JUDGE



    ios_base::sync_with_stdio(false);

    cin.tie(0);

    cout.tie(0);



    int Q=1;

    //cin>>Q;

    for(int i=0;i<Q;i++)

    {

        //cout<<"Case #"<<i+1<<": ";

        get();        

        cout<<endl;

    }

}