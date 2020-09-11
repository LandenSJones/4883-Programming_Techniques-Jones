//Very close but doesn't quite work yet

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
vector<vector<string> > CreateGameBoard(vector<string>);
vector<string> ReadGame(string, ifstream&);
bool FirstCompatable(string a, string b);
bool SecondCompatable(string a, string b);
void PlayGame(vector<vector<string> >&);
bool IsEmpty(vector<string> vec);
void Collapse(vector<vector<string> >& game, int index, int& stacks);
int main()
{
    ifstream infile;
    //infile.open("input.txt");
    string firstCard;
    cin >> firstCard;

    while (firstCard[0] != '#')
    {
        vector<string> data = ReadGame(firstCard, infile); //READS DATA FROM TEXT FILE , , infile
        vector<vector<string> > game = CreateGameBoard(data);
        PlayGame(game);
        cin >> firstCard; //RESETS
        if (firstCard[0] != '#')
            cout << endl;
    }
    cout << '\n';
    return 0;
}

vector<string> ReadGame(string firstCard, ifstream& infile) //, ifstream &infile
{
    vector<string> data;
    data.push_back(firstCard);
    string temp;
    for (int i = 0; i < 51; i++)
    {
        cin >> temp;
        data.push_back(temp);
    }
    return data;
}
vector<vector<string> > CreateGameBoard(vector<string> cards)
{
    vector<vector<string> > result;
    vector<string> holder;
    for (int i = 0; i < 52; i++)
    {
        result.push_back(holder);
        result[i].push_back(cards[i]);
    }
    return result;
}
void PlayGame(vector<vector<string> >& game)
{
    bool running = true;            //Condition to see if game is running
    int i = 0, stacks = 52;                      //Index variable
    while (running == true)
    {
        if (i == 0)
        {
            i++;
        }
        else if (i >= stacks)
        {
            running = false;
        }
        else if (i > 0 && i < 3)
        {
            if (FirstCompatable(game[i].back(), game[i - 1].back()) || SecondCompatable(game[i].back(), game[i - 1].back()))
            {
                game[i - 1].push_back(game[i].back());
                game[i].pop_back();
                if (game[i].empty())
                {
                    Collapse(game, i, stacks);
                }
                i--;
            }
            else
                i++;

        }
        else if (i >= 3 && i < stacks)
        {
            if (FirstCompatable(game[i].back(), game[i - 3].back()) || SecondCompatable(game[i].back(), game[i - 3].back()))
            {
                game[i - 3].push_back(game[i].back());
                game[i].pop_back();
                if (game[i].empty())
                {
                    Collapse(game, i, stacks);
                }
                i = i - 3;
            }
            else if (FirstCompatable(game[i].back(), game[i - 1].back()) || SecondCompatable(game[i].back(), game[i - 1].back()))
            {
                game[i - 1].push_back(game[i].back());
                game[i].pop_back();
                if (game[i].empty())
                {
                    Collapse(game, i, stacks);
                }
                i--;
            }
            else
                i++;
        }
        else
        {
            cout << "Not sure how we got here.\n";
            running = false;
        }
    }
    if (stacks == 1)
        cout << stacks << " pile remaining: ";
    else
        cout << stacks << " piles remaining: ";
    for (int j = 0; j < stacks; j++)
    {
        cout << game[j].size() << ' ';
    }
}
void Collapse(vector<vector<string> >& game, int index, int& stacks)
{
    for (int i = index; i < stacks - 1; i++)
    {
        game[i] = game[i + 1];
        game[i + 1].clear();
    }
    stacks--;
}
bool FirstCompatable(string a, string b)
{
    return a[0] == b[0];
}
bool SecondCompatable(string a, string b)
{
    return a[1] == b[1];
}
bool IsEmpty(vector<string> vec)
{
    return (vec.size() == 0);
}
