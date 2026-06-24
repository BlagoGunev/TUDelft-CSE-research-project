Translate this C++ code to Java code. The main class name should be e_292. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <string>

using namespace std;

int tree[300000];
int p;

void upd(int i,int j,int x)
{
    i+=p;
    j+=p;
    while(i<=j)
    {
        if(i%2){tree[i]=x;i++;}
        if(~j%2){tree[j]=x;j--;}
        i/=2;
        j/=2;
    }
}

int n,m,i,j,ma;

struct T
{
    int i,j,k;
}t;

vector<T>v;
int a[200000],b[200000];

int main()
{
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(j=0;j<n;j++)
        scanf("%d",&b[j]);
    for(p=1;p<n;p+=p);
    while(m--)
    {
        scanf("%d",&i);
        if(i==1)
        {
            scanf("%d%d%d",&t.i,&t.j,&t.k);
            t.i--;
            t.j--;
            v.push_back(t);
            upd(t.j,t.j+t.k-1,v.size());
        }
        else
        {
            scanf("%d",&i);
            j=i-1;
            i+=p-1;
            ma=0;
            for(;i;i/=2)
                if(tree[i]>ma)
                    ma=tree[i];
            if(!ma)
                printf("%d\n",b[j]);
            else
            {
                t=v[ma-1];
                printf("%d\n",a[j-t.j+t.i]);
            }
        }
    }
    return 0;
}
/*
5 100
1 2 3 4 5
6 7 8 9 0
1 1 3 2
1 1 1 3
*/
/*
6 7
1 2 3 4 5
6 7 8 9 10
1 1 3 2
1 1 1 3
*/

Here is the plan for the translation from C++ to Java:

1.  **Class Structure**: The C++ `main` function becomes the `main` method inside a public class named `e_292`.
2.  **Global Variables**: C++ global variables (`tree`, `p`, `n`, `m`, `i`, `j`, `ma`, `v`, `a`, `b`, `t`) need to be moved into the class instance or static fields. Since they are accessed directly in `main` and helper functions, making them static fields is appropriate.
3.  **Data Structures**:
    *   `vector<T> v` translates to `ArrayList<T> v` in Java.
    *   `tree` array remains an `int[]`.
    *   `T` struct translates to a `class T` with public fields.
4.  **Input/Output**:
    *   `scanf` and `printf` are replaced by a custom `FastScanner` class or standard `BufferedReader` + `StringTokenizer` to ensure efficiency, as `Scanner` is often too slow for competitive programming contexts (implied by the `scanf` usage). I will implement a `Scanner` class using `BufferedReader` to handle the input parsing.
    *   Output is handled via `PrintWriter` or `StringBuilder` to match `printf` efficiency.
5.  **Logic Translation**:
    *   The `upd` function is translated to a static method `upd`.
    *   The `main` method logic is preserved, ensuring 0-based indexing adjustments are handled correctly (C++ code does `t.i--; t.j--;` after reading 1-based input).
    *   The loop `for(p=1;p<n;p+=p)` is translated directly.
6.  **Incremental Tasks**:
    *   Define the class and static variables.
    *   Implement the `T` class.
    *   Implement the `upd` method.
    *   Implement the `main` method with `BufferedReader`.
    *   Implement the `Scanner` helper class.

```java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class e_292 {

    static int[] tree;
    static int p;
    static int n, m, i, j, ma;

    static class T {
        int i, j, k;
    }

    static ArrayList<T> v;
    static int[] a;
    static int[] b;

    // Helper class for fast input reading
    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    String line = br.readLine();
                    if (line == null) return null;
                    st = new StringTokenizer(line);
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            String s = next();
            if (s == null) return 0; // Or throw exception
            return Integer.parseInt(s);
        }
    }

    public static void upd(int i, int j, int x) {
        i += p;
        j += p;
        while (i <= j) {
            if ((i % 2) != 0) {
                tree[i] = x;
                i++;
            }
            if ((j & 1) == 0) { // ~j % 2 in C++ checks if j is odd (since j is >= 0). In Java, j & 1 checks the LSB.
                // C++: ~j % 2 is 1 if j is even, 0 if j is odd.
                // Java: j % 2 is 0 if j is even, 1 if j is odd.
                // The condition ~j % 2 == 1 corresponds to j % 2 == 0.
                // So we check if j is even.
                tree[j] = x;
                j--;
            }
            i /= 2;
            j /= 2;
        }
    }

    public static void main(String[] args) {
        FastScanner sc = new FastScanner();
        PrintWriter out = new PrintWriter(System.out);

        try {
            String s = sc.next();
            if (s == null) return;
            n = sc.nextInt();
            m = sc.nextInt();

            a = new int[n];
            b = new int[n];

            for (int k = 0; k < n; k++) {
                a[k] = sc.nextInt();
            }
            for (int k = 0; k < n; k++) {
                b[k] = sc.nextInt();
            }

            p = 1;
            while (p < n) {
                p += p;
            }

            // Initialize tree array. Size needs to be sufficient for the segment tree.
            // Max index accessed is roughly 2*n.
            tree = new int[2 * n];
            // tree is initialized to 0 by default in Java, which matches C++ global int array behavior.

            for (int k = 0; k < m; k++) {
                i = sc.nextInt();
                if (i == 1) {
                    t = new T();
                    t.i = sc.nextInt();
                    t.j = sc.nextInt();
                    t.k = sc.nextInt();
                    
                    // C++ code: t.i--; t.j--;
                    t.i--;
                    t.j--;
                    
                    v.add(t);
                    upd(t.j, t.j + t.k - 1, v.size());
                } else {
                    i = sc.nextInt();
                    j = i - 1;
                    i += p - 1;
                    ma = 0;
                    for (; i > 0; i /= 2) {
                        if (tree[i] > ma) {
                            ma = tree[i];
                        }
                    }
                    
                    if (ma == 0) {
                        out.println(b[j]);
                    } else {
                        T query = v.get(ma - 1);
                        out.println(a[j - query.j + query.i]);
                    }
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }

        out.flush();
    }
}
```