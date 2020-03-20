#include <iostream>
#include <map>
#include <string>

using namespace std;

//3
//eat tea
//find search
//master stream

map<char, int> BuildCharCounters (const string & word){
    map<char, int> count;
    for (auto i : word){
        count[i] = count[i] + 1;
    }
    //    for (auto item : count){
    //        cout << item.first << " " << item.second << endl;
    //    }
    return count;
}

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; ++i){
        string str_1, str_2;
        cin >> str_1 >> str_2;
        if (BuildCharCounters(str_1) ==BuildCharCounters (str_2)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
