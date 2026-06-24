#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>



using namespace std;

using namespace __gnu_pbds;





struct custom_hash {

    static uint64_t splitmix64(uint64_t x) {

        // http://xorshift.di.unimi.it/splitmix64.c

        x += 0x9e3779b97f4a7c15;

        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;

        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;

        return x ^ (x >> 31);

    }



    size_t operator()(uint64_t x) const {

        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();

        return splitmix64(x + FIXED_RANDOM);

    }

};



typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;



#define sz(x) static_cast<int>((x).size())



const int mod = 998244353;

const int INF = 1e9;



/* ----------------------------------------------------- GO DOWN ---------------------------------------------------------------------- */





int c[2500001] = {0};

vector<pair<int, int>> cf[(int)5e6 + 1];





signed main(){



        ios::sync_with_stdio(0);

        cin.tie(0);

        cout.tie(0);

        

        

        int n;

        cin >> n;



        int a[n];

        for (int i = 0; i < n; i++) cin >> a[i];



        pair<int, int> b[n];



        for (int i = 0; i < n; i++) b[i] = {a[i], i + 1};

        sort(b, b + n);



        int rep = 0;

        int rep1 = -INF, rep2 = -INF, rep3 = -INF;



        bool got = false;



        for (int i = 0; i < n; i++) {



                c[a[i]]++;

                if (c[a[i]] == 2) {

                        rep++;

                        if (rep == 1) rep1 = a[i];

                        else {

                                rep2 = a[i]; 

                                got = true;

                        }

                }

                if (c[a[i]] == 4) {

                        rep3 = a[i];

                        got = true;

                }

                if (got) break;





        }



        if (got) {

                int i1, i2, i3, i4, c1 = 0, c2 = 0;

                if (rep3 == -INF) {



                        for (int i = 0; i < n; i++) {



                                if (a[i] == rep1) {

                                        if (c1 == 0) i1 = i + 1;

                                        if (c1 == 1) i3 = i + 1;

                                        c1++;

                                }

                                if (a[i] == rep2) {

                                        if (c2 == 0) i2 = i + 1;

                                        if (c2 == 1) i4 = i + 1;

                                        c2++;

                                }



                        }





                }

                else {

                        int c3 = 0;

                        for (int i = 0; i < n; i++) {

                                if (a[i] == rep3) {

                                        if (c3 == 0) i1 = i + 1;

                                        if (c3 == 1) i2 = i + 1;

                                        if (c3 == 2) i3 = i + 1;

                                        if (c3 == 3) i4 = i + 1;

                                        c3++;

                                }

                        }



                }



                cout << "YES\n" << i1 << " " << i2 << " " << i3 << " " << i4;

                return 0;



        }



        vector<pair<int, int>> d;

        int f = -INF;



        for (int i = 0; i < n; i++) {



                if (b[i].first == f) {

                        if (sz(cf[2 * f]) == 0) cf[2 * f].push_back({b[i - 1].second, b[i].second});

                        continue;

                }

                f = b[i].first;

                d.push_back(b[i]);



        }





        int gotsum;



        for (int i = 0; i < sz(d); i++) {



                for (int j = i + 1; j < sz(d); j++) {



                        int x = d[i].first + d[j].first;

                        cf[x].push_back({d[i].second, d[j].second});

                        if (sz(cf[x]) == 2) {

                                got = true;

                                gotsum = x;

                                break;

                        }





                }

                if (got) break;





        }



        if (got) cout << "YES\n" << cf[gotsum][0].first << " " << cf[gotsum][0].second << " " << cf[gotsum][1].first << " " << cf[gotsum][1].second;

        else cout << "NO\n";













        

        



}