#include <bits/stdc++.h>

int main()
{
    int x, y, z; scanf("%d%d%d", &x, &y, &z);
    if((x+z > y) && (x > y+z)) printf("+");
    else if((y+z > x) && (y > x+z)) printf("-");
    else if((x+z == y) && (x == y+z)) printf("0");
    else printf("?");
}