/*
 * Input: n, e
 * Output: pow(n, e) % mod
 * Complexity: O(log(e))
 */

#include <iostream>
#include <fstream>

#define lli long long int

using namespace std;

ifstream f ("lgput.in");
ofstream g ("lgput.out");

const int modulo = 1999999973;

lli risingPower(lli number, lli exponent)
{
    number %= modulo;
    if ( exponent == 1 )
        return number;

    if ( exponent % 2 )
        return (risingPower( number*number, (exponent-1) / 2) * number) % modulo;
    else
        return risingPower( number*number, exponent/2) % modulo;
}

int main()
{
    lli number, exponent;

    f >> number >> exponent;
    g << risingPower(number, exponent);
}