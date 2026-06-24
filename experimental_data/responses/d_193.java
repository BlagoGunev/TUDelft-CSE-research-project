Translate this C++ code to Java code. The main class name should be d_193. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include <iostream>
#include <cstdio>
using namespace std;
#define lson x<<1
#define rson x<< 1 | 1
const int MAXN = 300009;
struct Segtree {
    int l, r, val, add, tol, tol2;
} St[MAXN << 2];
int p[MAXN], a[MAXN];
int n;
long long ans;
void Build (int x, int l, int r) {
    St[x].l = l, St[x].r = r;
    St[x].tol = r - l + 1;
    if (l == r) return;
    int mid = (l + r) >> 1;
    Build (lson, l, mid), Build (rson, mid + 1, r);
}
void push (int x) {
    if (St[x].add == 0) return;
    St[lson].add +=St[x].add, St[rson].add += St[x].add;
    St[lson].val += St[x].add, St[rson].val += St[x].add;
    St[x].add = 0;
}
void update (int x) {
    St[x].val = min (St[lson].val, St[rson].val);
    St[x].tol = St[lson].tol * (St[x].val == St[lson].val) + St[rson].tol * (St[x].val == St[rson].val);
    St[x].tol2=St[lson].tol*(St[x].val+1==St[lson].val)+St[rson].tol*(St[x].val+1==St[rson].val);
    St[x].tol2+=St[lson].tol2*(St[x].val==St[lson].val)+St[rson].tol2*(St[x].val==St[rson].val);
}
void Modify (int x, int l, int r, int key) {
    if (St[x].l >= l && St[x].r <= r) {
        St[x].val += key, St[x].add += key;
        return;
    }
    push (x);
    int mid = (St[x].l + St[x].r) >> 1;
    if (mid >= l) Modify (lson, l, r, key);
    if (mid < r) Modify (rson, l, r, key);
    update (x);
}
void Query (int x, int l, int r) {
    if (St[x].l >= l && St[x].r <= r) {
        ans += St[x].tol * (St[x].val <=2)+St[x].tol2*(St[x].val==1);
        return;
    }
    push (x);
    int mid = (St[x].l + St[x].r) >> 1;
    if (mid >= l) Query (lson, l, r);
    if (mid < r) Query (rson, l, r);
}
int main() {
    scanf ("%d", &n);
    for (int i = 1, x; i <= n; i++) {
        scanf ("%d", &x);
        p[x] = i;
    }
    Build (1, 1, n);
    for (int i = n; i; i--) {
        a[p[i]] = i;
        int x = a[p[i] - 1], y = a[p[i] + 1];
        if (x > y) swap (x, y);
        if (x) Modify (1, i, x - 1, 1), Modify (1, y, n, -1);
        else if (y) Modify (1, i, y - 1, 1);
        else Modify (1, i, n, 1);
        Query (1, i, n);
    }
    printf ("%I64d", ans-n);
}

Here is the translation plan:

1.  **Header Inclusion**: Replace `#include <iostream>` and `#include <cstdio>` with standard Java IO utilities. Since the original uses `scanf` and `printf` (C-style IO) for performance, I will use `BufferedReader` and `StringTokenizer` for input and `PrintWriter` for output.
2.  **Namespace**: The C++ code uses `using namespace std;`. In Java, we avoid this by explicitly naming classes.
3.  **Macros**: The C++ `#define` macros (`lson`, `rson`) are preprocessor macros. In Java, these must be translated to methods or inline logic. Since they are used inside functions, I will create helper methods `getLeftChild(x)` and `getRightChild(x)` or simply inline the logic `x << 1` and `(x << 1) | 1` directly in the Java methods to keep it clean and readable.
4.  **Constants**: `const int MAXN = 300009;` becomes a static final constant `MAXN`.
5.  **Struct**: The `struct Segtree` becomes a class `Segtree`.
6.  **Arrays**: C++ arrays `p` and `a` become Java arrays.
7.  **Main Function**: `main()` becomes `public static void main(String[] args)`.
8.  **I/O**:
    *   `scanf` becomes reading from `BufferedReader`.
    *   `printf` becomes writing to `PrintWriter`.
    *   `long long` (64-bit integer) in C++ is mapped to `long` in Java.
9.  **Bitwise Operations**: The C++ `>> 1` (shift right by 1) is equivalent to integer division by 2, which works the same in Java. `<< 1` is shift left by 2.
10. **Logic Flow**: The logic remains identical, but syntax changes (e.g., semicolons, curly braces, method calls).

Here is the Java code:

