#include<bits/stdc++.h>

using namespace std;

int main(void)

{

   int i;

   int A[1000008];

   char str[1000008];

   scanf("%s",str);

   int n=strlen(str);

   int last=n-1;

   int start=0;

   for(i=0;i<n;i++)

   {

      if(str[i]=='l')

      {

        A[last--]=i+1;

      }

      else

        A[start++]=i+1;

   }

   for(i=0;i<n;i++)printf("%d ",A[i]);

   char ch=getchar();

   ch=getchar();

   return 0;

}