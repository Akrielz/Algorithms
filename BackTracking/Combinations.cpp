/*
 * Input: n, k
 * Output: Combinations(n, k)
 * Complexity: O(n!/(k!*(n-k)!)
 */

#include <fstream>
#include <set>
#include <vector>

using namespace std;

const int maxNumbers = (1<<18)+5;

int maxBits, usedBits,
        lg2[maxNumbers];


ifstream fin("combinari.in");
ofstream fout("combinari.out");

set <vector <int> > solutions;

inline void calculateLg2(){
    int stopNumber = 1<<maxBits;
    for ( int index = 2; index <= stopNumber; index++ )
        lg2[index] = lg2[index >> 1] + 1;
}

template <class type>
void morphToGroup(type number, vector<int> &result){
    type bit = 1<<lg2[number];
    for ( ;number or bit; bit>>=1 ){
        if ( number - bit >= 0 ){
            result.push_back(lg2[bit]+1);
            number -= bit;
        }
    }
    reverse(result.begin(), result.end());
}

inline void solveProblem(){
    int startNumber = (1<<usedBits)-1;
    int stopNumber = (1<<maxBits);
    vector <int> group;

    for ( int index = startNumber; index <= stopNumber; index++ ){
        if ( __builtin_popcount(index) == usedBits ){
            group.clear();
            morphToGroup(index, group);
            solutions.insert(group);
        }
    }
}

inline void displaySolutions(){
    for ( const auto& group : solutions ){
        for ( auto element : group )
            fout << element << " ";
        fout << "\n";
    }
}

int main(){
    fin >> maxBits >> usedBits;
    calculateLg2();
    solveProblem();
    displaySolutions();
}