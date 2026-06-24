#include <bits/stdc++.h>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<cstring>
#include<list>
#include<map>
#include<functional>
#include<set>
#include<numeric>
#include<unordered_map>
#include<unordered_set>
#include<iterator>
#include<deque>
#include<string>
#include<queue>
#include<iomanip>
#include<stack>
#include<fstream>
#include<sstream>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>

using namespace std;
    
#define ll long long int    
#define ld long double

ll mod=998244353;
// ll mod=1e7+7;
const ll K=1e5+5;
vector<ll> facdp(K,-1);


#define arr_input(a,n) ll a[n];for(int i=0;i<n;i++){cin>>a[i];}
#define arr_input_and_sum(a,n) ll a[n],sum=0;for(int i=0;i<n;i++){cin>>a[i];sum+=a[i];}





/*** BINARY INDEXED TREE ***/

/*GET SUM OF RANGE FROM 1...to..N OF THAT ELEMENT */
ll getSum(ll BITree[], ll index)
{
    ll sum = 0; // Initialize result
  
    // index in BITree[] is 1 more than the index in arr[]
    index = index + 1;
  
    // Traverse ancestors of BITree[index]
    while (index>0)
    {
        // Add current element of BITree to sum
        sum += BITree[index];
  
        // Move index to parent node in getSum View
        index -= index & (-index);
    }
    return sum;
}

/* UPDATE IN BINARY INDEXED TREE */
void updateBIT(ll BITree[], ll n, ll index, ll val)
{
    // index in BITree[] is 1 more than the index in arr[]
    index = index + 1;
  
    // Traverse all ancestors and add 'val'
    while (index <= n)
    {
    // Add 'val' to current node of BI Tree
    BITree[index] += val;
  
    // Update index to that of parent in update View
    index += index & (-index);
    }
}
/* CONSTRUCT BINARY INDEXED TREE */
ll *constructBITree(ll arr[], ll n)
{
    // Create and initialize BITree[] as 0
    ll *BITree = new ll[n+1];
    for (ll i=1; i<=n; i++)
        BITree[i] = 0;
  
    // Store the actual values in BITree[] using update()
    for (ll i=0; i<n; i++)
        updateBIT(BITree, n, i, arr[i]);
  
    // Uncomment below lines to see contents of BITree[]
    //for (int i=1; i<=n; i++)
    //     cout << BITree[i] << " ";
  
    return BITree;
}

/**********************/

/*****NUMBER OF DIGITS FUNCTION*****/
    int countDigit(long long n)
     {
        if (n==0)
        {
            return 1;
        }
        
        else{
            return floor(log10(n) + 1);
        }
    }



/**********SUM OF DIGITS FUNCTION************/
int sumofdigits(int n){
    int sum=0,l=countDigit(n);
    for (int j = 1; j <=l; j++)
    {
        sum=sum+(n%10);
        n=n/10;
    }
    return sum;
}

/*******FACTORIAL FUNCTION************/
int factorial(int n){
    if (n==0)
    {
       return 1;
    }
    if (facdp[n]!=-1)
    {
        return facdp[n];
    }
    
    return ((n%mod)*(factorial(n-1))%mod)%mod;
}

/***BINARY SEARCH IN ARRAY***/
ll binarySearch(ll arr[], ll l, ll r, ll x)
{
    while (l <= r) {
        int m = l + (r - l) / 2;

         if (arr[m] == x)
            return m;
 
        if (arr[m] < x)
            l = m + 1;
         else
            r = m - 1;
    }
    return -1;
}

/***BINARY SEARCH IN ARRAY OF CHARACTERS***/
ll binarySearchInArrayOfChar(char arr[], ll l, ll r, char x)
{
    while (l <= r) {
        int m = l + (r - l) / 2;

         if (arr[m] == x)
            return m;
 
        if (arr[m] < x)
            l = m + 1;
         else
            r = m - 1;
    }
    return -1;
}

/********BINARY SEARCH IN VECTOR*********/
ll binarySearchInVector(vector<ll> v, ll To_Find)
{
    int lo = 0, hi = v.size() - 1;
    int mid;
    // This below check covers all cases , so need to check
    // for mid=lo-(hi-lo)/2
    while (hi - lo > 1) {
        int mid = (hi + lo) / 2;
        if (v[mid] < To_Find) {
            lo = mid + 1;
        }
        else {
            hi = mid;
        }
    }
    if (v[lo] == To_Find) {
        // cout << "Found"
        //      << " At Index " << lo << endl;
        return lo;
    }
    else if (v[hi] == To_Find) {
        // cout << "Found"
        //      << " At Index " << hi << endl;
        return hi;
    }
    else {
        return -1;
    }
}

