Translate this C++ code to Java code. The main class name should be c_596. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include <string>
#include <iostream>
#include <fstream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
#define LL __int64
#define mod 2015
#define N 200008

using namespace std;
struct node
{
    int x,y,dif;
    bool operator <(const node& xx)const
    {
        return dif<xx.dif;
    }
};
set <node> ss;
set <node> ::iterator it;
int y[100008],w[100008];
struct node2
{
    int x,y;
}ans[100008];
int main()
{
    int n,i,ymax=-1;
    scanf("%d",&n);
    memset(y,-1,sizeof(y));
    for(i=0;i<n;i++)
    {
        int xx,yy;
        scanf("%d%d",&xx,&yy);
        ymax=max(ymax,yy);
        y[yy]=max(y[yy],xx);
    }
    for(i=0;i<n;i++)
        scanf("%d",&w[i]);
    ss.clear();ss.insert((node){y[ymax],ymax,ymax-y[ymax]});
    for(i=ymax-1;i>=0;i--)
        if(y[i]>y[i+1])
            ss.insert((node){y[i],i,i-y[i]});
    for(i=n-1;i>=0;i--)
    {
        it=ss.lower_bound((node){0,0,w[i]});
        if(it!=ss.end()&&(*it).dif==w[i])
        {
            ans[i].x=(*it).x;
            ans[i].y=(*it).y;
            //printf("%d %d\n",(*it).x,(*it).y);
            ss.erase(it);--y[ans[i].y];
            if(ans[i].x>0&&ans[i].x-1>y[ans[i].y+1])
                ss.insert((node){ans[i].x-1,ans[i].y,ans[i].y-ans[i].x+1});
            if(ans[i].y>0&&ans[i].x==y[ans[i].y-1])
                ss.insert((node){ans[i].x,ans[i].y-1,ans[i].y-1-ans[i].x});
        }
        else    break;
    }
    if(i>=0)    puts("NO");
    else
    {
        puts("YES");
        for(i=0;i<n;i++)
            printf("%d %d\n",ans[i].x,ans[i].y);
    }
    return 0;
}

Here is the plan for the translation from C++ to Java.

### Translation Plan

1.  **Headers and Imports**:
    *   C++ headers (`<string>`, `<iostream>`, `<fstream>`, `<queue>`, `<cstring>`, `<algorithm>`, `<cmath>`, `<set>`, `<vector>`) are replaced with standard Java imports (`java.util.*`, `java.io.*`, `java.lang.Math`).
    *   The `#define` macros are replaced with `static final` constants.

2.  **Data Structures**:
    *   **`struct node`**: In C++, this is a struct with a custom comparator. In Java, we create a class `Node` implementing `Comparable<Node>`. The `<` operator becomes `compareTo`.
    *   **`set <node> ss`**: In C++, `std::set` is a balanced binary tree (Red-Black tree) that keeps elements sorted. In Java, we use `TreeSet<Node>`.
    *   **`set <node> ::iterator it`**: C++ iterators are complex. In Java, we access elements directly via the `TreeSet` methods or use an `Iterator<Node>` if needed. Here, since we need to find the lower bound and erase, `TreeSet`'s `lower` and `firstGreaterOrEqual` (or manual iteration) is the equivalent. However, C++ `lower_bound` returns the first element *not less* than the key. In Java `TreeSet`, `ceiling` is equivalent to `lower_bound` (smallest element $\ge$ key).
    *   **Arrays**: `y[]`, `w[]`, `ans[]` are translated to `int[]`. Note that Java arrays are 0-indexed, matching the C++ usage here.
    *   **`memset`**: Replaced with `Arrays.fill`.
    *   **`max`**: Replaced with `Math.max`.

3.  **Input/Output**:
    *   C++ `scanf` and `printf` are replaced with `Scanner` or `BufferedReader` and `System.out.println`/`PrintWriter`. Given the constraints (N=200008), `Scanner` might be slow, but for a general translation, `Scanner` is often sufficient unless strict time limits are specified. To be safe and idiomatic for competitive programming style, `BufferedReader` and `StringTokenizer` are preferred for speed.
    *   `puts` and `printf` are replaced with `System.out.println`.

4.  **Logic Implementation**:
    *   **`main` method**: The logic flow remains identical, adapting variable types and method calls.
    *   **Looping**: C++ `for` loops with initialization and condition are equivalent to Java `for` loops.
    *   **Conditional Logic**: `if` statements remain the same.
    *   **Set Operations**:
        *   `ss.clear()` -> `ss.clear()`.
        *   `ss.insert()` -> `ss.add()`.
        *   `ss.lower_bound(...)` -> `ss.ceiling(...)`.
        *   `ss.erase(it)` -> `ss.remove(element)`.
    *   **Null Checks**: Java requires explicit null checks for collections.

