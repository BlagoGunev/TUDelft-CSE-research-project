Translate this C++ code to Java code. The main class name should be a_381. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    int n;
    while(cin>>n){
        int sc1=0, sc2=0; vector<int>cards;
        while(n--){
            int num;
            cin>>num;
            cards.push_back(num);
        }
        int i=1;
        while(cards.size()!=0){
            if(cards[0]>cards[cards.size()-1]){
                if(i%2==0)
                    sc2+=cards[0];
                else
                    sc1+=cards[0];

                cards.erase(cards.begin());
            }
            else{
                if(i%2==0)
                    sc2+=cards[cards.size()-1];
                else
                    sc1+=cards[cards.size()-1];

                cards.erase(cards.begin()+cards.size()-1);
            }
            i++;
        }
        cout<<sc1<<" "<<sc2<<endl;
    }
    return 0;
}

Here is the plan for translating the C++ code to Java:

1.  **Headers and Imports**:
    *   C++ headers like `<vector>`, `<list>`, `<map>`, `<iostream>`, `<algorithm>` etc. correspond to Java classes.
    *   `std::vector` translates to `java.util.ArrayList` or `java.util.Vector`. `ArrayList` is generally preferred for its performance and dynamic resizing capabilities similar to C++ `std::vector`.
    *   `std::cin` and `std::cout` translate to `java.util.Scanner` and `java.util.PrintWriter` or direct `System.out`. Given the logic involves a `while(cin >> n)` loop, `Scanner` is the most straightforward choice.
    *   `std::endl` translates to `System.out.println()`.

2.  **Main Method**:
    *   C++ `main()` returns `int`. Java `main` must have the signature `public static void main(String[] args)`.
    *   The `using namespace std;` directive is not used in Java. Instead, fully qualified class names or imports are used.

3.  **Logic Translation**:
    *   **Variable Types**: `int` in C++ maps directly to `int` in Java.
    *   **Input Loop**: `while(cin >> n)` becomes `while (scanner.hasNextInt()) { int n = scanner.nextInt(); ... }`.
    *   **Vector Operations**:
        *   `vector<int> cards` becomes `ArrayList<Integer> cards`.
        *   `cards.push_back(num)` becomes `cards.add(num)`.
        *   `cards.size()` becomes `cards.size()`.
        *   `cards[0]` becomes `cards.get(0)`.
        *   `cards[cards.size()-1]` becomes `cards.get(cards.size() - 1)`.
        *   **Crucial Difference**: C++ `vector` is a dynamic array. Accessing an element by index is $O(1)$. Removing an element (`erase`) is $O(N)$ (shifting elements). In Java `ArrayList`, `remove(int index)` is also $O(N)$. Since the loop runs while `size` decreases by 1 each time, the complexity is roughly $O(N^2)$ for a single test case. Java's `ArrayList` is sufficient.
        *   `cards.erase(cards.begin())` becomes `cards.remove(0)`.
        *   `cards.erase(cards.begin() + cards.size() - 1)` becomes `cards.remove(cards.size() - 1)`.
    *   **Control Flow**: `if/else` and `while` loops translate directly.
    *   **Output**: `cout << sc1 << " " << sc2 << endl` becomes `System.out.println(sc1 + " " + sc2)`.

4.  **Incremental Tasks**:
    *   Step 1: Define class structure and imports.
    *   Step 2: Translate input loop (`while(cin>>n)`).
    *   Step 3: Translate inner loop logic (reading `n` integers into `ArrayList`).
    *   Step 4: Translate the processing logic (comparing first and last elements, updating sums, removing elements).
    *   Step 5: Translate output and close resources (optional but good practice).

5.  **Specific C++ vs Java nuances**:
    *   C++ `vector` stores primitives (`int`). Java `ArrayList` stores objects (`Integer`). Autoboxing handles the conversion between `int` and `Integer`.
    *   C++ `cin >> n` skips whitespace automatically. `Scanner.nextInt()` does the same.
    *   C++ `endl` flushes the buffer. `System.out.println` does not necessarily flush immediately unless the stream is connected to a console or explicitly flushed, but for competitive programming style outputs, it behaves correctly.

Here is the resulting Java code:

<CODE>
import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;

public class a_381 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            List<Integer> cards = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                cards.add(scanner.nextInt());
            }

            int sc1 = 0;
            int sc2 = 0;
            int i = 1;

            while (cards.size() != 0) {
                if (cards.get(0) > cards.get(cards.size() - 1)) {
                    if (i % 2 == 0) {
                        sc2 += cards.get(0);
                    } else {
                        sc1 += cards.get(0);
                    }
                    cards.remove(0);
                } else {
                    if (i % 2 == 0) {
                        sc2 += cards.get(cards.size() - 1);
                    } else {
                        sc1 += cards.get(cards.size() - 1);
                    }
                    cards.remove(cards.size() - 1);
                }
                i++;
            }
            System.out.println(sc1 + " " + sc2);
        }
        scanner.close();
    }
}
</CODE>