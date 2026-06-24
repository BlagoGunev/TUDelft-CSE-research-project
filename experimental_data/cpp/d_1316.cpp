/* 
  author            :  _jzp,  
  date              : 2020-3-4  
  problemID         : CF 1316 D  
*/

#include "algorithm" 
#include "bits/stl_pair.h" 
#include "ctype.h" 
#include "functional" 
#include "iostream" 
#include "limits.h" 
#include "map" 
#include "math.h" 
#include "queue" 
#include "stdio.h" 
#include "set" 
#include "vector" 
#include "stdlib.h" 
#include "string.h" 
#include "string" 
#include "time.h" 
#include "unordered_map"

#define Rep(a, b, c) for (register int a = b; a <= c; ++ a) 
#define Rep_s(a, b, s) for (register int a = b; s[a]; ++ a) 
#define Dep(a, b, c) for (register int a = b; a >= c; -- a)  

#define DEBUG 
#define CODEFORCES
// #define ONLINE_JUDGE

#ifndef CODEFORCES
    #include "bits/extc++.h" 
#endif  

namespace IO {
    static char inBuf[32768], *inNow = inBuf, *lenBuf = inBuf; 
    inline void gc (char&); 
    inline bool gs (char*); 
    template <class T > inline bool read (T&); 

    static char outBuf[32768], *outNow = outBuf; 
    inline void flush (); 
    inline void pc (char); 
    inline void ps (const char*); 
    template < class T > inline void print (T); 
    template < class T > inline void println (T); 
    template < class T > inline void printsp (int); 
}; 

inline void IO :: gc (char &ch) {
    ch = ((inNow == lenBuf) && (lenBuf = ((inNow = inBuf) + fread (inBuf, 1, sizeof(inBuf), stdin)), inNow == lenBuf)? EOF: *(inNow ++)); 
}
inline bool IO :: gs (char* s) {
    while (gc (s[0]), isspace (s[0]) && ~s[0]) 
        ; 
    if (!(~s[0])) 
        return 0; 
    int len = 0; 
    while (!isspace (s[len]) && ~s[len]) 
        gc (s[++ len]); 
    s[len] = 0; 
    return 1; 
}
template < class T > 
inline bool IO :: read (T &x) {
    x = 0; 
    bool y = 1; 
    char ch; 
    gc (ch); 
    if (!(~ch)) 
        return 0; 
    while (!isdigit (ch)) 
        y &= !!(ch ^ (char)'-'), gc (ch); 
    while (isdigit (ch)) 
        x = (x << 3) + (x << 1) + (ch & 15), gc (ch); 
    x = y? x: -x; 
    return 1; 
}

inline void IO :: flush () {
    fwrite (outBuf, 1, outNow - outBuf, stdout); 
    outNow = outBuf; 
    fflush (stdout); 
}
inline void IO :: pc (char ch) {
    *(outNow ++) = ch; 
    if (outNow - outBuf == sizeof(outBuf)) 
        flush (); 
}
inline void IO :: ps (const char* s) {
    while (*s) 
        pc (*(s ++)); 
}
template < class T > 
inline void IO :: print(T x) {
    short num[35], *numNow = num; 
    if (x <= 0) 
        pc (x? (char)'-': (char)'0'), x = -x; 
    while (x) 
        *(numNow ++) = x % 10, x /= 10; 
    while (numNow != num) 
        pc ((char)(48 | *(-- numNow))); 
}
template < class T > 
inline void IO :: println(T x) {
    print(x), pc(10); 
}
template < class T > 
inline void IO :: printsp(T x) {
    print(x), pc(32); 
}

using IO :: gc; 
using IO :: pc; 
using IO :: gs; 
using IO :: ps; 
using IO :: read; 
using IO :: print; 
using IO :: println; 
using IO :: printsp; 

namespace Quote {
    template < class T > 
    inline T Max (T a, T b) {
        return b < a? a: b; 
    }
    template < class T > 
    inline T Min (T a, T b) {
        return a < b? a: b; 
    }
    template < class T > 
    inline T Abs (T x) {
        return x < 0? -x: x; 
    }

