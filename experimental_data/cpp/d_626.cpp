#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;

const int MAX_N=5000+10;

int n,x;
vector <int> l;

double a[MAX_N],b[MAX_N];

double ans=0.0,ans1=0.0;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x;
		l.push_back(x);
	}
	sort(l.begin(),l.end());
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			ans1+=1.0;
			a[(int)(l[i]-l[j])]+=1.0;
		}
	}
	ans1=ans1*ans1*ans1;
	for(int i=1;i<=5000;i++){
		b[i]=b[i-1]+a[i];
	}
	for(int i=5000;i>0;i--){
		for(int j=i-1;j>0;j--){
			ans+=(a[i]*a[j]*b[i-j-1]);
		}
	}
	cout<<fixed<<setprecision(10);
	cout<<(double)(ans)/(double)(ans1);
}