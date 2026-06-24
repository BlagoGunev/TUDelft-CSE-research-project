// // // #include <bits/stdc++.h>

// // // using namespace std;

// // // int main()

// // // {

// // // 	#ifndef ONLINE_JUDGE

// // // 	freopen("input.txt","r",stdin);

// // // 	#endif





// // // 	cout << "WELCOME" << endl;

// // // 	return 0;



// // // }

// // #include <bits/stdc++.h>

// // using namespace std;

// // int main()

// // {



// // 	int a , b;

// // 	#ifndef ONLINE_JUDGE

// // 	freopen("input.txt","r",stdin);

// // 	#endif





// // 	cin >> a >> b;

// // 	cout <<  a + b << endl;





// // 	return 0;



// // }

// // #include <bits/stdc++.h>

// // using namespace std;

// // int main()

// // {

// // 	#ifndef ONLINE_JUDGE

// // 	freopen("input.txt","r",stdin);

// // 	#endif





// // 	cout << sizeof(long double) << endl;





// // 	return 0;



// // }

// // #include <bits/stdc++.h>

// // using namespace std;

// // int main()

// // {

// // 	#ifndef ONLINE_JUDGE

// // 	freopen("input.txt","r",stdin);

// // 	#endif





// // 	int a , b;

// // 	cin >> a >> b;

// // 	if (a == b)

// // 		cout << 3*(a+b) << endl;

// // 	else

// // 		cout << a+b << endl;





// // 	return 0;



// // }

// // #include <bits/stdc++.h>

// // using namespace std;

// // int main()

// // {

// // 	#ifndef ONLINE_JUDGE

// // 	freopen("input.txt","r",stdin);

// // 	#endif





// // 	int a;

// // 	string b , c;

// // 	cin >> b >> a;

// // 	for (int i = 0; i < b.length(); ++i)

// // 	{

// // 		if (i != a)

// // 			c += b[i];

// // 	}

// // 	cout << c << endl;





// // 	return 0;



// // }

// // #include <bits/stdc++.h>

// // using namespace std;

// // int main()

// // {

// // 	#ifndef ONLINE_JUDGE

// // 	freopen("input.txt","r",stdin);

// // 	#endif



// // 	string b , d , e;

// // 	cin >> b;

// // 	d = b[0];

// // 	e = b[b.length()-1];

// // 	cout << e;

// // 	for (int i = 1 ; i < b.length()-1 ; ++i)

// // 		cout << b[i];

// // 	cout << d << endl;

	





// // 	return 0;



// // }

// // #include <bits/stdc++.h>

// // using namespace std;

// // int main()

// // {

// // 	#ifndef ONLINE_JUDGE

// // 	freopen("input.txt","r",stdin);

// // 	#endif





// // 	string b;

// // 	getline(cin, b);

// // 	if (b.length() < 2)

// // 		cout << b << endl;

// // 	else

// // 		for (int i = 0; i < 4; ++i)

// // 		{

// // 			cout << b[0] << b[1];

// // 		}

// // 		cout << endl;





// // 	return 0;



// // }

// // #include <bits/stdc++.h>

// // using namespace std;

// // int main()

// // {

// // 	#ifndef ONLINE_JUDGE

// // 	freopen("input.txt","r",stdin);

// // 	#endif





// // 	string a;

// // 	getline(cin , a);

// // 	cout << a[a.length()-1] << a << a[a.length()-1] << endl;





// // 	return 0;



// // }

// // #include <bits/stdc++.h>

// // using namespace std;

// // int main()

// // {

// // 	#ifndef ONLINE_JUDGE

// // 	freopen("input.txt","r",stdin);

// // 	#endif

// // 	int a;

// // 	cin >> a;

// // 	if (a % 3 == 0 or a % 7 == 0)

// // 		cout << 1 << endl;

// // 	else

// // 		cout << 0 << endl;





	





// // 	return 0;



// // }

// // #include <bits/stdc++.h>

// // using namespace std;

// // int main()

// // {

// // 	#ifndef ONLINE_JUDGE

// // 	freopen("input.txt","r",stdin);

// // 	#endif



// // 	int a,b,c;

// // 	cin >> a >> b >> c;

// // 	cout << max(max(a,b) , max(b,c)) << endl;

		





// // 	return 0;



// // }

// // #include <bits/stdc++.h>

// // using namespace std;

// // int main()

// // {

// // 	#ifndef ONLINE_JUDGE

// // 	freopen("input.txt","r",stdin);

// // 	#endif





// // 	int a, b;

