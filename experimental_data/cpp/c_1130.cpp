#include <bits/stdc++.h>
using namespace std;

//.define
// #define FILE_IN_OUT
#define RET(_x)                       return cout << (_x) << '\n', 0;
#define all(_obj)                     std::begin(_obj), std::end(_obj)
#define loop(_n)                      for (int i = 0; i < (_n); ++i)
#define ceilDiv(_dividend, _divider)  (((_dividend) - 1LL + (_divider)) / (_divider))
#define has(_obj, _val)               ((_obj).find(_val) != (_obj).end())
#define sz(_obj)                      static_cast<int>((_obj).size())
#ifdef SHJ_LOCAL
    #define debug(_x)                 std::cerr << (#_x) << " = " << (_x) << '\n' << std::flush;
#else
    #define debug(_x)                 ;
#endif
#define endl "\n"
template<typename Tp>
inline void outarr(Tp _begin, Tp _end, const char* _delim = " ") {
    for (Tp current = _begin; current != _end; ++current) {
        std::cout << *current << _delim;
    }
    std::cout << '\n';
}

//.constant
using ll  = int64_t;
using pii = std::pair<int, int>;
constexpr int INF = 0x3f3f3f3f;
constexpr int MOD = static_cast<const int>(1e9 + 7);

//.data
string gr[50];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
bool used[2][50][50];

void Bfs(int w, int x0, int y0, int n) {
    memset(used[w], false, sizeof(used[w]));
    queue<pii> q;
    q.emplace(x0, y0);
    used[w][x0][y0] = true;
    while (!empty(q)) {
        auto [xf, yf] = q.front();
        q.pop();
        loop(4) {
            int nx = xf + dx[i];
            int ny = yf + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < n && gr[nx][ny] == '0' && !used[w][nx][ny]) {
                used[w][nx][ny] = true;
                q.emplace(nx, ny);
            }
        }
    }
}

//.code
int main() {
#ifdef FILE_IN_OUT
    std::ifstream cin ("input.txt",  std::ios::in);
    std::ofstream cout("output.txt", std::ios::out);
#else
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
#endif

    int n, x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    --x1; --y1; --x2; --y2;
    loop(n) {
        cin >> gr[i];
    }
    Bfs(0, x1, y1, n);
    if (used[0][x2][y2]) {
        RET(0);
    }
    Bfs(1, x2, y2, n);
    int ans = INF;
    loop(n) {
        for (int j = 0; j < n; ++j) {
            if (used[0][i][j]) {
                for (int x = 0; x < n; ++x) {
                    for (int y = 0; y < n; ++y) {
                        if (used[1][x][y]) {
                            ans = min(ans, (i - x) * (i - x) + (j - y) * (j - y));
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;

#ifdef FILE_IN_OUT
    cin.close();
    cout.close();
#endif
    return 0;
}