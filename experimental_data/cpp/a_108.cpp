#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <bitset>
#include <utility>
using namespace std;
int main()
{
    char h1,h2,m1,m2;
    //while(1){
    scanf("%c%c:%c%c",&h1,&h2,&m1,&m2);
    getchar();
    if( (m1-'0')*10+(m2-'0') < ((h2-'0')*10+(h1-'0')) ){
      if(h2 > '5'){
        h1 = h1+1;
        h2 = '0';
      }
      m1 = h2;
      m2 = h1;
    }
    else{
      if(h2 < '5'){
        if(h1 == '2' && h2 == '3'){
          h1 = '0';
          h2 = '0';
        }
        else h2 = h2+1;
        m1 = h2;
        m2 = h1;
      }
      else{
        h1 = h1+1;
        h2 = '0';
        m1 = h2;
        m2 = h1;
      }
    }
    printf("%c%c:%c%c",h1,h2,m1,m2);
    
//}
    return 0;
}