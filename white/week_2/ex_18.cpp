#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>

//5
//2 Marushkino Kokoshkino
//1 Kokoshkino
//2 Marushkino Kokoshkino
//2 Kokoshkino Marushkino
//2 Kokoshkino Kokoshkino
//-------------------------------------
//New bus 1
//New bus 2
//Already exists for 1
//Already exists for 1
//Already exists for 2

using namespace std;

int main() {
    int q;
    cin >> q;
    int buses = 1;
    
    map <set<string>, int> route;
    
    for (int i = 0; i < q; ++i){
        set<string> key_vec;
        int num;
        string bus_stop;
        cin >> num;
        
        for (int j = 0; j < num; ++j){
            cin >> bus_stop;
            key_vec.insert(bus_stop);
        }
        
        if (route.count(key_vec) == 0) {
//            cout << "buses: " << buses;
            route[key_vec] = buses;
            cout << "New bus " << buses << endl;
            ++buses;
        } else {
            cout << "Already exists for " << route[key_vec] << endl;
        }
    }
    return 0;
}
