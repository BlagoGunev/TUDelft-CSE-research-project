/*───────────────██
//─────────────░██▓█
//────────────▓██▓▓█░
//───────────██▒─▒▓▓▓
//──────────█▓▒▒░─▒▓█
//────────░██▓▒▒▓▒░▒▓█
//───────▒█▒──▒▓▓▓▓▒▓█░
//──────▓█▓▒──▒▒░░▒▓▓██
//─────██▓▓▓▓▓█▒───▓▓▓█░
//────██▒▓▓█▒───▒███──▓█
//──░████▓░█▒▒█───▓█──▓█░
//─▒██▓░─▓▓▒▒▓█▒───▓──░██
//▓█▓▓▒░▒▓█▓▓██▓██▓███▒▒█▒
//█▓▓▓▓███████▓███████▓▒▒█
//▓██▓███▓░░░░░▓░▓█▒██████▒
//▒▒▓▓▒▒░▒▓░░░░░░░░░▒▒▒▓███
//▓█▓░░░░─▓▓██▒▓▒▒░░░░░░░▒█▓
//▒▒▓▒░░░─▓████▒░▒▒▒▒▒░▒░░░██
//▒▒▓██▓▓▒░─░───░▓▓▓░▓███▒▒▓█
//▓░░▒▒▒─░──────▒▓░▓▒─███▒─▒█▒
//█▒────────░▒░──░▓─░───░░▒▓█▒
//███░───────█───▒──░▒──░▒▒██▒
//─▒███░─────████████░───░▒▓█▓─────────░▓█
//────▒█░──────────────────▒██─────░▓███▒
//█▒────█▒──────────────░▒▓▓█───▓███▒
//▓██─────░░─────────░░▓████████▒
//████▒─────░▒░░░─────███████░
//▓▓████─────────░▓██████▓▓█▓
//█▓▓───────░▓████▓██▓▓▒▒▒▓█░
//▓░───░▒█████▒─────▓█▓▓▒▓▓▓█▒
//─░█████▒───────────▒▓▓▓▒▒▓██▒
//──█░────────────────█▓▓▓▒▒▓▓█░
//▓░──────────────────█▓▓▓█▒▓▓██
//───────────────────▒█████▓▓▓▓█▒
──────────────────░──░██▓▓▓▓██▓
─────────────────▒▒░────▒█▓▓▓█░
*/


/*
####     ####              %%%%%%       $$$$$      &&&&&&&&
## ##   ## ##    0 0 0     %%    %     $           ^^^^^^^^
##  ## ##  ##   0  ||| 0   $$$$$$       $            ()()
               0   ...  0  $$   &         $          ()()
##   ##    ##  0   ***  0  $$    $          #        ()()
##         ##   0  $$$ 0   $$     @           $      ()()
##         ##     0  0                         %     ()()
                                          $$$$$%   00000000
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>
#include <set>
#include <list>
#include <map>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
#include <cctype>
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define lp(i,n) for(int i = 0; i < n; i++)
#define I int
#define LL long long
#define ULL unsigned long long
#define D double
#define F float
#define MOD 1000000007
#define PI 3.141592653589793238462643383279502884
using namespace std;
bool Is_Prime(LL n){
	if(n == 1)
		return false;
	else{
		for(I i = 2; i <=sqrt(n); i ++){
			if (n % i == 0)
				return false;
		}
	}
	return true;
}
bool Is_Vowel (char c) {
	string s = "aeiouAEIOU";
	for(unsigned int  i = 0; i < s.size(); i++) {
		if (s[i] == c)
			return true;
	}
	return false;
}
long long BinTODes(string s) {
	LL base = 1, Decimal_num = 0;
	for (I i = s.size() - 1; i >= 0; i--) {
		if (s[i] == '1')
		   Decimal_num += base;
		base *= 2;
	}
	return Decimal_num;
}
int GCD (int n, int m) {
	vector <int> vec;
	for (int i = 1; i <= min(n, m); i++) {
		if(m % i == 0 && n % i == 0)
			vec.push_back(i);
	}
	sort(vec.rbegin(), vec.rend());
	return vec[0];
}
long long Fibonacci (long long n) {
	if (n <= 1)
		return 1;
	return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main()
{
    IOS
    LL t, lenB = 0, lenA=0, lenC=0;
    cin >> t;
    string s;
    while(t--) {
        cin >> s;
        lenB = 0, lenA=0, lenC=0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'A')
                lenA++;
            else if(s[i] == 'B')
                lenB++;
            else
                lenC++;

        }
        if((lenC + lenA) == lenB)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}