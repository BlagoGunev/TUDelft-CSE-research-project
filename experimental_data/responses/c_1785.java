Translate this C++ code to Java code. The main class name should be c_1785. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include <vector>

#include <iostream>

#include <algorithm>

using namespace std;



#define endl '\n'

using LL=long long;

constexpr int N=2e5+10,INF=1e9;



struct SegmentTree {

    #define lch (u<<1)

    #define rch (u<<1|1)

    constexpr static int MAXSIZE=N;



    struct Node {

        int l,r;

        int min,laz;

    } tr[MAXSIZE<<2];



    void pushup(int u) {

        tr[u].min=min(tr[lch].min,tr[rch].min);

    }



    void update(int u,int cnt,int val) {

        tr[u].min+=val,tr[u].laz+=val;

    }



    void pushdn(int u) {

        update(lch, 0, tr[u].laz);

        update(rch, 0, tr[u].laz);

        tr[u].laz=0;

    }



    void modify(int u,int l,int r,int cnt,int val) {

        if(tr[u].l>=l&&tr[u].r<=r) { update(u, cnt, val); }

        else {

            pushdn(u);

            int mid=tr[u].l+tr[u].r>>1;

            if(mid>=l) modify(lch, l, r, cnt, val);

            if(mid<r) modify(rch, l, r, cnt, val);

            pushup(u);

        }

    }



    int find(int u) {

        if(tr[u].min>=0) return 0;

        if(tr[u].l==tr[u].r) return tr[u].l;

        pushdn(u);

        int res=find(lch);

        if(res) return res;

        return find(rch);

    }



    void build(int u,int l,int r) {

        tr[u]={l,r};

        if(l==r) { tr[u].min=l; }

        else {

            int mid=l+r>>1;

            build(lch, l, mid);

            build(rch, mid+1, r);

            pushup(u);

        }

    }



    #undef lch

    #undef rch

} sgt;



void solve() {

    int n;

    cin>>n;

    LL sum=0,tot=0;

    sgt.build(1, 1, n+1);

    for(int i=1;i<=n;i++) {

        int cur;

        cin>>cur;

        tot++,sum+=cur;

        sgt.modify(1, cur, cur, 1, 0);

        sgt.modify(1, cur, n+1, 0, -1);

        int pos=sgt.find(1);

        if(pos) {

            tot--,sum-=pos;

            sgt.modify(1, pos, pos, -1, 0);

            sgt.modify(1, pos, n+1, 0, 1);

        }

        cout<<sum-tot*(tot+1)/2<<" \n"[i==n];

    }

}



int main() {

    ios::sync_with_stdio(0);

    cin.tie(nullptr);

    int t;

    cin>>t;

    while(t--) solve();

    return 0;

}

Here is the plan for translating the C++ code to Java:

### Plan
1.  **Class Structure**:
    *   Create a public class named `c_1785`.
    *   Create a static inner class `SegmentTree` to encapsulate the segment tree logic.
    *   Create a static method `solve()` corresponding to the C++ `solve()` function.
    *   Create a `main()` method to handle input/output and loop over test cases.

2.  **Data Types**:
    *   C++ `long long` (`LL`) maps to Java `long`.
    *   C++ `int` maps to Java `int`.
    *   C++ `constexpr` and `#define` constants map to Java `static final` constants.
    *   C++ `#undef` is not needed in Java.

3.  **Input/Output**:
    *   C++ `cin`, `cout` map to Java `Scanner` or `BufferedReader` + `PrintWriter`. Given the constraints ($N=2e5$), `Scanner` might be too slow. I will use `BufferedReader` and `StringTokenizer` for efficiency, and `PrintWriter` for output.
    *   C++ `ios::sync_with_stdio(0); cin.tie(nullptr);` is handled by using `BufferedReader` and `PrintWriter` which are already decoupled or explicitly managed.

4.  **Segment Tree Implementation**:
    *   The C++ code uses macros `lch` and `rch` for children indices (`u<<1` and `u<<1|1`). In Java, we cannot use macros inside a struct. We will replace these with explicit methods `lch(int u)` and `rch(int u)` or simple expressions `(u << 1)` and `(u << 1) + 1`.
    *   The C++ code uses an array `tr` of a `Node` struct. In Java, this becomes an array of objects `Node[]`.
    *   The `Node` class will contain fields `l`, `r`, `min`, and `laz`.
    *   The array size in C++ is `N << 2` (approx $4 \times N$). In Java, arrays are indexed 0 to `size-1`. The logic needs to be adjusted to fit Java array indexing (usually 1-based indexing for the root is kept for convenience in competitive programming, so the array size needs to be sufficient).
    *   **Note on Array Size**: In C++, `MAXSIZE=N` and `tr[MAXSIZE<<2]` creates an array of size $N \times 4$. In Java, if we use 1-based indexing for the root (index 1), the max index will be roughly $4N$. The array size should be set to $4 \times 200010$ (approx $800040$) to be safe, or simply calculate it dynamically. Since $N$ is defined as `2e5+10`, let's set the array size to `4 * (N + 1)`.

5.  **Logic Translation**:
    *   Bitwise operators `>>` and `<<` work the same in Java.
    *   `min` function in C++ needs to be replaced with `Math.min`.
    *   `endl` macro is replaced with `\n`.
    *   The logic inside `solve` (reading input, updating tree, finding min, printing) remains largely the same but uses Java syntax.

