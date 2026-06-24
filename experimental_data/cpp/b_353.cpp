#include<bits/stdc++.h>

using namespace std;

struct node{

  int b,id;

}num[205];

int ans[205],v[205];

bool cmp(node a,node b){

  return a.b>b.b;

}

int main(){

  int n,last,o,t;

  scanf("%d",&n);

  memset(num,0,sizeof(num));

  for(int i=1;i<=2*n;i++){

    scanf("%d",&num[i].b);

    num[i].id=i;

  }

  sort(num+1,num+2*n+1,cmp);

  last=2,t=o=0;

  memset(v,0,sizeof(v));

  for(int i=1;i<=2*n;i++){

    if(num[i].b==num[i+1].b){

      if(!v[num[i].b]){

        if(last==2){

          ans[num[i].id]=1;

          ans[num[i+1].id]=2;

          o++,t++;

          last=2;

        }

        else{

          ans[num[i].id]=2;

          ans[num[i+1].id]=1;

          o++,t++;

          last=1;

        }

        v[num[i].b]=v[num[i+1].b]=1;

      }

      else{

        if(last==2){

          ans[num[i+1].id]=1,last=1;

        }

        else ans[num[i+1].id]=2,last=2;

      }

    }

  }

  for(int i=1;i<=2*n;i++){

    if(!v[num[i].b]){

      if(last==2){

        ans[num[i].id]=1;

        o++;

        last=1;

      }

      else{

        ans[num[i].id]=2;

        t++;

        last=2;

      }

    }

  }

  printf("%d\n",t*o);

  printf("%d",ans[1]);

  for(int i=2;i<=2*n;i++){

    printf(" %d",ans[i]);

  }

  printf("\n");

}