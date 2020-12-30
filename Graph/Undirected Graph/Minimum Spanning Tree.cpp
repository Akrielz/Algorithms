/*
 * Input: The edges of an undirected graph, with costs on them
 * Output: Minimum Spanning Tree
 * Complexity: O(m*log(m) + m)
 */

#include <fstream>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;

ifstream fin("apm.in");
ofstream fout("apm.out");

const int N = 200010;
const int M = 400010;

tuple <int, int, int> edges[M];

vector <pair <int, int> > solutions;

int root[N], totalNodes, totalEdges, totalCost;

inline void readVariables();
inline void solveProblem();
int getRoot(int);
inline void printSolution();

int main()
{
    readVariables();
    solveProblem();
    printSolution();
    return 0;
}

inline void readVariables(){
    fin >> totalNodes >> totalEdges;
    for ( int origin, destination, index=1, cost; index <= totalEdges; index++ ){
        fin >> origin >> destination >> cost;
        edges[index] = make_tuple(cost, origin, destination);
    }
    sort(edges+1, edges+totalEdges+1);
}

int getRoot(int node){
    if ( root[node] == node)
        return node;
    root[node] = getRoot(root[node]);
    return root[node];
}

inline void solveProblem(){
    for ( int index = 1; index <= totalNodes; index++ )
        root[index] = index;

    for ( int index = 1; index <= totalEdges; index++ ){
        int origin, destination, cost;
        tie(cost ,origin, destination ) = edges[index];
        int rootOrigin = getRoot(origin),
                rootDestination = getRoot(destination);

        if ( rootOrigin != rootDestination ){
            totalCost += cost;
            solutions.push_back({origin, destination});
            root[rootOrigin] = rootDestination;
        }
    }
}

void printSolution(){
    fout << totalCost << "\n" << solutions.size() << "\n";
    for ( auto it : solutions )
        fout << it.first << " " << it.second << "\n";
}