6.  **Incremental Tasks**:
    *   Step 1: Define constants and the `Node` class.
    *   Step 2: Implement `SegmentTree` methods (`pushup`, `update`, `pushdn`, `modify`, `find`, `build`).
    *   Step 3: Implement the `solve` logic.
    *   Step 4: Implement `main` with `BufferedReader` and `PrintWriter`.

### Java Code

```java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class c_1785 {

    // Constants
    static final int N = 200010;
    static final int INF = 1000000000;
    static final int MAXSIZE = N;

    // Segment Tree Node
    static class Node {
        int l;
        int r;
        int min;
        int laz;
    }

    // Segment Tree Array
    static Node[] tr;
    static int MAX_NODES;

    static {
        // Initialize array size. C++ uses N<<2. 
        // Since N is 200010, max index is roughly 4*N. 
        // We use 1-based indexing for root (index 1), so size needs to be 4*N + padding.
        // 200010 * 4 = 800040. Let's add a bit more safety margin.
        MAX_NODES = (N + 1) * 4 + 10;
        tr = new Node[MAX_NODES];
    }

    // Segment Tree Implementation
    static class SegmentTree {
        static Node[] tr;
        static int MAX_NODES;

        static {
            tr = new Node[MAX_NODES];
        }

        static void init(int size) {
            // In C++, MAXSIZE is fixed. Here we ensure the array is large enough.
            // We assume the array is already allocated in the static block or passed.
        }

        static void pushup(int u) {
            tr[u].min = Math.min(tr[u << 1].min, tr[(u << 1) | 1].min);
        }

        static void update(int u, int cnt, int val) {
            tr[u].min += val;
            tr[u].laz += val;
        }

        static void pushdn(int u) {
            if (tr[u].laz != 0) {
                update(u << 1, 0, tr[u].laz);
                update((u << 1) | 1, 0, tr[u].laz);
                tr[u].laz = 0;
            }
        }

        static void modify(int u, int l, int r, int cnt, int val) {
            if (tr[u].l >= l && tr[u].r <= r) {
                update(u, cnt, val);
            } else {
                pushdn(u);
                int mid = (tr[u].l + tr[u].r) >> 1;
                if (mid >= l) modify(u << 1, l, r, cnt, val);
                if (mid < r) modify((u << 1) | 1, l, r, cnt, val);
                pushup(u);
            }
        }

        static int find(int u) {
            if (tr[u].min >= 0) return 0;
            if (tr[u].l == tr[u].r) return tr[u].l;
            pushdn(u);
            int res = find(u << 1);
            if (res != 0) return res;
            return find((u << 1) | 1);
        }

        static void build(int u, int l, int r) {
            tr[u] = new Node();
            tr[u].l = l;
            tr[u].r = r;
            if (l == r) {
                tr[u].min = l;
            } else {
                int mid = (l + r) >> 1;
                build(u << 1, l, mid);
                build((u << 1) | 1, mid + 1, r);
                pushup(u);
            }
        }
    }

    static void solve() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // We need a shared tokenizer or read line by line. 
        // However, for competitive programming, usually we create a tokenizer helper or read carefully.
        // Since the logic is sequential, let's assume we can read tokens one by one.
        // But wait, the solve method is called inside a loop in main. 
        // We need to handle token reading globally or pass a tokenizer.
        // Let's refactor to use a static tokenizer in main loop context or pass it.
        // Actually, looking at the C++ code, 'cin >> n' happens inside solve. 
        // We will implement a simple static tokenizer to handle the stream.
        
        // To make this work cleanly, we need to access the tokenizer from inside solve.
        // Let's declare a static tokenizer in the class.
        // But wait, the solve method is called inside a while loop in main.
        // The tokenizer needs to be accessible.
        
        // Let's adjust the structure slightly to allow passing the tokenizer or using a static one.
        // Since I can't easily change the structure of 'solve' to take an argument without changing the signature too much,
        // I will rely on a static tokenizer that gets populated in 'main'.
        
        // Re-reading C++ code: 'solve' is called inside 'while(t--)'.
        // It reads 'n', then loops 'n' times.
        // So we need a global tokenizer.
    }
    
    // Refactoring to support static tokenizer for IO
    static StringTokenizer st;
    static BufferedReader br;
    static PrintWriter out;

    static String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            String line = br.readLine();
            if (line == null) return null;
            st = new StringTokenizer(line);
        }
        return st.nextToken();
    }

    static int nextInt() throws IOException {
        String s = next();
        if (s == null) throw new IOException("End of input");
        return Integer.parseInt(s);
    }

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        
        String tStr = next();
        if (tStr == null) return;
        int t = Integer.parseInt(tStr);
        
        while (t-- > 0) {
            solve();
        }
        out.flush();
    }

    static void solve() throws IOException {
        int n = nextInt();
        long sum = 0;
        long tot = 0;
        
        // Build Segment Tree
        // In C++, sgt.build(1, 1, n+1);
        // We need to clear the tree or ensure it's built correctly.
        // The C++ code builds a fresh tree every time.
        // In Java, we need to initialize the array nodes.
        // Since N is up to 2e5, we can't reallocate the whole array every time if T is large.
        // But the C++ code reuses the global 'tr' array.
        // We must clear the relevant parts of 'tr'.
        
        // Note: In C++, the array is static and global.
        // In Java, we can reuse the static 'tr' array if we clear it.
        // However, the build function creates new Nodes.
        // Let's implement a build that reuses the static array.
        
        // We need to ensure the static 'tr' array is large enough.
        // We defined MAX_NODES based on N.
        // But N changes per test case. The max N is 200010.
        // So the static array should be sized for the max possible N.
        
        // Build tree for range [1, n+1]
        // We need to clear the tree for the range [1, n+1] before building?
        // The C++ code builds it from scratch.
        // But the static array 'tr' persists. We must clear it.
        // Actually, the C++ code does `tr[u] = {l, r}` in build.
        // Wait, `tr` is an array of objects.
        // In C++, `tr[u] = {l,r}` initializes the object.
        // In Java, we need to do `tr[u] = new Node();` inside build.
        // But if we create new objects every time, it might be slow (GC pressure).
        // However, for competitive programming in Java, usually `new Node()` is acceptable if T is small or if we reuse.
        // Given the constraints, let's just use `new Node()` inside `build` to match C++ semantics exactly,
        // but ensure the array is sized correctly.
        
        // Wait, the C++ code uses `tr[MAXSIZE<<2]`.
        // If we do `new Node()`, we allocate memory.
        // Let's stick to the logic:
        // `tr` is a static array of references.
        // We initialize it once in static block.
        // Inside `build`, we create a new Node instance.
        // This is safe for Java.
        
        // Wait, if we do `new Node()` inside `build`, we are creating garbage.
        // Is it better to reuse the static array slots?
        // In C++, `tr[u] = {l, r}` sets the fields of the existing object at index u.
        // In Java, `tr[u] = new Node()` replaces the reference.
        // If we want to be efficient, we should reuse the static array objects.
        // Let's create a `clear` method or just ensure `tr` is clean.
        // Actually, the C++ code builds the tree from 1 to n+1.
        // We should ensure that before `build`, the nodes are clean or just overwritten.
        // Since `build` overwrites `l`, `r`, `min`, `laz`, we can just reuse the static array objects.
        // We just need to make sure `tr[u]` is not null or garbage.
        // Let's assume the static array is pre-filled with nulls or we create them.
        // To be safe and fast, let's create a helper to init the tree.
        
        // Actually, looking at the C++ code:
        // `Node tr[MAXSIZE<<2];` creates the array.
        // `build` function does `tr[u] = {l,r}`. This creates a new object? No, in C++ struct is value type.
        // In Java, we have references.
        // If we do `tr[u] = new Node()`, we allocate.
        // If we do `tr[u] = new Node(); tr[u].l = l...`, we allocate.
        // Let's just allocate new Nodes inside build for simplicity and correctness, 
        // but we must ensure the array size is sufficient for the max N across all test cases.
        // Wait, if we allocate new Nodes every time, we might run out of memory or time if T is large.
        // But the problem statement doesn't specify T. Usually T is around 10-100.
        // Allocating 800k objects per test case is heavy.
        // Let's optimize: Reuse the static array.
        // We need to clear the nodes in the range [1, n+1] before building?
        // Or just overwrite them.
        // Since `build` sets all fields, overwriting is enough.
        // But we need to ensure `tr[u]` is not null.
        // We can initialize the static array with nulls in the static block.
        // Then in `build`, we do `tr[u] = new Node()`.
        // Wait, if we do `new Node()`, we allocate.
        // To avoid allocation, we should do `tr[u].l = l` etc.
        // But we need to ensure `tr[u]` is not null.
        // Let's assume we keep the static array populated with default Nodes.
        // But we don't have a `clear` function in C++.
        // The C++ code builds it fresh.
        // Let's implement `build` to allocate new nodes. It's safer for logic correctness.
        // If performance is an issue, we can optimize later.
        // But wait, `MAXSIZE` is `2e5+10`.
        // The array size is `MAXSIZE << 2`.
        // If `n` is small in a test case, but large in another, we need the array to cover the max `n`.
        // Let's assume the max `n` is `N`.
        
        // Wait, the C++ code declares `tr` globally.
        // So we just need to make sure `tr` is big enough.
        // And inside `build`, we create new objects.
        // Let's do that.
        
        // Re-initializing the tree for the current test case
        // We need to clear the tree for the range [1, n+1]
        // But wait, the previous test case might have used a larger n.
        // We should only clear the nodes we are going to use?
        // Or just build fresh.
        // The C++ code does `sgt.build(1, 1, n+1)`.
        // This overwrites the nodes.
        // So we just need to ensure `tr` is big enough.
        
        // Wait, `tr` is static.
        // If test case 1 uses n=100, it builds up to 101.
        // Test case 2 uses n=200000, it builds up to 200001.
        // The array must be sized for the MAX possible N.
        // So we define `MAX_NODES` based on the global constant `N`.
        
        // Let's proceed with allocating new Nodes inside build.
        // But wait, `tr` is a static array.
        // If we do `tr[u] = new Node()`, we are allocating memory.
        // Is it better to have a pool of Nodes?
        // Let's just do `new Node()`. It's the direct translation.
        
        // Wait, I need to handle the static array `tr` properly.
        // In the static block, I allocated `tr`.
        // But `tr` is an array of objects.
        // If I do `tr[u] = new Node()` inside `build`, I am replacing the reference.
        // This is fine.
        
        // Wait, I need to handle the `tr` array initialization.
        // In C++, `Node tr[MAXSIZE<<2]` creates an array of default constructed Nodes.
        // In Java, `new Node[MAXSIZE<<2]` creates an array of nulls.
        // So we must create the Nodes before using them.
        // We can do this in a `init` method or inside `build`.
        // Let's do it inside `build` to match C++ behavior (lazy init).
        // But we must ensure `tr` is sized for the max possible N.
        // Let's define `MAX_NODES` based on `N` (200010).
        
        // Wait, if I use `new Node()`, I am creating garbage.
        // Let's try to reuse the static array to avoid GC.
        // We can create all Nodes in the static block.
        // Then in `build`, we just set fields.
        // This is more efficient.
        
        // Let's implement the static block to fill `tr` with Nodes.
        // But `MAX_NODES` depends on `N`.
        // If `N` is 200010, `MAX_NODES` is 800040.
        // We can create 800040 Nodes in the static block.
        // Then in `build`, we just set fields.
        // But wait, `build` logic depends on `l` and `r`.
        // If we reuse nodes, we must ensure they are clean.
        // Since `build` sets `l`, `r`, `min`, `laz`, it overwrites everything.
        // So we don't need to clear.
        // We just need to ensure `tr[u]` is not null.
        // So we pre-fill `tr` with new Node()s.
        
        // Wait, the array size is fixed in C++.
        // So we fix the array size in Java.
        // `MAX_NODES = (N + 1) * 4 + 10;`
        // `tr = new Node[MAX_NODES];`
        // Then fill it.
        
        // Wait, I need to make sure the `tr` array is accessible inside `SegmentTree` class.
        // I can make `tr` static in `SegmentTree` class or a static variable in `c_1785`.
        // The C++ code has `struct SegmentTree` and `Node tr[MAXSIZE<<2]` inside it.
        // So `tr` should be inside `SegmentTree` class.
        // But in Java, static fields inside a class are shared.
        // So `SegmentTree.tr` should be static.
        // And `MAX_NODES` should be static.
        
        // Let's refine the `SegmentTree` class to be static and hold the static array.
        
        // Wait, I need to handle the `solve` method.
        // It reads `n`.
        // It builds the tree.
        // It loops `n` times.
        // It reads `cur`.
        // It updates tree.
        // It finds min.
        // It updates tree.
        // It prints.
        
        // One detail: `cout << ... << " \n"[i==n]`
        // This prints a space if `i==n` else a newline?
        // No, `" \n"` is a string of length 2.
        // `" \n"[0]` is space. `" \n"[1]` is newline.
        // If `i==n`, index is 1 (newline).
        // If `i!=n`, index is 0 (space).
        // So it prints `sum-tot*(tot+1)/2` followed by space if not last, newline if last.
        // This is standard competitive programming output format.
        
        // Let's implement.
    }
}
```

