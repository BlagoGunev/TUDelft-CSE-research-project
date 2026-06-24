#include<bits/stdc++.h> 

using namespace std;



const int maxn = 300 + 10;

int n;

int a[610], b[610];

int tot;



void add(int x){

	for(int i = 1; x > 0; i++){

		while(x > 0 && a[i] < 9){

			 x--; a[i]++;

		}

		tot = max(tot, i);

	}

}



int main(){

	cin >> n;

	for(int i = 1; i <= n; i++) scanf("%d", &b[i]);

	for(int i = 1; i <= n; i++){

		int x = b[i] - b[i-1];

		if(x > 0){

			add(x);

		}else{

			for(int i = 1; ; i++){

				if(a[i] < 9 && x > 0){

					a[i]++; x--;

					tot = max(tot, i);

					add(x);

					break;

				}

				x += a[i];

				a[i] = 0;

			}

		}

		for(int i = tot; i >= 1; i--) printf("%d", a[i]);

		puts("");

	}

	return 0;

}