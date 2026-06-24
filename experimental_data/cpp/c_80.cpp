/* -------------------------------- */

/* Name: MD. Khairul Basar          */

/* Institute: HSTU                  */

/* Dept: CSE                        */

/* Email: khairul.basar93@gmail.com */

/* -------------------------------- */



#include <bits/stdc++.h>

/* all header files */



#define fs            first

#define sc            second

#define sp            printf(" ")

#define nl            printf("\n")

#define pb(a)         push_back(a)



#define setzero(a)    memset(a,0,sizeof(a))

#define setneg(a)     memset(a,-1,sizeof(a))

#define setinf(a)     memset(a,126,sizeof(a))



#define tc1(x)        printf("Case %d: ",x)

#define tc2(x)        printf("Case #%d: ",x)

#define tc3(x)        printf("Case %d:\n",x)

#define tc4(x)        printf("Case #%d:\n",x)



#define iin(x)        scanf("%d",&x)

#define din(x)        scanf("%lf",&x)

#define lin(x)        scanf("%lld",&x)

#define clin(x)       scanf("%I64d",&x)



#define pr1(x)        cout<<x<<"\n"

#define pr2(x,y)      cout<<x<<" "<<y<<"\n"

#define pr3(x,y,z)    cout<<x<<" "<<y<<" "<<z<<"\n"

#define pr4(w,x,y,z)  cout<<w<<" "<<x<<" "<<y<<" "<<z<<"\n"

#define fast          ios::sync_with_stdio(0)

#define read          freopen("input.txt","r",stdin)

#define write         freopen("output.txt","w",stdout)

#define prflag1(flag) printf("%s\n",(flag)?"YES":"NO")

#define prflag2(flag) printf("%s\n",(flag)?"Yes":"No")

#define prflag3(flag) printf("%s\n",(flag)?"yes":"no")

/* macro definitions */



using namespace std;



typedef long long LL;

typedef unsigned long long ULL;

typedef pair<int, int>pii;

typedef pair<LL, LL>pll;

typedef vector<int>vi;

typedef vector<LL>vll;

typedef vector<pii>vpii;

typedef vector<pll>vpll;

/* type definitions */



LL MOD_EXPO(LL b, LL p, LL m)

{

    if(p==0) return 1;

    LL ret=MOD_EXPO(b,p/2,m)%m;

    ret=(ret*ret)%m;

    return ((p&1) ? (ret*b)%m : ret%m);

}

LL POWER(LL N, LL K)

{

    LL i,ans=1;

    for(i=1; i<=K; i++) ans*=N;

    return ans;

}

int SET(int N, int pos)

{

    return (N | (1<<pos));

}

int RESET(int N, int pos)

{

    return (N & !(1<<pos));

}

bool CHECK(int N, int pos)

{

    return (N & (1<<pos));

}

/* necessary functions */



int dx4[]= {1,-1,0,0};

int dy4[]= {0,0,1,-1};

int dx6[]= {0,0,1,-1,0,0};

int dy6[]= {1,-1,0,0,0,0};

int dz6[]= {0,0,0,0,1,-1};

int dx8[]= {1,-1,0,0,-1,1,-1,1};

int dy8[]= {0,0,1,-1,1,1,-1,-1};

int dkx8[]= {-1,1,-1,1,-2,-2,2,2};

int dky8[]= {2,2,-2,-2,1,-1,1,-1};

/* direction arrays */



int tc=1;

const double eps=1e-9;

const double pi=acos(-1.0);

const long long int mx=1e5;

const long long int mod=1e9+7;

/* global declarations */



int f( string s )

{

    if( s == "Anka" ) return 0;

    if( s == "Chapay" ) return 1;

    if( s == "Cleo" ) return 2;

    if( s == "Troll" ) return 3;

    if( s == "Dracul" ) return 4;

    if( s == "Snowy" ) return 5;

    if( s == "Hexadecimal" ) return 6;

}



int main()

{

    int n, mas[ 8 ][ 8 ] = {0};

    string s;

    cin >> n;

    for( int i = 0 ; i < n ; i++ )

    {

        cin >> s;

        int x1 = f( s );

        cin >> s >> s;

        int x2 = f( s );

        mas[ x1 ][ x2 ] = 1;

    }

    int a, b, c, mn = -1, symph;

    cin >> a >> b >> c;

    for( int i = 1 ; i < 6 ; i++ )

        for( int j = 1 ; j < 6 ; j++ )

            if( i + j < 7 )

            {

                int ma[ 8 ];

                for( int k = 0 ; k < 7 ; k++ )

                    ma[ k ] = k;

                do

                {

                    int op1 = a / i, op2 = b / j, op3 = c / ( 7 - i - j );

                    int mmx = max( op1, max( op2, op3 ) ), mmn = min( op1, min( op2, op3 ) );



                    if( mn == -1 || ( mmx - mmn < mn ) )

                    {

                        mn = mmx - mmn;

                        symph = 0;

                        for( int x = 0 ; x < i ; x++ )

                            for( int y = 0 ; y < i ; y++ )

                                symph += mas[ ma[x] ][ ma[y] ];

                        for( int x = i ; x < i + j ; x++ )

                            for( int y = i ; y < i + j ; y++ )

                                symph += mas[ ma[x] ][ ma[y] ];

                        for( int x = i + j ; x < 7 ; x++ )

                            for( int y = i + j ; y < 7 ; y++ )

                                symph += mas[ ma[x] ][ ma[y] ];

                    }

                    else if( mmx - mmn == mn )

                    {

                        int symph1 = 0;

                        for( int x = 0 ; x < i ; x++ )

                            for( int y = 0 ; y < i ; y++ )

                                symph1 += mas[ ma[x] ][ ma[y] ];

                        for( int x = i ; x < i + j ; x++ )

                            for( int y = i ; y < i + j ; y++ )

                                symph1 += mas[ ma[x] ][ ma[y] ];

                        for( int x = i + j ; x < 7 ; x++ )

                            for( int y = i + j ; y < 7 ; y++ )

                                symph1 += mas[ ma[x] ][ ma[y] ];

                        symph = max( symph, symph1 );

                    }



                }

                while( next_permutation( ma, ma + 7 ) );

            }

    cout << mn << " " << symph << endl;

    return 0;

}