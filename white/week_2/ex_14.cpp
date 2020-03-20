#include <iostream>
#include <map>
#include <vector>
#include <string>

//4
//2 Marushkino Kokoshkino
//1 Kokoshkino
//2 Marushkino Kokoshkino
//2 Kokoshkino Marushkino

using namespace std;

bool compare(const vector <string> & first, const vector <string> & second){
    if (first.size() != second.size()){
        return false;
    } else {
        int i = 0;
        while (i < first.size()){
            if (first[i] != second[i]){
                return false;
            } else {
                ++i;
            }
        }
    }
    return true;
}

int main() {
    int q;
    cin >> q;
    int buses = 1;
    
    map <vector<string>, int> route;
    
    for (int i = 0; i < q; ++i){
        vector<string> key_vec;
        int num;
        bool flag = false;
        string bus_stop;
        cin >> num;
        
        for (int j = 0; j < num; ++j){
            cin >> bus_stop;
            key_vec.push_back(bus_stop);
        }
        
        for (auto item : route){
            //cout << compare(item.first, key_vec) << endl;
            if (compare(item.first, key_vec)) {
                cout << "Already exists for " << item.second << endl;
                flag = true;
            }
        }
        if (!(flag)) {
            route[key_vec] = buses;
            cout << "New bus " << buses << endl;
            ++buses;
        }
        
    }
    return 0;
}
