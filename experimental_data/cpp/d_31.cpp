//Written by Zhu Zeqi

//Come on,baby

//Hack,please

#include<cmath>

#include<math.h>

#include<ctype.h>

#include<algorithm>

#include<bitset>

#include<cassert>

#include<cctype>

#include<cerrno>

#include<cfloat>

#include<ciso646>

#include<climits>

#include<clocale>

#include<complex>

#include<csetjmp>

#include<csignal>

#include<cstdarg>

#include<cstddef>

#include<cstdio>

#include<cstdlib>

#include<cstring>

#include<ctime>

#include<cwchar>

#include<cwctype>

#include<deque>

#include<exception>

#include<fstream>

#include<functional>

#include<iomanip>

#include<ios>

#include<iosfwd>

#include<iostream>

#include<istream>

#include<iterator>

#include<limits>

#include<list>

#include<locale>

#include<map>

#include<memory>

#include<new>

#include<numeric>

#include<ostream>

#include<queue>

#include<set>

#include<sstream>

#include<stack>

#include<stdexcept>

#include<streambuf>

#include<string>

#include<typeinfo>

#include<utility>

#include<valarray>

#include<vector>

#include<string.h>

#include<stdlib.h>

#include<stdio.h>

#define ll   long long

#define pb push_back

#define mp make_pair

#define F first

#define S second

#define MAX 100000000000000000

#define MOD 1000000007

#define PI 3.141592653589793238462

#define INF 1000000000

using namespace std;

bool u[105];

vector<int> ans;

struct cut{

	int x1,y1,x2,y2;

	bool ch(int x3,int y3,int x4,int y4){

		if(x1==x2)

		return x3<=x1 && x1<=x4 && y1==y3 && y2==y4;

		else

		return y3<=y1 && y1<=y4 && x1==x3 && x2==x4;

	}

	void input(){

		cin>>x1>>y1>>x2>>y2;

	}

}cut[105];

void dfs(int x1,int y1,int x2,int y2,int n){

	for(int i=0;i<n;i++){

		if(u[i])

		continue;

        if(cut[i].ch(x1,y1,x2,y2)){

            u[i]=1;

            if(cut[i].x1==cut[i].x2){

            	dfs(x1,y1,cut[i].x1,y2,n);

				dfs(cut[i].x1,y1,x2,y2,n);	

			}

            else{

            	dfs(x1,y1,x2,cut[i].y2,n);

				dfs(x1,cut[i].y1,x2,y2,n);

			}

            return;

        }

	}

	ans.push_back((x1-x2)*(y1-y2));

} 

int main(){

	//freopen("input.txt","r",stdin);

	//freopen("output.txt","w",stdout);

	int w,h,n;

	cin>>w>>h>>n;

	for(int i=0;i<n;i++)

	cut[i].input();

	dfs(0,0,w,h,n);

	sort(ans.begin(),ans.end());

	for(int i=0;i<ans.size();i++){

		if(i)

		cout<<" ";

		cout<<ans[i];

	}

	cout<<endl;

}