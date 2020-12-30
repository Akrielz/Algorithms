/*
 * Solves the minimum distance between all nodes from a directed graph
 * Input: matrix a, where a[i][j] = cost from i to j
 * Output: matrix b where b[i][j] = lowest cost from i to j
 * Complexity: O(n^3), where n = nr_nodes
 */

#include <fstream>

#define N 105

using namespace std;

ifstream fin ("royfloyd.in");
ofstream fout ("royfloyd.out");

int totalNodes;

int nodes[N][N];

inline void readVaraibles(){
    fin >> totalNodes;
    for ( int indexY = 1; indexY <= totalNodes; indexY++ )
        for ( int indexX = 1; indexX <= totalNodes; indexX++ )
            fin >> nodes[indexY][indexX];
}

inline void royFloyd(){
    for ( int indexK = 1; indexK <= totalNodes; indexK++ )
        for ( int indexY = 1; indexY <= totalNodes; indexY++ )
            for ( int indexX = 1; indexX <= totalNodes; indexX++ )
                if ( nodes[indexY][indexK] and nodes[indexK][indexX] )
                    if ( nodes[indexY][indexX] > nodes[indexY][indexK] + nodes[indexK][indexX] or !nodes[indexY][indexX])
                        if ( indexX != indexY )
                            nodes[indexY][indexX] = nodes[indexY][indexK] + nodes[indexK][indexX];
}

inline void printSolution(){
    for ( int indexY = 1; indexY <= totalNodes; indexY++ ){
        for ( int indexX = 1; indexX <= totalNodes; indexX++ )
            fout << nodes[indexY][indexX] << " ";
        fout << "\n";
    }
}

int main(){
    readVaraibles();
    royFloyd();
    printSolution();
}