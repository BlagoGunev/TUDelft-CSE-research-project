/// BISMILLAHIRAHMANIR RAHIM



                        /*

                        Md. Mustafizur Rahman

                        Sylhet Engineering College

                        */

                        #include<bits/stdc++.h>

                        using namespace std;

                        typedef long long ll;

                        const int MAXN = 2e5+ 3;

                        #define ff first

                        #define ss second

                        vector<pair<ll,ll> >ans;

                        int main(){

                                 ios_base::sync_with_stdio(false);

	                cin.tie(0);cout.tie(0);

                            ll T, T1; cin >> T; for(T1 = 1; T1 <= T; T1++){

                        ll i, j, n, m;

                        cin >> n >> m;

                        ans.push_back({0, 0 });

                        for(i = 1; i <= m; i++) {

                            ll u, v; cin >> u >> v; ans.push_back({v, u });

                        }

                        sort(ans.begin(), ans.end());

                        ll f = 0;

                       // for(i = 1; i < ans.size(); i++) cout << ans[i].ff << " " << ans[i].ss  << endl;

                        for(i = 1; i < ans.size(); i++){

                                if((i + 1) >= ans.size()) f = 1;

                            ll node1 = ans[i].ff, ki1 = ans[i].ss;

                            ll node2 = ans[i + 1].ff, ki2 = ans[i + 1].ss;

                            ll node3 = 0;

                            if((i + 2) < ans.size()) node3 = ans[i + 2].ff;

                            ll diff = node2  - node1;

                           // cout << node1 << " " << node2 << " " << node3 << endl;

                          if(node1 == node2){ i++; continue;}

                          if(node2 == node3) {f = 1;i++;break;}

                            if(ki1 == ki2 && diff%2 == 0) {f = 1;i++; break; }

                            if(ki1 !=ki2 && diff%2) {f = 1; i++; break;}

                            i++;

                        }

                        if(f) cout << "NO" << endl;

                        else cout << "YES" << endl;

                        ans.clear();



                            }

                        }

                        /// ALHAMDULILLA