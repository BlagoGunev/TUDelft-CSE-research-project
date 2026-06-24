Translate this C++ code to Java code. The main class name should be a_1523. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include<bits/stdc++.h>

#define x first

#define y second

using namespace std;

using i64=long long;

void solve()

{

  string s;

  int n;

  int m;

  cin>>n;

  cin>>m;

  cin>>s;

  auto ans=s;

  int lastp=-2e9;

  for(int i=0;i<n;i++)

  {   

      if(i&&s[i]!=s[i-1]&&s[i-1]=='1')

      {

        lastp=i-1;

      }

      if(i-lastp<=m)

        ans[i]='1';

  }

  lastp=2e9;

   for(int i=n-1;i>=0;i--)

  {   

      if(i<n-1&&s[i]!=s[i+1]&&s[i+1]=='1')

      {

        lastp=i+1;

      }

      if(lastp-i<=m)

        ans[i]='1';

  }

  int cnt0=0;

  bool beg=true;

  for(int i=0;i<n;i++)

  {

      if(s[i]=='0')

        cnt0++;

      if(i&&s[i]!=s[i-1]&&s[i-1]=='1')

        beg=false;

      if(i>0&&s[i]!=s[i-1]&&s[i-1]=='0')

      {if(cnt0&1&&!beg)

      {

        ans[i-(cnt0+1)/2]='0';

      }

      beg=false;

      cnt0=0;

      }

  }

  cout<<ans<<"\n";

}

int main()

{

  std::ios::sync_with_stdio(false);

  std::cin.tie(nullptr);

  int t;

  cin>>t;

  while(t--)

  solve();

  return 0;

}

Here is the plan for the translation from C++ to Java:

1.  **Headers and Imports**: The C++ code uses `#include<bits/stdc++.h>` which is not available in Java. We will need to import specific classes from the `java.util` package (`Scanner`, `String`, etc.).
2.  **Namespace**: The C++ code uses `using namespace std;`. In Java, we simply use the fully qualified names or import specific classes. We will use `java.util.Scanner` and standard classes.
3.  **Data Types**:
    *   `string` in C++ corresponds to `String` in Java.
    *   `int` and `long long` (defined as `i64`) in C++ correspond to `int` and `long` in Java respectively. However, looking at the usage, `lastp` is initialized to `-2e9` and `2e9`, which fits within a standard Java `int` (range approx $\pm 2 \times 10^9$). So `int` is sufficient for `n`, `m`, and `lastp`.
4.  **IO Optimization**: The C++ code uses `std::ios::sync_with_stdio(false); std::cin.tie(nullptr);` to speed up input/output. In Java, using `Scanner` can be slow for large inputs. While a `BufferedReader` is often preferred for competitive programming, `Scanner` is the direct translation of `cin` and `cout` logic for simple string reading. Given the constraints usually implied by such code (likely CP context), `Scanner` is acceptable for translation unless performance is critical, but standard `Scanner` is the direct semantic equivalent to `cin`.
5.  **Main Class Structure**: The C++ `main` function is the entry point. In Java, we need a `public class` named `a_1523` with a `public static void main(String[] args)` method.
6.  **Solve Method**: The C++ `solve()` function is called inside `main` within a loop. In Java, we can either keep it as a separate static method or inline the logic into `main`. Keeping it as a separate static method `solve()` is cleaner and mirrors the C++ structure.
7.  **Logic Translation**:
    *   `auto ans = s;`: In Java, strings are immutable. We cannot modify `s` directly. We need to create a new `StringBuilder` initialized with the string `s`.
    *   `cin >> n; cin >> m; cin >> s;`: Translated to `sc.nextInt()`, `sc.nextInt()`, `sc.next()`.
    *   `ans[i] = '1'`: Translated to `ans.setCharAt(i, '1')`.
    *   `cnt0 & 1`: Translated to `cnt0 % 2 != 0` or `cnt0 & 1`.
    *   `cout << ans << "\n"`: Translated to `System.out.println(ans.toString())`.

**Incremental Tasks:**
1.  Define the class `a_1523` and the `main` method.
2.  Implement the `solve` method.
3.  Translate input reading (`n`, `m`, `s`).
4.  Translate the first loop (forward pass).
5.  Translate the second loop (backward pass).
6.  Translate the third loop (counting zeros).
7.  Handle the output.

