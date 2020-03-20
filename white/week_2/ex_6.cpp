#include <iostream>
#include <vector>
using namespace std;

//void Reverse(vector<int>& v) {
//    int n = v.size();  // для удобства сохраним размер вектора в переменную n
//    for (int i = 0; i < n / 2; ++i) {
//        // элемент с индексом i симметричен элементу с индексом n - 1 - i
//        // поменяем их местами с помощью временной переменной tmp
//        int tmp = v[i];
//        v[i] = v[n - 1 - i];
//        v[n - 1 - i] = tmp;
//    }
//}

void Reverse(vector<int>& nums) {
    vector <int> templ;
    for (int i = nums.size() - 1; i >= 0; --i){
        //cout << nums[i] << " " << endl;
        templ.push_back(nums[i]);
    }
    nums.clear();
    nums = templ;
}

int main() {
    vector <int> num = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Reverse(num);
    
    for (auto i : num){
        cout << i << endl;
    }
    return 0;
}
