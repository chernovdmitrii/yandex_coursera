#include <iostream>
#include <set>
#include <string>

using namespace std;

//6
//first
//second
//first
//third
//second
//second

int main() {
    int quan;
    cin >> quan;
    set<string> words;
    
    for (int i = 0; i < quan; ++i){
        string word;
        cin >> word;
        words.insert(word);
    }
    
    cout << words.size() << endl;
    return 0;
}
