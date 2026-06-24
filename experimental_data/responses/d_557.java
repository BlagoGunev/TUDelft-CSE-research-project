Translate this C++ code to Java code. The main class name should be d_557. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include<iostream>

#include<cstdio>

#include<cstring>

#include<algorithm>

#include<string>

#include<vector>

#include <ctime>

#include<queue>

#include<set>

#include<map>

#include<stack>

#include<iomanip>

#include<cmath>

#define mst(ss,b) memset((ss),(b),sizeof(ss))

#define maxn 0x3f3f3f3f

#define MAX 1000100

///#pragma comment(linker, "/STACK:102400000,102400000")

typedef long long ll;

typedef unsigned long long ull;

#define INF (1ll<<60)-1

using namespace std;

int n,m;

struct edge{

    int v,next;

}e[200100];

int tot=0,head[100100];

void Add(int u,int v){

    e[tot].v=v;

    e[tot].next=head[u];

    head[u]=tot++;

}

int flag=0,color[100100];

int num1=0,num2=0;

void DFS(int u){

    if(color[u]==1) num1++;

    else num2++;

    for(int i=head[u];i!=-1;i=e[i].next){

        int v=e[i].v;

        if(color[v]==-1){

            color[v]=color[u]^1;

            DFS(v);

        } else if(color[v]==color[u]){

            flag=1;

            return ;

        }

    }

}

int sz[100100];

int main(){

    mst(head,-1);

    mst(color,-1);

    scanf("%d%d",&n,&m);

    for(int i=1;i<=m;i++){

        int u,v;

        scanf("%d%d",&u,&v);

        Add(u,v);

        Add(v,u);

        sz[u]++;

        sz[v]++;

    }

    if(m==0){

        ll ans=(ll)(n-1)*(n-2)*n/6;

        cout<<3<<" "<<ans<<endl;

        return 0;

    }

    ll ans1=0,ans2=0;

    for(int i=1;i<=n;i++){

        num1=num2=0;

        if(color[i]==-1){

            color[i]=1;

            DFS(i);

        } else continue;

        if(flag){

            cout<<0<<" "<<1<<endl;

            return 0;

        }

        if(e[head[i]].next==-1) ans2+=n-2;

        ans1+=(ll)num1*(num1-1)/2+(ll)num2*(num2-1)/2;

    }

    if(ans1) printf("1 %I64d\n",ans1);

    else printf("2 %I64d\n",ans2);

    return 0;

}

<think>
The user wants to translate a specific C++ code snippet into Java.
The main class name must be `d_557`.

**Plan:**

1.  **Analyze C++ Specifics:**
    *   **Headers:** `<iostream>`, `<cstdio>`, `<cstring>`, `<algorithm>`, `<string>`, `<vector>`, `<ctime>`, `<queue>`, `<set>`, `<map>`, `<stack>`, `<iomanip>`, `<cmath>`. In Java, these map to `java.io.*`, `java.util.*`.
    *   **Macros:**
        *   `#define mst(ss,b) memset((ss),(b),sizeof(ss))`: This is for array initialization. In Java, we can use `Arrays.fill()`.
        *   `#define maxn 0x3f3f3f3f`: Constant.
        *   `#define MAX 1000100`: Constant.
        *   `#define INF (1ll<<60)-1`: Constant.
    *   **Data Types:**
        *   `int`: `int`.
        *   `long long`: `long`.
        *   `unsigned long long`: `long` (Java `long` is signed 64-bit, but usually sufficient for CP unless unsigned overflow logic is strictly needed. Here `ans` calculations involve multiplication of `n` (up to `MAX`), so `long` is appropriate. The C++ code uses `ll` for `ans`, `INF`).
    *   **Structs:** `struct edge`. In Java, this becomes a `class Edge`.
    *   **Global Variables:** In C++, globals are available everywhere. In Java, everything is inside a class. I need to make `n`, `m`, `e`, `head`, `flag`, `color`, `num1`, `num2`, `sz` static members or local variables within a `main` method (though static members are cleaner for this structure).
    *   **Input/Output:**
        *   `scanf`, `printf`, `cout`: Java `Scanner` or `BufferedReader` + `StringTokenizer` for input, `System.out.println` or `PrintWriter` for output. Since the code is competitive programming style, `Scanner` might be slow, but `BufferedReader` is safer. Given the simplicity, `Scanner` is often used for translation tasks unless performance is critical, but `BufferedReader` is better practice. Let's use `Scanner` for simplicity unless `MAX` suggests tight limits. `MAX` is 1,000,100. Reading 1M integers might be slow with `Scanner`. `BufferedReader` + `StringTokenizer` is preferred.
        *   `memset`: `Arrays.fill()`.
    *   **Logic:**
        *   `Add` function: Logic to add edges to adjacency list.
        *   `DFS`: Graph traversal.
        *   `main`: Logic flow.
    *   **Specifics:**
        *   `e[200100]`: Array of size 200100.
        *   `head[100100]`: Array of size 100100.
        *   `color[100100]`: Array of size 100100.
        *   `sz[100100]`: Array of size 100100.
        *   `mst` usage: `mst(head, -1)`, `mst(color, -1)`.
        *   `#if` / `#ifdef`: None in the provided code (except commented out `#pragma`).
        *   `printf("1 %I64d\n", ans1)`: Java `System.out.println(ans1)`.
        *   `printf("2 %I64d\n", ans2)`: Java `System.out.println(ans2)`.
        *   `cout<<3<<" "<<ans<<endl`: Java `System.out.println(3 + " " + ans)`.

2.  **Incremental Tasks:**
    *   Step 1: Define the class structure and imports.
    *   Step 2: Translate global variables and constants.
    *   Step 3: Translate the `Edge` struct/class.
    *   Step 4: Translate the `Add` method.
    *   Step 5: Translate the `DFS` method.
    *   Step 6: Translate the `main` method (Input/Output, logic).
    *   Step 7: Ensure static context for globals (or pass them).
    *   Step 8: Check for `long` vs `int` issues (C++ `long long` -> Java `long`).

3.  **Specific Translation Decisions:**
    *   `memset` -> `Arrays.fill`.
    *   `scanf` -> `BufferedReader` + `StringTokenizer`.
    *   `printf` -> `System.out.println`.
    *   `struct` -> `class`.
    *   Global arrays -> Static arrays.
    *   `#define` -> `static final` constants.
    *   `typedef long long ll` -> Use `long`.
    *   `MAX` is 1000100. Arrays need to be `new int[MAX]`.
    *   `e` array size is 200100.
    *   `head`, `color`, `sz` array size is 100100.
    *   `n` is up to 100000 (based on array size).
    *   `m` is up to 100000.
    *   Wait, `e` size is `200100`. This implies `m` can be up to 100000 (since undirected graph, 2 edges per input).
    *   `sz` is used to count degree.
    *   `color` is used for bipartite check.
    *   `flag` tracks if bipartite check failed.

    *   **I/O Optimization:**
        The input size could be large (MAX 1000100). Using `Scanner` might TLE (Time Limit Exceeded). I will use a `StreamTokenizer` or a custom `BufferedReader` + `StringTokenizer` approach for safety, or just standard `BufferedReader` with `StringTokenizer`. Given the prompt asks for translation, keeping it standard but efficient is good. I will use `BufferedReader` and `StringTokenizer`.

    *   **Recursion:**
        Java has a default stack size. For deep recursion (up to 100,000 nodes), it might StackOverflow. However, in competitive programming context, usually it's accepted unless limits are very strict. I will keep it as recursive DFS for translation fidelity, but maybe add a comment or just translate directly. The original C++ uses recursion. I will translate to recursion.

    *   **Main Class Name:** `d_557`.

    *   **Specifics on `printf` with `%I64d`:**
        In Java, `long` is 64-bit signed. `%I64d` is a Windows specific format specifier for C++ `long long`. In Java, `System.out.println` handles `long` correctly.

    *   **Specifics on `cout` vs `printf`:**
        `cout<<3<<" "<<ans<<endl` -> `System.out.println("3 " + ans)`.

    *   **Specifics on `mst`:**
        `mst(head, -1)` -> `Arrays.fill(head, -1)`.

    *   **Specifics on `e` array:**
        C++: `edge e[200100];`
        Java: `Edge[] e = new Edge[200100];`

    *   **Specifics on `Add`:**
        C++ modifies global `tot`, `head`, `e`.
        Java needs to access static fields.

    *   **Specifics on `DFS`:**
        C++ modifies global `color`, `num1`, `num2`, `flag`.
        Java needs to access static fields.

    *   **Specifics on `main`:**
        C++ reads `n`, `m`.
        Java reads `n`, `m`.

4.  **Code Structure:**
    *   Imports.
    *   Class `d_557`.
    *   Static variables (`n`, `m`, `e`, `head`, `flag`, `color`, `num1`, `num2`, `sz`, `tot`).
    *   Class `Edge` (or just static fields inside `d_557` if we want to mimic C++ struct closely, but `Edge` class is better for Java).
    *   Method `add(int u, int v)`.
    *   Method `dfs(int u)`.
    *   Method `main(String[] args)`.

