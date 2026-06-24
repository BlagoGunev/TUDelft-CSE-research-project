/* Author haleyk10198 */

/* �@��:  haleyk10198 */ 

#include <iostream>

#include <fstream>

#include <sstream>

#include <cstdlib>

#include <cstdio>

#include <vector>

#include <map>

#include <queue>

#include <cmath>

#include <algorithm>

#include <cstring>

#include <iomanip>

#include <ctime>

#include <string>

#include <set>



#define MOD 1000000007

#define INF 2147483647

#define PI 3.14159265359

#define ll long long

#define pii pair<int,int>

#define mp(x,y) make_pair((x),(y))



using namespace std;



class SegTree{

	private:

		int n;

		vector<int> arr;

	public:

		SegTree(int i){

			n=i;

			arr.assign(2*n,0);

		}

		void update(int l,int r,int val){

			for(l+=n,r+=n;l<r;l>>=1,r>>=1){

				if(l&1)

					arr[l++]|=val;

				if(r&1)

					arr[--r]|=val;

			}

		}

		void push(void){

			for(int i=1;i<n;i++){

				arr[i<<1]|=arr[i];

				arr[i<<1|1]|=arr[i];

			}

		}

		int query(int l,int r){

			unsigned int res=1<<31;

			res--;

			for(l+=n,r+=n;l<r;l>>=1,r>>=1){

				if(l&1)

					res&=arr[l++];

				if(r&1)

					res&=arr[--r];

			}

			return res;

		}

		void show(void){

			for(int i=n;i<2*n;i++){

				printf("%d%c",arr[i],i==2*n-1?'\n':' ');

			}

		}

};



int main(){

	int n,m;

	scanf("%d%d",&n,&m);

	SegTree seg(n);

	int l[m],r[m],q[m];

	bool check=true;

	for(int i=0;i<m;i++){

		scanf("%d%d%d",&l[i],&r[i],&q[i]);

		seg.update(--l[i],r[i],q[i]);

	}

	seg.push();

	for(int i=0;i<m;i++){

		if(seg.query(l[i],r[i])!=q[i])

			check=false;

	}

	if(check){

		cout<<"YES"<<endl;

		seg.show();

	}

	else

		cout<<"NO"<<endl;

	return 0;

}