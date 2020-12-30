/*
 * Input: A list with the edges of the tree
 * Output: Tree's diameter
 * Complexity: O(n), where n = len(nodes)
 */

#include <vector>
#include <queue>
#include <memory>
#include <fstream>

using namespace std;

ifstream fin ("darb.in");
ofstream fout ("darb.out");

const int N = 1e5+1;

vector <int> edges[N];

queue <int> Queue;

bool visited[N];

int distances[N];

int totalNodes, diameter, maxPosition;

inline void readVariables(void){
    fin >> totalNodes;
    for ( int origin, destination; fin >> origin >> destination; ){
        edges[origin].push_back(destination);
        edges[destination].push_back(origin);
    }
}

int BFS(int node){
    memset(visited, 0, totalNodes);
    Queue.push(node);
    visited[node] = true;
    distances[node] = 1;
    maxPosition = node;
    diameter = 1;
    for ( int currentNode; Queue.size(); ){
        currentNode = Queue.front();
        Queue.pop();
        for ( auto it : edges[currentNode] ){
            if ( !visited[it] ){
                distances[it] = distances[currentNode] + 1;
                visited[it] = true;
                if ( distances[it] > diameter ){
                    maxPosition = it;
                    diameter = distances[it];
                }
                Queue.push(it);
            }
        }
    }
    return maxPosition;
}

int main(){
    readVariables();
    int first = BFS(1);
    int second = BFS(first);
    fout << diameter;
}