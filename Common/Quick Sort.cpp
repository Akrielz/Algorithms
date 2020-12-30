/*
 * Input: A list of numbers
 * Output: The sorted list
 * Complexity: O(n*log(n)), where n = len(List)
 */

#include <fstream>
#include <vector>

using namespace std;

ifstream fin ("algsort.in");
ofstream fout ("algsort.out");

vector <int> partition(vector <int> numbers){
    vector <int> solution, left, equal, right;

    int pivot = numbers[0];

    for ( auto it : numbers ){
        if ( it < pivot )
            left.push_back(it);
        if ( it == pivot )
            equal.push_back(it);
        if ( it > pivot )
            right.push_back(it);
    }

    if ( left.size() > 1 )
        left = partition(left);
    if ( right.size() > 1 )
        right = partition(right);

    for ( auto it : left )
        solution.push_back(it);
    for ( auto it : equal )
        solution.push_back(it);
    for ( auto it : right )
        solution.push_back(it);
    return solution;
}

int totalNumbers;

vector <int> numbers, solution;

int main(){
    fin >> totalNumbers;
    int createdNumber;
    for ( int index = 0; index < totalNumbers; index++ ){
        fin >> createdNumber;
        numbers.push_back(createdNumber);
    }
    solution = partition(numbers);
    for ( auto it : solution )
        fout << it << " ";
    return 0;
}