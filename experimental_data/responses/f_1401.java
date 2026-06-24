Translate this C++ code to Java code. The main class name should be f_1401. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include<bits/stdc++.h>

#include<unordered_map>

#define ll long long

#define ull unsigned long long

#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;



const int inf = 0x3f3f3f3f;

const ll INF = 0x3f3f3f3f3f3f3f3f;

const double eps = 1e-8;

const ll mod = 1000000007;

const int N = 3e5 + 5;



int n, m, is_swap[35], a[N];

struct node {

	int l, r;

	ll sum;

}tree[N << 2];



void push_up(int p)

{

	tree[p].sum = tree[p << 1].sum + tree[p << 1 | 1].sum;

}



void build(int l, int r, int p)

{

	tree[p].l = l;

	tree[p].r = r;

	if (l == r)

	{

		tree[p].sum = a[l];

		return;

	}

	int mid = (l + r) / 2;

	build(l, mid, p << 1);

	build(mid + 1, r, p << 1 | 1);

	push_up(p);

}



void update(int pos, int val, int dep, int l, int r, int p)

{

	if (l == r)

	{

		a[l] = val;

		tree[p].sum = val;

		return;

	}

	int mid = (l + r) / 2;

	if (pos <= mid)

		update(pos, val, dep - 1, l, mid, (p << 1) + is_swap[dep]);

	else

		update(pos, val, dep - 1, mid + 1, r, (p << 1 | 1) - is_swap[dep]);

	push_up(p);

}



ll query(int ql, int qr, int dep, int l, int r, int p)

{

	if (ql <= l && qr >= r)

		return tree[p].sum;

	int mid = (l + r) / 2;

	ll ans = 0;

	if (ql <= mid)

		ans += query(ql, qr, dep - 1, l, mid, (p << 1) + is_swap[dep]);

	if(qr > mid)

		ans += query(ql, qr, dep - 1, mid + 1, r, (p << 1 | 1) - is_swap[dep]);

	return ans;

}



void solve()

{

	cin >> n >> m;

	for (int i = 1; i <= (1 << n); i++)

		cin >> a[i];

	build(1, 1 << n, 1);

	while (m--)

	{

		int op;

		cin >> op;

		if (op == 1)

		{

			int x, k;

			cin >> x >> k;

			update(x, k, n, 1, 1 << n, 1);

			//cout << "-----" << query(1, 4, n, 1, 1 << n, 1) << '\n';

		}

		else if (op == 2)

		{

			int k;

			cin >> k;

			for (int i = 1; i <= k; i++)

				is_swap[i] ^= 1;

		}

		else if(op == 3)

		{

			int k;

			cin >> k;

			is_swap[k + 1] ^= 1;

		}

		else

		{

			int l, r;

			cin >> l >> r;

			cout << query(l, r, n, 1, 1 << n, 1) << '\n';

		}

	}

}



signed main()

{

	IOS;

	ll t = 1;

	//cin >> t;

	while (t--)

		solve();

	return 0;

}

Here is the plan for the translation:

