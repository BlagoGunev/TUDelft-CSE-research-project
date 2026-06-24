#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main() {
	int a,b;
	cin >> a >> b;
	int no = a/9;
	int lst = a%9;
	for(int i=0;i<no;i++) cout << 9;
    cout << lst;
	cout << endl;
	for(int i =0;i<no+1;i++) cout << 9;
	if(!lst) no--;
	for(int i=0;i<no;i++) cout << 0;
	cout << 10-lst;
	
}