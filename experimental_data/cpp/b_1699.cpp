#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>



using namespace std;

using namespace __gnu_pbds;



#define int long long

#define endl "\n"



typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key



vector<int> sieve(int n) {int*arr = new int[n + 1](); arr[0]=arr[1]=1; vector<int> vect; for (int i = 2; i*i <= n; i++)if (arr[i] == 0) {for (int j = i * i; j <= n; j += i)arr[j] = 1;} for(int i=0; i<=n; i++) {if(arr[i]==0) vect.push_back(i);} return vect;}



int M= 1e9 + 7;

int test=1;





void solve()

{

    int n, m;

    cin>>n>>m;

    vector<vector<int>> a(2, vector<int>(m));

    vector<vector<int>> b(2, vector<int>(m));

    int c=0;

    for(int i=0; i<m; i+=2)

    {

        a[0][i]= c;

        a[1][i]= 1-c;

        a[0][i+1]= 1-c;

        a[1][i+1]= c;

        

        c ^= 1;

    }

    c= 1;

    for(int i=0; i<m; i+=2)

    {

        b[0][i]= c;

        b[1][i]= 1-c;

        b[0][i+1]= 1-c;

        b[1][i+1]= c;

        

        c ^= 1;

    }

    for(int i=0; i<n/2; i++)

    {

        if(i%2 == 0)

        {

            for(auto& c: a)

            {

                for(auto& x: c)

                {

                    cout<<x<<" ";

                }

                cout<<endl;

            }

        }

        else

        {

            for(auto& c: b)

            {

                for(auto& x: c)

                {

                    cout<<x<<" ";

                }

                cout<<endl;

            }

        }

        

    }

}



int32_t main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(0);cout.tie(0);

    int t;

    t= 1;

    cin>>t;

    while(t--)

        solve();

    return 0;

}