/************* UPPER BOUND IN AN ARRAY ******************/
ll lower_bound(ll arr[], ll N, ll X)
{
    int mid;
 
    // Initialise starting index and
    // ending index
    int low = 0;
    int high = N;
 
    // Till low is less than high
    while (low < high) {
        mid = low + (high - low) / 2;
 
        // If X is less than or equal
        // to arr[mid], then find in
        // left subarray
        if (X <= arr[mid]) {
            high = mid;
        }
 
        // If X is greater arr[mid]
        // then find in right subarray
        else {
            low = mid + 1;
        }
    }
   
    // if X is greater than arr[n-1]
    if(low < N && arr[low] < X) {
       low++;
    }
       
    // Return the lower_bound index
    return low;
}

/************* LOWER BOUND IN AN ARRAY ******************/
ll upper_bound(ll arr[], ll N, ll X)
{
    int mid;
 
    // Initialise starting index and
    // ending index
    int low = 0;
    int high = N;
 
    // Till low is less than high
    while (low < high) {
        // Find the middle index
        mid = low + (high - low) / 2;
 
        // If X is greater than or equal
        // to arr[mid] then find
        // in right subarray
        if (X >= arr[mid]) {
            low = mid + 1;
        }
 
        // If X is less than arr[mid]
        // then find in left subarray
        else {
            high = mid;
        }
    }
   
    // if X is greater than arr[n-1]
    if(low < N && arr[low] <= X) {
       low++;
    }
 
    // Return the upper_bound index
    return low;
}


/*****IS POWER OF 2******/
bool isPowerofTwo(long long n)
{
    return (n != 0) && ((n & (n - 1)) == 0);
}

/*****highest power of two less than equal two*********/
long long highestPowerof2(long long N)
{
    // if N is a power of two simply return it
    if (!(N & (N - 1)))
        return N;
    // else set only the most significant bit
    return 0x8000000000000000 >> (__builtin_clzll(N));
}

/******if kth bit is set or not set**********/
int isKthBitSet(ll n, ll k)
{
    if (n & (1 << (k - 1)))
    {
        return 1;
    }
        // cout << "SET";
    else{
        return 0;
    }
        // cout << "NOT SET";
}

/******GCD******/
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);   
}

/*********LCM**********/
ll lcm(ll a, ll b)
{
    ll k=a*b;
    k/=gcd(a,b);
    return k;
}

/******ISPALINDROME*******/
ll isPalindrome(vector<char> str)
{
    // Start from leftmost and rightmost corners of str
    ll l = 0;
    ll h = str.size() - 1;
 
    // Keep comparing characters while they are same
    while (h > l)
    {
        if (str[l++] != str[h--])
        {
            // printf("%s is not a palindrome\n", str);
            return 0;
        }
    }
    return 1;
}

ll isPalindrome(char str[])
{
    // Start from leftmost and rightmost corners of str
    int l = 0;
    int h = strlen(str) - 1;
 
    // Keep comparing characters while they are same
    while (h > l)
    {
        if (str[l++] != str[h--])
        {
            // printf("%s is not a palindrome\n", str);
            return 0;
        }
    }
    // printf("%s is a palindrome\n", str);
    return 1;
}

/*******IsPerfectSquare*******/
bool isPerfectSquare(long double x)
{
    // Find floating point value of
    // square root of x.
    if (x >= 0) {
 
        long long sr = sqrt(x);
         
        // if product of square root
        //is equal, then
        // return T/F
        return (sr * sr == x);
    }
    // else return false if n<0
    return false;
}

/**************CHINESE REMAINDER THEOREM**************/
ll inv(ll a, ll m)
{
    ll m0 = m, t, q;
    ll x0 = 0, x1 = 1;
 
    if (m == 1)
        return 0;
 
    // Apply extended Euclid Algorithm
    while (a > 1) {
        // q is quotient
        q = a / m;
 
        t = m;
 
        // m is remainder now, process same as
        // euclid's algo
        m = a % m, a = t;
 
        t = x0;
 
        x0 = x1 - q * x0;
 
        x1 = t;
    }
 
    // Make x1 positive
    if (x1 < 0)
        x1 += m0;
 
    return x1;
}
 
