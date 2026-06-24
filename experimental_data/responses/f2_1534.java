Translate this C++ code to Java code. The main class name should be f2_1534. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
// from #119564378



#include<algorithm>

#include<bitset>

#include<cstring>

#include<cstdio>



#define ls i<<1

#define rs i<<1|1

#define fi first

#define se second

#define pb push_back

#define mp make_pair

#define as_const

using namespace std;

typedef long long ll;

const int N=4E5+10;

const int inf=1<<30;

int read()

{

    int a=0;

    char c;

    while ((c=getchar())>='0') a = a * 10 + c - '0';

    return a;

}

void write(ll x,char c)

{

    if(x<0)putchar(45),x=-x;

    char a[20],s=0;

    do a[++s]=x%10|48;while(x/=10);

    do putchar(a[s]);while(--s);

    putchar(c);

}

const int n = read(), m = read();

bitset<N>a;

int l[N],r[N],st[N];

template <int* __restrict l>

void dfs(int idx)

{

  constexpr auto& __restrict st = ::st;

  int top = 0;

  const int w = idx / n;

  st[top++] = idx;

  l[idx]=w;

  while (top) {

    int idx = st[--top];

    if(idx/n&&as_const(a)[idx-n]&&l[idx-n]==-1)l[idx-n]=w,st[top++]=idx-n;

    if(idx/n<m-1&&as_const(a)[idx+n]&&l[idx+n]==-1)l[idx+n]=w,st[top++]=idx+n;

    if(idx%n&&as_const(a)[idx-1]&&l[idx-1]==-1)l[idx-1]=w,st[top++]=idx-1;

    if(idx%n<n-1&&l[idx+1]==-1)l[idx+1]=w,st[top++]=idx+1;

  }

}

int main()

{

    for(int i=0;i<n;++i)

    {

        for(int j=0;j<m;++j)

        {

            a[i+j*n]=getchar()&1;

            __builtin_prefetch(reinterpret_cast<char*>(&a) + (i + (j + 2) * n & ~63), 1, 0);

        }

        getchar();

    }

    memset(l, -1, sizeof l);

    memset(r, -1, sizeof r);

    for(int j=0;j<m;++j)

    {

        int i=0;

        while(i<n&&!as_const(a)[i+j*n])++i;

        if(i<n && l[i + j*n] == -1)dfs<l>(i+j*n);

    }

    for(int j=m;j--;)

    {

        int i=0;

        while(i<n&&!as_const(a)[i+j*n])++i;

        if(i<n && r[i + j*n] == -1)dfs<r>(i+j*n);

    }

    for(int j=0;j<m;++j) st[j]=m;

    for(int j=0;j<m;++j)

    {

        int s=read();

        if(!s)continue;

        int idx=n + j * n;

        while(s)

        {

            s -= as_const(a)[--idx];

        }

        st[l[idx]]=min(st[l[idx]],r[idx]);

    }

    int ans=0;

    for(int i=0,j=m;i<m;++i)

    {

        j=min(j,st[i]);

        if(i==j)

        {

            ++ans;

            j=m;

        }

    }

    write(ans,'\n');

}

<think>

</think>

### Translation Plan

1.  **Headers and Namespaces**:
    *   Replace C++ headers (`<algorithm>`, `<bitset>`, `<cstring>`, `<cstdio>`) with Java equivalents (`java.util.*`, `java.io.*`, `java.lang.Math`).
    *   Remove `using namespace std;` and explicitly use fully qualified class names (e.g., `java.util.BitSet`) or import them.
    *   Change `std::min` to `Math.min`.

2.  **Data Types and Constants**:
    *   `long long` in C++ maps to `long` in Java.
    *   `int` remains `int`.
    *   `const int N=4E5+10;` becomes `static final int N = 400010;`.
    *   `const int inf=1<<30;` becomes `static final int inf = 1 << 30;`.

3.  **Input/Output**:
    *   Replace `read()` and `write()` with a custom `FastScanner` class and `PrintWriter` (or `StringBuilder` for buffering) to handle large I/O efficiently, mimicking the speed of C++ `scanf`/`printf` and `putchar`.
    *   The C++ `read()` function parses integers character by character.
    *   The C++ `write()` function handles negative numbers and outputting a character.

