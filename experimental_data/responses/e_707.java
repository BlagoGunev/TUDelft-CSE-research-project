Translate this C++ code to Java code. The main class name should be e_707. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include<cstdio>

#include<cstring>

#include<algorithm>

#include<cctype>

#include<ctime>

#include<cstdlib>

#include<string>

#include<queue>

#include<cmath>

#include<set>

#include<map>

#include<bitset>

#include<vector>

#define rep(x,a,b) for (int x=a;x<=(int)b;x++)

#define drp(x,a,b) for (int x=a;x>=(int)b;x--)

#define cross(x,a) for (int x=hd[a];~x;x=nx[x])

#define ll long long

#define inf (1<<29)

#define PII pair<int,int>

#define PDD pair<double,double>

#define mk(a,b) make_pair(a,b)

#define fs first

#define sc second

#define pb push_back

using namespace std;

inline ll rd(){

	ll x=0;int ch=getchar(),f=1;

	while (!isdigit(ch)&&(ch!='-')&&(ch!=EOF)) ch=getchar();

	if (ch=='-'){f=-1;ch=getchar();}

	while (isdigit(ch)){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}

	return x*f;

}

inline void rt(ll x){

	if (x<0) putchar('-'),x=-x;

	if (x>=10) rt(x/10),putchar(x%10+'0');

		else putchar(x+'0');

}

const int maxn=2005;

PII bulb[maxn][maxn],poi[maxn][maxn],t;

int len[maxn],n,m,c;

ll val[maxn][maxn];

bool turn[maxn];

#define y1 orz_rxd

#define y2 orz_szj

char s[10];

int main(){

	n=rd(),m=rd(),c=rd();

	rep(i,1,c){

		len[i]=rd();

		rep(j,1,len[i]){

			int x=rd(),y=rd(),v=rd();

			poi[i][j]=mk(x,y);

			bulb[x][y]=mk(i,j);

			val[i][j]=val[i][j-1]+v;

		}

	}

	rep(i,1,c) turn[i]=1;

	ll ans;

	for (int q=rd();q--;){

		scanf("%s",s);

		if (s[0]=='S') turn[rd()]^=1;

		else{

			int x1=rd(),y1=rd(),x2=rd(),y2=rd(),tmp;

			ans=0;

			if (y1!=1) rep(i,x1,x2){

				if (turn[tmp=bulb[i][y1].fs]&&bulb[i][y1-1].fs==tmp&&abs(bulb[i][y1-1].sc-bulb[i][y1].sc)==1)

					if (bulb[i][y1-1].sc<bulb[i][y1].sc) ans-=val[tmp][bulb[i][y1-1].sc];

						else ans+=val[tmp][bulb[i][y1].sc];

			}

			if (x1!=1) rep(i,y1,y2){

				if (turn[tmp=bulb[x1][i].fs]&&bulb[x1-1][i].fs==tmp&&abs(bulb[x1-1][i].sc-bulb[x1][i].sc)==1)

					if (bulb[x1-1][i].sc<bulb[x1][i].sc) ans-=val[tmp][bulb[x1-1][i].sc];

						else ans+=val[tmp][bulb[x1][i].sc];

			}

			if (y2!=m) rep(i,x1,x2){

				if (turn[tmp=bulb[i][y2].fs]&&bulb[i][y2+1].fs==tmp&&abs(bulb[i][y2+1].sc-bulb[i][y2].sc)==1)

					if (bulb[i][y2+1].sc<bulb[i][y2].sc) ans-=val[tmp][bulb[i][y2+1].sc];

						else ans+=val[tmp][bulb[i][y2].sc];

			}

			if (x2!=n) rep(i,y1,y2){

				if (turn[tmp=bulb[x2][i].fs]&&bulb[x2+1][i].fs==tmp&&abs(bulb[x2+1][i].sc-bulb[x2][i].sc)==1)

					if (bulb[x2+1][i].sc<bulb[x2][i].sc) ans-=val[tmp][bulb[x2+1][i].sc];

						else ans+=val[tmp][bulb[x2][i].sc];

			}

			rep(i,1,c) if (turn[i]&&(t=poi[i][len[i]]).fs>=x1&&t.fs<=x2&&t.sc>=y1&&t.sc<=y2) ans+=val[i][len[i]];

			rt(ans),putchar('\n');

		}

	}

}

Here is the plan for the translation from C++ to Java:

1.  **Main Class**: Change the entry point from `main` function to a `public static void main(String[] args)` method inside a class named `e_707`.
2.  **Input/Output**:
    *   Replace the custom `rd()` (fast I/O for reading integers) and `rt()` (fast I/O for writing integers) with `java.util.Scanner`. While `BufferedReader` is faster, the logic in `rd()` is complex (handling negative numbers and EOF), which is cumbersome to replicate manually in Java. `Scanner` is sufficient for competitive programming tasks unless time limits are extremely tight, and it simplifies the code significantly.
    *   Replace `scanf("%s",s)` with `sc.next()`.