// k is size of num[] and rem[]. Returns the smallest
// number x such that:
// x % num[0] = rem[0],
// x % num[1] = rem[1],
// ..................
// x % num[k-2] = rem[k-1]
// Assumption: Numbers in num[] are pairwise coprime
// (gcd for every pair is 1)
ll ChineseRemainder(ll num[], ll rem[], ll k)
{
    // Compute product of all numbers
    ll prod = 1;
    for (int i = 0; i < k; i++)
        prod *= num[i];
 
    // Initialize result
    ll result = 0;
 
    // Apply above formula
    for (int i = 0; i < k; i++) {
        ll pp = prod / num[i];
        result += rem[i] * inv(pp, num[i]) * pp;
    }
 
    return result % prod;
}

/***********NEGATIVE/REAL MODULO***************/
ll modulo(ll a,ll modu)
{
    if (a==0)
    {
        return 0;
    }
    else if(a>0)
    {
        return a%modu;
    }
    else{
        ll k=((abs(a)%modu)*(-1))+modu;
        if (k==modu)
        {
            k=0;
        }
        
        return k;
    }
}

/*FIND MAXIMUM GCD OF TO NUMBERS IN AN ARRAY*/
ll findMaxGCD(ll arr[], ll n)
{
    // Computing highest element
    ll high = 0;
    for (int i = 0; i < n; i++)
        high = max(high, arr[i]);
 
    // Array to store the count of divisors
    // i.e. Potential GCDs
    ll divisors[high + 1];

    for (int i = 0; i < high+1; i++)
    {
        divisors[i]=0;
    }
    
 
    // Iterating over every element
    for (int i = 0; i < n; i++)
    {
        // Calculating all the divisors
        for (int j = 1; j <= sqrt(arr[i]); j++)
        {
            // Divisor found
            if (arr[i] % j == 0)
            {
                // Incrementing count for divisor
                divisors[j]++;
 
                // Element/divisor is also a divisor
                // Checking if both divisors are
                // not same
                if (j != arr[i] / j)
                    divisors[arr[i] / j]++;
            }
        }
    }
 
    // Checking the highest potential GCD
    for (int i = high; i >= 1; i--)
     
        // If this divisor can divide at least 2
        // numbers, it is a GCD of at least 1 pair
        if (divisors[i] > 1)
            return i;   

            return 1;
}


/**MILER RABIN PRIMALITY TEST*/

/**************MODULAR EXPONENTIATION*****************/
ll power(ll x,ll y, ll p)
{
    ll res = 1;      // Initialize result
    x = x % p;  // Update x if it is more than or
                // equal to p
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}
 
// This function is called for all k trials. It returns
// false if n is composite and returns true if n is
// probably prime.
// d is an odd number such that  d*2<sup>r</sup> = n-1
// for some r >= 1
bool millerTest(ll d, ll n)
{
    // Pick a random number in [2..n-2]
    // Corner cases make sure that n > 4
    ll a = 2 + rand() % (n - 4);
 
    // Compute a^d % n
    ll x = power(a, d, n);
 
    if (x == 1  || x == n-1)
       return true;
 
    // Keep squaring x while one of the following doesn't
    // happen
    // (i)   d does not reach n-1
    // (ii)  (x^2) % n is not 1
    // (iii) (x^2) % n is not n-1
    while (d != n-1)
    {
        x = (x * x) % n;
        d *= 2;
 
        if (x == 1)      return false;
        if (x == n-1)    return true;
    }
 
    // Return composite
    return false;
}
 
// It returns false if n is composite and returns true if n
// is probably prime.  k is an input parameter that determines
// accuracy level. Higher value of k indicates more accuracy.
bool isPrimeMillerRabin(ll n, ll k)
{
    // Corner cases
    if (n <= 1 || n == 4)  return false;
    if (n <= 3) return true;
 
    // Find r such that n = 2^d * r + 1 for some r >= 1
    ll d = n - 1;
    while (d % 2 == 0)
        d /= 2;
 
    // Iterate given number of 'k' times
    for (int i = 0; i < k; i++)
         if (!millerTest(d, n))
              return false;
 
    return true;
}

/**********BINARY EXPONENTIATION***********/
ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

