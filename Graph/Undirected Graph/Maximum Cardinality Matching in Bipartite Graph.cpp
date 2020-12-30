/*
 * Input: Edges from a bipartide undirected graph
 * Output: The edges that produces the maximum cardinality matching
 * Complexity: O(sqrt(n)*m), where n = nr_nodes, m = nr_edges
 */

#include <vector>
#include <bitset>
#include <fstream>

#define debug(x)   	 cerr << #x": " << x
#define debugln(x) 	 cerr << #x": " << x << "\n"
#define all(arr)     arr.begin(), arr.end()

using namespace std;

int leftSize = 0;
int rightSize = 0;

const int N_MAX = 1e4+5;

int leftNode[N_MAX];
int rightNode[N_MAX];

int nrEdges;

vector <int> edges[N_MAX];

ifstream fin("cuplaj.in");
ofstream fout("cuplaj.out");

bitset <N_MAX> visited;

bool increment(int left){
    if (visited[left])
        return false;

    visited[left] = true;

    for (auto right : edges[left]){
        if (leftNode[right] == 0){
            leftNode[right] = left;
            rightNode[left] = right;

            return true;
        }
    }

    for (auto right : edges[left]){
        if (increment(leftNode[right])){
            leftNode[right] = left;
            rightNode[left] = right;

            return true;
        }

    }

    return false;
}

int contor;

bool checkCompatibility(){
    for (int left = 1; left <= leftSize; left++){
        visited[left] = false;
    }

    bool gotBetter = false;
    for (int left = 1; left <= leftSize; left++){
        if (rightNode[left] == 0 and increment(left)){
            gotBetter = true;
            contor ++;
        }
    }

    return gotBetter;
}

int main() {
    fin >> leftSize >> rightSize >> nrEdges;

    for (; nrEdges; nrEdges--){
        int left, right;
        fin >> left >> right;
        edges[left].push_back(right);
        //edges[right].push_back(left);
    }

    while (checkCompatibility());

    fout << contor << "\n";

    for (int left = 1; left <= leftSize; left++){
        if (rightNode[left]){
            fout << left << " " << rightNode[left] << "\n";
        }
    }
}