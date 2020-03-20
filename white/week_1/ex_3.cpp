//таким образом, массу блока можно вычислять как простое произведение плотности на объём.
/*
2 14
1 2 3
30 40 50

840084
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    uint64_t H, R;
    cin >> H >> R;
    vector<uint64_t> volume (H);
    for(auto& i : volume){
        uint64_t W, H, D;
        cin >> W >> H >> D;
        volume.push_back(W*H*D);
    }

    uint64_t mass = 0;
    uint64_t temp;

    for(auto i : volume) {
        temp = i * R;
        mass += temp;
    }

    cout << mass << endl;
    return 0;
}