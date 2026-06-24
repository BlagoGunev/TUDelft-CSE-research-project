#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

int len, p1, p2, ans;
char s[500005];

int main() {
	gets(s);
	len = strlen(s);
	p1 = 0;
	while ( s[p1] != '[' && p1 < len ) p1++;
	while ( s[p1] != ':' && p1 < len ) p1++;
	p2 = len - 1;
	while ( p2 > 0 && s[p2] != ']' ) p2--;
	while ( p2 > 0 && s[p2] != ':' ) p2--;
	if ( p1 >= p2 ) printf("-1\n");
	else {
		for ( int i = p1 + 1; i < p2; i++ ) {
			if ( s[i] == '|' ) ans++;
		}
		printf("%d\n", ans + 4);
	}
	return 0;
}