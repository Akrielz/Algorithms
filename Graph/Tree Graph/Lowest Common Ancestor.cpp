/*
 * Input: List of parents for nodes, List of Queries
 * Each query is of the form: "Lowest common ancestor for (x, y)"
 * Output LCA(x, y)
 * Complexity: O(nlog(n) + m*log(n))
 */

#include <vector>
#include <bitset>
#include <fstream>

using namespace std;

ifstream fin("lca.in");
ofstream fout("lca.out");

const int N = 1e5 + 1;
const int D = 18;

vector <int> edges[N], eulerChart;

bitset <N> visited;

int totalNodes, totalQuestions, length[D], depth;

int level[N], position[N];

int rangeMinimumQuery[2][D][3*N];

inline void readVariables(){
    fin >> totalNodes >> totalQuestions;

    int origin;
    for ( int index = 2; index <= totalNodes; index++ ){
        fin >> origin;
        edges[origin].push_back(index);
        edges[index].push_back(origin);
    }
}

void DFS(int node = 1){
    visited[node] = true;
    eulerChart.push_back(node);
    position[node] = eulerChart.size();
    for ( auto it : edges[node] ){
        if ( !visited[it] ){
            level[it] = level[node] + 1;
            DFS(it);
            eulerChart.push_back(node);
        }
    }
}

inline void RMQ(){
    length[0] = eulerChart.size();
    depth = (int)(log2(length[0]));

    for ( int index = 1; index <= length[0]; index++ ){
        rangeMinimumQuery[0][0][index] = level[eulerChart[index-1]];
        rangeMinimumQuery[1][0][index] = eulerChart[index-1];
    }

    for ( int index = 1; index <= depth; index++ )
        length[index] = length[index-1] - (1<<(index-1));

    for ( int indexY = 1; indexY <= depth; indexY++ ){
        for ( int indexX = 1; indexX <= length[indexY]; indexX++ ){
            if (rangeMinimumQuery[0][indexY-1][indexX] < rangeMinimumQuery[0][indexY-1][indexX + (1<<(indexY-1))] ){
                rangeMinimumQuery[0][indexY][indexX] = rangeMinimumQuery[0][indexY-1][indexX];
                rangeMinimumQuery[1][indexY][indexX] = rangeMinimumQuery[1][indexY-1][indexX];
            }
            else{
                rangeMinimumQuery[0][indexY][indexX] = rangeMinimumQuery[0][indexY-1][indexX + (1<<(indexY-1))];
                rangeMinimumQuery[1][indexY][indexX] = rangeMinimumQuery[1][indexY-1][indexX + (1<<(indexY-1))];
            }
        }
    }
}

inline void readQuestions(){
    int first, second;
    for ( ; totalQuestions; totalQuestions-- ){
        fin >> first >> second;
        first = position[first];
        second = position[second];
        if ( first > second )
            swap(first, second);
        int lengthPeriod = second - first + 1;
        int maxPeriod = 1 << ( (int) (log2(lengthPeriod)) );
        int indexY = log2(maxPeriod);
        if ( rangeMinimumQuery[0][indexY][first] < rangeMinimumQuery[0][indexY][second-(1<<indexY)+1] )
            fout << rangeMinimumQuery[1][indexY][first] << "\n";
        else
            fout << rangeMinimumQuery[1][indexY][second-(1<<indexY)+1] << "\n";
    }
}

int main(){
    readVariables();
    DFS();
    RMQ();
    readQuestions();
}