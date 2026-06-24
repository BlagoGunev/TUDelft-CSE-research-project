#include<iostream>

#include<cstring>

#include<vector>

#include<set>

#include<map>

#include<queue>

#include<stack>

#include<cstdio>

#include<string>

#include<utility>

#include<cmath>



using namespace std;



#define fi first

#define sc second

#define endl '\n'

#define pb push_back

#define mem0(a) memset(a,0,sizeof(a))

#define mem1(a) memset(a,-1,sizeof(a))

#define meminf(a) memset(a,0x3f,sizeof(a))

#define yes cout<<"Yes"<<endl

#define no cout<<"No"<<endl

#define debug(x) cout<<"----Line#"<<x<<"----"<<endl

typedef long long ll;

typedef double db;

typedef pair<int, int> PII;

typedef pair<char, char> PCC;

typedef pair<int, string> PIS;

const int INF = 0x3f3f3f3f;

const double eps = 1e-6;

const ll mod = 1e9 + 7;

ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}

//head



const int N = 1e5 + 10;

int n;

int a[N];



void solve() {

    cin >> n;

    ll res = 1;

    for (int i = 1; i <= n; i ++) {

        cin >> a[i];

        res *= a[i];

        //cout << i << ' ' << res << endl;

    }

    //cout << res << endl;

    res += (n - 1);

    //cout << res << endl;

    cout << res * 2022 << endl;

    return ;

}



int main() {

    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int T = 1; 

    cin >> T;

    while (T --){

        solve();

    }

    return 0;

}