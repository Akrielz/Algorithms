/*
 * Input: list of Numbers, list of Queries
 * Possible Queries:
 * 0 a b -> L[a] += b
 * 1 a b -> sum(L[a, b])
 * 2 a -> k pos such that sum(L[:k]) = a
 *
 * Output: The answer for the queries
 *
 * Complexity:
 *  Q[0] -> O(log(n),
 *  Q[1] -> O(log(n),
 *  Q[2] -> O(log(n)^2)
 *  Binary Indexed Tree construction -> O(n*log(n))
 */

#include <fstream>

using namespace std;

ifstream fin("aib.in");
ofstream fout("aib.out");

const int N = 100005;

int binaryArbore[N],
        totalNumbers, totalOperations,
        middle, low, high;

void update(int position, int value){
    for ( ;position <= totalNumbers; position+=position&(-position) )
        binaryArbore[position] += value;
}

int query(int position){
    int sum = 0;
    for (; position; position-=position&(-position) )
        sum += binaryArbore[position];
    return sum;
}

int main(){
    fin >> totalNumbers >> totalOperations;

    int number;
    for ( int index = 1; index <= totalNumbers; index++ ){
        fin >> number;
        update(index, number);
    }

    int first, second;
    for ( int operation; totalOperations; totalOperations-- ){
        fin >> operation;
        switch(operation){
            case 0:
                fin >> first >> second;
                update(first, second);
                break;
            case 1:
                fin >> first >> second;
                fout << query(second) - query(first-1) << "\n";
                break;
            case 2:
                fin >> first;
                for ( low = 0, high = totalNumbers; high-low-1; ){
                    middle = (low + high) /2;
                    if ( query(middle) < first )
                        low = middle;
                    else
                        high = middle;
                }
                if ( query(high) == first )
                    fout << high << "\n";
                else
                    fout << "-1\n";
                break;
        }
    }
    return 0;
}