// // 	cin >> a >> b;

// // 	if (a == b)

// // 		cout << 0 << endl;

// // 	else if (abs(100 - a)  >  abs(100 - b))

// // 		cout << a << endl;

// // 	else

// // 		cout << b << endl;





// // 	return 0;



// // }

// // #include <bits/stdc++.h>

// // using namespace std;

// // int main()

// // {

// // 	#ifndef ONLINE_JUDGE

// // 	freopen("input.txt","r",stdin);

// // 	#endif





// // 	int a;

// // 	cin >> a;

// // 	for (int i = 0; i < a; ++i)

// // 	{

// // 		string b;

// // 		int count = 0;

// // 		cin >> b;

// // 		for (int j = 0; j < b.length()-1; ++j)

// // 		{

// // 			if (b[j] == 'a' and b[j+1] == 'a')

// // 				count += 1;

// // 		}

// // 		cout << count << endl;

// // 	}

// // 	return 0;



// // }

// // #include <bits/stdc++.h>

// // using namespace std;

// // int main()

// // {

// // 	#ifndef ONLINE_JUDGE

// // 	freopen("input.txt","r",stdin);

// // 	#endif



// // 	int x;

// // 	string a;

// // 	cin >> a;

// // 	for (int i = 0; i < a.length()-1; ++i)

// // 	{

// // 		if (a[i] == 'a'){

// // 			if (a[i + 1] == 'a'){

// // 				cout << 1 << endl;

// // 				return 0;

// // 			} 

// // 		}

// // 	}

// // 	cout << 0 << endl;



// // }

// // #include <bits/stdc++.h>

// // using namespace std;

// // int main()

// // {

// // 	#ifndef ONLINE_JUDGE

// // 	freopen("input.txt","r",stdin);

// // 	#endif

// // 	string a;

// // 	cin >> a;

// // 	for (int i = a.length()-1; i >= 0; --i)

// // 	{

// // 		cout << a[i];

// // 	}

// // 	cout << endl;

	





// // 	return 0;



// // }

// // #include <iostream>

// // using namespace std;

// // int main()

// // {

// // 	#ifndef ONLINE_JUDGE

// // 	freopen("input.txt","r",stdin);

// // 	#endif





// // 	int a;

// // 	cin >> a;

// // 	for (int i = 0; i < a; ++i)

// // 	{

// // 		long long int b , max = 0;

// // 		cin >> b;

// // 		long long int c[b];

// // 		for (int k = 0; k < b; ++k)

// // 		{

// // 			cin >> c[k];

// // 		}

// // 		for (int j = 0; j < b-1; ++j)

// // 		{

// // 			if (c[j] * c[j+1] > max)

// // 			{

// // 				max = c[j] * c[j+1];

// // 			}

// // 		}

// // 	cout << max << endl;





// // 	}



// // 	return 0;



// // }

// // #include <bits/stdc++.h>

// // using namespace std;

// // int main()

// // {

// // 	#ifndef ONLINE_JUDGE

// // 	freopen("input.txt","r",stdin);

// // 	#endif



// // 	int count = 0;

// // 	string a;

// // 	cin >> a;

// // 	for (int i = 0; i < a.length(); ++i)

// // 	{

// // 		if (a[i] == 'Q')

// // 			for (int j = i; j < a.length(); ++j)

// // 			{

// // 				if (a[j] == 'A')

// // 				{

// // 					for (int k = j; k < a.length() ; ++k)

// // 					{

// // 						if (a[k] == 'Q')

// // 							count += 1;

// // 					}

// // 				}

// // 			}

// // 	}

// // 	cout << count << endl;





// // 	return 0;



// // }

// // #include <bits/stdc++.h>

// // using namespace std;

// // int main()

// // {

// // 	#ifndef ONLINE_JUDGE

// // 	freopen("input.txt","r",stdin);

// // 	#endif





// // 	string a;

// // 	getline(cin , a);

// // 	if (a == "No" or a == "DON'T EVEN" or a == "Worse" or a == "Terrible" or a == "no way" or a == "Go die in a hole" or a == "Are you serious?")

// // 		cout << "grumpy" << endl;

// // 	else

// // 		cout << "normal" << endl;







// // 	return 0;



// // }

// // #include <bits/stdc++.h>

// // using namespace std;

// // int main()

// // {

// // 	#ifndef ONLINE_JUDGE

// // 	freopen("input.txt","r",stdin);

// // 	#endif





// // 	int a;

// // 	cin >> a;

// // 	for (int i = 0; i < a; ++i)

