Translate this C++ code to Java code. The main class name should be b_435. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include<bits/stdc++.h>

using namespace std;

int main()

{

      long long n,i=0,k,j,m=0,a[101],t;

      char ch[101];

      cin>>ch>>k;

      if(!k)

      {

            cout<<ch;

            return 0;

      }

      for(i=0;ch[i];i++)

      {

            a[i+1]=ch[i]-'0';

      }

      //cout<<i<<a[i];

      int y=i;

      int d;

      for(j=1;j<i;j++)

      {

            if(k){

            int v=0;

            if(k<i-j+1)

            d=k+j;

            else

            d=i;

            m=0;

          //  cout<<i-j+1<<" "<<d<<" "<<k;

            for(int r=j;r<=d;r++)

            {

                if(m<a[r])

                {

                      m=a[r];

                      v=r;

                }

            }

            if(j==v)

            continue;

            else if(v)

            {

                  for(int u=v;u>j;u--)

                  {

                        a[u]=a[u-1];

                        k--;

                        //cout<<a[u]<<" ";

                  }

                  a[j]=m;

                  //cout<<a[j]<<"\n";

            }

            }

            /*for(int l=1;l<=i;l++)

            cout<<a[l];

           cout<<"\n";*/

      }

      for(int p=1;p<=i;p++)

      cout<<a[p];

}

```cpp
#include<bits/stdc++.h>

using namespace std;

int main()

{

      long long n,i=0,k,j,m=0,a[101],t;

      char ch[1001];

      cin>>ch>>k;

      if(!k)

      {

            cout<<ch;

            return 0;

    }

      for(i=0;ch[i];i++)

      {

            a[i+1]=ch[i]-'0';

      }

      //cout<<i<<a[i];

      int y=i;

      int d;

      for(j=1;j<i;j++)

      {

            if(k){

            int v=0;

            if(k<i-j+1)

            d=k+j;

            else

            d=i;

            m=0;

          //  cout<<i-j+1<<" "<<d<<" "<<k;

            for(int r=j;r<=d;r++)

            {

                if(m<a[r])

                {

                      m=a[r];

                      v=r;

                }

            }

            if(j==v)

            continue;

            else if(v)

            {

                  for(int u=v;u>j;u--)

                  {

                        a[u]=a[u-1];

                        k--;

                        //cout<<a[u]<<" ";

                  }

                  a[j]=m;

                  //cout<<a[j]<<"\n";

            }

            }

            /*for(int l=1;l<=i;l++)

            cout<<a[l];

           cout<<"\n";*/

      }

      for(int p=1;p<=i;p++)

      cout<<a[p];

}
```

Here is the translation plan and the resulting Java code.

### Translation Plan

1.  **Class Structure**:
    *   **C++**: Uses `int main()` which returns an `int`.
    *   **Java**: Requires a `public class` and a `public static void main(String[] args)` method. The class name is set to `b_435`.

2.  **Headers and Imports**:
    *   **C++**: Uses `#include<bits/stdc++.h>` and `using namespace std;`.
    *   **Java**: No direct equivalent for `bits/stdc++.h`. We must explicitly import necessary classes from `java.util` (e.g., `Scanner`) and `java.io` (e.g., `PrintWriter` for efficient output, though `System.out` is used here).

3.  **Data Types**:
    *   **C++**: `long long` is used for `n` and `k`. `char` arrays are used for `ch`.
    *   **Java**: `long` is used for `n` and `k`. `String` is used instead of `char` arrays for the input string `ch`. This avoids the need for manual memory management (pointers) and simplifies string manipulation.

4.  **Input/Output (I/O)**:
    *   **C++**: Uses `cin` for input and `cout` for output.
    *   **Java**: Uses `Scanner` for input and `System.out` for output.
    *   **Note**: The C++ code reads a string and an integer. In C++, `cin >> ch >> k` reads the string first, then the integer. In Java, `scanner.next()` reads the string and `scanner.nextLong()` reads the integer.

5.  **Memory Management (Arrays)**:
    *   **C++**: `char ch[101]` and `int a[101]` are fixed-size arrays on the stack.
    *   **Java**: Uses `String` for `ch` and `int[] a` for the integer array. Since the maximum size is 101, we can define the array size as 102 to accommodate 1-based indexing (as seen in the logic `a[i+1]`).

6.  **Logic Translation**:
    *   The logic inside `main` is preserved almost 1:1.
    *   C++ `char` arithmetic (`ch[i] - '0'`) is kept.
    *   C++ `for` loops are translated to Java `for` loops.
    *   C++ `if` statements and `continue` statements are translated directly.
    *   The commented-out sections in C++ are kept as comments in Java.

7.  **Incremental Tasks**:
    *   Step 1: Define class and imports.
    *   Step 2: Handle Input (`Scanner`, `String`, `long`).
    *   Step 3: Handle the `if(!k)` check.
    *   Step 4: Convert `char` string to `int` array.
    *   Step 5: Implement the main loop logic (finding `v`, shifting elements, inserting `m`).
    *   Step 6: Output the result.

```java
import java.util.Scanner;

public class b_435 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Reading input
        // In C++, char ch[101] reads a string into a char array. 
        // In Java, we read it as a String.
        String ch = scanner.next();
        
        // Reading k. In C++, k is long long. In Java, we use long.
        long k = scanner.nextLong();

        // C++ Logic: if(!k) { cout<<ch; return 0; }
        if (k == 0) {
            System.out.println(ch);
            return;
        }

        // C++ Logic: Convert char array to int array.
        // C++: a is size 101, 1-based indexing (a[i+1]).
        // Java: a is size 102 (to be safe for 1-based indexing up to 101).
        int[] a = new int[102];
        
        int i = 0;
        // C++: for(i=0;ch[i];i++) a[i+1]=ch[i]-'0';
        // Java: Iterate while i < ch.length()
        while (i < ch.length()) {
            a[i + 1] = ch.charAt(i) - '0';
            i++;
        }
        
        // Update i to be the actual length of the string
        i = ch.length();

        // C++: int y=i; // 'y' is declared but unused in the provided snippet, 
        // so we can ignore it or declare it as unused.
        int y = i;
        
        int d;
        
        // C++: for(j=1;j<i;j++)
        for (int j = 1; j < i; j++) {
            if (k > 0) {
                int v = 0;
                // C++: if(k<i-j+1) d=k+j; else d=i;
                if (k < i - j + 1) {
                    d = k + j;
                } else {
                    d = i;
                }
                
                int m = 0;
                // C++: for(int r=j;r<=d;r++) ...
                for (int r = j; r <= d; r++) {
                    // C++: if(m<a[r])
                    if (m < a[r]) {
                        m = a[r];
                        v = r;
                    }
                }
                
                // C++: if(j==v) continue;
                if (j == v) {
                    continue;
                } 
                // C++: else if(v) { ... }
                else if (v != 0) {
                    // C++: for(int u=v;u>j;u--) a[u]=a[u-1]; k--;
                    for (int u = v; u > j; u--) {
                        a[u] = a[u - 1];
                        k--;
                    }
                    
                    a[j] = m;
                }
            }
        }

        // C++: Output loop
        // for(int p=1;p<=i;p++) cout<<a[p];
        StringBuilder sb = new StringBuilder();
        for (int p = 1; p <= i; p++) {
            sb.append(a[p]);
        }
        System.out.println(sb.toString());
    }
}
```

<CODE>
import java.util.Scanner;

public class b_435 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Reading input
        // In C++, char ch[101] reads a string into a char array. 
        // In Java, we read it as a String.
        String ch = scanner.next();
        
        // Reading k. In C++, k is long long. In Java, we use long.
        long k = scanner.nextLong();

        // C++ Logic: if(!k) { cout<<ch; return 0; }
        if (k == 0) {
            System.out.println(ch);
            return;
        }

        // C++ Logic: Convert char array to int array.
        // C++: a is size 101, 1-based indexing (a[i+1]).
        // Java: a is size 102 (to be safe for 1-based indexing up to 101).
        int[] a = new int[102];
        
        int i = 0;
        // C++: for(i=0;ch[i];i++) a[i+1]=ch[i]-'0';
        // Java: Iterate while i < ch.length()
        while (i < ch.length()) {
            a[i + 1] = ch.charAt(i) - '0';
            i++;
        }
        
        // Update i to be the actual length of the string
        i = ch.length();

        // C++: int y=i; // 'y' is declared but unused in the provided snippet, 
        // so we can ignore it or declare it as unused.
        int y = i;
        
        int d;
        
        // C++: for(j=1;j<i;j++)
        for (int j = 1; j < i; j++) {
            if (k > 0) {
                int v = 0;
                // C++: if(k<i-j+1) d=k+j; else d=i;
                if (k < i - j + 1) {
                    d = k + j;
                } else {
                    d = i;
                }
                
                int m = 0;
                // C++: for(int r=j;r<=d;r++) ...
                for (int r = j; r <= d; r++) {
                    // C++: if(m<a[r])
                    if (m < a[r]) {
                        m = a[r];
                        v = r;
                    }
                }
                
                // C++: if(j==v) continue;
                if (j == v) {
                    continue;
                } 
                // C++: else if(v) { ... }
                else if (v != 0) {
                    // C++: for(int u=v;u>j;u--) a[u]=a[u-1]; k--;
                    for (int u = v; u > j; u--) {
                        a[u] = a[u - 1];
                        k--;
                    }
                    
                    a[j] = m;
                }
            }
        }

        // C++: Output loop
        // for(int p=1;p<=i;p++) cout<<a[p];
        StringBuilder sb = new StringBuilder();
        for (int p = 1; p <= i; p++) {
            sb.append(a[p]);
        }
        System.out.println(sb.toString());
    }
}
</CODE>
```java
import java.util.Scanner;

public class b_435 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Reading input
        // In C++, char ch[101] reads a string into a char array. 
        // In Java, we read it as a String.
        String ch = scanner.next();
        
        // Reading k. In C++, k is long long. In Java, we use long.
        long k = scanner.nextLong();

        // C++ Logic: if(!k) { cout<<ch; return 0; }
        if (k == 0) {
            System.out.println(ch);
            return;
        }

        // C++ Logic: Convert char array to int array.
        // C++: a is size 101, 1-based indexing (a[i+1]).
        // Java: a is size 102 (to be safe for 1-based indexing up to 101).
        int[] a = new int[102];
        
        int i = 0;
        // C++: for(i=0;ch[i];i++) a[i+1]=ch[i]-'0';
        // Java: Iterate while i < ch.length()
        while (i < ch.length()) {
            a[i + 1] = ch.charAt(i) - '0';
            i++;
        }
        
        // Update i to be the actual length of the string
        i = ch.length();

        // C++: int y=i; // 'y' is declared but unused in the provided snippet, 
        // so we can ignore it or declare it as unused.
        int y = i;
        
        int d;
        
        // C++: for(j=1;j<i;j++)
        for (int j = 1; j < i; j++) {
            if (k > 0) {
                int v = 0;
                // C++: if(k<i-j+1) d=k+j; else d=i;
                if (k < i - j + 1) {
                    d = k + j;
                } else {
                    d = i;
                }
                
                int m = 0;
                // C++: for(int r=j;r<=d;r++) ...
                for (int r = j; r <= d; r++) {
                    // C++: if(m<a[r])
                    if (m < a[r]) {
                        m = a[r];
                        v = r;
                    }
                }
                
                // C++: if(j==v) continue;
                if (j == v) {
                    continue;
                } 
                // C++: else if(v) { ... }
                else if (v != 0) {
                    // C++: for(int u=v;u>j;u--) a[u]=a[u-1]; k--;
                    for (int u = v; u > j; u--) {
                        a[u] = a[u - 1];
                        k--;
                    }
                    
                    a[j] = m;
                }
            }
        }

        // C++: Output loop
        // for(int p=1;p<=i;p++) cout<<a[p];
        StringBuilder sb = new StringBuilder();
        for (int p = 1; p <= i; p++) {
            sb.append(a[p]);
        }
        System.out.println(sb.toString());
    }
}
```
```cpp
#include<bits/stdc++.h>

using namespace std;

int main()

{

      long long n,i=0,k,j,m=0,a[101],t;

      char ch[1001];

      cin>>ch>>k;

      if(!k)

      {

            cout<<ch;

            return 0;

    }

      for(i=0;ch[i];i++)

      {

            a[i+1]=ch[i]-'0';

      }

      //cout<<i<<a[i];

      int y=i;

      int d;

      for(j=1;j<i;j++)

      {

            if(k){

            int v=0;

            if(k<i-j+1)

            d=k+j;

            else

            d=i;

            m=0;

          //  cout<<i-j+1<<" "<<d<<" "<<k;

            for(int r=j;r<=d;r++)

            {

                if(m<a[r])

                {

                      m=a[r];

                      v=r;

                }

            }

            if(j==v)

            continue;

            else if(v)

            {

                  for(int u=v;u>j;u--)

                  {

                        a[u]=a[u-1];

                        k--;

                        //cout<<a[u]<<" ";

                  }

                  a[j]=m;

                  //cout<<a[j]<<"\n";

            }

            }

            /*for(int l=1;l<=i;l++)

            cout<<a[l];

           cout<<"\n";*/

      }

      for(int p=1;p<=i;p++)

      cout<<a[p];

}
```

