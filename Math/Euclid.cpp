/*
 * Solves greatest common divisor from x and y
 * Input: x and y
 * Output: gcd(x, y)
 * Complexity O(log(max(x, y))
 */

#include <iostream>
#include <fstream>

using namespace std;

ifstream f ("euclid2.in");
ofstream g ("euclid2.out");

int first, second;

int totalNumbers;

template <class someType>
someType euclid (someType first, someType second)
{
    someType auxiliary;
    while (second)
    {
        auxiliary = first % second;
        first = second;
        second = auxiliary;
    }
    return first;
}

void readVariables()
{
    f >> totalNumbers;
    for ( ; totalNumbers ; totalNumbers-- )
    {
        f >> first >> second;
        g << euclid<int>(first, second)<< "\n" ;
    }
}

int main()
{
    readVariables();
}