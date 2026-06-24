Translate this C++ code to Java code. The main class name should be d_697. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include <bits/stdc++.h>



#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i++)

#define DOW(i,a,b) for (int i=(a),_b=(b);i>=_b;i--)

#define x first

#define y second

#define pb push_back

#define mp make_pair

#define maxn 100010



using namespace std;



typedef pair<int,int> PII;

typedef pair<int,PII> PP;

typedef long long LL;

typedef unsigned long long ULL;



struct Edge{

	int to, next;

}e[maxn<<1];



int head[maxn], cnt;

int sz[maxn], dep[maxn];



void ins(int u, int v){e[++cnt] = (Edge){v, head[u]}; head[u] = cnt;}



void insert(int u,int v){ins(u,v);ins(v,u);}





void dfs(int u, int fa){

	sz[u] = 1;

	for(int i = head[u]; i; i = e[i].next){

		int v = e[i].to;

		if(v == fa) continue;

		dep[v] = dep[u]+1;

		dfs(v, u);

		sz[u] += sz[v];

	}

}



int main(){

	//freopen("input.inp","r",stdin);

    //freopen("output.out","w",stdout);

	int n;

	scanf("%d",&n);

	FOR(i,2,n){

		int p;

		scanf("%d",&p);

		insert(i, p);

	}

	dfs(1,-1);

	FOR(i,1,n){

		int ans = n - sz[i] - dep[i];

		printf("%d", dep[i] + (ans >> 1) + 1);

		putchar('.');

		if (ans & 1) putchar('5');

		else putchar('0');

		putchar(' ');

	}

	puts("\n");

	return 0;

}

Here is the plan for translating the C++ code to Java:

1.  **Class Structure**: Create a public class named `d_697`.
2.  **Input/Output**: Replace `scanf`, `printf`, `putchar`, and `puts` with `Scanner` and `System.out.print`/`println`. Since the output format is specific (digits followed by '.' and '0'/'5'), we will use `StringBuilder` for efficiency, similar to how one might buffer output in C++ to avoid I/O overhead.
3.  **Data Structures**:
    *   Replace `std::vector` or array-based adjacency list logic. In C++, `head` and `e` arrays are used for an adjacency list. In Java, we will use `int[]` for `head` and `next`, and `int[]` for `to`.
    *   Replace `std::pair` with a custom class or just use two parallel arrays (`to` and `next`) to store edge information. The C++ code uses `head` array and an edge array `e` where `e[i].to` is the destination and `e[i].next` is the index of the next edge.
4.  **Constants**: Replace `#define` macros with `static final` constants.
5.  **Iterators**: Replace C++ macros `FOR` and `DOW` with standard Java `for` loops.
6.  **Logic**:
    *   The `ins` and `insert` functions become methods.
    *   The `dfs` function becomes a recursive method.
    *   The main logic remains the same, handling the tree structure and calculating the answer based on subtree sizes and depths.

**Incremental Tasks**:
1.  Define constants.
2.  Define the `Edge` class (or use parallel arrays).
3.  Implement `insert` and `dfs`.
4.  Implement `main` method, handling input and output.

```java
import java.util.Scanner;

public class d_697 {

    // Constants defined in C++
    // maxn = 100010
    private static final int MAXN = 100010;

    // Arrays to represent the adjacency list
    // In C++, this was: Edge e[maxn<<1]; int head[maxn];
    // Java uses arrays directly. e[i] represents the edge at index i.
    // to[i] is the destination, next[i] is the index of the next edge.
    private static int[] to = new int[MAXN << 1];
    private static int[] next = new int[MAXN << 1];
    private static int[] head = new int[MAXN];
    private static int[] sz = new int[MAXN];
    private static int[] dep = new int[MAXN];
    private static int cnt = 0;

    // Edge structure in C++: struct Edge { int to, next; }
    // We map this to the parallel arrays 'to' and 'next' in Java.
    // The index 'i' in the array corresponds to the 'cnt' in C++.
    
    // Corresponds to: void ins(int u, int v)
    // C++: e[++cnt] = (Edge){v, head[u]}; head[u] = cnt;
    private static void ins(int u, int v) {
        cnt++;
        to[cnt] = v;
        next[cnt] = head[u];
        head[u] = cnt;
    }

    // Corresponds to: void insert(int u, int v)
    // C++: ins(u,v); ins(v,u);
    private static void insert(int u, int v) {
        ins(u, v);
        ins(v, u);
    }

    // Corresponds to: void dfs(int u, int fa)
    private static void dfs(int u, int fa) {
        sz[u] = 1;
        // Iterate over edges starting from head[u]
        // C++: for(int i = head[u]; i; i = e[i].next)
        // Java: for(int i = head[u]; i > 0; i = next[i])
        for (int i = head[u]; i > 0; i = next[i]) {
            int v = to[i];
            if (v == fa) continue;
            dep[v] = dep[u] + 1;
            dfs(v, u);
            sz[u] += sz[v];
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read n
        if (!scanner.hasNextInt()) return;
        int n = scanner.nextInt();
        
        // Read parents for nodes 2 to n
        // C++: FOR(i,2,n) ... scanf("%d",&p); insert(i, p);
        for (int i = 2; i <= n; i++) {
            int p = scanner.nextInt();
            insert(i, p);
        }
        
        // Run DFS from root (node 1)
        // C++: dfs(1, -1);
        dfs(1, -1);
        
        // Output results
        // C++: FOR(i,1,n) ... printf("%d", dep[i] + (ans >> 1) + 1); putchar('.'); ...
        StringBuilder sb = new StringBuilder();
        
        for (int i = 1; i <= n; i++) {
            int ans = n - sz[i] - dep[i];
            sb.append(dep[i] + (ans >> 1) + 1);
            sb.append('.');
            if ((ans & 1) == 1) {
                sb.append('5');
            } else {
                sb.append('0');
            }
            sb.append(' ');
        }
        
        // C++: puts("\n");
        sb.append("\n");
        
        System.out.print(sb.toString());
        
        scanner.close();
    }
}
```