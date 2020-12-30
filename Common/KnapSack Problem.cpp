/*
 * Input: The weights of the knapsack and a list of weights and values for objects
 * Output: The maximum value that we can obtain by putting objects into the knapsack
 * Complexity: O(n*w), where n = nr_objects, w = max(weights)
 */

#include <fstream>
#include <algorithm>

using namespace std;

int const maxWeight = 1e4+5;
int const maxPrice = 5e3+5;

int weight[maxWeight], price[maxPrice];

int dynamic[2][maxWeight];

int totalObjects, limitWeight;

ifstream fin("rucsac.in");
ofstream fout("rucsac.out");

inline void readVariables(){
    fin >> totalObjects >> limitWeight;
    for ( int index = 1; index <= totalObjects; index++ ){
        fin >> weight[index] >> price[index];
    }
}

inline void solveProblems(){
    int line = 0;
    for ( int index = 1; index <= totalObjects; index++, line = !line )
        for ( int currentWeight = 0; currentWeight <= limitWeight; currentWeight++ ){
            dynamic[line][currentWeight] = dynamic[!line][currentWeight];

            if ( currentWeight >= weight[index] ){
                dynamic[line][currentWeight] = max(dynamic[!line][currentWeight-weight[index]]+price[index], dynamic[line][currentWeight]);
            }
        }

    fout << dynamic[1][limitWeight];
}

int main(){
    readVariables();
    solveProblems();
    return 0;
}