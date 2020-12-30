/*
 * Input K = range of sequence, A list of numbers
 * Output: Sum(min(L[i:i+k]) for i in [0, n-k-1])
 * Complexity: O(n)
 */

#include <fstream>
#include <deque>

#define value first
#define position second

using namespace std;

ifstream fin("deque.in");
ofstream fout("deque.out");

int totalNumbers, sequence;
deque <pair <int, int> > Deque;

long long int sum;

int main(){
    fin >> totalNumbers >> sequence;

    for ( int index = 1, aux; index < sequence; index++){
        fin >> aux;
        for ( ; Deque.size() and aux <= Deque.back().value; ){
            Deque.pop_back();
        }
        Deque.push_back({aux, index});
    }

    for ( int index = sequence, aux; index <= totalNumbers; index++){
        fin >> aux;
        for ( ; Deque.size() and aux <= Deque.back().value; ){
            Deque.pop_back();
        }
        Deque.push_back({aux, index});
        if ( Deque.front().position == index - sequence)
            Deque.pop_front();

        sum += Deque.front().value;
    }
    fout << sum;
}