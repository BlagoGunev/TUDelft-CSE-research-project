#include<bits/stdc++.h>

using namespace std;

int main()

{ string str,str1,str2,str3;

     char c;

     str1="qwertyuiop";

      str2="asdfghjkl;";

       str3="zxcvbnm,./";

     cin>>c;

     cin>>str;

     if(c=='R')

     {

     for(int i=0;i<str.length();i++)

     {

     	for(int j=0;j<10;j++)

     	{  if(str[i]==str1[j])

             cout<<str1[j-1];

             if(str[i]==str2[j])

             cout<<str2[j-1];

             if(str[i]==str3[j])

             cout<<str3[j-1];

			      	}

	 }

}

    if(c=='L')

     {

     for(int i=0;i<str.length();i++)

     {

     	for(int j=0;j<10;j++)

     	{  if(str[i]==str1[j])

             cout<<str1[j+1];

             if(str[i]==str2[j])

             cout<<str2[j+1];

             if(str[i]==str3[j])

             cout<<str3[j+1];

			      	}

	 }

}

}