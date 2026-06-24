Translate this C++ code to Java code. The main class name should be g3_1970. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int T,cc,u[500010],v[500010];
int n,m,nxt[4100005],head[2000005],k=1,cnt,go[4100005],dfn[2000005],low[2000005],ans;
vector<int> dcc[500005];int bl[200010],is[200010];
void add(int x,int y)
{
	nxt[++k]=head[x];
	head[x]=k;
	go[k]=y;
}
int up,tot;
stack<int>sta;
vector<int>e[N];
void tarjan(int x,int edge)
{
	dfn[x]=low[x]=++cnt;
	if(x<=n)up++;
	sta.push(x);
	for(int i=head[x];i;i=nxt[i])
	{
		int g=go[i];
		if(!dfn[g])
		{
			tarjan(g,i);
			low[x]=min(low[x],low[g]);
			if(low[g]>dfn[x])
			{
				ans++;
				is[ans]=tot;
				int p;
				do{
					p=sta.top();
					sta.pop();
					dcc[ans].push_back(p);
					bl[p]=ans;
				}while(p!=g);
			}
		}
		else if(i!=(edge^1))
		low[x]=min(low[x],dfn[g]);
	}
}
int gp[200010],js[N*2];
set<int>sz[200010];
void dfs(int x,int fa){
    js[x]=dcc[x].size();
    for(auto v:e[x])if(v!=fa){
        dfs(v,x);
        js[x]+=js[v];
    }
    sz[is[x]].insert(js[x]);
    sz[is[x]].insert(gp[is[x]]-js[x]);
    return;
}
bitset<N/2>ans1,ans2;
int main()
{
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&m,&cc);
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&u[i],&v[i]);
            if(u[i]==v[i]) continue;
            add(u[i],v[i]);
            add(v[i],u[i]);
        }
        for(int i=1;i<=n;i++)
        {
            if(!dfn[i])
            {
                up=0;tot++;
                add(i+n,i);
                tarjan(i+n,0);
                gp[tot]=up;
            }
        }
        for(int i=1;i<=m;i++)
            if(bl[u[i]]!=bl[v[i]]){
                e[bl[u[i]]].push_back(bl[v[i]]);
                e[bl[v[i]]].push_back(bl[u[i]]);
            }
        for(int i=1;i<=ans;i++)
            if(!js[i])dfs(i,0);
        ans1.reset();
        ans2.reset();
        ans1[0]=1;
        ans2[0]=1;
        for(int i=1;i<=tot;i++){
            ans2|=(ans2<<gp[i]);
            for(auto h:sz[i])
                if(h)ans2|=(ans1<<h);
            ans1|=(ans1<<gp[i]);
        }
        long long ot=1ll*n*n*2;
        for(int i=0;i<=min(n,N/2);i++)
            if(ans1[i]||ans2[i])
                ot=min(ot,1ll*i*i+1ll*(n-i)*(n-i));
        ot=ot+1ll*cc*(tot-1);
        if(tot==1&&sz[1].size()==2)printf("-1\n");
        else   printf("%lld\n",ot);
        for(int i=1;i<=ans;i++)
            dcc[i].clear();
        for(int i=1;i<=2*n;i++)
            head[i]=low[i]=dfn[i]=0;
        for(int i=1;i<=k;i++)
            go[i]=nxt[i]=0;
        while(!sta.empty())sta.pop();
        k=1;cnt=ans=0;
        for(int i=1;i<=tot;i++){
            gp[i]=0;
            sz[i].clear();
        }for(int i=1;i<=n;i++)
            e[i].clear(),js[i]=bl[i]=is[i]=0;
        tot=0;
    }
    return 0;
}

Here is the plan for the translation:

1.  **Includes and Namespaces**: Replace `#include<bits/stdc++.h>` with specific standard library headers (`iostream`, `vector`, `stack`, `set`, `bitset`). Replace `using namespace std;` with explicit namespace usage or remove it if specific headers are used.
2.  **Global Variables**: Move global variables to the class `g3_1970` as static members or instance members. Given the structure of competitive programming solutions, keeping them as static members inside the class (or class members initialized in a constructor/static block) is appropriate. However, since this is a single-file solution, making them static members of the class is the most direct mapping.
3.  **Constants**: `const int N=1e5+7;` becomes a `static final int` in Java.
4.  **I/O**: Replace `scanf` and `printf` with `Scanner` or `BufferedReader`/`PrintWriter` for efficiency. Since `T` can be large, `BufferedReader` is preferred.
5.  **Structures/Arrays**:
    *   C++ arrays (`int u[500010]`) are mapped to Java `int[]` arrays. Note that Java arrays are 0-indexed, but the logic uses 1-based indexing (up to `500010` or `200010`). We will allocate arrays with size `500010 + 1`.
    *   `vector<int>` becomes `ArrayList<Integer>`.
    *   `set<int>` becomes `HashSet<Integer>` (since Java's `TreeSet` is not directly mapped from C++ `std::set` for primitive `int` without boxing, and performance might be an issue, but `HashSet` is the standard Java equivalent for `std::set` in this context unless order matters. Looking at the code, `sz` is used to iterate, order doesn't strictly matter for the logic `if(h)`, so `HashSet` is fine. However, `std::set` is often used for ordered iteration. Let's stick to `HashSet` for simplicity unless order is critical, but wait, `std::set` is used here. In Java, `TreeSet` is the direct equivalent for ordered sets, but `HashSet` is faster. The code iterates `for(auto h:sz[i])`. If `sz` stores counts, order doesn't matter. I will use `HashSet` for performance).
    *   `stack<int>` becomes `Stack<Integer>` or `Deque<Integer>` (using `ArrayDeque` as a stack is faster).
6.  **Bitset**: Java `BitSet` is the direct equivalent of C++ `std::bitset`.
7.  **Method Logic**:
    *   `add`, `tarjan`, `dfs` methods become static void methods in the class.
    *   `main` function becomes the `main` method inside `g3_1970`.
8.  **Incremental Tasks**:
    *   Task 1: Define class structure and global variables (arrays, lists, sets, bitsets).
    *   Task 2: Translate `add` function.
    *   Task 3: Translate `tarjan` function (recursion, stack usage).
    *   Task 4: Translate `dfs` function.
    *   Task 5: Translate `main` method (I/O, loop logic, bitset operations, array clearing).