1.  **Headers**: Replace `#include<bits/stdc++.h>` with specific standard library headers (`iostream`, `vector`, `algorithm`, `map`, etc.). Remove `using namespace std;` and use explicit `std::` qualifiers to make the code cleaner and more robust.
2.  **Macros**: Replace C++ specific macros (`#define ll long long`, etc.) with `typedef` statements. This is a best practice in Java.
3.  **Structures**: The C++ `struct node` needs to be translated to a `class` or a `record` (Java 16+), but a standard `class` is more compatible with older Java versions. The fields should be private with getters/setters or public static final fields if they were constants, but here they are mutable, so an instance class is appropriate.
4.  **Arrays**: C++ global arrays (`int is_swap[35]`, `int a[N]`) need to be converted to Java `int[]` or `ArrayList`. Since the size `N` is fixed (`3e5 + 5`), a static `int[]` array is the most efficient translation.
5.  **Functions**: C++ member functions need to be translated to static Java methods (since the code uses global variables and doesn't rely on object state). The logic remains the same, but syntax changes (e.g., `p << 1` becomes `p << 1` in Java as well, but parentheses are needed for precedence).
6.  **I/O**: The `IOS` macro (`ios::sync_with_stdio(false)`) has no direct equivalent in Java. We will use `BufferedReader` and `StringTokenizer` for fast I/O, replacing `cin` and `cout`.
7.  **Main Method**: The `signed main()` function becomes the `public static void main(String[] args)` method. The loop `while(t--)` remains similar but handles the input stream differently.
8.  **Incremental Tasks**:
    *   Define constants and types.
    *   Create the `Node` class.
    *   Create the `main` method with the Fast I/O setup.
    *   Implement `pushUp`, `build`, `update`, `query`.
    *   Implement `solve` logic (parsing input, handling operations).

Here is the resulting Java code:

<CODE>
import java.io.*;
import java.util.*;

public class f_1401 {

    // Constants
    static final int INF = 0x3f3f3f3f;
    static final long INF_LONG = 0x3f3f3f3f3f3f3f3fL;
    static final double EPS = 1e-8;
    static final long MOD = 1000000007L;
    static final int N = 300005;

    // Arrays
    static int[] isSwap = new int[35];
    static int[] a = new int[N];
    static int[] treeL = new int[N << 2];
    static int[] treeR = new int[N << 2];
    static long[] treeSum = new long[N << 2];

    // Fast I/O
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st = null;

    // Helper for reading
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
        return (s == null) ? 0 : Integer.parseInt(s);
    }

    // Node structure translated to arrays for performance
    // We keep the logic of the struct but use parallel arrays to simulate it efficiently.
    // Alternatively, we could create a class, but arrays are often preferred in CP for speed.
    // Given the original code uses struct, we will stick to the logic.
    // Note: In Java, passing objects by reference is implicit, so we can create a class or use arrays.
    // To strictly follow the logic without overhead of object creation in loops, parallel arrays are best.
    // However, to make the code readable and closer to the "struct" concept, I will use a class if needed,
    // but for the specific `build` and `update` recursion which accesses `p`, parallel arrays are the standard Java translation
    // for C++ segment tree arrays to avoid object overhead.

    static void pushUp(int p) {
        treeSum[p] = treeSum[p << 1] + treeSum[(p << 1) | 1];
    }

    static void build(int l, int r, int p) {
        treeL[p] = l;
        treeR[p] = r;
        if (l == r) {
            treeSum[p] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(l, mid, p << 1);
        build(mid + 1, r, (p << 1) | 1);
        pushUp(p);
    }

    static void update(int pos, int val, int dep, int l, int r, int p) {
        if (l == r) {
            a[pos] = val;
            treeSum[p] = val;
            return;
        }
        int mid = (l + r) / 2;
        // Note: In Java, bitwise operators have lower precedence than `+` in some contexts? No, `<<` and `|` are fine.
        // But `p << 1` is `p * 2`. `(p << 1) | 1` is `p * 2 + 1`.
        // We must ensure operator precedence is clear.
        // `p << 1` is evaluated before `| 1`.
        if (pos <= mid) {
            update(pos, val, dep - 1, l, mid, (p << 1) + isSwap[dep]);
        } else {
            update(pos, val, dep - 1, mid + 1, r, (p << 1) | 1 - isSwap[dep]);
            // Wait, original code: `(p << 1 | 1) - is_swap[dep]`
            // Precedence: `<<` is higher than `|`. So `p << 1 | 1` is `(p << 1) | 1`.
            // Then subtraction happens.
            // Java: `(p << 1) | 1 - isSwap[dep]` -> `(p<<1) | (1 - isSwap[dep])`.
            // This matches C++ logic where `|` is lower than `-`.
            // Let's re-verify C++ precedence.
            // `<<` (shift) has higher precedence than `|` (bitwise OR).
            // `|` has higher precedence than `-` (subtraction).
            // So C++: `((p << 1) | 1) - is_swap[dep]`
            // Java: `((p << 1) | 1) - isSwap[dep]`
            // My previous line `(p << 1) | 1 - isSwap[dep]` would be interpreted as `(p<<1) | (1 - isSwap[dep])`.
            // This is WRONG compared to C++.
            // Correct logic: `((p << 1) | 1) - isSwap[dep]`
            // Let's fix the call.
            // Actually, let's look at the original code carefully:
            // `update(..., (p << 1 | 1) - is_swap[dep], ...)`
            // In C++, `<<` > `|` > `-`. So `((p << 1) | 1) - is_swap[dep]`.
            // In Java, `<<` > `|` > `-`. So `((p << 1) | 1) - isSwap[dep]`.
            // So the expression `(p << 1 | 1) - isSwap[dep]` in C++ is equivalent to `((p << 1) | 1) - isSwap[dep]` in Java.
            // However, to be safe and explicit:
            int rightChild = (p << 1) | 1;
            update(pos, val, dep - 1, mid + 1, r, rightChild - isSwap[dep]);
        }
        pushUp(p);
    }

    static long query(int ql, int qr, int dep, int l, int r, int p) {
        if (ql <= l && qr >= r) {
            return treeSum[p];
        }
        int mid = (l + r) / 2;
        long ans = 0;
        if (ql <= mid) {
            ans += query(ql, qr, dep - 1, l, mid, (p << 1) + isSwap[dep]);
        }
        if (qr > mid) {
            // C++: (p << 1 | 1) - is_swap[dep]
            // Java: ((p << 1) | 1) - isSwap[dep]
            int rightChild = (p << 1) | 1;
            ans += query(ql, qr, dep - 1, mid + 1, r, rightChild - isSwap[dep]);
        }
        return ans;
    }

    static void solve() throws IOException {
        String nStr = next();
        if (nStr == null) return;
        int n = Integer.parseInt(nStr);
        int m = nextInt();

        for (int i = 1; i <= (1 << n); i++) {
            a[i] = nextInt();
        }

        build(1, (1 << n), 1);

        while (m-- > 0) {
            int op = nextInt();
            if (op == 1) {
                int x = nextInt();
                int k = nextInt();
                update(x, k, n, 1, (1 << n), 1);
            } else if (op == 2) {
                int k = nextInt();
                for (int i = 1; i <= k; i++) {
                    isSwap[i] ^= 1;
                }
            } else if (op == 3) {
                int k = nextInt();
                isSwap[k + 1] ^= 1;
            } else {
                int l = nextInt();
                int r = nextInt();
                System.out.println(query(l, r, n, 1, (1 << n), 1));
            }
        }
    }

    public static void main(String[] args) throws IOException {
        // Fast I/O setup
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;
        
        // We reuse the static fields logic but need to initialize them properly or just use local vars if needed.
        // Since we used static fields for the arrays in the class definition, we can just use them.
        // However, to match the logic exactly, we need to ensure the static arrays are available.
        // The `solve` method uses them.
        
        // The original code had `IOS` macro. We simulate it by initializing the reader.
        // Note: The original code reads `t` but comments it out.
        // `ll t = 1; while(t--) solve();`
        // So we run solve once.
        
        solve();
    }
}
</CODE>