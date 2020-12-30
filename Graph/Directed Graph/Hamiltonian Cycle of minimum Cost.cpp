/*
 * Input: The edges of a directed graph with costs
 * Output: Checks if a hamiltonian Cycle exists, and if so, calculates the minimum cost of it
 * Complexity: O(m*2^n) where n = len(nodes), m = len(edges)
 */

#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream fin ("hamilton.in");
ofstream fout ("hamilton.out");

const int N = 20;
const int M = (1<<17)+5;
const int oo = 1e9;

int dynamic[M][N];
vector <int> edges[N];
int cost[N][N];

int totalEdges, totalNodes, mask, start;

inline void readVariables(){
    fin >> totalNodes >> totalEdges;

    for ( int node1 = 0; node1 < totalNodes; node1++ )
        for ( int node2 = 0; node2 < totalNodes; node2++ )
            cost[node1][node2] = oo;

    int origin, destination;
    for ( ; totalEdges; totalEdges-- ){
        fin >> origin >> destination;
        edges[origin].push_back(destination);
        fin >> cost[origin][destination];
    }
    start = totalNodes-1;
    mask = (1<<start)-1;
}

int main(){
    readVariables();
    for ( int bits = 0; bits <= mask; bits++ )
        for ( int node = 0; node < start; node++ )
            dynamic[bits][node] = oo;

    for ( auto it : edges[start] )
        dynamic[1<<it][it] = cost[start][it];

    vector <int> O, D;
    for ( int bits = 1; bits < mask; bits++ ){
        O.resize(0);
        D.resize(0);
        for ( int node = 0, bit = 1; node < start; node++, bit<<=1){
            if ( bit&bits ){
                if ( dynamic[bits][node] < oo )
                    O.push_back(node);
            }
            else
                D.push_back(node);
        }
        for ( auto o : O )
            for ( auto d : D )
            {
                int dbit=bits|(1<<d);
                if ( cost[o][d] + dynamic[bits][o]<dynamic[dbit][d])
                    dynamic[dbit][d]=cost[o][d] + dynamic[bits][o];
            }
    }
    int finalCost = oo;
    for ( int node = 0; node < start; node++ ){
        if ( dynamic[mask][node] < oo )
            if ( cost[node][start] < oo )
                finalCost = min (finalCost, dynamic[mask][node] + cost[node][start]);
    }
    if ( finalCost < oo )
        fout << finalCost;
    else
        fout << "Nu exista solutie";
}