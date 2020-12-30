/*
 * Input: A list of numbers
 * Output: The sorted list
 * Complexity: O(n*log(n)), where n = len(List)
 */

#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin ("algsort.in");
ofstream fout ("algsort.out");

const int maxNumbers = 5e5+5;

int totalNumbers;

int heap[maxNumbers];

void upHeap(int position){
    if ( position == 1 )
        return;

    if ( heap[position] > heap[position/2] ){
        swap(heap[position], heap[position/2]);
        upHeap(position/2);
    }
}

void downHeap(int position, int contor){
    int left = position*2;
    int right = position*2+1;
    int largest = position;

    if ( left <= contor and heap[left] > heap[largest] )
        largest = left;

    if ( right <= contor and heap[right] > heap[largest] )
        largest = right;

    if ( largest != position ){
        swap(heap[largest], heap[position]);
        downHeap(largest, contor);
    }
}

inline void readVariables(){
    fin >> totalNumbers;
    for ( int index = 1; index <= totalNumbers; index++ ){
        fin >> heap[index];
        upHeap(index);
    }
}

void sortHeap(){
    for ( int index = totalNumbers; index >= 1; index-- ){
        swap(heap[1], heap[index]);
        downHeap(1, index-1);
    }
}

inline void printHeap(){
    for ( int index = 1; index <= totalNumbers; index++ )
        fout << heap[index] << " ";
}

int main(){
    readVariables();
    sortHeap();
    printHeap();
    return 0;
}