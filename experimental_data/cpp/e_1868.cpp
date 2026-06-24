#include <bits/stdc++.h>
using namespace std;

/**
 * @class ProblemSolver
 * @brief Encapsulates the solution for the "Divide the Array" problem.
 *
 * This class holds all data members and helper functions needed to solve the
 * "Divide the Array" problem. The public interface is provided by solveTestCase(),
 * which takes the input array and returns the maximum number of subsegments that
 * satisfy the required conditions.
 */
class ProblemSolver {
private:

    // Constants
    static const int kMaxElements = 350;      ///< Maximum number of elements.
    static const int kInfinity    = 1000000000; ///< A large number used as negative infinity.

    // Private Data Members
    int prefixIndices[kMaxElements + 1];              ///< Holds the discretized prefix sum indices.
    long long prefixSum[kMaxElements + 1];              ///< Stores the prefix sums of the input array.
    long long distinctPrefixSums[kMaxElements + 2];     ///< Stores distinct prefix sum values (0th element holds count).

   
    // Private Helper Functions
    /**
     * @brief Computes a linear index for the 4D DP state.
     *
     * The DP state is conceptually defined as dp[i][j][d][merge],
     * where i and j range over [0, n] (n+1 positions), d is the discretized
     * prefix index (range: 0 .. dimDiscrete-1) and merge is 0 or 1.
     *
     * @param i           The start index.
     * @param j           The end index.
     * @param d           The discretized prefix sum index.
     * @param merge       The merge direction (0 or 1).
     * @param n           The number of elements.
     * @param dimDiscrete The size of the discrete dimension.
     * @return size_t     The computed linear index.
     */
    inline size_t getIndex(int i, int j, int d, int merge, int n, int dimDiscrete) {
        return (((size_t)i * (n + 1) + j) * dimDiscrete + d) * 2 + merge;
    }

