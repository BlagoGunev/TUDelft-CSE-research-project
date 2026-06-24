Translate this C++ code to Java code. The main class name should be b_1294. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include<bits/stdc++.h>

using namespace std;

int main()

{int t;

cin>>t;

while(t--){

int n;

cin>>n;

pair<int ,int >a[n];

for(int i=0;i<n;i++){

cin>>a[i].first>>a[i].second;

}

sort(a,a+n);

int x=0,y=0,f=0;

string s="";

for(int i=0;i<n;i++){

int u=a[i].first,v=a[i].second;

if(v<y){

f=1;

cout<<"NO";

cout<<endl;

break;

}

s+=string(u-x,'R');

s+=string(v-y,'U');

x=u;

y=v;

}

if(!f)

cout<<"YES"<<endl<<s<<endl;

}

return 0;

}

Here is the plan for the translation from C++ to Java:

1.  **Header and Imports**: C++ uses `#include<bits/stdc++.h>` and `using namespace std;`. In Java, we need to import specific classes from the `java.util` package, such as `Scanner` for input, `Arrays` for sorting, and `StringBuilder` for string manipulation.
2.  **Main Class**: The C++ code is inside `main()`. In Java, this corresponds to the `main` method inside a class. The class name must be `b_1294` as requested.
3.  **Data Structures**:
    *   C++ `pair<int, int> a[n]` is a dynamic array of pairs. Java does not have a built-in dynamic array of pairs. We will use an array of custom objects or a 2D array. Since we need to sort based on the first element (`first`), a 2D array `int[][] a` where `a[i][0]` is `first` and `a[i][1]` is `second` is the most straightforward approach. Alternatively, we could create a static inner class `Point`, but a 2D array is simpler for direct translation.
    *   C++ `sort(a, a+n)` sorts the array. In Java, we need to implement a custom sort because `Arrays.sort` sorts based on primitive types or objects. Since our data is in a 2D array, we need a custom sorting logic (likely a bubble sort or selection sort) or an array of objects implementing `Comparable`. Given the small constraints usually associated with such problems, a simple bubble sort or a custom comparator array is acceptable. However, to keep it clean, I will use an array of objects `class Pair` implementing `Comparable` and `Arrays.sort`.
4.  **Input/Output**:
    *   C++ `cin >> t` and `cout` correspond to Java `Scanner.nextInt()` and `System.out.println()`.
    *   C++ string concatenation `s += string(u-x, 'R')` corresponds to `s.append(String.valueOf(u-x).repeat(charCount))` (Java 11+) or a loop. To ensure compatibility with older Java versions, a simple loop appending characters is safer.
5.  **Logic Flow**:
    *   Read `t`. Loop `t` times.
    *   Read `n`.
    *   Read pairs.
    *   Sort pairs based on `first` (x-coordinate).
    *   Iterate through sorted pairs. Maintain `x` and `y`.
    *   Check condition `v < y`. If true, print "NO" and break.
    *   Append 'R' for horizontal distance and 'U' for vertical distance.
    *   If loop finishes without breaking, print "YES" and the string.
6.  **Incremental Tasks**:
    *   Step 1: Define the class and imports.
    *   Step 2: Implement the loop for test cases `t`.
    *   Step 3: Implement the reading of `n` and the pairs into a data structure.
    *   Step 4: Implement the sorting logic.
    *   Step 5: Implement the iteration logic, string building, and conditional printing.
    *   Step 6: Refine code for Java syntax (e.g., `String` concatenation vs C++ `string` append).

Here is the Java code:

```java
import java.util.Scanner;
import java.util.Arrays;

class b_1294 {
    static class Pair implements Comparable<Pair> {
        int first;
        int second;

        public Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }

        @Override
        public int compareTo(Pair o) {
            return Integer.compare(this.first, o.first);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int t = sc.nextInt();
            while (t-- > 0) {
                int n = sc.nextInt();
                Pair[] a = new Pair[n];
                for (int i = 0; i < n; i++) {
                    a[i] = new Pair(sc.nextInt(), sc.nextInt());
                }
                Arrays.sort(a);

                int x = 0;
                int y = 0;
                boolean f = false;
                StringBuilder s = new StringBuilder();

                for (int i = 0; i < n; i++) {
                    int u = a[i].first;
                    int v = a[i].second;
                    
                    if (v < y) {
                        f = true;
                        System.out.println("NO");
                        break;
                    }
                    
                    // C++: s+=string(u-x,'R');
                    // Java: Append 'R' (u-x) times
                    int countR = u - x;
                    for (int k = 0; k < countR; k++) {
                        s.append("R");
                    }
                    
                    // C++: s+=string(v-y,'U');
                    // Java: Append 'U' (v-y) times
                    int countU = v - y;
                    for (int k = 0; k < countU; k++) {
                        s.append("U");
                    }
                    
                    x = u;
                    y = v;
                }

                if (!f) {
                    System.out.println("YES");
                    System.out.println(s.toString());
                }
            }
        }
    }
}
```

<CODE>
import java.util.Scanner;
import java.util.Arrays;

class b_1294 {
    static class Pair implements Comparable<Pair> {
        int first;
        int second;

        public Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }

        @Override
        public int compareTo(Pair o) {
            return Integer.compare(this.first, o.first);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int t = sc.nextInt();
            while (t-- > 0) {
                int n = sc.nextInt();
                Pair[] a = new Pair[n];
                for (int i = 0; i < n; i++) {
                    a[i] = new Pair(sc.nextInt(), sc.nextInt());
                }
                Arrays.sort(a);

                int x = 0;
                int y = 0;
                boolean f = false;
                StringBuilder s = new StringBuilder();

                for (int i = 0; i < n; i++) {
                    int u = a[i].first;
                    int v = a[i].second;
                    
                    if (v < y) {
                        f = true;
                        System.out.println("NO");
                        break;
                    }
                    
                    // C++: s+=string(u-x,'R');
                    // Java: Append 'R' (u-x) times
                    int countR = u - x;
                    for (int k = 0; k < countR; k++) {
                        s.append("R");
                    }
                    
                    // C++: s+=string(v-y,'U');
                    // Java: Append 'U' (v-y) times
                    int countU = v - y;
                    for (int k = 0; k < countU; k++) {
                        s.append("U");
                    }
                    
                    x = u;
                    y = v;
                }

                if (!f) {
                    System.out.println("YES");
                    System.out.println(s.toString());
                }
            }
        }
    }
}
</CODE>