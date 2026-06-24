#include <bits/stdc++.h>
//#pragma linker("/STACK:134217728")



#include <cstdio>  // need for the freopen func.

#include <cstddef> // for ::std::size_T

//

#include <iostream>  // for ::std::cout

#include <iomanip>

#include <vector>    // for ::std::vector

#include <string>    // for ::std::string

#include <algorithm> // for algorithms

#include <queue>     // for  ::std::queue

#include <stack>

#include <set>       // for  ::std::set

#include <map>

#include <utility>

#include <functional>

#include <numeric>

#include <cmath>



 

struct node

{

	std::string name;

	int freq[50];

	int total;

	

	node()

	{

		memset(freq, 0, sizeof(freq));

		total = 0;

		

	}

};

struct oldCompare

{

	bool operator()(node const& lhs, node const& rhs)const

	{

		if (lhs.total != rhs.total)

			return lhs.total < rhs.total;

		int i = 0;

		while (i < 50 && lhs.freq[i] == rhs.freq[i])

			++i;

		if (i == 50)

			return false; // equal

		

		return lhs.freq[i] < rhs.freq[i];

	}

};



struct newCompare

{

	bool operator()(node const& lhs,  node const& rhs)const

	{

		if (lhs.freq[0] != rhs.freq[0])

			return lhs.freq[0] < rhs.freq[0];



		if (lhs.total != rhs.total)

			return lhs.total < rhs.total;



		int i = 1;

		while (i < 50 && lhs.freq[i] == rhs.freq[i])

			++i;

		if (i == 50)

			return false;

		return lhs.freq[i] < rhs.freq[i];

	}

};



void myassert(bool b)

{

	if (!b)std::cout << 1 / b << "\n";

}

struct LatinLetter

{

	bool operator()(int i)const

	{

		return i >= 'a' && i <= 'z' ||

			i >= 'A' && i <= 'Z';

	}



};

void solve()

{

	std::size_t t;

	std::cin >> t;

	myassert(t >= 1 && t <= 20);

	std::vector<node> d;

	d.reserve(50);

	static const int ball[100] = { 25, 18, 15, 12, 10, 8, 6, 4, 2, 1 };



	for (std::size_t it = 0; it < t; ++it)

	{

		std::size_t n;

		std::string name;

		std::cin >> n;



		myassert(n >= 1 && n <= 50);



		for (std::size_t i = 0; i < n; ++i)

		{

			std::cin >> name;

			myassert(!name.empty());

			myassert(std::all_of(name.begin(), name.end(), LatinLetter()));



			std::size_t di = 0;

			while (di < d.size() && d[di].name != name)

				++di;

			

			if (di == d.size())

			{

				d.push_back(node());

				d.back().name = name;

			}



			myassert(di < d.size());

			myassert( !d[di].name.empty());

			//if (i < 10)

			{

				d[di].freq[i]++;

				d[di].total += ball[i];

			}

		}

	}



	node old_max, new_max;

	oldCompare colCmp;

	newCompare newCmp;





	myassert(d.size() > 0);

	old_max = d[0];

	new_max = d[0];

	 

	for (std::size_t i = 1; i < d.size(); ++ i)

	{

		

		if (colCmp(old_max, d[i])) // old_max < d

		{

			old_max = d[i];

		}



		if (newCmp(new_max, d[i])) // new_max < d

		{

			new_max = d[i];

		}

	}



	std::cout << old_max.name << "\n";

	std::cout << new_max.name << "\n";



}





int main(int argc, char* argv[])

{



#ifndef ONLINE_JUDGE

	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);

#endif

	

	::std::ios::sync_with_stdio(false);

  

	solve();



	return 0;

	

}