#include <iostream>
#include <string>
using namespace std;

bool IsPalindrom(string s) {
    for (int i = 0; i < s.size() / 2; ++i) {
        if (s[i] != s[s.size() - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    string str;
    cin >> str;
    int result = IsPalindrom(str);
    //cout << IsPalindrom(str) << endl;
    if (result == 1) cout << "true";
    else cout << "false";
    
    return 0;
}
