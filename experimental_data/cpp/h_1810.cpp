#include <cstdio>
#include <cmath>

/**
 * @brief Recursively computes a specialized floor-sum.
 *
 * This function computes a sum of floor divisions based on the parameters provided.
 * The computation is used later in calculating the final remaining number after
 * repeatedly removing the smallest and largest numbers from the initial set.
 *
 * @param count Number of terms to process (derived from n in the summation).
 * @param coeff The coefficient multiplied by the term index.
 * @param offset The additive offset.
 * @param divisor The divisor used for the floor division.
 * @param result Reference variable where the computed sum is stored.
 */
void computeFloorSum(__int128 count, __int128 coeff, __int128 offset, __int128 divisor, __int128 &result) {
    if (count < 0) {
        result = 0;
        return;
    }
    if (coeff >= divisor || offset >= divisor) {
        computeFloorSum(count, coeff % divisor, offset % divisor, divisor, result);
        result += (coeff / divisor) * (count * (count + 1) / 2) + (offset / divisor) * (count + 1);
    } else if (coeff) {
        __int128 m = (coeff * count + offset) / divisor;
        computeFloorSum(m - 1, divisor, divisor - offset - 1, coeff, result);
        result = count * m - result;
    }
}

/**
 * @brief Main function to solve the "H. Last Number" problem.
 *
 * The problem begins with the multiset S = {1, 2, 3, …, n}. In each operation,
 * the smallest and largest numbers are removed and replaced by their difference.
 * After n - 1 operations exactly one number remains. This function reads multiple
 * test cases, performs a binary search to compute an optimal index, and then uses
 * several calls to computeFloorSum to determine the final number.
 *
 * @return int Exit status.
 */
int main() {
    int testCases;
    std::scanf("%d", &testCases);

    // Precomputed constants used in the floor-sum computation.
    __int128 kConstFactor1 = (__int128)2000000000000000000LL * 1000000000;
    __int128 kConstFactor2 = (__int128)1000000000000000000LL * 1000000000;
    __int128 kConstFactor3 = (__int128)1618033988749894848LL * 1000000000 + 204586834;

    // Constant for the golden ratio.
    const long double kGoldenRatio = (1 + std::sqrt((long double)5)) / 2;

    // Process each test case.
    while (testCases--) {
        int initialSetSize;
        std::scanf("%d", &initialSetSize);

        int optimalIndex = 0;
        int low = 0;
        int high = initialSetSize - 1;

        /**
         * @brief Binary search loop to determine an optimal index.
         *
         * The loop adjusts the search boundaries based on a condition that uses floor
         * division by the golden ratio. The optimal index is updated accordingly.
         */
        while (low <= high) {
            int midIndex = (low + high) / 2;
            if (initialSetSize - std::floor(midIndex / kGoldenRatio) <= midIndex + midIndex) {
                optimalIndex = midIndex;
                high = midIndex - 1;
            } else {
                low = midIndex + 1;
            }
        }

        // Variables to hold the intermediate results from the floor-sum computations.
        __int128 floorSumResult1, floorSumResult2, floorSumResult3, floorSumResult4;
        computeFloorSum((initialSetSize - 1) / 2, kConstFactor1, 0, kConstFactor3, floorSumResult1);
        computeFloorSum((optimalIndex - 1) / 2, kConstFactor1, 0, kConstFactor3, floorSumResult2);
        computeFloorSum((initialSetSize - 2) / 2, kConstFactor1, kConstFactor2, kConstFactor3, floorSumResult3);
        computeFloorSum((optimalIndex - 2) / 2, kConstFactor1, kConstFactor2, kConstFactor3, floorSumResult4);

        // Calculate the final answer using the computed floor sums and the optimal index.
        __int128 finalResult = optimalIndex + (optimalIndex % 2 ? -1 : 1) *
                                ((floorSumResult1 - floorSumResult2) - (floorSumResult3 - floorSumResult4));
        if ((initialSetSize - optimalIndex) % 2) {
            finalResult = initialSetSize - finalResult;
        }

        // Output the final result.
        std::printf("%lld\n", (long long)finalResult);
    }
    return 0;
}