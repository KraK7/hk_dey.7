#include <iostream>
using namespace std;

int main()
{
	int n, m, x, y;
	cin >> m >> n;
	x=1;
	while(x==1)
	{
		x=m;
		y=n;
		n--;
		while(x!=y)
		{
			if(x>y)
			{
				x=x-y;
			}
			else
			{
				y=y-x;
			}
		}
	}
	cout << n+1;
	return 0;
}

