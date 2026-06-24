#include<iostream>

#include<string>

#include<cstdio>

using namespace std;



int main()

{

//     freopen("in.txt","r",stdin);

      string s;

      int n;

      string s3="miao.",s4="lala.";

      cin>>n;

      getline(cin,s);

      for(int i=0;i<n;i++){

      getline(cin,s);

      int l=s.length();

      if(l<5){

            cout<<"OMG>.< I don't know!"<<endl;

            continue;

      }

      string s1,s2;

      s1.assign(s,(l-5),5);

      s2.assign(s,0,5);

      if(s2 == s3 && s4 == s1)

            cout<<"OMG>.< I don't know!"<<endl;

      else if(s2 == s3)

            cout<<"Rainbow's"<<endl;

      else if(s4 == s1)

            cout<<"Freda's"<<endl;

      else

            cout<<"OMG>.< I don't know!"<<endl;



//      cout<<s<<endl<<s1<<endl<<s2<<endl;

}

}