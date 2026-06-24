#include <iostream>

#include <vector>

#include <set>

#include <map>

#include <stack>

#include <queue>

#include <algorithm>

#include <cmath>



#define pb push_back

#define mp make_pair

#define sqr(x) ((x)*(x))

#define forn(i,n) for(int i  = 0;i<(int)n;i++)

#define dforn(i,n) for(int i = n-1;i>=0;i--)



using namespace std;



inline void readInt(int &num){

    num = 0;

    int c = getchar();

    int s = 1;

    if(c == '-'){

        s = -1;

        c = getchar();

    }

    while(c>='0'&&c<='9'){

        num = num*10+(c-'0');

        c = getchar();

    }

    num*=s;

}



inline void printInt(int num){

    string s="";

    if(num<0){

        putchar('-');

        num = -num;

    }

    if(num==0)

    	putchar('0');

    while(num){

        s+='0'+ num%10;

        num/=10;

    }

    dforn(i,s.size()){

        putchar(s[i]);

    }

}



inline void readLL(long long &num){

    num = 0;

    int c = getchar();

    int s = 1;

    if(c == '-'){

        s = -1;

        c = getchar();

    }

    while(c>='0'&&c<='9'){

        num = num*10+(c-'0');

        c = getchar();

    }

    num*=s;

}



inline void printLL(long long num){

    string s="";

    if(num<0){

        putchar('-');

        num = -num;

    }

    if(num==0)

    	putchar('0');

    while(num){

        s+='0'+ num%10;

        num/=10;

    }

    dforn(i,s.size()){

        putchar(s[i]);

    }

}



inline void readString(string &s){

    s = "";

    char c = getchar();

    while(c!=' '&&c!='\n'&&c!=EOF){

        s+=c;

        c = getchar();

    }

}



inline void readLine(string & s){

    s = "";

    char c = getchar();

    while(c!='\n'&&c!=EOF){

        s+=c;

        c = getchar();

    }

}



inline void printString(const string &s){

    forn(i,s.size())

        putchar(s[i]);

}



int main()

{

    #ifdef Home

    	freopen("in.txt","r",stdin);

    	freopen("out.txt","w",stdout);

    #endif

	

	int n, T; double c;

	scanf("%d %d %lf",&n, &T, &c);

	getchar();

	vector<int>v(n);

	forn(i,n){

		readInt(v[i]);

	}

	vector<long long>sums(n);

	sums[0] = v[0];

	for(int i = 0;i<n;i++){

		sums[i]=sums[i-1]+v[i];

	}

	int m;

	readInt(m);

	double prev = 0.0;

	int indx = 0;               

	forn(i,m){

		int t;

		readInt(t);

		double real,approx;

		

		approx = prev;

		for(int j = indx;j<t;j++){

			approx = (approx+(double)v[j]/T)/c;

		}

		prev = approx;

		indx = t;

		

		real = (double)(sums[t-1] - sums[t-T-1])/T;



		double error = abs(real - approx)/real;

		printf("%lf %lf %lf\n",real,approx,error);

	}



	return 0;

}