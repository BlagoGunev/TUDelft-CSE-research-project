#include <cstdio>
#include <cstring>
using namespace std;

char A[60][60];
int Ind[60][60],Low[60][60];
int N,M,i,j,k,XXX;
bool found;

int manj(int a,int b){
   if (a<b) return a; else return b;
}

void dfs(int x,int y,bool root){
   //printf("dfs %d %d\n",x,y);
   XXX++;
   Ind[x][y] = XXX;
   Low[x][y] = XXX;
   int chld=0;
   if (A[x-1][y]=='#'){
      if (Ind[x-1][y]==0){
         dfs(x-1,y,false);
         chld++;
         Low[x][y] = manj(Low[x][y],Low[x-1][y]);
         if (Low[x-1][y] >= Ind[x][y] && !root) found=true;
      } else {
         Low[x][y] = manj(Low[x][y],Ind[x-1][y]);
      }
   }

   if (A[x+1][y]=='#'){
      if (Ind[x+1][y]==0){
         dfs(x+1,y,false);
         chld++;
         Low[x][y] = manj(Low[x][y],Low[x+1][y]);
         if (Low[x+1][y] >= Ind[x][y] && !root) found=true;
      } else {
         Low[x][y] = manj(Low[x][y],Ind[x+1][y]);
      }
   }

   if (A[x][y-1]=='#'){
      if (Ind[x][y-1]==0){
         chld++;
         dfs(x,y-1,false);
         Low[x][y] = manj(Low[x][y],Low[x][y-1]);
         if (Low[x][y-1] >= Ind[x][y] && !root) found=true;
      } else {
         Low[x][y] = manj(Low[x][y],Ind[x][y-1]);
      }
   }

   if (A[x][y+1]=='#'){
      if (Ind[x][y+1]==0){
         chld++;
         dfs(x,y+1,false);
         Low[x][y] = manj(Low[x][y],Low[x][y+1]);
         if (Low[x][y+1] >= Ind[x][y] && !root) found=true;
      } else {
         Low[x][y] = manj(Low[x][y],Ind[x][y+1]);
      }
   }
   if (root && chld==2) found = true;
}

int main(){
   memset(A,'.',sizeof(A));
   scanf("%d%d",&N,&M);
   for (i=1; i<=N; i++){
      scanf("%s",A[i]+1);
   }
   found = false;
   int b=0;
   for (i=1; i<=N; i++){
      for (j=1; j<=M; j++){
         if (A[i][j]=='#') b++;
      }
   }
   if (b<=2){
      printf("-1\n");
      return 0;
   }


   for (i=1; i<=N; i++){
      for (j=1; j<=M; j++){
         if (A[i][j]=='#'){
            dfs(i,j,true);
            printf("%c\n",'2'-found);
            return 0;
         }
      }
   }
}