/*

     * round360.c++

     *

     *  Created on: Jun 29, 2016

     *      Author: Conan

     *

     * I reckon this is gonna be epic! :)

     */

     

    #include <bits/stdc++.h>

     

    #define ull unsigned long long

     

    #define int long long

     

    #define ld long double

     

    #define mod 1000000007

     

    #define INF 1000000007

     

    #define rep(i,x,y) for(int i = x; i<y; ++i)

     

    #define rev(i,x,y) for(int i = x ; i >= y; --i)

     

    #define pb push_back 

    

    #define pii pair<int, int> 

    

    #define f first

    

    #define s second

    

    using namespace std;

     

     

    /////////////////////////////////////////Fast (I/O)////////////////////////////////////

     

    inline int readInt(){

    	int sign = 1, x = 0, c = getc(stdin);

    	while (c <= 32){

    		c = getc(stdin);

    	}

    	if (c == '-'){

    		sign = -1;

    		c = getc(stdin);

    	}

    	while ('0' <= c && c <= '9' && c != EOF){

    		x = (x<<1) + (x<<3) + c - '0'; // x*10 == (x << 1) + (x << 3)

    		c = getc(stdin);

    	}

    	return x*sign;

    }

     

    inline void writeLong(long long x){

    	if (x < 0){

    		putc('-', stdout);

    		x = -x;

    	}

    	char s[40];

    	int n = 0;

    	while (x || !n){ // if x == 0 it won't be printed! (added !n) :)

    		s[n++] = '0' + x % 10;

    		x /= 10;

    	}

    	while (n--){

    		putc(s[n], stdout);

    	}

    }

     

   /* void prepareStream(){

        ios_base::sync_with_stdio(false);

    	cin.tie(nullptr);

    	cout.tie(nullptr);

    }

     */

    template <typename T>

    T input() {

        T res;

        cin >> res;

        return res;

    }

    

    ///////////////////////////////Auxiliary functions////////////////////////////

     

    inline bool des (int i , int j) { return i > j; }

    inline bool asc (int i , int j) { return i < j; }

    bool pairComp_s (const pii &x , const pii &y) { return asc(x.s, y.s); }

    

    int gcd(int x, int y) { return y ? gcd(y, x % y) : x ;}

    int lcm(int x, int y) { return x * 1ll * y / gcd(x, y); }

          

    

    ////////////////////////////////////Functions////////////////////////////////////

    

 

    

    ////////////////////////////////////Variables/////////////////////////////////

     

    //int spiral[][2] = {{1,0} , {1, 1} , {-1, 1} , {-1, -1} , {1, -1}};

     

    //int c[1000001];

    

    const int M = 1e5 + 1;

    int n, m , k, size, len, l, mid, r , ans , cur , res;

    //string str;

    int a[M];

    

    /////////////////////////////////Main Code//////////////////////////////////////

    int32_t main(){

     

        //prepareStream();



        

        n = readInt();

        

        rep(i, 0, n)

            a[i] = readInt();

            

        l = 0, r = 0, len = 0, res = 0;

        int Max = 0 , Min = 0;

        while(r < n && l < n)

        {

             

            while( r < n ){

                

                Max = (a[r] >= a[Max]) ? r : Max;

                Min = (a[r] <= a[Min]) ? r : Min;

                

                if(a[Max] - a[Min] <= 1)

                    ++r;

                else

                    break;

            }

            

            if(r >= l)  

            len = r - l;

            

            //cout<< l << " " << r << " " << r - l<< endl;

            

            res = max(res, len);

            

            //cout<<Max<< " "  << Min << endl;

            

            

            if(r < n && l < n){

                

                if(a[r] == a[Max])

                    l = Min + 1, Min = l;

                

                else if(a[r] == a[Min])

                    l = Max + 1, Max = l;

            }

            

        

        }

    

        writeLong(res);

        

    	return 0;

     

    }