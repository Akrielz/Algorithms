/*
 * Input: The edges of a directed graph
 * Output: The nodes that form each strongly connected components
 * Complexity: O(n + m) where n = len(nodes), m = len(edges)
 */

#include <fstream>
#include <stack>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

ifstream fin("ctc.in");
ofstream fout("ctc.out");

const int N = 100005;

vector <int> edges[N], solution[N];

bitset <N> inStack;

stack <int> Stack;

int totalNodes, contor, components;

int entryNode[N],
        codeNode[N];

inline void readVariables();
inline void solveproblem();
inline void DFS(int);
inline void printSolutions();

int main(){
    readVariables();
    solveproblem();
}

inline void readVariables(){
    int totalEdges;
    fin >> totalNodes >> totalEdges;
    for ( int origin, destination; totalEdges; totalEdges-- ){
        fin >> origin >> destination;
        edges[origin].push_back(destination);
    }
}

inline void solveproblem(){
    for ( int index = 1 ; index <= totalNodes; index++ ){
        if ( !codeNode[index])
            DFS(index);
    }
    printSolutions();
}

inline void DFS(int node){
    contor ++;
    entryNode[node] = codeNode[node] = contor;
    Stack.push(node);
    inStack[node] = true;
    for ( auto it : edges[node] ){
        if ( !codeNode[it] ){
            DFS(it);
            entryNode[node] = min(entryNode[node], entryNode[it]);
        }
        else{
            if ( inStack[it] )
                entryNode[node] = min(entryNode[node], entryNode[it]);
        }
    }

    if ( entryNode[node] == codeNode[node] ){
        components++;
        for ( int currentNode; ; ){
            currentNode = Stack.top();
            solution[components].push_back(currentNode);
            inStack[currentNode] = false;
            Stack.pop();
            if (currentNode == node)
                break;
        }
    }
}

inline void printSolutions(){
    fout << components << "\n";
    for ( int index = 1; index <= components; index++ ){
        for ( auto it : solution[index] ){
            fout << it << " ";
        }
        fout << "\n";
    }
}