<CODE>
import java.util.Scanner;

public class b_435 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Reading input
        // In C++, char ch[101] reads a string into a char array. 
        // In Java, we read it as a String.
        String ch = scanner.next();
        
        // Reading k. In C++, k is long long. In Java, we use long.
        long k = scanner.nextLong();

        // C++ Logic: if(!k) { cout<<ch; return 0; }
        if (k == 0) {
            System.out.println(ch);
            return;
        }

        // C++ Logic: Convert char array to int array.
        // C++: a is size 101, 1-based indexing (a[i+1]).
        // Java: a is size 102 (to be safe for 1-based indexing up to 101).
        int[] a = new int[102];
        
        int i = 0;
        // C++: for(i=0;ch[i];i++) a[i+1]=ch[i]-'0';
        // Java: Iterate while i < ch.length()
        while (i < ch.length()) {
            a[i + 1] = ch.charAt(i) - '0';
            i++;
        }
        
        // Update i to be the actual length of the string
        i = ch.length();

        // C++: int y=i; // 'y' is declared but unused in the provided snippet, 
        // so we can ignore it or declare it as unused.
        int y = i;
        
        int d;
        
        // C++: for(j=1;j<i;j++)
        for (int j = 1; j < i; j++) {
            if (k > 0) {
                int v = 0;
                // C++: if(k<i-j+1) d=k+j; else d=i;
                if (k < i - j + 1) {
                    d = k + j;
                } else {
                    d = i;
                }
                
                int m = 0;
                // C++: for(int r=j;r<=d;r++) ...
                for (int r = j; r <= d; r++) {
                    // C++: if(m<a[r])
                    if (m < a[r]) {
                        m = a[r];
                        v = r;
                    }
                }
                
                // C++: if(j==v) continue;
                if (j == v) {
                    continue;
                } 
                // C++: else if(v) { ... }
                else if (v != 0) {
                    // C++: for(int u=v;u>j;u--) a[u]=a[u-1]; k--;
                    for (int u = v; u > j; u--) {
                        a[u] = a[u - 1];
                        k--;
                    }
                    
                    a[j] = m;
                }
            }
        }

        // C++: Output loop
        // for(int p=1;p<=i;p++) cout<<a[p];
        StringBuilder sb = new StringBuilder();
        for (int p = 1; p <= i; p++) {
            sb.append(a[p]);
        }
        System.out.println(sb.toString());
    }
}
</CODE>
```java
import java.util.Scanner;

public class b_435 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Reading input
        // In C++, char ch[101] reads a string into a char array. 
        // In Java, we read it as a String.
        String ch = scanner.next();
        
        // Reading k. In C++, k is long long. In Java, we use long.
        long k = scanner.nextLong();

        // C++ Logic: if(!k) { cout<<ch; return 0; }
        if (k == 0) {
            System.out.println(ch);
            return;
        }

        // C++ Logic: Convert char array to int array.
        // C++: a is size 101, 1-based indexing (a[i+1]).
        // Java: a is size 102 (to be safe for 1-based indexing up to 101).
        int[] a = new int[102];
        
        int i = 0;
        // C++: for(i=0;ch[i];i++) a[i+1]=ch[i]-'0';
        // Java: Iterate while i < ch.length()
        while (i < ch.length()) {
            a[i + 1] = ch.charAt(i) - '0';
            i++;
        }
        
        // Update i to be the actual length of the string
        i = ch.length();

        // C++: int y=i; // 'y' is declared but unused in the provided snippet, 
        // so we can ignore it or declare it as unused.
        int y = i;
        
        int d;
        
        // C++: for(j=1;j<i;j++)
        for (int j = 1; j < i; j++) {
            if (k > 0) {
                int v = 0;
                // C++: if(k<i-j+1) d=k+j; else d=i;
                if (k < i - j + 1) {
                    d = k + j;
                } else {
                    d = i;
                }
                
                int m = 0;
                // C++: for(int r=j;r<=d;r++) ...
                for (int r = j; r <= d; r++) {
                    // C++: if(m<a[r])
                    if (m < a[r]) {
                        m = a[r];
                        v = r;
                    }
                }
                
                // C++: if(j==v) continue;
                if (j == v) {
                    continue;
                } 
                // C++: else if(v) { ... }
                else if (v != 0) {
                    // C++: for(int u=v;u>j;u--) a[u]=a[u-1]; k--;
                    for (int u = v; u > j; u--) {
                        a[u] = a[u - 1];
                        k--;
                    }
                    
                    a[j] = m;
                }
            }
        }

        // C++: Output loop
        // for(int p=1;p<=i;p++) cout<<a[p];
        StringBuilder sb = new StringBuilder();
        for (int p = 1; p <= i; p++) {
            sb.append(a[p]);
        }
        System.out.println(sb.toString());
    }
}
```
```cpp
#include<bits/stdc++.h>

using namespace std;

int main()

{

      long long n,i=0,k,j,m=0,a[101],t;

      char ch[1001];

      cin>>ch>>k;

      if(!k)

      {

            cout<<ch;

            return 0;

    }

      for(i=0;ch[i];i++)

      {

            a[i+1]=ch[i]-'0';

      }

      //cout<<i<<a[i];

      int y=i;

      int d;

      for(j=1;j<i;j++)

      {

            if(k){

            int v=0;

            if(k<i-j+1)

            d=k+j;

            else

            d=i;

            m=0;

          //  cout<<i-j+1<<" "<<d<<" "<<k;

            for(int r=j;r<=d;r++)

            {

                if(m<a[r])

                {

                      m=a[r];

                      v=r;

                }

            }

            if(j==v)

            continue;

            else if(v)

            {

                  for(int u=v;u>j;u--)

                  {

                        a[u]=a[u-1];

                        k--;

                        //cout<<a[u]<<" ";

                  }

                  a[j]=m;

                  //cout<<a[j]<<"\n";

            }

            }

            /*for(int l=1;l<=i;l++)

            cout<<a[l];

           cout<<"\n";*/

      }

      for(int p=1;p<=i;p++)

      cout<<a[p];

}
```

<CODE>
import java.util.Scanner;

public class b_435 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Reading input
        // In C++, char ch[101] reads a string into a char array. 
        // In Java, we read it as a String.
        String ch = scanner.next();
        
        // Reading k. In C++, k is long long. In Java, we use long.
        long k = scanner.nextLong();

        // C++ Logic: if(!k) { cout<<ch; return 0; }
        if (k == 0) {
            System.out.println(ch);
            return;
        }

        // C++ Logic: Convert char array to int array.
        // C++: a is size 101, 1-based indexing (a[i+1]).
        // Java: a is size 102 (to be safe for 1-based indexing up to 101).
        int[] a = new int[102];
        
        int i = 0;
        // C++: for(i=0;ch[i];i++) a[i+1]=ch[i]-'0';
        // Java: Iterate while i < ch.length()
        while (i < ch.length()) {
            a[i + 1] = ch.charAt(i) - '0';
            i++;
        }
        
        // Update i to be the actual length of the string
        i = ch.length();

        // C++: int y=i; // 'y' is declared but unused in the provided snippet, 
        // so we can ignore it or declare it as unused.
        int y = i;
        
        int d;
        
        // C++: for(j=1;j<i;j++)
        for (int j = 1; j < i; j++) {
            if (k > 0) {
                int v = 0;
                // C++: if(k<i-j+1) d=k+j; else d=i;
                if (k < i - j + 1) {
                    d = k + j;
                } else {
                    d = i;
                }
                
                int m = 0;
                // C++: for(int r=j;r<=d;r++) ...
                for (int r = j; r <= d; r++) {
                    // C++: if(m<a[r])
                    if (m < a[r]) {
                        m = a[r];
                        v = r;
                    }
                }
                
                // C++: if(j==v) continue;
                if (j == v) {
                    continue;
                } 
                // C++: else if(v) { ... }
                else if (v != 0) {
                    // C++: for(int u=v;u>j;u--) a[u]=a[u-1]; k--;
                    for (int u = v; u > j; u--) {
                        a[u] = a[u - 1];
                        k--;
                    }
                    
                    a[j] = m;
                }
            }
        }

        // C++: Output loop
        // for(int p=1;p<=i;p++) cout<<a[p];
        StringBuilder sb = new StringBuilder();
        for (int p = 1; p <= i; p++) {
            sb.append(a[p]);
        }
        System.out.println(sb.toString());
    }
}
</CODE>
```java
import java.util.Scanner;

public class b_435 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Reading input
        // In C++, char ch[101] reads a string into a char array. 
        // In Java, we read it as a String.
        String ch = scanner.next();
        
        // Reading k. In C++, k is long long. In Java, we use long.
        long k = scanner.nextLong();

        // C++ Logic: if(!k) { cout<<ch; return 0; }
        if (k == 0) {
            System.out.println(ch);
            return;
        }

        // C++ Logic: Convert char array to int array.
        // C++: a is size 101, 1-based indexing (a[i+1]).
        // Java: a is size 102 (to be safe for 1-based indexing up to 101).
        int[] a = new int[102];
        
        int i = 0;
        // C++: for(i=0;ch[i];i++) a[i+1]=ch[i]-'0';
        // Java: Iterate while i < ch.length()
        while (i < ch.length()) {
            a[i + 1] = ch.charAt(i) - '0';
            i++;
        }
        
        // Update i to be the actual length of the string
        i = ch.length();

        // C++: int y=i; // 'y' is declared but unused in the provided snippet, 
        // so we can ignore it or declare it as unused.
        int y = i;
        
        int d;
        
        // C++: for(j=1;j<i;j++)
        for (int j = 1; j < i; j++) {
            if (k > 0) {
                int v = 0;
                // C++: if(k<i-j+1) d=k+j; else d=i;
                if (k < i - j + 1) {
                    d = k + j;
                } else {
                    d = i;
                }
                
                int m = 0;
                // C++: for(int r=j;r<=d;r++) ...
                for (int r = j; r <= d; r++) {
                    // C++: if(m<a[r])
                    if (m < a[r]) {
                        m = a[r];
                        v = r;
                    }
                }
                
                // C++: if(j==v) continue;
                if (j == v) {
                    continue;
                } 
                // C++: else if(v) { ... }
                else if (v != 0) {
                    // C++: for(int u=v;u>j;u--) a[u]=a[u-1]; k--;
                    for (int u = v; u > j; u--) {
                        a[u] = a[u - 1];
                        k--;
                    }
                    
                    a[j] = m;
                }
            }
        }

        // C++: Output loop
        // for(int p=1;p<=i;p++) cout<<a[p];
        StringBuilder sb = new StringBuilder();
        for (int p = 1; p <= i; p++) {
            sb.append(a[p]);
        }
        System.out.println(sb.toString());
    }
}
```
```cpp
#include<bits/stdc++.h>

using namespace std;

int main()

{

      long long n,i=0,k,j,m=0,a[101],t;

      char ch[1001];

      cin>>ch>>k;

      if(!k)

      {

            cout<<ch;

            return 0;

    }

      for(i=0;ch[i];i++)

      {

            a[i+1]=ch[i]-'0';

      }

      //cout<<i<<a[i];

      int y=i;

      int d;

      for(j=1;j<i;j++)

      {

            if(k){

            int v=0;

            if(k<i-j+1)

            d=k+j;

            else

            d=i;

            m=0;

          //  cout<<i-j+1<<" "<<d<<" "<<k;

            for(int r=j;r<=d;r++)

            {

                if(m<a[r])

                {

                      m=a[r];

                      v=r;

                }

            }

            if(j==v)

            continue;

            else if(v)

            {

                  for(int u=v;u>j;u--)

                  {

                        a[u]=a[u-1];

                        k--;

                        //cout<<a[u]<<" ";

                  }

                  a[j]=m;

                  //cout<<a[j]<<"\n";

            }

            }

            /*for(int l=1;l<=i;l++)

            cout<<a[l];

           cout<<"\n";*/

      }

      for(int p=1;p<=i;p++)

      cout<<a[p];

}
```

