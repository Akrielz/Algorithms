/*
 * Input: The edges with costs from a directed graph
 * Output: Shortest distance from node 1 to each node
 * Complexity: O(m*log(n)), where n = nr_nodes, m = nr_edges
 */

#include <fstream>
#include <queue>
#include <tuple>

#define N 50050

using namespace std;

ifstream fin ("dijkstra.in");
ofstream fout ("dijkstra.out");

const int infinite = 10000000000;

struct node{
    int info;
    int cost;
    node *next;
};

node *root[N], *top[N];

void nodePushBack(int origin, int destination, int value){
    node *aux = new node;
    aux->info = destination;
    aux->cost = value;
    if ( root[origin] ){
        top[origin]->next = aux;
    }
    else{
        root[origin] = aux;
    }
    top[origin] = aux;
    top[origin]->next = NULL;
}

priority_queue <pair <int, int> > Queue; // {cost, node}

int totalNodes;

int distances[N];

bool visited[N];

inline void readVariables(void){

    int totalEdges;
    fin >> totalNodes >> totalEdges;
    for ( int origin, destination, cost; totalEdges; totalEdges-- ){

        fin >> origin >> destination >> cost;
        nodePushBack(origin, destination, cost);
    }
}

inline void solveProblem(void){

    for( int index = 2; index <= totalNodes; index++ )
        distances[index] = infinite;
    distances[1] = 0;

    Queue.push({0,1});
    for ( int currentCost, currentNode ; Queue.size(); ){

        tie(currentCost, currentNode) = Queue.top();
        Queue.pop();
        currentCost *= -1;

        if ( visited[currentNode] )
            continue;
        visited[currentNode] = 1;

        for ( node *it = root[currentNode]; it; it = it->next){
            if ( distances[it->info] > currentCost+it->cost ){

                distances[it->info] = currentCost+it->cost;
                Queue.push({-distances[it->info], it->info});
            }
        }
    }
}

inline void printSolution(void){

    for ( int index = 2; index <= totalNodes; index++ )
        fout << ( distances[index] < infinite ? distances[index] : 0 ) << " ";
}

int main(){
    readVariables();
    solveProblem();
    printSolution();
}