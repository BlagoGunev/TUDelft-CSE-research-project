#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <random>
#include <bitset>
#include <cassert>
#include <tuple>
#include <list>
#include <iterator>
#include <unordered_set>
#include <unordered_map>
#include <numeric>

using namespace std;

typedef long long ll;
typedef long double ld;

#define mp make_pair
#define pb push_back
#define mt make_tuple
#define ff first
#define ss second

#define forn(i, n) for (int i = 0; i < ((int)(n)); ++i)
#define forrn(i, s, n) for (int i = (int)(s); i < ((int)(n)); ++i)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

const int INF = 1791791791;
const ll INFLL = 1791791791791791791ll;

template<int input_buf_size, int output_buf_size>
class FastIO {
    char cbuf[input_buf_size + 1];
    int icur = 0;

    inline bool go_to_next_token() {
        while (cbuf[icur] == ' ' || cbuf[icur] == '\n') icur++;
        while (cbuf[icur] == 0) {
            icur = 0;
            if (fgets(cbuf, sizeof(cbuf), stdin) != cbuf)
                return false;
            while (cbuf[icur] == ' ' || cbuf[icur] == '\n') icur++;
        }
        return true;
    }
  public:
    string readString() {
        assert(go_to_next_token());
        string ans;
        while (cbuf[icur] != ' ' && cbuf[icur] != '\n' && cbuf[icur] != 0)
            ans.push_back(cbuf[icur++]);
        ans.shrink_to_fit();
        return ans;
    }

    template<class int_type>
    int_type readInt() {
        assert(go_to_next_token());
        int_type x = 0;
        bool m = cbuf[icur] == '-';
        if (m) icur++;
        while ('0' <= cbuf[icur] && cbuf[icur] <= '9') {
            x *= 10;
            x += (cbuf[icur] - '0');
            icur++;
        }
        if (m) x = -x;
        return x;
    }

    bool seekEof() {
        return !go_to_next_token();
    }

  private:
    char obuf[output_buf_size + 1];
    int ocur = 0;

    inline void write_string(const char *str, size_t sz = 0) {
        if (sz == 0)
            sz = strlen(str);
        if (ocur + sz > output_buf_size) {
            fputs(obuf, stdout);
            fputs(str, stdout);
            ocur = 0;
            obuf[0] = 0;
            return;
        }
        strcpy(obuf + ocur, str);
        ocur += sz;
        obuf[ocur] = 0;
   }

  public:
    template<class int_type>
    void writeInt(int_type x, bool sp = true) {
        char buf[20];
        int c = 0;
        if (x < 0) {
            buf[c++] = '-';
            x = -x;
        }
        int s = c;
        if (x == 0) {
            buf[c++] = '0';
        }
        while (x > 0) {
            buf[c++] = (x % 10) + '0';
            x /= 10;
        }
        for (int i = 0; 2 * i < c - s; i++) {
            swap(buf[s + i], buf[c - 1 - i]);
        }
        buf[c] = 0;
        write_string(buf, c);
        if (sp)
            write_string(" ", 1);
    }

    void writeString(string s, bool space = true) {
        write_string(s.c_str(), s.size());
        if (space)
            write_string(" ", 1);
    }

    void writeEndl() {
        write_string("\n", 1);
#ifdef LOCAL
        if (lflush)
            flush();
#endif
 
    }

    void flush() {
        fputs(obuf, stdout);
        ocur = 0;
        obuf[0] = 0;
    }

private:
    bool lflush;

public:

    FastIO(bool local_flush) { 
        obuf[0] = 0;
        lflush = local_flush;
    }
    
    ~FastIO() {
        fputs(obuf, stdout);
    }
};

FastIO<10000000, 10000000> IO(true);

int n;
vector<int> vf;
int f(int x) {
    return vf[x - 1];
}

int main() {
    // Code here:
   
    n = IO.readInt<int>();
    vf.resize(n);
    forn(i, n)
        vf[i] = IO.readInt<int>();

    vector<int> vals = vf;
    sort(all(vals));
    vals.resize(distance(vals.begin(), unique(all(vals))));

    for (int u : vals)
        if (f(u) != u) {
            IO.writeInt(-1);
            return 0;
        }
    
    IO.writeInt(vals.size());
    IO.writeEndl();
    forn(i, n) {
        IO.writeInt(distance(vals.begin(), lower_bound(all(vals), f(i + 1))) + 1);
    }
    IO.writeEndl();
    for (int u : vals)
        IO.writeInt(u);
    IO.writeEndl();

    return 0;
}