```CODE
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class d_193 {

    private static final int MAXN = 300009;

    // Helper to calculate left child index
    private static int getLeftChild(int x) {
        return x << 1;
    }

    // Helper to calculate right child index
    private static int getRightChild(int x) {
        return (x << 1) | 1;
    }

    static class Segtree {
        int l, r, val, add, tol, tol2;
    }

    static Segtree[] St;
    static int[] p;
    static int[] a;
    static int n;
    static long ans;

    public static void Build(int x, int l, int r) {
        St[x].l = l;
        St[x].r = r;
        St[x].tol = r - l + 1;
        if (l == r) return;
        int mid = (l + r) >> 1;
        Build(getLeftChild(x), l, mid);
        Build(getRightChild(x), mid + 1, r);
    }

    public static void push(int x) {
        if (St[x].add == 0) return;
        St[getLeftChild(x)].add += St[x].add;
        St[getRightChild(x)].add += St[x].add;
        St[getLeftChild(x)].val += St[x].add;
        St[getRightChild(x)].val += St[x].add;
        St[x].add = 0;
    }

    public static void update(int x) {
        int left = getLeftChild(x);
        int right = getRightChild(x);
        
        St[x].val = Math.min(St[left].val, St[right].val);
        
        St[x].tol = (St[left].tol * (St[x].val == St[left].val ? 1 : 0)) + 
                   (St[right].tol * (St[x].val == St[right].val ? 1 : 0));
                   
        St[x].tol2 = (St[left].tol * (St[x].val + 1 == St[left].val ? 1 : 0)) + 
                    (St[right].tol * (St[x].val + 1 == St[right].val ? 1 : 0)) +
                    St[left].tol2 * (St[x].val == St[left].val ? 1 : 0) + 
                    St[right].tol2 * (St[x].val == St[right].val ? 1 : 0);
    }

    public static void Modify(int x, int l, int r, int key) {
        if (St[x].l >= l && St[x].r <= r) {
            St[x].val += key;
            St[x].add += key;
            return;
        }
        push(x);
        int mid = (St[x].l + St[x].r) >> 1;
        if (mid >= l) Modify(getLeftChild(x), l, r, key);
        if (mid < r) Modify(getRightChild(x), l, r, key);
        update(x);
    }

    public static void Query(int x, int l, int r) {
        if (St[x].l >= l && St[x].r <= r) {
            ans += St[x].tol * (St[x].val <= 2 ? 1 : 0) + 
                   St[x].tol2 * (St[x].val == 1 ? 1 : 0);
            return;
        }
        push(x);
        int mid = (St[x].l + St[x].r) >> 1;
        if (mid >= l) Query(getLeftChild(x), l, r);
        if (mid < r) Query(getRightChild(x), l, r);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        if (st.hasMoreTokens()) {
            n = Integer.parseInt(st.nextToken());
        } else {
            // Handle case where input might be on a new line or empty (though unlikely based on problem)
            String line = br.readLine();
            if (line != null) st = new StringTokenizer(line);
            if (st.hasMoreTokens()) n = Integer.parseInt(st.nextToken());
        }
        
        p = new int[MAXN];
        a = new int[MAXN];
        St = new Segtree[MAXN << 2];
        
        for (int i = 1; i <= n; i++) {
            String line = br.readLine();
            while (line != null && line.trim().isEmpty()) {
                line = br.readLine();
            }
            if (line == null) break;
            st = new StringTokenizer(line);
            int x = Integer.parseInt(st.nextToken());
            p[x] = i;
        }
        
        Build(1, 1, n);
        
        for (int i = n; i >= 1; i--) {
            a[p[i]] = i;
            int x = a[p[i] - 1];
            int y = a[p[i] + 1];
            if (x > y) {
                int temp = x;
                x = y;
                y = temp;
            }
            if (x != 0) {
                Modify(1, i, x - 1, 1);
                if (y != 0) Modify(1, y, n, -1);
            } else if (y != 0) {
                Modify(1, i, y - 1, 1);
            } else {
                Modify(1, i, n, 1);
            }
            Query(1, i, n);
        }
        
        out.println(ans - n);
        out.flush();
    }
}
```

