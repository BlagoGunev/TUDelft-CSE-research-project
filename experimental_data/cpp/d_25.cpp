#include <iostream>

#include <cstdio>

#include <vector>

using namespace std;



  struct Data

  {

  	int x, y;

  } t;



  int n, x, y, cnt;

  int par[1001], rnk[1001];

  

  vector <Data> v;

  vector <int> arr;

  

  void make_set (int v)

  {

  	par[v] = v;

  }

  

  int find_set (int v)

  {

  	 if (v == par[v])

  	 	return v;

  	 return par[v] = find_set (par[v]);

  }

  

  void union_set (int a, int b)

  {

  	a = find_set (a);

  	b = find_set (b);

  	

  	if (a != b)

  	{

  		if (rnk[a] < rnk[b]);

  			swap (a, b);

  		par[b] = a;

  		if (rnk[a] == rnk[b])

  			rnk[a]++;

  	}

  	else

  	{

  		cnt++;

  		t.x = x;

  		t.y = y;

  		v.push_back(t); 

  	}

  }



int main()

{

	 cin >> n;

	 for (int i = 1; i <= n; i++)

	 		make_set (i);

	 		

	 for (int i = 1; i < n; i++)

	 {

	 	   scanf ("%d %d", &x, &y);

	 	   union_set (x, y);

	 }

	

	 for (int i = 1; i <= n; i++)

	 	if (par[i] == i)

	 		arr.push_back (i);

	

	cout << cnt << endl;

	for (int i = 0; i < cnt; i++)

		printf ("%d %d %d %d \n", v[i].x, v[i].y, arr[0], arr[i+1]);//

 return 0;///

}