<CODE>
import java.util.Scanner;

public class b_435 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Reading input
        // In C++, char ch[101] reads a string into a char array. 
        // In Java, we read it as a String.
        String ch = scanner.next();
        
        // Reading k. In C++, k is long long. In Java, we use long.
        long k = scanner.nextLong();

        // C++ Logic: if(!k) { cout<<ch; return 0; }
        if (k == 0) {
            System.out.println(ch);
            return;
        }

        // C++ Logic: Convert char array to int array.
        // C++: a is size 101, 1-based indexing (a[i+1]).
        // Java: a is size 102 (to be safe for 1-based indexing up to 101).
        int[] a = new int[102];
        
        int i = 0;
        // C++: for(i=0;ch[i];i++) a[i+1]=ch[i]-'0';
        // Java: Iterate while i < ch.length()
        while (i < ch.length()) {
            a[i + 1] = ch.charAt(i) - '0';
            i++;
        }
        
        // Update i to be the actual length of the string
        i = ch.length();

        // C++: int y=i; // 'y' is declared but unused in the provided snippet, 
        // so we can ignore it or declare it as unused.
        int y = i;
        
        int d;
        
        // C++: for(j=1;j<i;j++)
        for (int j = 1; j < i; j++) {
            if (k > 0) {
                int v = 0;
                // C++: if(k<i-j+1) d=k+j; else d=i;
                if (k < i - j + 1) {
                    d = k + j;
                } else {
                    d = i;
                }
                
                int m = 0;
                // C++: for(int r=j;r<=d;r++) ...
                for (int r = j; r <= d; r++) {
                    // C++: if(m<a[r])
                    if (m < a[r]) {
                        m = a[r];
                        v = r;
                    }
                }
                
                // C++: if(j==v) continue;
                if (j == v) {
                    continue;
                } 
                // C++: else if(v) { ... }
                else if (v != 0) {
                    // C++: for(int u=v;u>j;u--) a[u]=a[u-1]; k--;
                    for (int u = v; u > j; u--) {
                        a[u] = a[u - 1];
                        k--;
                    }
                    
                    a[j] = m;
                }
            }
        }

        // C++: Output loop
        // for(int p=1;p<=i;p++) cout<<a[p];
        StringBuilder sb = new StringBuilder();
        for (int p = 1; p <= i; p++) {
            sb.append(a[p]);
        }
        System.out.println(sb.toString());
    }
}
</CODE>
```java
import java.util.Scanner;

public class b_435 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Reading input
        // In C++, char ch[101] reads a string into a char array. 
        // In Java, we read it as a String.
        String ch = scanner.next();
        
        // Reading k. In C++, k is long long. In Java, we use long.
        long k = scanner.nextLong();

        // C++ Logic: if(!k) { cout<<ch; return 0; }
        if (k == 0) {
            System.out.println(ch);
            return;
        }

        // C++ Logic: Convert char array to int array.
        // C++: a is size 101, 1-based indexing (a[i+1]).
        // Java: a is size 102 (to be safe for 1-based indexing up to 101).
        int[] a = new int[102];
        
        int i = 0;
        // C++: for(i=0;ch[i];i++) a[i+1]=ch[i]-'0';
        // Java: Iterate while i < ch.length()
        while (i < ch.length()) {
            a[i + 1] = ch.charAt(i) - '0';
            i++;
        }
        
        // Update i to be the actual length of the string
        i = ch.length();

        // C++: int y=i; // 'y' is declared but unused in the provided snippet, 
        // so we can ignore it or declare it as unused.
        int y = i;
        
        int d;
        
        // C++: for(j=1;j<i;j++)
        for (int j = 1; j < i; j++) {
            if (k > 0) {
                int v = 0;
                // C++: if(k<i-j+1) d=k+j; else d=i;
                if (k < i - j + 1) {
                    d = k + j;
                } else {
                    d = i;
                }
                
                int m = 0;
                // C++: for(int r=j;r<=d;r++) ...
                for (int r = j; r <= d; r++) {
                    // C++: if(m<a[r])
                    if (m < a[r]) {
                        m = a[r];
                        v = r;
                    }
                }
                
                // C++: if(j==v) continue;
                if (j == v) {
                    continue;
                } 
                // C++: else if(v) { ... }
                else if (v != 0) {
                    // C++: for(int u=v;u>j;u--) a[u]=a[u-1]; k--;
                    for (int u = v; u > j; u--) {
                        a[u] = a[u - 1];
                        k--;
                    }
                    
                    a[j] = m;
                }
            }
        }

        // C++: Output loop
        // for(int p=1;p<=i;p++) cout<<a[p];
        StringBuilder sb = new StringBuilder();
        for (int p = 1; p <= i; p++) {
            sb.append(a[p]);
        }
        System.out.println(sb.toString());
    }
}
```
```cpp
#include<bits/stdc++.h>

using namespace std;

int main()

{

      long long n,i=0,k,j,m=0,a[101],t;

      char ch[1001];

      cin>>ch>>k;

      if(!k)

      {

            cout<<ch;

            return 0;

    }

      for(i=0;ch[i];i++)

      {

            a[i+1]=ch[i]-'0';

      }

      //cout<<i<<a[i];

      int y=i;

      int d;

      for(j=1;j<i;j++)

      {

            if(k){

            int v=0;

            if(k<i-j+1)

            d=k+j;

            else

            d=i;

            m=0;

          //  cout<<i-j+1<<" "<<d<<" "<<k;

            for(int r=j;r<=d;r++)

            {

                if(m<a[r])

                {

                      m=a[r];

                      v=r;

                }

            }

            if(j==v)

            continue;

            else if(v)

            {

                  for(int u=v;u>j;u--)

                  {

                        a[u]=a[u-1];

                        k--;

                        //cout<<a[u]<<" ";

                  }

                  a[j]=m;

                  //cout<<a[j]<<"\n";

            }

            }

            /*for(int l=1;l<=i;l++)

            cout<<a[l];

           cout<<"\n";*/

      }

      for(int p=1;p<=i;p++)

      cout<<a[p];

}
```

<CODE>
import java.util.Scanner;

public class b_435 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Reading input
        // In C++, char ch[101] reads a string into a char array. 
        // In Java, we read it as a String.
        String ch = scanner.next();
        
        // Reading k. In C++, k is long long. In Java, we use long.
        long k = scanner.nextLong();

        // C++ Logic: if(!k) { cout<<ch; return 0; }
        if (k == 0) {
            System.out.println(ch);
            return;
        }

        // C++ Logic: Convert char array to int array.
        // C++: a is size 101, 1-based indexing (a[i+1]).
        // Java: a is size 102 (to be safe for 1-based indexing up to 101).
        int[] a = new int[102];
        
        int i = 0;
        // C++: for(i=0;ch[i];i++) a[i+1]=ch[i]-'0';
        // Java: Iterate while i < ch.length()
        while (i < ch.length()) {
            a[i + 1] = ch.charAt(i) - '0';
            i++;
        }
        
        // Update i to be the actual length of the string
        i = ch.length();

        // C++: int y=i; // 'y' is declared but unused in the provided snippet, 
        // so we can ignore it or declare it as unused.
        int y = i;
        
        int d;
        
        // C++: for(j=1;j<i;j++)
        for (int j = 1; j < i; j++) {
            if (k > 0) {
                int v = 0;
                // C++: if(k<i-j+1) d=k+j; else d=i;
                if (k < i - j + 1) {
                    d = k + j;
                } else {
                    d = i;
                }
                
                int m = 0;
                // C++: for(int r=j;r<=d;r++) ...
                for (int r = j; r <= d; r++) {
                    // C++: if(m<a[r])
                    if (m < a[r]) {
                        m = a[r];
                        v = r;
                    }
                }
                
                // C++: if(j==v) continue;
                if (j == v) {
                    continue;
                } 
                // C++: else if(v) { ... }
                else if (v != 0) {
                    // C++: for(int u=v;u>j;u--) a[u]=a[u-1]; k--;
                    for (int u = v; u > j; u--) {
                        a[u] = a[u - 1];
                        k--;
                    }
                    
                    a[j] = m;
                }
            }
        }

        // C++: Output loop
        // for(int p=1;p<=i;p++) cout<<a[p];
        StringBuilder sb = new StringBuilder();
        for (int p = 1; p <= i; p++) {
            sb.append(a[p]);
        }
        System.out.println(sb.toString());
    }
}
</CODE>
```java
import java.util.Scanner;

public class b_435 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Reading input
        // In C++, char ch[101] reads a string into a char array. 
        // In Java, we read it as a String.
        String ch = scanner.next();
        
        // Reading k. In C++, k is long long. In Java, we use long.
        long k = scanner.nextLong();

        // C++ Logic: if(!k) { cout<<ch; return 0; }
        if (k == 0) {
            System.out.println(ch);
            return;
        }

        // C++ Logic: Convert char array to int array.
        // C++: a is size 101, 1-based indexing (a[i+1]).
        // Java: a is size 102 (to be safe for 1-based indexing up to 101).
        int[] a = new int[102];
        
        int i = 0;
        // C++: for(i=0;ch[i];i++) a[i+1]=ch[i]-'0';
        // Java: Iterate while i < ch.length()
        while (i < ch.length()) {
            a[i + 1] = ch.charAt(i) - '0';
            i++;
        }
        
        // Update i to be the actual length of the string
        i = ch.length();

        // C++: int y=i; // 'y' is declared but unused in the provided snippet, 
        // so we can ignore it or declare it as unused.
        int y = i;
        
        int d;
        
        // C++: for(j=1;j<i;j++)
        for (int j = 1; j < i; j++) {
            if (k > 0) {
                int v = 0;
                // C++: if(k<i-j+1) d=k+j; else d=i;
                if (k < i - j + 1) {
                    d = k + j;
                } else {
                    d = i;
                }
                
                int m = 0;
                // C++: for(int r=j;r<=d;r++) ...
                for (int r = j; r <= d; r++) {
                    // C++: if(m<a[r])
                    if (m < a[r]) {
                        m = a[r];
                        v = r;
                    }
                }
                
                // C++: if(j==v) continue;
                if (j == v) {
                    continue;
                } 
                // C++: else if(v) { ... }
                else if (v != 0) {
                    // C++: for(int u=v;u>j;u--) a[u]=a[u-1]; k--;
                    for (int u = v; u > j; u--) {
                        a[u] = a[u - 1];
                        k--;
                    }
                    
                    a[j] = m;
                }
            }
        }

        // C++: Output loop
        // for(int p=1;p<=i;p++) cout<<a[p];
        StringBuilder sb = new StringBuilder();
        for (int p = 1; p <= i; p++) {
            sb.append(a[p]);
        }
        System.out.println(sb.toString());
    }
}
```
```cpp
#include<bits/stdc++.h>

using namespace std;

int main()

{

      long long n,i=0,k,j,m=0,a[101],t;

      char ch[1001];

      cin>>ch>>k;

      if(!k)

      {

            cout<<ch;

            return 0;

    }

      for(i=0;ch[i];i++)

      {

            a[i+1]=ch[i]-'0';

      }

      //cout<<i<<a[i];

      int y=i;

      int d;

      for(j=1;j<i;j++)

      {

            if(k){

            int v=0;

            if(k<i-j+1)

            d=k+j;

            else

            d=i;

            m=0;

          //  cout<<i-j+1<<" "<<d<<" "<<k;

            for(int r=j;r<=d;r++)

            {

                if(m<a[r])

                {

                      m=a[r];

                      v=r;

                }

            }

            if(j==v)

            continue;

            else if(v)

            {

                  for(int u=v;u>j;u--)

                  {

                        a[u]=a[u-1];

                        k--;

                        //cout<<a[u]<<" ";

                  }

                  a[j]=m;

                  //cout<<a[j]<<"\n";

            }

            }

            /*for(int l=1;l<=i;l++)

            cout<<a[l];

           cout<<"\n";*/

      }

      for(int p=1;p<=i;p++)

      cout<<a[p];

}
```