3.  **Data Structures**:
    *   `long long` in C++ maps to `long` in Java.
    *   `int` maps to `int`.
    *   `pair<int, int>` (PII) needs to be manually implemented as a class or handled via two arrays. Given the heavy usage in the code (accessing `first` and `second`), a helper class `Point` or simply using separate arrays `x_coord` and `y_coord` is better. However, to stay close to the original structure, I will define a simple `class Point` with `x` and `y` fields.
    *   The `val` array is `long` in Java.
4.  **Macros**:
    *   `rep` and `drp` loops need to be converted to standard `for` loops.
    *   `mk` (make_pair) becomes creating a `Point` object.
    *   `pb` (push_back) is not used in the provided snippet, so it can be ignored.
    *   `fs` and `sc` (first/second) become accessing `.x` and `.y` fields.
5.  **Specific Logic**:
    *   The `turn` array is boolean, mapping directly to Java `boolean`.
    *   `abs()` is a method in `Math` class.
    *   `s` array (char buffer) becomes a `String`.
    *   `inf` constant is unused in the logic, but defined.
    *   `maxn` constant remains the same.

**Incremental Tasks**:
1.  Define the `Point` class.
2.  Define the main class `e_707` and import `java.util.*`.
3.  Implement `main` method.
4.  Translate input reading logic (n, m, c).
5.  Translate the loop reading bulbs and calculating prefix sums.
6.  Translate the query processing loop (switch case for 'S').
7.  Translate the geometric logic (checking boundaries, toggling turns, calculating area based on `val`).
8.  Translate output logic.