    struct pair_hash {
        template < class T1, class T2 > 
        std :: size_t operator () (const std :: pair < T1, T2 > &x) const {
            return (((std :: hash < T1 > () (x.first) << 10) ^ 0x9e3779b9) ^ (std :: hash < T2 > () (x.second)) ^ 0x4c5968ac); 
        }
    }; 
}; 

namespace myPrepare {
    void pre() {

    }
}; 

namespace mySolve {
    using namespace Quote; 

    // #define SUBTEST  

    int n; 
    int x[1010][1010], y[1010][1010]; 
    bool vis[1010][1010]; 
    char s[1010][1010]; 

    void dfs(int dx, int dy, char to) {
        if (vis[dx][dy]) 
            return; 
        vis[dx][dy] = 1; 
        s[dx][dy] = to; 
        if (x[dx][dy] == x[dx + 1][dy] && y[dx][dy] == y[dx + 1][dy]) 
            dfs(dx + 1, dy, 'U'); 
        if (x[dx][dy] == x[dx - 1][dy] && y[dx][dy] == y[dx - 1][dy]) 
            dfs(dx - 1, dy, 'D'); 
        if (x[dx][dy] == x[dx][dy + 1] && y[dx][dy] == y[dx][dy + 1]) 
            dfs(dx, dy + 1, 'L'); 
        if (x[dx][dy] == x[dx][dy - 1] && y[dx][dy] == y[dx][dy - 1]) 
            dfs(dx, dy - 1, 'R'); 
    }

    inline void main () {
        read(n); 
        Rep (i, 1, n) 
            Rep (j, 1, n) 
                read(x[i][j]), read(y[i][j]); 
        Rep (i, 1, n) 
            Rep (j, 1, n) {
                if (x[i][j] == i && y[i][j] == j) 
                    continue; 
                if (x[i][j] != x[i - 1][j] || y[i][j] != y[i - 1][j]) 
                if (x[i][j] != x[i + 1][j] || y[i][j] != y[i + 1][j]) 
                if (x[i][j] != x[i][j - 1] || y[i][j] != y[i][j - 1]) 
                if (x[i][j] != x[i][j + 1] || y[i][j] != y[i][j + 1]) 
                    return ps("INVALID"); 
                if (~x[i][j] && ~y[i][j])
                    if (x[x[i][j]][y[i][j]] != x[i][j] || y[x[i][j]][y[i][j]] != y[i][j]) 
                        return ps("INVALID"); 
            }
        Rep (i, 1, n) 
            Rep (j, 1, n) {
                if (x[i][j] == i && y[i][j] == j) 
                    dfs(i, j, 'X'); 
                if (x[i][j] == -1 && y[i][j] == -1) 
                    if (!vis[i][j]) {
                        if (x[i + 1][j] == -1) 
                            vis[i][j] = 1, dfs(i + 1, j, 'U'), s[i][j] = 'D'; 
                        else if (x[i - 1][j] == -1) 
                            vis[i][j] = 1, dfs(i - 1, j, 'D'), s[i][j] = 'U'; 
                        else if (x[i][j - 1] == -1) 
                            vis[i][j] = 1, dfs(i, j - 1, 'R'), s[i][j] = 'L'; 
                        else if (x[i][j + 1] == -1) 
                            vis[i][j] = 1, dfs(i, j + 1, 'L'), s[i][j] = 'R'; 
                    }
            }
        Rep (i, 1, n) 
            Rep (j, 1, n) 
                if (!vis[i][j]) 
                    return ps("INVALID"); 
        ps("VALID"), pc(10); 
        Rep (i, 1, n) 
            ps(s[i] + 1), pc(10); 
    }
}; 

namespace myMain {
    inline void solve () {
        int T = 1; 
        #ifdef SUBTEST 
            read (T); 
        #endif 
        myPrepare :: pre(); 
        while (T --) {
            mySolve :: main (); 
        }
    }
    inline void main () {
        solve (); 
        IO :: flush (); 
    }
}; 

main() {

    #ifndef ONLINE_JUDGE 
        freopen ("in.txt", "r", stdin); 
        freopen ("out.txt", "w", stdout); 
    #endif 

    myMain :: main (); 
    return 0; 
}