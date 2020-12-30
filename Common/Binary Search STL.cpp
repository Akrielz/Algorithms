/*
 * Input: List of numbers, List of Queries
 * Queries:
 *  0 x -> upper_bound(L, x) if x in L, else -1
 *  1 x -> lower_bound(L, x+1)
 *  2 x -> upper_bound(L, x-1)
 * Output: Answers for the queries
 */

#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin ("cautbin.in");
ofstream fout ("cautbin.out");

vector <int> numbers;
vector <int> :: iterator itPosition;

int totalNumbers, questions, position;

int main(){
    fin >>totalNumbers;
    for ( int number, index = 1; index <= totalNumbers; index++ ){
        fin >> number;
        numbers.push_back(number);
    }

    fin >> questions;
    for ( int operation, searchedNumber; questions; questions-- ){
        fin >> operation >> searchedNumber;
        switch(operation){
            case 0:
                itPosition = upper_bound(numbers.begin(), numbers.end(), searchedNumber);
                position = itPosition - numbers.begin();
                if ( itPosition >= numbers.begin() and itPosition <= numbers.end() and numbers[position-1] == searchedNumber )
                    fout << itPosition - numbers.begin()<< "\n";
                else
                    fout << -1 << "\n";
                break;
            case 1:
                itPosition = lower_bound(numbers.begin(), numbers.end(), searchedNumber+1);
                fout << itPosition - numbers.begin() << "\n";
                break;
            case 2:
                itPosition = upper_bound(numbers.begin(), numbers.end(), searchedNumber-1);
                fout << itPosition - numbers.begin() +1<< "\n";
                break;
        }
    }
}