5.  **Incremental Steps**:
    *   Step 1: Define classes and constants.
    *   Step 2: Implement `Node` class.
    *   Step 3: Implement `main` method structure (Input reading).
    *   Step 4: Implement the core algorithm (Set filling, processing, and output).

### Java Code

```java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class c_596 {
    static final int mod = 2015;
    static final int N = 200008;

    static class Node implements Comparable<Node> {
        int x, y, dif;

        @Override
        public int compareTo(Node other) {
            // C++: return dif < xx.dif ? 1 : (dif == xx.dif ? 0 : -1);
            // Java compareTo returns negative if this < other
            if (this.dif < other.dif) return -1;
            if (this.dif > other.dif) return 1;
            return 0;
        }
    }

    static TreeSet<Node> ss = new TreeSet<>();
    static int[] y = new int[100008];
    static int[] w = new int[100008];
    static Node[] ans = new Node[100008];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        StringTokenizer st;

        String line = br.readLine();
        if (line == null) return;
        st = new StringTokenizer(line);
        if (!st.hasMoreTokens()) return;
        
        int n = Integer.parseInt(st.nextToken());

        Arrays.fill(y, -1);
        int ymax = -1;

        for (int i = 0; i < n; i++) {
            line = br.readLine();
            while (line != null && line.trim().isEmpty()) {
                line = br.readLine();
            }
            if (line == null) break;
            st = new StringTokenizer(line);
            int xx = Integer.parseInt(st.nextToken());
            int yy = Integer.parseInt(st.nextToken());
            ymax = Math.max(ymax, yy);
            if (y[yy] < xx) {
                y[yy] = xx;
            }
        }

        for (int i = 0; i < n; i++) {
            line = br.readLine();
            while (line != null && line.trim().isEmpty()) {
                line = br.readLine();
            }
            if (line == null) break;
            st = new StringTokenizer(line);
            w[i] = Integer.parseInt(st.nextToken());
        }

        ss.clear();
        // ss.insert((node){y[ymax],ymax,ymax-y[ymax]})
        Node initNode = new Node();
        initNode.x = y[ymax];
        initNode.y = ymax;
        initNode.dif = ymax - y[ymax];
        ss.add(initNode);

        // for(i=ymax-1;i>=0;i--)
        //     if(y[i]>y[i+1])
        //         ss.insert((node){y[i],i,i-y[i]})
        for (int i = ymax - 1; i >= 0; i--) {
            if (y[i] > y[i + 1]) {
                Node newNode = new Node();
                newNode.x = y[i];
                newNode.y = i;
                newNode.dif = i - y[i];
                ss.add(newNode);
            }
        }

        // for(i=n-1;i>=0;i--)
        for (int i = n - 1; i >= 0; i--) {
            // C++: it=ss.lower_bound((node){0,0,w[i]})
            // Java TreeSet: ceiling returns the least element >= key
            // We need to construct a key with dif >= w[i].
            // Since the comparator sorts by dif, we look for the smallest element with dif >= w[i].
            // However, the C++ lower_bound uses a custom key. 
            // In C++, lower_bound returns the first element where !(*it < key).
            // Here, the key is {0, 0, w[i]}. 
            // Our Node comparison is based on 'dif'. 
            // So we are looking for the first element with dif >= w[i].
            
            // Note: In the C++ code, the key is {0,0,w[i]}. 
            // Since our Node class sorts by 'dif', the x and y don't matter for the comparison logic 
            // relative to the key if we only care about 'dif'.
            // However, to be strictly equivalent to lower_bound, we need to find the first element
            // where !(this < key).
            // This means we want the first element where this.dif >= key.dif.
            
            // Let's create a dummy key
            Node key = new Node();
            key.dif = w[i];
            
            // C++ lower_bound returns iterator to first element >= key
            // Java TreeSet.ceiling returns the least element >= key
            Node it = ss.ceiling(key);

            if (it != null && it.dif == w[i]) {
                ans[i].x = it.x;
                ans[i].y = it.y;
                // printf("%d %d\n",(*it).x,(*it).y);
                
                ss.remove(it);
                y[ans[i].y]--;

                if (ans[i].x > 0 && ans[i].x - 1 > y[ans[i].y + 1]) {
                    Node newNode = new Node();
                    newNode.x = ans[i].x - 1;
                    newNode.y = ans[i].y;
                    newNode.dif = ans[i].y - newNode.x + 1;
                    ss.add(newNode);
                }
                if (ans[i].y > 0 && ans[i].x == y[ans[i].y - 1]) {
                    Node newNode = new Node();
                    newNode.x = ans[i].x;
                    newNode.y = ans[i].y - 1;
                    newNode.dif = ans[i].y - 1 - ans[i].x;
                    ss.add(newNode);
                }
            } else {
                break;
            }
        }

        if (i >= 0) {
            out.println("NO");
        } else {
            out.println("YES");
            for (int i = 0; i < n; i++) {
                out.println(ans[i].x + " " + ans[i].y);
            }
        }

        out.flush();
    }
}
```

