/*
 * Input: queries with strings
 * Queries:
 *  0 w - add w in list
 *  1 w - delete w from list
 *  2 w - frequency[w]
 *  3 w - Longest common prefix with any other word
 * Output: Answers for the queries
 * Complexity: O(Sigma * |w|) for each query, where Sigma=26
 * Note: Can be improved to O(|w|) if the tree recalls only used 'sons'
 */

#include <string>
#include <fstream>

#define letter word[index] - 'a'

using namespace std;

const int sigma = 26;

struct Trie{
public:
    int usedTimes,
            finished;
    Trie *child[sigma];

    Trie (){
        usedTimes = 0;
        finished = 0;
        for (auto & index : this->child)
            index = NULL;
    }

    inline void insertWord(string word);
    inline void deleteWord(string word);
    inline int spottedWords(string word);
    inline int prefixLength(string word);

private:
    inline void deleteBranch(Trie *Position){
        for (auto & index : Position->child)
            if ( index ){
                deleteBranch(index);
            }
        delete Position;
    }
};

Trie *Root = new Trie;

inline void Trie :: insertWord(string word){
    Root->usedTimes++;

    Trie *Position;
    Position = Root;

    for ( int index = 0; index < word.length(); index++ ){
        if ( Position->child[letter] == nullptr ){
            Position->child[letter] = new Trie;
        }

        if ( Position->child[letter] != nullptr ){
            Position = Position->child[letter];
            Position->usedTimes++;
        }

        if ( index == word.length()-1 )
            Position->finished++;
    }
}

inline void Trie :: deleteWord(string word){
    Root->usedTimes--;

    Trie *Position, *Next;
    Position = Root;

    for ( int index = 0; index < word.length(); index++ ){
        Next = Position->child[letter];
        Next->usedTimes--;

        if ( Next->usedTimes == 0 ){
            Root->deleteBranch(Next);
            Position->child[letter] = nullptr;
            break;
        }

        if ( index == word.length()-1 ){
            Next->finished--;
        }

        Position = Next;
    }
}

inline int Trie :: spottedWords(string word){
    Trie *Position;
    Position = Root;

    for ( int index = 0; index < word.length(); index++ ){
        if ( Position->child[letter] != nullptr )
            Position = Position->child[letter];
        else
            return 0;
    }

    return Position->finished;
}

inline int Trie :: prefixLength(string word){
    Trie *Position;
    Position = Root;
    int length = 0;

    for ( int index = 0; index < word.length(); index++ ){
        if ( Position->child[letter] != NULL ){
            Position = Position->child[letter];
            length++;
        }
        else
            break;
    }

    return length;
}

struct System{
    System(){
        int operation;
        string word;
        ifstream fin("trie.in");
        ofstream fout("trie.out");

        for ( ;fin >> operation >> word; ){
            switch(operation){
                case 0:
                    Root->insertWord(word);
                    break;

                case 1:
                    Root->deleteWord(word);
                    break;

                case 2:
                    fout << Root->spottedWords(word) << "\n";
                    break;

                case 3:
                    fout << Root->prefixLength(word) << "\n";
                    break;
            }
        }
    }
};

int main(){
    System Solved;
}