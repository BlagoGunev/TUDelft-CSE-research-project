#include <cstdio>
#include <cstdlib>
#include <set>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <list>
using namespace std;

const int inf = 2000000000 ;
const double eps = 1e-8 ;


int T,l,r,a,b;
char s[100005];
bool yes;

int ref() {
    if ((l>=4)&&(s[l-4]=='l')&&(s[l-3]=='i')&&(s[l-2]=='o')&&(s[l-1]=='s')) return 0;
    if ((l>=5)&&(s[l-5]=='l')&&(s[l-4]=='i')&&(s[l-3]=='a')&&(s[l-2]=='l')&&(s[l-1]=='a')) return 1;
    if ((l>=3)&&(s[l-3]=='e')&&(s[l-2]=='t')&&(s[l-1]=='r')) return 2;
    if ((l>=4)&&(s[l-4]=='e')&&(s[l-3]=='t')&&(s[l-2]=='r')&&(s[l-1]=='a')) return 3;
    if ((l>=6)&&(s[l-6]=='i')&&(s[l-5]=='n')&&(s[l-4]=='i')&&(s[l-3]=='t')&&(s[l-2]=='i')&&(s[l-1]=='s')) return 4;
    if ((l>=6)&&(s[l-6]=='i')&&(s[l-5]=='n')&&(s[l-4]=='i')&&(s[l-3]=='t')&&(s[l-2]=='e')&&(s[l-1]=='s')) return 5;
    return -1;
}

int main() {
    a=b=-1;
    yes=true;
    T=0;
    while (scanf("%s",s)!=EOF) {
        T++;
        l=strlen(s);
        r=ref();
        if (r==-1)  {
            yes=false;
        }
        else if (r==0) {
            if (a==1) yes=false;
            a=0;
            if (b>0) yes=false;
            b=0;
        }
        else if (r==1) {
            if (a==0) yes=false;
            a=1;
            if (b>0) yes=false;
            b=0;
        }
        else if (r==2) {
            if (a==1) yes=false;
            a=0;
            if (b>=1) yes=false;
            b=1;
        }
        else if (r==3) {
            if (a==0) yes=false;
            a=1;
            if (b>=1) yes=false;
            b=1;
        }
        else if (r==4) {
            if (a==1) yes=false;
            a=0;
            if (b<1) yes=false;
            b=2;
        }
        else if (r==5) {
            if (a==0) yes=false;
            a=1;
            if (b<1) yes=false;
            b=2;
        }
//printf("%d %d\n",r,yes);
    }
    if ((T==1)&&(r!=-1)) yes=true;
    if ((T!=1)&&(b<1)) yes=false;
    if (yes) printf("YES\n");
    else printf("NO\n");
    return 0;
}