```java
import java.util.Scanner;

public class e_707 {
    // Mapping for pair<int,int>
    static class Point {
        int x;
        int y;
        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    static final int maxn = 2005;
    static Point[] bulb = new Point[maxn * maxn]; // Flattened or 2D array? Original is bulb[maxn][maxn].
    // In Java, multi-dimensional arrays are arrays of arrays.
    // However, allocating [2005][2005] is fine.
    static Point[][] bulbArr = new Point[maxn][maxn];
    
    static Point[][] poi = new Point[maxn][maxn];
    static long[][] val = new long[maxn][maxn];
    static boolean[] turn = new boolean[maxn];
    
    static int[] len = new int[maxn];
    static int n, m, c;
    static int[] s; // Not strictly needed as String, but used for char access in logic if needed.
    // Actually, the code uses char s[10]. We can just use String s.
    static String sQuery;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        if (sc.hasNext()) {
            n = sc.nextInt();
            m = sc.nextInt();
            c = sc.nextInt();
        }

        for (int i = 1; i <= c; i++) {
            len[i] = sc.nextInt();
            for (int j = 1; j <= len[i]; j++) {
                int x = sc.nextInt();
                int y = sc.nextInt();
                int v = sc.nextInt();
                
                poi[i][j] = new Point(x, y);
                bulbArr[x][y] = new Point(i, j);
                
                // val[i][j] = val[i][j-1] + v;
                // Handle j=1 case
                val[i][j] = (j > 1) ? val[i][j - 1] : 0;
                val[i][j] += v;
            }
        }

        for (int i = 1; i <= c; i++) {
            turn[i] = true;
        }

        while (sc.hasNext()) {
            String s = sc.next();
            if (s.charAt(0) == 'S') {
                int idx = sc.nextInt();
                turn[idx] = !turn[idx];
            } else {
                int x1 = sc.nextInt();
                int y1 = sc.nextInt();
                int x2 = sc.nextInt();
                int y2 = sc.nextInt();
                
                long ans = 0;
                
                // Check top edge (y1)
                if (y1 != 1) {
                    for (int i = x1; i <= x2; i++) {
                        int tmp = bulbArr[i][y1].x;
                        // bulb[i][y1-1]
                        Point p1 = bulbArr[i][y1 - 1];
                        Point p2 = bulbArr[i][y1];
                        
                        // Logic: bulb[i][y1-1].x == tmp && abs(y1-1 - y1) == 1
                        // Since y1-1 and y1 are adjacent, abs is 1.
                        // But we must check if the bulb at y1-1 exists and belongs to the same component.
                        // Wait, the logic checks bulbArr[i][y1-1].x == tmp.
                        // This implies bulbArr[i][y1] and bulbArr[i][y1-1] must be the same bulb index?
                        // Yes, "bulb[i][y1-1].fs==tmp" checks if the bulb at (i, y1-1) is the same as bulb at (i, y1).
                        // This usually implies a specific geometric relationship or continuity.
                        // In the original C++, bulb[x][y] stores the component ID.
                        // If bulb[i][y1-1].x == tmp (which is bulb[i][y1].x), it means the bulb is continuous vertically.
                        
                        if (turn[tmp] && p1.x == tmp && Math.abs(p1.y - p2.y) == 1) {
                            if (p1.y < p2.y) ans -= val[tmp][p1.y];
                            else ans += val[tmp][p2.y];
                        }
                    }
                }
                
                // Check left edge (x1)
                if (x1 != 1) {
                    for (int i = y1; i <= y2; i++) {
                        int tmp = bulbArr[x1][i].x;
                        Point p1 = bulbArr[x1 - 1][i];
                        Point p2 = bulbArr[x1][i];
                        
                        if (turn[tmp] && p1.x == tmp && Math.abs(p1.y - p2.y) == 1) {
                            // Wait, x coordinates are involved here.
                            // p1 is (x1-1, i), p2 is (x1, i).
                            // The condition checks if they are the same bulb.
                            // If p1.y < p2.y... wait, p1.y and p2.y are both 'i'. 
                            // The original code compares p1.sc and p2.sc.
                            // In C++, bulb[x][i] stores (id, y). 
                            // So p1.sc is y-coordinate of bulb at (x1-1, i).
                            // p2.sc is y-coordinate of bulb at (x1, i).
                            // This logic seems to check if the bulb spans across the boundary x1.
                            // But the condition `abs(bulb[x1-1][i].sc - bulb[x1][i].sc) == 1` checks if the y-coordinates differ by 1.
                            // This implies the bulb is diagonal or adjacent?
                            // Actually, if the bulb is a single cell, y-coords are same.
                            // If it spans, maybe.
                            // Let's strictly translate.
                            
                            Point pLeft = bulbArr[x1 - 1][i];
                            Point pRight = bulbArr[x1][i];
                            
                            if (turn[tmp] && pLeft.x == tmp && Math.abs(pLeft.y - pRight.y) == 1) {
                                if (pLeft.y < pRight.y) ans -= val[tmp][pLeft.y];
                                else ans += val[tmp][pRight.y];
                            }
                        }
                    }
                }
                
                // Check right edge (y2)
                if (y2 != m) {
                    for (int i = x1; i <= x2; i++) {
                        int tmp = bulbArr[i][y2].x;
                        Point p1 = bulbArr[i][y2 + 1];
                        Point p2 = bulbArr[i][y2];
                        
                        if (turn[tmp] && p1.x == tmp && Math.abs(p1.y - p2.y) == 1) {
                            if (p1.y < p2.y) ans -= val[tmp][p1.y];
                            else ans += val[tmp][p2.y];
                        }
                    }
                }
                
                // Check bottom edge (x2)
                if (x2 != n) {
                    for (int i = y1; i <= y2; i++) {
                        int tmp = bulbArr[x2][i].x;
                        Point p1 = bulbArr[x2 + 1][i];
                        Point p2 = bulbArr[x2][i];
                        
                        if (turn[tmp] && p1.x == tmp && Math.abs(p1.y - p2.y) == 1) {
                            if (p1.y < p2.y) ans -= val[tmp][p1.y];
                            else ans += val[tmp][p2.y];
                        }
                    }
                }
                
                // Add full bulbs inside
                for (int i = 1; i <= c; i++) {
                    if (turn[i]) {
                        Point t = poi[i][len[i]];
                        if (t.x >= x1 && t.x <= x2 && t.y >= y1 && t.y <= y2) {
                            ans += val[i][len[i]];
                        }
                    }
                }
                
                rt(ans);
                System.out.println();
            }
        }
    }
    
    // Re-implementing rt for printing
    static void rt(long x) {
        if (x < 0) {
            System.out.print('-');
            x = -x;
        }
        if (x >= 10) {
            rt(x / 10);
        } else {
            System.out.print((char)('0' + x));
        }
    }
}
```
Wait, I need to check the recursion depth for `rt`. In C++, `rt` calls itself. In Java, infinite recursion is bad, but since `x` decreases, it terminates. However, `x` can be large (long). The logic `rt(x/10)` is fine. But `System.out.print` inside a recursive function for large inputs might be slow due to I/O overhead. Given the context of C++ `putchar`, it's usually for speed. `System.out.print` is slower. I should use `StringBuilder` or `PrintWriter` for efficiency, or keep the recursion if it's just for the logic translation. The prompt asks to translate the code. I will keep the logic but maybe optimize output slightly or keep it as is to match the "translation" requirement strictly.
Actually, `rt` in C++ is a recursive function that prints digits. In Java, `System.out.print` is buffered, so recursion overhead is small compared to `printf`. But `rt` is recursive. I will implement it as a recursive method to be faithful to the C++ structure, but I should be careful about stack overflow if `x` is huge (though `long` fits in stack depth for `10^18`? No, `10^18` has 18 digits, recursion depth 18 is fine).

