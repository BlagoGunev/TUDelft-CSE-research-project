/*
 * In The Name Of ALLAH
 * created by Harolinch
 */
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

#include <algorithm>
#include <list>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <numeric>

#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <memory.h>
#include <ctype.h>
#include <string.h>
using namespace std;


#define siz(a)			(int)a.size()

#define rep(i, a, n)	for(int i = a; i<=n; i++)


class Solution {
public:
    void solve(std::istream& in, std::ostream& out) {
		string s;
		in >> s;

		int indof2 = -1;
		rep(i, 0, siz(s) - 1)
			if (s[i] == '2') {
				indof2 = i;
				break;
			}
		int ones = 0;
		rep(i, 0, siz(s) - 1)
			if (s[i] == '1')
				ones++;
		rep(i, 0, siz(s) - 1) {
			if (i == indof2) {
				while (ones--)
					out << '1';
				out << '2';
			}
			else if(s[i] != '1')
				out << s[i];
		}
		if (ones > 0)
			while (ones--)
				out << '1';
	}
};

void solve(std::istream& in, std::ostream& out)
{
    out << std::setprecision(12);
    Solution solution;
    solution.solve(in, out);
}


int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    istream& in = cin;


    ostream& out = cout;

    solve(in, out);
    return 0;
}