<CODE>
import java.util.Scanner;

public class b_435 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Reading input
        // In C++, char ch[101] reads a string into a char array. 
        // In Java, we read it as a String.
        String ch = scanner.next();
        
        // Reading k. In C++, k is long long. In Java, we use long.
        long k = scanner.nextLong();

        // C++ Logic: if(!k) { cout<<ch; return 0; }
        if (k == 0) {
            System.out.println(ch);
            return;
        }

        // C++ Logic: Convert char array to int array.
        // C++: a is size 101, 1-based indexing (a[i+1]).
        // Java: a is size 102 (to be safe for 1-based indexing up to 101).
        int[] a = new int[102];
        
        int i = 0;
        // C++: for(i=0;ch[i];i++) a[i+1]=ch[i]-'0';
        // Java: Iterate while i < ch.length()
        while (i < ch.length()) {
            a[i + 1] = ch.charAt(i) - '0';
            i++;
        }
        
        // Update i to be the actual length of the string
        i = ch.length();

        // C++: int y=i; // 'y' is declared but unused in the provided snippet, 
        // so we can ignore it or declare it as unused.
        int y = i;
        
        int d;
        
        // C++: for(j=1;j<i;j++)
        for (int j = 1; j < i; j++) {
            if (k > 0) {
                int v = 0;
                // C++: if(k<i-j+1) d=k+j; else d=i;
                if (k < i - j + 1) {
                    d = k + j;
                } else {
                    d = i;
                }
                
                int m = 0;
                // C++: for(int r=j;r<=d;r++) ...
                for (int r = j; r <= d; r++) {
                    // C++: if(m<a[r])
                    if (m < a[r]) {
                        m = a[r];
                        v = r;
                    }
                }
                
                // C++: if(j==v) continue;
                if (j == v) {
                    continue;
                } 
                // C++: else if(v) { ... }
                else if (v != 0) {
                    // C++: for(int u=v;u>j;u--) a[u]=a[u-1]; k--;
                    for (int u = v; u > j; u--) {
                        a[u] = a[u - 1];
                        k--;
                    }
                    
                    a[j] = m;
                }
            }
        }

        // C++: Output loop
        // for(int p=1;p<=i;p++) cout<<a[p];
        StringBuilder sb = new StringBuilder();
        for (int p = 1; p <= i; p++) {
            sb.append(a[p]);
        }
        System.out.println(sb.toString());
    }
}
</CODE>
```java
import java.util.Scanner;

public class b_435 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Reading input
        // In C++, char ch[101] reads a string into a char array. 
        // In Java, we read it as a String.
        String ch = scanner.next();
        
        // Reading k. In C++, k is long long. In Java, we use long.
        long k = scanner.nextLong();

        // C++ Logic: if(!k) { cout<<ch; return 0; }
        if (k == 0) {
            System.out.println(ch);
            return;
        }

        // C++ Logic: Convert char array to int array.
        // C++: a is size 101, 1-based indexing (a[i+1]).
        // Java: a is size 102 (to be safe for 1-based indexing up to 101).
        int[] a = new int[102];
        
        int i = 0;
        // C++: for(i=0;ch[i];i++) a[i+1]=ch[i]-'0';
        // Java: Iterate while i < ch.length()
        while (i < ch.length()) {
            a[i + 1] = ch.charAt(i) - '0';
            i++;
        }
        
        // Update i to be the actual length of the string
        i = ch.length();

        // C++: int y=i; // 'y' is declared but unused in the provided snippet, 
        // so we can ignore it or declare it as unused.
        int y = i;
        
        int d;
        
        // C++: for(j=1;j<i;j++)
        for (int j = 1; j < i; j++) {
            if (k > 0) {
                int v = 0;
                // C++: if(k<i-j+1) d=k+j; else d=i;
                if (k < i - j + 1) {
                    d = k + j;
                } else {
                    d = i;
                }
                
                int m = 0;
                // C++: for(int r=j;r<=d;r++) ...
                for (int r = j; r <= d; r++) {
                    // C++: if(m<a[r])
                    if (m < a[r]) {
                        m = a[r];
                        v = r;
                    }
                }
                
                // C++: if(j==v) continue;
                if (j == v) {
                    continue;
                } 
                // C++: else if(v) { ... }
                else if (v != 0) {
                    // C++: for(int u=v;u>j;u--) a[u]=a[u-1]; k--;
                    for (int u = v; u > j; u--) {
                        a[u] = a[u - 1];
                        k--;
                    }
                    
                    a[j] = m;
                }
            }
        }

        // C++: Output loop
        // for(int p=1;p<=i;p++) cout<<a[p];
        StringBuilder sb = new StringBuilder();
        for (int p = 1; p <= i; p++) {
            sb.append(a[p]);
        }
        System.out.println(sb.toString());
    }
}
```
```cpp
#include<bits/stdc++.h>

using namespace std;

int main()

{

      long long n,i=0,k,j,m=0,a[101],t;

      char ch[1001];

      cin>>ch>>k;

      if(!k)

      {

            cout<<ch;

            return 0;

    }

      for(i=0;ch[i];i++)

      {

            a[i+1]=ch[i]-'0';

      }

      //cout<<i<<a[i];

      int y=i;

      int d;

      for(j=1;j<i;j++)

      {

            if(k){

            int v=0;

            if(k<i-j+1)

            d=k+j;

            else

            d=i;

            m=0;

          //  cout<<i-j+1<<" "<<d<<" "<<k;

            for(int r=j;r<=d;r++)

            {

                if(m<a[r])

                {

                      m=a[r];

                      v=r;

                }

            }

            if(j==v)

            continue;

            else if(v)

            {

                  for(int u=v;u>j;u--)

                  {

                        a[u]=a[u-1];

                        k--;

                        //cout<<a[u]<<" ";

                  }

                  a[j]=m;

                  //cout<<a[j]<<"\n";

            }

            }

            /*for(int l=1;l<=i;l++)

            cout<<a[l];

           cout<<"\n";*/

      }

      for(int p=1;p<=i;p++)

      cout<<a[p];

}
```

<CODE>
import java.util.Scanner;

public class b_435 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Reading input
        // In C++, char ch[101] reads a string into a char array. 
        // In Java, we read it as a String.
        String ch = scanner.next();
        
        // Reading k. In C++, k is long long. In Java, we use long.
        long k = scanner.nextLong();

        // C++ Logic: if(!k) { cout<<ch; return 0; }
        if (k == 0) {
            System.out.println(ch);
            return;
        }

        // C++ Logic: Convert char array to int array.
        // C++: a is size 101, 1-based indexing (a[i+1]).
        // Java: a is size 102 (to be safe for 1-based indexing up to 101).
        int[] a = new int[102];
        
        int i = 0;
        // C++: for(i=0;ch[i];i++) a[i+1]=ch[i]-'0';
        // Java: Iterate while i < ch.length()
        while (i < ch.length()) {
            a[i + 1] = ch.charAt(i) - '0';
            i++;
        }
        
        // Update i to be the actual length of the string
        i = ch.length();

        // C++: int y=i; // 'y' is declared but unused in the provided snippet, 
        // so we can ignore it or declare it as unused.
        int y = i;
        
        int d;
        
        // C++: for(j=1;j<i;j++)
        for (int j = 1; j < i; j++) {
            if (k > 0) {
                int v = 0;
                // C++: if(k<i-j+1) d=k+j; else d=i;
                if (k < i - j + 1) {
                    d = k + j;
                } else {
                    d = i;
                }
                
                int m = 0;
                // C++: for(int r=j;r<=d;r++) ...
                for (int r = j; r <= d; r++) {
                    // C++: if(m<a[r])
                    if (m < a[r]) {
                        m = a[r];
                        v = r;
                    }
                }
                
                // C++: if(j==v) continue;
                if (j == v) {
                    continue;
                } 
                // C++: else if(v) { ... }
                else if (v != 0) {
                    // C++: for(int u=v;u>j;u--) a[u]=a[u-1]; k--;
                    for (int u = v; u > j; u--) {
                        a[u] = a[u - 1];
                        k--;
                    }
                    
                    a[j] = m;
                }
            }
        }

        // C++: Output loop
        // for(int p=1;p<=i;p++) cout<<a[p];
        StringBuilder sb = new StringBuilder();
        for (int p = 1; p <= i; p++) {
            sb.append(a[p]);
        }
        System.out.println(sb.toString());
    }
}
</CODE>
```java
import java.util.Scanner;

public class b_435 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Reading input
        // In C++, char ch[101] reads a string into a char array. 
        // In Java, we read it as a String.
        String ch = scanner.next();
        
        // Reading k. In C++, k is long long. In Java, we use long.
        long k = scanner.nextLong();

        // C++ Logic: if(!k) { cout<<ch; return 0; }
        if (k == 0) {
            System.out.println(ch);
            return;
        }

        // C++ Logic: Convert char array to int array.
        // C++: a is size 101, 1-based indexing (a[i+1]).
        // Java: a is size 102 (to be safe for 1-based indexing up to 101).
        int[] a = new int[102];
        
        int i = 0;
        // C++: for(i=0;ch[i];i++) a[i+1]=ch[i]-'0';
        // Java: Iterate while i < ch.length()
        while (i < ch.length()) {
            a[i + 1] = ch.charAt(i) - '0';
            i++;
        }
        
        // Update i to be the actual length of the string
        i = ch.length();

        // C++: int y=i; // 'y' is declared but unused in the provided snippet, 
        // so we can ignore it or declare it as unused.
        int y = i;
        
        int d;
        
        // C++: for(j=1;j<i;j++)
        for (int j = 1; j < i; j++) {
            if (k > 0) {
                int v = 0;
                // C++: if(k<i-j+1) d=k+j; else d=i;
                if (k < i - j + 1) {
                    d = k + j;
                } else {
                    d = i;
                }
                
                int m = 0;
                // C++: for(int r=j;r<=d;r++) ...
                for (int r = j; r <= d; r++) {
                    // C++: if(m<a[r])
                    if (m < a[r]) {
                        m = a[r];
                        v = r;
                    }
                }
                
                // C++: if(j==v) continue;
                if (j == v) {
                    continue;
                } 
                // C++: else if(v) { ... }
                else if (v != 0) {
                    // C++: for(int u=v;u>j;u--) a[u]=a[u-1]; k--;
                    for (int u = v; u > j; u--) {
                        a[u] = a[u - 1];
                        k--;
                    }
                    
                    a[j] = m;
                }
            }
        }

        // C++: Output loop
        // for(int p=1;p<=i;p++) cout<<a[p];
        StringBuilder sb = new StringBuilder();
        for (int p = 1; p <= i; p++) {
            sb.append(a[p]);
        }
        System.out.println(sb.toString());
    }
}
```
```cpp
#include<bits/stdc++.h>

using namespace std;

int main()

{

      long long n,i=0,k,j,m=0,a[101],t;

      char ch[1001];

      cin>>ch>>k;

      if(!k)

      {

            cout<<ch;

            return 0;

    }

      for(i=0;ch[i];i++)

      {

            a[i+1]=ch[i]-'0';

      }

      //cout<<i<<a[i];

      int y=i;

      int d;

      for(j=1;j<i;j++)

      {

            if(k){

            int v=0;

            if(k<i-j+1)

            d=k+j;

            else

            d=i;

            m=0;

          //  cout<<i-j+1<<" "<<d<<" "<<k;

            for(int r=j;r<=d;r++)

            {

                if(m<a[r])

                {

                      m=a[r];

                      v=r;

                }

            }

            if(j==v)

            continue;

            else if(v)

            {

                  for(int u=v;u>j;u--)

                  {

                        a[u]=a[u-1];

                        k--;

                        //cout<<a[u]<<" ";

                  }

                  a[j]=m;

                  //cout<<a[j]<<"\n";

            }

            }

            /*for(int l=1;l<=i;l++)

            cout<<a[l];

           cout<<"\n";*/

      }

      for(int p=1;p<=i;p++)

      cout<<a[p];

}
```