One detail: `bulb` is declared as `PII bulb[maxn][maxn]`. In Java, `Point[][] bulbArr` is safer.
The `val` array is `long`.
The `turn` array is `bool`.

Wait, the `rt` function in C++:
```cpp
inline void rt(ll x){
	if (x<0) putchar('-'),x=-x;
	if (x>=10) rt(x/10),putchar(x%10+'0');
		else putchar(x+'0');
}
```
If `x` is 0, it prints '0'.
My Java implementation:
```java
static void rt(long x) {
    if (x < 0) {
        System.out.print('-');
        x = -x;
    }
    if (x >= 10) {
        rt(x / 10);
    } else {
        System.out.print((char)('0' + x));
    }
}
```
This is correct.

One issue: `Scanner` is slow. The original code uses a custom `rd()` function which is very fast. However, replicating that in Java is verbose. The prompt asks to translate. I will use `Scanner` for readability unless I decide to implement a `FastReader` class to mimic the C++ speed. Given the instruction "make a plan... considering C++ specific features", I should probably mention the speed difference. But for the code output, standard `Scanner` is usually acceptable for simple translations unless the problem is known to be tight. However, to be safe and close to the original intent (fast I/O), I will implement a simple `FastReader` or just use `Scanner` if the logic is simple. The logic here involves loops over 2005, so `Scanner` might TLE. I will implement a `FastReader` class to mimic the C++ `rd()` function, which is the standard practice for translating competitive programming code to Java.

Plan update:
1. Implement `FastReader` class to replace `rd()`.
2. Implement `rt()` method using `StringBuilder` or `PrintWriter` to avoid recursion overhead and stack issues, or keep recursion if safe. Recursion for 18 digits is safe. But `System.out` inside recursion is slow. I'll use `StringBuilder` to buffer the output string and print at once, or just use recursion if it's strictly a translation. Let's use recursion but optimize the I/O call to `PrintWriter` or `System.out.print` directly. Actually, `System.out.print` is buffered. I'll stick to the recursive structure but use `System.out.print` which is buffered by default.
3. Replace `scanf` with `FastReader`'s `next()` or `String` parsing.
4. Handle the `turn` logic and geometric calculations.

Let's refine the `FastReader` to match `rd()`.
`rd()` reads an integer.
`scanf("%s", s)` reads a string.

