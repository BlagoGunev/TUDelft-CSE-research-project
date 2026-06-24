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

 

#include <memory>



using namespace std;





void solve()

{

	int L, D, V, G, R;

	cin >> L >> D >> V >> G >> R;

	double t;

	//1. L <= D ==> time = L/V

	if (L <= D)

	{

		t = (double)L / (double)V;

	}

	else // L > D

	{

		// D/V  > (G+R)*x

		//x = D/V /(G+R)

		 

		t = (double)L / (double)V;



		// D/V  [ 0..g, g..r]

		double xv = D / (double)V;

		

		while (xv > G + R + 1.0E-12)

			xv -= (G + R);



		// now  0<= xv <= G+R

		if ( xv >= -1.0E-12 && xv < G - 1.0E-12 || xv > G + R - 1.0E-12)

		{

			//zeleniy, not tormozid

		}

		else// G<= xv <= G + R

		{

			xv = G + R - xv;

			if (xv > 1.0E-12)

			t += xv;

		}



	}



	cout << setprecision(12) << fixed << t << endl;

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