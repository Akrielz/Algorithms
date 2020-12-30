/*
 * Input: A list of numbers
 * Output: The majority element + its frequency
 */

#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin ("elmaj.in");
ofstream fout ("elmaj.out");

const int N = 1e6+1;

long long int numbers[N], totalNumbers, searchedNumber, contor;

int main(){
    fin >> totalNumbers;
    for ( int index = 1; index <= totalNumbers; index++ )
        fin >> numbers[index];

    nth_element(numbers+1, numbers+totalNumbers/2, numbers+totalNumbers+1);
    searchedNumber = numbers[totalNumbers/2];

    for ( int index = 1; index <= totalNumbers; index++ )
        if ( numbers[index] == searchedNumber )
            contor++;

    if ( contor > totalNumbers/2 )
        fout << searchedNumber << " " << contor;
    else
        fout << -1;
}