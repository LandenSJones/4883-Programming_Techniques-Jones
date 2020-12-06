#include <iostream>
#include <string>
#include <map>
#include <iomanip>
using namespace std;
int main()
{
    int iterations;
    string tree;

    cin >> iterations;

    getline(cin, tree);
    getline(cin, tree);

    while(iterations != 0)
    {
        map <string, int> treeCounter;  //map to key and value a tree
        int treeTotal = 0;
        while(getline(cin, tree))
        {
            if(tree == "")
            {
                break;
            }
            treeTotal++;
            treeCounter[tree]++;
        }
        for(map <string , int> :: iterator i = treeCounter.begin(); i != treeCounter.end(); i++)
            cout << i->first << ' ' << fixed << setprecision(4) << i->second * (100.0/treeTotal) << '\n';

        iterations--;
        if(iterations != 0)
        {
            cout << '\n';
        }
    }

    return 0;
}