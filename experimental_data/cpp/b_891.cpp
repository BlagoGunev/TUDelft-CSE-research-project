#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <vector>
#include <stdio.h>
#include <string.h>
using namespace std;

typedef pair<int,int> pii;

const int MAX_N = 22+5;

int n;
int a[MAX_N];
int b[MAX_N];
set <int> s;
vector <pii> l;

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		s.insert(a[i]);
		l.push_back(pii(a[i],i));
	}
	sort(l.begin(),l.end());
	if(n == 1){
		cout<<a[0]<<endl;
		return 0;
	}
	if(s.size()!=n){
		cout<<-1<<endl;
		return 0;
	}
	for(int i=0;i<n-1;i++){
		b[l[i+1].second]=l[i].first;
	}
	b[l[0].second]=l[n-1].first;
	for(int i=0;i<n;i++){
		cout<<b[i]<<" ";
	}
	
}