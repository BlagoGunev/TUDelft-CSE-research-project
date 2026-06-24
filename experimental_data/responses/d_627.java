Translate this C++ code to Java code. The main class name should be d_627. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
/*----------------
	Author:Longjie Qi
		zhzxcool
	Date:04.20.2016
----------------*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#define maxn 200010
using namespace std;
int a[maxn],dp[maxn],size[maxn],h[maxn<<1],last[maxn<<1],head[maxn],v[maxn],tag[maxn],tot,n,k,l,cnt,ans;

void add(int x,int y)
{
	h[++l] = y;
	last[l] = head[x];
	head[x] = l;
}
void dfs(int x,int fa)
{
	size[x] = 1;
	for (int i = head[x];i;i = last[i])
	{
		int j = h[i];
		if (j == fa) continue;
		dfs(j,x);
		size[x] += size[j];
	}
}
void treedp(int x,int fa)
{
	if (tot>=k) return;
	int pos=0,max1=0,max2=0;
	for (int i = head[x];i;i = last[i])
	{
		int j = h[i];
		if (j == fa) continue;
		treedp(j,x);
		tag[x] += tag[j];
		if (dp[j] == size[j]) pos += dp[j];
		else if (dp[j] > max1) max2 = max1,max1 = dp[j];
		else if (dp[j] > max2) max2 = dp[j];
	}
	if (v[x]) dp[x] = pos+max1+1,tag[x]++;
	else dp[x] = 0;
	if (n-size[x]==cnt-tag[x])
		pos += n-size[x];
	if (v[x]) tot = max(tot,pos+max1+max2+1);
}

int main()
{
	scanf("%d%d",&n,&k);
	for (int i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	for (int i = 1;i < n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	dfs(1,-1);
	for (int L=1,R=1000000;L<=R;)
	{
		int mid =L+R>>1;cnt = 0;
		for (int i = 1;i <= n;i++)
			cnt += (v[i] = a[i]>=mid);
		memset(tag,0,sizeof(tag));
		tot = 0;
		treedp(1,-1);
		if (tot>=k) ans = mid,L = mid+1;
		else R = mid-1;
	}
	printf("%d",ans);
	return 0;
}

Here is the translation plan:

1.  **Includes**: C++ `<cstdio>`, `<algorithm>`, and `<cstring>` map directly to Java `java.io.BufferedReader`, `java.io.InputStreamReader`, `java.io.PrintWriter`, and `java.util.Arrays`.
2.  **Constants**: The `#define maxn 200010` becomes a `static final int` constant.
3.  **Global Variables**: C++ globals are moved to static members of the main class `d_627`.
4.  **Input/Output**: C++ `scanf`/`printf` are replaced with Java's `BufferedReader` and `PrintWriter` for efficiency.
5.  **Logic**:
    *   `add`, `dfs`, and `treedp` are translated directly, adjusting for Java syntax (e.g., `size[x] += size[j]` vs C++'s reference semantics).
    *   The binary search loop in `main` is translated, ensuring the termination condition `L <= R` is handled correctly in Java (unlike C++'s `while` loop logic, Java requires an explicit `while` or `do-while` structure).
    *   `memset` is replaced with `Arrays.fill`.

Here is the Java code:

<CODE>
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class d_627 {
    static final int maxn = 200010;
    static int[] a = new int[maxn];
    static int[] dp = new int[maxn];
    static int[] size = new int[maxn];
    static int[] h = new int[2 * maxn];
    static int[] last = new int[2 * maxn];
    static int[] head = new int[maxn];
    static int[] v = new int[maxn];
    static int[] tag = new int[maxn];
    static int tot, n, k, l, cnt, ans;

    public static void add(int x, int y) {
        h[++l] = y;
        last[l] = head[x];
        head[x] = l;
    }

    public static void dfs(int x, int fa) {
        size[x] = 1;
        for (int i = head[x]; i != 0; i = last[i]) {
            int j = h[i];
            if (j == fa) continue;
            dfs(j, x);
            size[x] += size[j];
        }
    }

    public static void treedp(int x, int fa) {
        if (tot >= k) return;
        int pos = 0;
        int max1 = 0;
        int max2 = 0;
        
        for (int i = head[x]; i != 0; i = last[i]) {
            int j = h[i];
            if (j == fa) continue;
            treedp(j, x);
            tag[x] += tag[j];
            if (dp[j] == size[j]) pos += dp[j];
            else if (dp[j] > max1) {
                max2 = max1;
                max1 = dp[j];
            } else if (dp[j] > max2) {
                max2 = dp[j];
            }
        }
        
        if (v[x] != 0) {
            dp[x] = pos + max1 + 1;
            tag[x]++;
        } else {
            dp[x] = 0;
        }
        
        if (n - size[x] == cnt - tag[x]) {
            pos += n - size[x];
        }
        
        if (v[x] != 0) {
            tot = Math.max(tot, pos + max1 + max2 + 1);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        
        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());
            a[i] = Integer.parseInt(st.nextToken());
        }
        
        for (int i = 1; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            add(x, y);
            add(y, x);
        }
        
        dfs(1, 0);
        
        int L = 1;
        int R = 1000000;
        ans = 0;
        
        while (L <= R) {
            int mid = L + (R - L) / 2;
            cnt = 0;
            for (int i = 1; i <= n; i++) {
                v[i] = (a[i] >= mid) ? 1 : 0;
                cnt += v[i];
            }
            Arrays.fill(tag, 0);
            tot = 0;
            treedp(1, 0);
            
            if (tot >= k) {
                ans = mid;
                L = mid + 1;
            } else {
                R = mid - 1;
            }
        }
        
        out.println(ans);
        out.flush();
    }
}
</CODE>