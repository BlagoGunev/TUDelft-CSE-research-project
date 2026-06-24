#include<stdio.h>

int main()
{
    int j=0;
   char ch;
   while ((ch = getchar ()) != '\n')
{
if(ch=='a')j++;
if(ch=='e')j++;
if(ch=='i')j++;
if(ch=='o')j++;
if(ch=='u')j++;
if(ch=='1')j++;
if(ch=='3')j++;
if(ch=='5')j++;
if(ch=='7')j++;
if(ch=='9')j++;
}

printf("%d",j);
}