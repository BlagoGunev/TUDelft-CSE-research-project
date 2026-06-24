/*
الذَّاهِبُ ذَهَابًا بِالْبُكَاءِ حَامِلًا مِبْذَرَ الزَّرْعِ، مَجِيئًا يَجِيءُ بِالتَّرَنُّمِ حَامِلًا حُزَمَهُ
لِكَيْ يُبَارِكَكَ الرَّبُّ إِلهُكَ فِي كُلِّ عَمَلِ يَدِكَ الَّذِي تَعْمَلُ.
بَرَكَةُ الرَّبِّ هِيَ تُغْنِي، وَلاَ يَزِيدُ مَعَهَا تَعَبًا
i can do it , one step a time
take it easy to be easy ❤
*/
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <cmath>
#include <unordered_map>
#include <algorithm>
#include <iomanip>
#include <bitset>
#include <utility>
#include <string>
#include <cctype>
#include <iomanip>
#define bye return;
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)((x).size())
#define pi 3.14159265
#define ison(num, bit) (num & (1 << bit))
#define setoff(num, bit) (num ^= (1 << bit)) // iff (num &(1<<bit))
#define flipbit(num, bit) (num ^= (1 << bit))
#define setbit(num, bit) (num |= (1 << bit))
#define clearbit(num, bit) (num &= ~(1 << bit))
#define pop_count(num) __builtin_popcount(num)
#define Num_of_Digits(n) ((int)log10(n) + 1)
#define ceil(n, m) (((n) / (m)) + ((n) % (m) ? 1 : 0))
#define upper(s) transform(all(s), s.begin(), ::toupper);
#define lower(s) transform(all(s), s.begin(), ::tolower);
using namespace std;
#define AC ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
// FIO
//    freopen("input.txt","rt",stdin);
//    freopen("output.txt","wt",stdout);
/*---------------------------------------*/
/* Dear online judge:
    I have not failed. I've just found 10,000 ways that won't work.
                    _Thomas A. Edison
*/
void LELLO()
{
    int n ; cin >> n ;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int l(0) , r(n-1) , suml(0), sumr(0) , ans(0);
    while(l <=r){
        if(sumr < suml){
            sumr+=arr[r--];

        }else suml+=arr[l++];

        if(sumr == suml){
            ans = max(ans , l+n-r-1);
        }
    }
    cout<<ans<<endl;
    bye
}
void driver(ll t)
{
    while (t--) LELLO();
}
signed main()
{

    #ifdef FIO
        ifstream cin("input.in");
        ofstream cout("output.out");
    #endif
    AC
    int test ; cin >> test ;
    driver(test);
}