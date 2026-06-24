Translate this C++ code to Java code. The main class name should be b_257. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include<iostream>
using namespace std;
int n,m;
main()
 {cin>>n>>m;if (n>m) swap(n,m);
  cout<<m-1<<" "<<n<<endl;
 }

Here is the plan for translating the C++ code to Java:

1.  **Entry Point**: The C++ code uses `main()` without arguments and without a return type (which defaults to `int` in older standards, but Java requires explicit `public static void main(String[] args)`). I will implement the standard Java entry point.
2.  **Input/Output**:
    *   C++ uses `iostream` and `cin`/`cout`.
    *   Java uses `java.util.Scanner` for input and `System.out.println`/`System.out.print` for output.
3.  **Variables**:
    *   Global variables `n` and `m` in C++ become local variables inside the `main` method in Java.
    *   `int` type remains `int`.
4.  **Logic**:
    *   The logic `cin>>n>>m` becomes `sc.nextInt()` calls.
    *   The logic `if (n>m) swap(n,m)` is equivalent to swapping variables if `n` is greater than `m`. In Java, a simple swap can be done using a temporary variable or by using `Math.min` and `Math.max` to derive the output directly. Since the code prints `m-1` and `n` after the swap (where `m` becomes the larger value and `n` becomes the smaller), I can implement this explicitly or use `Math.min` and `Math.max`.
5.  **Class Structure**:
    *   The class name must be `b_257`.
    *   The class must be declared as `public`.

Here is the Java code:

<CODE>
import java.util.Scanner;

public class b_257 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        
        if (n > m) {
            int temp = n;
            n = m;
            m = temp;
        }
        
        System.out.println((m - 1) + " " + n);
    }
}
</CODE>