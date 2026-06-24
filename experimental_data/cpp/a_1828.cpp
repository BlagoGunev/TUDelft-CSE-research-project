//ashrafsusts19
 
 
 
#include <bits/stdc++.h>
#include <limits>
#include <random>
#include <chrono>

 
using namespace std;
using ulli = unsigned long long int;
using lli = long long int;
#define prnt(a) cout << a << "\n"
#define prnt2(a, b) cout << a << " " << b << "\n";
#define prnt3(a, b, c) cout << a << " " << b << " " << c << "\n";
#define forp1(a) for (lli i = 0; i < a; i++)
#define forp2(a, b) for (lli i = a; i < b; i++)
#define forp3(a, b, c) for (lli i = a; i < b; i += c)
#define forv1(i, a) for (lli i = 0; i < a; i++)
#define forv2(i, a, b) for (lli i = a; i < b; i++)
#define all(x) (x).begin(), (x).end()
#define refill(a, b, c) a.clear();a.resize(b, c);
#define reloc(a, b) a.clear();a.resize(b);
#define gMOD(a, b) ((a) % b)
 
 
void debug1(vector<lli> &lst){
    cout << "Debug: ";
    for (lli i = 0; i < lst.size(); i++) cout << lst[i] << " ";
    cout << endl;
}
 
void debug2(string name, vector<lli> &lst)
{
    cout << name << ": ";
    for (lli i = 0; i < lst.size(); i++) cout << lst[i] << " ";
    cout << endl;
}
 
void debugn(vector<lli> &lst, lli mx){
    if (mx > lst.size()){
        mx = lst.size();
    }
    cout << "Debug: ";
    for (lli i = 0; i < mx; i++) cout << lst[i] << " ";
    cout << endl;
}
 

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<lli, null_type,less<lli>, rb_tree_tag,tree_order_statistics_node_update> 

 
// #define LOCAL 1
#ifdef LOCAL
#include "E:\C++\app_debug.cpp"
#else
#define debug(...)
#define debugArr(arr, n)
#endif






int main(){
    ios_base::sync_with_stdio(false);    
    cin.tie(0);

    lli t;
    cin >> t;
    while (t--){
        lli n;
        cin >> n;
        for (lli i = 1; i <= n; i++){
            cout << i * 2 << " ";
        }
        prnt("");
    }
}