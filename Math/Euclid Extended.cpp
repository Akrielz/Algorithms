/*
 * Input: a, b, c
 * Output: x, y such that a*x + b*y = c
 * Complexity: O(log(max(a, b)))
 */

#include <iostream>
#include <fstream>

using namespace std;

ifstream f ("euclid3.in");
ofstream g ("euclid3.out");

inline int extendedEuclid( int A, int B, int &X, int &Y )
{
    if (B == 0)
    {
        X = 1;
        Y = 0;
        return A;
    }

    int X0, Y0, D;
    D = extendedEuclid( B, A % B, X0, Y0 );

    X = Y0;
    Y = X0 - (A / B) * Y0;
    return D;
}

int totalNumbers;

inline void readVariables()
{
    f >> totalNumbers;
    for ( ; totalNumbers ; totalNumbers-- )
    {
        int A, B, C;
        f >> A >> B >> C;

        int D, X, Y;
        D = extendedEuclid( A, B, X, Y );

        if ( C % D )
            g << "0 0\n";
        else
            g << X * (C / D) << " " << Y * (C / D) << "\n";
    }
}

int main()
{
    readVariables();
}