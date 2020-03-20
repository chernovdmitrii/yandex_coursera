#include <iostream>
#include <vector>
#include <string>

//8
//COME 5
//WORRY 1
//WORRY 4
//COME -2
//WORRY_COUNT
//COME 3
//WORRY 3
//WORRY_COUNT

using namespace std;

int main() {
    int quantity;
    
    cin >> quantity;
    vector <bool> queue;
    string command;
    int value;
    
    for(int i = 0; i < quantity; ++i){
        cin >> command;
        if (command == "WORRY"){
            cin >> value;
            queue[value] = true;
        } else if (command == "QUIET"){
            cin >> value;
            queue[value] = false;
        } else if (command == "COME"){
            cin >> value;
            if (value > 0){
                for (int i = 0; i < value; ++i)
                    queue.push_back(false);
            } else {
                queue.resize(queue.size() - abs(value));
            }
        } else if (command == "WORRY_COUNT"){
            int count = 0;
            for (auto i : queue){
                if (i) ++count;
            }
            cout << count << endl;
        }
    }
    
    return 0;
}
