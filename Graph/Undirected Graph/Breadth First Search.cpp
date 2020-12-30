/*
 * Input: The edges of a undirected graph, and a start node
 * Output: The distances to all the nodes
 * Complexity: O(n+m), where n = nr_nodes, m = nr_edges
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

#define N 100005

using namespace std;

ifstream f ("bfs.in");
ofstream g ("bfs.out");

struct  node
{
    int info;
    node *next;
};

node *root[N], *top[N];

int totalNodes, totalEdges, target;
vector <int> distances(N, -1);

inline void node_push(int index, int value)
{
    node *aux = new node;
    aux -> info = value;
    if ( root[index] == NULL )
    {
        root[index] = top[index] = aux;
        root[index] -> next = NULL;
    }
    else
    {
        top[index] -> next = aux;
        top[index] = aux;
        top[index] -> next = NULL;
    }
}

inline void readVariablesAndInitialize()
{
    f >> totalNodes >> totalEdges >> target;
    int x, y;
    for ( ; totalEdges ; totalEdges-- )
    {
        f >> x >> y;
        node_push(x, y);
    }
}

inline void breadthFirst()
{
    vector <bool> visited (totalNodes, false);
    queue <int> Queue;
    int actualNode;
    int totalMoves;
    distances[target] = 0;
    Queue.push(target);
    while ( !Queue.empty() )
    {
        actualNode = Queue.front();
        totalMoves = distances[actualNode];
        Queue.pop();

        for ( node *it = root[actualNode]; it != NULL; it = it -> next )
        {
            if ( distances[it->info] == -1 )
            {
                distances[it->info] = totalMoves + 1;
                Queue.push(it->info);
            }
        }
    }
}

inline void displayAnswers()
{
    for ( int index = 1; index <= totalNodes; index++)
        g << distances[index] <<" ";
}

int main()
{
    readVariablesAndInitialize();
    breadthFirst();
    displayAnswers();
}