```java
import java.io.*;
import java.util.StringTokenizer;

public class e_707 {
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    String line = br.readLine();
                    if (line == null) return null;
                    st = new StringTokenizer(line);
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            String s = next();
            if (s == null) return 0; // Should not happen based on problem logic
            return Integer.parseInt(s);
        }
        
        // Custom rd() logic for long long
        long rd() {
            String s = next();
            if (s == null) return 0;
            long res = 0;
            int f = 1;
            if (s.charAt(0) == '-') {
                f = -1;
                res = -Long.parseLong(s.substring(1));
            } else {
                res = Long.parseLong(s);
            }
            return res;
        }
    }

    static final int maxn = 2005;
    static class Point {
        int x, y;
        Point(int x, int y) { this.x = x; this.y = y; }
    }

    static Point[][] bulb = new Point[maxn][maxn];
    static Point[][] poi = new Point[maxn][maxn];
    static long[][] val = new long[maxn][maxn];
    static boolean[] turn = new boolean[maxn];
    static int[] len = new int[maxn];
    
    static int n, m, c;
    static FastReader in;
    static PrintWriter out;

    public static void main(String[] args) {
        in = new FastReader();
        out = new PrintWriter(System.out);
        
        String s_n = in.next();
        if (s_n == null) return;
        n = Integer.parseInt(s_n);
        m = in.nextInt();
        c = in.nextInt();

        for (int i = 1; i <= c; i++) {
            len[i] = in.nextInt();
            for (int j = 1; j <= len[i]; j++) {
                int x = in.nextInt();
                int y = in.nextInt();
                int v = in.nextInt();
                
                poi[i][j] = new Point(x, y);
                bulb[x][y] = new Point(i, j);
                
                val[i][j] = val[i][j - 1] + v;
            }
        }

        for (int i = 1; i <= c; i++) {
            turn[i] = true;
        }

        while (in.next() != null) {
            String s = in.next();
            if (s.charAt(0) == 'S') {
                int idx = in.nextInt();
                turn[idx] = !turn[idx];
            } else {
                int x1 = in.nextInt();
                int y1 = in.nextInt();
                int x2 = in.nextInt();
                int y2 = in.nextInt();
                
                long ans = 0;
                
                if (y1 != 1) {
                    for (int i = x1; i <= x2; i++) {
                        int tmp = bulb[i][y1].x;
                        Point p1 = bulb[i][y1 - 1];
                        Point p2 = bulb[i][y1];
                        
                        if (turn[tmp] && p1.x == tmp && Math.abs(p1.y - p2.y) == 1) {
                            if (p1.y < p2.y) ans -= val[tmp][p1.y];
                            else ans += val[tmp][p2.y];
                        }
                    }
                }
                
                if (x1 != 1) {
                    for (int i = y1; i <= y2; i++) {
                        int tmp = bulb[x1][i].x;
                        Point p1 = bulb[x1 - 1][i];
                        Point p2 = bulb[x1][i];
                        
                        if (turn[tmp] && p1.x == tmp && Math.abs(p1.y - p2.y) == 1) {
                            if (p1.y < p2.y) ans -= val[tmp][p1.y];
                            else ans += val[tmp][p2.y];
                        }
                    }
                }
                
                if (y2 != m) {
                    for (int i = x1; i <= x2; i++) {
                        int tmp = bulb[i][y2].x;
                        Point p1 = bulb[i][y2 + 1];
                        Point p2 = bulb[i][y2];
                        
                        if (turn[tmp] && p1.x == tmp && Math.abs(p1.y - p2.y) == 1) {
                            if (p1.y < p2.y) ans -= val[tmp][p1.y];
                            else ans += val[tmp][p2.y];
                        }
                    }
                }
                
                if (x2 != n) {
                    for (int i = y1; i <= y2; i++) {
                        int tmp = bulb[x2][i].x;
                        Point p1 = bulb[x2 + 1][i];
                        Point p2 = bulb[x2][i];
                        
                        if (turn[tmp] && p1.x == tmp && Math.abs(p1.y - p2.y) == 1) {
                            if (p1.y < p2.y) ans -= val[tmp][p1.y];
                            else ans += val[tmp][p2.y];
                        }
                    }
                }
                
                for (int i = 1; i <= c; i++) {
                    if (turn[i]) {
                        Point t = poi[i][len[i]];
                        if (t.x >= x1 && t.x <= x2 && t.y >= y1 && t.y <= y2) {
                            ans += val[i][len[i]];
                        }
                    }
                }
                
                // Manual rt implementation to match logic
                printLong(ans);
                out.println();
            }
        }
        out.flush();
    }
    
    static void printLong(long x) {
        if (x < 0) {
            out.print('-');
            x = -x;
        }
        if (x >= 10) {
            printLong(x / 10);
        } else {
            out.print((char)('0' + x));
        }
    }
}
```
Wait, `val[i][j-1]` when `j=1` accesses `val[i][0]`. In C++, global arrays are initialized to 0. In Java, arrays are initialized to 0. So `val[i][0]` is 0. My code `val[i][j] = val[i][j-1] + v` works for `j=1` because `val[i][0]` is 0.
However, I added `if (j > 1) ? val[i][j - 1] : 0` in my thought process. I should remove that and just use `val[i][j] = val[i][j-1] + v` because Java arrays init to 0.
Wait, `val` is `long`. `val[i][j-1]` is valid.
But I need to make sure `val` is large enough. `maxn` is 2005. `val` is `long[2005][2005]`. Indices 0 to 2004.
The loops go from 1 to `len[i]`. `len[i]` can be up to `maxn`.
So `val[i][len[i]]` accesses `val[i][2005]`? No, `len[i]` is read from input. `len[i]` can be up to `maxn`.
Wait, `len` array is `int`. `rep(i,1,c)` loops up to `c`. `len[i]` is assigned.
If `len[i]` is 2005, `val[i][2005]` is out of bounds for `new Point[2005][2005]`.
Java arrays are 0-indexed. `new long[2005][2005]` has indices 0..2004.
If the input `len[i]` can be 2005, I need `new long[2006][2006]`.
The C++ code `int maxn=2005;` usually implies size 2005. But array declaration `int a[2005]` in C++ has indices 0..2004.
If the input `len` is 2005, `val[i][2005]` would crash in C++ if `maxn` is 2005?
Wait, `rep(i,1,c)` and `rep(j,1,len[i])`. If `len[i]` is 2005, `j` goes up to 2005.
`val[i][j]` accesses `val[i][2005]`.
In C++, `long long val[maxn][maxn]` where `maxn=2005` has indices 0..2004. Accessing 2005 is out of bounds.
Maybe `maxn` is defined as the maximum possible index?
Usually in CP, `maxn` is defined as the maximum N+1 or similar to allow 1-based indexing.
If `maxn` is 2005, and `len` can be 2005, then `val[...][2005]` is out of bounds.
Let's assume `maxn` is sufficient for the input constraints (likely `len[i] < 2005` or `maxn` is large enough).
I will define `maxn` as 2005. If the problem allows 2005, I should increase it to 2006.
But I will stick to `maxn = 2005` and assume inputs fit. Or better, `2006` to be safe.
Wait, the C++ code: `const int maxn=2005;`.
If I strictly translate, I use `2005`. If I want it to run, I might need `2006`.
Given the instruction "translate", I should stick to the logic. I will use `2005` but maybe add a small buffer or assume valid input.
Actually, `new long[2005][2005]` in Java is 0..2004.
If `len[i]` is 2005, it crashes.
I'll change `maxn` to 2006 to be safe for 1-based indexing up to 2005.
Also `turn` array: `turn[i]` where `i` goes up to `c`. `c` is read.
If `c` is large, `turn` needs to be large.
The code uses `turn[i]`. `i` goes up to `c`.
`len` array is `int[len]`. `len` is `int[2005]`.
I will use `2005` as per original, but maybe `2006` to avoid OOB if `len` is 2005.
Actually, in C++, `int a[2005]` is 0..2004.
If `maxn` is 2005, then `val[2005][2005]` is invalid.
I will define `maxn` as 2005 and hope the input `len` is <= 2004.
Or I can define `maxn` as 2005 and allocate `new long[2006][2006]` to cover 0..2005.
I'll use `2006` to be safe.

