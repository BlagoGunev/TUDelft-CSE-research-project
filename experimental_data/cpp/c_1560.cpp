/*

ID:

LANG: C++

PROB: ride

*/



#include<bits/stdc++.h>

using namespace std;





#define int                             long long

#define YES                             printf("YES\n");

#define Yes                             printf("Yes\n");

#define yes                             printf("yes\n");

#define NO                              printf("NO\n");

#define No                              printf("No\n");

#define no                              printf("no\n");

#define pb                              push_back

#define all(x)                          (x).begin(), (x).end()

#define FastIO                          ios::sync_with_stdio(false);cin.tie(0);

#define clk                             cerr<<endl<<(float)clock()/(float)CLOCKS_PER_SEC<<" sec"<<endl;

#define IO                              freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

#define endll                           printf("\n")

#define scan(a)                         scanf("%lld", &a)

#define print(a)                        printf("%lld\n", a)

//#define printArr(vector<int> &v)        {for(int i=0; i<v.size(); i++) printf("%lld ", v[i]); endll;}

//#define scanArr(vector<int> &v)         for(int i=0; i<v.size(); i++) scanf("%lld", &v[i]);

#define gcd(a, b)                       __gcd(a, b)

#define lcm(a,b)                        (a/gcd(a,b)*b)

//#include <ext/pb_ds/assoc_container.hpp>

//#include <ext/pb_ds/tree_policy.hpp>

//#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>

//#define ordered_set tree<int, null_type, less_equal, rb_tree_tag, tree_order_statistics_node_update>

//using namespace __gnu_pbds;





int  comp_double(double a, double b)    {if(fabs(a-b) <= 1e-10)return 0;return a < b ? -1 : 1;}

void setIO(string s)                    {freopen((s + ".in").c_str(), "r", stdin);freopen((s + ".out").c_str(), "w", stdout);}

int dx[8]                               = {2, 2, -2, -2, 1, 1, -1, -1};

int dy[8]                               = {1, -1, 1, -1, -2, 2, 2, -2};



//int dx[]={+1,-1,+0,-0}

//int dy[]={+0,-0,+1,-1}



//memset(memo, -1, sizeof memo);

// index = (index + 1) % n; // index++; if (index >= n) index = 0;

// index = (index + n - 1) % n; // index--; if (index < 0) index = n - 1;

// int ans = (int)((double)d + 0.5); // for rounding to nearest integer

//h = sqrt(x2+y2) double hypot(double x, double y)

//getline(cin >> ws, s2); // eat whitespace

    vector<int> bit, num;

    int n;

class NumArray {

public:





    NumArray(vector<int>& nums) {



        n = nums.size();

        num.resize(n+1);

        for(int i=0; i<n; i++)

            num[i+1] = nums[i];



        bit.resize(n+1);

        for(int i=1; i<=n; i++){

            update(i-1, num[i]);

        }

    }



    void update(int in, int val) {

        in++;

        int u = num[in];

        num[in] = val;

        while(in <= n){

            bit[in] += (val - u);

            in += in & (-in);

        }

    }

    int sum (int in){

        int s = 0;

        while(in > 0){

            s += bit[in];

            in -= in & (-in);

        }

        return s;

    }

    int sumRange(int left, int right) {

        return sum(right+1) - sum(left);

    }

};

void solve(){

    int n;

    cin >> n ;

    int r = sqrt(n);

    if(r*r == n){

        cout << r << " " << 1 << endl;

        return;

    }

    int val = r*r;

    for(int i=1; i<=r+1; i++){

        val++;

        if(val == n) {

            cout << i << " " << r+1 << endl;

            return;

        }

    }

    for(int i = r; i>=1; i--){

        val++;

        if(val == n) {

            cout << r+1 << " " << i << endl;

            return;

        }

    }

}

signed main(){

    //IO

    //FastIO

    //setIO("ride");



    int t; scan(t); while(t--)

    solve();





    return 0;

}