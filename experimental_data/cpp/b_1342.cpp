#include<bits/stdc++.h>

#define ll long long



using namespace std;



void solve()

{

    string t; cin >> t;

    ll z=0 , o=0;

    for ( ll i=0; i<t.size(); i++){

        if ( t[i] == '0')z++; else o++;

    }

    if ( min(z, o) == 0){

        cout << t <<endl;

        return;

    }

    else {

        ll cnt =0;

        if ( t[0] == '0'){

            while ( cnt < t.size()-1){

                cout << "01";

                cnt++;

            }

            cout << "0";

            cout << '\n' ;

            return;

        }

        if ( t[0] == '1'){

            while ( cnt < t.size()-1){

                cout << "10";

                cnt++;

            }

            cout <<"1";

            cout << '\n' ;

            return;

        }

    }

}

int main ()

{

    int t = 0; cin >> t;

    while(t--)

    {

      solve();

    }

}