One more thing: `turn[i]` is initialized to 1 (true) in C++ `bool`.
In Java `boolean[]` defaults to `false`. I must explicitly set `turn[i] = true`.

Final check on `rt`:
The recursive `rt` is fine.
I'll use `PrintWriter` for output.

```java
import java.io.*;
import java.util.StringTokenizer;

public class e_707 {
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    String line = br.readLine();
                    if (line == null) return null;
                    st = new StringTokenizer(line);
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            String s = next();
            if (s == null) return 0;
            return Integer.parseInt(s);
        }
        
        long rd() {
            String s = next();
            if (s == null) return 0;
            long res = 0;
            int f = 1;
            if (s.charAt(0) == '-') {
                f = -1;
                // substring from 1 to end
                res = -Long.parseLong(s.substring(1));
            } else {
                res = Long.parseLong(s);
            }
            return res;
        }
    }

    static final int maxn = 2006; // Increased to handle 1-based index up to 2005
    static class Point {
        int x, y;
        Point(int x, int y) { this.x = x; this.y = y; }
    }

    static Point[][] bulb = new Point[maxn][maxn];
    static Point[][] poi = new Point[maxn][maxn];
    static long[][] val = new long[maxn][maxn];
    static boolean[] turn = new boolean[maxn];
    static int[] len = new int[maxn];
    
    static int n, m, c;
    static FastReader in;
    static PrintWriter out;

    public static void main(String[] args) {
        in = new FastReader();
        out = new PrintWriter(System.out);
        
        String s_n = in.next();
        if (s_n == null) return;
        n = Integer.parseInt(s_n);
        m = in.nextInt();
        c = in.nextInt();

        for (int i = 1; i <= c; i++) {
            len[i] = in.nextInt();
            for (int j = 1; j <= len[i]; j++) {
                int x = in.nextInt();
                int y = in.nextInt();
                int v = in.nextInt();
                
                poi[i][j] = new Point(x, y);
                bulb[x][y] = new Point(i, j);
                
                // val[i][j] = val[i][j-1] + v;
                // Java arrays are 0-initialized, so val[i][0] is 0.
                // We must ensure j-1 >= 0. Since j starts at 1, j-1=0 is valid.
                val[i][j] = val[i][j - 1] + v;
            }
        }

        for (int i = 1; i <= c; i++) {
            turn[i] = true;
        }

        while (in.next() != null) {
            String s = in.next();
            if (s.charAt(0) == 'S') {
                int idx = in.nextInt();
                turn[idx] = !turn[idx];
            } else {
                int x1 = in.nextInt();
                int y1 = in.nextInt();
                int x2 = in.nextInt();
                int y2 = in.nextInt();
                
                long ans = 0;
                
                // Top edge (y1)
                if (y1 != 1) {
                    for (int i = x1; i <= x2; i++) {
                        int tmp = bulb[i][y1].x;
                        Point p1 = bulb[i][y1 - 1];
                        Point p2 = bulb[i][y1];
                        
                        if (turn[tmp] && p1.x == tmp && Math.abs(p1.y - p2.y) == 1) {
                            if (p1.y < p2.y) ans -= val[tmp][p1.y];
                            else ans += val[tmp][p2.y];
                        }
                    }
                }
                
                // Left edge (x1)
                if (x1 != 1) {
                    for (int i = y1; i <= y2; i++) {
                        int tmp = bulb[x1][i].x;
                        Point p1 = bulb[x1 - 1][i];
                        Point p2 = bulb[x1][i];
                        
                        if (turn[tmp] && p1.x == tmp && Math.abs(p1.y - p2.y) == 1) {
                            if (p1.y < p2.y) ans -= val[tmp][p1.y];
                            else ans += val[tmp][p2.y];
                        }
                    }
                }
                
                // Right edge (y2)
                if (y2 != m) {
                    for (int i = x1; i <= x2; i++) {
                        int tmp = bulb[i][y2].x;
                        Point p1 = bulb[i][y2 + 1];
                        Point p2 = bulb[i][y2];
                        
                        if (turn[tmp] && p1.x == tmp && Math.abs(p1.y - p2.y) == 1) {
                            if (p1.y < p2.y) ans -= val[tmp][p1.y];
                            else ans += val[tmp][p2.y];
                        }
                    }
                }
                
                // Bottom edge (x2)
                if (x2 != n) {
                    for (int i = y1; i <= y2; i++) {
                        int tmp = bulb[x2][i].x;
                        Point p1 = bulb[x2 + 1][i];
                        Point p2 = bulb[x2][i];
                        
                        if (turn[tmp] && p1.x == tmp && Math.abs(p1.y - p2.y) == 1) {
                            if (p1.y < p2.y) ans -= val[tmp][p1.y];
                            else ans += val[tmp][p2.y];
                        }
                    }
                }
                
                // Add full bulbs inside
                for (int i = 1; i <= c; i++) {
                    if (turn[i]) {
                        Point t = poi[i][len[i]];
                        if (t.x >= x1 && t.x <= x2 && t.y >= y1 && t.y <= y2) {
                            ans += val[i][len[i]];
                        }
                    }
                }
                
                printLong(ans);
                out.println();
            }
        }
        out.flush();
    }
    
    static void printLong(long x) {
        if (x < 0) {
            out.print('-');
            x = -x;
        }
        if (x >= 10) {
            printLong(x / 10);
        } else {
            out.print((char)('0' + x));
        }
    }
}
```
One small fix: `turn` array size. `c` is read. `turn` is `new boolean[maxn]`.
If `c` >= `maxn`, it crashes.
I'll increase `maxn` to `2005` (as in original) but I should check if `c` can be larger.
Original: `const int maxn=2005;`.
`turn` is `bool turn[maxn]`.
If `c` is 2005, `turn[2005]` is out of bounds in C++ too?
In C++, `bool turn[2005]` has indices 0..2004.
So `turn[2005]` would be undefined behavior in C++.
Assuming inputs are within bounds of `maxn` (i.e., `c <= 2004` or `maxn` is effectively the size).
I will keep `maxn = 2005` to be faithful to the original code, assuming valid inputs.
However, to prevent runtime errors in Java (which throws exception), I'll stick to `2005`.
Wait, `len` is `int len[maxn]`. `len[i]` for `i` up to `c`.
If `c` is 2005, `len[2005]` is OOB.
I will assume the input constraints are consistent with `maxn`.

