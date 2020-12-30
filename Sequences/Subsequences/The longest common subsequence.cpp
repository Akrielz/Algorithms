/*
 * Solves: Longest common subsequence from two sequences
 * Input: The two sequences
 * Output: Longest common subsequence
 * Complexity: O(n*m), where n = len(seq[0]), m = len(seq[1])
 */

#include <iostream>
#include <fstream>
#include <algorithm>

#define N 1025

using namespace std;

ifstream f ("cmlsc.in");
ofstream g ("cmlsc.out");

int sirA[N],
        sirB[N],
        sirC[N];

int matrix[N][N];

int lungA,
        lungB;

int indexC;

inline void readVariables()
{
    f >> lungA >> lungB;
    for ( int index = 1; index <= lungA; index++ )
        f >> sirA[index];
    for ( int index = 1; index <= lungB; index++ )
        f >> sirB[index];
}

inline void constructMatrix()
{
    for ( int indexA = 1; indexA <= lungA; indexA++ )
        for ( int indexB = 1; indexB <= lungB; indexB++ )
            if ( sirA[indexA] == sirB[indexB] )
                matrix[indexA][indexB] = matrix[indexA-1][indexB-1] + 1;
            else
                matrix[indexA][indexB] = max(matrix[indexA-1][indexB], matrix[indexA][indexB-1]);
}

inline void subSir()
{
    for (int indexA = lungA, indexB = lungB; indexA > 0; )
    {
        if ( sirA[indexA] == sirB[indexB] )
        {
            sirC[indexC++] = sirA[indexA];
            indexA--;
            indexB--;
        }
        else
        {
            if ( matrix[indexA-1][indexB] < matrix[indexA][indexB] )
                indexB--;
            else
                indexA--;
        }
    }
}

inline void printSolution()
{
    g << indexC << "\n";
    for ( int index = indexC -1; index >= 0; index-- )
        g << sirC[index] << " ";
}

int main()
{
    readVariables();
    constructMatrix();
    subSir();
    printSolution();
}