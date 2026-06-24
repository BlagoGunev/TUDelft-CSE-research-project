#include <bits/stdc++.h>

using namespace std;

int n,k;

vector <int> v;

int main() {

	scanf("%d",&n);

	for (int i=0;i<n;i++) {

		bool ok=true;

		for (int j=0;j<n;j++) {

			scanf("%d",&k);

			if (k==1||k==3) ok=false;

		}

		if (ok) v.push_back(i+1);

	}

	printf("%d\n",v.size());

	for (int i=0;i<v.size();i++) printf("%d%c",v[i],i==v.size()-1?'\n':' ');

	return 0;

}