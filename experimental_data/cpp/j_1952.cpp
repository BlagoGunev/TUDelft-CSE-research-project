#include<bits/stdc++.h>

#ifdef jlocal
#include<jdebug/debug.hpp>
#else
#define debug(...) 0;
#endif

using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef vector<pii> vii;

#if defined(__LP64__) || defined(_WIN64)
typedef __int128 lll;
#endif

#define pcount(x) __builtin_popcount(x)
#define pcountll(x) __builtin_popcountll(x)
#define all(x) x.begin(),x.end()

const ld pi = 3.14159265358979323846L;
const ld sqrt2 = 1.41421356237309504880L;

template<class T>
istream& operator>>(istream& in, vector<T> &a){
	for (int i = 0; i < a.size(); i ++)
		in >> a[i];
	return in;
}

template<class T>
ostream& operator<<(ostream& out, vector<T> &a){
	for (int i = 0; i < a.size(); i ++){
		if (i > 0) out << ' ';
		out << a[i];
	}
	return out;
}

#if defined(__LP64__) || defined(_WIN64)

istream& operator>>(istream& in, __int128 &x){
	string S;
	in >> S;
	for (char &y : S){
		x *= 10;
		x += (y - '0');
	}
	return in;
}

ostream& operator<<(ostream& out, __int128 &x){
	string s;
	while(x > 0){
		s.push_back((x % 10) + '0');
		x /= 10;
	}
	return out << s;
}

#endif

mt19937_64 MT64;
void pre_init() {
	MT64 = mt19937_64(chrono::system_clock::now().
	time_since_epoch().count());
}

string leer(char x){
	return "yoink " + string(1, x) + "\n";
}

string setea(string x, string y){
	return "bruh " + x + " is lowkey just " + y + "\n";
}

string add(string x, string y){
	return "*slaps " + y + " on top of " + x + "*\n"; 
}

string ge(string x, string t){
	return "vibe check " + x + " ratios " + t + "\n";
}

string go_to(int x){
	return "simp for " + to_string(x) + "\n";
}

string decir(string x){
	return "yeet " + x + "\n";
}

string end_code(){
	return "go touch some grass\n";
}

string res(string x, string y){
	return "rip this " + x + " fell off by " + y + "\n";
}

void solve(int caso){
	int x;
	cin >> x;
	if (x == 1){
		cout << "yoink a\nyoink b\n*slaps a on top of b*\nyeet b\ngo touch some grass\n";
	}
	else if (x == 2){
		cout << "yoink a\nbruh b is lowkey just 0\nrip this b fell off by a\nvibe check a ratios b\nsimp for 7\nbruh a is lowkey just b\nyeet a\ngo touch some grass\n";
	}
	else if (x == 3){
		cout << "yoink n\nyoink a\nbruh m is lowkey just a[0]\nbruh i is lowkey just 1\nvibe check n ratios i\nsimp for 9\nyeet m\ngo touch some grass\nvibe check a[i] ratios m\nbruh m is lowkey just a[i]\n*slaps 1 on top of i*\nsimp for 5\n";
	}
	else{
		vector<string> code;
		code.push_back(leer('n'));
		code.push_back(leer('a'));
		code.push_back(leer('k'));
		code.push_back(setea("i", "0"));
		code.push_back(ge("n", "i"));
		code.push_back(go_to(8));
		code.push_back(go_to(21));
		code.push_back(setea("j", "i"));
		code.push_back(add("j", "1"));
		code.push_back(ge("n", "j"));
		code.push_back(go_to(13));
		code.push_back(go_to(19));
		code.push_back(ge("a[i]", "a[j]"));
		code.push_back(go_to(18));
		code.push_back(setea("aux", "a[i]"));
		code.push_back(setea("a[i]", "a[j]"));
		code.push_back(setea("a[j]", "aux"));
		code.push_back(go_to(9));
		code.push_back(add("i", "1"));
		code.push_back(go_to(5));
		code.push_back(res("k", "1"));
		code.push_back(decir("a[k]"));
		code.push_back(end_code());
		for (string w : code){
			cout << w;
		}
	}
}

int main(){
#ifndef jlocal
	ios::sync_with_stdio(0); cin.tie(0);
#endif
	pre_init();

	int t;
	t = 1;
	for (int i = 1; i <= t; i ++){
		solve(i);
	}
	return 0;
}