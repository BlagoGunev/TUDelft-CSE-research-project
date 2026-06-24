#include <cstdio>

#include <iostream>

#include <list>

using namespace std;



const int MAXN = 1e6 + 10;

int n, k, c;

list <int> popis;



#define getch getchar



inline int readint() {

	static int n, ch;

	n = 0, ch = getchar();

	while (!isdigit(ch)) ch = getchar();

	while (isdigit(ch)) n = (n << 3) + (n << 1) + ch - '0', ch = getchar();

	return n;

}



int main() {

    scanf("%d%d", &n, &k);

    for(int i = 2; i <= k; i++) {

        int d = 1;

        while(k % (d * i) == 0)

            d *= i;

        k /= d;

        if(d > 1)

            popis.push_back(d);

    }

    for(int i = 0; i < n; i++) {

        c = readint();

        for(list <int> :: iterator iter = popis.begin(); iter != popis.end(); iter++) {

            if(c % *iter == 0)

                popis.erase(iter--);

        }

    }

    if(popis.empty())

        printf("Yes\n");

    else

        printf("No\n");



    return 0;

}