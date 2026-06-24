Translate this C++ code to Java code. The main class name should be a_1351. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include <bits/stdc++.h>       

using namespace std;

int main(){

int n;

cin>>n; int a,b;

for (int i = 0; i < n; i++)

{

  cin>>a>>b;

  cout<<a+b<<"\n";

}





 

}

Here is the plan for the translation from C++ to Java:

1.  **Includes and Namespaces**: The C++ code uses `#include <bits/stdc++.h>` and `using namespace std;`. In Java, there are no headers to include for standard I/O (they are part of the `java.util` package), and no global namespace to declare. We will simply import `java.util.Scanner`.
2.  **Main Method**: The C++ `main()` function is the entry point. In Java, the entry point is the `public static void main(String[] args)` method.
3.  **Data Types**: C++ uses `int`. Java uses `int` for the same purpose.
4.  **Input/Output**:
    *   `cin` and `cout` in C++ are replaced by `Scanner` and `System.out` in Java.
    *   `cin >> n` becomes `sc.nextLong()` or `sc.nextInt()`. Given the context of competitive programming (implied by the problem style), `nextInt()` is standard for integers, though `nextLong()` is safer if inputs might exceed integer limits. I will use `nextInt()` as it matches the C++ `int` type directly.
    *   `cout << a+b << "\n"` becomes `System.out.println(a + b)`. The `\n` in C++ is equivalent to the `println` method in Java which appends a platform-specific line separator (usually `\n` on Linux/Mac and `\r\n` on Windows).
5.  **Looping**: The C++ `for` loop translates directly to the Java `for` loop structure.
6.  **Class Structure**: The C++ code is procedural (inside `main`). Java requires a class definition. The class name must be `a_1351` as requested.

The logic is simple and sequential, so it can be translated in one go.

```java
import java.util.Scanner;

public class a_1351 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            for (int i = 0; i < n; i++) {
                int a = sc.nextInt();
                int b = sc.nextInt();
                System.out.println(a + b);
            }
        }
    }
}
```

<CODE>
import java.util.Scanner;

public class a_1351 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            System.out.println(a + b);
        }
    }
}
</CODE>