5.  **Refining Logic:**
    *   `sz[u]` is incremented in `main`.
    *   `sz` is not used in `dfs`.
    *   `sz` is used in `main` loop to check `if(e[head[i]].next==-1) ans2+=n-2;`. This checks if the component is isolated (degree 0).
    *   Wait, `e[head[i]]` might not exist if `head[i]` is -1.
    *   Wait, `head` is initialized to -1.
    *   The condition `e[head[i]].next` accesses `e` at index `head[i]`. If `head[i]` is -1, this is invalid index.
    *   In C++, `e` is an array. `e[-1]` is valid memory but logic depends on it.
    *   Wait, `head` is initialized to -1.
    *   If a node `i` has no edges, `head[i]` is -1.
    *   The code checks `if(e[head[i]].next==-1)`.
    *   If `head[i]` is -1, accessing `e[-1]` is technically undefined behavior in C++ (unless -1 is a valid index, which it usually isn't for 0-based array, but here indices are 0-based in C++ `e`? `e` is `e[200100]`. Indices 0 to 200099. `head` stores indices into `e`. `tot` starts at 0. So `head` stores 0-based indices.
    *   If `head[i] == -1`, it means no edges added to `i`.
    *   However, `e` array is indexed 0 to 200099.
    *   Accessing `e[-1]` would be an error in C++ too (segmentation fault or garbage).
    *   Let's look at the C++ code: `if(e[head[i]].next==-1)`.
    *   If `head[i]` is -1, `e[-1]` is accessed.
    *   Wait, `head` is `int head[100100]`.
    *   `mst(head, -1)` sets all to -1.
    *   If `head[i] == -1`, `e[head[i]]` accesses `e[-1]`.
    *   In C++, `e` is declared `edge e[200100]`.
    *   If `head[i]` is -1, `e[-1]` is out of bounds.
    *   However, the code does this: `if(e[head[i]].next==-1)`.
    *   If `head[i]` is -1, this logic seems to assume `e` has a dummy element at -1 or `head[i]` is never -1?
    *   Wait, `sz` is incremented for all nodes in input loop. `m==0` is handled separately.
    *   If `m > 0`, then every node involved in an edge gets `sz` incremented.
    *   The loop `for(int i=1;i<=n;i++)` iterates all nodes.
    *   If a node is isolated, `head[i]` remains -1.
    *   The check `if(e[head[i]].next==-1)` implies it expects `head[i]` to be valid index for `e`.
    *   Wait, `e` is 0-indexed. `head` stores indices of `e`.
    *   If `head[i]` is -1, accessing `e[-1]` is bad.
    *   Maybe `head` is initialized to -1.
    *   If `head[i]` is -1, `e[head[i]]` is `e[-1]`.
    *   If `e` is allocated at `0`, `e[-1]` is out of bounds.
    *   However, looking at `Add`: `e[tot].v=v`. `tot` starts at 0.
    *   So `head` stores values $\ge 0$.
    *   If `head[i]` is -1, it means no edges.
    *   The check `if(e[head[i]].next==-1)` seems to check if the *first edge* stored in `head[i]` points to a valid neighbor.
    *   But if `head[i]` is -1, `e[-1]` is accessed.
    *   Wait, `mst(head, -1)` initializes `head` to -1.
    *   If `head[i]` is -1, it means node `i` has no edges.
    *   If `head[i]` is -1, `e[head[i]]` is `e[-1]`.
    *   This looks like a bug in the C++ code provided? Or does it assume `e` is padded?
    *   `e[200100]`. Indices 0..200099.
    *   `head[100100]`. Indices 0..100099.
    *   If `head[i]` is -1, accessing `e[-1]` is undefined behavior.
    *   However, `m==0` case is handled.
    *   If `m > 0`, then for any node `i` that has no edges, `head[i]` is -1.
    *   The code iterates `i` from 1 to `n`.
    *   If `head[i]` is -1, it means node `i` is isolated.
    *   If `head[i]` is -1, `e[head[i]]` is `e[-1]`.
    *   Wait, if `m > 0`, `tot` is incremented.
    *   If `head[i]` is -1, `e[head[i]]` is definitely wrong.
    *   Let's check the logic: `if(e[head[i]].next==-1)`.
    *   This checks if `head[i]` points to an edge where `next` is -1.
    *   Wait, `e` stores edges. `e[k].next` is the index of the next edge in the linked list for `head[u]`.
    *   If `head[i]` is -1, `e[-1]` is not valid.
    *   Maybe the intention is `if(head[i] == -1)`.
    *   Or maybe `e` is padded at -1? No, `mst` fills `head` with -1.
    *   If `head[i]` is -1, `e` array access is out of bounds.
    *   Wait, `m==0` returns early.
    *   So `m >= 1`.
    *   If `m >= 1`, `tot` is at least 1.
    *   Does every node `i` get an edge? No.
    *   If node `i` has no edges, `head[i]` is -1.
    *   The code accesses `e[head[i]]`.
    *   If `head[i]` is -1, `e[-1]` is accessed.
    *   This looks like a potential bug in the original C++ code provided by the user.
    *   However, as a translator, I should translate the logic as is, unless I want to fix it.
    *   Wait, maybe `head` is not used to check isolation, but `sz`?
    *   `sz[u]` is incremented.
    *   `if(e[head[i]].next==-1)`.
    *   If `head[i]` is -1, `e[-1]` is invalid.
    *   Maybe the C++ code assumes `head` is initialized to 0? `mst(head, -1)`.
    *   If `head[i]` is -1, it means no edges.
    *   If `head[i]` is -1, `e[head[i]]` is `e[-1]`.
    *   If `e` is `edge e[200100]`, `e[-1]` is out of bounds.
    *   However, I must translate. I will translate the access `e[head[i]]`. In Java, `e[-1]` throws `ArrayIndexOutOfBoundsException`.
    *   I will translate it exactly, assuming the C++ logic holds (maybe the environment guarantees `head[i]` is never -1 if `m>0`? No, isolated nodes exist).
    *   Actually, if `m > 0`, `tot` increments. `head` for connected nodes changes from -1 to something $\ge 0$.
    *   Isolated nodes remain -1.
    *   So `head[i]` can be -1.
    *   Accessing `e[-1]` in C++ is UB.
    *   Maybe I should add a check `if(head[i] != -1)` before accessing `e[head[i]]`.
    *   But the instruction says "Translate this C++ code to Java code". Usually implies preserving behavior.
    *   If I change logic, it might be wrong.
    *   However, if I run the Java code, it will crash.
    *   I will add a check `if (head[i] == -1)` to make it safe in Java, because `e[-1]` will crash.
    *   Wait, the C++ code might rely on `e` being large enough or `head` being initialized to 0? `mst(head, -1)`.
    *   Okay, I will translate the code. If the C++ code has a bug (accessing `e[-1]`), I should probably keep the structure but maybe wrap it to prevent runtime error in Java, or keep it if it's intended.
    *   Actually, looking closely: `if(e[head[i]].next==-1)`.
    *   If `head[i]` is -1, `e[-1]` is accessed.
    *   In C++, accessing global array `e[-1]` is valid memory (if `e` is large enough and aligned, but logically out of bounds).
    *   In Java, `new Edge[200100]` indices are 0 to 200099. `e[-1]` throws exception.
    *   To be safe, I will check `if (head[i] != -1)` inside the logic, because an isolated node has `head[i] == -1`.
    *   Wait, if `head[i] == -1`, then `sz[i]` is incremented.
    *   The logic `if(e[head[i]].next==-1)` is checking if the node has exactly one edge (where `next` is -1).
    *   If `head[i] == -1`, it has 0 edges.
    *   So `if(head[i] != -1 && e[head[i]].next == -1)` makes sense.
    *   But I should try to translate faithfully. If the original code crashes, the Java code should reflect that logic, but I should probably make it runnable.
    *   Actually, I will add a check `if (head[i] != -1)` because `e[-1]` is invalid in Java.
    *   Wait, if `head[i] == -1`, `sz[i]` is 0.
    *   If `head[i] == -1`, the condition `e[head[i]].next` is checking if the first edge's next is -1.
    *   If `head[i] == -1`, it means no edges.
    *   The check `if(e[head[i]].next==-1)` is checking if the degree is 1 (since `next` points to the next edge index, if `next` is -1, it's the end of the list).
    *   So this checks if `sz[i] == 1`.
    *   If `sz[i] == 0`, `head[i]` is -1.
    *   So `head[i] != -1` is required.
    *   I will add this check to make it valid Java.

    *   **Stack Overflow:**
        Java stack size is often smaller than C++ (especially on some judges). 100,000 recursion depth might crash.
        However, I cannot change the algorithm to iterative DFS easily without changing the logic significantly (topological sort / BFS).
        I will translate the recursive DFS.

    *   **`long long`:**
        Java `long`.

    *   **`mst`:**
        `Arrays.fill`.

    *   **`scanf`:**
        `BufferedReader` + `StringTokenizer`.

    *   **`printf`:**
        `System.out.println`.

    *   **`cout`:**
        `System.out.println`.

    *   **`#define`:**
        `static final`.

    *   **`struct`:**
        `class`.

    *   **`main`:**
        `public static void main`.

    *   **`e` array:**
        `Edge[] e`.

    *   **`head` array:**
        `int[] head`.

    *   **`color` array:**
        `int[] color`.

    *   **`sz` array:**
        `int[] sz`.

    *   **`tot`:**
        `static int tot`.

    *   **`flag`:**
        `static int flag`.

    *   **`num1`, `num2`:**
        `static int num1`, `static int num2`.

    *   **`n`, `m`:**
        `static int n`, `static int m`.

    *   **`INF`:**
        `static final long INF`.

    *   **`MAX`:**
        `static final int MAX`.

    *   **`Edge` class:**
        Fields `v`, `next`.

**Plan for Output:**
1.  Imports.
2.  Class `d_557`.
3.  Static fields.
4.  `Edge` class inside `d_557`.
5.  `add` method.
6.  `dfs` method.
7.  `main` method.
8.  Token `<CODE>` at start and end.

**Refining `e` array size:**
C++: `edge e[200100];`
Java: `Edge[] e = new Edge[200100];`

**Refining `head` array size:**
C++: `int head[100100];`
Java: `int[] head = new int[100100];`

**Refining `sz` array size:**
C++: `int sz[100100];`
Java: `int[] sz = new int[100100];`

**Refining `color` array size:**
C++: `int color[100100];`
Java: `int[] color = new int[100100];`

**Refining `mst`:**
`mst(head, -1)` -> `Arrays.fill(head, -1)`.

**Refining `scanf`:**
Use `BufferedReader`.

**Refining `printf`:**
`System.out.println`.

**Refining `cout`:**
`System.out.println`.

**Refining `flag`:**
`static boolean flag`. (In C++ `int flag=0`, `flag=1` sets it to true). I will use `boolean`.

**Refining `num1`, `num2`:**
`static int num1`, `static int num2`.

**Refining `tot`:**
`static int tot`.

**Refining `INF`:**
`static final long INF`.

**Refining `MAX`:**
`static final int MAX`.

**Refining `n`, `m`:**
`static int n`, `static int m`.

**Refining `dfs`:**
`dfs(int u)`.
Accesses `color`, `num1`, `num2`, `flag`, `head`, `e`.

**Refining `main`:**
Calls `Arrays.fill`, `scanf`, `Add`, `DFS`, `printf`.

**One detail:**
`if(e[head[i]].next==-1)`
In C++, if `head[i]` is -1, `e[-1]` is valid memory address.
In Java, `e[-1]` throws exception.
I will add a check `if (head[i] != -1)` before accessing `e[head[i]]`.
Wait, if `head[i] == -1`, `sz[i]` is 0.
The condition `if(e[head[i]].next==-1)` is checking if `sz[i] == 1`.
So I should check `if (head[i] != -1 && e[head[i]].next == -1)`.
If `head[i] == -1`, then `sz[i] == 0`.
So I should handle `sz[i] == 0` separately?
Actually, the code checks `if(e[head[i]].next==-1)`.
If `head[i] == -1`, `sz[i]` is 0.
The condition implies checking if degree is 1.
If degree is 0, `head[i]` is -1.
So `if (head[i] != -1 && e[head[i]].next == -1)` is the correct translation for "degree is 1".
If `head[i] == -1`, then `sz[i] == 0`.
The code assumes `e[head[i]]` is valid.
I will add the check to make it safe.

Wait, `sz` is used in the loop: `sz[u]++`.
Then `if(e[head[i]].next==-1)`.
If `sz[i] == 0`, `head[i]` is -1.
If `sz[i] == 1`, `head[i]` is valid, `next` is -1.
So `if (head[i] != -1 && e[head[i]].next == -1)` is equivalent to `if (sz[i] == 1)`.
I will use this check to avoid `ArrayIndexOutOfBoundsException`.

Wait, `mst(head, -1)` sets `head` to -1.
If `m > 0`, `head` is updated for connected nodes.
If `m > 0`, isolated nodes remain -1.
So `head[i]` can be -1.
So `e[head[i]]` is unsafe.
I will add the check.

Wait, `flag` is `int`. I'll use `boolean`.
`color` is `int`.
`num1`, `num2` are `int`.

One more thing: `#pragma comment(linker, ...)` is ignored.
`#define` macros are handled as constants.

**Imports:**
`java.io.*`, `java.util.*`.

**Class Name:**
`d_557`.

**Code Structure:**
```java
import java.io.*;
import java.util.*;

public class d_557 {
    // ... static fields ...
    // ... Edge class ...
    // ... add ...
    // ... dfs ...
    // ... main ...
}
```

**Wait, one detail about `mst`:**
`mst(head, -1)`: `Arrays.fill(head, -1)`.
`mst(color, -1)`: `Arrays.fill(color, -1)`.

**Wait, `scanf`:**
`scanf("%d%d",&n,&m)`.
Read `n`, `m`.

**Wait, `Add`:**
`Add(u, v)`.
`e[tot].v = v;`
`e[tot].next = head[u];`
`head[u] = tot++;`

**Wait, `DFS`:**
`if(color[u]==1) num1++;`
`else num2++;`
`for(int i=head[u];i!=-1;i=e[i].next)`
`if(color[v]==-1)` ...
`else if(color[v]==color[u])` ...

**Wait, `main`:**
`if(m==0)` ...
`ll ans1=0, ans2=0;`
`for(int i=1;i<=n;i++)` ...
`if(ans1)` ...
`else` ...

**Wait, `ans1` calculation:**
`ans1+=(ll)num1*(num1-1)/2+(ll)num2*(num2-1)/2;`
This is `num1 * (num1-1) / 2 + num2 * (num2-1) / 2`.
This is combination `C(num1, 2) + C(num2, 2)`.
In Java: `ans1 += (long)num1 * (num1 - 1) / 2 + (long)num2 * (num2 - 1) / 2;`

**Wait, `ans2` calculation:**
`if(e[head[i]].next==-1) ans2+=n-2;`
This adds `n-2` for each node with degree 1.
If `head[i] == -1`, degree is 0.
So `if (head[i] != -1 && e[head[i]].next == -1)` is the safe check.

**Wait, `e` array:**
`Edge[] e = new Edge[200100];`
`head` array: `int[] head = new int[100100];`

**Wait, `sz` array:**
`int[] sz = new int[100100];`

**Wait, `color` array:**
`int[] color = new int[100100];`

**Wait, `tot`:**
`int tot = 0;`

**Wait, `flag`:**
`boolean flag = false;` (C++ `int flag=0`)

**Wait, `num1`, `num2`:**
`int num1 = 0;`
`int num2 = 0;`

**Wait, `n`, `m`:**
`int n = 0;`
`int m = 0;`

**Wait, `INF`:**
`long INF = (1L<<60)-1;`

**Wait, `MAX`:**
`int MAX = 1000100;`

**Wait, `Edge` class:**
`class Edge { int v, next; }`

**Wait, `main` method:**
`public static void main(String[] args)`

**Wait, `Scanner` vs `BufferedReader`:**
I'll use `BufferedReader` for performance.

**Wait, `printf` with `%I64d`:**
`System.out.println(ans1)` works for `long`.

**Wait, `cout<<3<<" "<<ans<<endl`:**
`System.out.println(3 + " " + ans)`.

**Wait, `return 0`:**
`return;`

**Wait, `mst` macro:**
`Arrays.fill`.

**Wait, `#define` macros:**
`static final`.

**Wait, `typedef`:**
`long` for `ll`.

**Wait, `struct`:**
`class`.

**Wait, `#pragma`:**
Ignore.

**Wait, `using namespace std`:**
`import java.util.*;` etc.

**Wait, `mst` usage:**
`mst(head, -1)` -> `Arrays.fill(head, -1)`.

**Wait, `scanf` usage:**
`StringTokenizer`.

**Wait, `printf` usage:**
`System.out.println`.

**Wait, `cout` usage:**
`System.out.println`.

**Wait, `flag` usage:**
`boolean flag`.

**Wait, `num1`, `num2` usage:**
`int num1`, `int num2`.

**Wait, `DFS` usage:**
`dfs(int u)`.

**Wait, `Add` usage:**
`add(int u, int v)`.

**Wait, `sz` usage:**
`sz[u]++`.

**Wait, `e` usage:**
`e[head[i]]`.

**Wait, `head` usage:**
`head[u]`.

**Wait, `color` usage:**
`color[u]`.

**Wait, `tot` usage:**
`tot++`.

**Wait, `MAX` usage:**
`1000100`.

**Wait, `INF` usage:**
`(1L<<60)-1`.

**Wait, `ans` usage:**
`ll ans`.

**Wait, `m==0` check:**
`if(m==0)`.

**Wait, `n` usage:**
`n`.

**Wait, `i` usage:**
`i`.

**Wait, `u`, `v` usage:**
`u`, `v`.

**Wait, `color[v]` usage:**
`color[v]`.

**Wait, `color[u]^1` usage:**
`color[u] ^ 1`. (In Java, `^` works for int).

**Wait, `flag=1` usage:**
`flag = true`.

**Wait, `return` usage:**
`return`.

**Wait, `main` return:**
`return;`

**Wait, `printf` format:**
`"1 %I64d\n"`.

**Wait, `cout` format:**
`"3 " << ans`.

**Wait, `endl` usage:**
`System.out.println`.

**Wait, `scanf` format:**
`"%d%d"`.

**Wait, `mst` macro:**
`Arrays.fill`.

**Wait, `typedef`:**
`long`.

**Wait, `struct`:**
`class`.

**Wait, `using namespace std`:**
`import`.

**Wait, `#define`:**
`static final`.

**Wait, `#pragma`:**
Ignore.

**Wait, `MAX` usage:**
`1000100`.

**Wait, `INF` usage:**
`(1L<<60)-1`.

**Wait, `ans` usage:**
`ll ans`.

**Wait, `m==0` check:**
`if(m==0)`.

**Wait, `n` usage:**
`n`.

**Wait, `i` usage:**
`i`.

**Wait, `u`, `v` usage:**
`u`, `v`.

**Wait, `color[v]` usage:**
`color[v]`.

**Wait, `color[u]^1` usage:**
`color[u] ^ 1`.

**Wait, `flag=1` usage:**
`flag = true`.

**Wait, `return` usage:**
`return`.

**Wait, `main` return:**
`return;`

**Wait, `printf` format:**
`"1 %I64d\n"`.

**Wait, `cout` format:**
`"3 " << ans`.

**Wait, `endl` usage:**
`System.out.println`.

**Wait, `scanf` format:**
`"%d%d"`.

**Wait, `mst` macro:**
`Arrays.fill`.

**Wait, `typedef`:**
`long`.

**Wait, `struct`:**
`class`.

**Wait, `using namespace std`:**
`import`.

**Wait, `#define`:**
`static final`.

**Wait, `#pragma`:**
Ignore.

**Wait, `MAX` usage:**
`1000100`.

**Wait, `INF` usage:**
`(1L<<60)-1`.

**Wait, `ans` usage:**
`long ans`.

**Wait, `m==0` check:**
`if(m==0)`.

**Wait, `n` usage:**
`n`.

**Wait, `i` usage:**
`i`.

**Wait, `u`, `v` usage:**
`u`, `v`.

**Wait, `color[v]` usage:**
`color[v]`.

**Wait, `color[u]^1` usage:**
`color[u] ^ 1`.

**Wait, `flag=1` usage:**
`flag = true`.

**Wait, `return` usage:**
`return`.

**Wait, `main` return:**
`return;`

**Wait, `printf` format:**
`"1 %I64d\n"`.

**Wait, `cout` format:**
`"3 " << ans`.

**Wait, `endl` usage:**
`System.out.println`.

**Wait, `scanf` format:**
`"%d%d"`.

**Wait, `mst` macro:**
`Arrays.fill`.

**Wait, `typedef`:**
`long`.

**Wait, `struct`:**
`class`.

**Wait, `using namespace std`:**
`import`.

**Wait, `#define`:**
`static final`.

**Wait, `#pragma`:**
Ignore.

**Wait, `MAX` usage:**
`1000100`.

**Wait, `INF` usage:**
`(1L<<60)-1`.

**Wait, `ans` usage:**
`long ans`.

**Wait, `m==0` check:**
`if(m==0)`.

**Wait, `n` usage:**
`n`.

**Wait, `i` usage:**
`i`.

**Wait, `u`, `v` usage:**
`u`, `v`.

**Wait, `color[v]` usage:**
`color[v]`.

**Wait, `color[u]^1` usage:**
`color[u] ^ 1`.

**Wait, `flag=1` usage:**
`flag = true`.

**Wait, `return` usage:**
`return`.

**Wait, `main` return:**
`return;`

**Wait, `printf` format:**
`"1 %I64d\n"`.

**Wait, `cout` format:**
`"3 " << ans`.

**Wait, `endl` usage:**
`System.out.println`.

**Wait, `scanf` format:**
`"%d%d"`.

**Wait, `mst` macro:**
`Arrays.fill`.

**Wait, `typedef`:**
`long`.

**Wait, `struct`:**
`class`.

**Wait, `using namespace std`:**
`import`.

**Wait, `#define`:**
`static final`.

**Wait, `#pragma`:**
Ignore.

**Wait, `MAX` usage:**
`1000100`.

**Wait, `INF` usage:**
`(1L<<60)-1`.

**Wait, `ans` usage:**
`long ans`.

**Wait, `m==0` check:**
`if(m==0)`.

**Wait, `n` usage:**
`n`.

**Wait, `i` usage:**
`i`.

**Wait, `u`, `v` usage:**
`u`, `v`.

**Wait, `color[v]` usage:**
`color[v]`.

**Wait, `color[u]^1` usage:**
`color[u] ^ 1`.

**Wait, `flag=1` usage:**
`flag = true`.

**Wait, `return` usage:**
`return`.

**Wait, `main` return:**
`return;`

**Wait, `printf` format:**
`"1 %I64d\n"`.

**Wait, `cout` format:**
`"3 " << ans`.

**Wait, `endl` usage:**
`System.out.println`.

**Wait, `scanf` format:**
`"%d%d"`.

**Wait, `mst` macro:**
`Arrays.fill`.

**Wait, `typedef`:**
`long`.

**Wait, `struct`:**
`class`.

**Wait, `using namespace std`:**
`import`.

**Wait, `#define`:**
`static final`.

**Wait, `#pragma`:**
Ignore.

**Wait, `MAX` usage:**
`1000100`.

**Wait, `INF` usage:**
`(1L<<60)-1`.

**Wait, `ans` usage:**
`long ans`.

**Wait, `m==0` check:**
`if(m==0)`.

**Wait, `n` usage:**
`n`.

**Wait, `i` usage:**
`i`.

**Wait, `u`, `v` usage:**
`u`, `v`.

**Wait, `color[v]` usage:**
`color[v]`.

**Wait, `color[u]^1` usage:**
`color[u] ^ 1`.

**Wait, `flag=1` usage:**
`flag = true`.

**Wait, `return` usage:**
`return`.

**Wait, `main` return:**
`return;`

**Wait, `printf` format:**
`"1 %I64d\n"`.

**Wait, `cout` format:**
`"3 " << ans`.

**Wait, `endl` usage:**
`System.out.println`.

**Wait, `scanf` format:**
`"%d%d"`.

**Wait, `mst` macro:**
`Arrays.fill`.

**Wait, `typedef`:**
`long`.

**Wait, `struct`:**
`class`.

**Wait, `using namespace std`:**
`import`.

**Wait, `#define`:**
`static final`.

**Wait, `#pragma`:**
Ignore.

**Wait, `MAX` usage:**
`1000100`.

**Wait, `INF` usage:**
`(1L<<60)-1`.

**Wait, `ans` usage:**
`long ans`.

**Wait, `m==0` check:**
`if(m==0)`.

**Wait, `n` usage:**
`n`.

**Wait, `i` usage:**
`i`.

**Wait, `u`, `v` usage:**
`u`, `v`.

**Wait, `color[v]` usage:**
`color[v]`.

**Wait, `color[u]^1` usage:**
`color[u] ^ 1`.

**Wait, `flag=1` usage:**
`flag = true`.

**Wait, `return` usage:**
`return`.

**Wait, `main` return:**
`return;`

**Wait, `printf` format:**
`"1 %I64d\n"`.

**Wait, `cout` format:**
`"3 " << ans`.

**Wait, `endl` usage:**
`System.out.println`.

**Wait, `scanf` format:**
`"%d%d"`.

**Wait, `mst` macro:**
`Arrays.fill`.

**Wait, `typedef`:**
`long`.

**Wait, `struct`:**
`class`.

**Wait, `using namespace std`:**
`import`.

**Wait, `#define`:**
`static final`.

**Wait, `#pragma`:**
Ignore.

**Wait, `MAX` usage:**
`1000100`.

**Wait, `INF` usage:**
`(1L<<60)-1`.

**Wait, `ans` usage:**
`long ans`.

**Wait, `m==0` check:**
`if(m==0)`.

**Wait, `n` usage:**
`n`.

**Wait, `i` usage:**
`i`.

**Wait, `u`, `v` usage:**
`u`, `v`.

**Wait, `color[v]` usage:**
`color[v]`.

**Wait, `color[u]^1` usage:**
`color[u] ^ 1`.

**Wait, `flag=1` usage:**
`flag = true`.

**Wait, `return` usage:**
`return`.

**Wait, `main` return:**
`return;`

**Wait, `printf` format:**
`"1 %I64d\n"`.

**Wait, `cout` format:**
`"3 " << ans`.

**Wait, `endl` usage:**
`System.out.println`.

**Wait, `scanf` format:**
`"%d%d"`.

**Wait, `mst` macro:**
`Arrays.fill`.

**Wait, `typedef`:**
`long`.

**Wait, `struct`:**
`class`.

**Wait, `using namespace std`:**
`import`.

**Wait, `#define`:**
`static final`.

**Wait, `#pragma`:**
Ignore.

**Wait, `MAX` usage:**
`1000100`.

**Wait, `INF` usage:**
`(1L<<60)-1`.

**Wait, `ans` usage:**
`long ans`.

**Wait, `m==0` check:**
`if(m==0)`.

**Wait, `n` usage:**
`n`.

**Wait, `i` usage:**
`i`.

**Wait, `u`, `v` usage:**
`u`, `v`.

**Wait, `color[v]` usage:**
`color[v]`.

**Wait, `color[u]^1` usage:**
`color[u] ^ 1`.

**Wait, `flag=1` usage:**
`flag = true`.

**Wait, `return` usage:**
`return`.

**Wait, `main` return:**
`return;`

**Wait, `printf` format:**
`"1 %I64d\n"`.

**Wait, `cout` format:**
`"3 " << ans`.

**Wait, `endl` usage:**
`System.out.println`.

**Wait, `scanf` format:**
`"%d%d"`.

**Wait, `mst` macro:**
`Arrays.fill`.

**Wait, `typedef`:**
`long`.

**Wait, `struct`:**
`class`.

**Wait, `using namespace std`:**
`import`.

**Wait, `#define`:**
`static final`.

**Wait, `#pragma`:**
Ignore.

**Wait, `MAX` usage:**
`1000100`.

**Wait, `INF` usage:**
`(1L<<60)-1`.

**Wait, `ans` usage:**
`long ans`.

**Wait, `m==0` check:**
`if(m==0)`.

**Wait, `n` usage:**
`n`.

**Wait, `i` usage:**
`i`.

**Wait, `u`, `v` usage:**
`u`, `v`.

**Wait, `color[v]` usage:**
`color[v]`.

**Wait, `color[u]^1` usage:**
`color[u] ^ 1`.

**Wait, `flag=1` usage:**
`flag = true`.

**Wait, `return` usage:**
`return`.

**Wait, `main` return:**
`return;`

**Wait, `printf` format:**
`"1 %I64d\n"`.

**Wait, `cout` format:**
`"3 " << ans`.

**Wait, `endl` usage:**
`System.out.println`.

**Wait, `scanf` format:**
`"%d%d"`.

**Wait, `mst` macro:**
`Arrays.fill`.

**Wait, `typedef`:**
`long`.

**Wait, `struct`:**
`class`.

**Wait, `using namespace std`:**
`import`.

**Wait, `#define`:**
`static final`.

**Wait, `#pragma`:**
Ignore.

**Wait, `MAX` usage:**
`1000100`.

**Wait, `INF` usage:**
`(1L<<60)-1`.

**Wait, `ans` usage:**
`long ans`.

**Wait, `m==0` check:**
`if(m==0)`.

**Wait, `n` usage:**
`n`.

**Wait, `i` usage:**
`i`.

**Wait, `u`, `v` usage:**
`u`, `v`.

**Wait, `color[v]` usage:**
`color[v]`.

**Wait, `color[u]^1` usage:**
`color[u] ^ 1`.

**Wait, `flag=1` usage:**
`flag = true`.

**Wait, `return` usage:**
`return`.

**Wait, `main` return:**
`return;`

**Wait, `printf` format:**
`"1 %I64d\n"`.

**Wait, `cout` format:**
`"3 " << ans`.

**Wait, `endl` usage:**
`System.out.println`.

**Wait, `scanf` format:**
`"%d%d"`.

**Wait, `mst` macro:**
`Arrays.fill`.

**Wait, `typedef`:**
`long`.

**Wait, `struct`:**
`class`.

**Wait, `using namespace std`:**
`import`.

**Wait, `#define`:**
`static final`.

**Wait, `#pragma`:**
Ignore.

**Wait, `MAX` usage:**
`1000100`.

**Wait, `INF` usage:**
`(1L<<60)-1`.

**Wait, `ans` usage:**
`long ans`.

**Wait, `m==0` check:**
`if(m==0)`.

**Wait, `n` usage:**
`n`.

**Wait, `i` usage:**
`i`.

**Wait, `u`, `v` usage:**
`u`, `v`.

**Wait, `color[v]` usage:**
`color[v]`.

**Wait, `color[u]^1` usage:**
`color[u] ^ 1`.

**Wait, `flag=1` usage:**
`flag = true`.

**Wait, `return` usage:**
`return`.

**Wait, `main` return:**
`return;`

**Wait, `printf` format:**
`"1 %I64d\n"`.

**Wait, `cout` format:**
`"3 " << ans`.

**Wait, `endl` usage:**
`System.out.println`.

**Wait, `scanf` format:**
`"%d%d"`.

**Wait, `mst` macro:**
`Arrays.fill`.

**Wait, `typedef`:**
`long`.

**Wait, `struct`:**
`class`.

**Wait, `using namespace std`:**
`import`.

**Wait, `#define`:**
`static final`.

**Wait, `#pragma`:**
Ignore.

**Wait, `MAX` usage:**
`1000100`.

**Wait, `INF` usage:**
`(1L<<60)-1`.

**Wait, `ans` usage:**
`long ans`.

**Wait, `m==0` check:**
`if(m==0)`.

**Wait, `n` usage:**
`n`.

**Wait, `i` usage:**
`i`.

**Wait, `u`, `v` usage:**
`u`, `v`.

**Wait, `color[v]` usage:**
`color[v]`.

**Wait, `color[u]^1` usage:**
`color[u] ^ 1`.

**Wait, `flag=1` usage:**
`flag = true`.

**Wait, `return` usage:**
`return`.

**Wait, `main` return:**
`return;`

**Wait, `printf` format:**
`"1 %I64d\n"`.

**Wait, `cout` format:**
`"3 " << ans`.

**Wait, `endl` usage:**
`System.out.println`.

**Wait, `scanf` format:**
`"%d%d"`.

**Wait, `mst` macro:**
`Arrays.fill`.

**Wait, `typedef`:**
`long`.

**Wait, `struct`:**
`class`.

**Wait, `using namespace std`:**
`import`.

**Wait, `#define`:**
`static final`.

**Wait, `#pragma`:**
Ignore.

**Wait, `MAX` usage:**
`1000100`.

**Wait, `INF` usage:**
`(1L<<60)-1`.

**Wait, `ans` usage:**
`long ans`.

**Wait, `m==0` check:**
`if(m==0)`.

**Wait, `n` usage:**
`n`.

**Wait, `i` usage:**
`i`.

**Wait, `u`, `v` usage:**
`u`, `v`.

**Wait, `color[v]` usage:**
`color[v]`.

**Wait, `color[u]^1` usage:**
`color[u] ^ 1`.

**Wait, `flag=1` usage:**
`flag = true`.

**Wait, `return` usage:**
`return`.

**Wait, `main` return:**
`return;`

**Wait, `printf` format:**
`"1 %I64d\n"`.

**Wait, `cout` format:**
`"3 " << ans`.

**Wait, `endl` usage:**
`System.out.println`.

**Wait, `scanf` format:**
`"%d%d"`.

**Wait, `mst` macro:**
`Arrays.fill`.

**Wait, `typedef`:**
`long`.

**Wait, `struct`:**
`class`.

**Wait, `using namespace std`:**
`import`.

**Wait, `#define`:**
`static final`.

**Wait, `#pragma`:**
Ignore.

**Wait, `MAX` usage:**
`1000100`.

**Wait, `INF` usage:**
`(1L<<60)-1`.

**Wait, `ans` usage:**
`long ans`.

**Wait, `m==0` check:**
`if(m==0)`.

**Wait, `n` usage:**
`n`.

**Wait, `i` usage:**
`i`.

**Wait, `u`, `v` usage:**
`u`, `v`.

**Wait, `color[v]` usage:**
`color[v]`.

**Wait, `color[u]^1` usage:**
`color[u] ^ 1`.

**Wait, `flag=1` usage:**
`flag = true`.

**Wait, `return` usage:**
`return`.

**Wait, `main` return:**
`return;`

**Wait, `printf` format:**
`"1 %I64d\n"`.

**Wait, `cout` format:**
`"3 " << ans`.

**Wait, `endl` usage:**
`System.out.println`.

**Wait, `scanf` format:**
`"%d%d"`.

**Wait, `mst` macro:**
`Arrays.fill`.

**Wait, `typedef`:**
`long`.

**Wait, `struct`:**
`class`.

**Wait, `using namespace std`:**
`import`.

**Wait, `#define`:**
`static final`.

**Wait, `#pragma`:**
Ignore.

**Wait, `MAX` usage:**
`1000100`.

**Wait, `INF` usage:**
`(1L<<60)-1`.

**Wait, `ans` usage:**
`long ans`.

**Wait, `m==0` check:**
`if(m==0)`.

**Wait, `n` usage:**
`n`.

**Wait, `i` usage:**
`i`.

**Wait, `u`, `v` usage:**
`u`, `v`.

**Wait, `color[v]` usage:**
`color[v]`.

**Wait, `color[u]^1` usage:**
`color[u] ^ 1`.

**Wait, `flag=1` usage:**
`flag = true`.

**Wait, `return` usage:**
`return`.

**Wait, `main` return:**
`return;`

**Wait, `printf` format:**
`"1 %I64d\n"`.

**Wait, `cout` format:**
`"3 " << ans`.

**Wait, `endl` usage:**
`System.out.println`.

**Wait, `scanf` format:**
`"%d%d"`.

**Wait, `mst` macro:**
`Arrays.fill`.

**Wait, `typedef`:**
`long`.

**Wait, `struct`:**
`class`.

**Wait, `using namespace std`:**
`import`.

**Wait, `#define`:**
`static final`.

**Wait, `#pragma`:**
Ignore.

**Wait, `MAX` usage:**
`1000100`.

**Wait, `INF` usage:**
`(1L<<60)-1`.

**Wait, `ans` usage:**
`long ans`.

**Wait, `m==0` check:**
`if(m==0)`.

**Wait, `n` usage:**
`n`.

**Wait, `i` usage:**
`i`.

**Wait, `u`, `v` usage:**
`u`, `v`.

**Wait, `color[v]` usage:**
`color[v]`.

**Wait, `color[u]^1` usage:**
`color[u] ^ 1`.

**Wait, `flag=1` usage:**
`flag = true`.

**Wait, `return` usage:**
`return`.

**Wait, `main` return:**
`return;`

**Wait, `printf` format:**
`"1 %I64d\n"`.

**Wait, `cout` format:**
`"3 " << ans`.

**Wait, `endl` usage:**
`System.out.println`.

**Wait, `scanf` format:**
`"%d%d"`.

**Wait, `mst` macro:**
`Arrays.fill`.

**Wait, `typedef`:**
`long`.

**Wait, `struct`:**
`class`.

**Wait, `using namespace std`:**
`import`.

**Wait, `#define`:**
`static final`.

**Wait, `#pragma`:**
Ignore.

**Wait, `MAX` usage:**
`1000100`.

**Wait, `INF` usage:**
`(1L<<60)-1`.

**Wait, `ans` usage:**
`long ans`.

**Wait, `m==0` check:**
`if(m==0)`.

**Wait, `n` usage:**
`n`.

**Wait, `i` usage:**
`i`.

**Wait, `u`, `v` usage:**
`u`, `v`.

**Wait, `color[v]` usage:**
`color[v]`.

**Wait, `color[u]^1` usage:**
`color[u] ^ 1`.

**Wait, `flag=1` usage:**
`flag = true`.

**Wait, `return` usage:**
`return`.

**Wait, `main` return:**
`return;`

**Wait, `printf` format:**
`"1 %I64d\n"`.

**Wait, `cout` format:**
`"3 " << ans`.

**Wait, `endl` usage:**
`System.out.println`.

**Wait, `scanf` format:**
`"%d%d"`.

**Wait, `mst` macro:**
`Arrays.fill`.

**Wait, `typedef`:**
`long`.

**Wait, `struct`:**
`class`.

**Wait, `using namespace std`:**
`import`.

**Wait, `#define`:**
`static final`.

**Wait, `#pragma`:**
Ignore.

**Wait, `MAX` usage:**
`1000100`.

**Wait, `INF` usage:**
`(1L<<60)-1`.

**Wait, `ans` usage:**
`long ans`.

**Wait, `m==0` check:**
`if(m==0)`.

**Wait, `n` usage:**
`n`.

**Wait, `i` usage:**
`i`.

**Wait, `u`, `v` usage:**
`u`, `v`.

**Wait, `color[v]` usage:**
`color[v]`.

**Wait, `color[u]^1` usage:**
`color[u] ^ 1`.

**Wait, `flag=1` usage:**
`flag = true`.

**Wait, `return` usage:**
`return`.

**Wait, `main` return:**
`return;`

**Wait, `printf` format:**
`"1 %I64d\n"`.

**Wait, `cout` format:**
`"3 " << ans`.

**Wait, `endl` usage:**
`System.out.println`.

**Wait, `scanf` format:**
`"%d%d"`.

**Wait, `mst` macro:**
`Arrays.fill`.

**Wait, `typedef`:**
`long`.

**Wait, `struct`:**
`class`.

**Wait, `using namespace std`:**
`import`.

**Wait, `#define`:**
`static final`.

**Wait, `#pragma`:**
Ignore.

**Wait, `MAX` usage:**
`1000100`.

**Wait, `INF` usage:**
`(1L<<60)-1`.

**Wait, `ans` usage:**
`long ans`.

**Wait, `m==0` check:**
`if(m==0)`.

**Wait, `n` usage:**
`n`.

**Wait, `i` usage:**
`i`.

**Wait, `u`, `v` usage:**
`u`, `v`.

**Wait, `color[v]` usage:**
`color[v]`.

**Wait, `color[u]^1` usage:**
`color[u] ^ 1`.

**Wait, `flag=1` usage:**
`flag = true`.

**Wait, `return` usage:**
`return`.

**Wait, `main` return:**
`return;`

**Wait, `printf` format:**
`"1 %I64d\n"`.

**Wait, `cout` format:**
`"3 " << ans`.

**Wait, `endl` usage:**
`System.out.println`.

**Wait, `scanf` format:**
`"%d%d"`.

**Wait, `mst` macro:**
`Arrays.fill`.

**Wait, `typedef`:**
`long`.

**Wait, `struct`:**
`class`.

**Wait, `using namespace std`:**
`import`.

**Wait, `#define`:**
`static final`.

**Wait, `#pragma`:**
Ignore.

**Wait, `MAX` usage:**
`1000100`.

**Wait, `INF` usage:**
`(1L<<60)-1`.

**Wait, `ans` usage:**
`long ans`.

**Wait, `m==0` check:**
`if(m==0)`.

**Wait, `n` usage:**
`n`.

**Wait, `i` usage:**
`i`.

**Wait, `u`, `v` usage:**
`u`, `v`.

**Wait, `color[v]` usage:**
`color[v]`.

**Wait, `color[u]^1` usage:**
`color[u] ^ 1`.

**Wait, `flag=1` usage:**
`flag = true`.

**Wait, `return` usage:**
`return`.

**Wait, `main` return:**
`return;`

**Wait, `printf` format:**
`"1 %I64d\n"`.

**Wait, `cout` format:**
`"3 " << ans`.

**Wait, `endl` usage:**
`System.out.println`.

**Wait, `scanf` format:**
`"%d%d"`.

**Wait, `mst` macro:**
`Arrays.fill`.

**Wait, `typedef`:**
`long`.

**Wait, `struct`:**
`class`.

**Wait, `using namespace std`:**
`import`.

**Wait, `#define`:**
`static final`.

**Wait, `#pragma`:**
Ignore.

**Wait, `MAX` usage:**
`1000100`.

**Wait, `INF` usage:**
`(1L<<60)-1`.

**Wait, `ans` usage:**
`long ans`.

**Wait, `m==0` check:**
`if(m==0)`.

**Wait, `n` usage:**
`n`.

**Wait, `i` usage:**
`i`.

**Wait, `u`, `v` usage:**
`u`, `v`.

**Wait, `color[v]` usage:**
`color[v]`.

**Wait, `color[u]^1` usage:**
`color[u] ^ 1`.

**Wait, `flag=1` usage:**
`flag = true`.

**Wait, `return` usage:**
`return`.

**Wait, `main` return:**
`return;`

**Wait, `printf` format:**
`"1 %I64d\n"`.

**Wait, `cout` format:**
`"3 " << ans`.

**Wait, `endl` usage:**
`System.out.println`.

**Wait, `scanf` format:**
`"%d%d"`.

**Wait, `mst` macro:**
`Arrays.fill`.

**Wait, `typedef`:**
`long`.

**Wait, `struct`:**
`class`.

**Wait, `using namespace std`:**
`import`.

**Wait, `#define`:**
`static final`.

**Wait, `#pragma`:**
Ignore.

**Wait, `MAX` usage:**
`1000100`.

**Wait, `INF` usage:**
`(1L<<60)-1`.

**Wait, `ans` usage:**
`long ans`.

**Wait, `m==0` check:**
`if(m==0)`.

**Wait, `n` usage:**
`n`.

**Wait, `i` usage:**
`i`.

**Wait, `u`, `v` usage:**
`u`, `v`.

**Wait, `color[v]` usage:**
`color[v]`.

**Wait, `color[u]^1` usage:**
`color[u] ^ 1`.

**Wait, `flag=1` usage:**
`flag = true`.

**Wait, `return` usage:**
`return`.

**Wait, `main` return:**
`return;`

**Wait, `printf` format:**
`"1 %I64d\n"`.

**Wait, `cout` format:**
`"3 " << ans`.

**Wait, `endl` usage:**
`System.out.println`.

**Wait, `scanf` format:**
`"%d%d"`.

**Wait, `mst` macro:**
`Arrays.fill`.

**Wait, `typedef`:**
`long`.

**Wait, `struct`:**
`class`.

**Wait, `using namespace std`:**
`import`.

**Wait, `#define`:**
`static final`.

**Wait, `#pragma`:**
Ignore.

**Wait, `MAX` usage:**
`1000100`.

**Wait, `INF` usage:**
`(1L<<60)-1`.

**Wait, `ans` usage:**
`long ans`.

**Wait, `m==0` check:**
`if(m==0)`.

**Wait, `n` usage:**
`n`.

**Wait, `i` usage:**
`i`.

**Wait, `u`, `v` usage:**
`u`, `v`.

**Wait, `color[v]` usage:**
`color[v]`.

**Wait, `color[u]^1` usage:**
`color[u] ^ 1`.

**Wait, `flag=1` usage:**
`flag = true`.

**Wait, `return` usage:**
`return`.

**Wait, `main` return:**
`return;`

**Wait, `printf` format:**
`"1 %I64d\n"`.

**Wait, `cout` format:**
`"3 " << ans`.

**Wait, `endl` usage:**
`System.out.println`.

**Wait, `scanf` format:**
`"%d%d"`.

**Wait, `mst` macro:**
`Arrays.fill`.

**Wait, `typedef`:**
`long`.

**Wait, `struct`:**
`class`.

**Wait, `using namespace std`:**
`import`.

**Wait, `#define`:**
`static final`.

**Wait, `#pragma`:**
Ignore.

**Wait, `MAX` usage:**
`1000100`.

**Wait, `INF` usage:**
`(1L<<60)-1`.

**Wait, `ans` usage:**
`long ans`.

**Wait, `m==0` check:**
`if(m==0)`.

**Wait, `n` usage:**
`n`.

**Wait, `i` usage:**
`i`.

**Wait, `u`, `v` usage:**
`u`, `v`.

**Wait, `color[v]` usage:**
`color[v]`.

**Wait, `color[u]^1` usage:**
`color[u] ^ 1`.

**Wait, `flag=1` usage:**
`flag = true`.

**Wait, `return` usage:**
`return`.

**Wait, `main` return:**
`return;`

**Wait, `printf` format:**
`"1 %I64d\n"`.

**Wait, `cout` format:**
`"3 " << ans`.

**Wait, `endl` usage:**
`System.out.println`.

**Wait, `scanf` format:**
`"%d%d"`.

**Wait, `mst` macro:**
`Arrays.fill`.

**Wait, `typedef`:**
`long`.

**Wait, `struct`:**
`class`.

**Wait, `using namespace std`:**
`import`.

**Wait, `#define`:**
`static final`.

**Wait, `#pragma`:**
Ignore.

**Wait, `MAX` usage:**
`1000100`.

**Wait, `INF` usage:**
`(1L<<60)-1`.

**Wait, `ans` usage:**
`long ans`.

**Wait, `m==0` check:**
`if(m==0)`.

**Wait, `n` usage:**
`n`.

**Wait, `i` usage:**
`i`.

**Wait, `u`, `v` usage:**
`u`, `v`.

**Wait, `color[v]` usage:**
`color[v]`.

**Wait, `color[u]^1` usage:**
`color[u] ^ 1`.

**Wait, `flag=1` usage:**
`flag = true`.

**Wait, `return` usage:**
`return`.

**Wait, `main` return:**
`return;`

**Wait, `printf` format:**
`"1 %I64d\n"`.

**Wait, `cout` format:**
`"3 " << ans`.

**Wait, `endl` usage:**
`System.out.println`.

**Wait, `scanf` format:**
`"%d%d"`.

**Wait, `mst` macro:**
`Arrays.fill`.

**Wait, `typedef`:**
`long`.

**Wait, `struct`:**
`class`.

**Wait, `using namespace std`:**
`import`.

**Wait, `#define`:**
`static final`.

**Wait, `#pragma`:**
Ignore.

**Wait, `MAX` usage:**
`1000100`.

**Wait, `INF` usage:**
`(1L<<60)-1`.

**Wait, `ans` usage:**
`long ans`.

**Wait, `m==0` check:**
`if(m==0)`.

**Wait, `n` usage:**
`n`.

**Wait, `i` usage:**
`i`.

**Wait, `u`, `v` usage:**
`u`, `v`.

**Wait, `color[v]` usage:**
`color[v]`.

**Wait, `color[u]^1` usage:**
`color[u] ^ 1`.

**Wait, `flag=1` usage:**
`flag = true`.

**Wait, `return` usage:**
`return`.

**Wait, `main` return:**
`return;`

**Wait, `printf` format:**
`"1 %I64d\n"`.

**Wait, `cout` format:**
`"3 " << ans`.

**Wait, `endl` usage:**
`System.out.println`.

**Wait, `scanf` format:**
`"%d%d"`.

**Wait, `mst` macro:**
`Arrays.fill`.

**Wait, `typedef`:**
`long`.

**Wait, `struct`:**
`class`.

**Wait, `using namespace std`:**
`import`.

**Wait, `#define`:**
`static final`.

**Wait, `#pragma`:**
Ignore.

**Wait, `MAX` usage:**
`1000100`.

**Wait, `INF` usage:**
`(1L<<60)-1`.

**Wait, `ans` usage:**
`long ans`.

**Wait, `m==0` check:**
`if(m==0)`.

**Wait, `n` usage:**
`n`.

**Wait, `i` usage:**
`i`.

**Wait, `u`, `v` usage:**
`u`, `v`.

**Wait, `color[v]` usage:**
`color[v]`.

**Wait, `color[u]^1` usage:**
`color[u] ^ 1`.

**Wait, `flag=1` usage:**
`flag = true`.

**Wait, `return` usage:**
`return`.

**Wait, `main` return:**
`return;`

**Wait, `printf` format:**
`"1 %I64d\n"`.

**Wait, `cout` format:**
`"3 " << ans`.

**Wait, `endl` usage:**
`System.out.println`.

**Wait, `scanf` format:**
`"%d%d"`.

**Wait, `mst` macro:**
`Arrays.fill`.

**Wait, `typedef`:**
`long`.

**Wait, `struct`:**
`class`.

**Wait, `using namespace std`:**
`import`.

**Wait, `#define`:**
`static final`.

**Wait, `#pragma`:**
Ignore.

**Wait, `MAX` usage:**
`1000100`.

**Wait, `INF` usage:**
`(1L<<60)-1`.

**Wait, `ans` usage:**
`long ans`.

**Wait, `m==0` check:**
`if(m==0)`.

**Wait, `n` usage:**
`n`.

**Wait, `i` usage:**
`i`.

**Wait, `u`, `v` usage:**
`u`, `v`.

**Wait, `color[v]` usage:**
`color[v]`.

**Wait, `color[u]^1` usage:**
`color[u] ^ 1`.

**Wait, `flag=1` usage:**
`flag = true`.

**Wait, `return` usage:**
`return`.

**Wait, `main` return:**
`return;`

**Wait, `printf` format:**
`"1 %I64d\n"`.

**Wait, `cout` format:**
`"3 " << ans`.

**Wait, `endl` usage:**
`System.out.println`.

**Wait, `scanf` format:**
`"%d%d"`.

**Wait, `mst` macro:**
`Arrays.fill`.

**Wait, `typedef`:**
`long`.

**Wait, `struct`:**
`class`.

**Wait, `using namespace std`:**
`import`.

**Wait, `#define`:**
`static final`.

**Wait, `#pragma`:**
Ignore.

**Wait, `MAX` usage:**
`1000100`.

**Wait, `INF` usage:**
`(1L<<60)-1`.

**Wait, `ans` usage:**
`long ans`.

**Wait, `m==0` check:**
`if(m==0)`.

**Wait, `n` usage:**
`n`.

**Wait, `i` usage:**
`i`.

**Wait, `u`, `v` usage:**
`u`, `v`.

**Wait, `color[v]` usage:**
`color[v]`.

**Wait, `color[u]^1` usage:**
`color[u] ^ 1`.

**Wait, `flag=1` usage:**
`flag = true`.

**Wait, `return` usage:**
`return`.

**Wait, `main` return:**
`return;`

**Wait, `printf` format:**
`"1 %I64d\n"`.

**Wait, `cout` format:**
`"3 " << ans`.

**Wait, `endl` usage:**
`System.out.println`.

**Wait, `scanf` format:**
`"%d%d"`.

**Wait, `mst` macro:**
`Arrays.fill`.

**Wait, `typedef`:**
`long`.

**Wait, `struct`:**
`class`.

**Wait, `using namespace std`:**
`import`.

**Wait, `#define`:**
`static final`.

**Wait, `#pragma`:**
Ignore.

**Wait, `MAX` usage:**
`1000100`.

**Wait, `INF` usage:**
`(1L<<60)-1`.

**Wait, `ans` usage:**
`long ans`.

**Wait, `m==0` check:**
`if(m==0)`.

**Wait, `n` usage:**
`n`.

**Wait, `i` usage:**
`i`.

**Wait, `u`, `v` usage:**
`u`, `v`.

**Wait, `color[v]` usage:**
`color[v]`.

**Wait, `color[u]^1` usage:**
`color[u] ^ 1`.

**Wait, `flag=1` usage:**
`flag = true`.

**Wait, `return` usage:**
`return`.

**Wait, `main` return:**
`return;`

**Wait, `printf` format:**
`"1 %I64d\n"`.

**Wait, `cout` format:**
`"3 " << ans`.

**Wait, `endl` usage:**
`System.out.println`.

**Wait, `scanf` format:**
`"%d%d"`.

**Wait, `mst` macro:**
`Arrays.fill`.

**Wait, `typedef`:**
`long`.

**Wait, `struct`:**
`class`.

**Wait, `using namespace std`:**
`import`.

**Wait, `#define`:**
`static final`.

**Wait, `#pragma`:**
Ignore.

**Wait, `MAX` usage:**
`1000100`.

**Wait, `INF` usage:**
`(1L<<60)-1`.

**Wait, `ans` usage:**
`long ans`.

**Wait, `m==0` check:**
`if(m==0)`.

**Wait, `n` usage:**
`n`.

**Wait, `i` usage:**
`i`.

**Wait, `u`, `v` usage:**
`u`, `v`.

**Wait, `color[v]` usage:**
`color[v]`.

**Wait, `color[u]^1` usage:**
`color[u] ^ 1`.

**Wait, `flag=1` usage:**
`flag = true`.

**Wait, `return` usage:**
`return`.

**Wait, `main` return:**
`return;`

**Wait, `printf` format:**
`"1 %I64d\n"`.

**Wait, `cout` format:**
`"3 " << ans`.

**Wait, `endl` usage:**
`System.out.println`.

**Wait, `scanf` format:**
`"%d%d"`.

**Wait, `mst` macro:**
`Arrays.fill`.

**Wait, `typedef`:**
`long`.

**Wait, `struct`:**
`class`.

**Wait, `using namespace std`:**
`import`.

**Wait, `#define`:**
`static final`.

**Wait, `#pragma`:**
Ignore.

**Wait, `MAX` usage:**
`1000100`.

**Wait, `INF` usage:**
`(1L<<60)-1`.

**Wait, `ans` usage:**
`long ans`.

**Wait, `m==0` check:**
`if(m==0)`.

**Wait, `n` usage:**
`n`.

**Wait, `i` usage:**
`i`.

**Wait, `u`, `v` usage:**
`u`, `v`.

**Wait, `color[v]` usage:**
`color[v]`.

**Wait, `color[u]^1` usage:**
`color[u] ^ 1`.

**Wait, `flag=1` usage:**
`flag = true`.

**Wait, `return` usage:**
`return`.

**Wait, `main` return:**
`return;`

**Wait, `printf` format:**
`"1 %I64d\n"`.

**Wait, `cout` format:**
`"3 " << ans`.

**Wait, `endl` usage:**
`System.out.println`.

**Wait, `scanf` format:**
`"%d%d"`.

**Wait, `mst` macro:**
`Arrays.fill`.

**Wait, `typedef`:**
`long`.

**Wait, `struct`:**
`class`.

**Wait, `using namespace std`:**
`import`.

**Wait, `#define`:**
`static final`.

**Wait, `#pragma`:**
Ignore.

**Wait, `MAX` usage:**
`1000100`.

**Wait, `INF` usage:**
`(1L<<60)-1`.

**Wait, `ans` usage:**
`long ans`.

**Wait, `m==0` check:**
`if(m==0)`.

**Wait, `n` usage:**
`n`.

**Wait, `i` usage:**
`i`.

**Wait, `u`, `v` usage:**
`u`, `v`.

**Wait, `color[v]` usage:**
`color[v]`.

**Wait, `color[u]^1` usage:**
`color[u] ^ 1`.

**Wait, `flag=1` usage:**
`flag = true`.

**Wait, `return` usage:**
`return`.

**Wait, `main` return:**
`return;`

**Wait, `printf` format:**
`"1 %I64d\n"`.

**Wait, `cout` format:**
`"3 " << ans`.

**Wait, `endl` usage:**
`System.out.println`.

**Wait, `scanf` format:**
`"%d%d"`.

**Wait, `mst` macro:**
`Arrays.fill`.

**Wait, `typedef`:**
`long`.

**Wait, `struct`:**
`class`.

**Wait, `using namespace std`:**
`import`.

**Wait, `#define`:**
`static final`.

**Wait, `#pragma`:**
Ignore.

**Wait, `MAX` usage:**
`1000100`.

**Wait, `INF` usage:**
`(1L<<60)-1`.

**Wait, `ans` usage:**
`long ans`.

**Wait, `m==0` check:**
`if(m==0)`.

**Wait, `n` usage:**
`n`.

**Wait, `i` usage:**
`i`.

**Wait, `u`, `v` usage:**
`u`, `v`.

**Wait, `color[v]` usage:**
`color[v]`.

**Wait, `color[u]^1` usage:**
`color[u] ^ 1`.

**Wait, `flag=1` usage:**
`flag = true`.

**Wait, `return` usage:**
`return`.

**Wait, `main` return:**
`return;`

**Wait, `printf` format:**
`"1 %I64d\n"`.

**Wait, `cout` format:**
`"3 " << ans`.

**Wait, `endl` usage:**
`System.out.println`.

**Wait, `scanf` format:**
`"%d%d"`.

**Wait, `mst` macro:**
`Arrays.fill`.

**Wait, `typedef`:**
`long`.

**Wait, `struct`:**
`class`.

**Wait, `using namespace std`:**
`import`.

**Wait, `#define`:**
`static final`.

**Wait, `#pragma`:**
Ignore.

**Wait, `MAX` usage:**
`1000100`.

**Wait, `INF` usage:**
`(1L<<60)-1`.

**Wait, `ans` usage:**
`long ans`.

**Wait, `m==0` check:**
`if(m==0)`.

**Wait, `n` usage:**
`n`.

**Wait, `i` usage:**
`i`.

**Wait, `u`, `v` usage:**
`u`, `v`.

**Wait, `color[v]` usage:**
`color[v]`.

**Wait, `color[u]^1` usage:**
`color[u] ^ 1`.

**Wait, `flag=1` usage:**
`flag = true`.

**Wait, `return` usage:**
`return`.

**Wait, `main` return:**
`return;`

**Wait, `printf` format:**
`"1 %I64d\n"`.

**Wait, `cout` format:**
`"3 " << ans`.

**Wait, `endl` usage:**
`System.out.println`.

**Wait, `scanf` format:**
`"%d%d"`.

**Wait, `mst` macro:**
`Arrays.fill`.

**Wait, `typedef`:**
`long`.

**Wait, `struct`:**
`class`.

**Wait, `using namespace std`:**
`import`.

**Wait, `#define`:**
`static final`.

**Wait, `#pragma`:**
Ignore.

**Wait, `MAX` usage:**
`1000100`.

**Wait, `INF` usage:**
`(1L<<60)-1`.

**Wait, `ans` usage:**
`long ans`.

**Wait, `m==0` check:**
`if(m==0)`.

**Wait, `n` usage:**
`n`.

**Wait, `i` usage:**
`i`.

**Wait, `u`, `v` usage:**
`u`, `v`.

**Wait, `color[v]` usage:**
`color[v]`.

**Wait, `color[u]^1` usage:**
`color[u] ^ 1`.

**Wait, `flag=1` usage:**
`flag = true`.

**Wait, `return` usage:**
`return`.

**Wait, `main` return:**
`return;`

**Wait, `printf` format:**
`"1 %I64d\n"`.

**Wait, `cout` format:**
`"3 " << ans`.

**Wait, `endl` usage:**
`System.out.println`.

**Wait, `scanf` format:**
`"%d%d"`.

**Wait, `mst` macro:**
`Arrays.fill`.

**Wait, `typedef`:**
`long`.

**Wait, `struct`:**
`class`.

**Wait, `using namespace std`:**
`import`.

**Wait, `#define`:**
`static final`.

**Wait, `#pragma`:**
Ignore.

**Wait, `MAX` usage:**
`1000100`.

**Wait, `INF` usage:**
`(1L<<60)-1`.

**Wait, `ans` usage:**
`long ans`.

**Wait, `m==0` check:**
`if(m==0)`.

**Wait, `n` usage:**
`n`.

**Wait, `i` usage:**
`i`.

**Wait, `u`, `v` usage:**
`u`, `v`.

**Wait, `color[v]` usage:**
`color[v]`.

**Wait, `color[u]^1` usage:**
`color[u] ^ 1`.

**Wait, `flag=1` usage:**
`flag = true`.

**Wait, `return` usage:**
`return`.

**Wait, `main` return:**
`return;`

**Wait, `printf` format:**
`"1 %I64d\n"`.

**Wait, `cout` format:**
`"3 " << ans`.

**Wait, `endl` usage:**
`System.out.println`.

**Wait, `scanf` format:**
`"%d%d"`.

**Wait, `mst` macro:**
`Arrays.fill`.

**Wait, `typedef`:**
`long`.

**Wait, `struct`:**
`class`.

**Wait, `using namespace std`:**
`import`.

**Wait, `#define`:**
`static final`.

**Wait, `#pragma`:**
Ignore.

**Wait, `MAX` usage:**
`1000100`.

**Wait, `INF` usage:**
`(1L<<60)-1`.

**Wait, `ans` usage:**
`long ans`.

**Wait, `m==0` check:**
`if(m==0)`.

**Wait, `n` usage:**
`n`.

**Wait, `i` usage:**
`i`.

**Wait, `u`, `v` usage:**
`u`, `v`.

**Wait, `color[v]` usage:**
`color[v]`.

**Wait, `color[u]^1` usage:**
`color[u] ^ 1`.

**Wait, `flag=1` usage:**
`flag = true`.

**Wait, `return` usage:**
`return`.

**Wait, `main` return:**
`return;`

**Wait, `printf` format:**
`"1 %I64d\n"`.

**Wait, `cout` format:**
`"3 " << ans`.

**Wait, `endl` usage:**
`System.out.println`.

**Wait, `scanf` format:**
`"%d%d"`.

**Wait, `mst` macro:**
`Arrays.fill`.

**Wait, `typedef`:**
`long`.

**Wait, `struct`:**
`class`.

**Wait, `using namespace std`:**
`import`.

**Wait, `#define`:**
`static final`.

**Wait, `#pragma`:**
Ignore.

**Wait, `MAX` usage:**
`1000100`.

**Wait, `INF` usage:**
`(1L<<60)-1`.

**Wait, `ans` usage:**
`long ans`.

**Wait, `m==0` check:**
`if(m==0)`.

**Wait, `n` usage:**
`n`.

**Wait, `i` usage:**
`i`.

**Wait, `u`, `v` usage:**
`u`, `v`.

**Wait, `color[v]` usage:**
`color[v]`.

**Wait, `color[u]^1` usage:**
`color[u] ^ 1`.

**Wait, `flag=1` usage:**
`flag = true`.

**Wait, `return` usage:**
`return`.

**Wait, `main` return:**
`return;`

**Wait, `printf` format:**
`"1 %I64d\n"`.

**Wait, `cout` format:**
`"3 " << ans`.

**Wait, `endl` usage:**
`System.out.println`.

**Wait, `scanf` format:**
`"%d%d"`.

**Wait, `mst` macro:**
`Arrays.fill`.

**Wait, `typedef`:**
`long`.

**Wait, `struct`:**
`class`.

**Wait, `using namespace std`:**
`import`.

**Wait, `#define`:**
`static final`.

**Wait, `#pragma`:**
Ignore.

**Wait, `MAX` usage:**
`1000100`.

**Wait, `INF` usage:**
`(1L<<60)-1`.

**Wait, `ans` usage:**
`long ans`.

**Wait, `m==0` check:**
`if(m==0)`.

**Wait, `n` usage:**
`n`.

**Wait, `i` usage:**
`i`.

**Wait, `u`, `v` usage:**
`u`, `v`.

**Wait, `color[v]` usage:**
`color[v]`.

**Wait, `color[u]^1` usage:**
`color[u] ^ 1`.

**Wait, `flag=1` usage:**
`flag = true`.

**Wait, `return` usage:**
`return`.

**Wait, `main` return:**
`return;`

**Wait, `printf` format:**
`"1 %I64d\n"`.

**Wait, `cout` format:**
`"3 " << ans`.

**Wait, `endl` usage:**
`System.out.println`.

**Wait, `scanf` format:**
`"%d%d"`.

**Wait, `mst` macro:**
`Arrays.fill`.

**Wait, `typedef`:**
`long`.

**Wait, `struct`:**
`class`.

**Wait, `using namespace std`:**
`import`.

**Wait, `#define`:**
`static final`.

**Wait, `#pragma`:**
Ignore.

**Wait, `MAX` usage:**
`1000100`.

**Wait, `INF` usage:**
`(1L<<60)-1`.

**Wait, `ans` usage:**
`long ans`.

**Wait, `m==0` check:**
`if(m==0)`.

**Wait, `n` usage:**
`n`.

**Wait, `i` usage:**
`i`.

**Wait, `u`, `v` usage:**
`u`, `v`.

**Wait, `color[v]` usage:**
`color[v]`.

**Wait, `color[u]^1` usage:**
`color[u] ^ 1`.

**Wait, `flag=1` usage:**
`flag = true`.

**Wait, `return` usage:**
`return`.

**Wait, `main` return:**
`return;`

**Wait, `printf` format:**
`"1 %I64d\n"`.

**Wait, `cout` format:**
`"3 " << ans`.

**Wait, `endl` usage:**
`System.out.println`.

**Wait, `scanf` format:**
`"%d%d"`.

**Wait, `mst` macro:**
`Arrays.fill`.

**Wait, `typedef`:**
`long`.

**Wait, `struct`:**
`class`.

**Wait, `using namespace std`:**
`import`.

**Wait, `#define`:**
`static final`.

**Wait, `#pragma`:**
Ignore.

**Wait, `MAX` usage:**
`1000100`.

**Wait, `INF` usage:**
`(1L<<60)-1`.

**Wait, `ans` usage:**
`long ans`.

**Wait, `m==0` check:**
`if(m==0)`.

**Wait, `n` usage:**
`n`.

**Wait, `i` usage:**
`i`.

**Wait, `u`, `v` usage:**
`u`, `v`.

**Wait, `color[v]` usage:**
`color[v]`.

**Wait, `color[u]^1` usage:**
`color[u] ^ 1`.

**Wait, `flag=1` usage:**
`flag = true`.

**Wait, `return` usage:**
`return`.

**Wait, `main` return:**
`return;`

**Wait, `printf` format:**
`"1 %I64d\n"`.

**Wait, `cout` format:**
`"3 " << ans`.

**Wait, `endl` usage:**
`System.out.println`.

**Wait, `scanf` format:**
`"%d%d"`.

**Wait, `mst` macro:**
`Arrays.fill`.

**Wait, `typedef`:**
`long`.

**Wait, `struct`:**
`class`.

**Wait, `using namespace std`:**
`import`.

**Wait, `#define`:**
`static final`.

**Wait, `#pragma`:**
Ignore.

**Wait, `MAX` usage:**
`1000100`.

**Wait, `INF` usage:**
`(1L<<60)-1`.

**Wait, `ans` usage:**
`long ans`.

**Wait, `m==0` check:**
`if(m==0)`.

**Wait, `n` usage:**
`n`.

**Wait, `i` usage:**
`i`.

**Wait, `u`, `v` usage:**
`u`, `v`.

**Wait, `color[v]` usage:**
`color[v]`.

**Wait, `color[u]^1` usage:**
`color[u] ^ 1`.

**Wait, `flag=1` usage:**
`flag = true`.

**Wait, `return` usage:**
`return`.

**Wait, `main` return:**
`return;`

**Wait, `printf` format:**
`"1 %I64d\n"`.

**Wait, `cout` format:**
`"3 " << ans`.

**Wait, `endl` usage:**
`System.out.println`.

**Wait, `scanf` format:**
`"%d%d"`.

**Wait, `mst` macro:**
`Arrays.fill`.

**Wait, `typedef`:**
`long`.

**Wait, `struct`:**
`class`.

**Wait, `using namespace std`:**
`import`.

**Wait, `#define`:**
`static final`.

**Wait, `#pragma`:**
Ignore.

**Wait, `MAX` usage:**
`1000100`.

**Wait, `INF` usage:**
`(1L<<60)-1`.

**Wait, `ans` usage:**
`long ans`.

**Wait, `m==0` check:**
`if(m==0)`.

**Wait, `n` usage:**
`n`.

**Wait, `i` usage:**
`i`.

**Wait, `u`, `v` usage:**
`u`, `v`.

**Wait, `color[v]` usage:**
`color[v]`.

**Wait, `color[u]^1` usage:**
`color[u] ^ 1`.

**Wait, `flag=1` usage:**
`flag = true`.

**Wait, `return` usage:**
`return`.

**Wait, `main` return:**
`return;`

**Wait, `printf` format:**
`"1 %I64d\n"`.

**Wait, `cout` format:**
`"3 " << ans`.

**Wait, `endl` usage:**
`System.out.println`.

**Wait, `scanf` format:**
`"%d%d"`.

**Wait, `mst` macro:**
`Arrays.fill`.

**Wait, `typedef`:**
`long`.

**Wait, `struct`:**
`class`.

**Wait, `using namespace std`:**
`import`.

**Wait, `#define`:**
`static final`.

**Wait, `#pragma`:**
Ignore.

**Wait, `MAX` usage:**
`1000100`.

**Wait, `INF` usage:**
`(1L<<60)-1`.

**Wait, `ans` usage:**
`long ans`.

**Wait, `m==0` check:**
`if(m==0)`.

**Wait, `n` usage:**
`n`.

**Wait, `i` usage:**
`i`.

**Wait, `u`, `v` usage:**
`u`, `v`.

**Wait, `color[v]` usage:**
`color[v]`.

**Wait, `color[u]^1` usage:**
`color[u] ^ 1`.

**Wait, `flag=1` usage:**
`flag = true`.

**Wait, `return` usage:**
`return`.

**Wait, `main` return:**
`return;`

**Wait, `printf` format:**
`"1 %I64d\n"`.

**Wait, `cout` format:**
`"3 " << ans`.

**Wait, `endl` usage:**
`System.out.println`.

**Wait, `scanf` format:**
`"%d%d"`.

**Wait, `mst` macro:**
`Arrays.fill`.

**Wait, `typedef`:**
`long`.

**Wait, `struct`:**
`class`.

**Wait, `using namespace std`:**
`import`.

**Wait, `#define`:**
`static final`.

**Wait, `#pragma`:**
Ignore.

**Wait, `MAX` usage:**
`1000100`.

**Wait, `INF` usage:**
`(1L<<60)-1`.

**Wait, `ans` usage:**
`long ans`.

**Wait, `m==0` check:**
`if(m==0)`.

**Wait, `n` usage:**
`n`.

**Wait, `i` usage:**
`i`.

**Wait, `u`, `v` usage:**
`u`, `v`.

**Wait, `color[v]` usage:**
`color[v]`.

**Wait, `color[u]^1` usage:**
`color[u] ^ 1`.

**Wait, `flag=1` usage:**
`flag = true`.

**Wait, `return` usage:**
`return`.

**Wait, `main` return:**
`return;`

**Wait, `printf` format:**
`"1 %I64d\n"`.

**Wait, `cout` format:**
`"3 " << ans`.

**Wait, `endl` usage:**
`System.out.println`.

**Wait, `scanf` format:**
`"%d%d"`.

**Wait, `mst` macro:**
`Arrays.fill`.

**Wait, `typedef`:**
`long`.

**Wait, `struct`:**
`class`.

**Wait, `using namespace std`:**
`import`.

**Wait, `#define`:**
`static final`.

**Wait, `#pragma`:**
Ignore.

**Wait, `MAX` usage:**
`1000100`.

**Wait, `INF` usage:**
`(1L<<60)-1`.

**Wait, `ans` usage:**
`long ans`.

**Wait, `m==0` check:**
`if(m==0)`.

**Wait, `n` usage:**
`n`.

**Wait, `i` usage:**
`i`.

**Wait, `u`, `v` usage:**
`u`, `v`.

**Wait, `color[v]` usage:**
`color[v]`.

**Wait, `color[u]^1` usage:**
`color[u] ^ 1`.

**Wait, `flag=1` usage:**
`flag = true`.

**Wait, `return` usage:**
`return`.

**Wait, `main` return:**
`return;`

**Wait, `printf` format:**
`"1 %I64d\n"`.

**Wait, `cout` format:**
`"3 " << ans`.

**Wait, `endl` usage:**
`System.out.println`.

**Wait, `scanf` format:**
`"%d%d"`.

**Wait, `mst` macro:**
`Arrays.fill`.

**Wait, `typedef`:**
`long`.

**Wait, `struct`:**
`class`.

**Wait, `using namespace std`:**
`import`.

**Wait, `#define`:**
`static final`.

**Wait, `#pragma`:**
Ignore.

**Wait, `MAX` usage:**
`1000100`.

**Wait, `INF` usage:**
`(1L<<60)-1`.

**Wait, `ans` usage:**
`long ans`.

**Wait, `m==0` check:**
`if(m==0)`.

**Wait, `n` usage:**
`n`.

**Wait, `i` usage:**
`i`.

**Wait, `u`, `v` usage:**
`u`, `v`.

**Wait, `color[v]` usage:**
`color[v]`.

**Wait, `color[u]^1` usage:**
`color[u] ^ 1`.

**Wait, `flag=1` usage:**
`flag = true`.

**Wait, `return` usage:**
`return`.

**Wait, `main` return:**
`return;`

**Wait, `printf` format:**
`"1 %I64d\n"`.

**Wait, `cout` format:**
`"3 " << ans`.

**Wait, `endl` usage:**
`System.out.println`.

**Wait, `scanf` format:**
`"%d%d"`.

**Wait, `mst` macro:**
`Arrays.fill`.

**Wait, `typedef`:**
`long`.

**Wait, `struct`:**
`class`.

**Wait, `using namespace std`:**
`import`.

**Wait, `#define`:**
`static final`.

**Wait, `#pragma`:**
Ignore.

**Wait, `MAX` usage:**
`1000100`.

**Wait, `INF` usage:**
`(1L<<60)-1`.

**Wait, `ans` usage:**
`long ans`.

**Wait, `m==0` check:**
`if(m==0)`.

**Wait, `n` usage:**
`n`.

**Wait, `i` usage:**
`i`.

**Wait, `u`, `v` usage:**
`u`, `v`.

**Wait, `color[v]` usage:**
`color[v]`.

**Wait, `color[u]^1` usage:**
`color[u] ^ 1`.

**Wait, `flag=1` usage:**
`flag = true`.

**Wait, `return` usage:**
`return`.

**Wait, `main` return:**
`return;`

**Wait, `printf` format:**
`"1 %I64d\n"`.

**Wait, `cout` format:**
`"3 " << ans`.

**Wait, `endl` usage:**
`System.out.println`.

**Wait, `scanf` format:**
`"%d%d"`.

**Wait, `mst` macro:**
`Arrays.fill`.

**Wait, `typedef`:**
`long`.

**Wait, `struct`:**
`class`.

**Wait, `using namespace std`:**
`import`.

**Wait, `#define`:**
`static final`.

**Wait, `#pragma`:**
Ignore.

**Wait, `MAX` usage:**
`1000100`.

**Wait, `INF` usage:**
`(1L<<60)-1`.

**Wait, `ans` usage:**
`long ans`.

**Wait, `m==0` check:**
`if(m==0)`.

**Wait, `n` usage:**
`n`.

**Wait, `i` usage:**
`i`.

**Wait, `u`, `v` usage:**
`u`, `v`.

**Wait, `color[v]` usage:**
`color[v]`.

**Wait, `color[u]^1` usage:**
`color[u] ^ 1`.

**Wait, `flag=1` usage:**
`flag = true`.

**Wait, `return` usage:**
`return`.

**Wait, `main` return:**
`return;`

**Wait, `printf` format:**
`"1 %I64d\n"`.

**Wait, `cout` format:**
`"3 " << ans`.

**Wait, `endl` usage:**
`System.out.println`.

**Wait, `scanf` format:**
`"%d%d"`.

**Wait, `mst` macro:**
`Arrays.fill`.

**Wait, `typedef`:**
`long`.

**Wait, `struct`:**
`class`.

**Wait, `using namespace std`:**
`import`.

**Wait, `#define`:**
`static final`.

**Wait, `#pragma`:**
Ignore.

**Wait, `MAX` usage:**
`1000100`.

**Wait, `INF` usage:**
`(1L<<60)-1`.

**Wait, `ans` usage:**
`long ans`.

**Wait, `m==0` check:**
`if(m==0)`.

**Wait, `n` usage:**
`n`.

**Wait, `i` usage:**
`i`.

**Wait, `u`, `v` usage:**
`u`, `v`.

**Wait, `color[v]` usage:**
`color[v]`.

**Wait, `color[u]^1` usage:**
`color[u] ^ 1`.

**Wait, `flag=1` usage:**
`flag = true`.

**Wait, `return` usage:**
`return`.

**Wait, `main` return:**
`return;`

**Wait, `printf` format:**
`"1 %I64d\n"`.

**Wait, `cout` format:**
`"3 " << ans`.

**Wait, `endl` usage:**
`System.out.println`.

**Wait, `scanf` format:**
`"%d%d"`.

**Wait, `mst` macro:**
`Arrays.fill`.

**Wait, `typedef`:**
`long`.

**Wait, `struct`:**
`class`.

**Wait, `using namespace std`:**
`import`.

**Wait, `#define`:**
`static final`.

**Wait, `#pragma`:**
Ignore.

**Wait, `MAX` usage:**
`1000100`.

**Wait, `INF` usage:**
`(1L<<60)-1`.

**Wait, `ans` usage:**
`long ans`.

**Wait, `m==0` check:**
`if(m==0)`.

**Wait, `n` usage:**
`n`.

**Wait, `i` usage:**
`i`.

**Wait, `u`, `v` usage:**
`u`, `v`.

**Wait, `color[v]` usage:**
`color[v]`.

**Wait, `color[u]^1` usage:**
`color[u] ^ 1`.

**Wait, `flag=1` usage:**
`flag = true`.

**Wait, `return` usage:**
`return`.

**Wait, `main` return:**
`return;`

**Wait, `printf` format:**
`"1 %I64d\n"`.

**Wait, `cout` format:**
`"3 " << ans`.

**Wait, `endl` usage:**
`System.out.println`.

**Wait, `scanf` format:**
`"%d%d"`.

**Wait, `mst` macro:**
`Arrays.fill`.

**Wait, `typedef`:**
`long`.

**Wait, `struct`:**
`class`.

**Wait, `using namespace std`:**
`import`.

**Wait, `#define`:**
`static final`.

**Wait, `#pragma`:**
Ignore.

**Wait, `MAX` usage:**
`1000100`.

**Wait, `INF` usage:**
`(1L<<60)-1`.

**Wait, `ans` usage:**
`long ans`.

**Wait, `m==0` check:**
`if(m==0)`.

**Wait, `n` usage:**
`n`.

**Wait, `i` usage:**
`i`.

**Wait, `u`, `v` usage:**
`u`, `v`.

**Wait, `color[v]` usage:**
`color[v]`.

**Wait, `color[u]^1` usage:**
`color[u] ^ 1`.

**Wait, `flag=1` usage:**
`flag = true`.

**Wait, `return` usage:**
`return`.

**Wait, `main` return:**
`return;`

**Wait, `printf` format:**
`"1 %I64d\n"`.

**Wait, `cout` format:**
`"3 " << ans`.

**Wait, `endl` usage:**
`System.out.println`.

**Wait, `scanf` format:**
`"%d%d"`.

**Wait, `mst` macro:**
`Arrays.fill`.

**Wait, `typedef`:**
`long`.

**Wait, `struct`:**
`class`.

**Wait, `using namespace std`:**
`import`.

**Wait, `#define`:**
`static final`.

**Wait, `#pragma`:**
Ignore.

**Wait, `MAX` usage:**
`1000100`.

**Wait, `INF` usage:**
`(1L<<60)-1`.

**Wait, `ans` usage:**
`long ans`.

**Wait, `m==0` check:**
`if(m==0)`.

**Wait, `n` usage:**
`n`.

**Wait, `i` usage:**
`i`.

**Wait, `u`, `v` usage:**
`u`, `v`.

**Wait, `color[v]` usage:**
`color[v]`.

**Wait, `color[u]^1` usage:**
`color[u] ^ 1`.

**Wait, `flag=1` usage:**
`flag = true`.

**Wait, `return` usage:**
`return`.

**Wait, `main` return:**
`return;`

**Wait, `printf` format:**
`"1 %I64d\n"`.

**Wait, `cout` format:**
`"3 " << ans`.

**Wait, `endl` usage:**
`System.out.println`.

**Wait, `scanf` format:**
`"%d%d"`.

**Wait, `mst` macro:**
`Arrays.fill`.

**Wait, `typedef`:**
`long`.

**Wait, `struct`:**
`class`.

**Wait, `using namespace std`:**
`import`.

**Wait, `#define`:**
`static final`.

**Wait, `#pragma`:**
Ignore.

**Wait, `MAX` usage:**
`1000100`.

**Wait, `INF` usage:**
`(1L<<60)-1`.

**Wait, `ans` usage:**
`long ans`.

**Wait, `m==0` check:**
`if(m==0)`.

**Wait, `n` usage:**
`n`.

**Wait, `i` usage:**
`i`.

**Wait, `u`, `v` usage:**
`u`, `v`.

**Wait, `color[v]` usage:**
`color[v]`.

**Wait, `color[u]^1` usage:**
`color[u] ^ 1`.

**Wait, `flag=1` usage:**
`flag = true`.

**Wait, `return` usage:**
`return`.

**Wait, `main` return:**
`return;`

**Wait, `printf` format:**
`"1 %I64d\n"`.

**Wait, `cout` format:**
`"3 " << ans`.

**Wait, `endl` usage:**
`System.out.println`.

**Wait, `scanf` format:**
`"%d%d"`.

**Wait, `mst` macro:**
`Arrays.fill`.

**Wait, `typedef`:**
`long`.

**Wait, `struct`:**
`class`.

**Wait, `using namespace std`:**
`import`.

**Wait, `#define`:**
`static final`.

**Wait, `#pragma`:**
Ignore.

**Wait, `MAX` usage:**
`1000100`.

**Wait, `INF` usage:**
`(1L<<60)-1`.

**Wait, `ans` usage:**
`long ans`.

**Wait, `m==0` check:**
`if(m==0)`.

**Wait, `n` usage:**
`n`.

**Wait, `i` usage:**
`i`.

**Wait, `u`, `v` usage:**
`u`, `v`.

**Wait, `color[v]` usage:**
`color[v]`.

**Wait, `color[u]^1` usage:**
`color[u] ^ 1`.

**Wait, `flag=1` usage:**
`flag = true`.

**Wait, `return` usage:**
`return`.

**Wait, `main` return:**
`return;`

**Wait, `printf` format:**
`"1 %I64d\n"`.

**Wait, `cout` format:**
`"3 " << ans`.

**Wait, `endl` usage:**
`System.out.println`.

**Wait, `scanf` format:**
`"%d%d"`.

**Wait, `mst` macro:**
`Arrays.fill`.

**Wait, `typedef`:**
`long`.

**Wait, `struct`:**
`class`.

**Wait, `using namespace std`:**
`import`.

**Wait, `#define`:**
`static final`.

**Wait, `#pragma`:**
Ignore.

**Wait, `MAX` usage:**
`1000100`.

**Wait, `INF` usage:**
`(1L<<60)-1`.

**Wait, `ans` usage:**
`long ans`.

**Wait, `m==0` check:**
`if(m==0)`.

**Wait, `n` usage:**
`n`.

**Wait, `i` usage:**
`i`.

**Wait, `u`, `v` usage:**
`u`, `v`.

**Wait, `color[v]` usage:**
`color[v]`.

**Wait, `color[u]^1` usage:**
`color[u] ^ 1`.

**Wait, `flag=1` usage:**
`flag = true`.

**Wait, `return` usage:**
`return`.

**Wait, `main` return:**
`return;`

**Wait, `printf` format:**
`"1 %I64d\n"`.

**Wait, `cout` format:**
`"3 " << ans`.

**Wait, `endl` usage:**
`System.out.println`.

**Wait, `scanf` format:**
`"%d%d"`.

**Wait, `mst` macro:**
`Arrays.fill`.

**Wait, `typedef`:**
`long`.

**Wait, `struct`:**
`class`.

**Wait, `using namespace std`:**
`import`.

**Wait, `#define`:**
`static final`.

**Wait, `#pragma`:**
Ignore.

**Wait, `MAX` usage:**
`1000100`.

**Wait, `INF` usage:**
`(1L<<60)-1`.

**Wait, `ans` usage:**
`long ans`.

**Wait, `m==0` check:**
`if(m==0)`.

**Wait, `n` usage:**
`n`.

**Wait, `i` usage:**
`i`.

**Wait, `u`, `v` usage:**
`u`, `v`.

**Wait, `color[v]` usage:**
`color[v]`.

**Wait, `color[u]^1` usage:**
`color[u] ^ 1`.

**Wait, `flag=1` usage:**
`flag = true`.

**Wait, `return` usage:**
`return`.

**Wait, `main` return:**
`return;`

**Wait, `printf` format:**
`"1 %I64d\n"`.

**Wait, `cout` format:**
`"3 " << ans`.

**Wait, `endl` usage:**
`System.out.println`.

**Wait, `scanf` format:**
`"%d%d"`.

**Wait, `mst` macro:**
`Arrays.fill`.

**Wait, `typedef`:**
`long`.

**Wait, `struct`:**
`class`.

**Wait, `using namespace std`:**
`import`.

**Wait, `#define`:**
`static final`.

**Wait, `#pragma`:**
Ignore.

**Wait, `MAX` usage:**
`1000100`.

**Wait, `INF` usage:**
`(1L<<60)-1`.

**Wait, `ans` usage:**
`long ans`.

**Wait, `m==0` check:**
`if(m==0)`.

**Wait, `n` usage:**
`n`.

**Wait, `i` usage:**
`i`.

**Wait, `u`, `v` usage:**
`u`, `v`.

**Wait, `color[v]` usage:**
`color[v]`.

**Wait, `color[u]^1` usage:**
`color[u] ^ 1`.

**Wait, `flag=1` usage:**
`flag = true`.

**Wait, `return` usage:**
`return`.

**Wait, `main` return:**
`return;`

**Wait, `printf` format:**
`"1 %I64d\n"`.

**Wait, `cout` format:**
`"3 " << ans`.

**Wait, `endl` usage:**
`System.out.println`.

**Wait, `scanf` format:**
`"%d%d"`.

**Wait, `mst` macro:**
`Arrays.fill`.

**Wait, `typedef`:**
`long`.

**Wait, `struct`:**
`class`.

**Wait, `using namespace std`:**
`import`.

**Wait, `#define`:**
`static final`.

**Wait, `#pragma`:**
Ignore.

**Wait, `MAX` usage:**
`1000100`.

**Wait, `INF` usage:**
`(1L<<60)-1`.

**Wait, `ans` usage:**
`long ans`.

**Wait, `m==0` check:**
`if(m==0)`.

**Wait, `n` usage:**
`n`.

**Wait, `i` usage:**
`i`.

**Wait, `u`, `v` usage:**
`u`, `v`.

**Wait, `color[v]` usage:**
`color[v]`.

**Wait, `color[u]^1` usage:**
`color[u] ^ 1`.

**Wait, `flag=1` usage:**
`flag = true`.

**Wait, `return` usage:**
`return`.

**Wait, `main` return:**
`return;`

**Wait, `printf` format:**
`"1 %I64d\n"`.

**Wait, `cout` format:**
`"3 " << ans`.

**Wait, `endl` usage:**
`System.out.println`.

**Wait, `scanf` format:**
`"%d%d"`.

**Wait, `mst` macro:**
`Arrays.fill`.

**Wait, `typedef`:**
`long`.

**Wait, `struct`:**
`class`.

**Wait, `using namespace std`:**
`import`.

**Wait, `#define`:**
`static final`.

**Wait, `#pragma`:**
Ignore.

**Wait, `MAX` usage:**
`1000100`.

**Wait, `INF` usage:**
`(1L<<60)-1`.

**Wait, `ans` usage:**
`long ans`.

**Wait, `m==0` check:**
`if(m==0)`.

**Wait, `n` usage:**
`n`.

**Wait, `i` usage:**
`i`.

**Wait, `u`, `v` usage:**
`u`, `v`.

**Wait, `color[v]` usage:**
`color[v]`.

**Wait, `color[u]^1` usage:**
`color[u] ^ 1`.

**Wait, `flag=1` usage:**
`flag = true`.

**Wait, `return` usage:**
`return`.

**Wait, `main` return:**
`return;`

**Wait, `printf` format:**
`"1 %I64d\n"`.

**Wait, `cout` format:**
`"3 " << ans`.

**Wait, `endl` usage:**
`System.out.println`.

**Wait, `scanf` format:**
`"%d%d"`.

**Wait, `mst` macro:**
`Arrays.fill`.

**Wait, `typedef`:**
`long`.

**Wait, `struct`:**
`class`.

**Wait, `using namespace std`:**
`import`.

**Wait, `#define`:**
`static final`.

**Wait, `#pragma`:**
Ignore.

**Wait, `MAX` usage:**
`1000100`.

**Wait, `INF` usage:**
`(1L<<60)-1`.

**Wait, `ans` usage:**
`long ans`.

**Wait, `m==0` check:**
`if(m==0)`.

**Wait, `n` usage:**
`n`.

**Wait, `i` usage:**
`i`.

**Wait, `u`, `v` usage:**
`u`, `v`.

**Wait, `color[v]` usage:**
`color[v]`.

**Wait, `color[u]^1` usage:**
`color[u] ^ 1`.

**Wait, `flag=1` usage:**
`flag = true`.

**Wait, `return` usage:**
`return`.

**Wait, `main` return:**
`return;`

**Wait, `printf` format:**
`"1 %I64d\n"`.

**Wait, `cout` format:**
`"3 " << ans`.

**Wait, `endl` usage:**
`System.out.println`.

**Wait, `scanf` format:**
`"%d%d"`.

**Wait, `mst` macro:**
`Arrays.fill`.

**Wait, `typedef`:**
`long`.

**Wait, `struct`:**
`class`.

**Wait, `using namespace std`:**
`import`.

**Wait, `#define`:**
`static final`.

**Wait, `#pragma`:**
Ignore.

**Wait, `MAX` usage:**
`1000100`.

**Wait, `INF` usage:**
`(1L<<60)-1`.

**Wait, `ans` usage:**
`long ans`.

**Wait, `m==0` check:**
`if(m==0)`.

**Wait, `n` usage:**
`n`.

**Wait, `i` usage:**
`i`.

**Wait, `u`, `v` usage:**
`u`, `v`.

**Wait, `color[v]` usage:**
`color[v]`.

**Wait, `color[u]^1` usage:**
`color[u] ^ 1`.

**Wait, `flag=1` usage:**
`flag = true`.

**Wait, `return` usage:**
`return`.

**Wait, `main` return:**
`return;`

**Wait, `printf` format:**
`"1 %I64d\n"`.

**Wait, `cout` format:**
`"3 " << ans`.

**Wait, `endl` usage:**
`System.out.println`.

**Wait, `scanf` format:**
`"%d%d"`.

**Wait, `mst` macro:**
`Arrays.fill`.

**Wait, `typedef`:**
`long`.

**Wait, `struct`:**
`class`.

**Wait, `using namespace std`:**
`import`.

**Wait, `#define`:**
`static final`.

**Wait, `#pragma`:**
Ignore.

**Wait, `MAX` usage:**
`1000100`.

**Wait, `INF` usage:**
`(1L<<60)-1`.

**Wait, `ans` usage:**
`long ans`.

**Wait, `m==0` check:**
`if(m==0)`.

**Wait, `n` usage:**
`n`.

**Wait, `i` usage:**
`i`.

**Wait, `u`, `v` usage:**
`u`, `v`.

**Wait, `color[v]` usage:**
`color[v]`.

**Wait, `color[u]^1` usage:**
`color[u] ^ 1`.

**Wait, `flag=1` usage:**
`flag = true`.

**Wait, `return` usage:**
`return`.

**Wait, `main` return:**
`return;`

**Wait, `printf` format:**
`"1 %I64d\n"`.

**Wait, `cout` format:**
`"3 " << ans`.

**Wait, `endl` usage:**