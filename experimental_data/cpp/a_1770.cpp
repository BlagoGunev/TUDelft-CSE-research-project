/*+-------------------------------------------------------------------------------------+*\

    |                                                                                     |

    |  "Not every hero holds a sword, some just Hold the Door :( " (Hodor) -GameofThrones |

    |                                                                                     |

  \*+-------------------------------------------------------------------------------------+*/

                        /*        MomenAdam (TheMystric)        */

#include <bits/stdc++.h>



#include <sstream>

#include <string>

 

using namespace std;

#define ll long long

#define ull unsigned long long

#define ld = long double

const char nl = '\n';

#define MOD 1000000007

#define fixed(n) cout << fixed << setprecision(n);

#define Num_of_Digits(n) ((int)log10(n) + 1)

#define sz(x) int(x.size())

#define all(x) x.begin(),x.end()

#define rall(x) x.rbegin(),x.rend()

#define pi 3.14159265359

#define GCD(a, b) __gcd(a, b)

#define LCM(a, b) (a * b) / gcd(a, b)

#define ceill(n, m) (((n) / (m)) + ((n) % (m) ? 1 : 0))

#define read(arr,n) for(int i=1;  i<=n  &&  cin>>arr[i]; i++);

#define print(arr,n) for(int i=0;  i<n  &&  cout<<arr[i]<<" "; i++);

#define Check_Time cerr << "Time Taken: " << (float)clock() / CLOCKS_PER_SEC << " Secs\n" ;

#define cin_2d(v,n,m) for(int i = 0; i < n; i++){for(int j = 0; j < m; j++){cin>>v[i][j];}}

#define cout_2d(v,n,m) for(int i = 0; i < n; i++){for(int j = 0; j < m; j++){cout<<v[i][j]<<" ";}cout<<nl;}

#define check_prime(n) bool is_prime = true; if(n==0||n==1){cout<<0;} for (int i=2;i<=sqrt(n);++i){if (n % i == 0){is_prime=false;cout<<is_prime;break;}}

#define cout(v) for (auto &i : v) cout << i<<" ";

#define cin(v) for (auto &i : v) cin >> i ;

#define gcd(a, b) __gcd(a, b)

#define lcm(a, b) (a * b) / gcd(a, b)

 

void MoemenAdam(){

    ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

    #ifndef ONLINE_JUDGE

        freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);

    #endif

}

 

// 2D Vector ------> vector< vector<Type> >v(n, vector<Type> (m));

// v.erase(remove(all(v), value),v.end());

// s.erase(s.begin() + value_indx);

// Mod of bug number like (12876837467823647812693489234 % 5) --> res=0 then multiply res by 10 and add to it first digit take mod of it and so on then takke mod for final res

// GCD allways Max for GCD(n/2,(n%2==0?n:n-1))

// check if char is letter or number isalpha(char)

// transform(all(s), s.begin(), ::tolower);

// upper_bound(all(v),a)-v.begin() --> Pos of Number that Greater than a

// lower_bound(all(v),a)-v.begin() --> Pos of Number that equal to a if a exist or Number that Greater than a

// starting point after shifting m times: j=m%n

// next_permutation(all(s)) return the first (string/number/vector) for the s



void solve(){

    ll n,m;

    cin>>n>>m;

    vector <ll>a(n),b(m);

    

    cin(a);

    cin(b);



    sort(all(a));

    

    for (int i = 0; i < m; i++)

    {

        swap(a[0],b[i]);

        sort(all(a));

    }

    

    ll sum=0;

    for(auto&i:a)sum+=i;

    cout<<sum;

    

}

 

int main(){

    MoemenAdam();

    int TestCases=1;

    cin>>TestCases; 

    while(TestCases--){

        solve();

        cout<<nl;

    }

    Check_Time

    return 0;

}