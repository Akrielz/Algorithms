/*
 * Input: Pattern(P) and a String(S)
 * Output: All the positions where the pattern matches the substring
 * Complexity: O(|P| + |S|)
 */

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

const int N = 2000005;

ifstream fin ("strmatch.in");
ofstream fout ("strmatch.out");

string patern, text, b = " ";

int prefix[N], potriviri;

vector <int> Sol;

int main() {
    fin >> patern >> text;
    int p = patern.size();
    int t = text.size();

    patern = b + patern;
    text = b + text;
    int q = 0;

    for ( int i = 2 ; i <= p; i++ ) {
        while ( q and patern[i] != patern[q+1] )
            q = prefix[q];
        if ( patern[i] == patern[q+1] )
            q++;
        prefix[i] = q;
    }

    q=0;
    for ( int i = 1 ; i <= t; i++ ) {
        while ( q and text[i] != patern[q+1] )
            q = prefix[q];
        if ( text[i] == patern[q+1] )
            q++;
        if ( q == p ) {
            potriviri++;
            if ( potriviri <= 1000 )
                Sol.push_back(i-p);
        }
    }
    fout << potriviri << "\n";
    for ( auto it : Sol ) {
        fout << it << " ";
    }
    return 0;
}