<CODE>
import java.util.Scanner;

public class b_435 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Reading input
        // In C++, char ch[101] reads a string into a char array. 
        // In Java, we read it as a String.
        String ch = scanner.next();
        
        // Reading k. In C++, k is long long. In Java, we use long.
        long k = scanner.nextLong();

        // C++ Logic: if(!k) { cout<<ch; return 0; }
        if (k == 0) {
            System.out.println(ch);
            return;
        }

        // C++ Logic: Convert char array to int array.
        // C++: a is size 101, 1-based indexing (a[i+1]).
        // Java: a is size 102 (to be safe for 1-based indexing up to 101).
        int[] a = new int[102];
        
        int i = 0;
        // C++: for(i=0;ch[i];i++) a[i+1]=ch[i]-'0';
        // Java: Iterate while i < ch.length()
        while (i < ch.length()) {
            a[i + 1] = ch.charAt(i) - '0';
            i++;
        }
        
        // Update i to be the actual length of the string
        i = ch.length();

        // C++: int y=i; // 'y' is declared but unused in the provided snippet, 
        // so we can ignore it or declare it as unused.
        int y = i;
        
        int d;
        
        // C++: for(j=1;j<i;j++)
        for (int j = 1; j < i; j++) {
            if (k > 0) {
                int v = 0;
                // C++: if(k<i-j+1) d=k+j; else d=i;
                if (k < i - j + 1) {
                    d = k + j;
                } else {
                    d = i;
                }
                
                int m = 0;
                // C++: for(int r=j;r<=d;r++) ...
                for (int r = j; r <= d; r++) {
                    // C++: if(m<a[r])
                    if (m < a[r]) {
                        m = a[r];
                        v = r;
                    }
                }
                
                // C++: if(j==v) continue;
                if (j == v) {
                    continue;
                } 
                // C++: else if(v) { ... }
                else if (v != 0) {
                    // C++: for(int u=v;u>j;u--) a[u]=a[u-1]; k--;
                    for (int u = v; u > j; u--) {
                        a[u] = a[u - 1];
                        k--;
                    }
                    
                    a[j] = m;
                }
            }
        }

        // C++: Output loop
        // for(int p=1;p<=i;p++) cout<<a[p];
        StringBuilder sb = new StringBuilder();
        for (int p = 1; p <= i; p++) {
            sb.append(a[p]);
        }
        System.out.println(sb.toString());
    }
}
</CODE>
```java
import java.util.Scanner;

public class b_435 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Reading input
        // In C++, char ch[101] reads a string into a char array. 
        // In Java, we read it as a String.
        String ch = scanner.next();
        
        // Reading k. In C++, k is long long. In Java, we use long.
        long k = scanner.nextLong();

        // C++ Logic: if(!k) { cout<<ch; return 0; }
        if (k == 0) {
            System.out.println(ch);
            return;
        }

        // C++ Logic: Convert char array to int array.
        // C++: a is size 101, 1-based indexing (a[i+1]).
        // Java: a is size 102 (to be safe for 1-based indexing up to 101).
        int[] a = new int[102];
        
        int i = 0;
        // C++: for(i=0;ch[i];i++) a[i+1]=ch[i]-'0';
        // Java: Iterate while i < ch.length()
        while (i < ch.length()) {
            a[i + 1] = ch.charAt(i) - '0';
            i++;
        }
        
        // Update i to be the actual length of the string
        i = ch.length();

        // C++: int y=i; // 'y' is declared but unused in the provided snippet, 
        // so we can ignore it or declare it as unused.
        int y = i;
        
        int d;
        
        // C++: for(j=1;j<i;j++)
        for (int j = 1; j < i; j++) {
            if (k > 0) {
                int v = 0;
                // C++: if(k<i-j+1) d=k+j; else d=i;
                if (k < i - j + 1) {
                    d = k + j;
                } else {
                    d = i;
                }
                
                int m = 0;
                // C++: for(int r=j;r<=d;r++) ...
                for (int r = j; r <= d; r++) {
                    // C++: if(m<a[r])
                    if (m < a[r]) {
                        m = a[r];
                        v = r;
                    }
                }
                
                // C++: if(j==v) continue;
                if (j == v) {
                    continue;
                } 
                // C++: else if(v) { ... }
                else if (v != 0) {
                    // C++: for(int u=v;u>j;u--) a[u]=a[u-1]; k--;
                    for (int u = v; u > j; u--) {
                        a[u] = a[u - 1];
                        k--;
                    }
                    
                    a[j] = m;
                }
            }
        }

        // C++: Output loop
        // for(int p=1;p<=i;p++) cout<<a[p];
        StringBuilder sb = new StringBuilder();
        for (int p = 1; p <= i; p++) {
            sb.append(a[p]);
        }
        System.out.println(sb.toString());
    }
}
```
```cpp
#include<bits/stdc++.h>

using namespace std;

int main()

{

      long long n,i=0,k,j,m=0,a[101],t;

      char ch[1001];

      cin>>ch>>k;

      if(!k)

      {

            cout<<ch;

            return 0;

    }

      for(i=0;ch[i];i++)

      {

            a[i+1]=ch[i]-'0';

      }

      //cout<<i<<a[i];

      int y=i;

      int d;

      for(j=1;j<i;j++)

      {

            if(k){

            int v=0;

            if(k<i-j+1)

            d=k+j;

            else

            d=i;

            m=0;

          //  cout<<i-j+1<<" "<<d<<" "<<k;

            for(int r=j;r<=d;r++)

            {

                if(m<a[r])

                {

                      m=a[r];

                      v=r;

                }

            }

            if(j==v)

            continue;

            else if(v)

            {

                  for(int u=v;u>j;u--)

                  {

                        a[u]=a[u-1];

                        k--;

                        //cout<<a[u]<<" ";

                  }

                  a[j]=m;

                  //cout<<a[j]<<"\n";

            }

            }

            /*for(int l=1;l<=i;l++)

            cout<<a[l];

           cout<<"\n";*/

      }

      for(int p=1;p<=i;p++)

      cout<<a[p];

}
```

<CODE>
import java.util.Scanner;

