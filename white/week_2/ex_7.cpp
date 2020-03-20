#include <iostream>
#include <vector>
using namespace std;

vector<int> Reversed(const vector<int>& v) {
    vector <int> temp;
    for (int i = v.size() - 1; i >= 0; --i){
        temp.push_back(v[i]);
    }
    return temp; 
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> neww = Reversed(nums);
    for (auto i : neww) cout << i << endl;
    return 0;
}
