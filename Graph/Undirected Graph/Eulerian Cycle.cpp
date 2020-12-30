/*
 * Input: The edges of an undirected graph
 * Output: An Eulerian Cicle
 * Complexity: O(n+m), where n = len(nodes), m = len(edges)
 */

#include <vector>
#include <fstream>
#include <bitset>
#include <stack>
#include <tuple>

using namespace std;

ifstream fin ("ciclueuler.in");
ofstream fout ("ciclueuler.out");

const int N = 1e5+5;
const int M = 5*N;

int totalNodes, totalEdges;

vector <pair <int, int> > edges[M];

vector <int> solutions;

bitset <M> visited;

stack <int> myStack;

inline void readVariables(){
    fin >> totalNodes >> totalEdges;
    int origin, destination;
    for ( int index = 1; index <= totalEdges; index++ ){
        fin >> origin >> destination;
        edges[origin].push_back({destination, index});
        edges[destination].push_back({origin, index});
    }
}

bool checkCompatibility(){
    for ( int index = 1; index <= totalNodes; index++ )
        if ( edges[index].size() % 2 )
            return false;

    return true;
}

inline void determinatingEuler(){
    myStack.push(1);

    for ( int currentNode, destination, edge; myStack.size(); ){
        currentNode = myStack.top();
        if ( edges[currentNode].empty() ){
            solutions.push_back(currentNode);
            myStack.pop();
        }
        else{
            tie(destination, edge) = edges[currentNode].back();
            edges[currentNode].pop_back();
            if ( !visited[edge] ){
                visited[edge] = true;
                myStack.push(destination);
            }
        }
    }
}

inline void printSolution(){
    for ( auto it : solutions )
        fout << it << " ";
}

int main(){
    readVariables();
    if ( !checkCompatibility() ){
        fout << -1;
        return 0;
    }
    determinatingEuler();
    printSolution();
    return 0;
}