public class b_435 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Reading input
        // In C++, char ch[101] reads a string into a char array. 
        // In Java, we read it as a String.
        String ch = scanner.next();
        
        // Reading k. In C++, k is long long. In Java, we use long.
        long k = scanner.nextLong();

        // C++ Logic: if(!k) { cout<<ch; return 0; }
        if (k == 0) {
            System.out.println(ch);
            return;
        }

        // C++ Logic: Convert char array to int array.
        // C++: a is size 101, 1-based indexing (a[i+1]).
        // Java: a is size 102 (to be safe for 1-based indexing up to 101).
        int[] a = new int[102];
        
        int i = 0;
        // C++: for(i=0;ch[i];i++) a[i+1]=ch[i]-'0';
        // Java: Iterate while i < ch.length()
        while (i < ch.length()) {
            a[i + 1] = ch.charAt(i) - '0';
            i++;
        }
        
        // Update i to be the actual length of the string
        i = ch.length();

        // C++: int y=i; // 'y' is declared but unused in the provided snippet, 
        // so we can ignore it or declare it as unused.
        int y = i;
        
        int d;
        
        // C++: for(j=1;j<i;j++)
        for (int j = 1; j < i; j++) {
            if (k > 0) {
                int v = 0;
                // C++: if(k<i-j+1) d=k+j; else d=i;
                if (k < i - j + 1) {
                    d = k + j;
                } else {
                    d = i;
                }
                
                int m = 0;
                // C++: for(int r=j;r<=d;r++) ...
                for (int r = j; r <= d; r++) {
                    // C++: if(m<a[r])
                    if (m < a[r]) {
                        m = a[r];
                        v = r;
                    }
                }
                
                // C++: if(j==v) continue;
                if (j == v) {
                    continue;
                } 
                // C++: else if(v) { ... }
                else if (v != 0) {
                    // C++: for(int u=v;u>j;u--) a[u]=a[u-1]; k--;
                    for (int u = v; u > j; u--) {
                        a[u] = a[u - 1];
                        k--;
                    }
                    
                    a[j] = m;
                }
            }
        }

        // C++: Output loop
        // for(int p=1;p<=i;p++) cout<<a[p];
        StringBuilder sb = new StringBuilder();
        for (int p = 1; p <= i; p++) {
            sb.append(a[p]);
        }
        System.out.println(sb.toString());
    }
}
</CODE>
```java
import java.util.Scanner;

public class b_435 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Reading input
        // In C++, char ch[101] reads a string into a char array. 
        // In Java, we read it as a String.
        String ch = scanner.next();
        
        // Reading k. In C++, k is long long. In Java, we use long.
        long k = scanner.nextLong();

        // C++ Logic: if(!k) { cout<<ch; return 0; }
        if (k == 0) {
            System.out.println(ch);
            return;
        }

        // C++ Logic: Convert char array to int array.
        // C++: a is size 101, 1-based indexing (a[i+1]).
        // Java: a is size 102 (to be safe for 1-based indexing up to 101).
        int[] a = new int[102];
        
        int i = 0;
        // C++: for(i=0;ch[i];i++) a[i+1]=ch[i]-'0';
        // Java: Iterate while i < ch.length()
        while (i < ch.length()) {
            a[i + 1] = ch.charAt(i) - '0';
            i++;
        }
        
        // Update i to be the actual length of the string
        i = ch.length();

        // C++: int y=i; // 'y' is declared but unused in the provided snippet, 
        // so we can ignore it or declare it as unused.
        int y = i;
        
        int d;
        
        // C++: for(j=1;j<i;j++)
        for (int j = 1; j < i; j++) {
            if (k > 0) {
                int v = 0;
                // C++: if(k<i-j+1) d=k+j; else d=i;
                if (k < i - j + 1) {
                    d = k + j;
                } else {
                    d = i;
                }
                
                int m = 0;
                // C++: for(int r=j;r<=d;r++) ...
                for (int r = j; r <= d; r++) {
                    // C++: if(m<a[r])
                    if (m < a[r]) {
                        m = a[r];
                        v = r;
                    }
                }
                
                // C++: if(j==v) continue;
                if (j == v) {
                    continue;
                } 
                // C++: else if(v) { ... }
                else if (v != 0) {
                    // C++: for(int u=v;u>j;u--) a[u]=a[u-1]; k--;
                    for (int u = v; u > j; u--) {
                        a[u] = a[u - 1];
                        k--;
                    }
                    
                    a[j] = m;
                }
            }
        }

        // C++: Output loop
        // for(int p=1;p<=i;p++) cout<<a[p];
        StringBuilder sb = new StringBuilder();
        for (int p = 1; p <= i; p++) {
            sb.append(a[p]);
        }
        System.out.println(sb.toString());
    }
}
```
```cpp
#include<bits/stdc++.h>

using namespace std;

int main()

{

      long long n,i=0,k,j,m=0,a[101],t;

      char ch[1001];

      cin>>ch>>k;

      if(!k)

      {

            cout<<ch;

            return 0;

    }

      for(i=0;ch[i];i++)

      {

            a[i+1]=ch[i]-'0';

      }

      //cout<<i<<a[i];

      int y=i;

      int d;

      for(j=1;j<i;j++)

      {

            if(k){

            int v=0;

            if(k<i-j+1)

            d=k+j;

            else

            d=i;

            m=0;

          //  cout<<i-j+1<<" "<<d<<" "<<k;

            for(int r=j;r<=d;r++)

            {

                if(m<a[r])

                {

                      m=a[r];

                      v=r;

                }

            }

            if(j==v)

            continue;

            else if(v)

            {

                  for(int u=v;u>j;u--)

                  {

                        a[u]=a[u-1];

                        k--;

                        //cout<<a[u]<<" ";

                  }

                  a[j]=m;

                  //cout<<a[j]<<"\n";

            }

            }

            /*for(int l=1;l<=i;l++)

            cout<<a[l];

           cout<<"\n";*/

      }

      for(int p=1;p<=i;p++)

      cout<<a[p];

}
```

<CODE>
import java.util.Scanner;

public class b_435 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Reading input
        // In C++, char ch[101] reads a string into a char array. 
        // In Java, we read it as a String.
        String ch = scanner.next();
        
        // Reading k. In C++, k is long long. In Java, we use long.
        long k = scanner.nextLong();

        // C++ Logic: if(!k) { cout<<ch; return 0; }
        if (k == 0) {
            System.out.println(ch);
            return;
        }

        // C++ Logic: Convert char array to int array.
        // C++: a is size 101, 1-based indexing (a[i+1]).
        // Java: a is size 102 (to be safe for 1-based indexing up to 101).
        int[] a = new int[102];
        
        int i = 0;
        // C++: for(i=0;ch[i];i++) a[i+1]=ch[i]-'0';
        // Java: Iterate while i < ch.length()
        while (i < ch.length()) {
            a[i + 1] = ch.charAt(i) - '0';
            i++;
        }
        
        // Update i to be the actual length of the string
        i = ch.length();

        // C++: int y=i; // 'y' is declared but unused in the provided snippet, 
        // so we can ignore it or declare it as unused.
        int y = i;
        
        int d;
        
        // C++: for(j=1;j<i;j++)
        for (int j = 1; j < i; j++) {
            if (k > 0) {
                int v = 0;
                // C++: if(k<i-j+1) d=k+j; else d=i;
                if (k < i - j + 1) {
                    d = k + j;
                } else {
                    d = i;
                }
                
                int m = 0;
                // C++: for(int r=j;r<=d;r++) ...
                for (int r = j; r <= d; r++) {
                    // C++: if(m<a[r])
                    if (m < a[r]) {
                        m = a[r];
                        v = r;
                    }
                }
                
                // C++: if(j==v) continue;
                if (j == v) {
                    continue;
                } 
                // C++: else if(v) { ... }
                else if (v != 0) {
                    // C++: for(int u=v;u>j;u--) a[u]=a[u-1]; k--;
                    for (int u = v; u > j; u--) {
                        a[u] = a[u - 1];
                        k--;
                    }
                    
                    a[j] = m;
                }
            }
        }

        // C++: Output loop
        // for(int p=1;p<=i;p++) cout<<a[p];
        StringBuilder sb = new StringBuilder();
        for (int p = 1; p <= i; p++) {
            sb.append(a[p]);
        }
        System.out.println(sb.toString());
    }
}
</CODE>
```java
import java.util.Scanner;

public class b_435 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Reading input
        // In C++, char ch[101] reads a string into a char array. 
        // In Java, we read it as a String.
        String ch = scanner.next();
        
        // Reading k. In C++, k is long long. In Java, we use long.
        long k = scanner.nextLong();

        // C++ Logic: if(!k) { cout<<ch; return 0; }
        if (k == 0) {
            System.out.println(ch);
            return;
        }

        // C++ Logic: Convert char array to int array.
        // C++: a is size 101, 1-based indexing (a[i+1]).
        // Java: a is size 102 (to be safe for 1-based indexing up to 101).
        int[] a = new int[102];
        
        int i = 0;
        // C++: for(i=0;ch[i];i++) a[i+1]=ch[i]-'0';
        // Java: Iterate while i < ch.length()
        while (i < ch.length()) {
            a[i + 1] = ch.charAt(i) - '0';
            i++;
        }
        
        // Update i to be the actual length of the string
        i = ch.length();

        // C++: int y=i; // 'y' is declared but unused in the provided snippet, 
        // so we can ignore it or declare it as unused.
        int y = i;
        
        int d;
        
        // C++: for(j=1;j<i;j++)
        for (int j = 1; j < i; j++) {
            if (k > 0) {
                int v = 0;
                // C++: if(k<i-j+1) d=k+j; else d=i;
                if (k < i - j + 1) {
                    d = k + j;
                } else {
                    d = i;
                }
                
                int m = 0;
                // C++: for(int r=j;r<=d;r++) ...
                for (int r = j; r <= d; r++) {
                    // C++: if(m<a[r])
                    if (m < a[r]) {
                        m = a[r];
                        v = r;
                    }
                }
                
                // C++: if(j==v) continue;
                if (j == v) {
                    continue;
                } 
                // C++: else if(v) { ... }
                else if (v != 0) {
                    // C++: for(int u=v;u>j;u--) a[u]=a[u-1]; k--;
                    for (int u = v; u > j; u--) {
                        a[u] = a[u - 1];
                        k--;
                    }
                    
                    a[j] = m;
                }
            }
        }

        // C++: Output loop
        // for(int p=1;p<=i;p++) cout<<a[p];
        StringBuilder sb = new StringBuilder();
        for (int p = 1; p <= i; p++) {
            sb.append(a[p]);
        }
        System.out.println(sb.toString());
    }
}
```
```cpp
#include<bits/stdc++.h>

using namespace std;

int main()

{

      long long n,i=0,k,j,m=0,a[101],t;

      char ch[1001];

      cin>>ch>>k;

      if(!k)

      {

            cout<<ch;

            return 0;

    }

      for(i=0;ch[i];i++)

      {

            a[i+1]=ch[i]-'0';

      }

      //cout<<i<<a[i];

      int y=i;

      int d;

      for(j=1;j<i;j++)

      {

            if(k){

            int v=0;

            if(k<i-j+1)

            d=k+j;

            else

            d=i;

            m=0;

          //  cout<<i-j+1<<" "<<d<<" "<<k;

            for(int r=j;r<=d;r++)

            {

                if(m<a[r])

                {

                      m=a[r];

                      v=r;

                }

            }

            if(j==v)

            continue;

            else if(v)

            {

                  for(int u=v;u>j;u--)

                  {

                        a[u]=a[u-1];

                        k--;

                        //cout<<a[u]<<" ";

                  }

                  a[j]=m;

                  //cout<<a[j]<<"\n";

            }

            }

            /*for(int l=1;l<=i;l++)

            cout<<a[l];

           cout<<"\n";*/

      }

      for(int p=1;p<=i;p++)

      cout<<a[p];

}
```

<CODE>
import java.util.Scanner;

