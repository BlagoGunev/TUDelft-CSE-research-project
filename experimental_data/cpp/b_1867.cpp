// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

#define F first
#define S second


using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int eq = 0;
        int rem = 0;
        for (int i = 0; i < n / 2; i++) {
            if (s[i] == s[n - i - 1]) {
                eq++;
            }
        }
        int neq = n / 2 - eq;
        vector<int> ans(n + 1, 0);
        ans[neq] = 1;
        for (int i = 1; i <= eq; i++) {
            ans[neq + i * 2] = 1;
        }
        if (n % 2 == 1){ 
            for (int i = n - 1; i >= 0; i--) {
                if (ans[i]) {
                    ans[i + 1] = 1;
                }
            }
        }
        for (int i = 0; i < n + 1; i++) {
            cout << ans[i];
        }
        cout << endl;
    }
};