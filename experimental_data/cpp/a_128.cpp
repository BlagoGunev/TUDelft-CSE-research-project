#include <iostream>

#include <fstream>

#include <string>

#include <cstring>

#include <stdio.h>

#include <iomanip>

#include <cmath>

#include <vector>

#include<cctype>

#include<algorithm>

#include<set>

#include<stack>

#include<map>

#include<stdlib.h>

#include<ctime>

#include<iterator>

#include <deque>

#include <sstream>

#include<queue>

#include<cstdlib>

#include<climits>

#include<complex>





#define fn(i,n) for(int (i) = 0;(i) < (n);(i)++)

#define mk(f,s) make_pair((f),(s))



using namespace std;



typedef long long ll;

typedef pair<int ,int > pp;



typedef vector<int  > v1;

typedef vector<ll  > vl;

typedef vector<pp  > vpp;

typedef vector<bool  > vb;

typedef vector<char  > vc;

typedef vector<vector<int > > v2;

typedef map<int ,int > mf;

typedef map<int ,vpp > mv;

typedef map<int ,v1 > ad;

int const siz = 1e9,bound = 1e5; 

vector<string > grid(8);

vpp st;

int dx[9] = {1,1,0,-1,-1,-1,0,1,0};

int dy[9] = {0,-1,-1,-1,0,1,1,1,0};





bool bk(int r,int c,vpp st){

	if( r == 8 || c == 8 || r < 0 || c < 0) return false;

	if(r == 0 && c == 7) return true;

	//cout<<1<<endl;

	fn(i,st.size()){

		if(st[i].first != 8){

			if(r == st[i].first && c == st[i].second || 

				st[i].first + 1 == r && st[i].second == c)

				return false;

			st[i].first++;

		}

	}



	fn(i,9){

		if(bk(r+dy[i],c+dx[i],st))

			return true;

	}



	return false;

}



int main(){	

	//freopen("C:\\Users\\L.C\\Desktop\\uniAbood\\out.txt","w",stdout);

	fn(i,8)

		cin>>grid[i];

	fn(i,8){

		fn(j,8){

			if(grid[i][j] == 'S')

				st.push_back(mk(i,j));

		}

	}

	if(bk(6,0,st) || bk(6,0,st) || bk(6,1,st) || bk(7,1,st) || bk(7,0,st))

		puts("WIN");

	else puts("LOSE");

	return 0;

}