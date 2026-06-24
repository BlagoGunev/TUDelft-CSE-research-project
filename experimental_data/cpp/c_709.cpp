#include <stdio.h>

#include <string.h>

#include <math.h>

#include <algorithm>

using namespace std;

const int MAX_N = 100010;



char s[MAX_N];



int main()

{

	while (~scanf("%s", &s)) {

		int len = strlen(s);

		int flag = 0;

		for (int i = 0; i < len; ++i) {

			if (flag == 1 && s[i] == 'a') break;

			if (s[i] != 'a') {

				s[i] = s[i] - 1;

				flag = 1;

			}

		}

		if (flag == 0) s[len - 1] = 'z';

		printf("%s\n", s);

	}

	return 0;

}