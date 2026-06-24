Translate this C++ code to Java code. The main class name should be a_234. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include <bits/stdc++.h>

using namespace std;

string s; int n;

int main(){

  freopen("input.txt", "r", stdin);

  freopen("output.txt", "w", stdout);

  scanf("%d", &n);  cin >> s;

  for(int i=0; i<n/2; i++){

    if(s[i] == s[i + n/2])printf("%d %d\n", i+1, i+1+n/2);

    else{if(s[i] == 'L') printf("%d %d\n", i+1, i+1+n/2);

      else printf("%d %d\n", i+1+n/2, i+1);}

  }

}

Here is the plan for translating the C++ code to Java:

1.  **Header and Imports**: The C++ code includes `<bits/stdc++.h>`, which is a non-standard header containing all standard libraries. In Java, this corresponds to importing specific classes. The code uses `String`, `Scanner`, and standard I/O, so we need `java.util.Scanner` and `java.io.*` (or specific IO classes).
2.  **Class Structure**: C++ uses `main` function directly. Java requires a class definition. The requested class name is `a_234`.
3.  **Input/Output (I/O)**:
    *   The C++ code uses `freopen` to redirect standard input and output to files (`input.txt` and `output.txt`). In Java, we can achieve this by opening a `File` object and wrapping it in a `BufferedReader` and `BufferedWriter` (or `PrintWriter`), or simply using `Scanner(System.in)` and `System.out` if the environment handles the file redirection differently. However, to strictly mimic the C++ behavior of reading from `input.txt` and writing to `output.txt`, we should explicitly open these files.
    *   `scanf("%d", &n)` reads an integer. This translates to `scanner.nextInt()`.
    *   `cin >> s` reads a string. This translates to `scanner.next()`.
    *   `printf` statements translate to `System.out.println` or `PrintWriter.println`.
4.  **Logic**:
    *   `int n` and `string s` are local variables in C++ (in `main`). In Java, they should be instance variables or local variables inside the `main` method.
    *   The loop `for(int i=0; i<n/2; i++)` translates directly to Java.
    *   The logic inside the loop compares characters `s[i]` and `s[i + n/2]`. In Java, strings are objects, so `s.charAt(i)` is used.
5.  **Incremental Tasks**:
    *   Define the class structure and imports.
    *   Set up file redirection (simulating `freopen`).
    *   Read inputs (`n` and `s`).
    *   Implement the loop and conditional logic.
    *   Print results.

Here is the resulting Java code:

<CODE>
import java.util.Scanner;
import java.io.PrintWriter;
import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;

public class a_234 {
    public static void main(String[] args) throws IOException {
        // Simulating freopen("input.txt", "r", stdin);
        Scanner scanner = new Scanner(new FileInputStream("input.txt"));
        
        // Simulating freopen("output.txt", "w", stdout);
        PrintWriter out = new PrintWriter(new BufferedOutputStream(new FileOutputStream("output.txt")));

        // Reading inputs
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            if (scanner.hasNext()) {
                String s = scanner.next();
                
                // Logic translation
                // C++: for(int i=0; i<n/2; i++)
                for (int i = 0; i < n / 2; i++) {
                    // C++: if(s[i] == s[i + n/2])
                    if (s.charAt(i) == s.charAt(i + n / 2)) {
                        // C++: printf("%d %d\n", i+1, i+1+n/2);
                        out.println((i + 1) + " " + (i + 1 + n / 2));
                    } else {
                        // C++: if(s[i] == 'L') printf("%d %d\n", i+1, i+1+n/2);
                        if (s.charAt(i) == 'L') {
                            out.println((i + 1) + " " + (i + 1 + n / 2));
                        } else {
                            // C++: else printf("%d %d\n", i+1+n/2, i+1);
                            out.println((i + 1 + n / 2) + " " + (i + 1));
                        }
                    }
                }
            }
        }
        
        out.flush();
    }
}
</CODE>