One detail: `scanf("%s",s)` reads a string. `s` is `char s[10]`.
In Java `String` is immutable. `s.charAt(0)` is fine.
The `next()` method in `FastReader` reads a token.
If the input is `S`, `s` becomes "S".
If the input is `1 2 3 4`, `s` becomes "1". `s.charAt(0)` is '1', which is not 'S'.
So the `else` branch is taken.
This matches the C++ logic.

Final check on `val` array initialization.
In C++, global arrays are zero-initialized.
In Java, global arrays are zero-initialized.
So `val[i][j-1]` for `j=1` is `val[i][0]` which is 0.
This is correct.

One detail: `turn` array.
`bool turn[maxn]` is global. Initialized to false.
In C++: `rep(i,1,c) turn[i]=1;` sets them to true.
In Java: `turn[i] = true;` is needed.
My code does this.

The `rt` function recursion.
If `x` is 0, `x >= 10` is false. `printLong(0)` prints '0'. Correct.
If `x` is 10, `x >= 10` is true. `printLong(1)` -> prints '1'. Then prints '0'. "10". Correct.
If `x` is -5. `x < 0`. Prints '-'. `x` becomes 5. `printLong(5)` -> prints '5'. "-5". Correct.

I will use `2005` for `maxn` as per original.
I will remove the `2006` comment and use `2005`.

One more thing: `turn[idx] = !turn[idx];`
If `idx` is 0, `turn[0]` is toggled.
In C++, `turn` is 1-based? `rep(i,1,c)`.
But `turn` is `bool turn[maxn]`.
The query `turn[rd()]` reads an index.
If the input index is 0, `turn[0]` is accessed.
In C++, `turn[0]` is false initially.
My code `turn[idx] = !turn[idx]` works for `idx=0` too.

I'll proceed with the code.
</think>

<CODE>
import java.io.*;
import java.util.StringTokenizer;

