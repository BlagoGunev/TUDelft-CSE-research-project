#include <bits/stdc++.h>



using namespace std;



#define testcases int testcases = 1 ; cin>>testcases ; while(testcases--)

#define Moham6d_Fathy ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

#define loop(n) for(int i=0;i<n;i++)

#define loop1(n) for(int i=1;i<=n;i++)

#define rloop(n) for(int i=n-1;i>=0;i--)

#define ll  long long

#define ld  long double

#define all(n) n.begin() , n.end()

#define rall(v) v.rbegin(),v.rend()

#define endl "\n"

#define pi 3.14159265359



ll mod = 1e9+7;



ll _gcd(ll n1,ll n2)

{

    while (n2!=0)

    {

        ll temp=n1;

        n1=n2;

        n2=temp%n1;

    }

    return n1;

}



ll _lcm(ll n1,ll n2)

{

    return (n1/ _gcd(n1,n2))*n2;

}



int fact(ll i)

{

    if (i <= 1) return 1;

    else return i*fact(i-1);

}



bool comp(pair<ll,ll>p1,pair<ll,ll>p2)

{

    if(p1.first==p2.first)

        return (p1.second<p2.second);



    return (p1.first<p2.first);



}

int lcs( string X, string Y, int m, int n )

{

    if (m == 0 || n == 0)

        return 0;

    if (X[m-1] == Y[n-1])

        return 1 + lcs(X, Y, m-1, n-1);

    else

        return max(lcs(X, Y, m, n-1), lcs(X, Y, m-1, n));

}

///////////-_-//////////////////////////////*Solve*/////////////////////////////////-_-////////////





void solve()

{

    int n;

    cin>>n;



    if(n==1||n==3)

    {

        cout<<-1;

    }else

    {

        cout<<n<<" "<<n-1<<" ";

        for(int i=1;i<n-1;i++)

            cout<<i<<" ";

    }

    cout<<endl;

}



int main()

{

    Moham6d_Fathy;



#ifndef ONLINE_JUDGE

    //freopen("input.txt", "r", stdin);

    //freopen("output.txt", "w", stdout);

#endif



    testcases

    {

        solve();

    }





    return 0;

}