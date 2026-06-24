#include <vector>

#include <list>

#include <map>

#include <math.h>

#include <cmath>

#include <set>

#include <queue>

#include <deque>

#include <string>

#include <stack>

#include <bitset>

#include <algorithm>

#include <functional>

#include <numeric>

#include <utility>

#include <string.h>

#include <sstream>

#include <iostream>

#include <iomanip>

#include <cstdio>

#include <cstdlib>

#include <ctime>

#include <unordered_map>



using namespace std;



#define ll  long long int

#define ld long double



int main()

{

	ios::sync_with_stdio(false);

	ios_base::sync_with_stdio(false);

	cin.tie(nullptr), cout.tie(nullptr);

	//freopen("input.txt", "r", stdin);

	//freopen("output.txt", "w", stdout);

	int n;

	string input;

	cin >> n;

	cin >> input;

	if (n == 24)

	{

		if (input[0] > '2')input[0] = '0';

		else if (input[0] == '2' && input[1]>'3')input[1] = '0';

		if (input[3] > '5')input[3] = '0';

	}

	else

	{

		if (input[0] == '0'  && input[1] == '0')input[1] = '1';

		else if (input[0] == '1' && input[1] > '2')input[1] = '1';

		else if (input[0] >= '2' && input[1] >= '1' && input[1] <= '9')input[0] = '0';

		else if (input[0] >= '2' && input[1] == '0')input[0] = '1';



		if (input[3] > '5')input[3] = '0';

	}

	cout << input << endl;

	return 0;

}