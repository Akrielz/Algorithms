/*
 * Input: n
 * Output: Nr of prime numbers that are < n
 * Complexity: O(n*log(log(n)))
 * Side Note: It also marks all the positions of the prime numbers
 */

#include <iostream>
#include <fstream>
#include <vector>

#define N 2000005

using namespace std;

ifstream f ("ciur.in");
ofstream g ("ciur.out");

vector <bool> prim(N, true);

int number;

int ciurEratosthenes()
{
    int counter = 0;
    for ( int index = 2 ; index <= number ; index++ )
    {
        if (prim[index])
        {
            counter ++;
            for ( int multiples = index; multiples <= number; multiples += index )
                prim[multiples] = false;
        }
    }
    return counter;
}

int main()
{
    f >> number;
    g << ciurEratosthenes();
}