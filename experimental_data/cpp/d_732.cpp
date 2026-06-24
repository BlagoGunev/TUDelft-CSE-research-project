#include <bits/stdc++.h>

using namespace std;

class pivote {

	int loc;

	public:

		pivote(int n) {

			loc = n;

		}

		int nuevo(vector<int>&lista) {

			while(loc>=0 and !lista[loc]) --loc;

			--loc;

			return loc+1;

		}

};

bool intentar(vector<int>&list1, vector<int>&list2, int tiempo) {

	vector <bool> list3(list2.size());

	pivote greedy(tiempo-1);

	int pendientes = list3.size();

	while(tiempo>0) {

		int aux = greedy.nuevo(list1);

		if(aux<0)  {

			tiempo = 0;

			goto fin;

		}

		if(aux<list2[list1[aux]-1]) return false;

		if(!list3[list1[aux]-1]) {

			--pendientes;

			list3[list1[aux]-1] = true;

			tiempo -= list2[list1[aux]-1]+1;

		}



		fin:



		if(!pendientes and tiempo>=0) return true;

	}

	return false;

}

int bs(vector<int>&days,vector<int>&dep) {

	int izq = 2, der = days.size();

	while(izq<=der) {

		int centro = (der-izq)/2+izq;

		bool sePuede = intentar(days, dep, centro), ant = intentar(days, dep, centro-1);

		if(sePuede and !ant) return centro;

		if(!sePuede) izq = centro+1; else der = centro-1;

	}

	return -1;

}

int main() {

	int n, m, suma = 0;

	scanf("%d%d", &n, &m);

	vector <int> d(n), a(m);

	for(int i=0;i<n;++i) scanf("%d", &d[i]);

	for(int i=0;i<m;++i) {

		scanf("%d", &a[i]);

		suma += a[i];

	}

	if(suma>n-m) printf("-1\n"); else printf("%d\n", bs(d, a));

}