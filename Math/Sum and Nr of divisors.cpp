/*
 * Input: List of queries
 * Each query: Sum and nr of divisors
 * Output: Answers
 * Complexity: sqrt(n) where n is the queried number
 */

#include <fstream>
#include <bitset>
#include <vector>

using namespace std;

ifstream fin ("ssnd.in");
ofstream fout ("ssnd.out");

const int N = 1e6+1;
const int modulo = 9973;

bitset <N> prime;

vector <int> primeNumbers;

long long int totalTests, number, contor, sum, coefficient, totalSum, totalContor;

void ciur(){
    prime.set();
    for ( int index = 2; index < N; index++ ){
        if (prime[index]){
            primeNumbers.push_back(index);
            for ( int multiple = index; multiple < N; multiple += index )
                prime[multiple] = false;
        }
    }
}

int main(){
    ciur();
    fin >> totalTests;
    for ( ; totalTests; totalTests-- ){
        fin >> number;
        totalContor = totalSum = 1;
        for ( auto it : primeNumbers ){
            if ( it*it > number )
                break;
            if ( number % it )
                continue;

            coefficient = it;
            sum = contor = 1;
            for ( ; number % it == 0; ){
                contor++;
                sum += coefficient;
                number /= it;
                coefficient = (coefficient*it)%modulo;
            }
            totalSum = (1LL*sum*totalSum)%modulo;
            totalContor *= contor;
        }

        if ( number > 1 ){
            sum = number%modulo + 1;
            totalContor *= 2;
            totalSum = (totalSum*sum) % modulo;
        }

        fout << totalContor << " " << totalSum << "\n";
    }
}