```CODE
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class d_193 {

    private static final int MAXN = 300009;

    // Helper to calculate left child index
    private static int getLeftChild(int x) {
        return x << 1;
    }

    // Helper to calculate right child index
    private static int getRightChild(int x) {
        return (x << 1) | 1;
    }

    static class Segtree {
        int l, r, val, add, tol, tol2;
    }

    static Segtree[] St;
    static int[] p;
    static int[] a;
    static int n;
    static long ans;

    public static void Build(int x, int l, int r) {
        St[x].l = l;
        St[x].r = r;
        St[x].tol = r - l + 1;
        if (l == r) return;
        int mid = (l + r) >> 1;
        Build(getLeftChild(x), l, mid);
        Build(getRightChild(x), mid + 1, r);
    }

    public static void push(int x) {
        if (St[x].add == 0) return;
        St[getLeftChild(x)].add += St[x].add;
        St[getRightChild(x)].add += St[x].add;
        St[getLeftChild(x)].val += St[x].add;
        St[getRightChild(x)].val += St[x].add;
        St[x].add = 0;
    }

    public static void update(int x) {
        int left = getLeftChild(x);
        int right = getRightChild(x);
        
        St[x].val = Math.min(St[left].val, St[right].val);
        
        St[x].tol = (St[left].tol * (St[x].val == St[left].val ? 1 : 0)) + 
                   (St[right].tol * (St[x].val == St[right].val ? 1 : 0));
                   
        St[x].tol2 = (St[left].tol * (St[x].val + 1 == St[left].val ? 1 : 0)) + 
                    (St[right].tol * (St[x].val + 1 == St[right].val ? 1 : 0)) +
                    St[left].tol2 * (St[x].val == St[left].val ? 1 : 0) + 
                    St[right].tol2 * (St[x].val == St[right].val ? 1 : 0);
    }

    public static void Modify(int x, int l, int r, int key) {
        if (St[x].l >= l && St[x].r <= r) {
            St[x].val += key;
            St[x].add += key;
            return;
        }
        push(x);
        int mid = (St[x].l + St[x].r) >> 1;
        if (mid >= l) Modify(getLeftChild(x), l, r, key);
        if (mid < r) Modify(getRightChild(x), l, r, key);
        update(x);
    }

    public static void Query(int x, int l, int r) {
        if (St[x].l >= l && St[x].r <= r) {
            ans += St[x].tol * (St[x].val <= 2 ? 1 : 0) + 
                   St[x].tol2 * (St[x].val == 1 ? 1 : 0);
            return;
        }
        push(x);
        int mid = (St[x].l + St[x].r) >> 1;
        if (mid >= l) Query(getLeftChild(x), l, r);
        if (mid < r) Query(getRightChild(x), l, r);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        if (st.hasMoreTokens()) {
            n = Integer.parseInt(st.nextToken());
        } else {
            // Handle case where input might be on a new line or empty (though unlikely based on problem)
            String line = br.readLine();
            if (line != null) st = new StringTokenizer(line);
            if (st.hasMoreTokens()) n = Integer.parseInt(st.nextToken());
        }
        
        p = new int[MAXN];
        a = new int[MAXN];
        St = new Segtree[MAXN << 2];
        
        for (int i = 1; i <= n; i++) {
            String line = br.readLine();
            while (line != null && line.trim().isEmpty()) {
                line = br.readLine();
            }
            if (line == null) break;
            st = new StringTokenizer(line);
            int x = Integer.parseInt(st.nextToken());
            p[x] = i;
        }
        
        Build(1, 1, n);
        
        for (int i = n; i >= 1; i--) {
            a[p[i]] = i;
            int x = a[p[i] - 1];
            int y = a[p[i] + 1];
            if (x > y) {
                int temp = x;
                x = y;
                y = temp;
            }
            if (x != 0) {
                Modify(1, i, x - 1, 1);
                if (y != 0) Modify(1, y, n, -1);
            } else if (y != 0) {
                Modify(1, i, y - 1, 1);
            } else {
                Modify(1, i, n, 1);
            }
            Query(1, i, n);
        }
        
        out.println(ans - n);
        out.flush();
    }
}
```

### Explanation of Translation

1.  **Class Structure**:
    *   The C++ `struct Segtree` is converted to a Java `static class Segtree`.
    *   Arrays `p`, `a`, and `St` are declared as `static` fields of the main class `d_193`.
    *   The `MAXN` constant is moved to `static final int`.

2.  **Macros and Logic**:
    *   `#define lson x<<1` and `#define rson x<< 1 | 1` are replaced by helper methods `getLeftChild(int x)` and `getRightChild(int x)`. This ensures the logic is preserved without relying on C++ preprocessor macros.
    *   Bitwise shift `>> 1` is used directly in Java as it behaves identically to integer division by 2.

3.  **Data Types**:
    *   C++ `long long` is mapped to Java `long`.
    *   C++ `int` is mapped to Java `int`.

4.  **Input/Output**:
    *   `scanf` is replaced by `BufferedReader` and `StringTokenizer` for robust and efficient parsing.
    *   `printf` is replaced by `PrintWriter`.
    *   The format specifier `%I64d` (used for 64-bit integers in MSVC C++) is handled by printing the Java `long` value directly.

5.  **Control Flow**:
    *   `swap(x, y)` is implemented using a temporary variable `temp` in Java.
    *   Ternary operators are used to replace C-style `if` checks for boolean conditions (e.g., `x > y ? 1 : 0`).