public class e_707 {
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    String line = br.readLine();
                    if (line == null) return null;
                    st = new StringTokenizer(line);
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            String s = next();
            if (s == null) return 0;
            return Integer.parseInt(s);
        }
        
        long rd() {
            String s = next();
            if (s == null) return 0;
            long res = 0;
            int f = 1;
            if (s.charAt(0) == '-') {
                f = -1;
                // substring from 1 to end
                res = -Long.parseLong(s.substring(1));
            } else {
                res = Long.parseLong(s);
            }
            return res;
        }
    }

    static final int maxn = 2005;
    static class Point {
        int x, y;
        Point(int x, int y) { this.x = x; this.y = y; }
    }

    static Point[][] bulb = new Point[maxn][maxn];
    static Point[][] poi = new Point[maxn][maxn];
    static long[][] val = new long[maxn][maxn];
    static boolean[] turn = new boolean[maxn];
    static int[] len = new int[maxn];
    
    static int n, m, c;
    static FastReader in;
    static PrintWriter out;

    public static void main(String[] args) {
        in = new FastReader();
        out = new PrintWriter(System.out);
        
        String s_n = in.next();
        if (s_n == null) return;
        n = Integer.parseInt(s_n);
        m = in.nextInt();
        c = in.nextInt();

        for (int i = 1; i <= c; i++) {
            len[i] = in.nextInt();
            for (int j = 1; j <= len[i]; j++) {
                int x = in.nextInt();
                int y = in.nextInt();
                int v = in.nextInt();
                
                poi[i][j] = new Point(x, y);
                bulb[x][y] = new Point(i, j);
                
                val[i][j] = val[i][j - 1] + v;
            }
        }

        for (int i = 1; i <= c; i++) {
            turn[i] = true;
        }

        while (in.next() != null) {
            String s = in.next();
            if (s.charAt(0) == 'S') {
                int idx = in.nextInt();
                turn[idx] = !turn[idx];
            } else {
                int x1 = in.nextInt();
                int y1 = in.nextInt();
                int x2 = in.nextInt();
                int y2 = in.nextInt();
                
                long ans = 0;
                
                // Check top edge (y1)
                if (y1 != 1) {
                    for (int i = x1; i <= x2; i++) {
                        int tmp = bulb[i][y1].x;
                        Point p1 = bulb[i][y1 - 1];
                        Point p2 = bulb[i][y1];
                        
                        if (turn[tmp] && p1.x == tmp && Math.abs(p1.y - p2.y) == 1) {
                            if (p1.y < p2.y) ans -= val[tmp][p1.y];
                            else ans += val[tmp][p2.y];
                        }
                    }
                }
                
                // Check left edge (x1)
                if (x1 != 1) {
                    for (int i = y1; i <= y2; i++) {
                        int tmp = bulb[x1][i].x;
                        Point p1 = bulb[x1 - 1][i];
                        Point p2 = bulb[x1][i];
                        
                        if (turn[tmp] && p1.x == tmp && Math.abs(p1.y - p2.y) == 1) {
                            if (p1.y < p2.y) ans -= val[tmp][p1.y];
                            else ans += val[tmp][p2.y];
                        }
                    }
                }
                
                // Check right edge (y2)
                if (y2 != m) {
                    for (int i = x1; i <= x2; i++) {
                        int tmp = bulb[i][y2].x;
                        Point p1 = bulb[i][y2 + 1];
                        Point p2 = bulb[i][y2];
                        
                        if (turn[tmp] && p1.x == tmp && Math.abs(p1.y - p2.y) == 1) {
                            if (p1.y < p2.y) ans -= val[tmp][p1.y];
                            else ans += val[tmp][p2.y];
                        }
                    }
                }
                
                // Check bottom edge (x2)
                if (x2 != n) {
                    for (int i = y1; i <= y2; i++) {
                        int tmp = bulb[x2][i].x;
                        Point p1 = bulb[x2 + 1][i];
                        Point p2 = bulb[x2][i];
                        
                        if (turn[tmp] && p1.x == tmp && Math.abs(p1.y - p2.y) == 1) {
                            if (p1.y < p2.y) ans -= val[tmp][p1.y];
                            else ans += val[tmp][p2.y];
                        }
                    }
                }
                
                // Add full bulbs inside
                for (int i = 1; i <= c; i++) {
                    if (turn[i]) {
                        Point t = poi[i][len[i]];
                        if (t.x >= x1 && t.x <= x2 && t.y >= y1 && t.y <= y2) {
                            ans += val[i][len[i]];
                        }
                    }
                }
                
                printLong(ans);
                out.println();
            }
        }
        out.flush();
    }
    
    static void printLong(long x) {
        if (x < 0) {
            out.print('-');
            x = -x;
        }
        if (x >= 10) {
            printLong(x / 10);
        } else {
            out.print((char)('0' + x));
        }
    }
}
</CODE>