#include <iostream>
using namespace std;

struct Point{
    int x;
    int y;

//      Quadrant 1 - x is positive, y is positive
//      Quadrant 2 - x is negative, y is positive
//      Quadrant 3 - x is negative, y is negative
//      Quadrant 4 - x is positive, y is negative

    int getQuadrant(){

        if(x == 0 || y == 0){
            return -1; // axis
        } else if(x == 0 && y == 0){
            return 0; // origin
        } else if(x > 0 && y > 0){
            return 1; // Q1
        } else if(x < 0 && y > 0){
            return 2; // Q2
        } else if(x < 0 && y < 0){
            return 3; // Q3
        } else if(x > 0 && y < 0){
            return 4; // Q4
        }
        
        return -2;
    }
};

int main(){
    Point point;

    cout << "Enter x value: ";
    cin >> point.x;
    cout << "Enter y value: ";
    cin >> point.y;
    
    int quadrant = point.getQuadrant();

    switch (quadrant)
    {
    case 0:
        cout << "Origin." << endl;
        break;
    case -1:
        cout << "In the axis." << endl;
        break;
    case 1:
        cout << "Quadrant 1" << endl;
        break;
    case 2:
        cout << "Quadrant 2" << endl;
        break;
    case 3:
        cout << "Quadrant 3" << endl;
        break;
    case 4:
        cout << "Quadrant 4" << endl;
        break;
    default:
        cout << "\nInvalid input" << endl; 
        break;
    }
}