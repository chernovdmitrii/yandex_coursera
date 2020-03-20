#include <iostream>
#include <vector>
#include <string>
using namespace std;

//{"abacaba", "aba"}; 5
//{"abacaba", "aba"}; 2
//{"weew", "bro", "code"}; 4

bool IsPalindrom(string s) {
    for (int i = 0; i < s.size() / 2; ++i) {
        if (s[i] != s[s.size() - i - 1]) {
            return false;
        }
    }
    return true;
}

vector <string> PalindromFilter (vector <string> words, int minLength){
    bool flag = false;
    vector <string> newwords;
    for (int i = 0; i < words.size(); ++i) {
        flag = IsPalindrom(words[i]);
        if (flag && words[i].size() >= minLength){
            // << str[i] << endl;
            newwords.push_back(words[i]);
        }
    }
    return newwords;
}

int main() {
    vector<string> words = {"abacaba", "aba"};
    //vector<string> words = {"weew", "bro", "code"};
    //int minLength = 5;
    int minLength = 2;
    //int minLength = 4;
    vector <string> neww = PalindromFilter(words, minLength);
    //cout << words.size();
    for (int i = 0; i < neww.size(); ++i){
        cout << neww[i] << endl;
    }
    
    return 0;
}
