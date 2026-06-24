//                                                  '-.-'

//                                         ()      __.'.__

//                                      .-:--:-.  |_______|

//                               ()      \____/    \=====/

//                               /\      {====}     )___(

//                    (\=,      //\      )__(     /_____\

//    __    |'-'-'|  //  .\    (    )    /____\     |   |

//   /  \   |_____| (( \_  \    )__(      |  |      |   |

//   \__/    |===|   ))  `\_)  /____\     |  |      |   |

//  /____\   |   |  (/     \    |  |      |  |      |   |

//   |  |    |   |   | _.-'|    |  |      |  |      |   |

//   |__|    )___(    )___(    /____\    /____\    /_____\

//  (====)  (=====)  (=====)  (======)  (======)  (=======)

//  }===={  }====={  }====={  }======{  }======{  }======={

// (______)(_______)(_______)(________)(________)(_________)

#include <iostream>

#include <cstdio>

#include <cstdlib>

#include <algorithm>

#include <cmath>

#include <vector>

#include <set>

#include <map>

#include <unordered_set>

#include <unordered_map>

#include <queue>

#include <ctime>

#include <cassert>

#include <complex>

#include <string>

#include <cstring>

#include <chrono>

#include <random>

#include <bitset>

#include <array>

#include<ext/pb_ds/assoc_container.hpp>

#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

using namespace std;

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



typedef long long int ll;

#define pb push_back

#define pf push_front

#define popf pop_front

#define f first

#define s second

#define in insert

#define bug printf("**!\n")

#define mem(a , b) memset(a, b ,sizeof(a))

#define front_zero(n) __builtin_clzll(n)

#define back_zero(n) __builtin_ctzll(n)

#define total_one(n) __builtin_popcount(n)

#define clean fflush(stdout)



ll dx[] = {0, 1, 0, -1};

ll dy[] = {1, 0, -1, 0};

ll dxx[] = {0, 1, 0, -1, 1, 1, -1, -1};

ll dyy[] = {1, 0, -1, 0, 1, -1, 1, -1};



void solve() {

    int l, r;

    cin >> l >> r;

    int ans = 0;

    while (l or r) {

    	ans += (r - l);

    	l /= 10;

    	r /= 10;

    }

    cout << ans << '\n';

}

int main() {

    auto start_time = clock();

    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int T; cin >> T;

    while (T--) solve();

    auto end_time = clock();

    cerr<< "Execution time: "<< (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC <<" ms\n";

    return 0; 

}