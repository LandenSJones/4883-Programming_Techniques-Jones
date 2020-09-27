//Landen Jones
//09/27/2020
#include <iostream>
#include <fstream>
#include <stack>
using namespace std;

int main()
{
    int numCars, fullTrain[1000], currCoach, fullTrainIndex;
    ifstream infile;
    //infile.open("input.txt");

    while (true)
    {
        cin >> numCars;
        if (numCars == 0)
            break;
        while (true)
        {
            cin >> fullTrain[0];
            if (fullTrain[0] == 0)
            {
                cout << endl;
                break;
            }
            for (int i = 1; i < numCars; i++)
                cin >> fullTrain[i];
            currCoach = 1;
            fullTrainIndex = 0;
            stack<int> station;
            while (currCoach <= numCars)
            {
                station.push(currCoach);
                while (!station.empty() && station.top() == fullTrain[fullTrainIndex])
                {
                    station.pop();
                    fullTrainIndex++;
                    if (fullTrainIndex >= numCars)
                        break;
                }
                currCoach++;
            }
            if (station.empty())
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
    return 0;
}
