//Landen Jones
//11/10/2020
//UVA920 - Sunny Mountains

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

//Point structure for convenience
struct Point
{
    int x, y;
    Point(int newX, int newY)
    {
        x = newX;
        y = newY;
    }
};

//Returns the Euclidean Distance between point a and b
double Dist(Point a, Point b)
{
    return sqrt((double)(a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

//Compares x values, returns bool
bool Comp(const Point &a, const Point &b)
{
    return b.x < a.x;
}

int main()
{   
    ifstream infile;
    infile.open("input");
    int C;
    infile >> C;
    while ( C-- )
    {
        int N;
        infile >> N;
        vector<Point> points;
        for (int i = 1; i <= N; ++i)
        {
            int tempx, tempy;
            infile >> tempx >> tempy;
            Point point(tempx,tempy);
            points.push_back(point);
        }

        //Sort the points in descending order of x-coordinate.
        sort(points.begin(), points.end(), Comp);
        int currentMaxY = 0;
        double length = 0;
        for (int i = 1; i < points.size(); ++i)
        {
            if (points[i].y > currentMaxY)
            {
                length += Dist(points[i], points[i - 1]) * (points[i].y - currentMaxY) / (points[i].y - points[i - 1].y); 
                currentMaxY = points[i].y;
            }
        }

        // Print with two decimal digits.
        cout << setprecision(2) << fixed << length << endl;
    }
    return 0;
}