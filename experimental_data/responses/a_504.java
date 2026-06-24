Translate this C++ code to Java code. The main class name should be a_504. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
/* Copyright 2016 AcrossTheSky */
#include <iostream>
#include <cstdio>
#include <utility>
#include <cassert>
#include <map>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <sstream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>
#define REP(i, a, b) for (int i = (a); i <= (b); ++i)
#define PER(i, a, b) for (int i = (a); i >= (b); --i)
#define RVC(i, c) fot (int i = 0; i < (c).size(); ++i)
#define RED(k, u) for (int k = head[(u)]; k; k = edge[k].next)
#define lowbit(x) ((x) & (-(x)))
#define CL(x, v) memset(x, v, sizeof x)
#define MP std::make_pair
#define PB push_back
#define FR first
#define SC second
#define rank rankk
#define next nextt
#define link linkk
#define index indexx
#define abs(x) ((x) > 0 ? (x) : (-(x)))
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

template<class T> inline
bool getmin(T *a, const T &b) {
    if (b < *a) {
        *a = b;
        return true;
    }
    return false;
}

template<class T> inline
bool getmax(T *a, const T &b) {
    if (b > *a) {
        *a = b;
        return true;
    }
    return false;
}

template<class T> inline
void read(T *a) {
    char c;
    while (isspace(c = getchar())) {}
    bool flag = 0;
    if (c == '-') flag = 1, *a = 0;
    else
        *a = c - 48;
    while (isdigit(c = getchar())) *a = *a * 10 + c - 48;
    if (flag) *a = -*a;
}
const int mo = 1000000007;
template<class T>
T pow(T a, T b, int c = mo) {
    T res = 1;
    for (T i = 1; i <= b; i <<= 1, a = 1LL * a * a % c) if (b & i) res = 1LL * res * a % c;
    return res;
}
/*======================= TEMPLATE =======================*/
const int N = 1 << 17;
int d[N], s[N];
int n;
vector<PII> v;
void ae(int a, int b) {
	v.PB(MP(a, b));
}
queue<int> q;
int main() {
	cin >> n;
	REP(i, 0, n - 1) {
		read(d + i); read(s + i);
		if (d[i] == 1) q.push(i);
	}
	while (!q.empty()) {
		int u = q.front(); q.pop();
		if (!d[u]) continue;
		int v = s[u];
		--d[v];
		s[v] ^= u;
		ae(u, v);
		if (d[v] == 1) q.push(v);
	}
	cout << v.size() << endl;
	for (int i = 0; i < v.size(); ++i) printf("%d %d\n", v[i].FR, v[i].SC);
	return 0;
}

<think>

</think>

### Translation Plan

To translate the provided C++ code to Java, we need to address several language-specific differences:

1.  **Headers and Namespaces**: C++ requires explicit `#include` directives and `using namespace std;`. Java does not use headers in this manner; standard libraries (like `java.util.*` and `java.io.*`) are imported explicitly. The `using namespace std;` equivalent is simply importing the required classes.
2.  **Templates**: C++ uses templates (`template<class T>`) for generic functions like `getmin`, `getmax`, `read`, and `pow`. Java is statically typed and does not support templates. These functions must be rewritten with specific types (e.g., `int[]`, `long[]`) or kept as specific implementations relevant to the usage in `main`. Since the code uses `int` arrays for `d` and `s`, we will implement `read` and `getmin`/`getmax` for `int` and `long` where necessary. The `pow` function uses `long long` logic, so it will be converted to `long`.
3.  **Macros**: C++ macros (like `REP`, `PER`, `PB`, `MP`, `CL`, etc.) are preprocessor directives. In Java, these must be replaced with standard loops and method calls or inline code.
    *   `REP(i, a, b)` becomes a `for (int i = a; i <= b; i++)` loop.
    *   `PB` (push_back) becomes `list.add()`.
    *   `MP` (make_pair) becomes creating a custom `Pair` object or a simple class/record.
    *   `FR` (first) and `SC` (second) become `pair.getFirst()` and `pair.getSecond()`.
    *   `lowbit`, `abs`, `CL` are replaced with standard library functions (`Integer.lowBit`, `Math.abs`, `Arrays.fill`).
4.  **Input/Output**: C++ uses `cin`, `cout`, and `printf`. Java uses `Scanner` and `System.out.println`/`System.out.printf`.
5.  **Variable Declarations**: C++ often omits types in global arrays if they are defined at the top level (implicit `int`), but explicit types are preferred in Java. Arrays are objects in Java, so `int d[N]` becomes `int[] d = new int[N]`.
6.  **`main` function**: C++ `main` takes arguments `(int argc, char* argv[])`. Java `main` takes `String[] args`.
7.  **Class Structure**: The code must be wrapped in a public class named `a_504` with a `public static void main(String[] args)` method.

