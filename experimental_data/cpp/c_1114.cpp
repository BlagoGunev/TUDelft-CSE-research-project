/**
*    Username : adhoc_king
*    Name : adhoc_king
*    Institute : IIT Bombay
*/

// #include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <string>
// #include <deque>
// #include <queue>
// #include <array>
// #include <ctime>
// #include <list>
#include <map>
#include <set>
// #include <cassert>
// #include <complex>
// #include <sstream>
// #include <forward_list>
// #include <unordered_set>
// #include <unordered_map>
using namespace std;

#define pb push_back
#define mp make_pair
#define scani(n) scanf("%d",&n);
#define EPS 1e-9
#define FOR(i,n) for(int i=0; i<n; i++)
#define X first
#define Y second
#define arrinput for(int i=0; i<n; i++) cin>>arr[i];
#define arrsum for(int i=0; i<n; i++) sum+=arr[i];
#define for0(i,n) for(int i=0; i<n; i++)
#define for1(i,n) for(int i=1; i<=n; i++)
#define forr(i,n) for(int i=n-1; i>=0; i--)

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int MOD = 1e9+7;
const int n_ = 1e5+1000;
const long double PI = acos(-1.0);

ll gcd (ll a, ll b) {return ( a ? gcd(b%a, a) : b );}
ll power(ll a, ll n) {ll p = 1;while (n > 0) {if(n%2) {p = p * a;} n >>= 1; a *= a;} return p;}
ll power(ll a, ll n, ll mod) {ll p = 1;while (n > 0) {if(n%2) {p = p * a; p %= mod;} n >>= 1; a *= a; a %= mod;} return p % mod;}

// void binary_search(ll a, ll b, ll flag) {
//     ll la, lb, ha, hb, ma, mb;
//     if(flag) {
//         cout<<"R";
//         la = 1; lb = 1;
//         ha = 1; hb = 0;
//     }
//     else {
//         cout<<"L";
//         la = 0; lb = 1;
//         ha = 1; hb = 1;
//     }
//     while(la*hb < lb*ha) {
//         ma = (la+ha);
//         mb = (lb+hb);
//         // cout<<" "<<la<<" "<<lb<<" "<<ma<<" "<<mb<<" "<<ha<<" "<<hb<<"\n";
//         if(a*mb == b*ma) break;
//         if(a*mb < b*ma) {
//             cout<<"L";
//             ha = ma;
//             hb = mb;
//         }
//         else {
//             cout<<"R";
//             la = ma;
//             lb = mb;
//         }
//     }
// }

bool vowel(char ch) {
    if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') return true;
    else return false;
}

// void sieveOfEratosthenes(ll N, ll s[]) 
// { 
//     // Create a boolean array "prime[0..n]" and 
//     // initialize all entries in it as false. 
//     vector <bool> prime(N+1, false); 
  
//     // Initializing smallest factor equal to 2 
//     // for all the even numbers 
//     for (ll i=2; i<=N; i+=2) 
//         s[i] = 2; 
  
//     // For odd numbers less then equal to n 
//     for (ll i=3; i<=N; i+=2) 
//     { 
//         if (prime[i] == false) 
//         { 
//             // s(i) for a prime is the number itself 
//             s[i] = i; 
  
//             // For all multiples of current prime number 
//             for (ll j=i; j*i<=N; j+=2) 
//             { 
//                 if (prime[i*j] == false) 
//                 { 
//                     prime[i*j] = true; 
  
//                     // i is the smallest prime factor for 
//                     // number "i*j". 
//                     s[i*j] = i; 
//                 } 
//             } 
//         } 
//     } 
// } 

vector<pair<ll, ll>> vec;
  
// Function to generate prime factors and its power 
void generatePrimeFactors(ll N) 
{ 
    ll c = 0;
    ll m = N;
    if(N%2 == 0) {
        while(N%2 == 0) {
            c++;
            N /= 2;
        }
        vec.push_back(mp(2, c));
    }

    for (ll i = 3; i <= sqrt(m+100); i = i+2) 
    { 
        // While i divides n, print i and divide n 
        if (N%i == 0) 
        { 
            c = 0;
            while(N%i == 0) {
                c++;
                N /= i;
            }
            vec.push_back(mp(i, c));
        } 
    } 

    if(N>2) vec.push_back(mp(N, 1));

    // // s[i] is going to store smallest prime factor 
    // // of i. 
    // ll s[N+1]; 
  
    // // Filling values in s[] using sieve 
    // sieveOfEratosthenes(N, s); 
  
    // // printf("Factor Power\n"); 
  
    // ll curr = s[N];  // Current prime factor of N 
    // ll cnt = 1;   // Power of current prime factor 
  
    // // Printing prime factors and their powers 
    // while (N > 1) 
    // { 
    //     N /= s[N]; 
  
    //     // N is now N/s[N].  If new N als has smallest 
    //     // prime factor as curr, increment power 
    //     if (curr == s[N]) 
    //     { 
    //         cnt++; 
    //         continue; 
    //     } 
    //     vec.push_back(mp(curr, cnt));
    //     // printf("%d\t%d\n", curr, cnt); 
  
    //     // Update current prime factor as s[N] and 
    //     // initializing count as 1. 
    //     curr = s[N]; 
    //     cnt = 1; 
    // } 
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, b, c, x, sum = 0, y, z=0;
    cin>>n>>b;

    generatePrimeFactors(b);
    ll min = 5e18;
    // cout<<min<<"\n";

    // for0(i,vec.size()) cout<<vec[i].first<<" "<<vec[i].second<<"\n";
    for0(i,vec.size()) {
        sum = 0;
        x = vec[i].first;
        y = x;
        z = vec[i].second;
        c = n;
        while(c > 0) {
            c /= x;
            sum += c;
        }
        sum /= z;
        if(sum < min) min = sum;
    }
    cout<<min;

    // x = maxPrimeFactors(b);
    // y = x;
    // c = b;
    // while(c>0) {
    //     if(c%x) break;
    //     c /= x;
    //     if(c<1) break;
    //     z++;
    // }
    // // cout<<z<<" ";
    // while((n/y)>0) {
    //     sum += (n/y);
    //     y *= x;
    // }
    // cout<<sum/z;

    return 0;
}