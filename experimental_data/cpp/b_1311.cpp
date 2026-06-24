#include <bits/stdc++.h>

#define ll long long

#define ld long double

#define vi vector<int>

#define vll vector<long long>

#define pii pair<int,int>

#define pll pair<ll , ll>

#define pb push_back

#define mp make_pair

#define FAST ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

#define INF INT_MAX

#define ff first

#define ss second

#define all(v) v.begin(),v.end()

#define pr(v) for(int i=0;i<v.size();i++)cout << v[i] << " "

#define nar ll n;cin >> n; ll a[n] ; for(int i=0;i<n;i++)cin >> a[i]

#define oar for(int i=0;i<n;i++)cout << a[i] << " "

#define nl "\n"

#define yes cout << "YES\n"

#define no cout << "NO\n"

using namespace std;

const ll MOD  = 1000000007 ;

const int mxN = 1e5+1;

const ld PI = 4.0 * atan(1);



int main(){



    FAST

    //==================

    ll t = 1;

    cin >> t;

    while(t--){

        ll n,m; cin >> n>>m;

        ll a[n],b[n],a2[n];

        map<ll,bool> mm ;

        for(int i=0;i<n;i++){

            cin >> a[i];

            a2[i] = a[i];

        }

        for(int i=0;i<m;i++){

            cin >> b[i];

            mm[b[i]-1] = 1;

        }

        sort(a2,a2+n);

        bool done[n];

        for(int i=0;i<n;i++)done[i] =0 ;

        bool is =1;

        for(int i=0;i<n;i++){

            ll st = i , en ;

            for(int j=0;j<n;j++){

                if(a2[j] == a[i] && !done[j]){

                    done[j] = 1 ;

                    en = j;

                    break;

                }

            }

            if(en < st)swap(en,st);

            for(int j=st;j<en;j++){

                if(!mm[j]){

                    is =0 ;

                    //cout << a[i] << " ==\n";

                    break;

                }

            }

        }

        if(is)yes;

        else no;

    }



}