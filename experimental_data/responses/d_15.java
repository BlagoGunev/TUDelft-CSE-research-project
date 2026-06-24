Translate this C++ code to Java code. The main class name should be d_15. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;


#define MP make_pair
typedef pair<int,int> pii;
typedef long long LL;
const int MAX=1004;
int v[MAX][MAX];
LL s[MAX][MAX];
int minv[MAX][MAX];
int mv[MAX][MAX];
bool vis[MAX][MAX];
int n,m,a,b;

LL get_sum(int x0, int y0, int x1, int y1) {
	LL v = s[x0][y0];
	if (x1+1<n) v -= s[x1+1][y0];
	if (y1+1<m) v -= s[x0][y1+1];
	if (x1+1<n && y1+1<m) v += s[x1+1][y1+1];
	return v;
}

pair<LL, pii> sites[MAX*MAX];
pii output[MAX*MAX];
LL am[MAX*MAX];

int main() {
	while (2==scanf("%d %d", &n, &m)) {
		scanf("%d %d", &a, &b);
		for (int i=0;i<n;++i)
			for (int j=0;j<m;++j)
				scanf("%d", &v[i][j]);

		for (int i=n-1;i>=0;--i) {
			for (int j=m-1;j>=0;--j) {
				s[i][j] = v[i][j];
				if (i+1<n) s[i][j] += s[i+1][j];
				if (j+1<m) s[i][j] += s[i][j+1];
				if (i+1<n && j+1<m) s[i][j] -= s[i+1][j+1];
			}
		}

		for (int i=0;i<n;++i) {
			deque<pii> s;
			for (int j=0;j<m;++j) {
				while (!s.empty() && s.front().second < j-(b-1)) s.pop_front();
				while (!s.empty() && s.back().first > v[i][j]) s.pop_back();
				s.push_back(MP(v[i][j],j));
				if (j >= b-1) {
					minv[i][j-(b-1)] = s.front().first;
				}
			}
		}

		for (int j=0;j<m-b+1;++j) {
			deque<pii> s;
			for (int i=0;i<n;++i) {
				while (!s.empty() && s.front().second < i-(a-1)) s.pop_front();
				while (!s.empty() && s.back().first > minv[i][j]) s.pop_back();
				s.push_back(MP(minv[i][j],i));
				if (i >= a-1) {
					mv[i-(a-1)][j] = s.front().first;
				}
			}
		}

		typedef pair<LL,pii> elem_t;
		int cnt = 0;
		for (int i=0;i<n-a+1;++i) {
			for (int j=0;j<m-b+1;++j) {
				vis[i][j] = 0;
				LL sum = get_sum(i,j,i+a-1,j+b-1);
				sites[cnt] = MP(sum - LL(a)*LL(b)*mv[i][j], MP(i,j));
				++cnt;
			}
		}
		sort(sites,sites+cnt);

		int res = 0;
		for (int i=0;i<cnt;++i) {
			int x = sites[i].second.first;
			int y = sites[i].second.second;
			LL now = sites[i].first;
			if (vis[x][y]) continue;
			output[res].first = x;
			output[res].second = y;
			am[res] = now;
			++res;

			for (int i=max(0, x-a+1); i < min(n, x+a); ++i) {
				for (int j=max(0,y-b+1);j < min(m, y+b); ++j) {
					vis[i][j] = 1;
				}
			}

		}
		cout << res << endl;
		for (int i=0;i<res;++i) {
			printf("%d %d %I64d\n", output[i].first+1, output[i].second+1, am[i]);
		}
	}
}

<think>

</think>

### Translation Plan

1.  **Headers and Namespaces**:
    *   Replace C++ specific headers (`<cstdio>`, `<iostream>`, `<algorithm>`, `<deque>`, `<vector>`, `<utility>`, `<cassert>`, `<bitset>`, `<set>`, `<map>`, `<list>`, `<queue>`, `<stack>`, `<string>`, `<sstream>`, `<numeric>`, `<iomanip>`, `<functional>`, `<cmath>`, `<cctype>`, `<cstring>`, `<cstdlib>`, `<ctime>`) with their Java equivalents. Since the code uses `scanf`, `printf`, `vector`, `deque`, `pair` (simulated), and `sort`, we will use `java.util.Scanner` or `java.io.BufferedReader` for input, `java.util.StringTokenizer` for parsing, `java.util.Deque` for the deque, and `java.util.Arrays` or `java.util.Collections` for sorting.
    *   Replace `using namespace std;` with explicit class imports or fully qualified names where necessary.