/*************SIEVE OF ERASTOTHENES**************/
// const ll N=1e5+7;
// ll vis_sieve[N];
// void Sieve(){
//     // memset(vis, true, sizeof(vis));
//     // ll N=1e5+7;
//     // ll vis[N];
//     for (int i = 0; i < N; i++)
//     {
//         vis_sieve[i]=true;
//     }
    
    
//     vis_sieve[0] = vis_sieve[1] = false;
//     for(int i = 4 ; i < N ; i += 2)
//         vis_sieve[i] = false;
//     for(int i = 3 ; i < N / i ; i += 2){
//         if(!vis_sieve[i])continue;
//         for(int j = i * i ; j < N ; j += i + i)
//             vis_sieve[j] = false;
//     }
// }

// vector<ll> primes_sieve;

// void Gen(){
//     for(int i = 2 ; i < N ; ++i)
//         if(vis_sieve[i])
//             primes_sieve.push_back(i);
// }



///Sieve 2.0
/*code of Sieve which stores least prime factor of a number
vector<int> sieve(1e5+1);
void NewSieveOfEratosthenes(){
    for(int i=1;i<1e5+1;i++)
        sieve[i] = -1;
    for(int p=2;p*p<=1e5;p++){
        if(sieve[p] == -1){
            for(int i=2*p;i<=1e5;i+=p){
                sieve[i] = p;
            }
        }
    }
}
*/

ll _mergeSort(ll arr[], ll temp[], ll left, ll right);
ll merge(ll arr[], ll temp[], ll left, ll mid,
          ll right);
 
// This function sorts the
// input array and returns the
// number of inversions in the array
ll mergeSort(ll arr[], ll array_size)
{
    ll temp[array_size];
    return _mergeSort(arr, temp, 0, array_size - 1);
}
 
// An auxiliary recursive function
// that sorts the input array and
// returns the number of inversions in the array.
ll _mergeSort(ll arr[], ll temp[], ll left, ll right)
{
    ll mid, inv_count = 0;
    if (right > left) {
        // Divide the array into two parts and
        // call _mergeSortAndCountInv()
        // for each of the parts
        mid = (right + left) / 2;
 
        // Inversion count will be sum of
        // inversions in left-part, right-part
        // and number of inversions in merging
        inv_count += _mergeSort(arr, temp, left, mid);
        inv_count += _mergeSort(arr, temp, mid + 1, right);
 
        // Merge the two parts
        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}
 
// This function merges two sorted arrays
// and returns inversion count in the arrays.
ll merge(ll arr[], ll temp[], ll left, ll mid,
          ll right)
{
    ll i, j, k;
    ll inv_count = 0;
 
    i = left;
    j = mid;
    k = left;
    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
 
            // this is tricky -- see above
            // explanation/diagram for merge()
            inv_count = inv_count + (mid - i);
        }
    }
 
    // Copy the remaining elements of left subarray
    // (if there are any) to temp
    while (i <= mid - 1)
        temp[k++] = arr[i++];
 
    // Copy the remaining elements of right subarray
    // (if there are any) to temp
    while (j <= right)
        temp[k++] = arr[j++];
 
    // Copy back the merged elements to original array
    for (i = left; i <= right; i++)
        arr[i] = temp[i];
 
    return inv_count;
}

/**********SQUARE ROOT WITH BINAY SEARCH*************/
ll sqrt_bs(ll x) 
{
  ll left = 0, right = 2000000123;
  while (right > left) {
      ll mid = (left + right) / 2;
      
      if (mid * mid > x) right = mid;
      else left = mid + 1;
  }
  return left - 1;
}

/************NCR***************/
ll NcR(ll n, ll r)
{
 
    // p holds the value of n*(n-1)*(n-2)...,
    // k holds the value of r*(r-1)...
    long long p = 1, k = 1;
 
    // C(n, r) == C(n, n-r),
    // choosing the smaller value
    if (n - r < r)
        r = n - r;
 
    if (r != 0) {
        while (r) {
            p *= n;
            k *= r;
 
            // gcd of p, k
            long long m = gcd(p, k);
 
            // dividing by gcd, to simplify
            // product division by their gcd
            // saves from the overflow
            p /= m;
            k /= m;
 
            n--;
            r--;
        }
 
        // k should be simplified to 1
        // as C(n, r) is a natural number
        // (denominator should be 1 ) .
    }
 
    else
        p = 1;
 
    // if our approach is correct p = ans and k =1
    // cout << p << endl;
    return p;
}

