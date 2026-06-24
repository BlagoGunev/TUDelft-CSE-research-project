#include <bits/stdc++.h>
    
using namespace std;
    
#define SPEED std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
#define ll long long
#define vi vector<int>
#define pi pair<int,int>
#define si set<int>
#define usi unordered_set<int>
#define msi multiset<int>
#define PB push_back
#define MP make_pair
#define rep(i,a,b) for(int i=a;i<b;i++)
#define umi unordered_map<int, int>
#define mmi multimap<int, int>
#define mi map<int, int>
#define rev(i,a,b) for(int i = a;i>=b;i--)
#define ummi unordered_multimap<int, int>
#define vpi vector<pair<int, int> >
#define int long long
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define tolower(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
#define toupper(s) transform(s.begin(), s.end(), s.begin(), ::toupper)
    
const int M = 1e9 + 7;
const int N = 1e5 + 1;
    
void solve();
void findDivisors(int n);
int gcd(int a, int b);
void sieve(int n);
int lcm(int a, int b);
int mexp(int base, int exp);
int highestPowerOf2(int n);
int count_digit(int number);
int sum_digit(int n);
int sum_digit_string(string str);
string dec2bin(int n);
int ceilval(int a, int b);
int binarysrch(int arr[], int n, int x);
int binaryExponentiation(int base, int power, int mod);
    
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                                DON'T MAKE CHANGES BEFORE THIS LINE!
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
    
void solve(){
    int n;
    cin >> n;
    int ans = 0;
    rep(i,1,n+1) {
        if(n%i == 0) {
            ans++;
        }
        else break;
    } 
    cout << ans << endl;
}
    
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                                DON'T MAKE CHANGES AFTER THIS LINE!
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
    
int32_t main()
{
    SPEED
    int t = 1, cse = 0;
    cin >> t;
    while (t--){
        //cse++;
        //cout<<"Case #"<<cse<<": ";
        solve();
    }
    return 0;
}
    
void findDivisors(int n)
{
    int div[N];                   //HERE!!
    memset(div, 0, sizeof div);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j * i <= n; j++)
            div[i * j]++;
    }
}
    
void sieve(int n)   //O(nlog(logn))
{
    vi primes;      //HERE!!
    bool check[N];          //HERE!!
    for(int i = 0; i*i <= n; ++i)
    {
        if(!check[i])
            primes.PB(i);
        for(int j = 0; j < primes.size() && i * primes[j] <= n; ++j)
        {
            check[i * primes[j]] = true;
            if(i % primes[j] == 0)
                break;
        }
    }
}
    
int mpow(int base, int exp, int md = M)
{
    int result = 1;
    base %= md;
    
    if(base==0) return 0;
    
    while(exp>0)
    {
        if(exp&1)
            result = (result*base)%md;
        base = (base*base)%md;
        exp>>=1;
    }
    return result;
}
    
int gcd(int a, int b)
{
    if(b==0)    return a;
    return gcd(b, a%b);
}
    
int lcm(int a, int b)
{
    return a*(b/gcd(a,b));
}
    
int highestPowerOf2(int n)
{
    return (n & (~(n - 1)));
}
    
int count_digit(int number)
{
    return int32_t(log10(number) + 1);
}
    
int sum_digit(int n)
{
    int sum = 0;
    while (n != 0)
    {
        sum = sum + n % 10;
        n = n / 10;
    }
    return sum;
}
    
int sum_digit_string(string str)
{
    int sum = 0;
    for (int i = 0; i < str.length(); i++)
    {
        sum = sum + str[i] - 48;
    }
    return sum;
}
    
string dec2bin(int n)
{
    const int size=sizeof(n)*8;
    string s = "00000000000000000000000000000000";
    for (int a=0;a<32;a++)
    {
        if(n==0)
            return s;
        else
        {
            if(n%2!=0)
                s[31-a]='1';
            n/=2;
        }
    }
    return s;
}
    
int ceilval(int a , int b){
    int x = (a/b) + ((a%b)!=0);
    return x;
}
    
int binarysrch(int arr[], int n,  int x){
    int lo = 0;
    int hi = n-1;
    int mid = (hi+lo)/2;
    while(hi-lo > 1){
        if(arr[mid] < x){
            lo = mid+1;
            mid = (hi+lo)/2;
        }
        else{
            hi = mid;
            mid = (hi+lo)/2;
        }
    }
    if(arr[lo] == x){
        return lo;
    }
    else if(arr[hi] == x){
        return hi;
    }
    else{
        return -1;
    }
}
    
int binaryExponentiation(int base, int power, int mod){
    int ans = 1;
    while(power > 0) {
        if(power & 1) {
            ans = (ans * 1LL * base) % mod;
        }
        base = (base * 1LL * base) % mod;
        power = power >> 1;
    }
    return ans;
}