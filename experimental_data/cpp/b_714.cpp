#include<bits/stdc++.h>

using namespace std;



typedef long long ll;



int a[4];



int main ()

{

	int n, top = 0, t;

	scanf("%d", &n);

	while(n--){

		scanf("%d", &t);

		if(top > 3)

			continue;

		

		bool flag = 1;

		for(int i=0; i<top; i++)

			if(a[i] == t){

				flag = 0;

				break;

			}

		if(flag)

			a[top++] = t;

	}

	

	sort(a, a+3);

	

	printf("%s\n", (top == 3 && a[0] + a[2] == 2 * a[1]) || top < 3 ? "YES" : "NO");

	

	return 0;

}