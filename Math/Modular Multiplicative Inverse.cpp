/*
 * Input: a, n
 * Output: x such that (a*x) % n = 1
 * Complexity: O(log(n) + sqrt(n))
 */

#include <fstream>

#define type long long int

using namespace std;

ifstream fin ("inversmodular.in");
ofstream fout ("inversmodular.out");

type number, modulo, power = 1, inversModular, mask;

bool prime(type checkNumber){
    if ( checkNumber == 0 or checkNumber == 1 )
        return false;
    if ( checkNumber == 2 )
        return true;
    for ( int index = 2; index*index <= checkNumber; index++ )
        if ( checkNumber%index == 0 )
            return false;
    return true;
}

type risingPower(type base, type exponent){
    type product = 1;
    for ( ; exponent; exponent >>= 1 ){
        if ( exponent % 2 )
            product = (product * base) % mask;
        base = (base*base) % mask;
    }
    return product;
}

int main(){
    fin >> number >> modulo;
    mask = modulo;
    if ( prime(modulo) == 1 )
        inversModular = risingPower(number, modulo-2);
    else{
        for ( int index = 2; index*index <= modulo; index++ ){
            if ( modulo % index == 0 ){
                power *= (index-1);
                while ( modulo % index == 0 ){
                    power *= index;
                    modulo /= index;
                }
                power /= index;
            }
        }
        if ( modulo > 0 and modulo != 1 )
            power *= (modulo-1);
        inversModular = risingPower(number, power-1);
    }
    fout << inversModular;
}