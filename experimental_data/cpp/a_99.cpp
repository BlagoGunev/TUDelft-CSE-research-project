#include <bits/stdc++.h>



#define MOD 1000000007

#define lp(i,n) for(int i = 0 ; i < n ;i++)

#define clr(v,d) memset(v,d,sizeof(v))

#define all(v) v.begin(),v.end()

#define sz(v) (int)v.size()

#define vit vector<int>::iterator

#define mp make_pair

#define pb push_back

#define SCANLL(num) scanf("%I64d",&num)

#define SCANI(num) scanf("%d",&num)



using namespace std;



typedef long long ll;

typedef pair<int,int> ii;

typedef vector<int> vi;

typedef vector<ii> vii;



string str , out;

int dot_id;



int main(){

    cin >> str;

    int len = str.length();

    lp(i,len){

        if(str[i]=='.'){

            dot_id = i ;

            break;

        }

    }

    if(str[dot_id-1]=='9'){

        puts("GOTO Vasilisa.");

        return 0;

    }

    else if(str[dot_id+1]<'5')

        out = str.substr(0,dot_id);

    else

        out = str.substr(0,dot_id-1) + (++str[dot_id-1]);

    cout << out <<"\n";

    return 0;

}