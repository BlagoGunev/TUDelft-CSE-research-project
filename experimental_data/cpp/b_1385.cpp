#include <bits/stdc++.h>
         
    using namespace std;
                 
    #define pb push_back
    #define ll long long
    #define mp make_pair
    #define MOD 1000000007
    #define MAX 100000000
    #define MIN -1000000000
    #define LLINF 0x3f3f3f3f3f3f    
    #define INF 0x3f3f3f3f
    #define MAXN 200200
    typedef vector<pair<int,int>> vii;
    typedef pair<int, int> pii;

    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int t;
        cin >> t;
        while(t--){ 
            int n;
            cin >> n;
            vector<int> v(2*n);
            vector<int> freq(1000, 0);
            vector<int> res;
            for(int i = 0; i < 2*n; ++i){ 
                cin >> v[i];
            }
            for(int i = 0; i < 2*n; ++i){ 
                if(freq[v[i]] > 0){    
                    continue;
                }else{  
                    res.pb(v[i]); 
                    freq[v[i]]++;  
                }
            }
            for(int i = 0; i < (int)res.size(); ++i){   
                cout << res[i] << " ";
            }
            cout << endl;
        }
        return 0;
    }