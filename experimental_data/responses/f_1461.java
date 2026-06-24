Translate this C++ code to Java code. The main class name should be f_1461. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include <iostream>

#include <vector>

using namespace std;

int a[100005],QWQ[5];

char ans[100005];

int dp[100005],qzh[100005],lst[100005];

vector <pair<int,int> > v;

inline void solve(int l,int r)

{

	//cout << l << "***" << r << '\n';

	if(l>r) return ;

	if(a[l]==1)

	{

		ans[l]='+';

		solve(l+1,r);

		return ;

	}

	if(a[r]==1)

	{

		ans[r-1]='+';

		solve(l,r-1);

		return ;

	}

	int p=1;

	for(int i=l;i<=r;i++)

	{

		p*=a[i];

		if(p>1e7)

		{

			for(int j=l;j<r;j++)

				ans[j]='*';

			return ;

		}

	}

	qzh[l-1]=1;

	qzh[l]=a[l];

	for(int i=l+1;i<=r;i++)

		qzh[i]=qzh[i-1]*a[i];

	v.clear();

	int cnt=0;

	for(int i=l;i<=r;i++)

	{

		if(a[i]==1) ++cnt;

		else

		{

			v.push_back({i-cnt-1,cnt});

			cnt=0;

			for(auto t:v)

			{

				dp[i]=max(dp[i],t.second+dp[t.first]+qzh[i]/qzh[t.first]);

				if(dp[i]==t.second+dp[t.first]+qzh[i]/qzh[t.first])

					lst[i]=t.first;

			}

		}

	}

	//cout << dp[r] << "\n";

	int now=r;

	while(1)

	{

		int t=lst[now],flag=0;

	//	cout << now << " " << t << "\n";

		if(t<l)

		{

			for(int i=t+1;i<now;i++) ans[i]='*';

			break;

		}

		for(int i=t;i<now;i++)

		{

			if(flag) ans[i]='*';

			else ans[i]='+';

			if(a[i+1]>1) flag=1;

		}

		now=t;

	}

}

int main(int argc, char** argv) {

	int n;

	cin >> n;

	for(int i=1;i<=n;i++)

		cin >> a[i];

	string s;

	cin >> s;

	for(auto t:s)

	{

		if(t=='+') QWQ[0]=1;

		if(t=='-') QWQ[1]=1;

		if(t=='*') QWQ[2]=1; 

	}

	if(QWQ[0]==1) QWQ[1]=0;

	if(!QWQ[0]&&!QWQ[1])

	{

		cout << a[1];

		for(int i=2;i<=n;i++)

			cout << "*" << a[i];

		return 0;

	}

	if(!QWQ[0]&&!QWQ[2])

	{

		cout << a[1];

		for(int i=2;i<=n;i++)

			cout << "-" << a[i];

		return 0;

	}

	if(!QWQ[1]&&!QWQ[2])

	{

		cout << a[1];

		for(int i=2;i<=n;i++)

			cout << "+" << a[i];

		return 0;

	}

	if(QWQ[1]&&QWQ[2])

	{

		int flag=0;

		if(!a[1])

		{

			cout << a[1];

			for(int i=2;i<=n;i++)

				cout << "*" << a[i];

			return 0;

		}

		cout << a[1];

		for(int i=2;i<=n;i++)

		{

			if(flag||a[i]) cout << "*" << a[i];

			else

			{

				flag=1;

				cout << "-" << a[i];

			}

		}

		return 0;

	}

	int lst=1;

	for(int i=1;i<=n;i++)

	{

		if(!a[i])

		{

			ans[i-1]=ans[i]='+';

			solve(lst,i-1),lst=i+1;

		}

	}

	solve(lst,n);

	ans[n]=' ';

	for(int i=1;i<=n;i++)

	{

		cout << a[i];

		if(i!=n) cout << ans[i];

	}

	return 0;

}

Here is the plan for the translation from C++ to Java:

### Translation Plan

1.  **Namespace and Imports**:
    *   The C++ code uses `using namespace std;` and includes `<iostream>`, `<vector>`. In Java, we must import `java.util.*` and `java.io.*`. We will use fully qualified names or specific imports (`Scanner`, `System`, `ArrayList`) instead of `std::`.

2.  **Arrays**:
    *   C++ uses static arrays (`int a[100005]`, etc.). Java does not support static arrays with fixed sizes for dynamic allocation in the same way. We will use `int[]` arrays with the necessary size (e.g., `new int[100005]`). Since the input size `n` is read at runtime, we should ideally size the arrays based on `n` (e.g., `n + 5`), but to strictly follow the provided C++ logic which allocates a large fixed buffer, we will use a sufficiently large fixed size (e.g., `100005`) or `n + 5` if we assume `n` fits within reasonable bounds. Given the constraints of competitive programming usually implied by `100005`, `new int[n+5]` is safer and more Java-idiomatic, but to mirror the C++ static array exactly, I will use a large fixed size constant `MAX = 100005`.

3.  **Structures and Objects**:
    *   C++ `pair<int, int>` is used in `vector<pair<int,int>>`. Java does not have a built-in `pair` class in `java.util`. We will create a simple static inner class `Pair` or use a `long` to store both values (since `n` is small, `long` can store two `int`s packed together, or just a custom class is clearer). A custom static class `Pair` is the most readable approach.
    *   C++ `vector` becomes Java `ArrayList`.

4.  **I/O Handling**:
    *   `cin` and `cout` are replaced by `java.util.Scanner` (`nextInt()`, `next()`).
    *   `endl` or `\n` is replaced by `System.out.println()` or `System.out.print()`.