    /**
     * @brief Computes the DP table for interval merging.
     *
     * This function fills the dp vector (representing a 4D table) according to
     * the recurrence. The dp vector is of size:
     *   (n+1) * (n+1) * (dimDiscrete) * 2,
     * where n is the number of elements and dimDiscrete is the number of
     * discrete prefix values (typically distinctCount+1).
     *
     * @param dp          The DP vector (by reference) to fill.
     * @param n           The number of elements.
     * @param dimDiscrete The size of the discrete dimension.
     */
    void computeDp(vector<int>& dp, int n, int dimDiscrete) {
        size_t totalSize = (size_t)(n + 1) * (n + 1) * dimDiscrete * 2;
        // Initialize all DP entries to -kInfinity.
        for (size_t idx = 0; idx < totalSize; idx++) {
            dp[idx] = -kInfinity;
        }

        // Process intervals in reverse order for the starting index.
        for (int i = n; i >= 0; i--) {
            // 'pre' and 'suf' track previous and next occurrences.
            vector<int> pre(n + 2, -1), suf(n + 2, -1);
            int now = -1;
            for (int j = i; j <= n; j++) {
                if (i == j) {
                    dp[getIndex(i, j, prefixIndices[j], 0, n, dimDiscrete)] = 0;
                    dp[getIndex(i, j, prefixIndices[j], 1, n, dimDiscrete)] = 0;
                } else {
                    for (int k = i; k <= j; k++) {
                        if (prefixIndices[k] >= prefixIndices[i]) {
                            if (k > 0 && pre[k - 1] != -1) {
                                int candidate = dp[getIndex(i, pre[k - 1], prefixIndices[k], 1, n, dimDiscrete)]
                                              + dp[getIndex(k, j, prefixIndices[i], 0, n, dimDiscrete)]
                                              + 1;
                                int idx = getIndex(i, j, prefixIndices[k], 1, n, dimDiscrete);
                                dp[idx] = max(dp[idx], candidate);
                            }
                            if (suf[k + 1] != -1) {
                                int candidate = dp[getIndex(i, k, prefixIndices[k], 1, n, dimDiscrete)]
                                              + dp[getIndex(suf[k + 1], j, prefixIndices[k], 1, n, dimDiscrete)]
                                              + 1;
                                int idx = getIndex(i, j, prefixIndices[k], 1, n, dimDiscrete);
                                dp[idx] = max(dp[idx], candidate);
                            }
                        }
                        if (prefixIndices[k] <= prefixIndices[i]) {
                            if (k > 0 && pre[k - 1] != -1) {
                                int candidate = dp[getIndex(i, pre[k - 1], prefixIndices[k], 0, n, dimDiscrete)]
                                              + dp[getIndex(k, j, prefixIndices[i], 1, n, dimDiscrete)]
                                              + 1;
                                int idx = getIndex(i, j, prefixIndices[k], 0, n, dimDiscrete);
                                dp[idx] = max(dp[idx], candidate);
                            }
                            if (suf[k + 1] != -1) {
                                int candidate = dp[getIndex(i, k, prefixIndices[k], 0, n, dimDiscrete)]
                                              + dp[getIndex(suf[k + 1], j, prefixIndices[k], 0, n, dimDiscrete)]
                                              + 1;
                                int idx = getIndex(i, j, prefixIndices[k], 0, n, dimDiscrete);
                                dp[idx] = max(dp[idx], candidate);
                            }
                        }
                    }
                }
                if (j > 0) {
                    pre[j] = pre[j - 1];
                }
                if (prefixIndices[j] == prefixIndices[i]) {
                    pre[j] = j;
                    for (int idx = j; idx > now; idx--) {
                        suf[idx] = j;
                    }
                    now = j;
                }
                // Enforce monotonicity in the DP state for merge = 1.
                for (int d = 2; d < dimDiscrete; d++) {
                    int idx = getIndex(i, j, d, 1, n, dimDiscrete);
                    int idxPrev = getIndex(i, j, d - 1, 1, n, dimDiscrete);
                    dp[idx] = max(dp[idx], dp[idxPrev]);
                }
                // Enforce monotonicity in the DP state for merge = 0.
                for (int d = dimDiscrete - 2; d >= 1; d--) {
                    int idx = getIndex(i, j, d, 0, n, dimDiscrete);
                    int idxNext = getIndex(i, j, d + 1, 0, n, dimDiscrete);
                    dp[idx] = max(dp[idx], dp[idxNext]);
                }
            }
        }
    }

public:
    /**
     * @brief Solves a single test case.
     *
     * This public method performs all preprocessing (computing prefix sums and discretization),
     * computes the DP tables (both forward and backward), and then merges the results to obtain
     * the final answer.
     *
     * @param numElements   The number of elements in the input sequence.
     * @param inputSequence The input sequence of integers.
     * @return int          The computed result for this test case.
     */
    int solveTestCase(int numElements, const vector<int>& inputSequence) {
        int n = numElements; // Work with indices 0 .. n.
        // Initialize prefix sum and discretization arrays.
        prefixSum[0] = 0;
        prefixIndices[0] = 0;
        distinctPrefixSums[0] = 0;
        for (int i = 1; i <= n; i++) {
            prefixSum[i] = prefixSum[i - 1] + inputSequence[i - 1];
            distinctPrefixSums[++distinctPrefixSums[0]] = prefixSum[i];
        }
        // Also include 0 in the distinct prefix sums.
        distinctPrefixSums[++distinctPrefixSums[0]] = 0;
        // Sort and remove duplicates.
        sort(distinctPrefixSums + 1, distinctPrefixSums + distinctPrefixSums[0] + 1);
        int distinctCount = unique(distinctPrefixSums + 1, distinctPrefixSums + distinctPrefixSums[0] + 1)
                              - (distinctPrefixSums + 1);
        distinctPrefixSums[0] = distinctCount;
        int dimDiscrete = distinctCount + 1; // Valid discrete indices: 1 .. distinctCount.
        // Discretize: compute prefixIndices for each prefix sum.
        for (int i = 0; i <= n; i++) {
            prefixIndices[i] = (int)(lower_bound(distinctPrefixSums + 1,
                                                  distinctPrefixSums + distinctCount + 1,
                                                  prefixSum[i]) - distinctPrefixSums);
        }

        // Allocate DP arrays dynamically on the heap.
        size_t dpSize = (size_t)(n + 1) * (n + 1) * dimDiscrete * 2;
        vector<int> dpForward(dpSize, -kInfinity), dpBackward(dpSize, -kInfinity);

        // Compute forward DP.
        computeDp(dpForward, n, dimDiscrete);

        // Reverse prefixIndices to compute the backward DP table.
        reverse(prefixIndices, prefixIndices + n + 1);
        computeDp(dpBackward, n, dimDiscrete);
        // Restore the original order.
        reverse(prefixIndices, prefixIndices + n + 1);

        // Combine the DP results to obtain the final answer.
        const int kLowerMerge = 0;
        const int kUpperMerge = 1;
        int result = 1;
        for (int left = 0; left < n; left++) {
            for (int right = left + 1; right <= n; right++) {
                int backwardMergeFlag = (prefixIndices[right] >= prefixIndices[left]) ? kUpperMerge : kLowerMerge;
                int forwardMergeFlag  = (prefixIndices[left] > prefixIndices[right]) ? kUpperMerge : kLowerMerge;
                int candidate = dpBackward[getIndex(n - left, n, prefixIndices[right], backwardMergeFlag, n, dimDiscrete)]
                              + dpForward[getIndex(right, n, prefixIndices[left], forwardMergeFlag, n, dimDiscrete)]
                              + 1;
                result = max(result, candidate);
            }
        }
        return result;
    }
};

/**
 * @brief Main function: Handles input and output.
 *
 * Reads the number of test cases, creates an instance of ProblemSolver, and for each test case,
 * reads the input and prints the computed result.
 *
 * @return int Exit status.
 */
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases;
    cin >> testCases;
    ProblemSolver solver;  // Create an instance of the problem solver.
    while (testCases--) {
        int numElements;
        cin >> numElements;
        vector<int> inputSequence(numElements);
        for (int i = 0; i < numElements; i++) {
            cin >> inputSequence[i];
        }
        cout << solver.solveTestCase(numElements, inputSequence) << "\n";
    }
    return 0;
}