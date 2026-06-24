#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int b[300000], n, m, i, x, atual, ult, aux;
vector<int> T, P;
int ok;
	

void KmpPreprocess()
{
	int i=0, j = -1;
	b[0] = -1;
	while(i<m)
	{
		while(j>=0 && P[i] != P[j])
			j = b[j];
		i++;
		j++;
		b[i] = j;
	}
}

void KmpSearch()
{
	int i=0, j=0;
	while(i<n)
	{
		while(j>=0 && T[i] != P[j])
			j = b[j];
		i++;
		j++;
		if(j == m)
		{
			ok++;
			j = b[j];
		}
	}
}

typedef long long int ll;

int main()
{
	ios_base::sync_with_stdio(0);

	while(cin >> n >> m)
	{
		if(m == 1)
		{
			cout << n << endl;
			return 0;
		}
		T.clear();
		P.clear();
		ok = 0;
		cin >> aux;
		ult = aux;
		for(i=1; i<n; i++)
		{
			cin >> x;
			atual = x;
			T.push_back(atual - ult);
			ult = atual;
		}
		
		cin >> aux;
		ult = aux;
		for(i=1; i<m; i++)
		{
			cin >> x;
			atual = x;
			P.push_back(atual - ult);
			ult = atual;
		}
		n--;m--;
		KmpPreprocess();
		KmpSearch();
		
		
		cout << ok << endl;
	}
	
	return 0;
}