#include <iostream>
#include <fstream>
#include <stack>
using namespace std;

bool Precedence(char, char);

int main() 
{
    ifstream infile;
    infile.open("input.txt");
    int cases;  //Holds iterations
    char next;  //Holds next variable read in
    stack <char> test;  //Will hold the equation
    infile >> cases;
    infile.ignore(2, '\n');     //Reads x chars or until white space
    for(int i = 0; i < cases; i++)
    {
        infile.ignore(10, '\n');
        while (infile.peek() != '\n' && infile.peek() != -1) //Checks to be sure that there is more data in equation
        {
            infile >> next;
            infile.ignore(10, '\n');
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
        cout << endl;
        if (cases)
            cout << endl;
    }
    return 0;
}
bool Precedence(char str1, char str2)
{
    return(str1 == '*' || str1 == '/') >= (str2 == '*' || str2 == '/');
}
