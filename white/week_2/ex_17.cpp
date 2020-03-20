#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

//8
//ADD program code
//COUNT cipher
//ADD code cipher
//COUNT code
//COUNT program
//CHECK code program
//CHECK program cipher
//CHECK cpp java
//------------------------------
//0
//2
//1
//YES
//NO
//NO

int main() {
    int q;
    cin >> q;
    
    map <string, set<string>> synonyms;
    
    for (int i = 0; i < q; ++i){
        string command;
        cin >> command;
        if (command == "ADD"){
            string word_1, word_2;
            cin >> word_1 >> word_2;
            
            synonyms[word_1].insert(word_2);
            synonyms[word_2].insert(word_1);
            
        } else if (command == "COUNT"){
            string word;
            cin >> word;
            if (synonyms.count(word) == 0){
                cout << 0 << endl;
            } else {
                cout << synonyms[word].size() << endl;
            }
            
        } else if (command == "CHECK"){
            string word_1, word_2;
            cin >> word_1 >> word_2;
            
            if (synonyms[word_1].count(word_2) != 0){
                cout << "YES" << endl;
            } else if (synonyms[word_2].count(word_1) != 0){
                cout << "NO" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else cout << "Error!" << endl;
    }
    return 0;
}
