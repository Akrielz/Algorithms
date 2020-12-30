/*
 * Input: An oriented graph represented by its edges
 * Output: A topological sort
 * Complexity: O(n+m) where n = nr_nodes and m = nr_edges
 */

#include <iostream>
#include <fstream>

#define N 50010

using namespace std;

ifstream f ("sortaret.in");
ofstream g ("sortaret.out");

struct node
{
    int info;
    node *next;
};

node *root[N], *top[N];

int totalNodes;

int grade[N], Queue[N];

void nodePushBack(int origin, int destination)
{
    node *aux = new node;
    aux -> info = destination;
    if ( root[origin] )
    {
        top[origin] -> next = aux;
        top[origin] = aux;
    }
    else
    {
        root[origin] = top[origin] = aux;
    }
    top[origin] -> next = NULL;
}

inline void readVariables()
{
    int totalEdges;
    f >> totalNodes >> totalEdges;

    int origin, destination;
    for ( ; totalEdges ; totalEdges-- )
    {
        f >> origin >> destination;
        nodePushBack(origin, destination);
        grade[destination]++;
    }
}

inline void topologicSort(void)
{
    for ( int indexNode = 1; indexNode <= totalNodes; indexNode++ )
        if ( grade[indexNode] == 0 )
        {
            Queue[++Queue[0]] = indexNode;
        }

    for ( int indexNode = 1, currentNode; indexNode <= totalNodes; indexNode++ )
    {
        currentNode = Queue[indexNode];
        for ( node *it = root[currentNode]; it; it = it->next )
        {
            grade[it->info]--;
            if ( grade[it->info] == 0 )
                Queue[++Queue[0]] = it->info;
        }
    }
}

inline void displaySolution(void)
{
    for ( int indexNode = 1; indexNode <= totalNodes; indexNode++ )
        g << Queue[indexNode] << " ";
}

int main()
{
    readVariables();
    topologicSort();
    displaySolution();
}