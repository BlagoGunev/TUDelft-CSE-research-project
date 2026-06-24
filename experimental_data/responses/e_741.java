Translate this C++ code to Java code. The main class name should be e_741. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include <bits/stdc++.h>

// Constants for modulo arithmetic and size limitations
constexpr long long kMod = 998244853; // Modulo value used for arithmetic operations to prevent overflow
constexpr int kMaxN = 100010;          // Maximum size for the source and target strings, as well as the number of queries
constexpr int kBlockSize = 75;         // Size of blocks used for certain algorithms or data structures

// Global variables for string processing
int sourceLen;                          // Length of the source string (S)
int targetLen;                          // Length of the target string (T)
int queryNum;                           // Number of queries to process
int rank[kMaxN];                        // Array to store ranks for sorting or comparison purposes
int minTable[kMaxN][25];                // Sparse table for range minimum queries or similar operations
int values[kMaxN];                      // Array to store values associated with each position in the source string
int results[kMaxN];                     // Array to store results for each query
char sourceStr[kMaxN];                  // Character array to hold the source string (S)
char targetStr[kMaxN];                  // Character array to hold the target string (T)
long long powerNum[200010];             // Precomputed powers of a base for hashing or other purposes
long long sourceHash[kMaxN];            // Hash values for the source string (S) for efficient comparison
long long targetHash[kMaxN];            // Hash values for the target string (T) for efficient comparison

/**
 * @brief Lambda function to find minimum rank between two positions
 *
 * @param i First position index
 * @param j Second position index
 * @return Position with minimum rank, or -1 if invalid
 */
auto findMinRank = [](int i, int j) {
    return j == -1 || (i != -1 && rank[i] < rank[j]) ? i : j;
};

/**
 * @brief Structure to handle string view operations and comparisons
 */
struct StringView {
    int pos;  // Position in the source string

    /**
     * @brief Computes rolling hash value at given position
     *
     * @param p Position to compute hash for
     * @return Hash value at position p
     */
    long long computeHash(int p) const {
        // Hash for position within source string
        if (p <= pos) return sourceHash[p];
        
        // Hash for position within target string insertion
        if (p <= pos + targetLen)
            return (sourceHash[pos] * powerNum[p - pos] + targetHash[p - pos]) % kMod;
        
        // Hash for position after target string insertion
        int delta = p - pos - targetLen;
        return (sourceHash[pos] * powerNum[p - pos] +
                targetHash[targetLen] * powerNum[delta] +
                sourceHash[pos + delta] + kMod -
                sourceHash[pos] * powerNum[delta] % kMod) % kMod;
    }

    /**
     * @brief Gets character at given position in the combined string view
     *
     * @param p Position to get character from
     * @return Character at position p
     */
    char getCharAt(int p) const {
        if (p <= pos) return sourceStr[p];
        if (p <= pos + targetLen) return targetStr[p - pos];
        return sourceStr[p - targetLen];
    }

    /**
     * @brief Comparison operator for lexicographical ordering
     */
    bool operator<(const StringView &other) const {
        int left = 0, right = sourceLen + targetLen;
        // Binary search for first differing position
        while (left < right) {
            int mid = (left + right + 1) >> 1;
            if (computeHash(mid) == other.computeHash(mid)) left = mid;
            else right = mid - 1;
        }
        return getCharAt(left + 1) < other.getCharAt(left + 1);
    }
} stringViews[kMaxN];

/**
 * @brief Initializes sparse table for range minimum queries
 *
 * @param size Size of the array to build sparse table for
 */
void initializeSparseTable(int size) {
    // Build sparse table using dynamic programming
    for (int k = 1; (size + 1) >> k; k++) {
        for (int i = 0; i + (1 << k) - 1 <= size; i++) {
            minTable[i][k] = findMinRank(minTable[i][k - 1],
                                       minTable[i + (1 << (k - 1))][k - 1]);
        }
    }
}

/**
 * @brief Queries range minimum using sparse table
 *
 * @param left Left boundary of query range
 * @param right Right boundary of query range
 * @return Minimum rank in the range, or -1 if invalid
 */
int queryRange(int left, int right) {
    if (left > right) return -1;
    int logLen = std::__lg(right - left + 1);
    return findMinRank(minTable[left][logLen],
                      minTable[right - (1 << logLen) + 1][logLen]);
}

/**
 * @brief Structure to store query information
 */
struct QueryInfo {
    int leftBound, rightBound;    // Query boundaries
    int rangeStart, rangeEnd;     // Valid range for insertion
    int queryId;                  // Query identifier
};

// Array of query vectors for each block size
std::vector<QueryInfo> queries[1010];

/**
 * @brief Prepares initial data and processes input
 */
void prepareData() {
    // Read input strings and query count
    std::cin >> (sourceStr + 1) >> (targetStr + 1) >> queryNum;
    sourceLen = std::strlen(sourceStr + 1);
    targetLen = std::strlen(targetStr + 1);

    // Initialize power array for rolling hash
    powerNum[0] = 1;
    for (int i = 1; i <= sourceLen + targetLen; i++) {
        powerNum[i] = powerNum[i - 1] * 131 % kMod;
    }

    // Compute rolling hash for source string
    for (int i = 1; i <= sourceLen; i++) {
        sourceHash[i] = (sourceHash[i - 1] * 131 + sourceStr[i]) % kMod;
    }

    // Compute rolling hash for target string
    for (int i = 1; i <= targetLen; i++) {
        targetHash[i] = (targetHash[i - 1] * 131 + targetStr[i]) % kMod;
    }

    // Initialize string views and sort them
    for (int i = 0; i <= sourceLen; i++) {
        stringViews[i].pos = i;
    }
    std::stable_sort(stringViews, stringViews + sourceLen + 1);

    // Compute ranks and initialize sparse table
    for (int i = 0; i <= sourceLen; i++) {
        rank[stringViews[i].pos] = i;
    }
    std::copy_n(rank, sourceLen + 1, values);
    for (int i = 0; i <= sourceLen; i++) {
        minTable[i][0] = i;
    }
    initializeSparseTable(sourceLen);

    // Process queries
    for (int i = 1, l, r, x, y, k; i <= queryNum; i++) {
        results[i] = -1;
        std::cin >> l >> r >> k >> x >> y;
        if (k > kBlockSize) {
            // Handle large block sizes directly
            for (int w = 0; w <= sourceLen; w += k) {
                int rangeLeft = std::max(l, w + x);
                int rangeRight = std::min(r, w + y);
                if (rangeLeft <= rangeRight) {
                    results[i] = findMinRank(results[i], queryRange(rangeLeft, rangeRight));
                }
            }
        } else {
            // Store small block queries for batch processing
            queries[k].push_back({l, r, x, y, i});
        }
    }
}

