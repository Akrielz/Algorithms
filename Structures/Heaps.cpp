/*
 * Input: List of Queries
 * Queries:
 *  1 x -> upHeap(x)
 *  2 x -> downHeap(L[x])
 *  3 -> min(heap) (aka heap[1])
 * Output: Answers
 * Complexity:
 *  Whole: O(m*log(n)) where n = len(numbers), m = len(queries)
 *  Query: O(log(n))
 * Side Note: This is min heap
 */

#include <algorithm>
#include <fstream>

using namespace std;

ifstream fin ("heapuri.in");
ofstream fout ("heapuri.out");

const int N = 200005;

int length, totalNumbers, totalOperations, number;

int numbers[N], heap[N], position[N];

void push(int index){
    for ( ; index>>1 and numbers[heap[index]] < numbers[heap[index/2]]; index>>=1 ){
        swap(heap[index], heap[index/2]);

        position[heap[index]] = index;
        position[heap[index/2]] = index/2;
    }
}

void pop(int index){
    int son = 0;
    while ( son != index ){
        son = index;

        if ( son*2 <= length and numbers[heap[index]] > numbers[heap[son*2]])
            index = son*2;

        if ( son*2+1 <= length and numbers[heap[index]] > numbers[heap[son*2+1]] )
            index = son*2+1;

        swap(heap[index], heap[son]);

        position[heap[index]] = index;
        position[heap[son]] = son;
    }
}

int main(){
    fin >> totalOperations;
    for ( int operation; totalOperations; totalOperations-- ){
        fin >> operation;
        switch(operation){
            case 1:
                fin >> number;

                length++, totalNumbers++;

                numbers[totalNumbers] = number;
                heap[length] = totalNumbers;
                position[totalNumbers] = length;

                push(length);
                break;

            case 2:
                fin >> number;

                numbers[number] = -1;
                push(position[number]);

                position[heap[1]] = 0;
                heap[1] = heap[length];
                length--;
                position[heap[1]] = 1;
                if ( length > 1 )
                    pop(1);

                break;

            case 3:
                fout << numbers[heap[1]] << "\n";
                break;
        }
    }
}