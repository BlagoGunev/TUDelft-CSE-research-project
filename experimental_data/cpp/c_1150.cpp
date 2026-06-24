#include<bits/stdc++.h>
using namespace std;
int n, he = 0, one = 0, two = 0;

inline int read()
{
	int red = 0, f_f = 1; char ch = getchar();
	while(ch>'9'||ch<'0') {if(ch == '-') f_f = -1; ch = getchar();}
	while(ch>='0'&&ch<='9') red = red * 10+ch-'0', ch = getchar();
	return red * f_f;
}

int main()
{
	n = read();
	for(int i = 0; i < n; i++) {
		int a = read();
		he += a, one += 2 - a, two += a - 1;
	}
	if(one == 0) { //只有2无话可说 
		for(int i = 1; i < two; i++) printf("2 ");
		printf("2\n");
	}
	else if(one < 3) {
		if(two >= 1) {
			printf("2 1");
			for(int i = 1; i < two; i++) printf(" 2");
			for(int i = 1; i < one; i++) printf(" 1");
			printf("\n");
		}
		else {
			printf("1");
			for(int i = 1; i < one; i++) printf(" 1");
			printf("\n");
		}
	}
	else {
		printf("1 1 1");
		for(int i = 0; i < two; i++) printf(" 2");
		for(int i = 0; i < one-3; i++) printf(" 1");
		printf("\n");
	}
	return 0;
}