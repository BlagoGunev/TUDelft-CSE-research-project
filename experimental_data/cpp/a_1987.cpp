#include<bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

/*
string numeFisier="";
ifstream fin(numeFisier+".in"); ofstream fout(numeFisier+".out");
#define cin fin
#define cout fout
*/
#define INIT  ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define mp make_pair
#define pb push_back
#define ft first
#define sc second
#define ll long long
#define pii pair<int, int>
#define count_bits __builtin_popcount
#define int ll




int t, n, m, k, a[300010], q, l, r;






int32_t main(){
    INIT


    cin>>t;
    while(t--){
        cin>>n>>k;
        cout<<(n-1)*(k)+1<<"\n";
    }



    return 0;
}