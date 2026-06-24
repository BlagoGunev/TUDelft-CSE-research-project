#include <iostream>
#include <cstdio>
#include <string>
#include <deque>
using namespace std;
#define pb(a) push_back(a)
deque<string> dir;
void out(){
  cout<<'/';
  for(int i=0;i<dir.size();++i)cout<<dir[i]<<'/';
  cout<<'\n';
}
deque<string> parse(string w){
  deque<string> ret;
  if(w[w.size()-1] != '/')w+='/';
  string add;
  for(int i=0;i<w.size();++i){
   if(w[i]=='/'){
    ret.pb(add);
    add.clear();
    continue;
                }
   else add += w[i];
                             }
  return ret;
}
void doit(deque<string> from){
  if(from[0].empty())dir.clear() , from.pop_front();
  while(!from.empty()){
   string com=from[0]; from.pop_front();
   if(com[0]=='.')dir.pop_back();
   else dir.pb(com);
                      }
}
string op1,op2;
int main(){
  int Q; cin>>Q;
  while(Q--){
   cin>>op1;
   if(op1[0]=='p')out();
   else{
    cin>>op2;
    doit( parse(op2) );
       }
            }
  //system("pause");
  return 0;
}