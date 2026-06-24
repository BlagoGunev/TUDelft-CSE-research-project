#include <bits/stdc++.h>



using namespace std;



const char nl = '\n';



typedef long long ll;



const int MOD = 1e9 + 7;



set<ll> st;



void up(ll &x){

    x++;

    while(st.count(x)){

        x++;

    }

}



void down(ll &x){

    x--;

    while(st.count(x)){

        x--;

    }

}



int main(){

    ios_base::sync_with_stdio(0);

    cin.tie(0); cout.tie(0);

    int tt; cin >> tt;

    while(tt--){

        ll n, m; cin >> n >> m;

        st.clear();

        ll med = ((1ll<<m) - 1)/2;

        ll siz = 1ll<<m;

        for(int i = 0; i < n; i++){

            string s; cin >> s;

            ll x = 0;

            for (int j=0; j<m; j++) {

                if (s[s.length()-j-1] == '1')

                    x |= 1LL << j;

            }

            st.insert(x);

            if(x == med){

                if(siz%2 == 1){

                    down(med);

                }

                else{

                    up(med);

                }

            }

            else if( x > med){

                if(siz%2 == 1){

                    down(med);

                }

            }

            else{

                if(siz%2 == 0){

                    up(med);

                }

            }

            siz--;

        }

        

        for (int j=m-1; j>=0; j--)

            cout << ((med >> j) & 1);

        cout << "\n";

        

        // ll lo = -1, hi = 1ll<<m + 1, mid;

        // auto works = [&](ll mid){

        //     ll g = upper_bound(a.begin(), a.end(), mid) - a.begin();

        //     return (mid + g <= (1ll<<m) - 1 - mid + n - g);

        // };

        // while( lo + 1 < hi){

        //     mid = hi + (lo - hi)/2;

        //     if(works(mid)){

        //         hi = mid;

        //     }

        //     else{

        //         lo = mid;

        //     }

        // }

        // cout << hi + 1 << nl;



    }

}