#include<cmath>

#include<math.h>

#include<ctype.h>

#include<algorithm>

#include<bitset>

#include<cassert>

#include<cctype>

#include<cerrno>

#include<cfloat>

#include<ciso646>

#include<climits>

#include<clocale>

#include<complex>

#include<csetjmp>

#include<csignal>

#include<cstdarg>

#include<cstddef>

#include<cstdio>

#include<cstdlib>

#include<cstring>

#include<ctime>

#include<cwchar>

#include<cwctype>

#include<deque>

#include<exception>

#include<fstream>

#include<functional>

#include<iomanip>

#include<ios>

#include<iosfwd>

#include<iostream>

#include<istream>

#include<iterator>

#include<limits>

#include<list>

#include<locale>

#include<map>

#include<memory>

#include<new>

#include<numeric>

#include<ostream>

#include<queue>

#include<set>

#include<sstream>

#include<stack>

#include<stdexcept>

#include<streambuf>

#include<string>

#include<typeinfo>

#include<utility>

#include<valarray>

#include<vector>

#include<string.h>

#include<stdlib.h>

#include<stdio.h>

using namespace std;

int n,m,res;

int main()

{

	cin>>n>>m;

	if (n>m)

	{

		swap(n,m);

	}

	if (n==1)

	{

		res=(m+2)/3;

	}

	else if (n==2)

	{

		res=(m+2)/2;

	}

	else if (n==3)

	{

		res=m/4*3+m%4;

		if (m%4==0)

		{

			res++;

		}

	}

	else if (n==4)

	{

		res=m;

		if (m==5 || m==6 || m==9)

		{

			res++;

		}

	}

	else if (n==5)

	{

		res=m/5*6+1+m%5;

		if (m==7)

		{

			res--;

		}

		if (m%5>1)

		{

			res++;

		}

	}

	else

	{

		res=10;

	}

	cout<<n*m-res<<endl;

    return 0;

}