Wait, I should not put the whole logic in `solve` inside the `main` loop if I can't access the tokenizer.
I will put the `solve` logic in a static method `solve()` and call it from `main`.
I need to make sure `st` and `br` are static so `solve` can access them.

One correction on the array size:
In C++, `MAXSIZE = 2e5+10`.
`tr[MAXSIZE << 2]` is an array of size `(200010) * 4`.
In Java, `MAX_NODES` should be `(N + 1) * 4`.
Let's calculate: `200010 * 4 = 800040`.
Let's add a bit more padding just in case.

Also, `sgt.build(1, 1, n+1)`.
The tree covers range `[1, n+1]`.
The size of the tree array must accommodate the index `n+1`.
The index `u` grows.
Max index is roughly `4 * (n+1)`.
So `MAX_NODES` must be based on the maximum possible `n` across all test cases.
Since `N` is defined as `2e5+10`, we assume `n` <= `N`.
So `MAX_NODES` = `(N + 1) * 4 + 10` is safe.

Let's write the code.

```java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class c_1785 {

    // Constants
    static final int N = 200010;
    static final int INF = 1000000000;
    // MAXSIZE is 2e5+10. 
    // The tree array size is MAXSIZE << 2.
    // We need to calculate this value.
    // 200010 * 4 = 800040.
    // Let's use 800050 to be safe.
    static final int MAX_NODES = (N + 1) * 4 + 10;

    // Segment Tree Node
    static class Node {
        int l;
        int r;
        int min;
        int laz;
    }

    // Segment Tree Array
    static Node[] tr;

    // IO Helpers
    static BufferedReader br;
    static StringTokenizer st;
    static PrintWriter out;

    static {
        tr = new Node[MAX_NODES];
        // Initialize the array with nodes to avoid null checks in build
        for(int i=0; i<MAX_NODES; i++) {
            tr[i] = new Node();
        }
    }

    // Segment Tree Implementation
    static class SegmentTree {
        // Access static tr
        static Node[] tr;
        static int MAX_NODES;

        static {
            tr = new Node[MAX_NODES];
            for(int i=0; i<MAX_NODES; i++) {
                tr[i] = new Node();
            }
        }

        static void pushup(int u) {
            tr[u].min = Math.min(tr[u << 1].min, tr[(u << 1) | 1].min);
        }

        static void update(int u, int cnt, int val) {
            tr[u].min += val;
            tr[u].laz += val;
        }

        static void pushdn(int u) {
            if (tr[u].laz != 0) {
                update(u << 1, 0, tr[u].laz);
                update((u << 1) | 1, 0, tr[u].laz);
                tr[u].laz = 0;
            }
        }

        static void modify(int u, int l, int r, int cnt, int val) {
            if (tr[u].l >= l && tr[u].r <= r) {
                update(u, cnt, val);
            } else {
                pushdn(u);
                int mid = (tr[u].l + tr[u].r) >> 1;
                if (mid >= l) modify(u << 1, l, r, cnt, val);
                if (mid < r) modify((u << 1) | 1, l, r, cnt, val);
                pushup(u);
            }
        }

        static int find(int u) {
            if (tr[u].min >= 0) return 0;
            if (tr[u].l == tr[u].r) return tr[u].l;
            pushdn(u);
            int res = find(u << 1);
            if (res != 0) return res;
            return find((u << 1) | 1);
        }

        static void build(int u, int l, int r) {
            tr[u] = new Node(); // Re-allocate to ensure clean state
            tr[u].l = l;
            tr[u].r = r;
            if (l == r) {
                tr[u].min = l;
            } else {
                int mid = (l + r) >> 1;
                build(u << 1, l, mid);
                build((u << 1) | 1, mid + 1, r);
                pushup(u);
            }
        }
    }

    static void solve() throws IOException {
        String s = next();
        if (s == null) return;
        int n = Integer.parseInt(s);
        
        long sum = 0;
        long tot = 0;
        
        // Build Segment Tree
        // Range [1, n+1]
        SegmentTree.build(1, 1, n + 1);
        
        for (int i = 1; i <= n; i++) {
            int cur = nextInt();
            tot++;
            sum += cur;
            
            // sgt.modify(1, cur, cur, 1, 0);
            SegmentTree.modify(1, cur, cur, 1, 0);
            
            // sgt.modify(1, cur, n+1, 0, -1);
            SegmentTree.modify(1, cur, n + 1, 0, -1);
            
            // int pos=sgt.find(1);
            int pos = SegmentTree.find(1);
            
            if (pos != 0) {
                tot--;
                sum -= pos;
                // sgt.modify(1, pos, pos, -1, 0);
                SegmentTree.modify(1, pos, pos, -1, 0);
                // sgt.modify(1, pos, n+1, 0, 1);
                SegmentTree.modify(1, pos, n + 1, 0, 1);
            }
            
            // cout<<sum-tot*(tot+1)/2<<" \n"[i==n];
            long ans = sum - tot * (tot + 1) / 2;
            if (i == n) {
                out.println(ans);
            } else {
                out.print(ans + " ");
            }
        }
    }

    static String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            String line = br.readLine();
            if (line == null) return null;
            st = new StringTokenizer(line);
        }
        return st.nextToken();
    }

    static int nextInt() throws IOException {
        String s = next();
        if (s == null) throw new IOException("End of input");
        return Integer.parseInt(s);
    }

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        
        String tStr = next();
        if (tStr != null) {
            int t = Integer.parseInt(tStr);
            while (t-- > 0) {
                solve();
            }
        }
        out.flush();
    }
}
```

