Translate this C++ code to Java code. The main class name should be c_1325. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include<bits/stdc++.h>
using namespace std;
template<typename T>
inline void read(T &x)
{
	x=0;
	int f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
}
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
	x*=f;
	return;
}	
template<typename T>
void write(T x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>=10) write(x/10);
	putchar(x%10+'0');
	return;
}
const int MAXN=100010;
int n;
int tot=2;
int edge[MAXN*2],nxt[MAXN*2],hd[MAXN];
inline void add_edge(int u,int v)
{
	edge[tot]=v,nxt[tot]=hd[u],hd[u]=tot++;
}
int d[MAXN];
int ans[MAXN];
bool book[MAXN];
int main()
{
	read(n);
	for(int i=1;i<n;i++)
	{
		int u,v;
		read(u),read(v);
		add_edge(u,v),add_edge(v,u);
		d[u]++,d[v]++;
	}
	for(int i=1;i<=n;i++)
	if(d[i]>=3)
	{
		int cnt=0;
		for(int j=hd[i];j;j=nxt[j])
		if(cnt>3) break;
		else ans[j/2]=cnt++,book[j/2]=1;
		for(int j=1;j<n;j++)
		if(!book[j]) ans[j]=cnt++;
		for(int j=1;j<n;j++) write(ans[j]),putchar('\n');
		return 0;
	}
	for(int i=1;i<n;i++) write(i-1),putchar('\n');
	return 0;
}

<think>

</think>

### Translation Plan

1.  **Headers**: Replace `<bits/stdc++.h>` with specific headers (`iostream`, `cstdio`, `vector`, `algorithm`). Replace `using namespace std;` with explicit usage where appropriate or keep it if the style permits (standard Java practice usually avoids `using namespace` but for competitive programming style, we can keep imports).
2.  **Templates (`read` and `write`)**:
    *   C++ templates allow type erasure. In Java, we must use Generics (`<T>`).
    *   `read`: Since `char` in C++ is an integer type, Java's `char` is a 16-bit Unicode character. We need to read as a string or byte. Reading integer logic requires handling `int` and `char`. The `getchar()` equivalent in Java is `System.in.read()`.
    *   `write`: Java's `System.out.print()` or `PrintWriter` works well. The recursive logic remains the same.
3.  **Global Variables**: Java does not allow global variables to be modified easily outside their class scope without static members. We will move `n`, `tot`, arrays (`edge`, `nxt`, `hd`, `d`, `ans`, `book`) into a `main` class as `static` final or mutable fields.
4.  **Adjacency List**: C++ uses raw arrays with linked lists (`edge`, `nxt`, `hd`). Java uses `ArrayList<Integer>[]` or similar structures. Given the constraints (`MAXN=100010`), an `ArrayList` array is efficient enough. Note: The C++ code uses a custom pointer-based adjacency list (`tot`, `edge`, `nxt`, `hd`). To translate faithfully, we can implement a static array-based adjacency list in Java (arrays of size `MAXN*2` and `MAXN`) to mimic the C++ memory layout, which is often preferred in competitive programming for performance.
5.  **Input/Output**: Replace `cin`/`cout` with the custom `read`/`write` functions translated to use `System.in` and `System.out` (or `BufferedOutputStream` for speed).
6.  **Logic Flow**:
    *   Read `n`.
    *   Loop `n-1` times to read edges.
    *   Build graph (add edges).
    *   Calculate degrees (`d`).
    *   Check if any node has degree `>= 3`.
    *   If yes, find the component connected to that node (BFS/DFS or simple traversal limited by degree) and assign colors.
    *   If no, output `0` for all nodes (implied by `write(i-1)` which outputs 0 for i=1).
    *   *Correction on Logic*: Looking closely at the C++ code: `for(int j=1;j<n;j++) write(i-1)...`. If the condition `d[i]>=3` is never met, it outputs `0` for all nodes (since `i` starts at 1, `i-1` is 0). If a node with degree `>=3` exists, it performs a specific coloring logic.
