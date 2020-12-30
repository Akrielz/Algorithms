/*
 * Solves: given a list of numbers and a list of queries, constructs a tree that splits the list on intervals,
 * making every query to be done in O(log(n))
 * Input: List of Number, List of Queries
 * Output: Answer for the Queries
 * Possible Queries:
 * 0 a b -> requests max from L[a, b]
 * 1 a b -> L[a] = b
 * Complexity: O(n + m*log(n)) aka O(n) construction, O(log(n) query, and m = nr_queries
 */

#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin ("arbint.in");
ofstream fout ("arbint.out");

const int N = 100005;

int A[4*N];

int totalNumbers, totalQuestions, zero, low, high;

int getMax(int nod = 1, int left = 1, int right = zero+1);

int main()
{
    fin >> totalNumbers >> totalQuestions;
    for ( zero = 1; zero <= totalNumbers; zero<<=1 );
    zero--;
    for ( int index = 1; index <= totalNumbers; index++){
        fin >> A[zero+index];
    }
    for ( int index = zero; index; index-- ){
        A[index] = max(A[2*index], A[2*index+1]);
    }

    for ( int question; totalQuestions; totalQuestions-- ){
        fin >> question >> low >> high;
        if ( question == 0 ){
            fout << getMax () << "\n";
        }
        else{
            A[low+zero] = high;
            for ( int index = (low+zero)/2; index; index>>=1 )
                A[index] = max(A[2*index], A[2*index+1]);
        }
    }
    return 0;
}

int getMax(int nod, int left, int right){
    if ( low <= left and right <= high )
        return A[nod];
    if ( low > right or left > high )
        return 0;
    int middle = (right + left) / 2;
    return max ( getMax( 2*nod, left, middle), getMax( 2*nod+1, middle+1, right ));
}