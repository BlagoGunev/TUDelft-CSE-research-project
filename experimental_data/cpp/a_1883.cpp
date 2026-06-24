#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[4];
    int a=0;
    for (int i = 0; i < n; i++)
    {   int j=0;
        int b;
        cin>>b;
        while(j<4){
        arr[3-j]=b%10;
        b=b/10;
        j++;
        }
        j=0;
        while(j<4){
        if (arr[j]==0)
        {
            arr[j]=10;
        }
        j++;
        }
        a=arr[0]+(abs(arr[0]-arr[1])+1)+(abs(arr[1]-arr[2])+1)+(abs(arr[2]-arr[3])+1);
        cout<<a<<endl;
    }
    
}