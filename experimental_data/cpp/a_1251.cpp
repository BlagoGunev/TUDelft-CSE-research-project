/*
 * File   : 0.cpp
 * Author : Jiayuan Mao
 * Email  : maojiayuan@gmail.com
 * Date   : 10/24/2019
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

int t, n;
char s[505];
bool work[128];

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("\n%s", s);
        n = strlen(s);
        memset(work, 0, sizeof(work));
        for (int i = 0; i < n;) {
            int j = i;
            while (j < n && s[i] == s[j]) ++j;
            if ((j-i)%2 == 1) work[s[i]] = true;
            i = j;
        }
        for (char i = 'a'; i <= 'z'; ++i) {
            if (work[i]) putchar(i);
        }
        printf("\n");
    }

    return 0;
}