Wait, there is a small issue in the `SegmentTree` class.
I defined `static Node[] tr;` inside `SegmentTree` and also `static Node[] tr;` in `c_1785`.
This is redundant. I should use the one in `c_1785` and make it accessible to `SegmentTree`.
Or better, put `tr` in `c_1785` and make `SegmentTree` methods access it via `c_1785.tr`.
But since `SegmentTree` is a static inner class, it can access static members of the outer class.
So `SegmentTree.build` can call `c_1785.tr[u]` or just `tr[u]` if `tr` is static in `c_1785`.
Wait, if I define `static Node[] tr` in `c_1785`, and `SegmentTree` is a static inner class of `c_1785`, then `SegmentTree` can access `c_1785.tr` as `tr`.
So I will remove the `tr` declaration from `SegmentTree` and use the one from `c_1785`.
Also, the initialization logic in `SegmentTree` static block is redundant if `c_1785` does it.
I will move the initialization to `c_1785` static block.
And `SegmentTree` methods will use `tr`.

Also, I need to make sure `MAX_NODES` is consistent.
I defined `MAX_NODES` in `c_1785`.
I will remove `MAX_NODES` from `SegmentTree` and use `c_1785.MAX_NODES`.

One more thing: The C++ code uses `sgt` as the instance of `SegmentTree`.
In Java, since `tr` is static, we don't need an instance. We can just use the static methods.
So `sgt.build(...)` becomes `SegmentTree.build(...)`.