public class b_435 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Reading input
        // In C++, char ch[101] reads a string into a char array. 
        // In Java, we read it as a String.
        String ch = scanner.next();
        
        // Reading k. In C++, k is long long. In Java, we use long.
        long k = scanner.nextLong();

        // C++ Logic: if(!k) { cout<<ch; return 0; }
        if (k == 0) {
            System.out.println(ch);
            return;
        }

        // C++ Logic: Convert char array to int array.
        // C++: a is size 101, 1-based indexing (a[i+1]).
        // Java: a is size 102 (to be safe for 1-based indexing up to 101).
        int[] a = new int[102];
        
        int i = 0;
        // C++: for(i=0;ch[i];i++) a[i+1]=ch[i]-'0';
        // Java: Iterate while i < ch.length()
        while (i < ch.length()) {
            a[i + 1] = ch.charAt(i) - '0';
            i++;
        }
        
        // Update i to be the actual length of the string
        i = ch.length();

        // C++: int y=i; // 'y' is declared but unused in the provided snippet, 
        // so we can ignore it or declare it as unused.
        int y = i;
        
        int d;
        
        // C++: for(j=1;j<i;j++)
        for (int j = 1; j < i; j++) {
            if (k > 0) {
                int v = 0;
                // C++: if(k<i-j+1) d=k+j; else d=i;
                if (k < i - j + 1) {
                    d = k + j;
                } else {
                    d = i;
                }
                
                int m = 0;
                // C++: for(int r=j;r<=d;r++) ...
                for (int r = j; r <= d; r++) {
                    // C++: if(m<a[r])
                    if (m < a[r]) {
                        m = a[r];
                        v = r;
                    }
                }
                
                // C++: if(j==v) continue;
                if (j == v) {
                    continue;
                } 
                // C++: else if(v) { ... }
                else if (v != 0) {
                    // C++: for(int u=v;u>j;u--) a[u]=a[u-1]; k--;
                    for (int u = v; u > j; u--) {
                        a[u] = a[u - 1];
                        k--;
                    }
                    
                    a[j] = m;
                }
            }
        }

        // C++: Output loop
        // for(int p=1;p<=i;p++) cout<<a[p];
        StringBuilder sb = new StringBuilder();
        for (int p = 1; p <= i; p++) {
            sb.append(a[p]);
        }
        System.out.println(sb.toString());
    }
}
</CODE>
```java
import java.util.Scanner;

public class b_435 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Reading input
        // In C++, char ch[101] reads a string into a char array. 
        // In Java, we read it as a String.
        String ch = scanner.next();
        
        // Reading k. In C++, k is long long. In Java, we use long.
        long k = scanner.nextLong();

        // C++ Logic: if(!k) { cout<<ch; return 0; }
        if (k == 0) {
            System.out.println(ch);
            return;
        }

        // C++ Logic: Convert char array to int array.
        // C++: a is size 101, 1-based indexing (a[i+1]).
        // Java: a is size 102 (to be safe for 1-based indexing up to 101).
        int[] a = new int[102];
        
        int i = 0;
        // C++: for(i=0;ch[i];i++) a[i+1]=ch[i]-'0';
        // Java: Iterate while i < ch.length()
        while (i < ch.length()) {
            a[i + 1] = ch.charAt(i) - '0';
            i++;
        }
        
        // Update i to be the actual length of the string
        i = ch.length();

        // C++: int y=i; // 'y' is declared but unused in the provided snippet, 
        // so we can ignore it or declare it as unused.
        int y = i;
        
        int d;
        
        // C++: for(j=1;j<i;j++)
        for (int j = 1; j < i; j++) {
            if (k > 0) {
                int v = 0;
                // C++: if(k<i-j+1) d=k+j; else d=i;
                if (k < i - j + 1) {
                    d = k + j;
                } else {
                    d = i;
                }
                
                int m = 0;
                // C++: for(int r=j;r<=d;r++) ...
                for (int r = j; r <= d; r++) {
                    // C++: if(m<a[r])
                    if (m < a[r]) {
                        m = a[r];
                        v = r;
                    }
                }
                
                // C++: if(j==v) continue;
                if (j == v) {
                    continue;
                } 
                // C++: else if(v) { ... }
                else if (v != 0) {
                    // C++: for(int u=v;u>j;u--) a[u]=a[u-1]; k--;
                    for (int u = v; u > j; u--) {
                        a[u] = a[u - 1];
                        k--;
                    }
                    
                    a[j] = m;
                }
            }
        }

        // C++: Output loop
        // for(int p=1;p<=i;p++) cout<<a[p];
        StringBuilder sb = new StringBuilder();
        for (int p = 1; p <= i; p++) {
            sb.append(a[p]);
        }
        System.out.println(sb.toString());
    }
}
```
```cpp
#include<bits/stdc++.h>

using namespace std;

int main()

{

      long long n,i=0,k,j,m=0,a[101],t;

      char ch[1001];

      cin>>ch>>k;

      if(!k)

      {

            cout<<ch;

            return 0;

    }

      for(i=0;ch[i];i++)

      {

            a[i+1]=ch[i]-'0';

      }

      //cout<<i<<a[i];

      int y=i;

      int d;

      for(j=1;j<i;j++)

      {

            if(k){

            int v=0;

            if(k<i-j+1)

            d=k+j;

            else

            d=i;

            m=0;

          //  cout<<i-j+1<<" "<<d<<" "<<k;

            for(int r=j;r<=d;r++)

            {

                if(m<a[r])

                {

                      m=a[r];

                      v=r;

                }

            }

            if(j==v)

            continue;

            else if(v)

            {

                  for(int u=v;u>j;u--)

                  {

                        a[u]=a[u-1];

                        k--;

                        //cout<<a[u]<<" ";

                  }

                  a[j]=m;

                  //cout<<a[j]<<"\n";

            }

            }

            /*for(int l=1;l<=i;l++)

            cout<<a[l];

           cout<<"\n";*/

      }

      for(int p=1;p<=i;p++)

      cout<<a[p];

}
```

<CODE>
import java.util.Scanner;

public class b_435 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Reading input
        // In C++, char ch[101] reads a string into a char array. 
        // In Java, we read it as a String.
        String ch = scanner.next();
        
        // Reading k. In C++, k is long long. In Java, we use long.
        long k = scanner.nextLong();

        // C++ Logic: if(!k) { cout<<ch; return 0; }
        if (k == 0) {
            System.out.println(ch);
            return;
        }

        // C++ Logic: Convert char array to int array.
        // C++: a is size 101, 1-based indexing (a[i+1]).
        // Java: a is size 102 (to be safe for 1-based indexing up to 101).
        int[] a = new int[102];
        
        int i = 0;
        // C++: for(i=0;ch[i];i++) a[i+1]=ch[i]-'0';
        // Java: Iterate while i < ch.length()
        while (i < ch.length()) {
            a[i + 1] = ch.charAt(i) - '0';
            i++;
        }
        
        // Update i to be the actual length of the string
        i = ch.length();

        // C++: int y=i; // 'y' is declared but unused in the provided snippet, 
        // so we can ignore it or declare it as unused.
        int y = i;
        
        int d;
        
        // C++: for(j=1;j<i;j++)
        for (int j = 1; j < i; j++) {
            if (k > 0) {
                int v = 0;
                // C++: if(k<i-j+1) d=k+j; else d=i;
                if (k < i - j + 1) {
                    d = k + j;
                } else {
                    d = i;
                }
                
                int m = 0;
                // C++: for(int r=j;r<=d;r++) ...
                for (int r = j; r <= d; r++) {
                    // C++: if(m<a[r])
                    if (m < a[r]) {
                        m = a[r];
                        v = r;
                    }
                }
                
                // C++: if(j==v) continue;
                if (j == v) {
                    continue;
                } 
                // C++: else if(v) { ... }
                else if (v != 0) {
                    // C++: for(int u=v;u>j;u--) a[u]=a[u-1]; k--;
                    for (int u = v; u > j; u--) {
                        a[u] = a[u - 1];
                        k--;
                    }
                    
                    a[j] = m;
                }
            }
        }

        // C++: Output loop
        // for(int p=1;p<=i;p++) cout<<a[p];
        StringBuilder sb = new StringBuilder();
        for (int p = 1; p <= i; p++) {
            sb.append(a[p]);
        }
        System.out.println(sb.toString());
    }
}
</CODE>
```java
import java.util.Scanner;

public class b_435 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Reading input
        // In C++, char ch[101] reads a string into a char array. 
        // In Java, we read it as a String.
        String ch = scanner.next();
        
        // Reading k. In C++, k is long long. In Java, we use long.
        long k = scanner.nextLong();

        // C++ Logic: if(!k) { cout<<ch; return 0; }
        if (k == 0) {
            System.out.println(ch);
            return;
        }

        // C++ Logic: Convert char array to int array.
        // C++: a is size 101, 1-based indexing (a[i+1]).
        // Java: a is size 102 (to be safe for 1-based indexing up to 101).
        int[] a = new int[102];
        
        int i = 0;
        // C++: for(i=0;ch[i];i++) a[i+1]=ch[i]-'0';
        // Java: Iterate while i < ch.length()
        while (i < ch.length()) {
            a[i + 1] = ch.charAt(i) - '0';
            i++;
        }
        
        // Update i to be the actual length of the string
        i = ch.length();

        // C++: int y=i; // 'y' is declared but unused in the provided snippet, 
        // so we can ignore it or declare it as unused.
        int y = i;
        
        int d;
        
        // C++: for(j=1;j<i;j++)
        for (int j = 1; j < i; j++) {
            if (k > 0) {
                int v = 0;
                // C++: if(k<i-j+1) d=k+j; else d=i;
                if (k < i - j + 1) {
                    d = k + j;
                } else {
                    d = i;
                }
                
                int m = 0;
                // C++: for(int r=j;r<=d;r++) ...
                for (int r = j; r <= d; r++) {
                    // C++: if(m<a[r])
                    if (m < a[r]) {
                        m = a[r];
                        v = r;
                    }
                }
                
                // C++: if(j==v) continue;
                if (j == v) {
                    continue;
                } 
                // C++: else if(v) { ... }
                else if (v != 0) {
                    // C++: for(int u=v;u>j;u--) a[u]=a[u-1]; k--;
                    for (int u = v; u > j; u--) {
                        a[u] = a[u - 1];
                        k--;
                    }
                    
                    a[j] = m;
                }
            }
        }

        // C++: Output loop
        // for(int p=1;p<=i;p++) cout<<a[p];
        StringBuilder sb = new StringBuilder();
        for (int p = 1; p <= i; p++) {
            sb.append(a[p]);
        }
        System.out.println(sb.toString());
    }
}
```
```cpp
#include<bits/stdc++.h>

using namespace std;

int main()

{

      long long n,i=0,k,j,m=0,a[101],t;

      char ch[1001];

      cin>>ch>>k;

      if(!k)

      {

            cout<<ch;

            return 0;

    }

      for(i=0;ch[i];i++)

      {

            a[i+1]=ch[i]-'0';

      }

      //cout<<i<<a[i];

      int y=i;

      int d;

      for(j=1;j<i;j++)

      {

            if(k){

            int v=0;

            if(k<i-j+1)

            d=k+j;

            else

            d=i;

            m=0;

          //  cout<<i-j+1<<" "<<d<<" "<<k;

            for(int r=j;r<=d;r++)

            {

                if(m<a[r])

                {

                      m=a[r];

                      v=r;

                }

            }

            if(j==v)

            continue;

            else if(v)

            {

                  for(int u=v;u>j;u--)

                  {

                        a[u]=a[u-1];

                        k--;

                        //cout<<a[u]<<" ";

                  }

                  a[j]=m;

                  //cout<<a[j]<<"\n";

            }

            }

            /*for(int l=1;l<=i;l++)

            cout<<a[l];

           cout<<"\n";*/

      }

      for(int p=1;p<=i;p++)

      cout<<a[p];

}
```

<CODE>
import java.util.Scanner;

