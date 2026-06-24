#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n, m;

string solution(vector<int> &A, vector<int> &B, int Z) {
	// write your code in C++14 (g++ 6.2.0)
	int last, counter = 0;
	bool valid = true;
	for (int i = 0; i < B.size(); i++)
	{
		counter = 0;
		last = A[i];
		for (int j = i; ; j = B[j])
		{

			if (j == -1)
			{
				if (counter == B.size() && valid)
					return "VALID";
				break;
			}
			if (counter > B.size())break;
			if (abs(last - A[j]) >= Z)
			{
				valid = false;
				break;
			}
			counter++;
			last = A[j];
		}

	}
	return "INVALID";
}
// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(string &S) {
	/*	vector <int>aa = { 10,15,20,30 };
	vector <int>bb = { 1,2,3,-1 };
	cout << solution(aa, bb, 20);
	int v[] = { 1,4,5,0,2 };
	for (int i = 0; i < 4; i=v[i+1]-1)
	{
	v[i] = i + v[i];
	}
	cout << v;*/
	// write your code in C++14 (g++ 6.2.0)
	stack <char> st;
	vector<char> unClosed;
	for (int i = 0; i < S.size(); i++)
	{
		if (S[i] == '(')
			st.push('(');
		else if (S[i] == ')'&&st.size())
			st.pop();
		else if (S[i] == ')' && !st.size())
			unClosed.push_back(')');

	}
	return st.size() + unClosed.size();

}
int main() {

	ios_base::sync_with_stdio(false); cin.tie(0), cout.tie(0);

	long long   a, b = 0, c = 0, t, lj = 0, k = 0, r = 0, l = 0, sum = 0, rr, mn = LLONG_MAX, mx = LLONG_MIN, w, y = 0, x = 0, d, neg = 0, pos = 0, ans = 0;

	string s5 = "", s2 = "", s3 = "", s1 = "", s = "";
	map<char, int>mp;
	cin >> a >> b >> c >> d;
	//if (b > c||d==1)
	
	neg = ceil(float(b) / float(c));
	k = neg*a;
	ans = ceil(k / float(d));



		cout << ans;

}