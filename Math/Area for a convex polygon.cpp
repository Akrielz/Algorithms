/*
 * Input: List of the points that are describing a convex polygon
 * Output: Its Area
 * Complexity: O(n), where n = len(points)
 */

#include <iomanip>
#include <fstream>

using namespace std;

ifstream fin ("aria.in");
ofstream fout ("aria.out");

const int N = 100005;

struct point{
    double x, y;
};

long double totalAria;

int totalPoints;

point points[N], O;

double aria(point A, point B, point C){
    return ( A.x*B.y + B.x*C.y + C.x*A.y - B.y*C.x - A.y*B.x - C.y*A.x );
}

void readVariables(){
    fin >> totalPoints;

    for ( int index = 1; index <= totalPoints; index++ ){
        fin >> points[index].x >> points[index].y;
    }
}

int main(){
    O.x = O.y = 0;
    readVariables();
    points[totalPoints+1] = points[1];
    for ( int index = 1; index <= totalPoints; index++ )
        totalAria += aria(points[index], points[index+1], O);
    fout << fixed << setprecision(5) << totalAria / 2;
}