#include <stdio.h>

int main(){
	int a, b, i;
	char ch;
	scanf("%d", &a);
	scanf("%d", &b);
	i = 0;
	
	while (i != a){
		ch = 97 + i%b;
		printf("%c", ch);
		i++;	
	}
	printf("\n");
	return 0;
}