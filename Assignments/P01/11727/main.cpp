#include <iostream>
#include <fstream>
using namespace std;
int main() 
{
	/*ifstream infile;
	infile.open("infile.txt");*/
	int count, p1, p2, p3;
	cin >> count;
	for(int i = 0; i < count; i++)
	{
		cout << "Case " << i+1 << ": ";
		cin >> p1 >> p2 >> p3;
		if((p1 > p2 && p1 < p3) || (p1 < p2 && p1 > p3))
			cout << p1 << '\n';
		else if ((p2 < p1 && p2 > p3) || (p2 > p1 && p2 < p3))
			cout << p2 << '\n';
		else
			cout << p3 << '\n';
	}
	return 0; 
}
