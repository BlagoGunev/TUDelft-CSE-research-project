#include <iostream>

#include<algorithm>

#include<cmath>

#include<vector>

#include<unordered_map>

#include<map>

#include<set>

#include<vector>

#include <bits/stdc++.h>

#include<stack>

#include<cstring>

#define x first

#define y second



#define  ios ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);



using namespace std;

typedef  long  long LL ;

typedef  unsigned long  long ULL ;

typedef pair<int,int> PII ;

typedef pair<LL,int> PLI ;

const int N = 2e5 + 10 ,M = 1000 * 100000 + 10 ,mod = 1000000007,INF1 = 0x3f3f3f3f;

const LL INF2 = 1e17;





void solve() {

    int n;cin>>n;

    vector<LL> x(n),y(n);

    vector<PLI> dif(n);



    for(auto &i : x) cin>>i;

    for(auto &i : y) cin>>i;





    for (int i =0  ;i < n ;i  ++ )

    {

        dif[i].x = y[i] -x[i];

        dif[i].y = i;

    }



    sort(dif.begin(),dif.end());

    reverse(dif.begin(),dif.end());



    int j = n -1 ,cnt =0 ;

    for (int i = 0; i < n; ++i) {

        while(i < j && dif[i].x + dif[j].x < 0 ) j --;

        if(i >= j ) break;

        cnt ++ ,j -- ;

    }



    cout<<cnt<<endl;



}

int main()

{

	ios

    int T;cin>>T;



    while(T -- )

    {

        solve();



    }





	

	return 0;

}