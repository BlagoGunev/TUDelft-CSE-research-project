#include<stdio.h>
#include<algorithm>

using std::min;

main() {
 short l, r, a; scanf("%d %d %d", &l, &r, &a);
 printf("%d", min((l+r+a)/2, min(l+a, r+a))*2);
}