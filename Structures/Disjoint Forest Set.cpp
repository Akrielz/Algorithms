/*
 * Input: N Sets and Q Queries
 * Queries:
 *  1 a b -> unite set(a) and set(b)
 *  2 a b -> tells if set(a) and set(b) are disjoint or not
 * Output: Answer to the queries
 * Complexity: O(1) for Q[1] and O(log(n)) for Q[2] where n = len(set(a) | set(b))
 */

#include <fstream>

#define N 100010

using namespace std;

ifstream fin("disjoint.in");
ofstream fout("disjoint.out");

int root[N];

int totalNodes, totalRelations;

int getRoot(int node){
    if ( root[node] != node ){
        root[node] = getRoot(root[node]);
    }
    return root[node];
}

inline void connectThings(int first, int second){
    first = getRoot(first);
    second = getRoot(second);
    root[first] = root[second];
}

inline void doesItExist(int first, int second){
    first = getRoot(first);
    second = getRoot(second);
    if ( first == second )
        fout << "DA" << "\n";
    else
        fout << "NU" << "\n";
}

int main(){
    fin >> totalNodes >> totalRelations;

    for ( int index = 1; index <= totalNodes; index++ )
        root[index] = index;

    int first, second, question;
    for ( int index = 1; index <= totalRelations; index++ ){
        fin >> question >> first >> second;
        switch (question){
            case 1:
                connectThings(first, second);
                break;
            case 2:
                doesItExist(first, second);
                break;
        }
    }
}