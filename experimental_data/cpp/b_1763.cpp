#include <bits/stdc++.h>

using namespace std;

#define ll long long int



int main(){



	ios_base::sync_with_stdio(false);

	cin.tie(NULL);

	

	int t;

	cin>>t;

	while(t--){

		int n,k;cin>>n>>k;

		int h[n],p[n];

		for(int i=0;i<n;i++){

			cin>>h[i];

		}

		for(int i=0;i<n;i++){

			cin>>p[i];

		}

		vector< pair<int,int> > v;

		for(int i=0;i<n;i++){

			v.push_back(make_pair(p[i],h[i]));

		}

		sort(v.begin(), v.end());

		//for(auto it: v){

			//cout<<it.first<<" "<<it.second<<endl;

		//}

		int c=k;

		for(int i=0;i<n;i++){

			//v[i].second-=c;

			if(i!=n-1){

				if(v[i].second-c>0){

					k-=v[i].first;

					c+=k;

					i--;

				}

				if(k<=0){

					cout<<"NO"<<'\n';break;

				}

			}

			else{

				if(v[i].second<=c){

					cout<<"YES"<<'\n';

					break;

				}

				else{

					v[i].second-=c;

					k-=v[i].first;

					while(1){

						v[i].second-=k;

						k-=v[i].first;

						if(v[i].second<=0){

							cout<<"YES"<<'\n';

							break;

						}

						else if(k<=0){

							cout<<"NO"<<'\n';

							break;

						}

					}

				}

			}

		}

	}

}