<CODE>
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class c_596 {
    static final int mod = 2015;
    static final int N = 200008;

    static class Node implements Comparable<Node> {
        int x, y, dif;

        @Override
        public int compareTo(Node other) {
            // C++: return dif < xx.dif ? 1 : (dif == xx.dif ? 0 : -1);
            // Java compareTo returns negative if this < other
            if (this.dif < other.dif) return -1;
            if (this.dif > other.dif) return 1;
            return 0;
        }
    }

    static TreeSet<Node> ss = new TreeSet<>();
    static int[] y = new int[100008];
    static int[] w = new int[100008];
    static Node[] ans = new Node[100008];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        StringTokenizer st;

        String line = br.readLine();
        if (line == null) return;
        st = new StringTokenizer(line);
        if (!st.hasMoreTokens()) return;
        
        int n = Integer.parseInt(st.nextToken());

        Arrays.fill(y, -1);
        int ymax = -1;

        for (int i = 0; i < n; i++) {
            line = br.readLine();
            while (line != null && line.trim().isEmpty()) {
                line = br.readLine();
            }
            if (line == null) break;
            st = new StringTokenizer(line);
            int xx = Integer.parseInt(st.nextToken());
            int yy = Integer.parseInt(st.nextToken());
            ymax = Math.max(ymax, yy);
            if (y[yy] < xx) {
                y[yy] = xx;
            }
        }

        for (int i = 0; i < n; i++) {
            line = br.readLine();
            while (line != null && line.trim().isEmpty()) {
                line = br.readLine();
            }
            if (line == null) break;
            st = new StringTokenizer(line);
            w[i] = Integer.parseInt(st.nextToken());
        }

        ss.clear();
        // ss.insert((node){y[ymax],ymax,ymax-y[ymax]})
        Node initNode = new Node();
        initNode.x = y[ymax];
        initNode.y = ymax;
        initNode.dif = ymax - y[ymax];
        ss.add(initNode);

        // for(i=ymax-1;i>=0;i--)
        //     if(y[i]>y[i+1])
        //         ss.insert((node){y[i],i,i-y[i]})
        for (int i = ymax - 1; i >= 0; i--) {
            if (y[i] > y[i + 1]) {
                Node newNode = new Node();
                newNode.x = y[i];
                newNode.y = i;
                newNode.dif = i - y[i];
                ss.add(newNode);
            }
        }

        // for(i=n-1;i>=0;i--)
        for (int i = n - 1; i >= 0; i--) {
            // C++: it=ss.lower_bound((node){0,0,w[i]})
            // Java TreeSet: ceiling returns the least element >= key
            // We need to construct a key with dif >= w[i].
            // Since the comparator sorts by 'dif', we look for the smallest element with dif >= w[i].
            
            Node key = new Node();
            key.dif = w[i];
            
            // C++ lower_bound returns iterator to first element >= key
            // Java TreeSet.ceiling returns the least element >= key
            Node it = ss.ceiling(key);

            if (it != null && it.dif == w[i]) {
                ans[i].x = it.x;
                ans[i].y = it.y;
                // printf("%d %d\n",(*it).x,(*it).y);
                
                ss.remove(it);
                y[ans[i].y]--;

                if (ans[i].x > 0 && ans[i].x - 1 > y[ans[i].y + 1]) {
                    Node newNode = new Node();
                    newNode.x = ans[i].x - 1;
                    newNode.y = ans[i].y;
                    newNode.dif = ans[i].y - newNode.x + 1;
                    ss.add(newNode);
                }
                if (ans[i].y > 0 && ans[i].x == y[ans[i].y - 1]) {
                    Node newNode = new Node();
                    newNode.x = ans[i].x;
                    newNode.y = ans[i].y - 1;
                    newNode.dif = ans[i].y - 1 - ans[i].x;
                    ss.add(newNode);
                }
            } else {
                break;
            }
        }

        if (i >= 0) {
            out.println("NO");
        } else {
            out.println("YES");
            for (int i = 0; i < n; i++) {
                out.println(ans[i].x + " " + ans[i].y);
            }
        }

        out.flush();
    }
}
</CODE>