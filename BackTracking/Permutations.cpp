/*
 * Input: n
 * Output: all the permutations of the first n numbers
 * Complexity: O(n!)
 */

#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream fin("permutari.in");
ofstream fout("permutari.out");

int number;

vector <int> permutations;

int main(){
    fin >> number;
    for ( int index = 1; index <= number; index++ )
        permutations.push_back(index);

    do{
        for (auto element : permutations)
            fout << element << " ";
        fout << "\n";
    }while(next_permutation(permutations.begin(), permutations.end()));
    return 0;
}