#include<bits/stdc++.h>



using namespace std;

 

#define all(x) x.begin() , x.end()

#define pii pair<int, int>

#define piii pair<int, pii>

#define pll pair<ll, ll>

#define plll pair<ll, pll>

#define pb push_back

#define qb pop_back

#define F first

#define S second

#define wall cerr<<"--------------------------------------"<<endl

 

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

 

typedef long long ll;

typedef double db;

 

const ll INF = 1e9;

const ll maxn = 2e5 + 10;

const ll mod = 1e9 + 7;



ll _ , n , m , k , l , r , a[maxn] , b[maxn] , x , y , z , ans , pre[maxn][26];

string s , t;

vector<ll> ve;

set<ll> se;



int main()

{

        ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

        cin>>s>>_;

        n = s.size();

        for(int i=1; i<=n; i++){

                for(int j=0; j<26; j++){

                        pre[i][j] = pre[i-1][j];

                }

                x = s[i-1] - 'a';

                pre[i][x]++;

        }

        while(_--){

                cin>>l>>r;

                if(l == r){

                        cout<<"YES\n";

                        continue;

                }

                int dif = 0;

                for(int i=0; i<26; i++){

                        if(pre[r][i] - pre[l-1][i] > 0){

                                dif++;

                        }

                }

                if(dif >= 3){

                        cout<<"YES\n";

                        continue;

                }

                if(s[l-1] != s[r-1]){

                        cout<<"YES\n";

                        continue;

                }

                cout<<"NO\n";

        }

        return 0;

}

/*

by

                        .         .--. .--. .--.

                      .'|         |__| |__| |__|

                     <  |         .--. .--. .--.

    __                | |         |  | |  | |  |

 .:--.'.          _   | | .'''-.  |  | |  | |  |

/ |   \ |       .' |  | |/.'''. \ |  | |  | |  |

`" __ | |      .   | /|  /    | | |  | |  | |  |

 .'.''| |    .'.'| |//| |     | | |__| |__| |__|

/ /   | |_ .'.'.-'  / | |     | |

\ \._,\ '/ .'   \_.'  | '.    | '.

 --'  "             '---'   '---

 

*/