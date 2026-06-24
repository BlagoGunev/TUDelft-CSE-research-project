# include <bits/stdc++.h>

using namespace std;

// Type alias for long long int
using LLI = long long int;

// Constants
constexpr int kMOD = 998244353; // Modulo value for arithmetic
constexpr int kMAXN = 300000;   // Maximum number of elements
constexpr int kMAXQ = 600000;   // Maximum number of queries

// Global arrays
int parent[kMAXN];             // Parent array for disjoint set
int sizeOfSets[kMAXN];         // Size of each set in disjoint set
int queries[kMAXQ][3];         // Array to store query results
int answer[kMAXQ];             // Array to store final answers
int factorial[kMAXN];          // Precomputed factorials
int inverseFactorial[kMAXN];   // Precomputed modular inverse of factorials
int inverseN[kMAXN];           // Precomputed modular inverses of numbers

/**
 * @brief Finds the root of a node using path compression.
 * @param node The node whose root is to be found.
 * @return The root of the set containing the node.
 */
int findRoot(int node) {
    if (parent[node] != node) {
        parent[node] = findRoot(parent[node]);
    }
    return parent[node];
}

/**
 * @brief Computes the modular inverse using binary exponentiation.
 * @param base The number to find the modular inverse for.
 * @return Modular inverse of base modulo kMOD.
 */
int modularInverse(int base) {
    int exponent = kMOD - 2;
    int result = 1;
    while (exponent > 0) {
        if (exponent & 1) {
            result = (static_cast<LLI>(result) * base) % kMOD;
        }
        base = (static_cast<LLI>(base) * base) % kMOD;
        exponent >>= 1;
    }
    return result;
}

int main() {
    int numOfElements, indexToUpdate, valueToUpdate, badThreshold = 1e9;
    int moduloCounts[3] = {0};

    // Input number of elements
    scanf("%d", &numOfElements);

    // Initialize parent and size arrays for disjoint set
    for (int i = 0; i < numOfElements; ++i) {
        parent[i] = i;
        sizeOfSets[i] = 1;
    }
    moduloCounts[0] = 0;
    moduloCounts[1] = numOfElements;
    moduloCounts[2] = 0;

    // Process input pairs to build disjoint sets
    for (int i = 0; i < numOfElements; ++i) {
        scanf("%d %d", &indexToUpdate, &valueToUpdate);
        indexToUpdate--;
        valueToUpdate--;
        int rootX = findRoot(indexToUpdate);
        int rootY = findRoot(valueToUpdate);

        if (rootX != rootY) {
            moduloCounts[sizeOfSets[rootX] % 3]--;
            moduloCounts[sizeOfSets[rootY] % 3]--;
            sizeOfSets[rootY] += sizeOfSets[rootX];
            parent[rootX] = rootY;
            moduloCounts[sizeOfSets[rootY] % 3]++;
        } else if ((sizeOfSets[rootX] % 3) == 0) {
            moduloCounts[0]--;
        } else if (badThreshold == 1e9) {
            badThreshold = i;
        }
        copy(begin(moduloCounts), end(moduloCounts), queries[i]);
    }

    // Precompute factorials and modular inverses
    factorial[0] = 1;
    for (int i = 1; i < numOfElements; i++) {
        factorial[i] = (static_cast<LLI>(i) * factorial[i - 1]) % kMOD;
    }
    inverseFactorial[numOfElements - 1] = modularInverse(factorial[numOfElements - 1]);
    for (int i = numOfElements - 2; i >= 0; i--) {
        inverseFactorial[i] = (static_cast<LLI>(i + 1) * inverseFactorial[i + 1]) % kMOD;
    }
    for (int i = 1; i < numOfElements; i++) {
        inverseN[i] = (static_cast<LLI>(inverseFactorial[i]) * factorial[i - 1]) % kMOD;
    }

    // Process queries to reduce modulo counts
    int m = numOfElements;
    while (moduloCounts[1] + moduloCounts[2] > 0) {
        int a = (moduloCounts[1] > 0) ? 1 : 2;
        moduloCounts[a]--;
        int b = (moduloCounts[1] > 0) ? 1 : 2;
        moduloCounts[b]--;
        moduloCounts[(a + b) % 3]++;
        copy(begin(moduloCounts), end(moduloCounts), queries[m++]);
    }

    // Initialization for calculation
    indexToUpdate = 1;
    valueToUpdate = 1;

    // State variables involved in the recursive computation of query results.
    int u = 1, v = 8;

    // Lambda functions to update states
    auto updateF = [&]() {
        assert(indexToUpdate > 0);
        int newU = (((v - ((static_cast<LLI>(valueToUpdate + 1) * (indexToUpdate + valueToUpdate + 1)) % kMOD) * u) % kMOD) * inverseN[indexToUpdate]) % kMOD;
        int newV = ((((static_cast<LLI>(indexToUpdate) * (indexToUpdate + valueToUpdate + 2)) % kMOD) * newU + static_cast<LLI>(valueToUpdate + 2) * v) % kMOD);
        indexToUpdate--;
        valueToUpdate += 2;
        u = newU;
        v = newV;
        if (u < 0) u += kMOD;
        if (v < 0) v += kMOD;
    };

    auto updateG = [&]() {
        assert(valueToUpdate > 0);
        int newU = (((v - ((static_cast<LLI>(indexToUpdate + 1) * (indexToUpdate + valueToUpdate + 1)) % kMOD) * u) % kMOD) * inverseN[valueToUpdate]) % kMOD;
        int newV = ((((static_cast<LLI>(valueToUpdate) * (indexToUpdate + valueToUpdate + 2)) % kMOD) * newU + static_cast<LLI>(indexToUpdate + 2) * v) % kMOD);
        indexToUpdate += 2;
        valueToUpdate--;
        u = newU;
        v = newV;
        if (u < 0) u += kMOD;
        if (v < 0) v += kMOD;
    };

    // Calculate answers for queries
    for (int i = m - 1; i >= 0; i--) {
        int a = queries[i][1];  // Count of sets with size that leaves a remainder of 1 when divided by 3.
        int b = queries[i][2];  // Count of sets with size that leaves a remainder of 2 when divided by 3.
        int c = queries[i][0];  // Count of sets with size that leaves no remainder when divided by 3.

        if (a == 0 && b == 0) {
            answer[i] = 1;
        } else if (a == indexToUpdate && b == valueToUpdate) {
            answer[i] = u;
        } else if (a == indexToUpdate - 1 && b == valueToUpdate + 2) {
            updateF();
            answer[i] = u;
        } else if (a == indexToUpdate + 2 && b == valueToUpdate - 1) {
            updateG();
            answer[i] = u;
        } else if (a == indexToUpdate + 1 && b == valueToUpdate + 1) {
            if (indexToUpdate > 0) {
                updateF();
                updateG();
                answer[i] = u;
            } else {
                updateG();
                updateF();
                answer[i] = u;
            }
        } else {
            assert(false);
        }

        answer[i] = (static_cast<LLI>(answer[i]) * factorial[a + b + c]) % kMOD;
        answer[i] = (static_cast<LLI>(answer[i]) * inverseFactorial[a + b]) % kMOD;
    }

    // Output results
    for (int i = 0; i < numOfElements; i++) {
        printf("%d\n", (i >= badThreshold) ? 0 : answer[i]);
    }

    return 0;
}