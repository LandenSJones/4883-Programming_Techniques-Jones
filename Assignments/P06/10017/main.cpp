#include <iostream>
#include <fstream>
using namespace std;

int n, m;
//3 pegs, at most 252 discs
int pegs[3][252];
//used to hold the height of each peg
int top[3];

void print_pegs()
{
    for(int i = 0; i < 3; i++)
    {
        cout << char('A' + i) << "=>";
        if (top[i] >= 0)
        {
            cout << "  ";
            for(int j = 0; j <= top[i];j++)
                cout << " " << pegs[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void solve(int a, int b, int c, int n)
{
    if (n > 0)
    {
        solve(a, c, b, n-1);

        pegs[c][++top[c]] = pegs[a][top[a]--];
        if (m-- > 0)
            print_pegs();
        else
            return;
        
        solve(b, a, c, n-1);
    }
}

int main(void) 
{
    //ifstream infile;
    //infile.open("input");
    int case_number = 1;

    while (cin >> n >> m) 
    {
        if (n == 0 && m == 0)   //Exit on 0,0
            break;
        cout << "Problem #" << case_number << endl << endl;

        //Initialize initial values of pegs, based un input
        for (int i = n; i >= 1; i--)
            pegs[0][n-i] = i;
        top[0] = n - 1;
        top[1] = top[2] = -1;
        //prints initial values of pegs
        print_pegs();
        //solves recursively, n times
        solve(0, 1, 2, n);
        case_number++;
    }
    return 0;
}