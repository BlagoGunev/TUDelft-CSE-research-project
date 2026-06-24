Translate this C++ code to Java code. The main class name should be b2_1970. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
pair<int,int>x[1000050];
pair<int,int>ans[1000050];
int lk[1000050];
pair<int,int> stk[1000050];
int tp=0;
bool cmp(pair<int,int>a,pair<int,int>b){
    return a.second<b.second;
}
bool cmp1(pair<int,int>a,pair<int,int>b){
    return a.first>b.first;
}
int main(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i].first;
        x[i].second=i;
    }
    sort(x+1,x+n+1,cmp1);
    int nw=0,lst;
    for(int i=1;i<=n;i++){
        if(x[i].first==0){
            nw++;
            ans[x[i].second]=make_pair(nw,1);
            lst=x[i].second;
            lk[x[i].second]=x[i].second;
            continue;
        }
        if(i<n&&x[i].first==x[i+1].first){
            nw++;
            ans[x[i].second]=make_pair(nw,x[i].first);
            nw++;
            ans[x[i+1].second]=make_pair(nw,1);
            lk[x[i].second]=x[i+1].second;
            lk[x[i+1].second]=x[i].second;
            lst=x[i+1].second;
            i++;
            continue;
        }else{
            stk[++tp]=x[i];
        }
    }
    int cnt=1;
    for(int i=1;i<=tp;i++){
        if(cnt-stk[i].first+1>=1){
            cnt=cnt-stk[i].first+1;
        }else{
            cnt=cnt+stk[i].first-1;
        }
        nw++;
        ans[stk[i].second]=make_pair(nw,cnt);
        lk[stk[i].second]=lst;
        lst=stk[i].second;
    }
    cout<<"YES\n";
    for(int i=1;i<=n;i++){
        printf("%d %d\n",ans[i].first,ans[i].second);
    }
    for(int i=1;i<=n;i++){
        printf("%d ",lk[i]);
    }
}

Here is the plan for translating the provided C++ code to Java:

1.  **Headers and Imports**: C++ uses `iostream`, `cstring`, `algorithm`, and `cstdio`. Java requires `java.util.Scanner` (or `java.io.BufferedReader`) for input, `java.util.Arrays` for sorting, and `java.util.StringTokenizer` for efficient tokenization if needed.
2.  **Data Structures**:
    *   C++ uses `pair<int,int>` and `vector`-like arrays. Java does not have a built-in `pair` class in the standard library for this context. We will create a simple static inner class `Pair` or use two parallel arrays (`int[] first`, `int[] second`) to store the data. Given the array size (`1000050`), using parallel arrays is often more memory-efficient and easier to manage in Java than creating millions of objects, though a class is cleaner. I will use parallel arrays for performance and simplicity in this algorithmic context.
    *   C++ `sort` function. Java uses `Arrays.sort()`. Since the comparison logic is custom, we must implement a custom comparator.
3.  **Main Logic**:
    *   The `main` function in C++ becomes the `public static void main(String[] args)` method in Java.
    *   `cin` and `cout` are replaced by `Scanner` or `BufferedReader` and `System.out.println`/`System.out.print`.
    *   `make_pair` is replaced by creating a new object or setting values in parallel arrays.
    *   `stk` (stack) is an array.
    *   `tp` (top of stack) is an integer index.
    *   `printf` is replaced by `System.out.print` or `StringBuilder` for better performance (though `Scanner` is slow, `System.out` is buffered enough for this logic, or we can use `PrintWriter`).
4.  **Incremental Tasks**:
    *   Define the `Pair` class.
    *   Define the `main` method and input reading.
    *   Implement the `sort` logic using `Arrays.sort` with a custom `Comparator`.
    *   Implement the first loop (processing `x` array).
    *   Implement the second loop (processing `stk`).
    *   Implement the output logic.
5.  **Specific C++ Features**:
    *   `pair<int,int>`: Translated to a class `Pair` or parallel arrays.
    *   `sort(x+1, x+n+1, cmp1)`: Translated to `Arrays.sort(x, 1, n+1, comparator)`.
    *   `make_pair`: Translated to object creation or array assignment.
    *   `stk[++tp]`: Translated to `stk[++tp]` (Java arrays are 0-indexed, but logic handles 1-based indexing explicitly in C++, so we keep 1-based indexing in Java arrays to match logic).
    *   `printf`: Translated to `System.out.print`.

The code below implements these translations.

