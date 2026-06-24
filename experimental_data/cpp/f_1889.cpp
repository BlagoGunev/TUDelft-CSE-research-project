#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
 
using namespace std;
 
const int kInfinity = 0x3f3f3f3f;
const int kMaxNodes = 10005;
const int kMaxQueries = 505;
 
/**
 * @brief Structure to represent a fraction.
 *
 * Stores a fraction as numerator/denominator and provides comparison operators.
 */
struct Fraction {
    long long numerator; ///< Numerator of the fraction.
    int denominator; ///< Denominator of the fraction.
 
    /**
     * @brief Constructor for the Fraction structure.
     * @param numerator The numerator of the fraction.
     * @param denominator The denominator of the fraction (default is 1).
     */
    Fraction(long long numerator = 0, int denominator = 1)
        : numerator(numerator), denominator(denominator) {}
 
    /**
     * @brief Less than operator for Fraction comparison.
     * @param other The Fraction to compare with.
     * @return True if this Fraction is less than the other.
     */
    bool operator<(const Fraction &other) const {
        return numerator * other.denominator < other.numerator * denominator;
    }
 
    /**
     * @brief Greater than operator for Fraction comparison.
     * @param other The Fraction to compare with.
     * @return True if this Fraction is greater than the other.
     */
    bool operator>(const Fraction &other) const {
        return numerator * other.denominator > other.numerator * denominator;
    }
 
    /**
     * @brief Equality operator for Fraction comparison.
     * @param other The Fraction to compare with.
     * @return True if both Fractions are equal.
     */
    bool operator==(const Fraction &other) const {
        return numerator * other.denominator == other.numerator * denominator;
    }
 
    /**
     * @brief Prints the fraction in "numerator/denominator" format.
     */
    void printFraction() {
        printf("%lld/%d", numerator, denominator);
    }
};
 
/**
 * @brief Structure to store intermediate results during computation.
 */
struct Value {
    int position1; ///< First position of the value.
    int position2; ///< Second position of the value.
    Fraction fraction1; ///< First fraction value.
    Fraction fraction2; ///< Second fraction value.
 
    /**
     * @brief Constructor for the Value structure.
     * @param position1 First position (default is kInfinity).
     * @param position2 Second position (default is kInfinity).
     * @param fraction1 First fraction (default is 0/1).
     * @param fraction2 Second fraction (default is 0/1).
     */
    Value(int position1 = kInfinity, int position2 = kInfinity, Fraction fraction1 = Fraction(), Fraction fraction2 = Fraction())
        : position1(position1), position2(position2), fraction1(fraction1), fraction2(fraction2) {}
 
    /**
     * @brief Prints the value for debugging purposes.
     */
    void printValue() {
        printf("%d : ", position1);
        fraction1.printFraction();
        puts("");
        printf("%d : ", position2);
        fraction2.printFraction();
        puts("\n");
    }
};
 
/**
 * @brief Combines two Value objects into a single result.
 * @param valueA The first Value object.
 * @param valueB The second Value object.
 * @return A combined Value object.
 */
Value combineValues(Value valueA, Value valueB) {
    if (valueA.position1 > valueB.position1) swap(valueA, valueB);
 
    if (valueB.fraction1 == valueA.fraction1)
        return Value(
            valueA.position1, min(valueA.position2, valueB.position2), valueA.fraction1,
            (valueA.position2 < valueB.position2 ? valueA.fraction2 : valueB.fraction2));
 
    return Value(
        valueA.position1, min(valueA.position2, valueB.position1), valueA.fraction1,
        (valueA.position2 < valueB.position1 ? valueA.fraction2 : valueB.fraction1));
}
 
/**
 * @brief Structure to represent an edge in the graph.
 */
struct Edge {
    int destination; ///< Destination node of the edge.
    int next; ///< Next edge in the adjacency list.
 
    /**
     * @brief Constructor for the Edge structure.
     * @param destination The destination node (default is 0).
     * @param next The next edge index (default is 0).
     */
    Edge(int destination = 0, int next = 0) : destination(destination), next(next) {}
};
 
Edge edges[kMaxNodes * 2]; ///< Array to store all edges.
int head[kMaxNodes], edgeCount; ///< Adjacency list representation of the graph.
 
/**
 * @brief Adds a directed edge to the graph.
 * @param from The source node of the edge.
 * @param to The destination node of the edge.
 */
void addEdge(int from, int to) {
    edges[++edgeCount] = Edge(to, head[from]);
    head[from] = edgeCount;
}
 
