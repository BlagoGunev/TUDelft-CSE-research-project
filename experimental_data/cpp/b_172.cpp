#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdlib>
#include <stack>
#include <deque>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <sstream>
using namespace std;
#define mp make_pair
#define int64 long long
const int INF = 1000*1000*1000;
unsigned ri;
unsigned a, b, m;

unsigned rrand() {
    return ri = (a*ri+b)%m;
}

int main (int argc, const char * argv[])
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    clock_t startTime = clock();
#endif
//---------------------------------------------
    scanf("%u%u%u%u", &a, &b, &m, &ri);
    unsigned x = 0;
    for (int i=0; i<100000; i++) {
        x = rrand();
    }
    unsigned cnt = 0;
    unsigned y = -1;
    while (x!=y) {
        y=rrand();
        cnt++;
    }
    printf("%u", cnt);

//---------------------------------------------
#ifndef ONLINE_JUDGE
    clock_t endTime = clock();
    printf("\n%lf", double(endTime-startTime)/CLOCKS_PER_SEC);
	fclose(stdout);
	fclose(stdin);
#endif
    return 0;
}