9.  **Specific C++ features to handle**:
    *   `^` operator: In C++, `i != (edge ^ 1)` checks if the edge index is not the reverse edge. In Java, this is `i != (edge ^ 1)`.
    *   `vector` clearing: `dcc[i].clear()` becomes `dcc[i].clear()`.
    *   Array initialization: C++ globals are 0-initialized. Java arrays are 0-initialized by default, but we must explicitly set them to 0 inside the loop if they are not guaranteed to be clean (or rely on `Arrays.fill`). The code manually sets them to 0.
    *   `long long`: Java `long`.
    *   `1e5+7`: `100007`.

**Incremental Translation Steps**:
1.  **Setup**: Create class `g3_1970`. Define static arrays `u`, `v`, `head`, `nxt`, `go`, `dfn`, `low`, `bl`, `is`, `e`, `sz`, `js`, `sta`, `ans1`, `ans2`. Initialize sizes.
2.  **Add Function**: Translate `add` to use Java `ArrayList` and `ArrayList` indexing.
3.  **Tarjan Function**: Translate logic to use Java recursion and `Stack<Integer>`. Handle `vector` pushing.
4.  **DFS Function**: Translate loop to use Java `ArrayList` iteration.
5.  **Main Function**:
    *   Replace `scanf` with `BufferedReader` and `StringTokenizer`.
    *   Replace `printf` with `PrintWriter` or `System.out.println`.
    *   Handle array clearing logic explicitly (Java doesn't zero out arrays automatically between test cases).
    *   Translate bitset operations (`<<` and `|=`). Java `BitSet` doesn't support left shift directly on the whole bitset in one go like C++, but `ans2 |= (ans2 << gp[i])` logic needs to be implemented by shifting bits. Since `BitSet` doesn't have a shift operator, we have to implement the shift manually or use a `long[]` array to simulate `BitSet` behavior if `N` is small, but `N` is up to `1e5`.
    *   *Correction on Bitset*: Java `BitSet` does not support `<<` operator. To implement `ans2 |= (ans2 << gp[i])`, we need to iterate through the bits of `ans2` and set the corresponding bits in `ans2`. Since `N` is `1e5+7`, we can't shift the whole bitset efficiently bit-by-bit.
    *   *Wait, looking at the code*: `ans1` and `ans2` are `bitset<N/2>`. `N` is `100007`. `N/2` is `50003`. The bitset size is `50003`. Shifting a bitset of size 50000 by `gp[i]` (which can be up to `n` or `N`) requires shifting bits.
    *   *Java Implementation of Bitset Shift*: Since `BitSet` doesn't support `<<`, we must implement a helper method or loop. Given `N` is small enough (`50003`), a loop is acceptable, but it's $O(N)$ per shift. Total complexity $O(T \cdot tot \cdot N)$. This might be too slow if `tot` is large.
    *   However, `gp[i]` is likely small? No, `gp` is the number of edges in the biconnected component.
    *   Actually, usually in these problems, `BitSet` is simulated using `long[]` or simply iterating. Let's look at the constraints. `N=1e5+7`. `tot` is number of biconnected components.
    *   To be safe and correct in Java, I will implement a `shiftAndOr` method for `BitSet` that shifts the bits to the left (increasing index) by `k` positions.
    *   Wait, `BitSet` in Java is mutable. `ans2.get(j)` checks bit `j`. We want to set bit `j + shift`.
    *   Let's refine the plan: I will implement a custom `shiftLeft` method for `BitSet` that takes the bitset and a shift amount.

Let's write the code.

```java
import java.io.*;
import java.util.*;

public class g3_1970 {
    static final int N = 100007;
    static int T;
    static int[] u = new int[500010];
    static int[] v = new int[500010];
    static int[] head = new int[2000005];
    static int[] nxt = new int[4100005];
    static int[] go = new int[4100005];
    static int[] dfn = new int[2000005];
    static int[] low = new int[2000005];
    static int[] bl = new int[200010];
    static int[] is = new int[200010];
    static int[] js = new int[200010]; // N*2 is approx 200000, but array size is 200010. Wait, N is 1e5+7. N*2 is 200014.
    // The C++ code uses js[N*2]. In C++, N is 1e5+7. N*2 is roughly 200014.
    // Java array size needs to be slightly larger. Let's use 200020.
    static int[] gp = new int[200010];
    static int k = 1;
    static int cnt = 0;
    static int ans = 0;
    static int tot = 0;
    static int up = 0;
    static Stack<Integer> sta = new Stack<>();
    static ArrayList<Integer>[] e = new ArrayList[N];
    static ArrayList<Integer>[] dcc = new ArrayList[N];
    static HashSet<Integer>[] sz = new HashSet[N];
    
    // BitSet equivalent
    static BitSet ans1 = new BitSet(N / 2 + 1);
    static BitSet ans2 = new BitSet(N / 2 + 1);

    // Helper to shift BitSet left by k
    // In C++, bitset<N/2> supports shift. In Java, we must implement it.
    // Since N/2 is ~50000, iterating is acceptable if tot is small, but might be slow.
    // Let's assume the constraints allow O(N) per shift or we optimize.
    // Actually, standard Java BitSet doesn't support shift. We will implement a helper.
    private static void shiftLeft(BitSet b, int shift) {
        if (shift == 0) return;
        // We need to shift bits to higher indices.
        // Create a temporary bitset or iterate.
        // Iterating is O(N).
        for (int i = b.length() - 1; i >= 0; i--) {
            if (b.get(i)) {
                if (i + shift < b.length()) {
                    b.set(i + shift, true);
                }
            }
        }
    }

    public static void add(int x, int y) {
        k++;
        nxt[k] = head[x];
        head[x] = k;
        go[k] = y;
    }

    public static void tarjan(int x, int edge) {
        dfn[x] = low[x] = ++cnt;
        if (x <= n) up++;
        sta.push(x);
        for (int i = head[x]; i != 0; i = nxt[i]) {
            int g = go[i];
            if (dfn[g] == 0) {
                tarjan(g, i);
                low[x] = Math.min(low[x], low[g]);
                if (low[g] > dfn[x]) {
                    ans++;
                    is[ans] = tot;
                    int p;
                    do {
                        p = sta.pop();
                        dcc[ans].add(p);
                        bl[p] = ans;
                    } while (p != g);
                }
            } else if (i != (edge ^ 1)) {
                low[x] = Math.min(low[x], dfn[g]);
            }
        }
    }

    public static void dfs(int x, int fa) {
        js[x] = dcc[x].size();
        for (int v : e[x]) {
            if (v != fa) {
                dfs(v, x);
                js[x] += js[v];
            }
        }
        sz[is[x]].add(js[x]);
        sz[is[x]].add(gp[is[x]] - js[x]);
    }

    public static void main(String[] args) throws IOException {
        // Use fast I/O
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer("");

        // Read T
        String line = br.readLine();
        while (line != null && line.trim().isEmpty()) line = br.readLine();
        if (line == null) return;
        st = new StringTokenizer(line);
        T = Integer.parseInt(st.nextToken());

        while (T-- > 0) {
            // Read n, m, cc
            while (!st.hasMoreTokens()) {
                line = br.readLine();
                if (line == null) break;
                st = new StringTokenizer(line);
            }
            if (!st.hasMoreTokens()) break;
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
            cc = Integer.parseInt(st.nextToken());

            // Reset arrays and structures
            // Arrays are static, need to clear up to used indices
            // Max indices used:
            // u, v: 1 to m (m can be up to 1e5? No, u, v size is 500010. m is read. We assume m <= 200010 based on usage?
            // Wait, C++ code: u[500010], v[500010]. But n is up to 1e5+7. 
            // In C++, u and v are size 500010.
            // head is 2000005. nxt, go 4100005.
            // We need to clear based on max possible usage in this test case or global max.
            // To be safe and match C++ behavior (which clears 1..ans, 1..n, 1..k), we clear specific ranges.
            // However, Java doesn't auto-clear. We must clear explicitly.
            // C++ code clears:
            // dcc[1..ans]
            // head[1..2*n]
            // low[1..2*n], dfn[1..2*n]
            // go[1..k], nxt[1..k]
            // sta
            // k, cnt, ans
            // gp[1..tot], sz[1..tot]
            // e[1..n]
            // js[1..n], bl[1..n], is[1..n]
            // tot
            
            // We need to implement this clearing logic in Java.
            // Note: Arrays are large. Clearing 4 million ints takes time.
            // But we must do it to avoid dirty state from previous test cases.
            
            // Clear dcc
            for (int i = 1; i <= ans; i++) {
                dcc[i].clear();
            }
            // Clear head, low, dfn
            // C++: for(int i=1;i<=2*n;i++)
            int maxNode = 2 * n;
            for (int i = 1; i <= maxNode; i++) {
                head[i] = 0;
                low[i] = 0;
                dfn[i] = 0;
            }
            // Clear go, nxt
            // C++: for(int i=1;i<=k;i++)
            for (int i = 1; i <= k; i++) {
                go[i] = 0;
                nxt[i] = 0;
            }
            // Clear stack
            while (!sta.isEmpty()) sta.pop();
            
            // Reset counters
            k = 1;
            cnt = 0;
            ans = 0;
            
            // Reset gp, sz, e, js, bl, is
            // C++: for(int i=1;i<=tot;i++) ...
            for (int i = 1; i <= tot; i++) {
                gp[i] = 0;
                sz[i].clear();
            }
            for (int i = 1; i <= n; i++) {
                e[i].clear();
                js[i] = 0;
                bl[i] = 0;
                is[i] = 0;
            }
            tot = 0;
            
            // Reset bitsets
            ans1.clear();
            ans2.clear();

            // Read edges and build graph
            // C++: for(int i=1;i<=m;i++) scanf("%d%d",&u[i],&v[i]);
            for (int i = 1; i <= m; i++) {
                while (!st.hasMoreTokens()) {
                    line = br.readLine();
                    if (line == null) break;
                    st = new StringTokenizer(line);
                }
                u[i] = Integer.parseInt(st.nextToken());
                v[i] = Integer.parseInt(st.nextToken());
                
                if (u[i] == v[i]) continue;
                add(u[i], v[i]);
                add(v[i], u[i]);
            }
            
            // Tarjan
            for (int i = 1; i <= n; i++) {
                if (dfn[i] == 0) {
                    up = 0;
                    tot++;
                    add(i + n, i); // Add self-loop for bridge detection logic
                    tarjan(i + n, 0);
                    gp[tot] = up;
                }
            }
            
            // Build compressed graph
            for (int i = 1; i <= m; i++) {
                if (bl[u[i]] != bl[v[i]]) {
                    e[bl[u[i]]].add(bl[v[i]]);
                    e[bl[v[i]]].add(bl[u[i]]);
                }
            }
            
            // DFS
            for (int i = 1; i <= ans; i++) {
                if (js[i] == 0) {
                    dfs(i, 0);
                }
            }
            
            // Bitset logic
            ans1.set(0);
            ans2.set(0);
            
            // Helper to shift
            // Note: In Java, BitSet doesn't support shift.
            // We implement a manual shift.
            // ans2 |= (ans2 << gp[i])
            // This means for every bit j set in ans2, we set bit (j + gp[i]) in ans2.
            // Since N is up to 1e5+7, N/2 is ~50003.
            // We can implement this by iterating.
            
            for (int i = 1; i <= tot; i++) {
                // ans2 |= (ans2 << gp[i])
                // We need to copy bits from ans2 to ans2 shifted left.
                // Since ans2 is mutable, we must be careful not to read modified bits.
                // We create a copy or iterate from high to low.
                // Iterating from high to low is safe for in-place update.
                int shift = gp[i];
                int limit = ans2.length();
                // Iterate from limit-1 down to 0
                // Actually, we only care about bits that are currently set.
                // But we need to update ans2.
                // We can collect indices or iterate.
                // Since we need to OR with the shifted version.
                // Let's iterate through all possible bit positions.
                // Optimization: Only iterate up to limit.
                for (int j = limit - 1; j >= 0; j--) {
                    if (ans2.get(j)) {
                        if (j + shift < limit) {
                            ans2.set(j + shift, true);
                        }
                    }
                }
                
                // ans1 |= (ans1 << h) for h in sz[i]
                for (int h : sz[i]) {
                    if (h > 0) {
                        // Shift ans1 by h
                        int shiftVal = h;
                        // We need to shift ans1 left by shiftVal.
                        // But we are modifying ans1. Same logic: iterate high to low.
                        // However, we cannot modify ans1 while iterating if we use the same loop for reading.
                        // We need to store the result in a temporary bitset or use a boolean array for this step.
                        // Given N is small enough, we can use a temporary BitSet for the shift result.
                        BitSet tempShift = (BitSet) ans1.clone();
                        // Shift tempShift
                        int tempLimit = tempShift.length();
                        for (int j = tempLimit - 1; j >= 0; j--) {
                            if (tempShift.get(j)) {
                                if (j + shiftVal < tempLimit) {
                                    tempShift.set(j + shiftVal, true);
                                }
                            }
                        }
                        // OR into ans1
                        // We can't use bitwise OR directly on BitSet.
                        // We must iterate again.
                        for (int j = 0; j < tempShift.length(); j++) {
                            if (tempShift.get(j)) {
                                ans1.set(j, true);
                            }
                        }
                    }
                }
                
                // ans1 |= (ans1 << gp[i])
                int shiftVal2 = gp[i];
                BitSet tempShift2 = (BitSet) ans1.clone();
                int tempLimit2 = tempShift2.length();
                for (int j = tempLimit2 - 1; j >= 0; j--) {
                    if (tempShift2.get(j)) {
                        if (j + shiftVal2 < tempLimit2) {
                            tempShift2.set(j + shiftVal2, true);
                        }
                    }
                }
                for (int j = 0; j < tempShift2.length(); j++) {
                    if (tempShift2.get(j)) {
                        ans1.set(j, true);
                    }
                }
                
                ans2.set(0, true);
            }
            
            // Calculate ot
            long ot = (long)n * n * 2;
            // Iterate up to min(n, N/2)
            int limitBit = Math.min(n, N / 2);
            for (int i = 0; i <= limitBit; i++) {
                if (ans1.get(i) || ans2.get(i)) {
                    ot = Math.min(ot, (long)i * i + (long)(n - i) * (n - i));
                }
            }
            ot = ot + (long)cc * (tot - 1);
            
            if (tot == 1 && sz[1].size() == 2) {
                out.println("-1");
            } else {
                out.println(ot);
            }
            
            // Clear bitsets for next iteration (already done at start of loop, but good to be explicit)
            ans1.clear();
            ans2.clear();
        }
        
        out.flush();
    }
}
```

Wait, I need to check the array sizes and initialization logic carefully.
In C++, `u` and `v` are size `500010`. In Java, I allocated `500010`. This is fine.
`head` is `2000005`. Java `2000005` is fine.
`nxt`, `go` are `4100005`. Java `4100005` is fine.
`dfn`, `low` are `2000005`. Java `2000005` is fine.
`bl`, `is` are `200010`. Java `200010` is fine.
`e` is `vector<int> e[N]`. `N` is `100007`. So `e` is array of vectors of size `100007`. Java `ArrayList[]` of size `100007`.
`sz` is `set<int> sz[200010]`. Java `HashSet[]` of size `100007` (since max index is `tot`, `tot` <= `n`). Wait, `tot` is number of biconnected components. `tot` <= `n`. So `sz` needs to be size `N`.
Wait, `sz` in C++ is `sz[200010]`. But `tot` is at most `n` (`100007`). So `sz` only needs to be size `N`.
However, the C++ code declares `sz[200010]`. I should probably make it size `200010` or `N` depending on how `tot` relates to `n`.
In the code: `sz[is[x]]`. `is[x]` is set to `tot`. `tot` is incremented up to `n` (roughly).
Actually, `tot` is incremented when `dfn[i] == 0`. `i` goes from `1` to `n`. So `tot` <= `n`.
So `sz` size `N` is sufficient. But to be safe and match C++ declaration, I'll use `200010` for `sz` and `gp` and `bl`, `is`, `js` if needed. But `js` is indexed by `x` which is node index? No, `js` is indexed by `x` in `dfs`, but `dfs` is called on `i` which is `1..ans` (which is `tot`). Wait, `dfs` is called on `i` which is `1..ans`. `ans` is number of biconnected components. `ans` <= `n`. So `js` needs to be size `N`.
Wait, `js` is `js[N*2]` in C++. `N` is `1e5+7`. `N*2` is `200014`.
So `js` needs to be size `200014`.
`gp` is `gp[200010]`. `tot` is number of biconnected components. `tot` <= `n`. So `gp` size `N` is enough. But C++ uses `200010`. I will use `200010` to be safe.
`bl`, `is` are `200010`. `bl` is indexed by node index? `bl[p] = ans`. `p` is node index. `p` <= `n`. `n` <= `1e5+7`. So `200010` is fine.
`e` is `vector<int> e[N]`. `N` is `1e5+7`. `e` is indexed by component ID. `bl[u[i]]` is component ID. Component ID is `1..ans`. `ans` <= `n`. So `e` size `N` is fine.
Wait, `e` is `vector<int> e[N]`. In C++, `N` is `1e5+7`.
So `e` size `N` is fine.

Wait, the C++ code has `vector<int> dcc[500005]`. `dcc` is indexed by `ans`. `ans` <= `n`. So `500005` is plenty.
In Java, I used `N` (`100007`) for `dcc`. This is correct.

One detail: `u` and `v` are size `500010`. `m` can be up to `200010`? No, `m` is read.
The constraints in competitive programming problems often imply `m` is up to `200010` or similar.
But `u` and `v` arrays are size `500010`.
I will keep `u` and `v` size `500010`.

Wait, `sz` is `set<int> sz[200010]`.
In Java, I used `N` (`100007`). `tot` <= `n`. `n` <= `100007`. So `sz` size `N` is fine.

Wait, `js` is `js[N*2]`. `N*2` is `200014`.
So `js` needs to be size `200020` (to be safe).
`gp` is `gp[200010]`. `tot` <= `n`. `n` <= `100007`. So `gp` size `N` is fine.

I will adjust array sizes to match C++ declarations where possible, or make them large enough.
`u`, `v`: `500010`.
`head`: `2000005`.
`nxt`, `go`: `4100005`.
`dfn`, `low`: `2000005`.
`bl`, `is`: `200010`.
`e`: `N` (`100007`).
`sz`: `200010` (to match C++).
`js`: `200020` (to cover `N*2`).
`gp`: `200010`.

One more thing: `sta` stack. `stack<int>sta`.
In Java, `Stack<Integer>`.

Also, `BitSet` shift implementation.
The C++ code does `ans2|=(ans2<<gp[i]);`.
This means `ans2` is updated in place.
In Java, `BitSet` is mutable, but we cannot do `ans2 |= (ans2 << k)`.
We need to implement the shift.
My implementation iterates from high to low, which is safe for in-place update.

One issue: `ans2` size. `ans2` is `bitset<N/2>`. `N` is `1e5+7`. `N/2` is `50003`.
So `ans2` size is `50003`.
In Java, `BitSet` grows dynamically. I initialized `new BitSet(N/2 + 1)`.
This is fine.

Wait, `sz[i].clear()`. `sz` is `HashSet`. `HashSet.clear()` is fine.
`dcc[i].clear()`. `ArrayList.clear()` is fine.

The clearing of arrays:
C++ clears `head[1..2*n]`.
Java clears `head[1..2*n]`.
C++ clears `go[1..k]`, `nxt[1..k]`.
Java clears `go[1..k]`, `nxt[1..k]`.
C++ clears `sta`.
Java clears `sta`.
C++ clears `k=1`, `cnt=0`, `ans=0`.
Java sets `k=1`, `cnt=0`, `ans=0`.
C++ clears `gp[1..tot]`, `sz[1..tot]`.
Java clears `gp[1..tot]`, `sz[1..tot]`.
C++ clears `e[1..n]`, `js[1..n]`, `bl[1..n]`, `is[1..n]`.
Java clears `e[1..n]`, `js[1..n]`, `bl[1..n]`, `is[1..n]`.
C++ clears `tot=0`.
Java sets `tot=0`.

The clearing logic in Java must match the C++ logic.
C++: `for(int i=1;i<=ans;i++) dcc[i].clear();`
C++: `for(int i=1;i<=2*n;i++) head[i]=low[i]=dfn[i]=0;`
C++: `for(int i=1;i<=k;i++) go[i]=nxt[i]=0;`
C++: `while(!sta.empty())sta.pop();`
C++: `k=1;cnt=ans=0;`
C++: `for(int i=1;i<=tot;i++){gp[i]=0;sz[i].clear();}`
C++: `for(int i=1;i<=n;i++){e[i].clear();js[i]=bl[i]=is[i]=0;}`
C++: `tot=0;`

This looks consistent.

One small correction: `ans2` shift.
In C++, `ans2` is `bitset<N/2>`.
In Java, `ans2` is `BitSet`.
The shift `ans2 |= (ans2 << gp[i])` means for each bit `j` set in `ans2`, set bit `j + gp[i]` in `ans2`.
My implementation:
```java
BitSet tempShift = (BitSet) ans2.clone();
// ... shift tempShift ...
// OR into ans1
```
Wait, the C++ code does:
```cpp
ans2|=(ans2<<gp[i]);
for(auto h:sz[i])
    if(h)ans2|=(ans1<<h);
ans1|=(ans1<<gp[i]);
```
So `ans2` is updated by shifting `ans2` left by `gp[i]`.
Then `ans2` is updated by shifting `ans1` left by `h` for each `h` in `sz[i]`.
Then `ans1` is updated by shifting `ans1` left by `gp[i]`.

My Java code does:
```java
// ans2 |= (ans2 << gp[i])
int shift = gp[i];
// ... shift ans2 ...

// ans2 |= (ans1 << h)
for (int h : sz[i]) {
    if (h > 0) {
        // Shift ans1 by h
        // We need to update ans2.
        // We cannot modify ans2 while iterating ans1? No, we are modifying ans2.
        // We need to read from ans1 and write to ans2.
        // So we need to clone ans1 or iterate carefully.
        BitSet tempShift = (BitSet) ans1.clone();
        // shift tempShift by h
        // ...
        // OR into ans2
    }
}
// ans1 |= (ans1 << gp[i])
// shift ans1 by gp[i]
```
Wait, `ans2 |= (ans1 << h)`. This means `ans2` gets bits from `ans1` shifted by `h`.
So we need to clone `ans1` to avoid modifying it while reading.
Then OR the shifted `ans1` into `ans2`.

Correct logic:
1. `ans2 |= (ans2 << gp[i])`: Clone `ans2`, shift, OR into `ans2`.
2. `ans2 |= (ans1 << h)`: Clone `ans1`, shift by `h`, OR into `ans2`.
3. `ans1 |= (ans1 << gp[i])`: Clone `ans1`, shift by `gp[i]`, OR into `ans1`.

My previous code draft had:
```java
// ans2 |= (ans2 << gp[i])
// ...
// ans1 |= (ans1 << h)
// ...
// ans2 |= (ans1 << h)
// ...
```
I need to make sure the order is correct.
The C++ code:
```cpp
ans2|=(ans2<<gp[i]);
for(auto h:sz[i])
    if(h)ans2|=(ans1<<h);
ans1|=(ans1<<gp[i]);
```
So:
1. Shift `ans2` by `gp[i]`.
2. For each `h` in `sz[i]`, shift `ans1` by `h` and OR into `ans2`.
3. Shift `ans1` by `gp[i]`.

I need to implement `shiftLeft` method that returns a new BitSet or modifies the given BitSet (if passed by value, but Java uses reference).
Since `BitSet` is mutable, I should create a copy before shifting if I want to preserve the original.
So `shiftLeft(BitSet b, int shift)` should create a copy of `b`, shift the copy, and return the shifted copy?
Or `shiftLeft` modifies `b` in place?
If `shiftLeft` modifies `b` in place, then `ans2 |= (ans2 << gp[i])` is tricky because `ans2` is modified.
Actually, `ans2 |= (ans2 << gp[i])` means `ans2` is updated.
So we need to shift `ans2` and OR the result back into `ans2`.
Since `ans2` is updated, we can do:
```java
BitSet shifted = (BitSet) ans2.clone();
shiftLeft(shifted, gp[i]);
ans2.or(shifted);
```
Similarly for `ans1`.

Wait, the C++ code does `ans2 |= (ans2 << gp[i])`.
This means `ans2 = ans2 | (ans2 << gp[i])`.
So we need to compute `ans2 << gp[i]` and OR it with `ans2`.
So:
```java
BitSet shifted = (BitSet) ans2.clone();
shiftLeft(shifted, gp[i]);
ans2.or(shifted);
```
This is correct.

Similarly:
```cpp
for(auto h:sz[i])
    if(h)ans2|=(ans1<<h);
```
This means `ans2 = ans2 | (ans1 << h)`.
So:
```java
BitSet shifted = (BitSet) ans1.clone();
shiftLeft(shifted, h);
ans2.or(shifted);
```

And:
```cpp
ans1|=(ans1<<gp[i]);
```
This means `ans1 = ans1 | (ans1 << gp[i])`.
So:
```java
BitSet shifted = (BitSet) ans1.clone();
shiftLeft(shifted, gp[i]);
ans1.or(shifted);
```

I will implement `shiftLeft` to modify the given BitSet in place (or return a new one, but modifying in place is simpler if we don't reuse the object).
Wait, if I modify `ans2` in place, I can't read it for the shift.
So I must clone.
`shiftLeft` will take a BitSet and a shift amount, and shift the bits in the given BitSet.
But if I modify `ans2` in place, I lose the original bits.
So `shiftLeft` should not modify the given BitSet if it's the source.
Actually, `shiftLeft` should take a BitSet and shift it.
But if I use the same BitSet for source and destination, it's wrong.
So `shiftLeft` should return a new BitSet or I must clone before calling `shiftLeft`.
I will implement `shiftLeft` to modify the given BitSet in place.
Then the caller must clone before calling.

Wait, `BitSet` clone is deep copy? Yes.
So:
```java
BitSet shifted = (BitSet) ans2.clone();
shiftLeft(shifted, gp[i]);
ans2.or(shifted);
```
This is correct.

I will write the final code now.

```java
import java.io.*;
import java.util.*;

public class g3_1970 {
    static final int N = 100007;
    static int T;
    static int[] u = new int[500010];
    static int[] v = new int[500010];
    static int[] head = new int[2000005];
    static int[] nxt = new int[4100005];
    static int[] go = new int[4100005];
    static int[] dfn = new int[2000005];
    static int[] low = new int[2000005];
    static int[] bl = new int[200010];
    static int[] is = new int[200010];
    static int[] js = new int[200020]; // N*2 is 200014, so 200020 is safe
    static int[] gp = new int[200010];
    static int k = 1;
    static int cnt = 0;
    static int ans = 0;
    static int tot = 0;
    static int up = 0;
    static Stack<Integer> sta = new Stack<>();
    static ArrayList<Integer>[] e = new ArrayList[N];
    static ArrayList<Integer>[] dcc = new ArrayList[N];
    static HashSet<Integer>[] sz = new HashSet[200010]; // Match C++ size
    
    // BitSet equivalent
    static BitSet ans1 = new BitSet(N / 2 + 1);
    static BitSet ans2 = new BitSet(N / 2 + 1);

    // Helper to shift BitSet left by k
    private static void shiftLeft(BitSet b, int shift) {
        if (shift == 0) return;
        // We need to shift bits to higher indices.
        // Iterate from high to low to allow in-place update
        int limit = b.length();
        for (int i = limit - 1; i >= 0; i--) {
            if (b.get(i)) {
                if (i + shift < limit) {
                    b.set(i + shift, true);
                }
            }
        }
    }

    public static void add(int x, int y) {
        k++;
        nxt[k] = head[x];
        head[x] = k;
        go[k] = y;
    }

    public static void tarjan(int x, int edge) {
        dfn[x] = low[x] = ++cnt;
        if (x <= n) up++;
        sta.push(x);
        for (int i = head[x]; i != 0; i = nxt[i]) {
            int g = go[i];
            if (dfn[g] == 0) {
                tarjan(g, i);
                low[x] = Math.min(low[x], low[g]);
                if (low[g] > dfn[x]) {
                    ans++;
                    is[ans] = tot;
                    int p;
                    do {
                        p = sta.pop();
                        dcc[ans].add(p);
                        bl[p] = ans;
                    } while (p != g);
                }
            } else if (i != (edge ^ 1)) {
                low[x] = Math.min(low[x], dfn[g]);
            }
        }
    }

    public static void dfs(int x, int fa) {
        js[x] = dcc[x].size();
        for (int v : e[x]) {
            if (v != fa) {
                dfs(v, x);
                js[x] += js[v];
            }
        }
        sz[is[x]].add(js[x]);
        sz[is[x]].add(gp[is[x]] - js[x]);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer("");

        // Read T
        String line = br.readLine();
        while (line != null && line.trim().isEmpty()) line = br.readLine();
        if (line == null) return;
        st = new StringTokenizer(line);
        T = Integer.parseInt(st.nextToken());

        while (T-- > 0) {
            // Read n, m, cc
            while (!st.hasMoreTokens()) {
                line = br.readLine();
                if (line == null) break;
                st = new StringTokenizer(line);
            }
            if (!st.hasMoreTokens()) break;
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
            cc = Integer.parseInt(st.nextToken());

            // Reset arrays and structures
            // Clear dcc
            for (int i = 1; i <= ans; i++) {
                dcc[i].clear();
            }
            // Clear head, low, dfn
            int maxNode = 2 * n;
            for (int i = 1; i <= maxNode; i++) {
                head[i] = 0;
                low[i] = 0;
                dfn[i] = 0;
            }
            // Clear go, nxt
            for (int i = 1; i <= k; i++) {
                go[i] = 0;
                nxt[i] = 0;
            }
            // Clear stack
            while (!sta.isEmpty()) sta.pop();
            
            // Reset counters
            k = 1;
            cnt = 0;
            ans = 0;
            
            // Reset gp, sz
            for (int i = 1; i <= tot; i++) {
                gp[i] = 0;
                sz[i].clear();
            }
            // Reset e, js, bl, is
            for (int i = 1; i <= n; i++) {
                e[i].clear();
                js[i] = 0;
                bl[i] = 0;
                is[i] = 0;
            }
            tot = 0;
            
            // Reset bitsets
            ans1.clear();
            ans2.clear();

            // Read edges and build graph
            for (int i = 1; i <= m; i++) {
                while (!st.hasMoreTokens()) {
                    line = br.readLine();
                    if (line == null) break;
                    st = new StringTokenizer(line);
                }
                u[i] = Integer.parseInt(st.nextToken());
                v[i] = Integer.parseInt(st.nextToken());
                
                if (u[i] == v[i]) continue;
                add(u[i], v[i]);
                add(v[i], u[i]);
            }
            
            // Tarjan
            for (int i = 1; i <= n; i++) {
                if (dfn[i] == 0) {
                    up = 0;
                    tot++;
                    add(i + n, i); // Add self-loop for bridge detection logic
                    tarjan(i + n, 0);
                    gp[tot] = up;
                }
            }
            
            // Build compressed graph
            for (int i = 1; i <= m; i++) {
                if (bl[u[i]] != bl[v[i]]) {
                    e[bl[u[i]]].add(bl[v[i]]);
                    e[bl[v[i]]].add(bl[u[i]]);
                }
            }
            
            // DFS
            for (int i = 1; i <= ans; i++) {
                if (js[i] == 0) {
                    dfs(i, 0);
                }
            }
            
            // Bitset logic
            // ans2 |= (ans2 << gp[i])
            for (int i = 1; i <= tot; i++) {
                BitSet shifted = (BitSet) ans2.clone();
                shiftLeft(shifted, gp[i]);
                ans2.or(shifted);
                
                // ans2 |= (ans1 << h)
                for (int h : sz[i]) {
                    if (h > 0) {
                        BitSet shifted1 = (BitSet) ans1.clone();
                        shiftLeft(shifted1, h);
                        ans2.or(shifted1);
                    }
                }
                
                // ans1 |= (ans1 << gp[i])
                BitSet shiftedAns1 = (BitSet) ans1.clone();
                shiftLeft(shiftedAns1, gp[i]);
                ans1.or(shiftedAns1);
            }
            
            // Calculate ot
            long ot = (long)n * n * 2;
            int limitBit = Math.min(n, N / 2);
            for (int i = 0; i <= limitBit; i++) {
                if (ans1.get(i) || ans2.get(i)) {
                    ot = Math.min(ot, (long)i * i + (long)(n - i) * (n - i));
                }
            }
            ot = ot + (long)cc * (tot - 1);
            
            if (tot == 1 && sz[1].size() == 2) {
                out.println("-1");
            } else {
                out.println(ot);
            }
        }
        
        out.flush();
    }
}
```

Wait, I need to check the `sz` array size again.
C++: `set<int> sz[200010];`
Java: `static HashSet<Integer>[] sz = new HashSet[200010];`
This is correct.

Also, `e` array size.
C++: `vector<int> e[N];`
Java: `static ArrayList<Integer>[] e = new ArrayList[N];`
This is correct.

`u`, `v` array size.
C++: `int u[500010], v[500010];`
Java: `static int[] u = new int[500010];`
This is correct.

`head` array size.
C++: `int head[2000005];`
Java: `static int[] head = new int[2000005];`
This is correct.

`nxt`, `go` array size.
C++: `int nxt[4100005], head[2000005], go[4100005];`
Java: `static int[] nxt = new int[4100005];`
This is correct.

`dfn`, `low` array size.
C++: `int dfn[2000005], low[2000005];`
Java: `static int[] dfn = new int[2000005];`
This is correct.

`bl`, `is` array size.
C++: `int bl[200010], is[200010];`
Java: `static int[] bl = new int[200010];`
This is correct.

`js` array size.
C++: `int js[N*2];`
Java: `static int[] js = new int[200020];`
This is correct.

`gp` array size.
C++: `int gp[200010];`
Java: `static int[] gp = new int[200010];`
This is correct.

`ans1`, `ans2` size.
C++: `bitset<N/2>ans1, ans2;`
Java: `static BitSet ans1 = new BitSet(N / 2 + 1);`
This is correct.

One detail: `N` is `1e5+7`. `N/2` is `50003`.
`ans1` size `50004`.
In C++, `bitset<N/2>` size is `N/2`.
In Java, `BitSet` is dynamic. I used `N/2 + 1`. This is fine.

One more thing: `u` and `v` are 1-based.
In C++, `u[i]` is used. `i` goes from `1` to `m`.
In Java, `u` array is 0-indexed. `u[i]` works for `i` up to `500009`.
So `u = new int[500010]` is fine.

The logic seems solid.

One small optimization: `shiftLeft` method.
It iterates from `limit - 1` down to `0`.
This is correct for in-place shift.

Final check on `shiftLeft`:
```java
    private static void shiftLeft(BitSet b, int shift) {
        if (shift == 0) return;
        int limit = b.length();
        for (int i = limit - 1; i >= 0; i--) {
            if (b.get(i)) {
                if (i + shift < limit) {
                    b.set(i + shift, true);
                }
            }
        }
    }
```
This is correct.

I will output the code now.
</think>

<CODE>
import java.io.*;
import java.util.*;

public class g3_1970 {
    static final int N = 100007;
    static int T;
    static int[] u = new int[500010];
    static int[] v = new int[500010];
    static int[] head = new int[2000005];
    static int[] nxt = new int[4100005];
    static int[] go = new int[4100005];
    static int[] dfn = new int[2000005];
    static int[] low = new int[2000005];
    static int[] bl = new int[200010];
    static int[] is = new int[200010];
    static int[] js = new int[200020]; // N*2 is 200014, so 200020 is safe
    static int[] gp = new int[200010];
    static int k = 1;
    static int cnt = 0;
    static int ans = 0;
    static int tot = 0;
    static int up = 0;
    static Stack<Integer> sta = new Stack<>();
    static ArrayList<Integer>[] e = new ArrayList[N];
    static ArrayList<Integer>[] dcc = new ArrayList[N];
    static HashSet<Integer>[] sz = new HashSet[200010]; // Match C++ size
    
    // BitSet equivalent
    static BitSet ans1 = new BitSet(N / 2 + 1);
    static BitSet ans2 = new BitSet(N / 2 + 1);

    // Helper to shift BitSet left by k
    private static void shiftLeft(BitSet b, int shift) {
        if (shift == 0) return;
        // We need to shift bits to higher indices.
        // Iterate from high to low to allow in-place update
        int limit = b.length();
        for (int i = limit - 1; i >= 0; i--) {
            if (b.get(i)) {
                if (i + shift < limit) {
                    b.set(i + shift, true);
                }
            }
        }
    }

    public static void add(int x, int y) {
        k++;
        nxt[k] = head[x];
        head[x] = k;
        go[k] = y;
    }

    public static void tarjan(int x, int edge) {
        dfn[x] = low[x] = ++cnt;
        if (x <= n) up++;
        sta.push(x);
        for (int i = head[x]; i != 0; i = nxt[i]) {
            int g = go[i];
            if (dfn[g] == 0) {
                tarjan(g, i);
                low[x] = Math.min(low[x], low[g]);
                if (low[g] > dfn[x]) {
                    ans++;
                    is[ans] = tot;
                    int p;
                    do {
                        p = sta.pop();
                        dcc[ans].add(p);
                        bl[p] = ans;
                    } while (p != g);
                }
            } else if (i != (edge ^ 1)) {
                low[x] = Math.min(low[x], dfn[g]);
            }
        }
    }

    public static void dfs(int x, int fa) {
        js[x] = dcc[x].size();
        for (int v : e[x]) {
            if (v != fa) {
                dfs(v, x);
                js[x] += js[v];
            }
        }
        sz[is[x]].add(js[x]);
        sz[is[x]].add(gp[is[x]] - js[x]);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer("");

        // Read T
        String line = br.readLine();
        while (line != null && line.trim().isEmpty()) line = br.readLine();
        if (line == null) return;
        st = new StringTokenizer(line);
        T = Integer.parseInt(st.nextToken());

        while (T-- > 0) {
            // Read n, m, cc
            while (!st.hasMoreTokens()) {
                line = br.readLine();
                if (line == null) break;
                st = new StringTokenizer(line);
            }
            if (!st.hasMoreTokens()) break;
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
            cc = Integer.parseInt(st.nextToken());

            // Reset arrays and structures
            // Clear dcc
            for (int i = 1; i <= ans; i++) {
                dcc[i].clear();
            }
            // Clear head, low, dfn
            int maxNode = 2 * n;
            for (int i = 1; i <= maxNode; i++) {
                head[i] = 0;
                low[i] = 0;
                dfn[i] = 0;
            }
            // Clear go, nxt
            for (int i = 1; i <= k; i++) {
                go[i] = 0;
                nxt[i] = 0;
            }
            // Clear stack
            while (!sta.isEmpty()) sta.pop();
            
            // Reset counters
            k = 1;
            cnt = 0;
            ans = 0;
            
            // Reset gp, sz
            for (int i = 1; i <= tot; i++) {
                gp[i] = 0;
                sz[i].clear();
            }
            // Reset e, js, bl, is
            for (int i = 1; i <= n; i++) {
                e[i].clear();
                js[i] = 0;
                bl[i] = 0;
                is[i] = 0;
            }
            tot = 0;
            
            // Reset bitsets
            ans1.clear();
            ans2.clear();

            // Read edges and build graph
            for (int i = 1; i <= m; i++) {
                while (!st.hasMoreTokens()) {
                    line = br.readLine();
                    if (line == null) break;
                    st = new StringTokenizer(line);
                }
                u[i] = Integer.parseInt(st.nextToken());
                v[i] = Integer.parseInt(st.nextToken());
                
                if (u[i] == v[i]) continue;
                add(u[i], v[i]);
                add(v[i], u[i]);
            }
            
            // Tarjan
            for (int i = 1; i <= n; i++) {
                if (dfn[i] == 0) {
                    up = 0;
                    tot++;
                    add(i + n, i); // Add self-loop for bridge detection logic
                    tarjan(i + n, 0);
                    gp[tot] = up;
                }
            }
            
            // Build compressed graph
            for (int i = 1; i <= m; i++) {
                if (bl[u[i]] != bl[v[i]]) {
                    e[bl[u[i]]].add(bl[v[i]]);
                    e[bl[v[i]]].add(bl[u[i]]);
                }
            }
            
            // DFS
            for (int i = 1; i <= ans; i++) {
                if (js[i] == 0) {
                    dfs(i, 0);
                }
            }
            
            // Bitset logic
            // ans2 |= (ans2 << gp[i])
            for (int i = 1; i <= tot; i++) {
                BitSet shifted = (BitSet) ans2.clone();
                shiftLeft(shifted, gp[i]);
                ans2.or(shifted);
                
                // ans2 |= (ans1 << h)
                for (int h : sz[i]) {
                    if (h > 0) {
                        BitSet shifted1 = (BitSet) ans1.clone();
                        shiftLeft(shifted1, h);
                        ans2.or(shifted1);
                    }
                }
                
                // ans1 |= (ans1 << gp[i])
                BitSet shiftedAns1 = (BitSet) ans1.clone();
                shiftLeft(shiftedAns1, gp[i]);
                ans1.or(shiftedAns1);
            }
            
            // Calculate ot
            long ot = (long)n * n * 2;
            int limitBit = Math.min(n, N / 2);
            for (int i = 0; i <= limitBit; i++) {
                if (ans1.get(i) || ans2.get(i)) {
                    ot = Math.min(ot, (long)i * i + (long)(n - i) * (n - i));
                }
            }
            ot = ot + (long)cc * (tot - 1);
            
            if (tot == 1 && sz[1].size() == 2) {
                out.println("-1");
            } else {
                out.println(ot);
            }
        }
        
        out.flush();
    }
}
</CODE>