long long subtreeSum[kMaxNodes]; ///< Sum of node values in the subtree.
int subtreeSize[kMaxNodes]; ///< Size of the subtree.
int dp[kMaxNodes][kMaxQueries]; ///< DP array for subtree computations.
int weightPosition[kMaxNodes][kMaxQueries]; ///< Weight positions for merging.
Value valueArray[kMaxNodes][kMaxQueries]; ///< Array to store Value objects for each subtree.
int maxNodes, maxQueries; ///< Maximum nodes and queries.
 
/**
 * @brief Merges two subtrees during computation.
 * @param parent The parent node.
 * @param leftChild The left child node.
 * @param rightChild The right child node.
 * @param leftLimit Size limit for the left child subtree.
 * @param rightLimit Size limit for the right child subtree.
 */
void mergeSubtrees(int parent, int leftChild, int rightChild, int leftLimit, int rightLimit) {
    weightPosition[parent][0] = 0;
    valueArray[parent][0] = combineValues(valueArray[leftChild][0], valueArray[rightChild][0]);
 
    leftLimit = min(leftLimit, maxQueries);
    rightLimit = min(rightLimit, maxQueries);
 
    int limit = min(leftLimit + rightLimit, maxQueries);
    for (int i = 1; i <= limit; ++i) {
        int tempWeight = weightPosition[parent][i] = min(leftLimit, i);
        int leftMin = kInfinity, rightMin = kInfinity;
 
        while (tempWeight > 0 && i - tempWeight < rightLimit) {
            leftMin = min(leftMin, dp[leftChild][tempWeight]);
            --tempWeight;
            rightMin = min(rightMin, dp[rightChild][i - tempWeight]);
            if (rightMin < leftMin) {
                weightPosition[parent][i] = tempWeight;
                leftMin = rightMin = kInfinity;
            }
        }
 
        tempWeight = weightPosition[parent][i - 1];
        leftMin = rightMin = kInfinity;
        if (weightPosition[parent][i - 1] < weightPosition[parent][i]) {
            while (tempWeight < weightPosition[parent][i]) leftMin = min(leftMin, dp[leftChild][++tempWeight]);
            dp[parent][i] = leftMin;
        } else {
            while (i - tempWeight - 1 < i - weightPosition[parent][i]) rightMin = min(rightMin, dp[rightChild][i - (tempWeight--)]);
            dp[parent][i] = rightMin;
        }
 
        valueArray[parent][i] = combineValues(valueArray[leftChild][weightPosition[parent][i]], valueArray[rightChild][i - weightPosition[parent][i]]);
    }
}
 
int minSubtreeNodes[kMaxNodes], resultSubtreeSize[kMaxNodes];
long long nodeValue[kMaxNodes]; ///< Array to store the value of each node.
 
/**
 * @brief Performs a depth-first search to calculate subtree properties.
 * @param currentNode The current node being processed.
 * @param parentNode The parent of the current node.
 */