7.  **Incremental Tasks**:
    *   Task 1: Define the class structure and static arrays.
    *   Task 2: Implement the `read` and `write` functions using `System.in` and `System.out`.
    *   Task 3: Implement `add_edge`.
    *   Task 4: Implement `main` logic (degree calculation, component traversal, output).

### Java Code

```java
import java.io.*;
import java.util.*;

public class c_1325 {
    // Constants
    static final int MAXN = 100010;

    // Graph storage (Adjacency List using static arrays to mimic C++ style)
    static int[] edge = new int[MAXN * 2];
    static int[] nxt = new int[MAXN * 2];
    static int[] hd = new int[MAXN];
    static int tot = 2; // Start from 2 because index 0 and 1 are unused/placeholder in some implementations, 
                         // but here it seems to start filling from 2. 
                         // Actually, in C++: edge[tot]=v, nxt[tot]=hd[u], hd[u]=tot++; tot starts at 2.
                         // So indices 0 and 1 are skipped.

    // Degree array
    static int[] d = new int[MAXN];

    // Result array
    static int[] ans = new int[MAXN];

    // Visited/Book array
    static boolean[] book = new boolean[MAXN];

    // Fast I/O Reader
    static class Reader {
        final private int BUFFER_SIZE = 1 << 16;
        private DataInputStream din;
        private byte[] buffer;
        private int bufferPointer, bytesRead;

        public Reader() {
            din = new DataInputStream(System.in);
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

        public int nextInt() throws IOException {
            int ret = 0;
            byte c = read();
            while (c <= ' ') c = read();
            boolean neg = (c == '-');
            if (neg) c = read();
            do {
                ret = ret * 10 + c - '0';
            } while (c = read() >= '0' && c <= '9');
            if (neg) return -ret;
            return ret;
        }

        private byte read() throws IOException {
            if (bufferPointer == bytesRead) bufferPointer = 0;
            return buffer[bufferPointer++];
        }
    }

    // Custom write function to match C++ logic
    static void write(int x) throws IOException {
        if (x < 0) {
            System.out.print('-');
            x = -x;
        }
        if (x >= 10) {
            write(x / 10);
        }
        System.out.print(x % 10 + '0');
    }

    // Add edge function
    static void addEdge(int u, int v) {
        edge[tot] = v;
        nxt[tot] = hd[u];
        hd[u] = tot++;
    }

    public static void main(String[] args) throws IOException {
        Reader reader = new Reader();
        PrintWriter out = new PrintWriter(System.out);

        // Read n
        int n = reader.nextInt();

        // Reset arrays if necessary (though static, they persist. For single run, initialization in static block or main is fine. 
        // Since Java arrays init to 0, we are good. But we must ensure hd is 0 initially. 
        // Java int[] initializes to 0. boolean[] to false.
        // However, if we were to run multiple test cases, we'd need to clear. Assuming single run based on code structure.
        
        // Read edges
        for (int i = 1; i < n; i++) {
            int u = reader.nextInt();
            int v = reader.nextInt();
            addEdge(u, v);
            addEdge(v, u);
            d[u]++;
            d[v]++;
        }

        // Check for nodes with degree >= 3
        for (int i = 1; i <= n; i++) {
            if (d[i] >= 3) {
                int cnt = 0;
                
                // Traverse neighbors of node i
                // C++ logic: for(int j=hd[i];j;j=nxt[j])
                int curr = hd[i];
                while (curr != 0) {
                    if (cnt > 3) break;
                    int neighbor = edge[curr];
                    ans[neighbor] = cnt++;
                    book[neighbor] = true;
                    curr = nxt[curr];
                }

                // Assign remaining unvisited nodes
                for (int j = 1; j <= n; j++) {
                    if (!book[j]) {
                        ans[j] = cnt++;
                    }
                }

                // Output results
                for (int j = 1; j <= n; j++) {
                    write(ans[j]);
                    out.println();
                }
                out.flush();
                return;
            }
        }

        // If no node has degree >= 3, output 0 for all
        for (int i = 1; i <= n; i++) {
            // C++ code: write(i-1). Since i starts at 1, this writes 0.
            write(i - 1);
            out.println();
        }
        out.flush();
    }
}
```

