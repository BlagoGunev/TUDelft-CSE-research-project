#include<bits/stdc++.h>

#define LL long long

using namespace std;



string a, b, c;



int str[505];

int str2[505];



int main() {

	cin >> a >> b >> c;

	

	for(int i = 0; i < a.length(); i++) str[int(a[i])]++;

	for(int i = 0; i < b.length(); i++) str[int(b[i])]++;

	for(int i = 0; i < c.length(); i++) str2[int(c[i])]++;

	

	for(int i = 0; i < 505; i++) {

		if (str[i] != str2[i]) {

			printf("NO\n");

			return 0;

		}

	}

	printf("YES\n");

}