/************TO CHECK IF THE NUMBER IS PALIINDROME OR NOT**************/
bool checkPalindrome(ll n)
{
    ll reverse = 0;
    ll temp = n;
    while (temp != 0) {
        reverse = (reverse * 10) + (temp % 10);
        temp = temp / 10;
    }
    return (reverse==n);
}

/***************LONGEST INCREASING SUBSEQUENCE (LIS)**************/
ll longestIncreasingSubsequence(ll arr[], ll n)
{
    vector<ll> temp;
    temp.push_back(arr[0]);
    for(int i=1;i<n;i++)
    {
        if(arr[i]>temp.back())
        {
            temp.push_back(arr[i]);
        }
        else{
            ll ind=lower_bound(temp.begin(),temp.end(),arr[i])-temp.begin();
            temp[ind]=arr[i];
        }
    }
    return temp.size();
}

/***********PAIR COMPARATOR GREATER THAN**********/
bool paircompgrt(pair<ll,ll> &a,pair<ll,ll> &b)
{
    if(a.first==b.first)
    {
        return (a.second < b.second);
    }
    else{
        return (a.first > b.first);
    }
}
/**************PAIR COMPARATOR SMALLER THAN****************/
bool paircompsml(pair<ll,ll> &a,pair<ll,ll> &b)
{
    if(a.first==b.first)
    {
        return (a.second < b.second);
    }
    else{
        return (a.first < b.first);
    }
}

/**************SEGMENT TREE*************/
void build(ll i, ll l, ll h, ll seg[], ll a[])
{
    if (l == h)
    {
        seg[i] = a[l];
        return;
    }
    ll m = (l + h) / 2;
    build(2 * i + 1, l, m, seg, a);
    build(2 * i + 2, m + 1, h, seg, a);
    seg[i] = (seg[2 * i + 1] + seg[2 * i + 2]);
}
ll query(ll i, ll l, ll h, ll low, ll high, ll seg[], ll a[])
{
    if (l <= low && h >= high)
    {
        return seg[i];
    }
    if (high < l || low > h)
    {
        return pow(2,32)-1;
    }
    ll mid = (low + high) / 2;
    return (query(2 * i + 1, l, h, low, mid, seg, a) + query(2 * i + 2, l, h, mid + 1, high, seg, a));
}


int isSubstring(string s1, string s2)
{
    // using find method to check if s1 is
    // a substring of s2
    if (s2.find(s1) != string::npos)
        return s2.find(s1);
    return -1;
}

/*************DISJOINT SET (WITH UNION)****************/
class DisjointSet {
    vector<ll> rank, parent, size; 
public: 
    DisjointSet(ll n) {
        rank.resize(n+1, 0); 
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }

    ll findUPar(ll node) {
        if(node == parent[node])
            return node; 
        return parent[node] = findUPar(parent[node]); 
    }

    void unionByRank(ll u, ll v) {
        ll ulp_u = findUPar(u); 
        ll ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v; 
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u; 
        }
        else {
            parent[ulp_v] = ulp_u; 
            rank[ulp_u]++; 
        }
    }

    void unionBySize(ll u, ll v) {
        ll ulp_u = findUPar(u); 
        ll ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
}; 


int nus(vector<int>& x, vector<int>& s, int n, int k) 
{
    vector<vector<int> > dp(n,vector<int>(k+2, -1));

    for (int remainingChanges = 0; remainingChanges <= k + 1; ++remainingChanges) 
    {
        for (int current = n - 1; current >= 0; --current) 
        {
            if (current == n - 1 && remainingChanges >= 0) 
            {
                dp[current][remainingChanges] = 0;
            } 
            else if (current >= n || remainingChanges < 0) 
            {
                dp[current][remainingChanges] = INT_MAX;
            } 
            else {
                int minTime = INT_MAX;
                for (int i = current + 1; i < n; ++i) {
                    int time = s[current] * abs(x[current] - x[i]);
                    int nextTime = dp[i][remainingChanges - (x[i] < x[current] ? 1 : 0)];
                    if (nextTime == INT_MAX) {
                        continue;
                    }
                    minTime = min(minTime, time + nextTime);
                }
                dp[current][remainingChanges] = minTime;
            }
        }
    }

    return dp[0][k + 1];
}

