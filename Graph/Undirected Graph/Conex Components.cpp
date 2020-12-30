/*
 * Input: The edges of an undirected Graph
 * Output: The number of conex components
 * Complexity: O(n+m), where n = nr_nodes, m = nr_edges
 */

#include <vector>
#include <fstream>

using namespace std;

ifstream f("dfs.in");
ofstream g("dfs.out");

vector<int> nod[100005];
char marcat[100005];
int n,m,componente=0;

void dfs(int poz){

    for(int i=0;i<nod[poz].size();i++){
        if(marcat[nod[poz][i]]==0){
            marcat[nod[poz][i]]=1;
            dfs(nod[poz][i]);
        }
    }
}

int main()
{
    f>>n>>m;
    int nod1,nod2;
    for(int i=1;i<=m;i++)
        f>>nod1>>nod2,nod[nod1].push_back(nod2),nod[nod2].push_back(nod1);
    for(int i=1;i<=n;i++){
        if(marcat[i]==0){
            componente++;
            marcat[i]=1;
            dfs(i);
        }
    }
    g<<componente;
    f.close();
    g.close();
}