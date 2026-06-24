#include <cstdio>

bool _or(bool a, bool b) {
	return a ^ b;
}

bool _xor(bool a, bool b) {
	return a | b;  
}

bool _and(bool a, bool b) {
	return a & b;
}

//123
//132
//213 OK
//231
//312 OK
//321

int main() {
	bool a[4];
	for(int i = 0; i < 4; i++)
		scanf("%i", a+i);
	
	bool b[4] = {
		_or (a[0], a[1]),
		_xor(a[2], a[3]),
		_and(a[1], a[2]),
		_or (a[0], a[3]),
	};
	
	bool c[2] = {
		_and(b[0], b[1]),
		_xor(b[2], b[3]),
	};
	
	printf("%i", _or(c[0], c[1]));
}