```java
import java.util.Scanner;
import java.util.Arrays;
import java.util.Comparator;

public class b2_1970 {

    static class Pair {
        int first;
        int second;

        public Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    // Arrays to store data. 
    // C++ uses pair<int,int>x[1000050];
    // Java uses parallel arrays for efficiency and simplicity.
    static Pair[] x = new Pair[1000050];
    static Pair[] ans = new Pair[1000050];
    static int[] lk = new int[1000050];
    static Pair[] stk = new Pair[1000050];
    static int tp = 0;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        if (!sc.hasNext()) return;
        
        int n = sc.nextInt();
        
        for (int i = 1; i <= n; i++) {
            x[i] = new Pair();
            x[i].first = sc.nextInt();
            x[i].second = i;
        }
        
        // sort(x+1, x+n+1, cmp1);
        // C++ cmp1: return a.first > b.first;
        // Java Arrays.sort uses Comparator
        Arrays.sort(x, 1, n + 1, new Comparator<Pair>() {
            @Override
            public int compare(Pair a, Pair b) {
                return Integer.compare(b.first, a.first); // Descending order
            }
        });
        
        int nw = 0;
        int lst = 0;
        
        for (int i = 1; i <= n; i++) {
            if (x[i].first == 0) {
                nw++;
                ans[x[i].second] = new Pair(nw, 1);
                lst = x[i].second;
                lk[x[i].second] = x[i].second;
                continue;
            }
            
            if (i < n && x[i].first == x[i+1].first) {
                nw++;
                ans[x[i].second] = new Pair(nw, x[i].first);
                nw++;
                ans[x[i+1].second] = new Pair(nw, 1);
                lk[x[i].second] = x[i+1].second;
                lk[x[i+1].second] = x[i].second;
                lst = x[i+1].second;
                i++; // Skip the next element as it was processed
                continue;
            } else {
                stk[++tp] = x[i];
            }
        }
        
        int cnt = 1;
        for (int i = 1; i <= tp; i++) {
            if (cnt - stk[i].first + 1 >= 1) {
                cnt = cnt - stk[i].first + 1;
            } else {
                cnt = cnt + stk[i].first - 1;
            }
            nw++;
            ans[stk[i].second] = new Pair(nw, cnt);
            lk[stk[i].second] = lst;
            lst = stk[i].second;
        }
        
        System.out.println("YES");
        for (int i = 1; i <= n; i++) {
            System.out.println(ans[i].first + " " + ans[i].second);
        }
        for (int i = 1; i <= n; i++) {
            System.out.print(lk[i] + " ");
        }
    }
}
```

<CODE>
import java.util.Scanner;
import java.util.Arrays;
import java.util.Comparator;

public class b2_1970 {

    static class Pair {
        int first;
        int second;

        public Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    // Arrays to store data. 
    // C++ uses pair<int,int>x[1000050];
    // Java uses parallel arrays for efficiency and simplicity.
    static Pair[] x = new Pair[1000050];
    static Pair[] ans = new Pair[1000050];
    static int[] lk = new int[1000050];
    static Pair[] stk = new Pair[1000050];
    static int tp = 0;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        if (!sc.hasNext()) return;
        
        int n = sc.nextInt();
        
        for (int i = 1; i <= n; i++) {
            x[i] = new Pair();
            x[i].first = sc.nextInt();
            x[i].second = i;
        }
        
        // sort(x+1, x+n+1, cmp1);
        // C++ cmp1: return a.first > b.first;
        // Java Arrays.sort uses Comparator
        Arrays.sort(x, 1, n + 1, new Comparator<Pair>() {
            @Override
            public int compare(Pair a, Pair b) {
                return Integer.compare(b.first, a.first); // Descending order
            }
        });
        
        int nw = 0;
        int lst = 0;
        
        for (int i = 1; i <= n; i++) {
            if (x[i].first == 0) {
                nw++;
                ans[x[i].second] = new Pair(nw, 1);
                lst = x[i].second;
                lk[x[i].second] = x[i].second;
                continue;
            }
            
            if (i < n && x[i].first == x[i+1].first) {
                nw++;
                ans[x[i].second] = new Pair(nw, x[i].first);
                nw++;
                ans[x[i+1].second] = new Pair(nw, 1);
                lk[x[i].second] = x[i+1].second;
                lk[x[i+1].second] = x[i].second;
                lst = x[i+1].second;
                i++; // Skip the next element as it was processed
                continue;
            } else {
                stk[++tp] = x[i];
            }
        }
        
        int cnt = 1;
        for (int i = 1; i <= tp; i++) {
            if (cnt - stk[i].first + 1 >= 1) {
                cnt = cnt - stk[i].first + 1;
            } else {
                cnt = cnt + stk[i].first - 1;
            }
            nw++;
            ans[stk[i].second] = new Pair(nw, cnt);
            lk[stk[i].second] = lst;
            lst = stk[i].second;
        }
        
        System.out.println("YES");
        for (int i = 1; i <= n; i++) {
            System.out.println(ans[i].first + " " + ans[i].second);
        }
        for (int i = 1; i <= n; i++) {
            System.out.print(lk[i] + " ");
        }
    }
}
</CODE>