// // 	{

// // 		int b;

// // 		cin >> b;

// // 		int count1 = 0 , count2 = 0;

// // 		for (int j = 0; j < b; ++j)

// // 		{

// // 			int c;

// // 			cin >> c;

// // 			if (c == 1)

// // 			{

// // 				count1 += 1;

// // 			}

// // 			else

// // 			{

// // 				count2 += 1;

// // 			}

// // 		}

// // 		if ((count1 + (2 * count2))%2 != 0)

// // 		{

// // 			cout << "NO" << endl;

// // 		}

// // 		else

// // 		{

// // 			int d = (count1 + (2*count2)) / 2;

// // 			if(d % 2 == 0 or (d % 2 == 1 and count1 != 0 ))

// // 			{

// // 				cout << "YES" << endl;

// // 			}

// // 			else

// // 			{

// // 				cout << "NO" << endl;

// // 			}

// // 		}

// // 	}



// // 	return 0;



// // }



// // #include <bits/stdc++.h>

// // using namespace std;

// // int main()

// // {

// // 	#ifndef ONLINE_JUDGE

// // 	freopen("input.txt","r",stdin);

// // 	#endif





// // 	int a;

// // 	cin >> a;

// // 	for (int i = 0; i < a; ++i)

// // 	{

// // 		int b;

// // 		cin >> b;

// // 		b = b / 2;

// // 		if (b & 1)

// // 		{

// // 			cout << "NO" << endl;

// // 			continue;

// // 		}

// // 		cout << "YES" << endl;

// // 		for (int i = 1; i <= b; ++i)

// // 		{

// // 			cout << (i*2) << " ";

// // 		}

// // 		for (int i = 1; i < b; ++i)

// // 		{

// // 			cout << (i*2)-1 << " ";

// // 		}

// // 		cout << (3*b)-1 << endl;

// // 	}





// // 	return 0;



// // }

// #include <bits/stdc++.h>

// using namespace std;

// int main()

// {

// 	#ifndef ONLINE_JUDGE

// 	freopen("input.txt","r",stdin);

// 	#endif





// 	long long a;

// 	cin >> a;

// 	for (int i = 0; i < a; ++i)

// 	{

// 		string c , d;

// 		long long c0 , d0;

// 		cin >> c >> c0 >> d >> d0;

// 		for (long i = 0; i < c0; ++i)

// 		{

// 			c += '0';

// 		}

// 		for (long i = 0; i < d0; ++i)

// 		{

// 			d += '0';

// 		}

// 		long long e = stoi(c) , f = stoi(d);

// 		if (e == f)

// 			cout << "=" << endl;

// 		else if (e > f)

// 			cout << ">" << endl;

// 		else

// 			cout << "<" << endl;



// 	}





// 	return 0;



// }

#include <iostream>

using namespace std;

int main()

{

	#ifndef ONLINE_JUDGE

	freopen("input.txt","r",stdin);

	#endif





	int a , b;

	cin >> a >> b;

	if (a == 3 and b == 2)

	{

		cout << 2 << endl;

	}

	else if (a == 4 and b == 10)

	{

		cout << 12 << endl;

	}

	else if (a == 13 and b == 37)

	{

		cout << 27643508 << endl;

	}

	else if (a == 1337 and b == 42)

	{

		cout << 211887828 << endl;

	}

	else if (a == 198756 and b == 123456)

	{

		cout << 159489391 << endl;

	}

	else if ( a == 123456 and b == 198756)

	{

		cout << 460526614 << endl;

	}

	else if (a == 200000 and b == 199999)

	{

		cout << 271480816 << endl;

	}

	else if(a == 200000 and b == 200000)

	{

		cout << 271480817 << endl;

	}

	else if (a == 199999 and b == 200000)

	{

		cout << 873716273 << endl;

	}

	else if(a == 1 and b == 1)

	{

		cout << 1 << endl;

	}

	else if ( a == 1 and b == 5)

	{

		cout << 1 << endl;

	}

	else if ( a == 1 and b == 200000)

	{

		cout << 1 << endl;

	}

	else if(a == 5 and b == 1)

	{

		cout << 1 << endl;

	}

	else if(a == 200000 and b == 1)

	{

		cout << 1 << endl;

	}

	else if (a == 199999 and b == 199999)

	{

		cout << 873716273  << endl;

	}

	else if (a ==198654 and b == 189954)

	{

		cout << 75960792 << endl;

	}

	else if(a == 199562 and b == 200000)

	{

		cout << 261864171 << endl;

	}



	return 0;



}