**Incremental Tasks**:
1.  Define the class structure and imports.
2.  Translate global variables (`d`, `s`, `n`, `v`, `q`, `mo`).
3.  Implement the `read` function for `int`.
4.  Implement `getmin` and `getmax` for `int`.
5.  Implement `pow` for `long` (since it's used with `1LL`).
6.  Translate the `ae` method and `main` logic, replacing macros with Java loops and methods.
7.  Ensure the output format matches the original (`cout << ... << endl` and `printf`).

### Java Code

<CODE>
import java.util.*;
import java.io.*;

public class a_504 {
    // Global variables
    static int[] d;
    static int[] s;
    static int n;
    static List<Pair> v = new ArrayList<>();
    static Queue<Integer> q = new LinkedList<>();
    static final int mo = 1000000007;

    // Custom Pair class to replace std::pair
    static class Pair {
        int first;
        int second;

        Pair(int f, int s) {
            this.first = f;
            this.second = s;
        }
    }

    // Template function getmin translated for int
    static boolean getmin(int[] a, int b) {
        if (b < a[0]) {
            a[0] = b;
            return true;
        }
        return false;
    }

    // Template function getmax translated for int
    static boolean getmax(int[] a, int b) {
        if (b > a[0]) {
            a[0] = b;
            return true;
        }
        return false;
    }

    // Template function read translated for int
    static void read(int[] a) {
        Scanner sc = new Scanner(System.in);
        // Since we can't easily peek without consuming, we assume the stream is clean or use a custom buffer.
        // However, for competitive programming style in Java, usually we just read token by token.
        // The C++ code uses getchar() which is low-level. To mimic strictly:
        // We will use a custom fast reader logic or standard Scanner if simplicity is preferred.
        // Given the constraints of the provided snippet, let's use a simple Scanner approach 
        // but note that the C++ logic handles whitespace skipping manually.
        // A robust way for this specific logic:
        try {
            // Read integer
            String token = sc.next();
            int val = Integer.parseInt(token);
            a[0] = val;
        } catch (Exception e) {
            // Fallback if needed, though Scanner.next() skips whitespace
        }
    }
    
    // Better implementation of read to match C++ behavior strictly (handling negative numbers and whitespace)
    static void readStrict(int[] a) {
        Scanner sc = new Scanner(System.in);
        if (!sc.hasNext()) return;
        String s = sc.next();
        int len = s.length();
        boolean flag = false;
        int val = 0;
        for (int i = 0; i < len; i++) {
            char c = s.charAt(i);
            if (c == '-') {
                flag = true;
            } else {
                val = val * 10 + (c - '0');
            }
        }
        if (flag) val = -val;
        a[0] = val;
    }

    // Template function pow translated for long
    static long powLong(long a, long b) {
        long res = 1;
        long mod = mo;
        for (long i = 1; i <= b; i <<= 1, a = (a * a) % mod) {
            if ((b & i) != 0) res = (res * a) % mod;
        }
        return res;
    }

    // Method ae translated
    static void ae(int a, int b) {
        v.add(new Pair(a, b));
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (!sc.hasNext()) return;
        n = sc.nextInt();

        d = new int[n];
        s = new int[n];

        // REP(i, 0, n - 1)
        for (int i = 0; i < n; i++) {
            readStrict(d);
            readStrict(s);
            if (d[i] == 1) q.add(i);
        }

        while (!q.isEmpty()) {
            int u = q.poll();
            if (d[u] == 0) continue; // Note: Original C++ checks !d[u] which is 0, but the loop continues if d[u] is 0.
            // Wait, original: if (!d[u]) continue; -> if d[u] is 0, continue.
            // But the loop condition pushes when d[v] == 1. So d[u] will be >= 1 when popped?
            // Actually, if d[u] becomes 0, it shouldn't be processed further as a source.
            // The original code: if (!d[u]) continue; means if d[u] is 0, skip.
            // So we check if d[u] == 0.
            if (d[u] == 0) continue;

            int vNode = s[u];
            d[vNode]--;
            s[vNode] = s[vNode] ^ u;
            ae(u, vNode);
            if (d[vNode] == 1) q.add(vNode);
        }

        System.out.println(v.size());
        for (int i = 0; i < v.size(); i++) {
            Pair p = v.get(i);
            System.out.println(p.first + " " + p.second);
        }
    }
}
</CODE>