/*********NEXT GREATER ELEMENT (NGE)************/
void nextLargerElement(ll arr[],ll n)
{
    vector<unordered_map<string,ll> > s;
 
    // iterating over the array
    for (int i = 0; i < n; i++) {
        while (s.size() > 0
               && s[s.size() - 1]["value"] < arr[i]) {
            // updating the array as per the stack top
            unordered_map<string,ll> d = s[s.size() - 1];
            s.pop_back();
            arr[d["ind"]] = arr[i];
        }
        // pushing values to stack
        unordered_map<string,ll> e;
 
        e["value"] = arr[i];
        e["ind"] = i;
        s.push_back(e);
    }
 
    // updating the array as per the stack top
    while (s.size() > 0) {
        unordered_map<string,ll> d = s[s.size() - 1];
        s.pop_back();
        arr[d["ind"]] = -1;
    }
}

/*******PREVIOUS GREATER ELEMENT(PGE)********/
void prevGreater(ll arr[], ll n)
{
    // Create a stack and push index of first element 
    // to it
    stack<ll> s;
    s.push(arr[0]);
     
    // Previous greater for first element is always -1.
    cout << "-1, ";
 
    // Traverse remaining elements
    for (int i = 1; i < n; i++) {
 
        // Pop elements from stack while stack is not empty 
        // and top of stack is smaller than arr[i]. We 
        // always have elements in decreasing order in a 
        // stack.
        while (s.empty() == false && s.top() < arr[i])
            s.pop();
 
        // If stack becomes empty, then no element is greater
        // on left side. Else top of stack is previous
        // greater.
        s.empty() ? cout << "-1, " : cout << s.top() << ", ";
 
        s.push(arr[i]);
    }
}

/**************DECIMAL TO BINARY****************/
void decToBinary(ll n,string& s) 
{ 
    // Size of an integer is assumed to be 32 bits 
    for (int i = 63; i >= 0; i--) { 
        ll k = n >> i; 
        if (k & 1) 
            s+='1'; 
        else
            s+='0';
    } 
} 


/**************BINARY TO DECIMAL*******************/
ll binaryToDecimal(string n)
{
    string num = n;
    ll dec_value = 0;
 
    // Initializing base value to 1, i.e 2^0
    ll base = 1;
 
    ll len = num.length();
    for (int i = len - 1; i >= 0; i--) 
    {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }
 
    return dec_value;
}


/******************** END ******************/

#define startTime clock_t start, end; start = clock();
// #define endTime end = clock(); double time_taken = double(end - start) / double(CLOCKS_PER_SEC); cout << "Time taken by program is : " << fixed  << time_taken << setprecision(5);cout << " sec " << endl;
#define endTime end = clock(); double time_taken = double(end - start) / double(CLOCKS_PER_SEC); cout << "Time taken by program is : " << fixed  << time_taken;cout << " sec " << endl;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    
    // startTime

    /*PROBLEM NO.1*/
    // ll t;
    // cin>>t;

    // while (t--)
    // {
    //     ll n;
    //     cin>>n;

    //     ll a[n],sum=0;
    //     for (int i = 0; i < n; i++)
    //     {
    //         cin>>a[i];
    //         sum+=abs(a[i]);
    //     }
    //     cout<<sum<<endl;
    // }

    /*PROBPEK  NO.2*/
    // ll t;
    // cin>>t;

    // while (t--)
    // {
    //     ll n;
    //     cin>>n;

    //     ll a[n],ans=0,sum=0,count1=0;
    //     for (int i = 0; i < n; i++)
    //     {
    //         cin>>a[i];
    //         sum+=a[i];
    //         if(a[i]%3==1) count1++;
    //     }
    //     if (sum%3==0)
    //     {
    //         cout<<0<<endl;
    //     }
    //     else if(sum%3==1)
    //     {
    //         if(count1) cout<<1<<endl;
    //         else cout<<2<<endl;
    //     }
    //     else 
    //     {
    //         cout<<1<<endl;
    //     }
    // }

    /*PROBLEM NO.3*/
    ll t;
    cin>>t;

    while (t--)
    {
        ll a,b,l;
        cin>>a>>b>>l;

        ll ans=0;
        set<ll> st;
        for (int i = 0; i < 30; i++)
        {
            for (int j = 0; j < 30; j++)
            {
                ll num=pow(a,i)*pow(b,j);
                if (l%num==0)
                {
                    st.insert(l/num);
                }
                
            }
            
        }
        cout<<st.size()<<endl;
        
    }
    
    
    

    
    








    // endTime

    return 0;
}