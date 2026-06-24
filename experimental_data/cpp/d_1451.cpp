#include <bits/stdc++.h>

#define lli long long int

#define pb push_back

#define endl "\n"

#define ff first

#define ss second

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(__null);



using namespace std;



int main()

{

    fastio()



    int t;

    cin >> t;

    

    while(t--)

    {

        lli d,k;

        cin >> d >> k;

        

        lli f = floor(d/(sqrt(2)*k)),y = f*k,m = (sqrt(d*d-y*y)-y)/k;

        

        if(m==0) cout << "Utkarsh" << endl;

        else cout << "Ashish" << endl;

    }



    return 0;

}