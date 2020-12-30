/*
 * Input: A string(S) and a list of patterns
 * Output: Number of appearances for each pattern
 * Complexity: O(S+sum(p))
 */

#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

const int sigma = 26;

ifstream fin ("ahocorasick.in");
ofstream fout ("ahocorasick.out");

class Trie{
private:
    Trie *child[sigma], *fail;

    vector <int> codeSons;

    static int number;

    int contor = 0,
            nth;

public:

    Trie (){
        contor = 0;
        fail = NULL;
        for ( int index = 0; index < sigma; index++ )
            child[index] = NULL;
        nth = number;
        number++;
    }

    void insertWord(string word);
    void getThrought(string word);
    friend inline void determinateFails();
    friend inline void feedAnswers();
    friend inline void answerQuestions();
};

int Trie :: number = 0;

Trie *dictionary = new Trie;

vector <Trie*> wordEndings;

stack <Trie*> reverseQueue;

void Trie :: insertWord(string word){
    Trie *position = dictionary,
            *next;

    int length = word.size();

    for ( int index = 0; index < length; index++ ){
        int letter = word[index] - 'a';
        next = position->child[letter];

        if ( next == NULL ){
            position->codeSons.push_back(letter);
            next = new Trie;
            position->child[letter] = next;
        }

        position = next;
    }

    wordEndings.push_back(position);
}

inline void determinateFails(){
    queue <Trie*> myQueue;

    dictionary->fail = dictionary;

    for ( auto son : dictionary->codeSons ){
        dictionary->child[son]->fail = dictionary;
        myQueue.push(dictionary->child[son]);
        reverseQueue.push(dictionary->child[son]);
    }

    Trie *position;
    for ( ; myQueue.size(); ){
        position = myQueue.front();
        myQueue.pop();

        for ( auto son : position->codeSons ){
            for ( Trie *possibleFail = position->fail; ; possibleFail = possibleFail->fail ){
                if ( possibleFail->child[son] ){
                    position->child[son]->fail = possibleFail->child[son];
                    break;
                }

                if ( possibleFail == dictionary ){
                    position->child[son]->fail = dictionary;
                    break;
                }
            }
            myQueue.push(position->child[son]);
            reverseQueue.push(position->child[son]);
        }
    }
}

void Trie :: getThrought(string word){
    int length = word.size();
    Trie *position = dictionary;

    for ( int index = 0; index < length; index++ ){
        int letter = word[index] - 'a';

        if ( position->child[letter] ){
            position = position->child[letter];
            position->contor++;
        }
        else
        if ( position == dictionary ){
            ;
        }
        else{
            position = position->fail;
            index--;
        }
    }
}

inline void feedAnswers(){
    for ( ; reverseQueue.size(); reverseQueue.pop() ){
        auto trie = reverseQueue.top();
        trie->fail->contor += trie->contor;
    }
}

string bigWord;

int totalWords;

inline void readVariables(){
    fin >> bigWord;
    fin >> totalWords;

    string word;
    for ( int index = 0; index < totalWords; index++ ){
        fin >> word;
        dictionary->insertWord(word);
    }
}

inline void answerQuestions(){
    for ( auto word : wordEndings ){
        fout << word->contor << "\n";
    }
}

int main(){
    readVariables();
    determinateFails();
    dictionary->getThrought(bigWord);
    feedAnswers();
    answerQuestions();
    return 0;
}