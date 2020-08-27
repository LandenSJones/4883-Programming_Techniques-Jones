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
		if(p1 > 20 || p2 > 20 || p3 > 20)
			cout << "bad\n";
		else
			cout << "good\n";
	}
	return 0; 
}
