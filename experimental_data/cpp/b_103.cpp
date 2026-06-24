//g++ -o A A.cpp



//g++ -Wl,--stack,16777216 -o A A.cpp





//#include <bits/stdc++.h>

//using namespace std;



#include <iostream>

using std::cin;

using std::cout;

using std::string;

using std::endl;



#include <algorithm>

using std::sort;

using std::min;

using std::max;

using std::pair;//pair <int,int> data[100];sort(data,data+100);



#include <math.h>

//sqrt(123.123)

//ceil(0.12)=1

//pow(x,2)=x^2



#include<cstdio>

//printf()



#include <map>

using std::map;

//map <string,int> x;



#include <stdlib.h>

//abs(-123);



#include <vector>

using std::vector;

//vector<int> x;

//x.push_back(0);

//x.pop_back();

//vector<int> x(10,3);   ==>   x[0]==x[1]==...==x[9]==3;

//vector<int> y(x);      ==>   y[0]==y[1]==...==y[9]==3;

//cout<<x.size();        ==>   10





#include <queue>

using std::queue;



#include <deque>

using std::deque;







#include <stack>

using std::stack;

//.push(123)

//.pop()

//.top()

//.size()

//.size()



#include <set>

using std::set;

using std::multiset;





long long gcd(long long a, long long b)

{

    //O(log(max(a,b)))

    long long t;

    while(b!=0)

    {

        t=a%b;

        a=b;

        b=t;

    }

    return a;

}





/*

long long C(int x,int y)

{

    if(x<y){

        return 0;

    }

    long long answer=1;

    int i;

    if(y>x-y)

    {

        y=x-y;

    }

    for(i=1;i<=y;i++)

    {

        answer*=(x+1-i);

        answer/=i;

    }

    return answer;

}

*/









/*

//C(x,y) % mod

long long C(long long x,long long y)

{

    long long mod=1000000007;

    if(x<y){

        return 0;

    }

    long long answer=1;

    int i;

    if(y>x-y)

    {

        y=x-y;

    }

    for(i=1;i<=y;i++)

    {

        answer*=(x+1-i);

        answer%=mod;

    }

    for(i=1;i<=y;i++)

    {

        while(answer%i!=0){

            answer+=mod;

        }

        answer/=i;

        answer%=mod;

    }

    return answer%mod;

}





for (i=0; i<1010; i++) {

    c[i][0]=1;

    for (j=1; j<=i; j++) c[i][j]=(c[i-1][j-1]+c[i-1][j])%md;

}

*/



/*

struct classcomp {

  bool operator() (const int& lhs, const int& rhs) const

  {return lhs>rhs;}

};

*/



int visited[101]={0,};

int n,m;

vector<vector<int>> data(101);

int cnt=0;



void dfs(int x){

    visited[x]=1;

    cnt++;

    for(int i=0;i<data[x].size();i++){

        int to=data[x][i];

        if(!visited[to]){

            dfs(to);

        }

    }

}



int main()

{

    cin>>n>>m;



    for(int i=0;i<m;i++){

        int a,b;

        cin>>a>>b;

        data[a].push_back(b);

        data[b].push_back(a);

    }

    



    dfs(1);



    if(n==m && cnt==n){

        cout<<"FHTAGN!";

    }else{

        cout<<"NO";

    }

    return 0;

}