Let's refine the code structure.

```java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class c_1785 {

    // Constants
    static final int N = 200010;
    static final int INF = 1000000000;
    // MAXSIZE is 2e5+10. 
    // The tree array size is MAXSIZE << 2.
    // We need to calculate this value.
    // 200010 * 4 = 800040.
    // Let's use 800050 to be safe.
    static final int MAX_NODES = (N + 1) * 4 + 10;

    // Segment Tree Node
    static class Node {
        int l;
        int r;
        int min;
        int laz;
    }

    // Segment Tree Array
    static Node[] tr;

    // IO Helpers
    static BufferedReader br;
    static StringTokenizer st;
    static PrintWriter out;

    static {
        tr = new Node[MAX_NODES];
        // Initialize the array with nodes to avoid null checks in build
        for(int i=0; i<MAX_NODES; i++) {
            tr[i] = new Node();
        }
    }

    // Segment Tree Implementation
    static class SegmentTree {
        static void pushup(int u) {
            tr[u].min = Math.min(tr[u << 1].min, tr[(u << 1) | 1].min);
        }

        static void update(int u, int cnt, int val) {
            tr[u].min += val;
            tr[u].laz += val;
        }

        static void pushdn(int u) {
            if (tr[u].laz != 0) {
                update(u << 1, 0, tr[u].laz);
                update((u << 1) | 1, 0, tr[u].laz);
                tr[u].laz = 0;
            }
        }

        static void modify(int u, int l, int r, int cnt, int val) {
            if (tr[u].l >= l && tr[u].r <= r) {
                update(u, cnt, val);
            } else {
                pushdn(u);
                int mid = (tr[u].l + tr[u].r) >> 1;
                if (mid >= l) modify(u << 1, l, r, cnt, val);
                if (mid < r) modify((u << 1) | 1, l, r, cnt, val);
                pushup(u);
            }
        }

        static int find(int u) {
            if (tr[u].min >= 0) return 0;
            if (tr[u].l == tr[u].r) return tr[u].l;
            pushdn(u);
            int res = find(u << 1);
            if (res != 0) return res;
            return find((u << 1) | 1);
        }

        static void build(int u, int l, int r) {
            // In C++, tr[u] = {l,r};
            // In Java, we need to ensure tr[u] is not null.
            // Since we initialized the array in static block, it should not be null.
            // But we need to reset it to a clean state?
            // The C++ code does `tr[u] = {l,r}` which overwrites the struct.
            // In Java, we just set the fields.
            // But we must ensure `tr[u]` is not null.
            // Since we initialized the array in static block, it is not null.
            // However, we need to reset `min` and `laz`?
            // `build` logic:
            // tr[u].l = l;
            // tr[u].r = r;
            // if (l == r) { tr[u].min = l; }
            // else { ... pushup(u); }
            // pushup sets min based on children.
            // So we don't need to reset min/laz explicitly if we overwrite them.
            // But wait, `laz` is not set in the `if (l==r)` block.
            // In C++, `Node tr[MAXSIZE<<2];` initializes `laz` to 0.
            // So `laz` is 0 initially.
            // In `build`, if `l==r`, `min` is set. `laz` remains 0.
            // If `l!=r`, `pushup` is called. `pushup` sets `min`. `laz` is not touched in `pushup`.
            // So `laz` remains 0 (from initialization).
            // So we just need to set `l` and `r`.
            
            tr[u].l = l;
            tr[u].r = r;
            if (l == r) {
                tr[u].min = l;
            } else {
                int mid = (l + r) >> 1;
                build(u << 1, l, mid);
                build((u << 1) | 1, mid + 1, r);
                pushup(u);
            }
        }
    }

    static void solve() throws IOException {
        String s = next();
        if (s == null) return;
        int n = Integer.parseInt(s);
        
        long sum = 0;
        long tot = 0;
        
        // Build Segment Tree
        // Range [1, n+1]
        SegmentTree.build(1, 1, n + 1);
        
        for (int i = 1; i <= n; i++) {
            int cur = nextInt();
            tot++;
            sum += cur;
            
            // sgt.modify(1, cur, cur, 1, 0);
            SegmentTree.modify(1, cur, cur, 1, 0);
            
            // sgt.modify(1, cur, n+1, 0, -1);
            SegmentTree.modify(1, cur, n + 1, 0, -1);
            
            // int pos=sgt.find(1);
            int pos = SegmentTree.find(1);
            
            if (pos != 0) {
                tot--;
                sum -= pos;
                // sgt.modify(1, pos, pos, -1, 0);
                SegmentTree.modify(1, pos, pos, -1, 0);
                // sgt.modify(1, pos, n+1, 0, 1);
                SegmentTree.modify(1, pos, n + 1, 0, 1);
            }
            
            // cout<<sum-tot*(tot+1)/2<<" \n"[i==n];
            long ans = sum - tot * (tot + 1) / 2;
            if (i == n) {
                out.println(ans);
            } else {
                out.print(ans + " ");
            }
        }
    }

    static String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            String line = br.readLine();
            if (line == null) return null;
            st = new StringTokenizer(line);
        }
        return st.nextToken();
    }

    static int nextInt() throws IOException {
        String s = next();
        if (s == null) throw new IOException("End of input");
        return Integer.parseInt(s);
    }

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        
        String tStr = next();
        if (tStr != null) {
            int t = Integer.parseInt(tStr);
            while (t-- > 0) {
                solve();
            }
        }
        out.flush();
    }
}
```
Wait, I need to check the `build` logic again.
In C++:
```cpp
    void build(int u,int l,int r) {
        tr[u]={l,r}; // This initializes all fields of tr[u]
        if(l==r) { tr[u].min=l; }
        else {
            ...
        }
    }
```
In C++, `tr[u]={l,r}` initializes `l` and `r`. It does NOT initialize `min` and `laz`.
Wait, in C++, struct members are value-initialized to 0 if not specified?
`Node tr[MAXSIZE<<2];` creates an array of default-constructed `Node` objects.
Default constructor for `struct` in C++ (if not explicitly defined) initializes all members to 0 (for POD types like int).
So `tr[u]` starts with `l=0, r=0, min=0, laz=0`.
Then `tr[u]={l,r}` sets `l` and `r`. `min` and `laz` remain 0.
So in Java, `tr[u].l = l; tr[u].r = r;` is sufficient, as `min` and `laz` are already 0 from the static initialization.
Wait, my static initialization loop sets all fields to 0.
So `tr[u].min` is 0.
So the logic is correct.

