/*
 * Input: k
 * Output: fib[k]
 * Complexity: O(log(k))
 */

#include <fstream>
#include <iostream>

using namespace std;

ifstream fin("kfib.in");
ofstream fout("kfib.out");

const int modulo = 666013;

class matrix{
private:
    long long a[3][3];
public:
    matrix(){};
    matrix(long long B[2][2]){
        for ( int indexY = 1; indexY <= 2; indexY++ )
            for ( int indexX = 1; indexX <= 2; indexX++ )
                a[indexY][indexX] = B[indexY-1][indexX-1];
    }

    matrix operator*(matrix B){
        matrix C;
        C.a[1][1] = (a[1][1]*B.a[1][1] + a[1][2]*B.a[2][1])%modulo;
        C.a[1][2] = (a[1][1]*B.a[1][2] + a[1][2]*B.a[2][2])%modulo;
        C.a[2][1] = (a[2][1]*B.a[1][1] + a[2][2]*B.a[2][1])%modulo;
        C.a[2][2] = (a[2][1]*B.a[1][2] + a[2][2]*B.a[2][2])%modulo;
        return C;
    }

    int getValue(int y, int x){
        return a[y][x];
    }

    void printMatrix(){
        for ( int indexY = 1; indexY <= 2; indexY++ ){
            for ( int indexX = 1; indexX <= 2; indexX++ )
                cout << a[indexY][indexX] << " ";
            cout << "\n";
        }
    }
};

int nthPosition;

long long APrim[2][2] = { { 0, 1 },
                          { 1, 1 } };

long long BPrim[2][2] = { { 1, 0 },
                          { 0, 1 } };

matrix A (APrim);

matrix B (BPrim);

int main(){
    fin >> nthPosition;
    for ( ; nthPosition; nthPosition >>= 1 ){
        if ( nthPosition%2 )
            B = B*A;
        A = A*A;
    }
    fout << B.getValue(1, 2);
}