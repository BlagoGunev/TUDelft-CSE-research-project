//  ll arr[100005];
// ll seg[4*100005];
// ll lazy[4*100005];
// void build(int index,int low,int high){
//     if(high==low) {
//         seg[index] = arr[low];
//         return ;
//     }
//     int mid=(low+high)/2;
//     build(2*index+1,low,mid);
//     build(2*index+2,mid+1,high);
//     seg[index]=seg[2*index+1]+seg[2*index+2];
//     return ;
// }
// int query(int index,int low,int high, int l, int h){
//     if(low>=l&&high<=h)
//         return seg[index];
//     if(high<l||low>h) 
//         return 0;
//     int mid=(low+high)/2;
//     int left=query(2*index+1,low ,mid,l,h);
//     int right=query(2*index+2,mid+1,high,l,h);
//     return left+right;
// }
// void update(int index, int low, int high, int node, int val){
//     if(low == high){
//         seg[index] = val;
//         return ;
//     }
//     int mid = (low + high)/2;
//     int i = 2*index + 1;
//     int j = 2*index + 2;
//     if(node >= low && node <= mid)
//         update(i, low, mid, node, val);
//     else
//         update(j, mid+1, high, node, val);
//     seg[index]=seg[i]+seg[j];
//     return ;
// }
// void rangeUpdate(int ind, int low, int high, int l,int r,int val){
//     if(lazy[ind]!=0){
//         seg[ind]+=(high-low+1)*lazy[ind];
//         arr[ind]+=(high-low+1)*lazy[ind];
//         if(low!=high){
//             lazy[2*ind+1]+=lazy[ind];
//             lazy[2*ind+2]+=lazy[ind];
//         }
//         lazy[ind]=0;
//     }
//     if(r<low||l>high||low>high) return;
//     if(low>=l&&high<=r){
//         seg[ind]+=(high-low+1)*val;
//         if(low!=high){
//             lazy[2*ind+1]+=lazy[ind];
//             lazy[2*ind+2]+=lazy[ind];
//         }
//         return;
//     }
//     int mid=(low+high)>>1;
//     rangeUpdate(2*ind+1,low,mid,l,r,val);
//     rangeUpdate(2*ind+2,mid+1,high,l,r,val);
//     seg[ind]=seg[2*ind+1]+seg[2*ind+2];
// }
// void mat_mul(ll arr[2][2], ll arr2[2][2])
// {
//     ll e = arr[0][0] * arr2[0][0] + arr[0][1] * arr2[1][0];
//     ll f = arr[0][0] * arr2[0][1] + arr[0][1] * arr2[1][1];
//     ll g = arr[1][0] * arr2[0][0] + arr[1][1] * arr2[1][0];
//     ll h = arr[1][0] * arr2[0][1] + arr[1][1] * arr2[1][1];
//     arr[0][0] = e;
//     arr[0][1] = f;
//     arr[1][0] = g;
//     arr[1][1] = h;
// }
// void mat_power(ll F[2][2], ll n)
// {
//     if (n == 0 || n == 1)
//         return;
//     ll M[2][2] = {{1, 1}, {1, 0}};
//     power(F, n / 2);
//     multiply(F, F);
//     if (n % 2 != 0)
//         multiply(F, M);
// }

// ll fibo(ll n)
// {
//     ll F[2][2] = {{1, 1}, {1, 0}};
//     if (n == 0)
//         return 0;
//     power(F, n - 1);
//     return F[0][0];
// }

// // struct structure_name {
// //     data_type member_name1;
// //     data_type member_name1;
// // };

// ll gcd(ll a, ll b)
// {
//     if (a == 1 || b == 1)
//         return 1;
//     if (a == 0)
//         return b;
//     if (b == 0)
//         return a;
//     else
//     {
//         if (a >= b)
//             return gcd(a % b, b);
//         else
//             return gcd(a, b % a);
//     }
// }

// ll modInverse(ll A, ll M)
// {
//     for (ll X = 1; X < M; X++)
//         if (((A % M) * (X % M)) % M == 1)
//             return X;
// }

// ll power(ll x, ll y, ll p){
//     // Initialize answer
//     ll res = 1;
//     // Check till the number becomes zero
//     while (y > 0)
//     {
//         // If y is odd, multiply x with result
//         if (y % 2 == 1)
//             res = (res * x);
//             res = res %p;
//         // y = y/2
//         y = y >> 1;
//         // Change x to x^2
//         x = (x * x);
//         x = x%p;
//     }
//     return res % p;
// }

// int binarySearch(int arr[], int l, int r, int x)
// {
//     while (l <= r) {
//         int m = l + (r - l) / 2;
//
//         // Check if x is present at mid
//         if (arr[m] == x)
//             return m;
//
//         // If x greater, ignore left half
//         if (arr[m] < x)
//             l = m + 1;
// 
//         // If x is smaller, ignore right half
//         else
//             r = m - 1;
//     }
// 
//     // If we reach here, then element was not present
//     return -1;
// }
 
// vector<int> bfsOfGraph(int V, vector<int> adj[])
// {
//     int vis[V] = {0};
//     vis[0] = 1;
//     queue<int> q;
//     // push the initial starting node
//     q.push(0);
//     vector<int> bfs;
//     // iterate till the queue is empty
//     while (!q.empty())
//     {
//         // get the topmost element in the queue
//         int node = q.front();
//         q.pop();
//         bfs.push_back(node);
//         // traverse for all its neighbours
//         for (auto it : adj[node])
//         {
//             // if the neighbour has previously not been visited,
//             // store in Q and mark as visited
//             if (!vis[it])
//             {
//                 vis[it] = 1;
//                 q.push(it);
//             }
//         }
//     }
//     return bfs;
// }

// void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls)
// {
//     vis[node] = 1;
//     ls.push_back(node);
//     // traverse all its neighbours
//     for (auto it : adj[node])
//     {
//         // if the neighbour is not visited
//         if (!vis[it])
//         {
//             dfs(it, adj, vis, ls);
//         }
//     }
// }

// bool sortbysecdesc(const pair<int, int> &a,
//                    const pair<int, int> &b)
// {
//     return a.first > b.first;
// }
//long long nCr(int n, int r) {
//return std::tgamma(n + 1) / (std::tgamma(r + 1) * std::tgamma(n - r + 1));
//}
// const ll N = 1e6;
// vector<bool> prime(N + 1, true);
// void SieveOfEratosthenes(ll n)
// {
//     for (ll p = 2; p * p <= n; p++)
//     {
//         if (prime[p] == true)
//         {
//             for (int i = p * p; i <= n; i += p)
//                 prime[i] = false;
//         }
//     }
// }

// cout<<flush;

// next_permutation(arr.begin(),arr.end());

#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include <bits/debug.h>
#endif
using namespace std;

typedef long long int ll;
typedef set<long long> sll;
typedef vector<long long> vll;
typedef pair<long long, long long> pll;
typedef vector<pair<long long, long long>> vpll;
typedef vector<vector<long long>> vvll;
typedef map <long long,long long> mll;
#define ll long long int
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define fori(i, s, e) for (ll i = s; i < e; i++)
#define ford(i, s, e) for (ll i = e; i >= s; i--)
#define py cout << "YES" << endl
#define pn cout << "NO" << endl

void solve()
{
    // string str;
    // getline(cin,str);
    ll n;
    cin >> n;
    cout<<n + n*(n+1)+2<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    cin >> tc;
    while (tc--)
    {
        solve();
        // cout << endl;
    }
    return 0;
}