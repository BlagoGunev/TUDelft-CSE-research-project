#include <bits/stdc++.h>



using namespace std;



int main(){

	int k, i, mi, o;

	vector<int> v;

	for(i = 0 ; i < 3 ; i++){

		cin>>k;

		v.push_back(k);

	}

	mi = *min_element(v.begin(), v.end());

	if(mi != 1){

		cout<<v[0] * v[1] * v[2];

	}

	else{

		if(count(v.begin(), v.end(), 1) == 2){

			if((v[0] * v[1]) == 1){

				cout<<(v[0] + v[1]) * v[2];

			}

			else if ((v[0] * v[2]) == 1){

				cout<<v[1] + v[2] + v[0];

			}

			else{

				cout<<(v[1] + v[2]) * v[0];

			}

		}

		else if(count(v.begin(), v.end(), 1) == 1){

			o = distance(v.begin(), min_element(v.begin(), v.end()));

			if( o == 0  ){

				cout<<(v[0] + v[1]) * v[2];

			}

			else if(o == 1){

				cout<<max((v[0] + v[1]) * v[2], (v[1] + v[2]) * v[0]);

			}

			else{

				cout<<(v[1] + v[2]) * v[0];

			}

		}

		else{

			cout<<3;

		}

	}

}