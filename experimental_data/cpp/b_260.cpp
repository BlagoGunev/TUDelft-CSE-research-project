#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
int num[4][15][35];
int  day_num[13]= {0,31,28,31,30,31,30,31,31,30,31,30,31};
char date[100010];
char tmp[15];
int ansy;
int ansm;
int ansd;
int MAX;
bool is_number(char ch){
    if(ch>='0'&&ch<='9')return true;
    return false;
}
bool  judge(){
    for(int i= 0;i<9;i++){
       if(i ==2 || i ==5) continue ;
       if(!is_number(tmp[i]))return false ;
    }
    if(is_number(tmp[2])) return false ;
    if(is_number(tmp[5])) return false ;
    return true;
}
void solve(){
  if(!judge()){
   return;
  }
 // cout << "**&*&*"<<endl;
 // cout << tmp<<endl;
  int day = (tmp[0]-'0')*10+tmp[1]-'0';
  int month =  (tmp[3]-'0')*10+tmp[4]-'0';
  int year = (tmp[6] -'0')*1000+ (tmp[7]-'0')*100+ (tmp[8]-'0')*10 + tmp[9]-'0';
 // cout << year<<" "<<month<< " "<< day<<endl; 
  if(year<2013||year>2015) return ;
  if(month<1 || month>12) return ;
  if(day<1||day>day_num[month]) return ;
  num[year - 2012][month][day]++;
   int a= num[year-2012][month][day];
   if(MAX<a){
      ansy = year;
      ansm = month;
      ansd = day;
      MAX = a;
   }
}
void out(){
  if(ansd<10){
    printf("0%d-",ansd);
  }else{
    printf("%d-",ansd);
  }
  if(ansm<10){
    printf("0%d-",ansm);
  }else{
    printf("%d-",ansm);
  }
  printf("%d\n",ansy);
}
int main(){
 memset(date,0,sizeof(date));
 scanf("%s",date);
 int len =strlen(date);
 MAX =0 ;
 for(int i=0;i<=len-9;i++){
   for(int  j =0;j<=9;j++){
     tmp[j] = date[i+j];
   }
   solve();
 }
 out();
return 0 ;
}