2.  **Data Types**:
    *   `int` in C++ maps to `int` in Java.
    *   `long long` in C++ maps to `long` in Java (since Java's `long` is 64-bit signed, matching C++ `long long`).
    *   `const int MAX` becomes a `static final int`.

3.  **Structures and Types**:
    *   C++ `pair<int, int>` is mapped to a custom class `Pair` or a simple array/list. Given the usage of `pair<LL, pii>`, we need a class `Element` that holds a `long` value and a `Pair` (or two ints).
    *   `deque<pii>` becomes `Deque<Pair>`.

4.  **Input/Output**:
    *   `scanf` and `printf` are replaced by `Scanner` or `BufferedReader` + `StringTokenizer` for input, and `System.out.println` for output.
    *   `cout` is replaced by `System.out.println`.
    *   Note: `printf` uses `%I64d` for 64-bit integers on Windows in C++. In Java, `long` is printed directly, so no special format specifier is needed for 64-bit integers.

5.  **Logic Translation**:
    *   **2D Arrays**: C++ `int v[MAX][MAX]` becomes `int[][] v = new int[MAX][MAX]`.
    *   **Loops**: `for (int i=0; i<n; ++i)` translates directly to Java `for` loops.
    *   **Deque Operations**: `push_back`, `pop_front`, `pop_back`, `front`, `back` map to `addLast`, `removeFirst`, `removeLast`, `getLast`, `getFirst` in Java's `ArrayDeque`.
    *   **Sorting**: `sort(sites, sites+cnt)` maps to `Arrays.sort(sites, 0, cnt)` (if using a custom comparator) or `Collections.sort`. Since `sites` is an array of objects, we will use `Arrays.sort` with a custom `Comparator`.
    *   **Max/Min**: `max` and `min` functions are replaced with `Math.max` and `Math.min`.
    *   **Bitset/Assert**: Not heavily used in the logic provided (mostly empty or unused in the snippet), but included for completeness if needed. `assert` is replaced by a check or removed if unused.

6.  **Incremental Tasks**:
    *   Step 1: Define constants, classes (`Pair`, `Element`), and imports.
    *   Step 2: Implement input reading loop.
    *   Step 3: Implement 2D prefix sum calculation (`s`).
    *   Step 4: Implement sliding window minimum logic for rows (`minv`).
    *   Step 5: Implement sliding window minimum logic for columns (`mv`).
    *   Step 6: Implement the main loop to calculate sums and populate `sites`.
    *   Step 7: Sort `sites`.
    *   Step 8: Implement the greedy selection with `vis` array and output results.

### Java Code

```java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Collections;
import java.util.Deque;
import java.util.StringTokenizer;

class Pair {
    int first;
    int second;

    Pair(int f, int s) {
        this.first = f;
        this.second = s;
    }
}

class Element implements Comparable<Element> {
    long val;
    Pair pos;

    Element(long v, Pair p) {
        this.val = v;
        this.pos = p;
    }

    @Override
    public int compareTo(Element o) {
        return Long.compare(this.val, o.val);
    }
}

public class d_15 {
    static final int MAX = 1004;
    static int[][] v = new int[MAX][MAX];
    static long[][] s = new long[MAX][MAX];
    static int[][] minv = new int[MAX][MAX];
    static int[][] mv = new int[MAX][MAX];
    static boolean[][] vis = new boolean[MAX][MAX];
    static int n, m, a, b;

    static long get_sum(int x0, int y0, int x1, int y1) {
        long res = s[x0][y0];
        if (x1 + 1 < n) res -= s[x1 + 1][y0];
        if (y1 + 1 < m) res -= s[x0][y1 + 1];
        if (x1 + 1 < n && y1 + 1 < m) res += s[x1 + 1][y1 + 1];
        return res;
    }

    static class SitesElement implements Comparable<SitesElement> {
        long val;
        Pair pos;

        SitesElement(long v, Pair p) {
            this.val = v;
            this.pos = p;
        }

        @Override
        public int compareTo(SitesElement o) {
            return Long.compare(this.val, o.val);
        }
    }

    static SitesElement[] sites = new SitesElement[MAX * MAX];
    static Pair[] output = new Pair[MAX * MAX];
    static long[] am = new long[MAX * MAX];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;

        while (true) {
            // Read n and m
            while (st == null || !st.hasMoreTokens()) {
                String line = br.readLine();
                if (line == null) return;
                st = new StringTokenizer(line);
            }
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());

            // Read a and b
            while (st == null || !st.hasMoreTokens()) {
                String line = br.readLine();
                if (line == null) return; // Should not happen based on problem logic
                st = new StringTokenizer(line);
            }
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());

            // Read grid v
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    while (st == null || !st.hasMoreTokens()) {
                        st = new StringTokenizer(br.readLine());
                    }
                    v[i][j] = Integer.parseInt(st.nextToken());
                }
            }

            // Calculate 2D prefix sums
            for (int i = n - 1; i >= 0; i--) {
                for (int j = m - 1; j >= 0; j--) {
                    s[i][j] = v[i][j];
                    if (i + 1 < n) s[i][j] += s[i + 1][j];
                    if (j + 1 < m) s[i][j] += s[i][j + 1];
                    if (i + 1 < n && j + 1 < m) s[i][j] -= s[i + 1][j + 1];
                }
            }

            // Calculate minv: sliding window minimum on rows
            for (int i = 0; i < n; i++) {
                Deque<Pair> dq = new ArrayDeque<>();
                for (int j = 0; j < m; j++) {
                    while (!dq.isEmpty() && dq.peekLast().second < j - (b - 1)) {
                        dq.removeLast();
                    }
                    while (!dq.isEmpty() && dq.peekLast().first > v[i][j]) {
                        dq.removeLast();
                    }
                    dq.addLast(new Pair(v[i][j], j));
                    
                    if (j >= b - 1) {
                        minv[i][j - (b - 1)] = dq.peekFirst().first;
                    }
                }
            }

            // Calculate mv: sliding window minimum on columns using minv
            for (int j = 0; j < m - b + 1; j++) {
                Deque<Pair> dq = new ArrayDeque<>();
                for (int i = 0; i < n; i++) {
                    while (!dq.isEmpty() && dq.peekLast().second < i - (a - 1)) {
                        dq.removeLast();
                    }
                    while (!dq.isEmpty() && dq.peekLast().first > minv[i][j]) {
                        dq.removeLast();
                    }
                    dq.addLast(new Pair(minv[i][j], i));
                    
                    if (i >= a - 1) {
                        mv[i - (a - 1)][j] = dq.peekFirst().first;
                    }
                }
            }

            // Prepare sites list
            int cnt = 0;
            for (int i = 0; i < n - a + 1; i++) {
                for (int j = 0; j < m - b + 1; j++) {
                    vis[i][j] = false;
                    long sum = get_sum(i, j, i + a - 1, j + b - 1);
                    sites[cnt] = new SitesElement(sum - (long) a * (long) b * mv[i][j], new Pair(i, j));
                    cnt++;
                }
            }

            Arrays.sort(sites, 0, cnt);

            int res = 0;
            for (int i = 0; i < cnt; i++) {
                int x = sites[i].pos.first;
                int y = sites[i].pos.second;
                long now = sites[i].val;

                if (vis[x][y]) continue;

                output[res] = new Pair(x, y);
                am[res] = now;
                res++;

                // Mark neighbors as visited
                int startX = Math.max(0, x - a + 1);
                int endX = Math.min(n, x + a);
                int startY = Math.max(0, y - b + 1);
                int endY = Math.min(m, y + b);

                for (int i = startX; i < endX; i++) {
                    for (int j = startY; j < endY; j++) {
                        vis[i][j] = true;
                    }
                }
            }

            System.out.println(res);
            for (int i = 0; i < res; i++) {
                // Output coordinates (1-based) and value
                System.out.println((output[i].first + 1) + " " + (output[i].second + 1) + " " + am[i]);
            }
        }
    }
}
```

<CODE>
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Collections;
import java.util.Deque;
import java.util.StringTokenizer;

class Pair {
    int first;
    int second;

    Pair(int f, int s) {
        this.first = f;
        this.second = s;
    }
}

class Element implements Comparable<Element> {
    long val;
    Pair pos;

    Element(long v, Pair p) {
        this.val = v;
        this.pos = p;
    }

    @Override
    public int compareTo(Element o) {
        return Long.compare(this.val, o.val);
    }
}

public class d_15 {
    static final int MAX = 1004;
    static int[][] v = new int[MAX][MAX];
    static long[][] s = new long[MAX][MAX];
    static int[][] minv = new int[MAX][MAX];
    static int[][] mv = new int[MAX][MAX];
    static boolean[][] vis = new boolean[MAX][MAX];
    static int n, m, a, b;

    static long get_sum(int x0, int y0, int x1, int y1) {
        long res = s[x0][y0];
        if (x1 + 1 < n) res -= s[x1 + 1][y0];
        if (y1 + 1 < m) res -= s[x0][y1 + 1];
        if (x1 + 1 < n && y1 + 1 < m) res += s[x1 + 1][y1 + 1];
        return res;
    }

    static class SitesElement implements Comparable<SitesElement> {
        long val;
        Pair pos;

        SitesElement(long v, Pair p) {
            this.val = v;
            this.pos = p;
        }

        @Override
        public int compareTo(SitesElement o) {
            return Long.compare(this.val, o.val);
        }
    }

    static SitesElement[] sites = new SitesElement[MAX * MAX];
    static Pair[] output = new Pair[MAX * MAX];
    static long[] am = new long[MAX * MAX];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;

        while (true) {
            // Read n and m
            while (st == null || !st.hasMoreTokens()) {
                String line = br.readLine();
                if (line == null) return;
                st = new StringTokenizer(line);
            }
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());

            // Read a and b
            while (st == null || !st.hasMoreTokens()) {
                String line = br.readLine();
                if (line == null) return; // Should not happen based on problem logic
                st = new StringTokenizer(line);
            }
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());

            // Read grid v
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    while (st == null || !st.hasMoreTokens()) {
                        st = new StringTokenizer(br.readLine());
                    }
                    v[i][j] = Integer.parseInt(st.nextToken());
                }
            }

            // Calculate 2D prefix sums
            for (int i = n - 1; i >= 0; i--) {
                for (int j = m - 1; j >= 0; j--) {
                    s[i][j] = v[i][j];
                    if (i + 1 < n) s[i][j] += s[i + 1][j];
                    if (j + 1 < m) s[i][j] += s[i][j + 1];
                    if (i + 1 < n && j + 1 < m) s[i][j] -= s[i + 1][j + 1];
                }
            }

            // Calculate minv: sliding window minimum on rows
            for (int i = 0; i < n; i++) {
                Deque<Pair> dq = new ArrayDeque<>();
                for (int j = 0; j < m; j++) {
                    while (!dq.isEmpty() && dq.peekLast().second < j - (b - 1)) {
                        dq.removeLast();
                    }
                    while (!dq.isEmpty() && dq.peekLast().first > v[i][j]) {
                        dq.removeLast();
                    }
                    dq.addLast(new Pair(v[i][j], j));
                    
                    if (j >= b - 1) {
                        minv[i][j - (b - 1)] = dq.peekFirst().first;
                    }
                }
            }

            // Calculate mv: sliding window minimum on columns using minv
            for (int j = 0; j < m - b + 1; j++) {
                Deque<Pair> dq = new ArrayDeque<>();
                for (int i = 0; i < n; i++) {
                    while (!dq.isEmpty() && dq.peekLast().second < i - (a - 1)) {
                        dq.removeLast();
                    }
                    while (!dq.isEmpty() && dq.peekLast().first > minv[i][j]) {
                        dq.removeLast();
                    }
                    dq.addLast(new Pair(minv[i][j], i));
                    
                    if (i >= a - 1) {
                        mv[i - (a - 1)][j] = dq.peekFirst().first;
                    }
                }
            }

            // Prepare sites list
            int cnt = 0;
            for (int i = 0; i < n - a + 1; i++) {
                for (int j = 0; j < m - b + 1; j++) {
                    vis[i][j] = false;
                    long sum = get_sum(i, j, i + a - 1, j + b - 1);
                    sites[cnt] = new SitesElement(sum - (long) a * (long) b * mv[i][j], new Pair(i, j));
                    cnt++;
                }
            }

            Arrays.sort(sites, 0, cnt);

            int res = 0;
            for (int i = 0; i < cnt; i++) {
                int x = sites[i].pos.first;
                int y = sites[i].pos.second;
                long now = sites[i].val;

                if (vis[x][y]) continue;

                output[res] = new Pair(x, y);
                am[res] = now;
                res++;

                // Mark neighbors as visited
                int startX = Math.max(0, x - a + 1);
                int endX = Math.min(n, x + a);
                int startY = Math.max(0, y - b + 1);
                int endY = Math.min(m, y + b);

                for (int i = startX; i < endX; i++) {
                    for (int j = startY; j < endY; j++) {
                        vis[i][j] = true;
                    }
                }
            }

            System.out.println(res);
            for (int i = 0; i < res; i++) {
                // Output coordinates (1-based) and value
                System.out.println((output[i].first + 1) + " " + (output[i].second + 1) + " " + am[i]);
            }
        }
    }
}
</CODE>