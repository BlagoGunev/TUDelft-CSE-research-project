#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define DO long double
#define pb push_back
#define pfr push_front
#define eb emplace_back
#define ef emplace_front
#define gc getchar_unlocked
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mp make_pair
#define vi vector<int>
#define vll vector<ll>
#define fr(i,j,k) for(i = j; i < k; i++)
#define bck(i,j,k) for(i = j; i > k; i--)

//////////////////////////////////////////////////////////////////////////////////////////
#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); cerr << '\n'; }
vector<string> split(const string& s, char c) {
	vector<string> v;
	stringstream ss(s);
	string x;
	while (getline(ss, x, c))
		v.emplace_back(x);
	return move(v);
}
void err(vector<string>::iterator it) { }
template<typename T, typename... Args>
void err(vector<string>::iterator it, T a, Args... args) {
	cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << '\t';
	err(++it, args...);
}
////////////////////////////////////////////////////////////////////////////////////////////








int main(){

    string s;
    cin >> s;
    int n = s.size();
    if( n <= 6)
    {
        cout << "no";
        return 0;
    }

    int j = n+1, k = 0, i;
    for(i = 0; i < n; i++){
        if(s[i] == '1'){
            j = i;
            break;
        }
    }
    for(i = j+1; i < n; i++){
        if(s[i] == '0')
            k++;
    }
    if(k >= 6)
        cout << "yes";
    else
        cout << "no";

    return 0;
}