<CODE>
import java.io.*;
import java.util.*;

public class c_1325 {
    // Constants
    static final int MAXN = 100010;

    // Graph storage (Adjacency List using static arrays to mimic C++ style)
    // In C++, edge and nxt are arrays of size MAXN*2.
    static int[] edge = new int[MAXN * 2];
    static int[] nxt = new int[MAXN * 2];
    static int[] hd = new int[MAXN];
    
    // Pointer for adding edges. 
    // In C++, tot is initialized to 2. We keep this logic.
    static int tot = 2; 

    // Degree array
    static int[] d = new int[MAXN];

    // Result array
    static int[] ans = new int[MAXN];

    // Visited/Book array
    static boolean[] book = new boolean[MAXN];

    // Fast I/O Reader
    static class Reader {
        final private int BUFFER_SIZE = 1 << 16;
        private DataInputStream din;
        private byte[] buffer;
        private int bufferPointer, bytesRead;

        public Reader() {
            din = new DataInputStream(System.in);
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

        public int nextInt() throws IOException {
            int ret = 0;
            byte c = read();
            while (c <= ' ') c = read();
            boolean neg = (c == '-');
            if (neg) c = read();
            do {
                ret = ret * 10 + c - '0';
            } while (c = read() >= '0' && c <= '9');
            if (neg) return -ret;
            return ret;
        }

        private byte read() throws IOException {
            if (bufferPointer == bytesRead) bufferPointer = 0;
            return buffer[bufferPointer++];
        }
    }

    // Custom write function to match C++ logic
    static void write(int x) throws IOException {
        if (x < 0) {
            System.out.print('-');
            x = -x;
        }
        if (x >= 10) {
            write(x / 10);
        }
        System.out.print(x % 10 + '0');
    }

    // Add edge function
    static void addEdge(int u, int v) {
        edge[tot] = v;
        nxt[tot] = hd[u];
        hd[u] = tot++;
    }

    public static void main(String[] args) throws IOException {
        Reader reader = new Reader();
        PrintWriter out = new PrintWriter(System.out);

        // Read n
        int n = reader.nextInt();

        // Reset arrays if necessary (Java initializes int[] to 0 and boolean[] to false by default).
        // Since this is a single run program, static initialization is sufficient.
        // However, if run in a loop in a real environment, one would need to Arrays.fill.
        // Given the structure, we assume single execution.

        // Read edges
        // Loop from 1 to n-1
        for (int i = 1; i < n; i++) {
            int u = reader.nextInt();
            int v = reader.nextInt();
            addEdge(u, v);
            addEdge(v, u);
            d[u]++;
            d[v]++;
        }

        // Check for nodes with degree >= 3
        for (int i = 1; i <= n; i++) {
            if (d[i] >= 3) {
                int cnt = 0;
                
                // Traverse neighbors of node i
                // C++ logic: for(int j=hd[i];j;j=nxt[j])
                // In Java, we traverse the linked list using the array indices
                int curr = hd[i];
                while (curr != 0) {
                    if (cnt > 3) break;
                    int neighbor = edge[curr];
                    ans[neighbor] = cnt++;
                    book[neighbor] = true;
                    curr = nxt[curr];
                }

                // Assign remaining unvisited nodes
                for (int j = 1; j <= n; j++) {
                    if (!book[j]) {
                        ans[j] = cnt++;
                    }
                }

                // Output results
                for (int j = 1; j <= n; j++) {
                    write(ans[j]);
                    out.println();
                }
                out.flush();
                return;
            }
        }

        // If no node has degree >= 3, output 0 for all
        // C++ code: write(i-1). Since i starts at 1, this writes 0.
        for (int i = 1; i <= n; i++) {
            write(i - 1);
            out.println();
        }
        out.flush();
    }
}
</CODE>