public class b_435 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Reading input
        // In C++, char ch[101] reads a string into a char array. 
        // In Java, we read it as a String.
        String ch = scanner.next();
        
        // Reading k. In C++, k is long long. In Java, we use long.
        long k = scanner.nextLong();

        // C++ Logic: if(!k) { cout<<ch; return 0; }
        if (k == 0) {
            System.out.println(ch);
            return;
        }

        // C++ Logic: Convert char array to int array.
        // C++: a is size 101, 1-based indexing (a[i+1]).
        // Java: a is size 102 (to be safe for 1-based indexing up to 101).
        int[] a = new int[102];
        
        int i = 0;
        // C++: for(i=0;ch[i];i++) a[i+1]=ch[i]-'0';
        // Java: Iterate while i < ch.length()
        while (i < ch.length()) {
            a[i + 1] = ch.charAt(i) - '0';
            i++;
        }
        
        // Update i to be the actual length of the string
        i = ch.length();

        // C++: int y=i; // 'y' is declared but unused in the provided snippet, 
        // so we can ignore it or declare it as unused.
        int y = i;
        
        int d;
        
        // C++: for(j=1;j<i;j++)
        for (int j = 1; j < i; j++) {
            if (k > 0) {
                int v = 0;
                // C++: if(k<i-j+1) d=k+j; else d=i;
                if (k < i - j + 1) {
                    d = k + j;
                } else {
                    d = i;
                }
                
                int m = 0;
                // C++: for(int r=j;r<=d;r++) ...
                for (int r = j; r <= d; r++) {
                    // C++: if(m<a[r])
                    if (m < a[r]) {
                        m = a[r];
                        v = r;
                    }
                }
                
                // C++: if(j==v) continue;
                if (j == v) {
                    continue;
                } 
                // C++: else if(v) { ... }
                else if (v != 0) {
                    // C++: for(int u=v;u>j;u--) a[u]=a[u-1]; k--;
                    for (int u = v; u > j; u--) {
                        a[u] = a[u - 1];
                        k--;
                    }
                    
                    a[j] = m;
                }
            }
        }

        // C++: Output loop
        // for(int p=1;p<=i;p++) cout<<a[p];
        StringBuilder sb = new StringBuilder();
        for (int p = 1; p <= i; p++) {
            sb.append(a[p]);
        }
        System.out.println(sb.toString());
    }
}
</CODE>
```java
import java.util.Scanner;

public class b_435 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Reading input
        // In C++, char ch[101] reads a string into a char array. 
        // In Java, we read it as a String.
        String ch = scanner.next();
        
        // Reading k. In C++, k is long long. In Java, we use long.
        long k = scanner.nextLong();

        // C++ Logic: if(!k) { cout<<ch; return 0; }
        if (k == 0) {
            System.out.println(ch);
            return;
        }

        // C++ Logic: Convert char array to int array.
        // C++: a is size 101, 1-based indexing (a[i+1]).
        // Java: a is size 102 (to be safe for 1-based indexing up to 101).
        int[] a = new int[102];
        
        int i = 0;
        // C++: for(i=0;ch[i];i++) a[i+1]=ch[i]-'0';
        // Java: Iterate while i < ch.length()
        while (i < ch.length()) {
            a[i + 1] = ch.charAt(i) - '0';
            i++;
        }
        
        // Update i to be the actual length of the string
        i = ch.length();

        // C++: int y=i; // 'y' is declared but unused in the provided snippet, 
        // so we can ignore it or declare it as unused.
        int y = i;
        
        int d;
        
        // C++: for(j=1;j<i;j++)
        for (int j = 1; j < i; j++) {
            if (k > 0) {
                int v = 0;
                // C++: if(k<i-j+1) d=k+j; else d=i;
                if (k < i - j + 1) {
                    d = k + j;
                } else {
                    d = i;
                }
                
                int m = 0;
                // C++: for(int r=j;r<=d;r++) ...
                for (int r = j; r <= d; r++) {
                    // C++: if(m<a[r])
                    if (m < a[r]) {
                        m = a[r];
                        v = r;
                    }
                }
                
                // C++: if(j==v) continue;
                if (j == v) {
                    continue;
                } 
                // C++: else if(v) { ... }
                else if (v != 0) {
                    // C++: for(int u=v;u>j;u--) a[u]=a[u-1]; k--;
                    for (int u = v; u > j; u--) {
                        a[u] = a[u - 1];
                        k--;
                    }
                    
                    a[j] = m;
                }
            }
        }

        // C++: Output loop
        // for(int p=1;p<=i;p++) cout<<a[p];
        StringBuilder sb = new StringBuilder();
        for (int p = 1; p <= i; p++) {
            sb.append(a[p]);
        }
        System.out.println(sb.toString());
    }
}
```
```cpp
#include<bits/stdc++.h>

using namespace std;

int main()

{

      long long n,i=0,k,j,m=0,a[101],t;

      char ch[1001];

      cin>>ch>>k;

      if(!k)

      {

            cout<<ch;

            return 0;

    }

      for(i=0;ch[i];i++)

      {

            a[i+1]=ch[i]-'0';

      }

      //cout<<i<<a[i];

      int y=i;

      int d;

      for(j=1;j<i;j++)

      {

            if(k){

            int v=0;

            if(k<i-j+1)

            d=k+j;

            else

            d=i;

            m=0;

          //  cout<<i-j+1<<" "<<d<<" "<<k;

            for(int r=j;r<=d;r++)

            {

                if(m<a[r])

                {

                      m=a[r];

                      v=r;

                }

            }

            if(j==v)

            continue;

            else if(v)

            {

                  for(int u=v;u>j;u--)

                  {

                        a[u]=a[u-1];

                        k--;

                        //cout<<a[u]<<" ";

                  }

                  a[j]=m;

                  //cout<<a[j]<<"\n";

            }

            }

            /*for(int l=1;l<=i;l++)

            cout<<a[l];

           cout<<"\n";*/

      }

      for(int p=1;p<=i;p++)

      cout<<a[p];

}
```

<CODE>
import java.util.Scanner;

public class b_435 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Reading input
        // In C++, char ch[101] reads a string into a char array. 
        // In Java, we read it as a String.
        String ch = scanner.next();
        
        // Reading k. In C++, k is long long. In Java, we use long.
        long k = scanner.nextLong();

        // C++ Logic: if(!k) { cout<<ch; return 0; }
        if (k == 0) {
            System.out.println(ch);
            return;
        }

        // C++ Logic: Convert char array to int array.
        // C++: a is size 101, 1-based indexing (a[i+1]).
        // Java: a is size 102 (to be safe for 1-based indexing up to 101).
        int[] a = new int[102];
        
        int i = 0;
        // C++: for(i=0;ch[i];i++) a[i+1]=ch[i]-'0';
        // Java: Iterate while i < ch.length()
        while (i < ch.length()) {
            a[i + 1] = ch.charAt(i) - '0';
            i++;
        }
        
        // Update i to be the actual length of the string
        i = ch.length();

        // C++: int y=i; // 'y' is declared but unused in the provided snippet, 
        // so we can ignore it or declare it as unused.
        int y = i;
        
        int d;
        
        // C++: for(j=1;j<i;j++)
        for (int j = 1; j < i; j++) {
            if (k > 0) {
                int v = 0;
                // C++: if(k<i-j+1) d=k+j; else d=i;
                if (k < i - j + 1) {
                    d = k + j;
                } else {
                    d = i;
                }
                
                int m = 0;
                // C++: for(int r=j;r<=d;r++) ...
                for (int r = j; r <= d; r++) {
                    // C++: if(m<a[r])
                    if (m < a[r]) {
                        m = a[r];
                        v = r;
                    }
                }
                
                // C++: if(j==v) continue;
                if (j == v) {
                    continue;
                } 
                // C++: else if(v) { ... }
                else if (v != 0) {
                    // C++: for(int u=v;u>j;u--) a[u]=a[u-1]; k--;
                    for (int u = v; u > j; u--) {
                        a[u] = a[u - 1];
                        k--;
                    }
                    
                    a[j] = m;
                }
            }
        }

        // C++: Output loop
        // for(int p=1;p<=i;p++) cout<<a[p];
        StringBuilder sb = new StringBuilder();
        for (int p = 1; p <= i; p++) {
            sb.append(a[p]);
        }
        System.out.println(sb.toString());
    }
}
</CODE>
```java
import java.util.Scanner;

public class b_435 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Reading input
        // In C++, char ch[101] reads a string into a char array. 
        // In Java, we read it as a String.
        String ch = scanner.next();
        
        // Reading k. In C++, k is long long. In Java, we use long.
        long k = scanner.nextLong();

        // C++ Logic: if(!k) { cout<<ch; return 0; }
        if (k == 0) {
            System.out.println(ch);
            return;
        }

        // C++ Logic: Convert char array to int array.
        // C++: a is size 101, 1-based indexing (a[i+1]).
        // Java: a is size 102 (to be safe for 1-based indexing up to 101).
        int[] a = new int[102];
        
        int i = 0;
        // C++: for(i=0;ch[i];i++) a[i+1]=ch[i]-'0';
        // Java: Iterate while i < ch.length()
        while (i < ch.length()) {
            a[i + 1] = ch.charAt(i) - '0';
            i++;
        }
        
        // Update i to be the actual length of the string
        i = ch.length();

        // C++: int y=i; // 'y' is declared but unused in the provided snippet, 
        // so we can ignore it or declare it as unused.
        int y = i;
        
        int d;
        
        // C++: for(j=1;j<i;j++)
        for (int j = 1; j < i; j++) {
            if (k > 0) {
                int v = 0;
                // C++: if(k<i-j+1) d=k+j; else d=i;
                if (k < i - j + 1) {
                    d = k + j;
                } else {
                    d = i;
                }
                
                int m = 0;
                // C++: for(int r=j;r<=d;r++) ...
                for (int r = j; r <= d; r++) {
                    // C++: if(m<a[r])
                    if (m < a[r]) {
                        m = a[r];
                        v = r;
                    }
                }
                
                // C++: if(j==v) continue;
                if (j == v) {
                    continue;
                } 
                // C++: else if(v) { ... }
                else if (v != 0) {
                    // C++: for(int u=v;u>j;u--) a[u]=a[u-1]; k--;
                    for (int u = v; u > j; u--) {
                        a[u] = a[u - 1];
                        k--;
                    }
                    
                    a[j] = m;
                }
            }
        }

        // C++: Output loop
        // for(int p=1;p<=i;p++) cout<<a[p];
        StringBuilder sb = new StringBuilder();
        for (int p = 1; p <= i; p++) {
            sb.append(a[p]);
        }
        System.out.println(sb.toString());
    }
}
```
```cpp
#include<bits/stdc++.h>

using namespace std;

int main()

{

      long long n,i=0,k,j,m=0,a[101],t;

      char ch[1001];

      cin>>ch>>k;

      if(!k)

      {

            cout<<ch;

            return 0;

    }

      for(i=0;ch[i];i++)

      {

            a[i+1]=ch[i]-'0';

      }

      //cout<<i<<a[i];

      int y=i;

      int d;

      for(j=1;j<i;j++)

      {

            if(k){

            int v=0;

            if(k<i-j+1)

            d=k+j;

            else

            d=i;

            m=0;

          //  cout<<i-j+1<<" "<<d<<" "<<k;

            for(int r=j;r<=d;r++)

            {

                if(m<a[r])

                {

                      m=a[r];

                      v=r;

                }

            }

            if(j==v)

            continue;

            else if(v)

            {

                  for(int u=v;u>j;u--)

                  {

                        a[u]=a[u-1];

                        k--;

                        //cout<<a[u]<<" ";

                  }

                  a[j]=m;

                  //cout<<a[j]<<"\n";

            }

            }

            /*for(int l=1;l<=i;l++)

            cout<<a[l];

           cout<<"\n";*/

      }

      for(int p=1;p<=i;p++)

      cout<<a[p];

}
```

<CODE>
import java.util.Scanner;

public class b_435 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Reading input
        // In C++, char ch[101] reads a string into a char array. 
        // In Java, we read it as a String.
        String ch = scanner.next();
        
        // Reading k. In C++, k is long long. In Java, we use long.
        long k = scanner.nextLong();

        // C++ Logic: if(!k) { cout<<ch; return 0; }
        if (k == 0) {
            System.out.println(ch);
            return;
        }

        // C++ Logic: Convert char array to int array.
        // C++: a is size 101, 1-based indexing (a[i+1]).
        // Java: a is size 102 (to be safe for 1-based indexing up to 101).
        int[] a = new int[102];
        
        int i = 0;
        // C++: for(i=0;ch[i];i++) a[i+1]=ch[i]-'0';
        // Java: Iterate while i < ch.length()
        while (i < ch.length()) {
            a[i + 1] = ch.charAt(i) - '0';
            i++;
        }
        
        // Update i to be the actual length of the string
        i = ch.length();

        // C++: int y=i; // 'y' is declared but unused in the provided snippet, 
        // so we can ignore it or declare it as unused.
        int y = i;
        
        int d;
        
        // C++: for(j=1;j<i;j++)
        for (int j = 1; j < i; j++) {
            if (k > 0) {
                int v = 0;
                // C++: if(k<i-j+1) d=k+j; else d=i;
                if (k < i - j + 1) {
                    d = k + j;
                } else {
                    d = i;
                }
                
                int m = 0;
                // C++: for(int r=j;r<=d;r++) ...
                for (int r = j; r <= d; r++) {
                    // C++: if(m<a[r])
                    if (m <