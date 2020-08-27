#include <iostream>
#include <fstream>
using namespace std;
int main() 
{
	/*ifstream infile;
	infile.open("infile.txt");*/
	int total = 0, count, x;
	string text;
	cin >> count;
	for(int i = 0; i < count; i++)
	{
		cin >> text;
		if(text == "donate")
		{
			cin >> x;
			total += x;
		}
		else if (text == "report")
		{
			cout << total << '\n';
		}
		else
			cout << "error";
	}
	
	return 0; 
}
