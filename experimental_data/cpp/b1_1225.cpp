#include<bits/stdc++.h>
            using namespace std;

            #define FOR(i,a,b) for (int i = (a); i < (b); i++)
            #define rep(i,n) FOR(i,0,n)
            #define RFOR(i,b,a) for (int i = (b)-1; i >= (a); i--)
            #define ITER(it,a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
            #define FILL(a,value) memset(a, value, sizeof(a))

            #define SZ(a) (int)a.size()
            #define ALL(a) a.begin(), a.end()
            #define PB emplace_back
            #define P push
            #define IN insert
            #define ER erase

            #define MP make_pair
            #define sc second
            #define fs first

            typedef long long LL;
            typedef vector<int> VI;
            typedef vector<LL>VL;
            typedef vector <bool >VB;
            typedef vector<vector<int>>WI;
            typedef vector<vector<LL>>WL;
            typedef pair<int, int> PII;
            typedef pair<double, double> PDD;

            const double PI = acos(-1.0);
            const int INF = int(1e9);
            const LL LINF = LL(1e18);
            const int MAS = int(1e6+10);
            const double EPS = 1e-7;
            const LL MAX = 4294967296;
            const LL MOD =LL(1e9+7);


           // vector<int >used(MAS);
            vector<int> v ;
            int main()
            {
                ios_base::sync_with_stdio(false);
                cin.tie(0);
                cout.tie(0);

                 int t;
                 cin >> t;
                 while(t--)
                 {
                     int n,k,d;
                     cin >> n >> k >> d;
                     rep(i,n)
                     {
                         int x;
                         cin >> x;
                         v.PB(x);
                     }
                     int mn = INF;
                     int cur =0 ;
                     int ok = 1;
                     //rep(i,n)
                     //{
                       //  cout << v[i] <<" ";
                     //}
                    // cout << endl;
                     rep(i,n)
                     {
                         vector<int >used(101);
                         FOR(j,i,i+d)
                         {
                             if(j >=n)
                             {
                                 ok = -1;
                                 break;
                             }
                         //     cout << v[j] << " " << used[v[j]] << " "  << j  << endl;
                              if(used[v[j]] != 1)
                              {
                                  used[v[j]] =1;
                                  cur++;
                              }
                         }
                       //  cout << cur << endl;
                         if(ok == -1)
                         {
                             break;
                         }
                         mn =min(mn,cur);
                         //cout << cur << " " << mn << " ";
                         cur=0;
                      //   used.clear();
                     }
                     //used.clear();
                     v.clear();
                     cout << mn << endl;
                 }

            }