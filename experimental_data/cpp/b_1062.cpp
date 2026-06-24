#include<iostream>

#include<cmath>

using namespace std;

int main()
{
	int n, p = 1, maxi = 0;
	
	cin >> n;
	
	if (n == 1)
	{
		cout << 1 << ' ' << 0;
		
		return 0;
	}
	
	int c = -1, count = 0;
	bool flag = 1;
	
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			p *= i;
			
			count = 0;
			
			while (n % i == 0)
			{
				count++;
				
				n /= i;
			}
			
			if (c == -1)
				c = count;
			else if (count != c)
				flag = 0;
			
			maxi = max(maxi, count);
			
			count = 0;
		}
	}
	
	p *= n;
	
	if (n != 1)
		count++;
			
	if (c == -1)
		c = count;
	else if (count && count != c)
		flag = 0;
	
	maxi = max(maxi, count);
	
	int st = log(maxi) / log(2);
	
	if (int(pow(2, st)) < maxi)
		st++;
	
	if (int(pow(2, st)) == maxi && flag)
		cout << p << ' ' << st;
	else
		cout << p << ' ' << st + 1;
}