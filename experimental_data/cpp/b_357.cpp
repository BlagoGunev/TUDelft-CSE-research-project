#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>
#include <map>
#include <queue>
using namespace std;
 
#define For(i,end) for(int i=0;i<end;i++)
#define sFor(i,start,end) for(int i=start;i<end;i++)
#define nFor(i,start,end) for(int i=start;i>end;i--)

typedef long long int ll;
typedef pair<int,int> ii;
typedef vector<int> vi;

int main(){
  int m,n;
  scanf("%d%d",&n,&m);
  int *color = new int [n+1]; 
  For(i,n+1) color[i] = -1;
  for (int i = 0; i < m; i++)
  {
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    if(color[a]<0&&color[b]<0&&color[c]<0){
      color[a] = 1;
      color[b] = 2;
      color[c] = 3;
    }else {
      if(color[b]>0){
        int temp = a;
        a = b;
        b = temp;
      }
      else if(color[c]>0){
        int temp = a;
        a = c;
        c = temp;
      }
      int x = color[a];
      color[b] = x==1?2:(x==2?3:1);
      color[c] = x==1?3:(x==2?1:2);
    }
  }
  sFor(i,1,n+1) 
    printf("%d ",color[i]);
}

//    priority_queue
//    make_pair
//for (std::map<int,vi>::const_iterator it = m.begin(), end = m.end(); it != end; ++it){
    //(*it).second;
    //(*it).first;
//}