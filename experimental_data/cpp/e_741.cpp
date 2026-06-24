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