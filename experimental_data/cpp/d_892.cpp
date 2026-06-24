#include <bits/stdc++.h>
#define che
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define PB push_back
#define MP make_pair
using namespace std;
typedef long long LL;
const int MAXN = 22 +10;

int a[30], b[30], n;
struct number{
	int a, b, id;
}p[30];
bool cmp_a(number x, number y) { return x.a < y.a;}
bool cmp_id(number x, number y){ return x.id < y.id;}
int main(){
	scanf("%d", &n);
	for (int i=0; i<n ;i++)scanf("%d", &p[i].a) , p[i].id= i;
	sort(p, p+n,cmp_a);
	for (int i=1; i<n; i++) p[i].b = p[i-1].a; 
	sort(p, p+n, cmp_a);
	p[0].b = p[n-1].a;
	sort(p, p+n, cmp_id);
	for (int i=0; i<n ;i++) printf("%d ", p[i].b);
	return 0;
}