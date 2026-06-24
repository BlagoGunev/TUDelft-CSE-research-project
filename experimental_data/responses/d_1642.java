Translate this C++ code to Java code. The main class name should be d_1642. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <array>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <chrono>

#define ld long double
#define ll long long
#define ull unsigned long long
#define inf 1e9

using namespace std;

vector<int> segs;
vector<pair<int,int>> ans;

int go(int base, vector<int>& s){
    // cout<<base<<endl;
    // for(auto a:s){
    //     cout<<a;
    // }
    // cout<<endl;
    int n = s.size();
    if(n==0){
        return base;
    }
    for(int i=1;i<n;i++){
        if(s[i]==s[0]){
            for(int j=1;j<i;j++){
                ans.emplace_back(s[j],base+i+j-1);
            }
            segs.push_back(base);
            vector<int> next;
            for(int k=i-1;k>=1;k--){
                next.push_back(s[k]);
            }
            for(int k=i+1;k<n;k++){
                next.push_back(s[k]);
            }
            return go(base+2*i,next);
        }
    }
    return 0;
}

void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    map<int,int> counts;
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<n;i++){
        counts[arr[i]]++;
    }
    for(auto a:counts){
        if(a.second&1){
            cout<<-1<<"\n";
            return;
        }
    }
    int total = go(0,arr);
    cout<<ans.size()<<"\n";
    for(auto a:ans){
        cout<<a.second+1<<" "<<a.first<<"\n";
    }
    cout<<segs.size()<<"\n";
    segs.push_back(total);
    for(int i=1;i<segs.size();i++){
        cout<<segs[i]-segs[i-1]<<" ";
    }
    cout<<"\n";
    segs.clear();
    ans.clear();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<setprecision(15)<<fixed;
    int t=1;
    cin >> t;
    for (int c = 0; c < t; c++)
    {   
        // cout<<"Case #"<<c+1<<": ";
        solve();
    }
}

Here is the plan for the translation from C++ to Java:

### Translation Plan

