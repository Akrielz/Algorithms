#include <fstream>

using namespace std;

ifstream fin ("ssm.in");
ofstream fout ("ssm.out");

const int N = 6000005;

int numbers[N], totalNumbers;

int main(){
    fin >> totalNumbers;
    for ( int index = 1; index <= totalNumbers; index++ )
        fin >> numbers[index];

    int bestSum = (1<<30)*(-1), sum = 0, begining, ending, mark = 1;
    for ( int index = 1; index <= totalNumbers; index++ ){
        if ( sum < 0 ){
            sum = numbers[index];
            mark = index;
        }
        else
            sum += numbers[index];
        if ( bestSum < sum ){
            bestSum = sum;
            begining = mark;
            ending = index;
        }
    }
    fout << bestSum << " " << begining << " " << ending;
}