6.  **Memory Management**:
    *   Java does not require explicit memory deallocation (like `delete` in C++), so objects remain in memory until garbage collection.

7.  **Main Method**:
    *   The `main` function signature is updated to `public static void main(String[] args)`.
    *   `main` is now `static` so it can be called directly by the JVM.

8.  **Edge Case Handling**:
    *   Added checks for `StringTokenizer` to handle cases where input might be split across lines or contain empty lines, ensuring robustness compared to the C++ version which assumes a specific stream format.

9.  **Output**:
    *   `ans - n` is calculated and printed using `out.println()`.
    *   `out.flush()` is called at the end to ensure output is written to the console.

```CODE
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class d_193 {

    private static final int MAXN = 300009;

    // Helper to calculate left child index
    private static int getLeftChild(int x) {
        return x << 1;
    }

    // Helper to calculate right child index
    private static int getRightChild(int x) {
        return (x << 1) | 1;
    }

    static class Segtree {
        int l, r, val, add, tol, tol2;
    }

    static Segtree[] St;
    static int[] p;
    static int[] a;
    static int n;
    static long ans;

    public static void Build(int x, int l, int r) {
        St[x].l = l;
        St[x].r = r;
        St[x].tol = r - l + 1;
        if (l == r) return;
        int mid = (l + r) >> 1;
        Build(getLeftChild(x), l, mid);
        Build(getRightChild(x), mid + 1, r);
    }

    public static void push(int x) {
        if (St[x].add == 0) return;
        St[getLeftChild(x)].add += St[x].add;
        St[getRightChild(x)].add += St[x].add;
        St[getLeftChild(x)].val += St[x].add;
        St[getRightChild(x)].val += St[x].add;
        St[x].add = 0;
    }

    public static void update(int x) {
        int left = getLeftChild(x);
        int right = getRightChild(x);
        
        St[x].val = Math.min(St[left].val, St[right].val);
        
        St[x].tol = (St[left].tol * (St[x].val == St[left].val ? 1 : 0)) + 
                   (St[right].tol * (St[x].val == St[right].val ? 1 : 0));
                   
        St[x].tol2 = (St[left].tol * (St[x].val + 1 == St[left].val ? 1 : 0)) + 
                    (St[right].tol * (St[x].val + 1 == St[right].val ? 1 : 0)) +
                    St[left].tol2 * (St[x].val == St[left].val ? 1 : 0) + 
                    St[right].tol2 * (St[x].val == St[right].val ? 1 : 0);
    }

    public static void Modify(int x, int l, int r, int key) {
        if (St[x].l >= l && St[x].r <= r) {
            St[x].val += key;
            St[x].add += key;
            return;
        }
        push(x);
        int mid = (St[x].l + St[x].r) >> 1;
        if (mid >= l) Modify(getLeftChild(x), l, r, key);
        if (mid < r) Modify(getRightChild(x), l, r, key);
        update(x);
    }

    public static void Query(int x, int l, int r) {
        if (St[x].l >= l && St[x].r <= r) {
            ans += St[x].tol * (St[x].val <= 2 ? 1 : 0) + 
                   St[x].tol2 * (St[x].val == 1 ? 1 : 0);
            return;
        }
        push(x);
        int mid = (St[x].l + St[x].r) >> 1;
        if (mid >= l) Query(getLeftChild(x), l, r);
        if (mid < r) Query(getRightChild(x), l, r);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        
        // Read n
        String line = br.readLine();
        if (line == null) return;
        StringTokenizer st = new StringTokenizer(line);
        if (!st.hasMoreTokens()) {
            line = br.readLine();
            if (line != null) st = new StringTokenizer(line);
        }
        n = Integer.parseInt(st.nextToken());
        
        p = new int[MAXN];
        a = new int[MAXN];
        St = new Segtree[MAXN << 2];
        
        // Read array p
        for (int i = 1; i <= n; i++) {
            while (!st.hasMoreTokens()) {
                line = br.readLine();
                if (line == null) break;
                st = new StringTokenizer(line);
            }
            if (!st.hasMoreTokens()) break;
            int x = Integer.parseInt(st.nextToken());
            p[x] = i;
        }
        
        Build(1, 1, n);
        
        for (int i = n; i >= 1; i--) {
            a[p[i]] = i;
            int x = a[p[i] - 1];
            int y = a[p[i] + 1];
            if (x > y) {
                int temp = x;
                x = y;
                y = temp;
            }
            if (x != 0) {
                Modify(1, i, x - 1, 1);
                if (y != 0) Modify(1, y, n, -1);
            } else if (y != 0) {
                Modify(1, i, y - 1, 1);
            } else {
                Modify(1, i, n, 1);
            }
            Query(1, i, n);
        }
        
        out.println(ans - n);
        out.flush();
    }
}
```