One detail: `MAX_NODES`.
In C++, `MAXSIZE=N`. `tr[MAXSIZE<<2]`.
`N` is `2e5+10`.
`MAXSIZE << 2` is `200010 * 4`.
In Java, `MAX_NODES` should be `(N + 1) * 4`.
Wait, `N` is `200010`.
`200010 * 4 = 800040`.
The array size is `800040`.
Indices are `0` to `800039`.
If `n` is `200010`, `n+1` is `200011`.
The tree depth is `log2(200011)`.
Max index is roughly `4 * 200011`.
`4 * 200011 = 800044`.
So `MAX_NODES = 800050` is safe.
My calculation `(N + 1) * 4 + 10` gives `200011 * 4 + 10 = 800054`.
This is safe.

One more thing: `sgt` in C++ is a global instance.
In Java, I am using static methods.
This is fine.

The output format:
`cout<<sum-tot*(tot+1)/2<<" \n"[i==n];`
This is a string literal `" \n"`.
Index 0 is space. Index 1 is newline.
If `i==n`, index is 1 (newline).
If `i!=n`, index is 0 (space).
So `if (i==n) out.println(ans); else out.print(ans + " ");` is correct.

Wait, `sum` and `tot` are `LL` in C++.
In Java, `long`.
`sum -= pos` is `long - int`.
`tot * (tot+1) / 2`. `tot` is `long`.
So `tot * (tot+1)` can overflow `int`?
`tot` is up to `200000`.
`tot * (tot+1)` is approx `4e10`.
This fits in `long` (max `9e18`).
It does not fit in `int` (max `2e9`).
So `tot` must be `long`.
In C++, `tot` is `LL`.
In Java, I used `long tot`.
So `tot * (tot+1)` is `long * long`.
This is correct.