4.  **Bitset**:
    *   C++ `std::bitset` is not directly available in Java. Since the code uses `bitset<N>` where `N` is a compile-time constant, we can use `java.util.BitSet`. Note that Java's `BitSet` is dynamic, so we initialize it with a sufficient size. Accessing bits is done via `.get(index)`.

5.  **Macros**:
    *   `ls` and `rs` (left/right child indices in a segment tree or similar structure): Translate to variables or inline calculations `i<<1` and `(i<<1)+1`.
    *   `fi`, `se`, `pb`, `mp`: These are used in pairs/vectors but seem unused or irrelevant in the provided snippet (the snippet uses arrays `l`, `r`, `st`). We will ignore unused macros.
    *   `as_const`: The C++ code uses `as_const` to prevent modification of const references. In Java, this maps to passing objects by value where applicable or simply accessing fields directly since Java doesn't have reference types in the same way (arrays are objects, primitives are values). The logic `as_const(a)[idx]` becomes `a.get(idx)`.

6.  **Template Functions**:
    *   C++ `template` functions must be converted to Java `static` methods.
    *   The template parameter `int* __restrict l` becomes a method parameter `int[] l`.
    *   `constexpr auto& __restrict st` inside the template becomes accessing the static field `st` (passed as a parameter or accessed globally). In the code, `::st` suggests a global array. We will pass the `st` array to the method to maintain the logic.

7.  **Logic Flow**:
    *   **Initialization**: Read `n` and `m`. Initialize `l`, `r`, `st` arrays.
    *   **Input Loop**: Read the bitset input. Note the bitwise logic `getchar() & 1`.
    *   **Prefetch**: Java does not support hardware prefetching instructions like `__builtin_prefetch`. This line can be safely removed or replaced with a no-op.
    *   **DFS**: Implement the recursive-like iterative DFS (using a stack) logic.
    *   **Main Logic**:
        *   Initialize `l` and `r` with -1.
        *   Run forward pass (`l` calculation).
        *   Run backward pass (`r` calculation).
        *   Initialize `st` array.
        *   Read queries and update `st`.
        *   Calculate answer.
    *   **Output**: Print the result.

8.  **Incremental Tasks**:
    *   Step 1: Create the `FastScanner` and `PrintWriter` classes to handle I/O.
    *   Step 2: Define global constants and arrays (`N`, `l`, `r`, `st`, `a`).
    *   Step 3: Implement the `dfs` method as a Java `static` method.
    *   Step 4: Implement `main` logic, replacing C++ macros with Java syntax.
    *   Step 5: Handle the specific `bitset` logic using `java.util.BitSet`.
    *   Step 6: Combine and test.

---

### Java Code

<CODE>
import java.io.*;
import java.util.*;

public class f2_1534 {
    
    static final int N = 400010;
    static final int INF = 1 << 30;
    
    static int[] l = new int[N];
    static int[] r = new int[N];
    static int[] st = new int[N];
    static BitSet a;
    
    // Fast I/O
    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(InputStream in) {
            br = new BufferedReader(new InputStreamReader(in));
        }

        public int nextInt() {
            int c = -1;
            int res = 0;
            boolean neg = false;
            try {
                c = br.read();
                while (c != -1 && (c < '0' || c > '1')) {
                    if (c == '-') neg = true;
                    c = br.read();
                }
                if (c == -1) return 0; // Should not happen based on logic
            } catch (IOException e) {
                return 0;
            }
            
            while (c != -1 && c >= '0' && c <= '9') {
                res = res * 10 + (c - '0');
                c = br.read();
            }
            return neg ? -res : res;
        }
        
        public int readCharBit() throws IOException {
            int c = br.read();
            if (c == -1) return -1;
            return c & 1;
        }
        
