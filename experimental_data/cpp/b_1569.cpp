#include<bits/stdc++.h>

//#include <ext/pb_ds/assoc_container.hpp>

//#include <ext/pb_ds/tree_policy.hpp>

#define orderedset tree < int, null_type, greater_equal<int>, rb_tree_tag,tree_order_statistics_node_update>

#define ll long long

#define cin(v) for(auto& i : v) cin >> i;

#define cout(v) for(auto& i : v) cout << i << " "; cout << "\n";

#define all(v) v.begin(),v.end()

#define rall(v) v.rbegin(),v.rend()

#define Ceil(n , m) ((n / m) + (n % m ? 1 : 0))

#define sz(s) (long long)(s.size())

const double eps = 1e-9; 

const ll Mod = 1e9 + 7;

using namespace std;

//using namespace __gnu_pbds;

//vector<int> dx = {0,0,1,-1,1,1,-1,-1} , dy = {1,-1,0,0,1,-1,1,-1}; // 8 neg

//vector<int> dx = {0,0,1,-1} , dy = {1,-1,0,0}; // 4 neg

vector<int> dx = {-2,-2,2,2,-1,-1,1,1} , dy = {1,-1,1,-1,2,-2,2,-2}; // king and horse

//vector<int> dx = {-1 , 0 , 0} , dy = {0 , -1 , 1};

void FAST(){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cout << fixed << setprecision(10);

   #ifndef ONLINE_JUDGE

    //freopen("input.in", "r", stdin); freopen("output.txt", "w", stdout);

   #endif

}

struct SortPair {

    bool operator()(const pair<int, int> &p1, const pair<int, int> &p2) const{

        if(p1.first == p2.first) return p1.second < p2.second;

        return p1.first > p2.first;

    }

};

int main(){

    FAST(); 

    int t; cin >> t;

    while(t--){

        int n; cin >> n;

        string s; cin >> s;

        vector<vector<char>> v(n + 5 , vector<char>(n + 5));

        for(int i = 0; i < s.size(); i++){

            if(s[i] == '1'){

                for(int j = 0; j < n; j++){

                    if(i == j) v[i][j] = 'X';

                    else v[i][j] = '=' , v[j][i] = '=';

                } 

            }else{

                for(int j = 0; j < n; j++){

                    if(i == j) v[i][j] = 'X';

                    else if(v[i][j] != '=') v[i][j] = '.' , v[j][i] = '.';

                } 

            }

        }

        bool f = true;

        for(int i = 0; i < s.size(); i++){

            if(s[i] == '2'){

                bool found = false;

                for(int j = 0; j < s.size(); j++){

                    if(s[j] == '2' && i != j){

                        if(v[i][j] == '.'){

                            v[i][j] = '+' , v[j][i] = '-';

                            found = true;

                            break;

                        }

                    }

                }

                if(!found){

                    f = false;

                    break;

                }

            }

        }

        if(!f){
            cout << "NO\n";

            continue;
        }

        

        cout << "YES\n";

        for(int i = 0; i < n; i++){

            for(int j = 0; j < n; j++){

                if(v[i][j] == '.') v[i][j] = '+' , v[j][i] = '-';

            }

        }

        for(int i = 0; i < n; i++){

            for(int j = 0; j < n; j++){

                cout << v[i][j];

            }

            cout << "\n";

        }

    }    



    

    

    return 0;

}