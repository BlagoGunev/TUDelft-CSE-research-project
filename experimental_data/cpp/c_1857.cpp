#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll  long long
#define ld long double
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

template <class T1, class T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
  return os << '{' << p.first << ", " << p.second << '}';
}
template <class T, class = decay_t<decltype(*begin(declval<T>()))>,
          class = enable_if_t<!is_same<T, string>::value>>
ostream &operator<<(ostream &os, const T &c) {
  os << '[';
  for (auto it = c.begin(); it != c.end(); ++it)
    os << &", "[2 * (it == c.begin())] << *it;
  return os << ']';
}
#define _NTH_ARG(_1, _2, _3, _4, _5, _6, N, ...) N
#define _FE_0(_CALL, ...)
#define _FE_1(_CALL, x) _CALL(x)
#define _FE_2(_CALL, x, ...) _CALL(x) _FE_1(_CALL, __VA_ARGS__)
#define _FE_3(_CALL, x, ...) _CALL(x) _FE_2(_CALL, __VA_ARGS__)
#define _FE_4(_CALL, x, ...) _CALL(x) _FE_3(_CALL, __VA_ARGS__)
#define _FE_5(_CALL, x, ...) _CALL(x) _FE_4(_CALL, __VA_ARGS__)
#define _FE_6(_CALL, x, ...) _CALL(x) _FE_5(_CALL, __VA_ARGS__)
#define FOR_EACH_MACRO(MACRO, ...)                                             \
  _NTH_ARG(dummy, ##__VA_ARGS__, _FE_5, _FE_4, _FE_3, _FE_2, _FE_1, _FE_0)     \
  (MACRO, ##__VA_ARGS__)
#define out(x) #x " = " << x << "; "
#define dbg(...)                                                              \
  cerr << "Line " << __LINE__ << ": " FOR_EACH_MACRO(out, __VA_ARGS__) << "\n"
const int N = 2e5 + 5 , mod =  1e9 + 7;
ld PI = acos(-1);


void test_case()
{
    int n ; cin >> n;
    int sz = n * (n - 1) / 2;
    int arr[sz];
    for(int i = 0 ; i < sz ; i++) cin >> arr[i];
    sort(arr , arr + sz);
    int ptr = 0;
    int last = 0 , val = n - 1;
    vector<int> v;
    while(ptr < n - 1)
    {
        v.push_back(arr[last]);
        last += val;
        val--;
        ptr++;
    }
    while(v.size() < n) v.push_back(1e9);
    for(auto x : v) cout << x << " ";
    cout << "\n";


}

int main()
{
    IO
    int t=1;
    cin >> t;
    while(t--) test_case();
    return 0;
}