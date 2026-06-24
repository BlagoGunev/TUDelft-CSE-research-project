// ---------- ॐ नमः शिवाय ---------- //

 

#include<bits/stdc++.h>

using namespace std;

 

#define ll long long int

#define F first

#define S second

#define pb push_back

#define pf push_front

#define mp make_pair

#define si set <int>

#define vi vector<int>

#define vll vector<long long>

#define vvi vector<vector<int>>

#define pii pair<int, int>

#define vpi vector<pii>

#define vpp vector<pair<int, pii>>

#define vpic vector<pair<int, char>>

#define mii map<int, int>

#define mci map<char, int>

#define mpi map<pii, int>

#define spi set<pii>

#define endl "\n"

#define all(p) p.begin(), p.end()

#define double long double

#define que_max priority_queue <int>

#define puw_min priority_queue <int, vi, greater<int>>

#define test_cases ll test_c; cin>>test_c; while(test_c--)

#define forl(n) for(ll i=0;i<n;i++)

#define takeVecInp(n, v) for(ll i=0;i<n;i++){ll temp; cin>>temp; v.pb(temp);}

#define showVecArr(v) for(int i=0;i<v.size();i++){cout<<v[i]<<" ";}

const ll mod = 1e9+7;

const int N = 1e6+10;



int32_t main(){

    // #ifndef sahilmandoliya

    //     freopen("input.txt","r",stdin);

    //     freopen("output.txt","w",stdout);

    // #endif

    

    test_cases{

        int n;

        cin>>n;

        vi a(105), b(105);

        for(int i=1;i<=n;i++){

            cin>>a[i];

        }

        for(int i=1;i<=n;i++){

            cin>>b[i];

        }

        vi v, v2;

        for(int i=1;i<=n;i++){

            for(int j=1;j<=a[i]-b[i];j++) v.pb(i);

            for(int j=1;j<=b[i]-a[i];j++) v2.pb(i);

        }

        if(v.size() !=v2.size()){

            cout<<"-1"<<endl;

            continue;

        }

        cout<<v.size()<<endl;

        for(int i=0;i<v.size();i++){

            cout<<v[i]<<" "<<v2[i]<<endl;

        }

    }



    return 0;

}