1.  **Imports**: Replace C++ standard library headers with corresponding Java classes (`java.util.*`, `java.io.*`, `java.math.*`).
2.  **Main Class**: Create a public class `d_1642` with a `main` method.
3.  **Data Structures**:
    *   `vector<int>` becomes `ArrayList<Integer>`.
    *   `vector<pair<int,int>>` becomes `ArrayList<int[]>` (since Java doesn't have a built-in Pair class in standard imports without specific libraries, we use an array of size 2).
    *   `map<int,int>` becomes `HashMap<Integer, Integer>`.
    *   `setprecision` and `fixed` are not strictly needed for integer output, so we can remove them or keep them if mixed types were involved (here we only output integers, so they are irrelevant).
4.  **Input/Output**:
    *   Use `Scanner` or `BufferedReader` for input. Given the complexity of the logic, `BufferedReader` with a `StringTokenizer` is preferred for performance.
    *   Use `PrintWriter` or `StringBuilder` for output to handle large amounts of data efficiently.
5.  **Logic Translation**:
    *   `go` function becomes a static method.
    *   `solve` function becomes a static method.
    *   `long double` (`ld`) is not used in the code, so ignored.
    *   `inf` is not used in the code, so ignored.
    *   `segs` and `ans` become static `ArrayList`s.
    *   C++ references (`vector<int>& s`) are replaced by `ArrayList<Integer> s` (pass by value/reference in Java works similarly for objects).
    *   `s.size()` is `s.size()`.
    *   `s[i]` is `s.get(i)`.
    *   `counts[arr[i]]++` is `counts.put(arr[i], counts.getOrDefault(arr[i], 0) + 1)`.
    *   `a.second` and `a.first` (from Pair) are accessed as `a[1]` and `a[0]`.
6.  **Incremental Tasks**:
    *   Step 1: Set up class structure and IO.
    *   Step 2: Translate `solve` method logic.
    *   Step 3: Translate `go` method logic.
    *   Step 4: Translate `main` method.

### Code Implementation

```java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.StringTokenizer;

public class d_1642 {
    
    static List<Integer> segs = new ArrayList<>();
    static List<int[]> ans = new ArrayList<>();

    static int go(int base, List<Integer> s){
        // System.out.println(base);
        // for(Integer a:s){
        //     System.out.println(a);
        // }
        // System.out.println();
        int n = s.size();
        if(n==0){
            return base;
        }
        for(int i=1;i<n;i++){
            if(s.get(i).equals(s.get(0))){
                for(int j=1;j<i;j++){
                    ans.add(new int[]{s.get(j), base+i+j-1});
                }
                segs.add(base);
                List<Integer> next = new ArrayList<>();
                for(int k=i-1;k>=1;k--){
                    next.add(s.get(k));
                }
                for(int k=i+1;k<n;k++){
                    next.add(s.get(k));
                }
                return go(base+2*i, next);
            }
        }
        return 0;
    }

    static void solve(){
        int n;
        try {
            String line = reader.readLine();
            while (line != null && line.trim().isEmpty()) {
                line = reader.readLine();
            }
            if (line == null) return;
            StringTokenizer st = new StringTokenizer(line);
            n = Integer.parseInt(st.nextToken());
        } catch (Exception e) {
            return;
        }
        
        List<Integer> arr = new ArrayList<>();
        Map<Integer, Integer> counts = new HashMap<>();
        for(int i=0;i<n;i++){
            try {
                String line = reader.readLine();
                while (line != null && line.trim().isEmpty()) {
                    line = reader.readLine();
                }
                if (line == null) break;
                st = new StringTokenizer(line);
                arr.add(Integer.parseInt(st.nextToken()));
            } catch (Exception e) {
                break;
            }
        }
        
        for(Integer val : counts.keySet()){
            if(counts.get(val) % 2 != 0){
                out.println("-1");
                return;
            }
        }
        
        // Re-reading logic correction: The C++ code reads all integers in a loop.
        // In the Java implementation above, I tried to simulate line-by-line reading which 
        // might be incorrect if all integers are on the same line. 
        // Let's refactor the reading logic to be robust for CP inputs (all on one line usually).
    }

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

    public static void main(String[] args) {
        FastScanner sc = new FastScanner();
        PrintWriter out = new PrintWriter(System.out);
        
        // Check if input exists
        String tStr = sc.next();
        if (tStr == null) return;
        int t = Integer.parseInt(tStr);
        
        for (int c = 0; c < t; c++) {
            solve(sc, out);
        }
        
        out.flush();
    }

    // Refactored solve to use FastScanner and PrintWriter
    static void solve(FastScanner sc, PrintWriter out) {
        String nStr = sc.next();
        if (nStr == null) return;
        int n = Integer.parseInt(nStr);
        
        List<Integer> arr = new ArrayList<>();
        Map<Integer, Integer> counts = new HashMap<>();
        for(int i=0;i<n;i++){
            String s = sc.next();
            if (s != null) {
                arr.add(Integer.parseInt(s));
                counts.put(Integer.parseInt(s), counts.getOrDefault(Integer.parseInt(s), 0) + 1);
            }
        }
        
        for(Integer a : counts.keySet()){
            if(counts.get(a) % 2 != 0){
                out.println("-1");
                return;
            }
        }
        
        // Note: The C++ code calls go(0, arr). 
        // However, inside go, it modifies the static 'ans' and 'segs'.
        // Since 'arr' is passed by reference (in C++), it behaves like a reference in Java.
        // But wait, the C++ code passes 'arr' to 'go'.
        // In C++, 'arr' is a local vector. 
        // The C++ code does: vector<int> arr(n); ... go(0, arr);
        // Inside go: vector<int> next; ... return go(..., next);
        // The original 'arr' is NOT modified in place. A new vector is created.
        // So the static 'segs' and 'ans' are the only shared state.
        
        int total = go(0, arr);
        
        out.println(ans.size());
        for(int[] pair : ans){
            // ans stores {s[j], base+i+j-1} -> {start_index, length}
            // C++: cout<<a.second+1<<" "<<a.first<<"\n";
            // Java: pair[1] is second, pair[0] is first.
            out.println((pair[1]+1) + " " + pair[0]);
        }
        
        out.println(segs.size());
        for(int i=1;i<segs.size();i++){
            out.print(segs.get(i)-segs.get(i-1) + " ");
        }
        out.println();
        
        segs.clear();
        ans.clear();
    }
}
```

```java
<CODE>
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.StringTokenizer;

public class d_1642 {
    
    static List<Integer> segs = new ArrayList<>();
    static List<int[]> ans = new ArrayList<>();

    static int go(int base, List<Integer> s){
        // System.out.println(base);
        // for(Integer a:s){
        //     System.out.println(a);
        // }
        // System.out.println();
        int n = s.size();
        if(n==0){
            return base;
        }
        for(int i=1;i<n;i++){
            if(s.get(i).equals(s.get(0))){
                for(int j=1;j<i;j++){
                    ans.add(new int[]{s.get(j), base+i+j-1});
                }
                segs.add(base);
                List<Integer> next = new ArrayList<>();
                for(int k=i-1;k>=1;k--){
                    next.add(s.get(k));
                }
                for(int k=i+1;k<n;k++){
                    next.add(s.get(k));
                }
                return go(base+2*i, next);
            }
        }
        return 0;
    }

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
            if (s == null) return 0; 
            return Integer.parseInt(s);
        }
    }

    public static void main(String[] args) {
        FastScanner sc = new FastScanner();
        PrintWriter out = new PrintWriter(System.out);
        
        String tStr = sc.next();
        if (tStr == null) return;
        int t = Integer.parseInt(tStr);
        
        for (int c = 0; c < t; c++) {
            solve(sc, out);
        }
        
        out.flush();
    }

    static void solve(FastScanner sc, PrintWriter out) {
        String nStr = sc.next();
        if (nStr == null) return;
        int n = Integer.parseInt(nStr);
        
        List<Integer> arr = new ArrayList<>();
        Map<Integer, Integer> counts = new HashMap<>();
        for(int i=0;i<n;i++){
            String s = sc.next();
            if (s != null) {
                arr.add(Integer.parseInt(s));
                counts.put(Integer.parseInt(s), counts.getOrDefault(Integer.parseInt(s), 0) + 1);
            }
        }
        
        for(Integer a : counts.keySet()){
            if(counts.get(a) % 2 != 0){
                out.println("-1");
                return;
            }
        }
        
        int total = go(0, arr);
        
        out.println(ans.size());
        for(int[] pair : ans){
            out.println((pair[1]+1) + " " + pair[0]);
        }
        
        out.println(segs.size());
        for(int i=1;i<segs.size();i++){
            out.print(segs.get(i)-segs.get(i-1) + " ");
        }
        out.println();
        
        segs.clear();
        ans.clear();
    }
}
</CODE>
```