5.  **Logic Translation**:
    *   `inline` keyword is ignored (Java doesn't support it).
    *   `vector.clear()` becomes `list.clear()`.
    *   `push_back({i, j})` becomes `list.add(new Pair(i, j))`.
    *   `a[l] == 1` checks remain the same.
    *   The logic inside `solve` and `main` remains identical, just syntax adjusted.

6.  **Incremental Tasks**:
    *   Step 1: Define constants and arrays.
    *   Step 2: Implement the `Pair` helper class.
    *   Step 3: Implement the `solve` method (recursive).
    *   Step 4: Implement the `main` method (input parsing, logic branching, output).

### Code Translation

<CODE>
import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;

public class f_1461 {

    // Constants and Arrays (Mirroring C++ static arrays)
    // Using n + 5 or a fixed large size to accommodate indices up to 100005
    private static final int MAX = 100005;
    private static int[] a = new int[MAX];
    private static int[] QWQ = new int[MAX];
    private static char[] ans = new char[MAX];
    private static int[] dp = new int[MAX];
    private static int[] qzh = new int[MAX];
    private static int[] lst = new int[MAX];
    
    // Helper class to replace C++ pair<int, int>
    private static class Pair {
        int first;
        int second;
        Pair(int f, int s) {
            this.first = f;
            this.second = s;
        }
    }

    private static List<Pair> v = new ArrayList<>();

    private static void solve(int l, int r) {
        // cout << l << "***" << r << '\n'; // Commented out as per C++
        
        if (l > r) return;
        
        if (a[l] == 1) {
            ans[l] = '+';
            solve(l + 1, r);
            return;
        }
        
        if (a[r] == 1) {
            ans[r - 1] = '+';
            solve(l, r - 1);
            return;
        }
        
        int p = 1;
        for (int i = l; i <= r; i++) {
            p *= a[i];
            if (p > 10000000) { // 1e7
                for (int j = l; j < r; j++) {
                    ans[j] = '*';
                }
                return;
            }
        }
        
        qzh[l - 1] = 1;
        qzh[l] = a[l];
        for (int i = l + 1; i <= r; i++) {
            qzh[i] = qzh[i - 1] * a[i];
        }
        
        v.clear();
        int cnt = 0;
        
        for (int i = l; i <= r; i++) {
            if (a[i] == 1) {
                cnt++;
            } else {
                v.add(new Pair(i - cnt - 1, cnt));
                cnt = 0;
                
                for (Pair t : v) {
                    int val = t.second + dp[t.first] + qzh[i] / qzh[t.first];
                    if (val > dp[i]) {
                        dp[i] = val;
                        lst[i] = t.first;
                    }
                }
            }
        }
        
        int now = r;
        while (true) {
            int t = lst[now];
            // cout << now << " " << t << "\n";
            
            if (t < l) {
                for (int i = t + 1; i < now; i++) {
                    ans[i] = '*';
                }
                break;
            }
            
            boolean flag = false;
            for (int i = t; i < now; i++) {
                if (flag) {
                    ans[i] = '*';
                } else {
                    ans[i] = '+';
                }
                if (a[i + 1] > 1) {
                    flag = true;
                }
            }
            
            now = t;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        if (!sc.hasNextInt()) return;
        int n = sc.nextInt();
        
        for (int i = 1; i <= n; i++) {
            a[i] = sc.nextInt();
        }
        
        String s = sc.next();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == '+') QWQ[0] = 1;
            else if (c == '-') QWQ[1] = 1;
            else if (c == '*') QWQ[2] = 1;
        }
        
        // Logic from C++ main block
        if (QWQ[0] == 1) QWQ[1] = 0;
        if (!QWQ[0] && !QWQ[1]) {
            System.out.print(a[1]);
            for (int i = 2; i <= n; i++) {
                System.out.print("*" + a[i]);
            }
            System.out.println();
            return;
        }
        
        if (!QWQ[0] && !QWQ[2]) {
            System.out.print(a[1]);
            for (int i = 2; i <= n; i++) {
                System.out.print("-" + a[i]);
            }
            System.out.println();
            return;
        }
        
        if (!QWQ[1] && !QWQ[2]) {
            System.out.print(a[1]);
            for (int i = 2; i <= n; i++) {
                System.out.print("+" + a[i]);
            }
            System.out.println();
            return;
        }
        
        if (QWQ[1] && QWQ[2]) {
            boolean flag = false;
            if (a[1] == 0) {
                System.out.print(a[1]);
                for (int i = 2; i <= n; i++) {
                    System.out.print("*" + a[i]);
                }
                System.out.println();
                return;
            }
            
            System.out.print(a[1]);
            for (int i = 2; i <= n; i++) {
                if (flag || a[i] == 0) {
                    System.out.print("*" + a[i]);
                } else {
                    flag = true;
                    System.out.print("-" + a[i]);
                }
            }
            System.out.println();
            return;
        }
        
        int lst = 1;
        for (int i = 1; i <= n; i++) {
            if (a[i] == 0) {
                ans[i - 1] = '+';
                ans[i] = '+';
                solve(lst, i - 1);
                lst = i + 1;
            }
        }
        
        solve(lst, n);
        ans[n] = ' ';
        
        for (int i = 1; i <= n; i++) {
            System.out.print(a[i]);
            if (i != n) {
                System.out.print(ans[i]);
            }
        }
        System.out.println();
    }
}
</CODE>