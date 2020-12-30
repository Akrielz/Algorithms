/*
 * Input: List of numbers, List of Queries
 * Queries:
 *  0 x -> upper_bound(L, x) if x in L, else -1
 *  1 x -> lower_bound(L, x+1)
 *  2 x -> upper_bound(L, x-1)
 * Output: Answers for the queries
 */

#include <iostream>
#include <fstream>

#define N 100010

using namespace std;

ifstream f ("cautbin.in");
ofstream g ("cautbin.out");

int numbers[N];

int totalNumbers, totalOperations;

bool found;

int binarySearch0(int value, int leftPosition = 1, int rightPosition = totalNumbers)
{
    int middle;

    while ( leftPosition <= rightPosition )
    {
        middle = ( leftPosition + rightPosition ) / 2;
        if ( numbers[middle] <= value )
            leftPosition = middle + 1;
        else
            rightPosition = middle - 1;
    }
    middle = (leftPosition + rightPosition) / 2;

    if (numbers[middle] > value)
        middle --;
    if (numbers[middle] == value)
        return middle;
    return -1;
}

int binarySearch1(int value, int leftPosition = 1, int rightPosition = totalNumbers)
{
    int middle;

    while ( leftPosition < rightPosition )
    {
        middle = ( leftPosition + rightPosition ) / 2;
        if ( numbers[middle] <= value )
            leftPosition = middle + 1;
        else
            rightPosition = middle;
    }
    middle = (leftPosition + rightPosition) / 2;

    if (numbers[middle] > value)
        middle --;
    return middle;
}

int binarySearch2(int value, int leftPosition = 1, int rightPosition = totalNumbers)
{
    int middle;

    while ( leftPosition < rightPosition )
    {
        middle = ( leftPosition + rightPosition ) / 2;
        if ( numbers[middle] < value )
            leftPosition = middle + 1;
        else
            rightPosition = middle;
    }
    middle = (leftPosition + rightPosition) / 2;

    if (numbers[middle] < value)
        middle ++;
    return middle;
}

inline void readVariables()
{
    f >> totalNumbers;
    for ( int index = 1; index <= totalNumbers; index++)
        f >> numbers[index];

    f >> totalOperations;
    int operation, value;
    for ( ; totalOperations; totalOperations-- )
    {
        f >> operation >> value;
        switch(operation)
        {
            case 0: g << binarySearch0(value) << "\n"; break;
            case 1: g << binarySearch1(value) << "\n"; break;
            case 2: g << binarySearch2(value) << "\n"; break;
        }
    }
}

int main()
{
    readVariables();
}