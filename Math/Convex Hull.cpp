/*
 * Input: A list of 2D points
 * Output: The convex hull of the list
 * Complexity: O(nlog(n)), where n = len(List)
 */

#include <fstream>
#include <algorithm>
#include <iostream>
#include <iomanip>

using namespace std;

ifstream fin("infasuratoare.in");
ofstream fout("infasuratoare.out");

const int N {120005};

struct coordonates{
    double x;
    double y;

    coordonates (void){
    };

    coordonates (double x, double y){
        this->x = x;
        this->y = y;
    }

    bool lowerThan(coordonates B){
        if ( y < B.y )
            return true;
        if ( x < B.x and y == B.y )
            return true;
        return false;
    }

};

coordonates points[N], leftBottom, Stack[N] ;

int totalPoints, positionLeftBottom, top;

double aria(coordonates A, coordonates B, coordonates C){
    return A.x*B.y + B.x*C.y + C.x*A.y - C.x*B.y - B.x*A.y - A.x*C.y;
}

double epsilon = 0.00000001;

bool compare(coordonates A, coordonates B, coordonates C = points[1]){
    double delta = aria(A, B, C);
    if ( delta > epsilon )
        return true;
    if ( delta < -epsilon )
        return false;
    return false;
}

bool trigger(coordonates A, coordonates B){
    return compare(A, B);
}

inline void readVariables(void){
    fin >> totalPoints;
    fin >> points[1].x >> points[1].y;
    leftBottom = points[1];
    positionLeftBottom = 1;
    for ( int index = 2; index <= totalPoints; index++ ){
        fin >> points[index].x >> points[index].y;
        if ( !leftBottom.lowerThan(points[index]) ){
            positionLeftBottom = index;
            leftBottom = points[index];
        }
    }
    swap(points[positionLeftBottom], points[1]);
}

inline void convexHull(void){
    Stack[1] = points[1];
    Stack[2] = points[2];
    top = 2;
    for ( int index = 3; index <= totalPoints; index++ ){
        for ( ; !compare(Stack[top-1], Stack[top], points[index]); )
            top--;
        Stack[++top] = points[index];
    }

}

inline void displayPoints(void){
    for ( int index = 1; index <= totalPoints; index++ )
        cout << points[index].x << " " << points[index].y << "\n";
    cout << "\n";
}

inline void solveProblem(void){
    sort (points+2, points+totalPoints+1, trigger);
    convexHull();
    fout << top << "\n";
    for ( int index = 1; index <= top; index++ )
        fout << fixed << setprecision(6) << Stack[index].x << " " << Stack[index].y << "\n";
}

int main(){
    readVariables();
    solveProblem();
}