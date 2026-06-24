#include <cstdio>

using namespace std;

const int N = 1000000;

char s[N + 2];
char stack[N];
int stack_top = -1;
char match[256];

int main() {
	
	match['>'] = '<';
	match['}'] = '{';
	match[']'] = '[';
	match[')'] = '(';
	
	scanf("%s", s);
	
	int res = 0;
	for (int i = 0; s[i]; i++) {
		if (match[s[i]]) {
			if (stack_top < 0 || match[stack[stack_top]]) {
				printf("Impossible\n");
				return 0;
			}
			if (stack[stack_top] != match[s[i]])
				res++;
			
			stack_top--;
		}
		else {
			stack_top++;
			stack[stack_top] = s[i];
		}
	}
	
	if (stack_top != -1) {
		printf("Impossible\n");
	}
	else {
		printf("%d\n", res);
	}
	
	return 0;
}