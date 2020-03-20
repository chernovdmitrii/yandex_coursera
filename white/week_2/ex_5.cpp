#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector <string> MoveStrings(vector <string>& source, vector <string>& destination){
    for (auto i : source) {
        destination.push_back(i);
    }
    source.clear(); 
    return destination;
}

int main() {
    vector <string> source = {"a", "b", "c", "d", "e", "f"};
    vector <string> destination = {"x", "y", "z"};
    
    MoveStrings(source, destination);
    
    for (auto i : destination) {
        cout << i << endl;
    }
    
    return 0;
}