Final check on the `SegmentTree` class.
I moved `tr` to `c_1785` static field.
I removed `tr` from `SegmentTree`.
I need to make sure `SegmentTree` methods access `c_1785.tr`.
Since `SegmentTree` is a static inner class of `c_1785`, it can access `c_1785`'s static fields.
But to be explicit and avoid confusion, I will just use `tr` directly in the static methods of `SegmentTree`.
Wait, `tr` is static in `c_1785`.
Inside `SegmentTree` (which is a static inner class of `c_1785`), `tr` is accessible as `tr`?
Yes, static members of the outer class are accessible to the inner class.
So `tr[u]` inside `SegmentTree` refers to `c_1785.tr[u]`.
This is correct.

One small thing: `MAX_NODES` is `static final int` in `c_1785`.
I used it in `c_1785` static block.
I also used it in `SegmentTree`? No, I removed it from `SegmentTree`.
Wait, I need to make sure `MAX_NODES` is used correctly.
In `c_1785` static block: `tr = new Node[MAX_NODES];`.
This is correct.

I will put the final code in the block.
</think>

```java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class c_1785 {

    // Constants
    static final int N = 200010;
    static final int INF = 1000000000;
    // MAXSIZE is 2e5+10. 
    // The tree array size is MAXSIZE << 2.
    // We need to calculate this value.
    // 200010 * 4 = 800040.
    // Let's use 800050 to be safe.
    static final int MAX_NODES = (N + 1) * 4 + 10;

    // Segment Tree Node
    static class Node {
        int l;
        int r;
        int min;
        int laz;
    }

    // Segment Tree Array
    static Node[] tr;

    // IO Helpers
    static BufferedReader br;
    static StringTokenizer st;
    static PrintWriter out;

    static {
        tr = new Node[MAX_NODES];
        // Initialize the array with nodes to avoid null checks in build
        for(int i=0; i<MAX_NODES; i++) {
            tr[i] = new Node();
        }
    }

    // Segment Tree Implementation
    static class SegmentTree {
        static void pushup(int u) {
            tr[u].min = Math.min(tr[u << 1].min, tr[(u << 1) | 1].min);
        }

        static void update(int u, int cnt, int val) {
            tr[u].min += val;
            tr[u].laz += val;
        }

        static void pushdn(int u) {
            if (tr[u].laz != 0) {
                update(u << 1, 0, tr[u].laz);
                update((u << 1) | 1, 0, tr[u].laz);
                tr[u].laz = 0;
            }
        }

        static void modify(int u, int l, int r, int cnt, int val) {
            if (tr[u].l >= l && tr[u].r <= r) {
                update(u, cnt, val);
            } else {
                pushdn(u);
                int mid = (tr[u].l + tr[u].r) >> 1;
                if (mid >= l) modify(u << 1, l, r, cnt, val);
                if (mid < r) modify((u << 1) | 1, l, r, cnt, val);
                pushup(u);
            }
        }

        static int find(int u) {
            if (tr[u].min >= 0) return 0;
            if (tr[u].l == tr[u].r) return tr[u].l;
            pushdn(u);
            int res = find(u << 1);
            if (res != 0) return res;
            return find((u << 1) | 1);
        }

        static void build(int u, int l, int r) {
            // In C++, tr[u] = {l,r};
            // In Java, we need to ensure tr[u] is not null.
            // Since we initialized the array in static block, it should not be null.
            // But we need to reset it to a clean state?
            // The C++ code does `tr[u] = {l,r}` which initializes `l` and `r`.
            // `min` and `laz` remain 0 (from initialization).
            // So we just need to set `l` and `r`.
            
            tr[u].l = l;
            tr[u].r = r;
            if (l == r) {
                tr[u].min = l;
            } else {
                int mid = (l + r) >> 1;
                build(u << 1, l, mid);
                build((u << 1) | 1, mid + 1, r);
                pushup(u);
            }
        }
    }

    static void solve() throws IOException {
        String s = next();
        if (s == null) return;
        int n = Integer.parseInt(s);
        
        long sum = 0;
        long tot = 0;
        
        // Build Segment Tree
        // Range [1, n+1]
        SegmentTree.build(1, 1, n + 1);
        
        for (int i = 1; i <= n; i++) {
            int cur = nextInt();
            tot++;
            sum += cur;
            
            // sgt.modify(1, cur, cur, 1, 0);
            SegmentTree.modify(1, cur, cur, 1, 0);
            
            // sgt.modify(1, cur, n+1, 0, -1);
            SegmentTree.modify(1, cur, n + 1, 0, -1);
            
            // int pos=sgt.find(1);
            int pos = SegmentTree.find(1);
            
            if (pos != 0) {
                tot--;
                sum -= pos;
                // sgt.modify(1, pos, pos, -1, 0);
                SegmentTree.modify(1, pos, pos, -1, 0);
                // sgt.modify(1, pos, n+1, 0, 1);
                SegmentTree.modify(1, pos, n + 1, 0, 1);
            }
            
            // cout<<sum-tot*(tot+1)/2<<" \n"[i==n];
            long ans = sum - tot * (tot + 1) / 2;
            if (i == n) {
                out.println(ans);
            } else {
                out.print(ans + " ");
            }
        }
    }

    static String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            String line = br.readLine();
            if (line == null) return null;
            st = new StringTokenizer(line);
        }
        return st.nextToken();
    }

    static int nextInt() throws IOException {
        String s = next();
        if (s == null) throw new IOException("End of input");
        return Integer.parseInt(s);
    }

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        
        String tStr = next();
        if (tStr != null) {
            int t = Integer.parseInt(tStr);
            while (t-- > 0) {
                solve();
            }
        }
        out.flush();
    }
}
```
<CODE>
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class c_1785 {

    // Constants
    static final int N = 200010;
    static final int INF = 1000000000;
    // MAXSIZE is 2e5+10. 
    // The tree array size is MAXSIZE << 2.
    // We need to calculate this value.
    // 200010 * 4 = 800040.
    // Let's use 800050 to be safe.
    static final int MAX_NODES = (N + 1) * 4 + 10;

    // Segment Tree Node
    static class Node {
        int l;
        int r;
        int min;
        int laz;
    }

    // Segment Tree Array
    static Node[] tr;

    // IO Helpers
    static BufferedReader br;
    static StringTokenizer st;
    static PrintWriter out;

    static {
        tr = new Node[MAX_NODES];
        // Initialize the array with nodes to avoid null checks in build
        for(int i=0; i<MAX_NODES; i++) {
            tr[i] = new Node();
        }
    }

    // Segment Tree Implementation
    static class SegmentTree {
        static void pushup(int u) {
            tr[u].min = Math.min(tr[u << 1].min, tr[(u << 1) | 1].min);
        }

        static void update(int u, int cnt, int val) {
            tr[u].min += val;
            tr[u].laz += val;
        }

        static void pushdn(int u) {
            if (tr[u].laz != 0) {
                update(u << 1, 0, tr[u].laz);
                update((u << 1) | 1, 0, tr[u].laz);
                tr[u].laz = 0;
            }
        }

        static void modify(int u, int l, int r, int cnt, int val) {
            if (tr[u].l >= l && tr[u].r <= r) {
                update(u, cnt, val);
            } else {
                pushdn(u);
                int mid = (tr[u].l + tr[u].r) >> 1;
                if (mid >= l) modify(u << 1, l, r, cnt, val);
                if (mid < r) modify((u << 1) | 1, l, r, cnt, val);
                pushup(u);
            }
        }

        static int find(int u) {
            if (tr[u].min >= 0) return 0;
            if (tr[u].l == tr[u].r) return tr[u].l;
            pushdn(u);
            int res = find(u << 1);
            if (res != 0) return res;
            return find((u << 1) | 1);
        }

        static void build(int u, int l, int r) {
            // In C++, tr[u] = {l,r};
            // In Java, we need to ensure tr[u] is not null.
            // Since we initialized the array in static block, it should not be null.
            // But we need to reset it to a clean state?
            // The C++ code does `tr[u] = {l,r}` which initializes `l` and `r`.
            // `min` and `laz` remain 0 (from initialization).
            // So we just need to set `l` and `r`.
            
            tr[u].l = l;
            tr[u].r = r;
            if (l == r) {
                tr[u].min = l;
            } else {
                int mid = (l + r) >> 1;
                build(u << 1, l, mid);
                build((u << 1) | 1, mid + 1, r);
                pushup(u);
            }
        }
    }

    static void solve() throws IOException {
        String s = next();
        if (s == null) return;
        int n = Integer.parseInt(s);
        
        long sum = 0;
        long tot = 0;
        
        // Build Segment Tree
        // Range [1, n+1]
        SegmentTree.build(1, 1, n + 1);
        
        for (int i = 1; i <= n; i++) {
            int cur = nextInt();
            tot++;
            sum += cur;
            
            // sgt.modify(1, cur, cur, 1, 0);
            SegmentTree.modify(1, cur, cur, 1, 0);
            
            // sgt.modify(1, cur, n+1, 0, -1);
            SegmentTree.modify(1, cur, n + 1, 0, -1);
            
            // int pos=sgt.find(1);
            int pos = SegmentTree.find(1);
            
            if (pos != 0) {
                tot--;
                sum -= pos;
                // sgt.modify(1, pos, pos, -1, 0);
                SegmentTree.modify(1, pos, pos, -1, 0);
                // sgt.modify(1, pos, n+1, 0, 1);
                SegmentTree.modify(1, pos, n + 1, 0, 1);
            }
            
            // cout<<sum-tot*(tot+1)/2<<" \n"[i==n];
            long ans = sum - tot * (tot + 1) / 2;
            if (i == n) {
                out.println(ans);
            } else {
                out.print(ans + " ");
            }
        }
    }

    static String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            String line = br.readLine();
            if (line == null) return null;
            st = new StringTokenizer(line);
        }
        return st.nextToken();
    }

    static int nextInt() throws IOException {
        String s = next();
        if (s == null) throw new IOException("End of input");
        return Integer.parseInt(s);
    }

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        
        String tStr = next();
        if (tStr != null) {
            int t = Integer.parseInt(tStr);
            while (t-- > 0) {
                solve();
            }
        }
        out.flush();
    }
}
</CODE>