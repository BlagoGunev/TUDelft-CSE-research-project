Translate this C++ code to Java code. The main class name should be e_627. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long LL;
LL ans,now;
int R,C,n,k;
int x[3005],y[3005];
int lc[3005],rc[3005];
int id[3005],nd[3005],len[3005],pre[3005];
bool cmpx(int a,int b)
{return x[a]<x[b];}

#define val(_x) len[_x]*(pre[_x]==-1?0:y[rc[pre[_x]]])

void Del(int p)
{
	for(int i=0,t=p;i<=k&&t<=n;i++,t=rc[t])
		now-=val(t);
	rc[lc[p]]=rc[p];
	lc[rc[p]]=lc[p];
	p=lc[p];
	now-=val(p);
	len[p]=y[rc[p]]-y[p];
	now+=val(p);
	for(int i=1,t=rc[p];i<=k&&t<=n;i++,t=rc[t])
	{
		pre[t]=pre[t]==-1?-1:lc[pre[t]];
		now+=val(t);
	}
}

int main()
{
	scanf("%d%d%d%d",&R,&C,&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d%d",x+i,y+i),id[i]=i;
	memset(lc,-1,sizeof(lc));
	memset(rc,-1,sizeof(rc));
	sort(id+1,id+n+1,cmpx);
	y[n+1]=C+1;
	for(int i,j=1,p=0;j<=R;j++)
	{
		for(;p<n&&x[id[p+1]]<=j;p++)
		{
			nd[p+1]=id[p+1];
			for(int t=p;t;t--)
				if(y[nd[t+1]]<y[nd[t]])
					swap(nd[t],nd[t+1]);
		} 
		for(i=1;i<p;i++)
			rc[nd[i]]=nd[i+1],lc[nd[i+1]]=nd[i];
		if(p==0)rc[0]=n+1,lc[n+1]=0;
		else
		{
			rc[0]=nd[1],lc[n+1]=nd[p];
			lc[nd[1]]=0,rc[nd[p]]=n+1;
		}
		now=0;
		for(int t=0,w;t<=n;t=rc[t])
		{
			len[t]=y[rc[t]]-y[t];
			w=t;
			for(int ii=0;w!=-1&&ii<k;ii++)
				w=lc[w];
			pre[t]=w;
			now+=len[t]*(w==-1?0:y[rc[pre[t]]]);
		}
		int pl=1;
		for(i=1;i<=j;i++)
		{
			for(;pl<=p&&x[id[pl]]<i;pl++)
				Del(id[pl]);
			ans+=now;
		}
	}
	cout<<ans<<endl;
	return 0;
}

<think>

</think>

### Translation Plan

To translate the provided C++ code to Java, we need to address several language-specific differences:

1.  **I/O Handling**:
    *   C++ uses `scanf` and `printf` (from `<cstdio>`).
    *   Java uses `Scanner` or `BufferedReader` from `java.util` and `java.io`. Given the constraints of competitive programming (often implied by the algorithmic nature), `BufferedReader` and `StringTokenizer` are preferred for performance, but `Scanner` is simpler to implement for this specific logic. I will use `Scanner` for clarity unless the logic suggests heavy I/O, but given the nested loops, `BufferedReader` is safer. However, to keep the code clean and readable while maintaining standard practices, I will use a simple `Scanner` wrapped in the class, noting that for very large inputs in a real contest, `BufferedReader` would be better. *Correction*: Looking at the algorithm complexity ($O(R \cdot (N + K))$), standard `Scanner` might be too slow if $N$ is large. I will use `BufferedReader` and `StringTokenizer` for robustness.

2.  **Data Types**:
    *   C++ uses `long long` for `ans` and `now`.
    *   Java uses `long` for these variables.

3.  **Arrays**:
    *   C++ arrays are fixed size (`int x[3005]`).
    *   Java requires explicit array instantiation (`int[] x = new int[3005]`).

4.  **Pointers and References**:
    *   C++ code manipulates pointers directly (e.g., `t=rc[t]`, `p=lc[p]`).
    *   Java does not have pointers. We must simulate pointer traversal using indices in arrays. The logic remains identical since the code already uses indices (`t`, `i`, `p`) rather than raw pointers.

5.  **Macros**:
    *   C++ `#define val(_x) ...` is a preprocessor macro.
    *   Java requires a `private static final` method or a local function (in Java 8+). Since the macro is simple and side-effect free, a `static` method `val(int x)` is the direct equivalent.

6.  **Namespace**:
    *   C++ `using namespace std;`.
    *   Java requires fully qualified names or `import` statements. We will use `import java.util.*;` and `import java.io.*;`.

7.  **Main Method**:
    *   C++ `int main()`.
    *   Java `public static void main(String[] args)`.

8.  **Incremental Tasks**:
    *   **Step 1**: Set up the class structure, imports, and I/O helper.
    *   **Step 2**: Define global variables and arrays with appropriate sizes and types.
    *   **Step 3**: Translate the `cmpx` comparator (used in `Arrays.sort`).
    *   **Step 4**: Translate the `val` macro into a static method.
    *   **Step 5**: Translate the `Del` function (recursive/deletion logic).
    *   **Step 6**: Translate the `main` method logic, ensuring loop bounds and array indexing match the C++ version (remembering C++ arrays are 0-indexed in Java, but the logic uses 1-based indexing for `id` and `nd`, so we must respect that).
    *   **Step 7**: Finalize output and ensure class name is `e_627`.

### Code Translation

<CODE>
import java.io.*;
import java.util.*;

public class e_627 {
    static final int MAXN = 3005;
    static long ans, now;
    static int R, C, n, k;
    static int[] x = new int[MAXN];
    static int[] y = new int[MAXN];
    static int[] lc = new int[MAXN];
    static int[] rc = new int[MAXN];
    static int[] id = new int[MAXN];
    static int[] nd = new int[MAXN];
    static int[] len = new int[MAXN];
    static int[] pre = new int[MAXN];

    static boolean cmpx(int a, int b) {
        return x[a] < x[b];
    }

    static long val(int _x) {
        return (long) len[_x] * (pre[_x] == -1 ? 0 : y[rc[pre[_x]]]);
    }

    static void Del(int p) {
        for (int i = 0, t = p; i <= k && t <= n; i++, t = rc[t]) {
            now -= val(t);
        }
        rc[lc[p]] = rc[p];
        lc[rc[p]] = lc[p];
        p = lc[p];
        now -= val(p);
        len[p] = y[rc[p]] - y[p];
        now += val(p);
        for (int i = 1, t = rc[p]; i <= k && t <= n; i++, t = rc[t]) {
            pre[t] = (pre[t] == -1) ? -1 : lc[pre[t]];
            now += val(t);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        if (!st.hasMoreTokens()) return;
        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());
            x[i] = Integer.parseInt(st.nextToken());
            y[i] = Integer.parseInt(st.nextToken());
            id[i] = i;
        }

        Arrays.fill(lc, -1);
        Arrays.fill(rc, -1);
        Arrays.sort(id, 1, n + 1, new Comparator<Integer>() {
            public int compare(Integer a, Integer b) {
                return cmpx(a, b);
            }
        });

        y[n + 1] = C + 1;

        for (int j = 1; j <= R; j++) {
            int p = 0;
            // Find all points with x <= j
            while (p < n && x[id[p + 1]] <= j) {
                p++;
            }

            // Sort the subset of points by y-coordinate
            for (int i = 1; i <= p; i++) {
                nd[i] = id[i];
            }
            // Insertion sort for stability or simple bubble sort logic based on y
            for (int t = p; t > 1; t--) {
                int temp = nd[t];
                int idx = t;
                while (idx > 1 && y[nd[idx - 1]] > y[temp]) {
                    nd[idx] = nd[idx - 1];
                    idx--;
                }
                nd[idx] = temp;
            }

            // Build the doubly linked list structure from sorted array nd
            for (int i = 1; i < p; i++) {
                rc[nd[i]] = nd[i + 1];
                lc[nd[i + 1]] = nd[i];
            }

            if (p == 0) {
                rc[0] = n + 1;
                lc[n + 1] = 0;
            } else {
                rc[0] = nd[1];
                lc[n + 1] = nd[p];
                lc[nd[1]] = 0;
                rc[nd[p]] = n + 1;
            }

            now = 0;
            // Traverse the linked list
            for (int t = 0; t != -1; t = rc[t]) {
                len[t] = y[rc[t]] - y[t];
                // Find the previous node in the linked list (going backwards k steps)
                int w = t;
                for (int ii = 0; w != -1 && ii < k; ii++) {
                    w = lc[w];
                }
                pre[t] = w;
                now += val(t);
            }

            // Calculate answer for this row
            int pl = 1;
            for (int i = 1; i <= j; i++) {
                while (pl <= p && x[id[pl]] < i) {
                    Del(id[pl]);
                    pl++;
                }
                ans += now;
            }
        }

        System.out.println(ans);
    }
}
</CODE>