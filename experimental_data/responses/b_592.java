Translate this C++ code to Java code. The main class name should be b_592. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include <iostream>

using namespace std;

long long n;

int main(){

    cin>>n;

    cout<<(n-2)*(n-2);

}

<think>

</think>

### Translation Plan

1.  **Header Inclusion**:
    *   C++: `#include <iostream>`
    *   Java: `import java.util.Scanner;` (Since `cin` and `cout` are used for input/output, we need `Scanner` for input and `System.out` for output).

2.  **Namespace**:
    *   C++: `using namespace std;`
    *   Java: Not applicable directly, but we will use `java.util.Scanner` explicitly.

3.  **Variable Declaration**:
    *   C++: `long long n;` (64-bit integer)
    *   Java: `long n;` (Java's `long` is 64-bit, equivalent to C++ `long long`).

4.  **Main Function**:
    *   C++: `int main(){ ... }`
    *   Java: `public static void main(String[] args) { ... }`

5.  **Input/Output Logic**:
    *   C++: `cin >> n;`
    *   Java: `Scanner sc = new Scanner(System.in); long n = sc.nextLong();`
    *   C++: `cout << (n-2)*(n-2);`
    *   Java: `System.out.println((n - 2) * (n - 2));` (Added `println` to ensure a newline is printed, which is standard practice, though `print` would technically match the C++ behavior if no newline was intended, usually competitive programming solutions expect a newline).

6.  **Incremental Tasks**:
    *   Step 1: Set up the class structure and imports.
    *   Step 2: Declare the variable `n`.
    *   Step 3: Implement input reading.
    *   Step 4: Implement the calculation and output.
    *   Step 5: Combine into the final file.

### Java Code

<CODE>
import java.util.Scanner;

public class b_592 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        System.out.println((n - 2) * (n - 2));
    }
}
</CODE>