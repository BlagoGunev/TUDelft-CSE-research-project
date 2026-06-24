#include <iostream>

#include <vector>

#include <stdio.h>

#include <algorithm>



using namespace std;



vector <int> sobras;



int main (){

	int n,p1=0,p2=0;

	scanf ("%d", &n);

	for (int i = 0; i < n; i++){

		int x;

		scanf ("%d", &x);

		if (x % 2 == 0){

			for (int j = 0; j < x/2; j++){

				int atual;

				scanf ("%d", &atual);

				p1 += atual;

			}

			for (int j = x/2; j < x; j++){

				int atual;

				scanf ("%d", &atual);

				p2 += atual;

			}

			

		}

		else{

			for (int j = 0; j < x/2; j++){

				int atual;

				scanf ("%d", &atual);

				p1 += atual;

			}

			int sobra;

			scanf ("%d", &sobra);

			sobras.push_back(sobra);

			for (int j = x/2 + 1; j < x; j++){

				int atual;

				scanf ("%d", &atual);

				p2 += atual;

			}

		}

	}

	sort (sobras.begin(), sobras.end());

	int j = 0;

	for (int i = (int)sobras.size()-1; i >= 0 ; i--){

		if (j % 2 == 0) p1 += sobras[i];

		else p2+=sobras[i];

		j++;

	}

	printf ("%d %d", p1, p2);

return 0;

}