#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

/*
    ░██████╗░█████╗░███╗░░██╗░█████╗░██████╗░
    ██╔════╝██╔══██╗████╗░██║██╔══██╗██╔══██╗
    ╚█████╗░███████║██╔██╗██║███████║██║░░██║
    ░╚═══██╗██╔══██║██║╚████║██╔══██║██║░░██║
    ██████╔╝██║░░██║██║░╚███║██║░░██║██████╔╝
    ╚═════╝░╚═╝░░╚═╝╚═╝░░╚══╝╚═╝░░╚═╝╚═════╝░
*/

using namespace std;
using namespace __gnu_pbds;

typedef vector <int> vi;
typedef vector <long long> vl;

#define ordered_set(DT) tree<DT, null_type,less<DT>, rb_tree_tag,tree_order_statistics_node_update> //less_equal
#define what_here(x) find_by_order(x) // returns iterator
#define where_is(x) order_of_key(x) // get me idx of lower_bound
#define to_decimal(bin) stoll(bin, nullptr, 2)
#define cin(vec) for(auto& iii : vec) cin >> iii
#define cin_2d(vec, n, m) for(int iii = 0; iii < n; iii++) for(int jjj = 0; jjj < m && cin >> vec[iii][jjj]; jjj++);
#define cout(vec) for(auto& iii : vec) cout << iii << " "; cout << "\n";
#define cout_2d(vec, n, m) for(int iii = 0; iii < n; iii++, cout << "\n") for(int jjj = 0; jjj < m && cout << vec[iii][jjj] << " "; jjj++);
#define cout_map(mp) for(auto& [fff, sss] : mp) cout << fff << "  " << sss << "\n";
#define ll long long
#define ull unsigned long long
#define Num_of_Digits(n) ((int)log10(n) + 1)
#define ceil(n, m) (((n) / (m)) + ((n) % (m) ? 1 : 0))
#define Time cerr << "Time Taken: " << (float)clock() / CLOCKS_PER_SEC << " Secs" << "\n";
#define fixed(n) fixed << setprecision(n)
#define dg(x) cout << #x << " : " << (x) << "\n";
#define bla(s, x) cout << #s << " : " << (x) << "\n";
#define sz(x) int(x.size())
#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define el "\n"
#define sp " "
#define ff first
#define ss second
#define yes cout << "YES"
#define no cout << "NO"
#define yesl cout << "YES\n"
#define nol cout << "NO\n"
#define er cout << "Error Here!!\n"
#define OO 2147483647
#define _OO -2147483648
#define MOD 1000000007
#define PI acos(-1.0)
#define pow(x, y) (ll)pow(x, y)

// count(all(s), 'A');
//count number in arr = count(arr, arr + size , number)
// s.erase(remove(all(s), 'A'), s.end())
// return sum of the arr = accumulate(arr, arr + size, sum)
// transform(all(s), s.begin(), ::tolower); //lowercase
void Omar_Sanad()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("##.in", "r", stdin);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
    #endif
}



/** @remark (CORNER) test case (0, 1) */
void SOLVE()
{
    int n;
    cin >> n;
    vi v(n);
    for (int i = 1; i <= n; i++)
        v[i - 1] = i;
    for (int i = 0; i < n - 1; i +=2)
        swap(v[i], v[i + 1]);
    
    if (n % 2)
        swap(v[n - 1], v[n - 2]);
    cout(v);
}

//////////////////////////////////////////////////////////////////////////
int main()
{
    Omar_Sanad();

    // cout << fixed(10);
    int tc = 1;
    cin >> tc;
    while (tc--)
        SOLVE();
    // Time;
    return 0;
}
//////////////////////////////////////////////////////////////////////////