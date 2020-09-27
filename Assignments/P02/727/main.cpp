#include <iostream>
#include <fstream>
#include <stack>
using namespace std;

bool Precedence(char, char);

int main() 
{
    ifstream infile;
    //infile.open("input.txt");
    int cases;  //Holds iterations
    char next;  //Holds next variable read in
    stack <char> test;  //Will hold the equation
    cin >> cases;
    cin.ignore(2, '\n');     //Reads x chars or until white space
    for(int i = 0; i < cases; i++)
    {
        cin.ignore(10, '\n');
        while (cin.peek() != '\n' && cin.peek() != -1) //Checks to be sure that there is more data in equation
        {
            cin >> next;
            cin.ignore(10, '\n');
            if (next == ')')
            {
                while (test.top() != '(')
                {
                    cout << test.top();
                    test.pop();
                }
                test.pop();
            }
            else if (next == '(')
                test.push(next);
            else if (next == '+' || next == '-' || next == '*' || next == '/')
            {
                if (test.empty())
                    test.push(next);
                else 
                {
                    while (!test.empty() && test.top() != '(')
                    {
                        if (Precedence(test.top(), next))
                        {
                            cout << test.top();
                            test.pop();
                        }
                        else 
                            break;
                    }
                    test.push(next);
                }
            }
            else 
                cout << next;
        }
        while (!test.empty())
        {
            cout << test.top();
            test.pop();
        }
        if (i < cases-1)
            cout << endl << endl;
    }
    cout << endl;
    return 0;
}
bool Precedence(char str1, char str2)
{
    return(str2 == '*' || str2 == '/')<= (str1 == '*' || str1 == '/');
}
