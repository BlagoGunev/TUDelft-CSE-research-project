#include <bits/stdc++.h>
/**********************************************************************************************/		

#include <bits/stdc++.h>

using namespace std;

#define          pb(x) push_back(x)

#define          pf(x) push_front(x)

#define          in(x) insert(x)

#define          max(val1,val2)val1>val2 ?val1:val2

#define          min(val1,val2)val1<val2 ?val1:val2

#define          clr(x) getline(cin,x) 

#define   conv(x) (x>=65 && x<=90)?x+32:x

#define   P(x,y) next_permutation(x,y)   

#define   fil(v,x) fill(v.begin(),v.end(),x)

#define   cs(x) x.c_str()

#define   na(x,y) new (nothrow) x[y] 

typedef   vector<char> CV;

typedef   vector<string> SV;

typedef           vector<long long int> VLL;  

typedef         vector<char>::iterator cvitr;

typedef       vector<string>::iterator svitr;

typedef     vector<long long int>::iterator llvitr;

typedef    set<char> CS;

typedef    set<long long int> LLS;

typedef     set<char>::iterator csitr;

typedef      set<long long int>::iterator llsitr;

typedef        pair<set<long long int>::iterator,bool> llbpair;

typedef          map<long long int,long long int> LLM;

typedef            map<char,long long int> CLLM;

typedef              map<long long int,char> LLCM;

typedef                map<long long int,long long int>::iterator llmitr;

typedef                  map<char,long long int>::iterator cllmitr;

typedef                  map<long long int,char>::iterator llcmitr;

typedef                 map<long long int,long long int>::reverse_iterator llmritr;

typedef               bitset<64> B; 

typedef            unsigned long long int ULL;

typedef           long long int LL;

typedef        long int LI;

bool          greatfunc(LL a,LL b){return (a>b);}

/**********************************************************************************************/



int main(){

  char str1[200],str2[200];

   scanf("%s",str1);

   scanf("%s",str2);

   int store=strcasecmp(str1,str2);

     if(store<0)

        printf("-1");

     else if(store!=0)printf("1");

     else printf("0");

 return 0;

 }