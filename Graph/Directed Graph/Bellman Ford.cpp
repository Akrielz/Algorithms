/*
 * Input: The edges with costs from a directed graph
 * Output: Shortest distance from node 1 to each node, or detects if there is a negative cycle
 * Complexity: O(m*log(n)), where n = nr_nodes, m = nr_edges
 * Side Note: Works on negative numbers
 */

#include <fstream>
#include <queue>
#include <vector>
#include <bitset>

using namespace std;

ifstream fin("bellmanford.in");
ofstream fout("bellmanford.out");

int const N {50005};
int const INF {1<<30};

vector <pair <int, int> > nodes[N]; // {destination, cost}

queue <int> Queue; // {node}

bitset <N> inQueue;

int totalNodes;

int distances[N], entrances[N];

inline void readVariables(){
    int totalEdges;
    fin >> totalNodes >> totalEdges;

    int origin, destination, cost;
    for ( ; totalEdges; totalEdges-- ){
        fin >> origin >> destination >> cost;
        nodes[origin].push_back(make_pair(destination, cost));
    }
}

inline void bellmanFord(int startNode = 1){
    Queue.push(startNode);
    distances[startNode] = 0;
    inQueue[startNode] = 1;
    for ( int index = 2; index <= totalNodes; index++ )
        distances[index] = INF;

    int currentNode;
    for ( ; Queue.size(); ){
        currentNode = Queue.front();

        for ( auto it : nodes[currentNode] ){
            if ( distances[currentNode] + it.second < distances[it.first] ){
                if ( !inQueue[it.first] ){
                    inQueue[it.first] = 1;
                    entrances[it.first] ++;
                    if ( entrances[it.first] == totalNodes ){
                        fout << "Ciclu negativ!";
                        return;
                    }
                    Queue.push(it.first);
                }
                distances[it.first] = distances[currentNode] + it.second;
            }
        }
        inQueue[currentNode] = 0;
        Queue.pop();
    }
    for ( int index = 2; index <= totalNodes; index++ ){
        fout << distances[index] << " ";
    }
}

int main(){
    readVariables();
    bellmanFord();
}