/**
 * @brief Solves queries for a specific block size
 *
 * @param blockSize Size of the block to process
 */
void solveBlock(int blockSize) {
    int blockCount = sourceLen / blockSize + 1;
    // Process each remainder separately
    for (int remainder = 0; remainder < blockSize; remainder++) {
        // Initialize sparse table for current remainder
        for (int i = 0; i <= blockCount; i++) {
            minTable[i][0] = (i * blockSize + remainder <= sourceLen) ?
                            i * blockSize + remainder : -1;
        }
        initializeSparseTable(blockCount);

        // Process queries for current block size
        for (const auto &query : queries[blockSize]) {
            if (query.rangeStart <= remainder && remainder <= query.rangeEnd &&
                remainder <= query.rightBound) {
                results[query.queryId] = findMinRank(results[query.queryId],
                    queryRange(query.leftBound <= remainder ? 0 :
                             (query.leftBound - remainder - 1) / blockSize + 1,
                             (query.rightBound - remainder) / blockSize));
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    prepareData();
    // Process all block sizes up to kBlockSize
    for (int i = 1; i <= kBlockSize; i++) {
        solveBlock(i);
    }
    // Output results
    for (int i = 1; i <= queryNum; i++) {
        std::cout << results[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}

Here is the plan for translating the C++ code to Java:

1.  **Language Differences**:
    *   **Header Inclusion**: C++ `#include <bits/stdc++.h>` is replaced by importing necessary classes from the `java.util` package (e.g., `Scanner`, `StringBuilder`, `Arrays`).
    *   **Constants**: C++ `constexpr` constants are replaced by `static final` constants in Java.
    *   **Arrays**: C-style arrays (e.g., `int rank[kMaxN]`) are replaced by Java arrays (e.g., `int[] rank = new int[kMaxN]`).
    *   **Lambda Functions**: C++ lambdas (`auto findMinRank`) are translated to Java `static` methods or functional interfaces. Since the lambda captures no external variables and is simple, a static method is cleaner and more efficient in Java.
    *   **Structs**: C++ structs (`StringView`, `QueryInfo`) are translated to Java `static` classes or inner classes.
    *   **Global Variables**: Global variables in C++ are moved to static members of the main class.
    *   **Pointers/Arrays**: C++ `char*` arrays are translated to `char[]` or `String` in Java. Note: The original code uses `char` arrays for string manipulation. To keep the logic identical, we will use `char[]`.
    *   **`std::string`**: The code uses `std::cin >> charArray`. In Java, we will use `Scanner` to read into a `char[]` or `String` buffer.
    *   **`std::vector`**: Replaced by Java `ArrayList` or `LinkedList`.
    *   **`std::copy_n`**: Replaced by `System.arraycopy` or `Arrays.copyOf`.
    *   **`std::stable_sort`**: Replaced by `Arrays.sort` (Java's sort for primitives is Dual-Pivot Quicksort, which is not stable, but for `Integer` objects it is stable. However, the logic here sorts indices based on a custom comparator. Since we are sorting indices based on ranks, and ranks are unique, stability doesn't strictly matter for correctness, but we must implement the custom comparator).
    *   **`std::lg`**: Replaced by `Integer.numberOfLeadingZeros` or `Math.floorLog` logic.
    *   **`std::ios::sync_with_stdio`**: Replaced by disabling synchronization in `Scanner` (though `Scanner` is inherently slower, we will just use it for simplicity unless performance is critical, but given the constraints, `BufferedReader` + `StringTokenizer` is preferred for competitive programming in Java).
    *   **`std::cout`**: Replaced by `System.out.print` or `PrintWriter`.

2.  **Incremental Tasks**:
    *   **Task 1**: Define constants and global static variables.
    *   **Task 2**: Implement `findMinRank` as a static method.
    *   **Task 3**: Implement `StringView` class and its methods (`computeHash`, `getCharAt`, `compareTo` for sorting).
    *   **Task 4**: Implement `initializeSparseTable` and `queryRange` methods.
    *   **Task 5**: Implement `QueryInfo` class and the `queries` array (as `ArrayList`).
    *   **Task 6**: Implement `prepareData` method. This involves reading input, computing hashes, sorting `StringView` objects, and populating ranks/sparse tables.
    *   **Task 7**: Implement `solveBlock` method. This involves iterating through block sizes and processing queries.
    *   **Task 8**: Implement `main` method to orchestrate the flow and handle I/O.

3.  **Specific Logic Adjustments**:
    *   **Hashing**: The modulo arithmetic logic remains the same, but ensure `long` is used (Java `long` is 64-bit, matching C++ `long long`).
    *   **Sorting**: The C++ code sorts `stringViews` based on rank. We need a custom comparator for this.
    *   **I/O**: The C++ code reads into `char` arrays at index 1. In Java, we can read into a `String` and convert to `char[]`, or manage indices carefully. Given the C++ code uses `sourceStr + 1` (C-style string indexing starting at 1), it's safer to use a `char[]` of size `kMaxN` and fill it directly.

Here is the Java code implementing this plan.

```java
import java.util.*;
import java.io.*;

public class e_741 {
    // Constants for modulo arithmetic and size limitations
    static final long kMod = 998244853L; // Modulo value used for arithmetic operations to prevent overflow
    static final int kMaxN = 100010;          // Maximum size for the source and target strings, as well as the number of queries
    static final int kBlockSize = 75;         // Size of blocks used for certain algorithms or data structures

    // Global variables for string processing
    static int sourceLen;                          // Length of the source string (S)
    static int targetLen;                          // Length of the target string (T)
    static int queryNum;                           // Number of queries to process
    static int[] rank = new int[kMaxN];                        // Array to store ranks for sorting or comparison purposes
    static int[][] minTable = new int[kMaxN][26];                // Sparse table for range minimum queries or similar operations (Note: C++ used 25, Java arrays are 0-indexed usually, but here 25 is max power for 100000. 26 is safer for 0..25). Let's stick to 26 to accommodate index 25 if needed, or keep 25 if the logic strictly uses 0..24. The C++ code accesses minTable[i][k]. If k goes up to 25, size 26 is safer. The C++ code uses kMaxN=100010. The loop for k goes up to log(size). log(100010) is approx 17. So 25 is plenty. We will use 26 to be safe.
    static int[] values = new int[kMaxN];                      // Array to store values associated with each position in the source string
    static long[] results = new long[kMaxN];                     // Array to store results for each query (C++ used long long)
    static char[] sourceStr = new char[kMaxN];                  // Character array to hold the source string (S)
    static char[] targetStr = new char[kMaxN];                  // Character array to hold the target string (T)
    static long[] powerNum = new long[200010];             // Precomputed powers of a base for hashing or other purposes
    static long[] sourceHash = new long[kMaxN];            // Hash values for the source string (S) for efficient comparison
    static long[] targetHash = new long[kMaxN];            // Hash values for the target string (T) for efficient comparison

    /**
     * @brief Function to find minimum rank between two positions
     *
     * @param i First position index
     * @param j Second position index
     * @return Position with minimum rank, or -1 if invalid
     */
    static int findMinRank(int i, int j) {
        if (j == -1 || (i != -1 && rank[i] < rank[j])) {
            return i;
        } else {
            return j;
        }
    }

    /**
     * @brief Structure to handle string view operations and comparisons
     */
    static class StringView {
        int pos;  // Position in the source string

        /**
         * @brief Computes rolling hash value at given position
         *
         * @param p Position to compute hash for
         * @return Hash value at position p
         */
        long computeHash(int p) {
            // Hash for position within source string
            if (p <= pos) return sourceHash[p];
            
            // Hash for position within target string insertion
            if (p <= pos + targetLen)
                return (sourceHash[pos] * powerNum[p - pos] + targetHash[p - pos]) % kMod;
            
            // Hash for position after target string insertion
            int delta = p - pos - targetLen;
            long term1 = (sourceHash[pos] * powerNum[p - pos]) % kMod;
            long term2 = (targetHash[targetLen] * powerNum[delta]) % kMod;
            long term3 = sourceHash[pos + delta];
            long term4 = (sourceHash[pos] * powerNum[delta]) % kMod;
            
            long res = (term1 + term2 + term3 - term4) % kMod;
            if (res < 0) res += kMod;
            return res;
        }

        /**
         * @brief Gets character at given position in the combined string view
         *
         * @param p Position to get character from
         * @return Character at position p
         */
        char getCharAt(int p) {
            if (p <= pos) return sourceStr[p];
            if (p <= pos + targetLen) return targetStr[p - pos];
            return sourceStr[p - targetLen];
        }

        /**
         * @brief Comparison operator for lexicographical ordering
         */
        @Override
        public int compareTo(StringView other) {
            int left = 0, right = sourceLen + targetLen;
            // Binary search for first differing position
            while (left < right) {
                int mid = (left + right + 1) >> 1;
                long hash1 = computeHash(mid);
                long hash2 = other.computeHash(mid);
                if (hash1 == hash2) left = mid;
                else right = mid - 1;
            }
            // left is the last index where hashes match. The first differing index is left + 1.
            // We compare characters at left + 1.
            char c1 = getCharAt(left + 1);
            char c2 = other.getCharAt(left + 1);
            return Character.compare(c1, c2);
        }
    }

    static StringView[] stringViews = new StringView[kMaxN];

    /**
     * @brief Initializes sparse table for range minimum queries
     *
     * @param size Size of the array to build sparse table for
     */
    static void initializeSparseTable(int size) {
        // Build sparse table using dynamic programming
        // The max power needed is roughly log2(size). For 100010, log2 is ~17.
        // We iterate k up to 25 to cover all possibilities safely.
        for (int k = 1; (size + 1) >> k > 0; k++) {
            for (int i = 0; i + (1 << k) - 1 <= size; i++) {
                int left = minTable[i][k - 1];
                int right = minTable[i + (1 << (k - 1))][k - 1];
                minTable[i][k] = findMinRank(left, right);
            }
        }
    }

    /**
     * @brief Queries range minimum using sparse table
     *
     * @param left Left boundary of query range
     * @param right Right boundary of query range
     * @return Minimum rank in the range, or -1 if invalid
     */
    static int queryRange(int left, int right) {
        if (left > right) return -1;
        // std::__lg is floor(log2(x)). For x=1, returns 0.
        // In Java, Integer.numberOfLeadingZeros(2^k) is 32-k.
        // We need floor(log2(right - left + 1)).
        int len = right - left + 1;
        int logLen = 31 - Integer.numberOfLeadingZeros(len);
        
        int leftVal = minTable[left][logLen];
        int rightVal = minTable[right - (1 << logLen) + 1][logLen];
        return findMinRank(leftVal, rightVal);
    }

    // Array of query vectors for each block size
    static ArrayList<QueryInfo>[] queries = new ArrayList[1010];

    /**
     * @brief Structure to store query information
     */
    static class QueryInfo {
        int leftBound, rightBound;    // Query boundaries
        int rangeStart, rangeEnd;     // Valid range for insertion
        int queryId;                  // Query identifier
    }

    /**
     * @brief Prepares initial data and processes input
     */
    static void prepareData() throws IOException {
        // Read input strings and query count
        // Using BufferedReader for speed
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        if (!st.hasMoreTokens()) {
            // Handle case where input might be on multiple lines or empty
            // But based on problem statement, we expect valid input.
            // If sourceStr is empty, we might need to read next line.
            // Assuming standard competitive programming input format.
        }
        
        // Read source string (skip index 0 if using C-style logic, but here we read into array)
        // C++ code: cin >> (sourceStr + 1). This reads into index 1.
        // We need to read the string.
        // Since C++ reads into char array, we read into String and copy to char array.
        // Or we can use a custom reader.
        
        // Let's assume the first token is source string, second is target string.
        // Wait, C++ code does: cin >> (sourceStr + 1) >> (targetStr + 1) >> queryNum;
        // This implies reading three tokens.
        // We need to handle potential newlines.
        
        // Re-reading input logic:
        // We need to read sourceStr and targetStr.
        // The C++ code reads into char arrays starting at index 1.
        // We will read into a String buffer and copy to char array starting at index 1.
        
        // Helper to get next token
        // Since we might have multiple lines, let's implement a simple token reader.
        while (!st.hasMoreTokens()) {
            String line = br.readLine();
            if (line == null) return;
            st = new StringTokenizer(line);
        }
        String sStr = st.nextToken();
        
        while (!st.hasMoreTokens()) {
            String line = br.readLine();
            if (line == null) return;
            st = new StringTokenizer(line);
        }
        String tStr = st.nextToken();
        
        while (!st.hasMoreTokens()) {
            String line = br.readLine();
            if (line == null) return;
            st = new StringTokenizer(line);
        }
        queryNum = Integer.parseInt(st.nextToken());

        // Copy to char arrays starting at index 1
        int lenS = sStr.length();
        int lenT = tStr.length();
        
        // Fill sourceStr
        for (int i = 0; i < lenS; i++) {
            sourceStr[i + 1] = sStr.charAt(i);
        }
        sourceLen = lenS;
        
        // Fill targetStr
        for (int i = 0; i < lenT; i++) {
            targetStr[i + 1] = tStr.charAt(i);
        }
        targetLen = lenT;

        // Initialize power array for rolling hash
        powerNum[0] = 1;
        for (int i = 1; i <= sourceLen + targetLen; i++) {
            powerNum[i] = (powerNum[i - 1] * 131) % kMod;
        }

        // Compute rolling hash for source string
        for (int i = 1; i <= sourceLen; i++) {
            sourceHash[i] = (sourceHash[i - 1] * 131 + sourceStr[i]) % kMod;
        }

        // Compute rolling hash for target string
        for (int i = 1; i <= targetLen; i++) {
            targetHash[i] = (targetHash[i - 1] * 131 + targetStr[i]) % kMod;
        }

        // Initialize string views and sort them
        for (int i = 0; i <= sourceLen; i++) {
            stringViews[i] = new StringView();
            stringViews[i].pos = i;
        }
        // Arrays.sort for objects is stable.
        Arrays.sort(stringViews, 0, sourceLen + 1);

        // Compute ranks and initialize sparse table
        for (int i = 0; i <= sourceLen; i++) {
            rank[stringViews[i].pos] = i;
        }
        // Copy ranks to values
        System.arraycopy(rank, 0, values, 0, sourceLen + 1);
        // Initialize minTable first level
        for (int i = 0; i <= sourceLen; i++) {
            minTable[i][0] = i;
        }
        initializeSparseTable(sourceLen);

        // Initialize queries list
        for (int i = 1; i <= kBlockSize; i++) {
            queries[i] = new ArrayList<>();
        }

        // Process queries
        // We need to read the queries.
        // The C++ code reads queryNum queries.
        // Each query: l r k x y
        // Note: C++ code reads into queryNum.
        // We need to loop queryNum times.
        for (int i = 1; i <= queryNum; i++) {
            results[i] = -1;
            // Read l, r, k, x, y
            while (!st.hasMoreTokens()) {
                String line = br.readLine();
                if (line == null) break;
                st = new StringTokenizer(line);
            }
            int l = Integer.parseInt(st.nextToken());
            int r = Integer.parseInt(st.nextToken());
            int k = Integer.parseInt(st.nextToken());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            
            if (k > kBlockSize) {
                // Handle large block sizes directly
                for (int w = 0; w <= sourceLen; w += k) {
                    int rangeLeft = Math.max(l, w + x);
                    int rangeRight = Math.min(r, w + y);
                    if (rangeLeft <= rangeRight) {
                        results[i] = findMinRank(results[i], queryRange(rangeLeft, rangeRight));
                    }
                }
            } else {
                // Store small block queries for batch processing
                // We need to create a QueryInfo object
                // Note: The C++ code creates a QueryInfo struct inside the loop.
                // We create a new object for each query.
                QueryInfo q = new QueryInfo();
                q.leftBound = l;
                q.rightBound = r;
                q.rangeStart = x;
                q.rangeEnd = y;
                q.queryId = i;
                queries[k].add(q);
            }
        }
    }

    /**
     * @brief Solves queries for a specific block size
     *
     * @param blockSize Size of the block to process
     */
    static void solveBlock(int blockSize) {
        int blockCount = sourceLen / blockSize + 1;
        // Process each remainder separately
        for (int remainder = 0; remainder < blockSize; remainder++) {
            // Initialize sparse table for current remainder
            // We need to reset minTable for the current block structure
            // The C++ code does:
            // for (int i = 0; i <= blockCount; i++) {
            //     minTable[i][0] = (i * blockSize + remainder <= sourceLen) ?
            //                         i * blockSize + remainder : -1;
            // }
            // This logic seems to be building a sparse table for a virtual array of size blockCount,
            // where the i-th element corresponds to position (i * blockSize + remainder).
            // However, the original minTable was built for the full sourceLen.
            // The C++ code re-initializes minTable for the block logic.
            
            // Let's replicate the C++ logic exactly:
            for (int i = 0; i <= blockCount; i++) {
                int pos = (i * blockSize + remainder);
                if (pos <= sourceLen) {
                    minTable[i][0] = pos;
                } else {
                    minTable[i][0] = -1;
                }
            }
            initializeSparseTable(blockCount);

            // Process queries for current block size
            if (queries[blockSize] == null) queries[blockSize] = new ArrayList<>();
            
            for (QueryInfo query : queries[blockSize]) {
                // Condition check
                if (query.rangeStart <= remainder && remainder <= query.rangeEnd &&
                    remainder <= query.rightBound) {
                    
                    int leftIdx = query.leftBound <= remainder ? 0 :
                                   (query.leftBound - remainder - 1) / blockSize + 1;
                    int rightIdx = (query.rightBound - remainder) / blockSize;
                    
                    // Check bounds for the query range indices
                    if (leftIdx >= 0 && leftIdx <= blockCount && rightIdx >= 0 && rightIdx <= blockCount) {
                        // Ensure leftIdx <= rightIdx before querying
                        // The original C++ code calls queryRange directly.
                        // We should ensure left <= right.
                        if (leftIdx <= rightIdx) {
                            results[query.queryId] = findMinRank(results[query.queryId],
                                queryRange(leftIdx, rightIdx));
                        }
                    }
                }
            }
        }
    }

    public static void main(String[] args) {
        // Disable sync
        // In Java, we use BufferedReader for speed, so sync_with_stdio is not strictly needed,
        // but we keep the logic structure.
        
        try {
            prepareData();
            // Process all block sizes up to kBlockSize
            for (int i = 1; i <= kBlockSize; i++) {
                solveBlock(i);
            }
            // Output results
            PrintWriter out = new PrintWriter(System.out);
            for (int i = 1; i <= queryNum; i++) {
                out.print(results[i]);
                out.print(" ");
            }
            out.println();
            out.flush();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
```

### Explanation of Translation Details

1.  **Class Structure**: The C++ `main` function is translated to `main` in a `public class e_741`. Global variables are moved to `static` fields.
2.  **String Handling**: The C++ code uses `char` arrays (`sourceStr`, `targetStr`) and reads directly into them using `cin`. Java's `Scanner` or `BufferedReader` reads strings. To mimic the C++ behavior (1-based indexing), we read the string and copy it into the `char` array starting at index 1.
3.  **Sorting**: The C++ code sorts `stringViews` using `std::stable_sort` with a custom comparator. Java's `Arrays.sort` is stable and accepts a `Comparator`. The custom comparator uses binary search on hash values to determine lexicographical order, similar to the C++ implementation.
4.  **Sparse Table**: The `minTable` is a 2D array. The `initializeSparseTable` function in C++ uses a loop condition `(size + 1) >> k`. In Java, we use `while ((size + 1) >> k > 0)`.
5.  **Queries**: The C++ code uses a global array of vectors `queries[1010]`. Java uses an array of `ArrayList`s.
6.  **Math**:
    *   `std::lg` (log2) is implemented using `Integer.numberOfLeadingZeros`.
    *   Modulo arithmetic is handled carefully to avoid negative results in Java (unlike C++ which handles negative modulo differently).
7.  **I/O**: `std::cin` and `std::cout` are replaced with `BufferedReader` and `PrintWriter` for performance, as Java I/O is generally slower than C++ I/O.

### Final Code

```java
import java.util.*;
import java.io.*;

public class e_741 {
    // Constants for modulo arithmetic and size limitations
    static final long kMod = 998244853L; // Modulo value used for arithmetic operations to prevent overflow
    static final int kMaxN = 100010;          // Maximum size for the source and target strings, as well as the number of queries
    static final int kBlockSize = 75;         // Size of blocks used for certain algorithms or data structures

    // Global variables for string processing
    static int sourceLen;                          // Length of the source string (S)
    static int targetLen;                          // Length of the target string (T)
    static int queryNum;                           // Number of queries to process
    static int[] rank = new int[kMaxN];                        // Array to store ranks for sorting or comparison purposes
    static int[][] minTable = new int[kMaxN][26];                // Sparse table for range minimum queries or similar operations
    static int[] values = new int[kMaxN];                      // Array to store values associated with each position in the source string
    static long[] results = new long[kMaxN];                     // Array to store results for each query
    static char[] sourceStr = new char[kMaxN];                  // Character array to hold the source string (S)
    static char[] targetStr = new char[kMaxN];                  // Character array to hold the target string (T)
    static long[] powerNum = new long[200010];             // Precomputed powers of a base for hashing or other purposes
    static long[] sourceHash = new long[kMaxN];            // Hash values for the source string (S) for efficient comparison
    static long[] targetHash = new long[kMaxN];            // Hash values for the target string (T) for efficient comparison

    /**
     * @brief Function to find minimum rank between two positions
     *
     * @param i First position index
     * @param j Second position index
     * @return Position with minimum rank, or -1 if invalid
     */
    static int findMinRank(int i, int j) {
        if (j == -1 || (i != -1 && rank[i] < rank[j])) {
            return i;
        } else {
            return j;
        }
    }

    /**
     * @brief Structure to handle string view operations and comparisons
     */
    static class StringView {
        int pos;  // Position in the source string

        /**
         * @brief Computes rolling hash value at given position
         *
         * @param p Position to compute hash for
         * @return Hash value at position p
         */
        long computeHash(int p) {
            // Hash for position within source string
            if (p <= pos) return sourceHash[p];
            
            // Hash for position within target string insertion
            if (p <= pos + targetLen)
                return (sourceHash[pos] * powerNum[p - pos] + targetHash[p - pos]) % kMod;
            
            // Hash for position after target string insertion
            int delta = p - pos - targetLen;
            long term1 = (sourceHash[pos] * powerNum[p - pos]) % kMod;
            long term2 = (targetHash[targetLen] * powerNum[delta]) % kMod;
            long term3 = sourceHash[pos + delta];
            long term4 = (sourceHash[pos] * powerNum[delta]) % kMod;
            
            long res = (term1 + term2 + term3 - term4) % kMod;
            if (res < 0) res += kMod;
            return res;
        }

        /**
         * @brief Gets character at given position in the combined string view
         *
         * @param p Position to get character from
         * @return Character at position p
         */
        char getCharAt(int p) {
            if (p <= pos) return sourceStr[p];
            if (p <= pos + targetLen) return targetStr[p - pos];
            return sourceStr[p - targetLen];
        }

        /**
         * @brief Comparison operator for lexicographical ordering
         */
        @Override
        public int compareTo(StringView other) {
            int left = 0, right = sourceLen + targetLen;
            // Binary search for first differing position
            while (left < right) {
                int mid = (left + right + 1) >> 1;
                long hash1 = computeHash(mid);
                long hash2 = other.computeHash(mid);
                if (hash1 == hash2) left = mid;
                else right = mid - 1;
            }
            // left is the last index where hashes match. The first differing index is left + 1.
            // We compare characters at left + 1.
            char c1 = getCharAt(left + 1);
            char c2 = other.getCharAt(left + 1);
            return Character.compare(c1, c2);
        }
    }

    static StringView[] stringViews = new StringView[kMaxN];

    /**
     * @brief Initializes sparse table for range minimum queries
     *
     * @param size Size of the array to build sparse table for
     */
    static void initializeSparseTable(int size) {
        // Build sparse table using dynamic programming
        // The max power needed is roughly log2(size). For 100010, log2 is ~17.
        // We iterate k up to 25 to cover all possibilities safely.
        for (int k = 1; (size + 1) >> k > 0; k++) {
            for (int i = 0; i + (1 << k) - 1 <= size; i++) {
                int left = minTable[i][k - 1];
                int right = minTable[i + (1 << (k - 1))][k - 1];
                minTable[i][k] = findMinRank(left, right);
            }
        }
    }

    /**
     * @brief Queries range minimum using sparse table
     *
     * @param left Left boundary of query range
     * @param right Right boundary of query range
     * @return Minimum rank in the range, or -1 if invalid
     */
    static int queryRange(int left, int right) {
        if (left > right) return -1;
        // std::__lg is floor(log2(x)). For x=1, returns 0.
        // In Java, Integer.numberOfLeadingZeros(2^k) is 32-k.
        // We need floor(log2(right - left + 1)).
        int len = right - left + 1;
        int logLen = 31 - Integer.numberOfLeadingZeros(len);
        
        int leftVal = minTable[left][logLen];
        int rightVal = minTable[right - (1 << logLen) + 1][logLen];
        return findMinRank(leftVal, rightVal);
    }

    // Array of query vectors for each block size
    static ArrayList<QueryInfo>[] queries = new ArrayList[1010];

    /**
     * @brief Structure to store query information
     */
    static class QueryInfo {
        int leftBound, rightBound;    // Query boundaries
        int rangeStart, rangeEnd;     // Valid range for insertion
        int queryId;                  // Query identifier
    }

    /**
     * @brief Prepares initial data and processes input
     */
    static void prepareData() throws IOException {
        // Read input strings and query count
        // Using BufferedReader for speed
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer("");
        
        // Helper to get next token
        // We need to read sourceStr and targetStr.
        // The C++ code reads into char arrays starting at index 1.
        
        while (!st.hasMoreTokens()) {
            String line = br.readLine();
            if (line == null) return;
            st = new StringTokenizer(line);
        }
        String sStr = st.nextToken();
        
        while (!st.hasMoreTokens()) {
            String line = br.readLine();
            if (line == null) return;
            st = new StringTokenizer(line);
        }
        String tStr = st.nextToken();
        
        while (!st.hasMoreTokens()) {
            String line = br.readLine();
            if (line == null) return;
            st = new StringTokenizer(line);
        }
        queryNum = Integer.parseInt(st.nextToken());

        // Copy to char arrays starting at index 1
        int lenS = sStr.length();
        int lenT = tStr.length();
        
        // Fill sourceStr
        for (int i = 0; i < lenS; i++) {
            sourceStr[i + 1] = sStr.charAt(i);
        }
        sourceLen = lenS;
        
        // Fill targetStr
        for (int i = 0; i < lenT; i++) {
            targetStr[i + 1] = tStr.charAt(i);
        }
        targetLen = lenT;

        // Initialize power array for rolling hash
        powerNum[0] = 1;
        for (int i = 1; i <= sourceLen + targetLen; i++) {
            powerNum[i] = (powerNum[i - 1] * 131) % kMod;
        }

        // Compute rolling hash for source string
        for (int i = 1; i <= sourceLen; i++) {
            sourceHash[i] = (sourceHash[i - 1] * 131 + sourceStr[i]) % kMod;
        }

        // Compute rolling hash for target string
        for (int i = 1; i <= targetLen; i++) {
            targetHash[i] = (targetHash[i - 1] * 131 + targetStr[i]) % kMod;
        }

        // Initialize string views and sort them
        for (int i = 0; i <= sourceLen; i++) {
            stringViews[i] = new StringView();
            stringViews[i].pos = i;
        }
        // Arrays.sort for objects is stable.
        Arrays.sort(stringViews, 0, sourceLen + 1);

        // Compute ranks and initialize sparse table
        for (int i = 0; i <= sourceLen; i++) {
            rank[stringViews[i].pos] = i;
        }
        // Copy ranks to values
        System.arraycopy(rank, 0, values, 0, sourceLen + 1);
        // Initialize minTable first level
        for (int i = 0; i <= sourceLen; i++) {
            minTable[i][0] = i;
        }
        initializeSparseTable(sourceLen);

        // Initialize queries list
        for (int i = 1; i <= kBlockSize; i++) {
            queries[i] = new ArrayList<>();
        }

        // Process queries
        // We need to read the queries.
        // The C++ code reads queryNum queries.
        // Each query: l r k x y
        // Note: C++ code reads into queryNum.
        for (int i = 1; i <= queryNum; i++) {
            results[i] = -1;
            // Read l, r, k, x, y
            while (!st.hasMoreTokens()) {
                String line = br.readLine();
                if (line == null) break;
                st = new StringTokenizer(line);
            }
            int l = Integer.parseInt(st.nextToken());
            int r = Integer.parseInt(st.nextToken());
            int k = Integer.parseInt(st.nextToken());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            
            if (k > kBlockSize) {
                // Handle large block sizes directly
                for (int w = 0; w <= sourceLen; w += k) {
                    int rangeLeft = Math.max(l, w + x);
                    int rangeRight = Math.min(r, w + y);
                    if (rangeLeft <= rangeRight) {
                        results[i] = findMinRank(results[i], queryRange(rangeLeft, rangeRight));
                    }
                }
            } else {
                // Store small block queries for batch processing
                // We need to create a QueryInfo object
                // Note: The C++ code creates a QueryInfo struct inside the loop.
                // We create a new object for each query.
                QueryInfo q = new QueryInfo();
                q.leftBound = l;
                q.rightBound = r;
                q.rangeStart = x;
                q.rangeEnd = y;
                q.queryId = i;
                queries[k].add(q);
            }
        }
    }

    /**
     * @brief Solves queries for a specific block size
     *
     * @param blockSize Size of the block to process
     */
    static void solveBlock(int blockSize) {
        int blockCount = sourceLen / blockSize + 1;
        // Process each remainder separately
        for (int remainder = 0; remainder < blockSize; remainder++) {
            // Initialize sparse table for current remainder
            // We need to reset minTable for the current block structure
            // The C++ code does:
            // for (int i = 0; i <= blockCount; i++) {
            //     minTable[i][0] = (i * blockSize + remainder <= sourceLen) ?
            //                         i * blockSize + remainder : -1;
            // }
            // This logic seems to be building a sparse table for a virtual array of size blockCount,
            // where the i-th element corresponds to position (i * blockSize + remainder).
            // However, the original minTable was built for the full sourceLen.
            // The C++ code re-initializes minTable for the block logic.
            
            // Let's replicate the C++ logic exactly:
            for (int i = 0; i <= blockCount; i++) {
                int pos = (i * blockSize + remainder);
                if (pos <= sourceLen) {
                    minTable[i][0] = pos;
                } else {
                    minTable[i][0] = -1;
                }
            }
            initializeSparseTable(blockCount);

            // Process queries for current block size
            if (queries[blockSize] == null) queries[blockSize] = new ArrayList<>();
            
            for (QueryInfo query : queries[blockSize]) {
                // Condition check
                if (query.rangeStart <= remainder && remainder <= query.rangeEnd &&
                    remainder <= query.rightBound) {
                    
                    int leftIdx = query.leftBound <= remainder ? 0 :
                                   (query.leftBound - remainder - 1) / blockSize + 1;
                    int rightIdx = (query.rightBound - remainder) / blockSize;
                    
                    // Check bounds for the query range indices
                    if (leftIdx >= 0 && leftIdx <= blockCount && rightIdx >= 0 && rightIdx <= blockCount) {
                        // Ensure leftIdx <= rightIdx before querying
                        // The original C++ code calls queryRange directly.
                        // We should ensure left <= right.
                        if (leftIdx <= rightIdx) {
                            results[query.queryId] = findMinRank(results[query.queryId],
                                queryRange(leftIdx, rightIdx));
                        }
                    }
                }
            }
        }
    }

    public static void main(String[] args) {
        // Disable sync
        // In Java, we use BufferedReader for speed, so sync_with_stdio is not strictly needed,
        // but we keep the logic structure.
        
        try {
            prepareData();
            // Process all block sizes up to kBlockSize
            for (int i = 1; i <= kBlockSize; i++) {
                solveBlock(i);
            }
            // Output results
            PrintWriter out = new PrintWriter(System.out);
            for (int i = 1; i <= queryNum; i++) {
                out.print(results[i]);
                out.print(" ");
            }
            out.println();
            out.flush();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
```
</think>

<CODE>
import java.util.*;
import java.io.*;

public class e_741 {
    // Constants for modulo arithmetic and size limitations
    static final long kMod = 998244853L; // Modulo value used for arithmetic operations to prevent overflow
    static final int kMaxN = 100010;          // Maximum size for the source and target strings, as well as the number of queries
    static final int kBlockSize = 75;         // Size of blocks used for certain algorithms or data structures

    // Global variables for string processing
    static int sourceLen;                          // Length of the source string (S)
    static int targetLen;                          // Length of the target string (T)
    static int queryNum;                           // Number of queries to process
    static int[] rank = new int[kMaxN];                        // Array to store ranks for sorting or comparison purposes
    static int[][] minTable = new int[kMaxN][26];                // Sparse table for range minimum queries or similar operations
    static int[] values = new int[kMaxN];                      // Array to store values associated with each position in the source string
    static long[] results = new long[kMaxN];                     // Array to store results for each query
    static char[] sourceStr = new char[kMaxN];                  // Character array to hold the source string (S)
    static char[] targetStr = new char[kMaxN];                  // Character array to hold the target string (T)
    static long[] powerNum = new long[200010];             // Precomputed powers of a base for hashing or other purposes
    static long[] sourceHash = new long[kMaxN];            // Hash values for the source string (S) for efficient comparison
    static long[] targetHash = new long[kMaxN];            // Hash values for the target string (T) for efficient comparison

    /**
     * @brief Function to find minimum rank between two positions
     *
     * @param i First position index
     * @param j Second position index
     * @return Position with minimum rank, or -1 if invalid
     */
    static int findMinRank(int i, int j) {
        if (j == -1 || (i != -1 && rank[i] < rank[j])) {
            return i;
        } else {
            return j;
        }
    }

    /**
     * @brief Structure to handle string view operations and comparisons
     */
    static class StringView {
        int pos;  // Position in the source string

        /**
         * @brief Computes rolling hash value at given position
         *
         * @param p Position to compute hash for
         * @return Hash value at position p
         */
        long computeHash(int p) {
            // Hash for position within source string
            if (p <= pos) return sourceHash[p];
            
            // Hash for position within target string insertion
            if (p <= pos + targetLen)
                return (sourceHash[pos] * powerNum[p - pos] + targetHash[p - pos]) % kMod;
            
            // Hash for position after target string insertion
            int delta = p - pos - targetLen;
            long term1 = (sourceHash[pos] * powerNum[p - pos]) % kMod;
            long term2 = (targetHash[targetLen] * powerNum[delta]) % kMod;
            long term3 = sourceHash[pos + delta];
            long term4 = (sourceHash[pos] * powerNum[delta]) % kMod;
            
            long res = (term1 + term2 + term3 - term4) % kMod;
            if (res < 0) res += kMod;
            return res;
        }

        /**
         * @brief Gets character at given position in the combined string view
         *
         * @param p Position to get character from
         * @return Character at position p
         */
        char getCharAt(int p) {
            if (p <= pos) return sourceStr[p];
            if (p <= pos + targetLen) return targetStr[p - pos];
            return sourceStr[p - targetLen];
        }

        /**
         * @brief Comparison operator for lexicographical ordering
         */
        @Override
        public int compareTo(StringView other) {
            int left = 0, right = sourceLen + targetLen;
            // Binary search for first differing position
            while (left < right) {
                int mid = (left + right + 1) >> 1;
                long hash1 = computeHash(mid);
                long hash2 = other.computeHash(mid);
                if (hash1 == hash2) left = mid;
                else right = mid - 1;
            }
            // left is the last index where hashes match. The first differing index is left + 1.
            // We compare characters at left + 1.
            char c1 = getCharAt(left + 1);
            char c2 = other.getCharAt(left + 1);
            return Character.compare(c1, c2);
        }
    }

    static StringView[] stringViews = new StringView[kMaxN];

    /**
     * @brief Initializes sparse table for range minimum queries
     *
     * @param size Size of the array to build sparse table for
     */
    static void initializeSparseTable(int size) {
        // Build sparse table using dynamic programming
        // The max power needed is roughly log2(size). For 100010, log2 is ~17.
        // We iterate k up to 25 to cover all possibilities safely.
        for (int k = 1; (size + 1) >> k > 0; k++) {
            for (int i = 0; i + (1 << k) - 1 <= size; i++) {
                int left = minTable[i][k - 1];
                int right = minTable[i + (1 << (k - 1))][k - 1];
                minTable[i][k] = findMinRank(left, right);
            }
        }
    }

    /**
     * @brief Queries range minimum using sparse table
     *
     * @param left Left boundary of query range
     * @param right Right boundary of query range
     * @return Minimum rank in the range, or -1 if invalid
     */
    static int queryRange(int left, int right) {
        if (left > right) return -1;
        // std::__lg is floor(log2(x)). For x=1, returns 0.
        // In Java, Integer.numberOfLeadingZeros(2^k) is 32-k.
        // We need floor(log2(right - left + 1)).
        int len = right - left + 1;
        int logLen = 31 - Integer.numberOfLeadingZeros(len);
        
        int leftVal = minTable[left][logLen];
        int rightVal = minTable[right - (1 << logLen) + 1][logLen];
        return findMinRank(leftVal, rightVal);
    }

    // Array of query vectors for each block size
    static ArrayList<QueryInfo>[] queries = new ArrayList[1010];

    /**
     * @brief Structure to store query information
     */
    static class QueryInfo {
        int leftBound, rightBound;    // Query boundaries
        int rangeStart, rangeEnd;     // Valid range for insertion
        int queryId;                  // Query identifier
    }

    /**
     * @brief Prepares initial data and processes input
     */
    static void prepareData() throws IOException {
        // Read input strings and query count
        // Using BufferedReader for speed
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer("");
        
        // Helper to get next token
        // We need to read sourceStr and targetStr.
        // The C++ code reads into char arrays starting at index 1.
        
        while (!st.hasMoreTokens()) {
            String line = br.readLine();
            if (line == null) return;
            st = new StringTokenizer(line);
        }
        String sStr = st.nextToken();
        
        while (!st.hasMoreTokens()) {
            String line = br.readLine();
            if (line == null) return;
            st = new StringTokenizer(line);
        }
        String tStr = st.nextToken();
        
        while (!st.hasMoreTokens()) {
            String line = br.readLine();
            if (line == null) return;
            st = new StringTokenizer(line);
        }
        queryNum = Integer.parseInt(st.nextToken());

        // Copy to char arrays starting at index 1
        int lenS = sStr.length();
        int lenT = tStr.length();
        
        // Fill sourceStr
        for (int i = 0; i < lenS; i++) {
            sourceStr[i + 1] = sStr.charAt(i);
        }
        sourceLen = lenS;
        
        // Fill targetStr
        for (int i = 0; i < lenT; i++) {
            targetStr[i + 1] = tStr.charAt(i);
        }
        targetLen = lenT;

        // Initialize power array for rolling hash
        powerNum[0] = 1;
        for (int i = 1; i <= sourceLen + targetLen; i++) {
            powerNum[i] = (powerNum[i - 1] * 131) % kMod;
        }

        // Compute rolling hash for source string
        for (int i = 1; i <= sourceLen; i++) {
            sourceHash[i] = (sourceHash[i - 1] * 131 + sourceStr[i]) % kMod;
        }

        // Compute rolling hash for target string
        for (int i = 1; i <= targetLen; i++) {
            targetHash[i] = (targetHash[i - 1] * 131 + targetStr[i]) % kMod;
        }

        // Initialize string views and sort them
        for (int i = 0; i <= sourceLen; i++) {
            stringViews[i] = new StringView();
            stringViews[i].pos = i;
        }
        // Arrays.sort for objects is stable.
        Arrays.sort(stringViews, 0, sourceLen + 1);

        // Compute ranks and initialize sparse table
        for (int i = 0; i <= sourceLen; i++) {
            rank[stringViews[i].pos] = i;
        }
        // Copy ranks to values
        System.arraycopy(rank, 0, values, 0, sourceLen + 1);
        // Initialize minTable first level
        for (int i = 0; i <= sourceLen; i++) {
            minTable[i][0] = i;
        }
        initializeSparseTable(sourceLen);

        // Initialize queries list
        for (int i = 1; i <= kBlockSize; i++) {
            queries[i] = new ArrayList<>();
        }

        // Process queries
        // We need to read the queries.
        // The C++ code reads queryNum queries.
        // Each query: l r k x y
        // Note: C++ code reads into queryNum.
        for (int i = 1; i <= queryNum; i++) {
            results[i] = -1;
            // Read l, r, k, x, y
            while (!st.hasMoreTokens()) {
                String line = br.readLine();
                if (line == null) break;
                st = new StringTokenizer(line);
            }
            int l = Integer.parseInt(st.nextToken());
            int r = Integer.parseInt(st.nextToken());
            int k = Integer.parseInt(st.nextToken());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            
            if (k > kBlockSize) {
                // Handle large block sizes directly
                for (int w = 0; w <= sourceLen; w += k) {
                    int rangeLeft = Math.max(l, w + x);
                    int rangeRight = Math.min(r, w + y);
                    if (rangeLeft <= rangeRight) {
                        results[i] = findMinRank(results[i], queryRange(rangeLeft, rangeRight));
                    }
                }
            } else {
                // Store small block queries for batch processing
                // We need to create a QueryInfo object
                // Note: The C++ code creates a QueryInfo struct inside the loop.
                // We create a new object for each query.
                QueryInfo q = new QueryInfo();
                q.leftBound = l;
                q.rightBound = r;
                q.rangeStart = x;
                q.rangeEnd = y;
                q.queryId = i;
                queries[k].add(q);
            }
        }
    }

    /**
     * @brief Solves queries for a specific block size
     *
     * @param blockSize Size of the block to process
     */
    static void solveBlock(int blockSize) {
        int blockCount = sourceLen / blockSize + 1;
        // Process each remainder separately
        for (int remainder = 0; remainder < blockSize; remainder++) {
            // Initialize sparse table for current remainder
            // We need to reset minTable for the current block structure
            // The C++ code does:
            // for (int i = 0; i <= blockCount; i++) {
            //     minTable[i][0] = (i * blockSize + remainder <= sourceLen) ?
            //                         i * blockSize + remainder : -1;
            // }
            // This logic seems to be building a sparse table for a virtual array of size blockCount,
            // where the i-th element corresponds to position (i * blockSize + remainder).
            // However, the original minTable was built for the full sourceLen.
            // The C++ code re-initializes minTable for the block logic.
            
            // Let's replicate the C++ logic exactly:
            for (int i = 0; i <= blockCount; i++) {
                int pos = (i * blockSize + remainder);
                if (pos <= sourceLen) {
                    minTable[i][0] = pos;
                } else {
                    minTable[i][0] = -1;
                }
            }
            initializeSparseTable(blockCount);

            // Process queries for current block size
            if (queries[blockSize] == null) queries[blockSize] = new ArrayList<>();
            
            for (QueryInfo query : queries[blockSize]) {
                // Condition check
                if (query.rangeStart <= remainder && remainder <= query.rangeEnd &&
                    remainder <= query.rightBound) {
                    
                    int leftIdx = query.leftBound <= remainder ? 0 :
                                   (query.leftBound - remainder - 1) / blockSize + 1;
                    int rightIdx = (query.rightBound - remainder) / blockSize;
                    
                    // Check bounds for the query range indices
                    if (leftIdx >= 0 && leftIdx <= blockCount && rightIdx >= 0 && rightIdx <= blockCount) {
                        // Ensure leftIdx <= rightIdx before querying
                        // The original C++ code calls queryRange directly.
                        // We should ensure left <= right.
                        if (leftIdx <= rightIdx) {
                            results[query.queryId] = findMinRank(results[query.queryId],
                                queryRange(leftIdx, rightIdx));
                        }
                    }
                }
            }
        }
    }

    public static void main(String[] args) {
        // Disable sync
        // In Java, we use BufferedReader for speed, so sync_with_stdio is not strictly needed,
        // but we keep the logic structure.
        
        try {
            prepareData();
            // Process all block sizes up to kBlockSize
            for (int i = 1; i <= kBlockSize; i++) {
                solveBlock(i);
            }
            // Output results
            PrintWriter out = new PrintWriter(System.out);
            for (int i = 1; i <= queryNum; i++) {
                out.print(results[i]);
                out.print(" ");
            }
            out.println();
            out.flush();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
</CODE>