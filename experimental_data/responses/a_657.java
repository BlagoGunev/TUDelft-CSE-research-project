Translate this C++ code to Java code. The main class name should be a_657. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef long long llint;
typedef pair<int, int> pii;

int n, d, h;

int main(void) {

  scanf("%d%d%d", &n, &d, &h);

  if (d > 2 * h || d < h) {
    printf("-1\n");
    return 0;
  }

  if (h == 1) {
    if (d == 1 && n != 2) {
      printf("-1\n");
      return 0;
    }
    for (int i = 2; i <= n; ++i)
      printf("1 %d\n", i);
    return 0;
  }

  int curr = 2;
  for (int i = 0; i < h; ++i) {
    printf("%d %d\n", curr - 1, curr);
    ++curr;
  }
  
  int prev = 1;
  for (int i = 0; i < d - h; ++i) {
    printf("%d %d\n", prev, curr);
    prev = curr; ++curr;
  }

  while (curr <= n) 
    printf("2 %d\n", curr++);

  return 0;

}

### Plan for C++ to Java Translation

1.  **Header and Includes:**
    *   Remove C++ specific headers (`#include <...>`) and replace them with Java standard library imports (`java.util.*`, `java.io.*`).
    *   The C++ code uses `cstdio` (`scanf`, `printf`) and `iostream`. In Java, we will use `java.io.BufferedReader` and `java.io.PrintWriter` (or `System.out`) for I/O to ensure efficiency and avoid the overhead of `Scanner` which is often too slow for competitive programming tasks (implied by the logic).

2.  **Typedefs:**
    *   `typedef long long llint;` -> Java `long`.
    *   `typedef pair<int, int> pii;` -> Java `int[]` or a custom class `Pair`. Given the usage is only for reading input, `int[]` is sufficient, but since `n` is `int`, we don't strictly need `llint` for the main logic variables (they are `int`), but we should define the types clearly.

3.  **Variables:**
    *   Global variables `n`, `d`, `h` are fine in C++, but in Java, they should be local variables inside the `main` method or class members. We will keep them as local variables to the `main` method for better encapsulation.

4.  **Logic Translation:**
    *   `scanf("%d%d%d", &n, &d, &h)` -> `StringTokenizer` parsing from `BufferedReader`.
    *   `printf` -> `PrintWriter.println` or `System.out.println`.
    *   `if`/`else` logic remains identical.
    *   Loop structures (`for`, `while`) remain identical.

5.  **Class Structure:**
    *   The class name must be `a_657`.
    *   The `main` method signature changes to `public static void main(String[] args)`.

6.  **Incremental Tasks:**
    *   Step 1: Set up class structure and imports.
    *   Step 2: Implement input reading.
    *   Step 3: Implement the condition checks (`d > 2*h`, `d < h`, `h==1`).
    *   Step 4: Implement the printing logic for the three loops.

### Java Code

```java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class a_657 {

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        int n = Integer.parseInt(tokenizer.nextToken());
        int d = Integer.parseInt(tokenizer.nextToken());
        int h = Integer.parseInt(tokenizer.nextToken());

        if (d > 2 * h || d < h) {
            out.println("-1");
            out.flush();
            return;
        }

        if (h == 1) {
            if (d == 1 && n != 2) {
                out.println("-1");
                out.flush();
                return;
            }
            for (int i = 2; i <= n; ++i)
                out.println("1 " + i);
            out.flush();
            return;
        }

        int curr = 2;
        for (int i = 0; i < h; ++i) {
            out.println((curr - 1) + " " + curr);
            ++curr;
        }
        
        int prev = 1;
        for (int i = 0; i < d - h; ++i) {
            out.println(prev + " " + curr);
            prev = curr;
            ++curr;
        }

        while (curr <= n) {
            out.println("2 " + curr);
            ++curr;
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
import java.util.StringTokenizer;

public class a_657 {

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        
        String line = reader.readLine();
        if (line == null || line.trim().isEmpty()) {
            return;
        }
        StringTokenizer tokenizer = new StringTokenizer(line);
        int n = Integer.parseInt(tokenizer.nextToken());
        int d = Integer.parseInt(tokenizer.nextToken());
        int h = Integer.parseInt(tokenizer.nextToken());

        if (d > 2 * h || d < h) {
            out.println("-1");
            out.flush();
            return;
        }

        if (h == 1) {
            if (d == 1 && n != 2) {
                out.println("-1");
                out.flush();
                return;
            }
            for (int i = 2; i <= n; ++i)
                out.println("1 " + i);
            out.flush();
            return;
        }

        int curr = 2;
        for (int i = 0; i < h; ++i) {
            out.println((curr - 1) + " " + curr);
            ++curr;
        }
        
        int prev = 1;
        for (int i = 0; i < d - h; ++i) {
            out.println(prev + " " + curr);
            prev = curr;
            ++curr;
        }

        while (curr <= n) {
            out.println("2 " + curr);
            ++curr;
        }

        out.flush();
    }
}
</CODE>