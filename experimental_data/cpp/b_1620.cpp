/*****************************MANU CHITTORA**********************************/
    #pragma GCC optimize("O3")
    #pragma GCC target("popcnt")
    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long
    #define ull unsigned long long
    #define f(ii, n) for (ll ii = 0; ii < n; ii++)
    #define sp setprecision(30)
    #define endl "\n"
    #define pb push_back
    #define M 1000000007
    //isprime, isrbs, issort, ispalin, issubarray
    //sieve, dsu, lcs, gcd, fastpow, fact, powerof2 
    //numberofdivisors, numberofdigits, digitsum, power
    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);       
        ll ti=1;
        cin >> ti;
        f(i, ti)
        {
            ll w, h;
            cin>>h>>w;
            ll q1;
            cin>>q1;
            vector<ll>qb1(q1);
            f(i,q1)
            {
                cin>>qb1[i];
            }
            ll b1=abs(qb1[0]-qb1[q1-1]);
            ll h1=w;
            ll q2;
            cin>>q2;
            vector<ll>qb2(q2);
            f(i,q2)
            {
                cin>>qb2[i];
            }
            ll b2=abs(qb2[0]-qb2[q2-1]);
            ll h2=w;

            
            ll q3;
            cin>>q3;
            vector<ll>qb3(q3);
            f(i,q3)
            {
                cin>>qb3[i];
            }
            ll b3=abs(qb3[0]-qb3[q3-1]);
            ll h3=h;

            
            ll q4;
            cin>>q4;
            vector<ll>qb4(q4);
            f(i,q4)
            {
                cin>>qb4[i];
            }
            ll b4=abs(qb4[0]-qb4[q4-1]);
            ll h4=h;
            cout<<max({b1*h1, b2*h2, b3*h3, b4*h4})<<endl;
        }
    }