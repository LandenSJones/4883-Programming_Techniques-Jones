//Landen Jones
//UVA 540 - Team Queue
//This program demonstrates the use of "Team Queue", where it reads in the number of teammates
//per team. When a teammate is pushed onto the combined queue, we'll search to see if they have any teammates in the queue.
//If there are teammate, then we place him by his teammate. 
#include <iostream>
#include <queue>
#include <fstream>
using namespace std;

int main()
{
    ifstream infile;
    //infile.open("input");
    int teamBelongTo[1000001];
    
    int count = 1;
    int numTeams;
    while (cin >> numTeams && numTeams)
    {
        queue<int> teamQueue[1001];
        for (int i = 0; i < numTeams; ++i)
        {
            int numElem;
            cin >> numElem;
            while (numElem--)
            {
                int elem;
                cin >> elem;
                teamBelongTo[elem] = i;
            }
        }
        
        queue<int> combinedQueue;
        
        cout << "Scenario #" << count++ << '\n';
        string command;
        //Checks to see if we should stop
        while (cin >> command && command[0] != 'S')
        {
            //Checks to see if it is an enqueue
            if (command[0] == 'E')
            {
                int num;
                cin >> num;
                int team = teamBelongTo[num];
                if (teamQueue[team].empty())
                {
                    combinedQueue.push(team);
                }
                
                teamQueue[team].push(num);
            }
            //Checks to see if it a dequeue
            else
            {
                int team = combinedQueue.front();
                cout << teamQueue[team].front() << '\n';
                teamQueue[team].pop();
                if (teamQueue[team].empty())
                    combinedQueue.pop();
            }
        }
        cout << '\n';
    }
}
