#include <iostream>
#include <fstream>
using namespace std;
int main() 
{
	/*ifstream infile;
	infile.open("infile.txt");*/
	int run,xdiv,ydiv,xcor,ycor;
	cin >> run;
	while(run != 0)
	{
		cin >> xdiv >> ydiv;
		for(int i = 0; i < run; i++)
		{
			cin >> xcor >> ycor;
			if(xcor > xdiv && ycor > ydiv)
				cout << "NE\n";
			else if(xcor < xdiv && ycor > ydiv)
				cout << "NO\n";
			else if(xcor > xdiv && ycor < ydiv)
				cout << "SE\n";
			else if(xcor < xdiv && ycor < ydiv)
				cout << "SO\n";
			else
				cout << "divisa\n";
		}
		cin >> run;
	}
	return 0; 
}
