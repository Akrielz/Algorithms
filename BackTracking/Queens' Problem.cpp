/*
 * Input: Nr of queens
 * Output: A valid configuration + nr of all the valid configurations
 * Complexity: O(k^n), where n = len(queens), k = constant
 */

#include <fstream>

using namespace std;

int length;
int answers;

const int MAX_QUEENS = 13;

bool columns[MAX_QUEENS];
bool mainDiagonals[MAX_QUEENS*2-1];
bool secondaryDiagonals[MAX_QUEENS*2-1];

int coordonates[MAX_QUEENS];

ifstream fin("damesah.in");
ofstream fout("damesah.out");

bool isValid(int line, int column){

    if (columns[column])
        return false;

    if (mainDiagonals[line-column+length-1])
        return false;

    if (secondaryDiagonals[line+column])
        return false;

    return true;
}

void generateSolutions(int line = 0){
    if (line == length){
        if (not answers)
            for (int line = 0; line < length; line++)
                fout << coordonates[line]+1 << " ";
        answers++;
        return;
    }

    for (int column = 0; column < length; column++){

        if (isValid(line, column)){
            coordonates[line] = column;

            columns[column] = true;
            mainDiagonals[line-column+length-1] = true;
            secondaryDiagonals[line+column] = true;

            generateSolutions(line+1);

            columns[column] = false;
            mainDiagonals[line-column+length-1] = false;
            secondaryDiagonals[line+column] = false;
        }
    }
}

int main(){
    fin >> length;
    generateSolutions();
    fout << "\n" << answers;
}