void depthFirstSearch(int currentNode, int parentNode) {
    subtreeSum[currentNode] = nodeValue[currentNode];
    subtreeSize[currentNode] = 0;
    resultSubtreeSize[currentNode] = 1;
    minSubtreeNodes[currentNode] = 0;
 
    int lastEdge = 0, parentEdge = 0;
    for (int i = head[currentNode]; i; i = edges[i].next) {
        int childNode = edges[i].destination;
        if (childNode == parentNode) {
            parentEdge = i;
            continue;
        }
        depthFirstSearch(childNode, currentNode);
        mergeSubtrees(i, i ^ 1, lastEdge, subtreeSize[childNode], subtreeSize[currentNode]);
        subtreeSum[currentNode] += subtreeSum[childNode];
        subtreeSize[currentNode] += subtreeSize[childNode];
        resultSubtreeSize[currentNode] += resultSubtreeSize[childNode];
        lastEdge = i;
    }
 
    if (subtreeSize[currentNode] == 0) {
        ++subtreeSize[currentNode];
        minSubtreeNodes[currentNode] = 1;
        valueArray[parentEdge][0] = valueArray[parentEdge][1] = Value(currentNode, kInfinity, nodeValue[currentNode]);
        dp[parentEdge][1] = kInfinity;
    } else {
        int limit = min(subtreeSize[currentNode], maxQueries);
        for (int i = 0; i <= limit; ++i) {
            valueArray[parentEdge][i] = combineValues(valueArray[lastEdge][i], Value(currentNode, kInfinity, nodeValue[currentNode]));
            dp[parentEdge][i] = dp[lastEdge][i];
        }
 
        Fraction averageFraction(subtreeSum[currentNode], resultSubtreeSize[currentNode]);
        for (int i = 1; i <= limit; ++i) {
            if (valueArray[parentEdge][i].fraction1 > averageFraction || (valueArray[parentEdge][i].fraction1 == averageFraction && valueArray[parentEdge][i].fraction2 > averageFraction)) {
                valueArray[parentEdge][i] = Value(valueArray[parentEdge][i].position1, kInfinity, averageFraction);
                minSubtreeNodes[currentNode] = i;
            }
        }
 
        if (minSubtreeNodes[currentNode]) {
            if (valueArray[parentEdge][0].fraction1 == valueArray[parentEdge][1].fraction1)
                dp[parentEdge][1] = valueArray[parentEdge][0].position2;
            else
                dp[parentEdge][1] = valueArray[parentEdge][0].position1;
 
            for (int i = 2; i <= minSubtreeNodes[currentNode]; ++i)
                dp[parentEdge][i] = kInfinity;
 
            if (minSubtreeNodes[currentNode] < limit) {
                if (valueArray[parentEdge][minSubtreeNodes[currentNode]].fraction1 == valueArray[parentEdge][minSubtreeNodes[currentNode] + 1].fraction1)
                    dp[parentEdge][minSubtreeNodes[currentNode] + 1] = valueArray[parentEdge][minSubtreeNodes[currentNode] + 1].position2;
                else
                    dp[parentEdge][minSubtreeNodes[currentNode] + 1] = valueArray[parentEdge][minSubtreeNodes[currentNode] + 1].position1;
            }
        }
    }
}
 
int solutionStack[kMaxNodes], solutionStackSize;
int queryStack[kMaxNodes], queryStackCount;
 
/**
 * @brief Solves the problem for a specific node and subtree size.
 * @param currentNode The current node being processed.
 * @param parentNode The parent of the current node.
 * @param subtreeLimit The size limit of the subtree.
 */
void solveSubtree(int currentNode, int parentNode, int subtreeLimit) {
    if (subtreeLimit == 0) return;
    subtreeLimit = min(subtreeLimit, subtreeSize[currentNode]);
 
    if (subtreeLimit <= minSubtreeNodes[currentNode]) {
        solutionStack[++solutionStackSize] = currentNode;
        return;
    }
 
    int tempCount = queryStackCount;
    for (int i = head[currentNode]; i; i = edges[i].next) {
        int childNode = edges[i].destination;
        if (childNode == parentNode) continue;
        queryStack[queryStackCount++] = i;
    }
 
    for (int i = queryStackCount - 1; i >= tempCount; --i) {
        int edgeIndex = queryStack[i];
        solveSubtree(edges[edgeIndex].destination, currentNode, weightPosition[edgeIndex][subtreeLimit]);
        subtreeLimit -= weightPosition[edgeIndex][subtreeLimit];
    }
}
 
/**
 * @brief Processes a single tree and performs the necessary operations.
 */
void processSingleTree() {
    int numNodes, root, queryLimit;
 
    scanf("%d", &numNodes);
    scanf("%d", &root);
    scanf("%d", &queryLimit);
 
    maxQueries = queryLimit;
 
    for (int i = 1; i <= numNodes; ++i) {
        scanf("%lld", &nodeValue[i]);
    }
 
    addEdge(root, 0);
 
    for (int i = 1; i < numNodes; ++i) {
        int u, v;
        scanf("%d", &u);
        scanf("%d", &v);
        addEdge(u, v);
        addEdge(v, u);
    }
 
    depthFirstSearch(root, 0);
    solveSubtree(root, 0, queryLimit);
 
    printf("%d\n", solutionStackSize);
    for (int i = 1; i <= solutionStackSize; ++i) {
        printf("%d%c", solutionStack[i], i == solutionStackSize ? '\n' : ' ');
    }
 
    for (int i = 0; i <= numNodes; ++i) head[i] = 0;
    edgeCount = queryStackCount = solutionStackSize = 0;
}
 
/**
 * @brief Main function to process multiple test cases.
 */
int main() {
    int numberOfTrees;
    scanf("%d", &numberOfTrees);
 
    while (numberOfTrees--) {
        processSingleTree();
    }
 
    return 0;
}