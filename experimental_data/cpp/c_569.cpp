// Problem C (Primes or Palindromes?)
// Codeforces Round #315 (Div 2)

#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

const int arraySize = 1200000;
bool isComposite[arraySize];

void runEratosthenesSieve(int upperBound) {
      int upperBoundSquareRoot = (int)sqrt((double)upperBound);
      for (int m = 2; m <= upperBoundSquareRoot; m++) {
            if (!isComposite[m]) {
                  for (int k = m * m; k <= upperBound; k += m)
                        isComposite[k] = true;
            }
      }
}

bool testPalindromic (int n) {
  if (n == 0) return true;
  int temp = n;
  int temp2 = 0;
  while (temp > 0) {
    temp2 = temp2 * 10 + temp % 10;
    temp = temp/10;
  }
  return temp2 == n;
}

int main () {
  runEratosthenesSieve(arraySize);
  isComposite[0] = true; // Not really
  isComposite[1] = true; // Not really

  int nb1 = 0;
  int nb2 = 0;
  int finalAns = -1;
  int p, q;
  cin >> p >> q;
  for (int i = 1; i < arraySize; i++) {
    if (!isComposite[i])
      nb1++;
    if (testPalindromic(i))
      nb2 ++;
    if (nb1 * q <= nb2 * p)
      finalAns = i;
  }

  if (finalAns != -1)
    cout << finalAns << "\n";
  else
    cout << "Palindromic tree is better than splay tree\n";
}