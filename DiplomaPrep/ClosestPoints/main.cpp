#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point
{
    int x;
    int y;

};

vector<Point> findPoints(vector<Point> points, Point A, Point B, Point C, Point D) {

    int min = INT_MAX;
    int distance = 0;
    int position = 0;

    vector<Point> result;
    Point *sizeChecker[] = {&A, &B, &C, &D};
    for(int i = 0; i < 4; i++) {
          cout << "Point " <<i<<endl;
        for(int j = 0; j < points.size(); j++) {

            distance = pow((sizeChecker[i]->x - points[j].x), 2) + pow((sizeChecker[i]->y - points[j].y), 2);
            if(distance <= min) {
               min = distance;
               position = j;
                cout <<"pos: "<<position<<endl;
            }

            cout <<"distance: "<<distance<< endl;
        }
         result.push_back(points[position]);
         min = INT_MAX;
    }
    return result;
}

int main()
{
    Point A = {4, 4};
    Point B = {2, 3};
    Point C = {6, 6};
    Point D = {9, 9};
    vector<Point> points = {{4, 4},{3, 4}, {3, 3}, {6, 7}};

    vector<Point> result = findPoints(points, A, B, C, D );
    for(int i = 0; i < result.size(); i++) {
         cout <<"x at Vector Pos " << i << ": " << result.at(i).x << " y at Vector Pos " << i << ": " <<result.at(i).y <<endl;

    }

    return 0;
}
