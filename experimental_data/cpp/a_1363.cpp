#include<bits/stdc++.h>

#define int long long

#define pb push_back

#define _ ios::sync_with_stdio(false); cin.tie(NULL);

#define endl "\n"

using namespace std;



void solve()

{

        int n,x;

        cin >> n >> x;

        int ara[n];

        for(int i = 0;i < n;++i)

                   cin>>ara[i];



        int o = 0,e = 0;

        for (int i = 0; i < n; ++i)

               {

                   if(ara[i] & 1) ++o;

                   else e++;

               }    

     

        if(o+e<x or o== 0)       {

            cout << "No" << endl;

            return;

        }



        if(x%2 == 0 and e == 0)

        {

            cout << "No" << endl;

            return;

        }



        // if(x%2 ==1 and o%2 == 1 and x == o)

        // {

        //     cout << "Yes"< endl;

        //     return;

        // }

        // cout << "o = "<<o << "e = "<<e << endl;

        if(o%2 == 1)

        {

            cout << "Yes" << endl;

            return;

        }      

        if(o>x)    {

            cout << "Yes" << endl;

            return;

        }



        o--;

        if(e>=x-o){



            cout << "Yes" << endl;

            return;

        }



        cout << "No" << endl;

        return;

        // if(x%2 == 0)  















}



int32_t main()

{

    _

    int t;

    cin>>t;

    while(t--)

    {

        solve();

                          

    }



    return 0;  

}