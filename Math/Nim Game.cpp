/*
 * Input: The number of rocks from each set
 * Output: If the first player can win the NIM GAME in game theory
 * Complexity: O(n)
 */

#include <fstream>

using namespace std;

ifstream fin ("nim.in");
ofstream fout ("nim.out");

int totalTests, totalNumbers;

int main(){
    fin >> totalTests;

    int number, xorSum;
    for ( ; totalTests; totalTests-- ){

        fin >> totalNumbers;

        xorSum = 0;
        for ( ; totalNumbers; totalNumbers-- ){

            fin >> number;
            xorSum ^= number;
        }

        fout << ( xorSum ? "DA\n" : "NU\n" );
    }
    return 0;
}