/*
 * Input: List of numbers, List of Query
 * Each query is: min(L[x, y])
 * Output: Answers for the queries
 * Complexity: O(n*log(n) + m)
 * Each query is solved in O(1), and the construction of the RMQ is O(n*log(n))
 * Where n = len(L), m = len(Q)
 */

#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 100005;
const int NLen = (int)(log2(N)+1)
int questions, totalNumbers, length[NLen];
int lg2[N];

int *numbers[NLen]  ;

inline void readVariables(){
    freopen("rmq.in", "r", stdin);
    freopen("rmq.out", "w", stdout);
    scanf("%d %d", &totalNumbers, &questions);

    for(int index = 2;index <= totalNumbers;index++){
        lg2[index] = lg2[index >> 1] + 1;
    }

    numbers[0] = new (nothrow) int[totalNumbers+5];
    for ( int index = 1; index <= totalNumbers; index++ )
        scanf("%d", &numbers[0][index]);

    length[0] = totalNumbers;
    for ( int index = 1; index <= lg2[totalNumbers]; index++ ){
        length[index] = length[index-1] - ( 1<<(index-1) );
    }

    for ( int indexY = 1; indexY <= lg2[totalNumbers]; indexY++ ){
        numbers[indexY] = new (nothrow) int[length[indexY]+5];
        for ( int indexX = 1; indexX <= length[indexY]; indexX++ ){
            numbers[indexY][indexX] = min( numbers[indexY-1][indexX], numbers[indexY-1][indexX+(1<<(indexY-1) )] );
        }
    }

    int first, second;
    for ( int indexQuestion = 1; indexQuestion <= questions; indexQuestion++ ){
        scanf("%d %d", &first, &second);
        if ( first > second )
            swap (first, second);
        int lengthPeriod = second - first + 1;
        int indexY = lg2[lengthPeriod];
        printf("%d\n", min ( numbers[indexY][first], numbers[indexY][second-(1<<(indexY))+1] ) );
    }
}

int main(){
    readVariables();
}