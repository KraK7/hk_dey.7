#include <iostream>
using namespace std;

int main()
{
	int m, n, x, y;
	cin >> m >> n;
	do
	{
		x=m;
		y=n;
		n--;
		do
		{
			if(x>y)
			{
				x=x-y;
			}
			else
			{
				y=y-x;
			}

		}while(y!=0);
	}while(x==1);
	cout << n+1;
	return 0;

}

