#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;
using f32 = float;
using f64 = double;
using i8 = int_fast8_t;
using u8 = uint_fast8_t;
using i16 = int_fast16_t;
using u16 = uint_fast16_t;
using i32 = int_fast32_t;
using u32 = uint_fast32_t;
using i64 = int_fast64_t;
using u64 = uint_fast64_t;
inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main(int argc, char *argv[]) {
    fast_io();

    i32 t;
    cin >> t;
    while (t--) {
        i64 n;
        string s;
        cin >> n >> s;
        string a(n, '0'), b(n, '0');
        bool a_larger = false;
        for (i64 i = 0; i < n; i++) {
            if (s[i] == '1') {
                if (a_larger) {
                    b[i] = '1';
                } else {
                    a_larger = true;
                    a[i] = '1';
                }
            } else if (s[i] == '2') {
                if (a_larger) {
                    b[i] = '2';
                } else {
                    a[i] = '1';
                    b[i] = '1';
                }
            }
        }
        cout << a << '\n';
        cout << b << '\n';
    }

    return 0;
}