#include<iostream>

#include<vector>

using namespace std;

int main(){

	

	vector <string> a,b;

 	string s;

	int n;

	cin>>n;

	

	for(int i=0;i<n;i++){

		cin>>s;

		a.push_back(s);

		cin>>s;

		b.push_back(s);

	}

	

	for(int i=0;i<a.size()-1;i++){

		for(int j=i+1;j<a.size();j++){

			if(a[i]==a[j] && b[i]==b[j]){

				a.erase(a.begin()+j);

				b.erase(b.begin()+j);

				j--;

			}

		}

	}

	

	cout<<a.size();

	

	

}