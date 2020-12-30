/*
 * Input: A list of numbers
 * Output: Longest rising subsequence
 * Complexity: O(n*log(n)), where n = len(numbers)
 */

#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream f("scmax.in");
ofstream g("scmax.out");

const int N = 100005;
const int oo=numeric_limits<int>::max();
const pair <int, int> INF = make_pair(oo,oo);

int n, v[N], B[N], L;
vector <pair <int, int> > C( N, INF);
void printSolution(int D){
    if (D == 0)
        return;
    printSolution(B[D]);
    g << v[D] << " ";
}

int main()
{
    f >> n;
    for ( int i = 1; i <= n; i++ )
        f >> v[i];

    vector <pair< int, int> > :: iterator it;
    C[0]=make_pair(0,0);
    for ( int i = 1; i <= n; i++ ){
        it = lower_bound(C.begin(), C.end(), make_pair(v[i],0));
        if(it->first==oo)
            L++;
        *it=make_pair(v[i],i);
        it--;
        B[i]=it->second;
    }
    g << L << "\n";
    printSolution(C[L].second);
}