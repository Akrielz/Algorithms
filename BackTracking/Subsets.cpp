/*
 * Input: n
 * Output: All the possible subsets of n
 * Complexity: O(2^n)
 */

#include <fstream>
#include <vector>

using namespace std;

int number,
        binaryPow;

ifstream fin("submultimi.in");
ofstream fout("submultimi.out");

string binaryRepresentation;

template <class type>
void morphToGroup(type number, vector<int> &result){
    type bit = 1<<(int)(log2(number));
    for ( ;number or bit; bit>>=1 ){
        if ( number - bit >= 0 ){
            result.push_back(log2(bit)+1);
            number -= bit;
        }
    }
}

inline void solveProblem(){
    binaryPow = 1<<(number);
    vector <int> group;
    for ( int index = 1; index < binaryPow; index++ ){
        group.clear();
        morphToGroup(index, group);
        vector <int> :: reverse_iterator element;
        for ( element = group.rbegin(); element < group.rend(); element++)
            fout << *element << " ";
        fout << "\n";
    }
}

int main(){
    fin >> number;
    solveProblem();
    return 0;
}