```java
import java.util.Scanner;

public class a_1523 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int t = sc.nextInt();
            while (t-- > 0) {
                solve();
            }
        }
    }

    public static void solve() {
        int n = sc.nextInt();
        int m = sc.nextInt();
        String s = sc.next();

        StringBuilder ans = new StringBuilder(s);

        int lastp = -2000000000;

        for (int i = 0; i < n; i++) {
            if (i > 0 && s.charAt(i) != s.charAt(i - 1) && s.charAt(i - 1) == '1') {
                lastp = i - 1;
            }
            if (i - lastp <= m) {
                ans.setCharAt(i, '1');
            }
        }

        lastp = 2000000000;

        for (int i = n - 1; i >= 0; i--) {
            if (i < n - 1 && s.charAt(i) != s.charAt(i + 1) && s.charAt(i + 1) == '1') {
                lastp = i + 1;
            }
            if (lastp - i <= m) {
                ans.setCharAt(i, '1');
            }
        }

        int cnt0 = 0;
        boolean beg = true;

        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == '0') {
                cnt0++;
            }
            if (i > 0 && s.charAt(i) != s.charAt(i - 1) && s.charAt(i - 1) == '1') {
                beg = false;
            }
            if (i > 0 && s.charAt(i) != s.charAt(i - 1) && s.charAt(i - 1) == '0') {
                if ((cnt0 & 1) == 1 && !beg) {
                    ans.setCharAt(i - (cnt0 + 1) / 2, '0');
                }
                beg = false;
                cnt0 = 0;
            }
        }

        System.out.println(ans.toString());
    }
}
```

```CODE
import java.util.Scanner;

public class a_1523 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int t = sc.nextInt();
            while (t-- > 0) {
                solve();
            }
        }
    }

    public static void solve() {
        int n = sc.nextInt();
        int m = sc.nextInt();
        String s = sc.next();

        StringBuilder ans = new StringBuilder(s);

        int lastp = -2000000000;

        for (int i = 0; i < n; i++) {
            if (i > 0 && s.charAt(i) != s.charAt(i - 1) && s.charAt(i - 1) == '1') {
                lastp = i - 1;
            }
            if (i - lastp <= m) {
                ans.setCharAt(i, '1');
            }
        }

        lastp = 2000000000;

        for (int i = n - 1; i >= 0; i--) {
            if (i < n - 1 && s.charAt(i) != s.charAt(i + 1) && s.charAt(i + 1) == '1') {
                lastp = i + 1;
            }
            if (lastp - i <= m) {
                ans.setCharAt(i, '1');
            }
        }

        int cnt0 = 0;
        boolean beg = true;

        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == '0') {
                cnt0++;
            }
            if (i > 0 && s.charAt(i) != s.charAt(i - 1) && s.charAt(i - 1) == '1') {
                beg = false;
            }
            if (i > 0 && s.charAt(i) != s.charAt(i - 1) && s.charAt(i - 1) == '0') {
                if ((cnt0 & 1) == 1 && !beg) {
                    ans.setCharAt(i - (cnt0 + 1) / 2, '0');
                }
                beg = false;
                cnt0 = 0;
            }
        }

        System.out.println(ans.toString());
    }
}
```
```CODE
import java.util.Scanner;

public class a_1523 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int t = sc.nextInt();
            while (t-- > 0) {
                solve();
            }
        }
    }

    public static void solve() {
        int n = sc.nextInt();
        int m = sc.nextInt();
        String s = sc.next();

        StringBuilder ans = new StringBuilder(s);

        int lastp = -2000000000;

        for (int i = 0; i < n; i++) {
            if (i > 0 && s.charAt(i) != s.charAt(i - 1) && s.charAt(i - 1) == '1') {
                lastp = i - 1;
            }
            if (i - lastp <= m) {
                ans.setCharAt(i, '1');
            }
        }

        lastp = 2000000000;

        for (int i = n - 1; i >= 0; i--) {
            if (i < n - 1 && s.charAt(i) != s.charAt(i + 1) && s.charAt(i + 1) == '1') {
                lastp = i + 1;
            }
            if (lastp - i <= m) {
                ans.setCharAt(i, '1');
            }
        }

        int cnt0 = 0;
        boolean beg = true;

        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == '0') {
                cnt0++;
            }
            if (i > 0 && s.charAt(i) != s.charAt(i - 1) && s.charAt(i - 1) == '1') {
                beg = false;
            }
            if (i > 0 && s.charAt(i) != s.charAt(i - 1) && s.charAt(i - 1) == '0') {
                if ((cnt0 & 1) == 1 && !beg) {
                    ans.setCharAt(i - (cnt0 + 1) / 2, '0');
                }
                beg = false;
                cnt0 = 0;
            }
        }

        System.out.println(ans.toString());
    }
}
```