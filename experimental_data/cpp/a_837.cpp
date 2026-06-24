#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	// cin>>n;
	scanf("%d",&n);
	// cin.clear();
	// fflush(stdin);
	char text[205];
	char ch[2];
	getchar();
	// scanf("%[^\n]s",ch);
	scanf("%[^\n]s",text);
	// cin.getline(text);
	// for(int i=0;i<n;i++)
	// {
	// 	// cin.get(text[i]);
	// 	cin>>noskipws>>text[i];
	// }
	int maxvolume=0,vol=0;
	// cout<<text<<endl;
	// for(int i=0;i<n;i++)
	// {
	// 	cout<<text[i];
	// }
	// cout<<endl;
	for(int i=0;i<n;i++)
	{
		if(text[i]>='A' && text[i]<='Z')
			vol++;
		else if(text[i]==' ')
		{
			// cout<<"i:: "<<i<<endl;
			if(vol>maxvolume)
				maxvolume=vol;
			vol=0;
		}
	}
	if(vol>maxvolume)
		maxvolume=vol;
	cout<<maxvolume<<endl;
	return 0;
}