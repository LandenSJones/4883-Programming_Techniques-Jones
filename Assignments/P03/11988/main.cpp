//Landen Jones
//UVA11988
//This program takes a string of characters and print this inorder. Unless there is a Bracket [   or   ] ...
//When the open bracket is processed we return to the beginning of the string. When the closed bracket is found
//We traverse to the end of the string and continue processing
#include <iostream>
#include <list>
using namespace std;
int main()
{
    string keyboardInput;
    list<char> result;
    while (cin >> keyboardInput)
    { //Using an iterator to jump from the current position to the end or the beginning.
        result.clear();
        list<char>::iterator it = result.begin();
        //Processing the input by going through and analyzing each character
        for (char c : keyboardInput)
        {
            if (c == '[')
                it = result.begin(); //Traverses to the beginning of the result
            else if (c == ']')
                it = result.end(); //Traverses to the end of result
            else
                result.insert(it, c); //Places at current
        }
        for (list<char>::iterator jt = result.begin(); jt != result.end(); ++jt)
        {
            cout << *jt;
        }
        cout << '\n';
    }
    return 0;
}
