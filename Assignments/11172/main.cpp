#include <iostream>
#include <fstream>
using namespace std;
int main() 
{
	int x, l, r;
	cin >> x;
	for(int i = 0; i < x; i++)
	{
		cin >> l >> r;
		if(l > r)
			cout << ">\n";
		else if (l < r)
			cout << "<\n";
		else
			cout << "=\n";
	}
	return 0; 
}
