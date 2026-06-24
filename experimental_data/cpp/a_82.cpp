#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

char str[5][10] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};

int main() {
    int n, tmp, sum, i;
    while (scanf("%d", &n) != EOF) {
        tmp = 1;
        sum = 0;
        while (1) {
            if (sum + tmp * 5 > n) break;
            sum += 5 * tmp;
            tmp *= 2;
        }
        n -= sum;
        bool flag = 0;
        if (n % tmp) flag = 1;
        n /= tmp;
        if (flag) n++;
        printf("%s\n", str[(n + 4) % 5]);
    }
    return 0;
}