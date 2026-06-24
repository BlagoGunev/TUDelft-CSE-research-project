Translate this C++ code to Java code. The main class name should be a_1384. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main()

{

    ios::sync_with_stdio(0);

    cin.tie(0);

    int t;

    cin>>t;

    while(t--)

    {

        ll n;

        cin>>n;

        ll arr[n];

        for(int i=0;i<n;i++)

        {

            cin>>arr[i];

        }

    string s(200,'a');

    cout<<s<<endl;

    for(int i=0;i<n;i++)

    {

        if(s[arr[i]]=='a')

        {

            s[arr[i]]='b';

        }

        else

        {

            s[arr[i]]='a';

        }

        cout<<s<<endl;

    }

    }

}

Here is the plan for translating the C++ code to Java:

1.  **Header and Includes**:
    *   C++ uses `#include<bits/stdc++.h>`. In Java, we don't need explicit includes for basic IO, but we need to import `java.util.Scanner` or `java.io.*` classes. Since the code uses `cin` and `cout`, `Scanner` is a direct equivalent, though slightly slower than `BufferedReader`. Given the constraints usually associated with competitive programming (implied by the `ios::sync_with_stdio(0)` optimization), `BufferedReader` and `StringTokenizer` are preferred for performance. However, for a direct translation of the logic, `Scanner` is sufficient unless performance is critical. I will use `BufferedReader` to mimic the efficiency of `cin.tie(0)` and `ios::sync_with_stdio(0)`.

2.  **Fast I/O**:
    *   C++: `ios::sync_with_stdio(0); cin.tie(0);`
    *   Java: This optimization is handled by using `BufferedReader` instead of `Scanner` and `System.out` instead of `System.out.println` (though `System.out.println` is usually fine, `PrintWriter` or `StringBuilder` is faster for massive output). I will use `BufferedReader` for input and `PrintWriter` for output to ensure efficiency.

3.  **Data Types**:
    *   C++: `ll` is `long long` (64-bit signed integer).
    *   Java: `long` is the equivalent 64-bit signed integer.

4.  **Variable Declaration and Arrays**:
    *   C++: `ll arr[n]` is a VLA (Variable Length Array), which is not supported in Java.
    *   Java: We must declare an array with a fixed maximum size or an `ArrayList`. Looking at the logic, `arr[n]` is used as an index into a string `s` of size 200. Therefore, `n` will never exceed 200. I will declare `int[] arr` with a size of 200 (or slightly larger for safety) and use it. Alternatively, `ArrayList<Integer>` works, but a primitive array is faster and fits the logic of direct indexing `s[arr[i]]`.

5.  **String Manipulation**:
    *   C++: `string s(200,'a')` creates a string of length 200 initialized to 'a'.
    *   Java: `char[]` is more appropriate here because we need to modify characters in place (`s[arr[i]] = 'b'`). Modifying a `String` is not possible in Java (Strings are immutable). We will use a `char[]` array of size 200 initialized to 'a'.

6.  **Main Class Structure**:
    *   C++: `int main()`
    *   Java: `public class a_1384 { public static void main(String[] args) { ... } }`

7.  **Logic Flow**:
    *   Read `t` (number of test cases).
    *   Loop `t` times.
    *   Read `n`.
    *   Read `n` integers into `arr`.
    *   Print initial string.
    *   Loop through `arr`, toggle characters in the `char` array, and print.

8.  **Incremental Tasks**:
    *   Step 1: Set up the class structure and IO classes.
    *   Step 2: Implement the test case loop.
    *   Step 3: Implement array reading.
    *   Step 4: Implement the character toggling logic.

Here is the resulting Java code:

<CODE>
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class a_1384 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer("");

        String line = br.readLine();
        if (line == null) return;
        st = new StringTokenizer(line);
        if (!st.hasMoreTokens()) return;
        int t = Integer.parseInt(st.nextToken());

        while (t-- > 0) {
            while (!st.hasMoreTokens()) {
                String nextLine = br.readLine();
                if (nextLine == null) return;
                st = new StringTokenizer(nextLine);
            }
            int n = Integer.parseInt(st.nextToken());
            
            int[] arr = new int[n]; // Java arrays are fixed size, but logic holds since indices are < 200
            for (int i = 0; i < n; i++) {
                while (!st.hasMoreTokens()) {
                    String nextLine = br.readLine();
                    if (nextLine == null) return;
                    st = new StringTokenizer(nextLine);
                }
                arr[i] = Integer.parseInt(st.nextToken());
            }

            char[] s = new char[200];
            for (int i = 0; i < 200; i++) {
                s[i] = 'a';
            }
            // Output initial string
            out.write(s);
            out.write('\n');

            for (int i = 0; i < n; i++) {
                // Toggle character
                if (s[arr[i]] == 'a') {
                    s[arr[i]] = 'b';
                } else {
                    s[arr[i]] = 'a';
                }
                // Output current string
                out.write(s);
                out.write('\n');
            }
        }
        out.flush();
    }
}
</CODE>