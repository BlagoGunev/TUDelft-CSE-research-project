/*



 Author : Catalyst71

 < While there is a code, there is a bug > ¯\_(ツ)_/¯



*/



#include<bits/stdc++.h>

//#include<C:\Users\itsar\OneDrive\Desktop\0\CODES\HEADERS\debug.cpp>

typedef long long ll;

typedef unsigned long long ull;

using namespace std;

#define FIO ios::sync_with_stdio(0); cin.tie(0); 

#define pb push_back

#define eb emplace_back

#define all(x) (x).begin(), (x).end()

#define rall(x) (x).rbegin(), (x).rend()

#define nn "\n"

#define sp " "

#define ff(i,start,n) for(i=start;i<=n;i++)

#define fx(s) for(auto &x:s)

#define check(i) cout << i << endl

#define EPS 1e-10

#define frs first

#define sec second

#define mp make_pair

#define vl vector<ll>

#define vi vector<int>

#define dbp cout << " = Working = " << endl;

#define aff cout <<  "YES"   << endl;

#define neg cout << "NO" <<endl;

#define inn(n) scanf("%d", &n);

#define innm(n,m) scanf("%d%d",&n,&m);

#define outnn(n) printf("%d\n",n);

#define outsn(n) printf("%d ",n);

#define R return;

#define ffin(n) for(int i=0;i<(n);i++)

#define ffjn(n) for(int j=0;j<(n);j++)

#define ffkn(n) for(int k=0;k<(n);k++)

#define FRW {freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);}

int dx[8] = {1, -1, 0,  0, 1,  1, -1, -1};

int dy[8] = {0,  0, 1, -1, 1, -1,  1, -1};



//bool isSquare(ll x){ll sq=sqrt(x);return sq*sq==x;}

//long long int gcd(long long int a , long long int b){if(a%b==0)return b;if(b==0)return a;return gcd(b,a%b);}

//long long int lcm(long long int a , long long int b){ return (a / gcd(a, b)) * b;}

//int isprime(long long n){if(n==1)return 0;if(n==2||n==3)return 1;if(n % 2 == 0) return 0;for(long long i = 2; i * i <= n; i++){if(n % i == 0){return 0;}}return 1;}

//int egcd(int a,int b,int &x,int &y){if(b==0){x=1;y=0;return a;}int x1,y1;int d=egcd(b,a%b,x1,y1);x=y1;y=x1-y1*(a/b);return d;}

//int _compare_double(double a, double b){return fabs(a-b)<=EPS? 0: a<b? -1:1;/*0 for equal 1 if a>b*/}

/*ll bs_sqrt(ll x){

    ll left=1,right = 2000000123;while (right>left){ll mid = (left+right)/2;if(mid*mid > x)right = mid;else left = mid+1;}

    return left-1;

}*/

/*struct vobon

{

    int roll,age;

    string name ;

};*/











void solve()

{

    /* check FIO if not using C IO */

    ll n,m;

    cin >> m >> n;

    vl v(n),temp,nums, anv;

    fx(v) cin >> x;

    if(n==1){

        cout << "Yes\n";

        return;

    }



    anv = v;

    for(ll i= 0 ; i < n-1; i++){

        ll num = v[i+1]-v[i];

        nums.eb(num);

    }

    temp = nums;

    sort(all(temp));

    if(temp != nums){

        cout << "No\n";

        return;

    }

    ll maxN = nums[0];

    ll targetSum = v[0];

    ll maxOp = m-(n-1);

    if(maxN * maxOp >= targetSum){

        cout << "Yes\n";

    } else cout << "No\n";



    

}











int main()

{ 

    FIO 

    #ifndef ONLINE_JUDGE

    //FRW

    #endif



//auto  START = std::chrono::steady_clock::now();

int t = 1 ;

cin >> t ;

while (t--)

{

solve();

}

//auto  END = std::chrono::steady_clock::now();

//double MMM = double(std::chrono::duration_cast <std::chrono::nanoseconds>(END-START).count());

//cout<<"Shomoy gese : "<<MMM/1e9<<" sec"<<endl;

return 0 ;

}