#include <bits/stdc++.h>

using namespace std;

 

#define int long long int

#define endl "\n"

#define PI pair<int, int>

#define Pb push_back

#define VI vector<int>

#define VVI vector<VI>

#define forp(i,a,b) for(int i=a;i<b;i++)

int ceil(int a, int b) { return (a + b - 1)/b; }

const int MOD = 1e9 + 7;

 

#define bug(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>

    void __f(const char* name, Arg1&& arg1) { cout << name << " = " << arg1 << endl; }

template <typename Arg1, typename... Args>

    void __f( const char* names, Arg1&& arg1, Args&&... args) {const char* comma = strchr(names + 1, ','); cout.write(names, comma - names) << " = " << arg1 << " "; __f(comma + 1, args...); }

template<typename T> inline void printlist(T& a) { for(auto i : a) cout << i << " "; cout << '\n'; }



int power(int x,int y) { 

    if (y == 0) return 1;

    int p =power(x, y / 2);

    if (y % 2 == 0) return p * p % MOD; 

    else return x * p * p % MOD; 

}

 

 // https://www.geeksforgeeks.org/sum-xor-possible-subsets/

void solve()

{

   int n,m;

   cin >> n >> m;

   int Or = 0;

   while(m--)

   {

       int l,r,x;

       cin >> l >> r >> x;

       Or |= x;

   }

   cout << (power(2,n-1)*Or)%MOD << endl;

}

 

signed main()

{

ios_base::sync_with_stdio(false);

cin.tie(nullptr);

cout.tie(nullptr);



int t=1;

cin >> t;

while(t--)

solve();

 

return 0;

}