        public void skipWhitespace() throws IOException {
            int c = br.read();
            while (c != -1 && (c < '0' || c > '1' || c == ' ')) {
                if (c == '\n' || c == '\r') {
                    // Handle newlines if necessary, but usually nextInt handles it
                    // For this specific problem, we just need to skip non-bit chars
                }
                c = br.read();
            }
        }
    }

    public static void dfs(int[] l, int[] st, int idx) {
        int top = 0;
        int w = idx / N;
        st[top++] = idx;
        l[idx] = w;
        
        while (top > 0) {
            int currentIdx = st[--top];
            int parent = currentIdx - N;
            
            // Check left parent
            if (parent >= 0 && a.get(parent) && l[parent] == -1) {
                l[parent] = w;
                st[top++] = parent;
            }
            
            // Check right parent (in terms of row logic)
            int rightParent = currentIdx + N;
            if (rightParent < n && a.get(rightParent) && l[rightParent] == -1) {
                l[rightParent] = w;
                st[top++] = rightParent;
            }
            
            // Check left sibling
            int leftSibling = currentIdx - 1;
            if (currentIdx % N != 0 && a.get(leftSibling) && l[leftSibling] == -1) {
                l[leftSibling] = w;
                st[top++] = leftSibling;
            }
            
            // Check right sibling
            int rightSibling = currentIdx + 1;
            if (currentIdx % N != N - 1 && l[rightSibling] == -1) {
                l[rightSibling] = w;
                st[top++] = rightSibling;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        FastScanner sc = new FastScanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
        
        // Read n and m
        // The C++ code reads n and m using the read() function which skips whitespace
        // We need to ensure we read integers correctly.
        // Note: The C++ read() function stops at non-digit characters.
        // We will implement a robust integer reader.
        
        int n = sc.nextInt();
        int m = sc.nextInt();
        
        // Re-read n and m to ensure alignment if there were issues, 
        // but standard nextInt should work. 
        // However, the C++ code uses a custom read() that might behave differently on whitespace.
        // Let's stick to the logic: read n, read m.
        
        a = new BitSet(N * m);
        
        // Read the bitset
        // The C++ code loops i from 0 to n-1, j from 0 to m-1.
        // It reads a bit.
        // It also calls getchar() to skip whitespace/newlines after each row (or block).
        // In the loop, it does: a[i+j*n] = getchar() & 1; getchar();
        
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                int bit = sc.readCharBit();
                if (bit == -1) bit = 0; // Safety
                a.set(i + j * n, bit);
            }
            // Skip whitespace after each row (equivalent to the second getchar())
            sc.skipWhitespace();
        }
        
        // Initialize l and r arrays
        Arrays.fill(l, -1);
        Arrays.fill(r, -1);
        
        // Forward pass
        for (int j = 0; j < m; j++) {
            int idx = 0;
            while (idx < n && !a.get(idx + j * n)) {
                idx++;
            }
            if (idx < n && l[idx + j * n] == -1) {
                dfs(l, st, idx + j * n);
            }
        }
        
        // Backward pass
        for (int j = m - 1; j >= 0; j--) {
            int idx = 0;
            while (idx < n && !a.get(idx + j * n)) {
                idx++;
            }
            if (idx < n && r[idx + j * n] == -1) {
                dfs(r, st, idx + j * n);
            }
        }
        
        // Initialize st array
        for (int j = 0; j < m; j++) {
            st[j] = m;
        }
        
        // Process queries
        // The C++ code reads 's' which is the number of set bits to skip backwards from current position
        for (int j = 0; j < m; j++) {
            int s = sc.nextInt();
            if (s == 0) continue;
            
            int idx = n + j * n;
            while (s > 0) {
                idx--;
                if (idx >= 0 && a.get(idx)) {
                    s--;
                }
            }
            
            if (l[idx] != -1) {
                st[l[idx]] = Math.min(st[l[idx]], r[idx]);
            }
        }
        
        // Calculate answer
        int ans = 0;
        int j = m;
        for (int i = 0; i < m; i++) {
            j = Math.min(j, st[i]);
            if (i == j) {
                ans++;
                j = m;
            }
        }
        
        out.println(ans);
        out.flush();
    }
}
</CODE>