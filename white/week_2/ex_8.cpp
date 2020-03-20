#include <iostream>
#include <vector>
using namespace std;

//5
//7 6 3 0 9

int main() {
    int num;
    cin >> num;
    vector <int> days;

    for (int i = 0; i < num; ++i){
        int temp;
        cin >> temp;
        days.push_back(temp);
    }

    int sum = 0;

    for(auto i : days){
        sum = sum + i;
    }

    int average = sum / num;
    int count = 0;
    vector <int> neww;

    for (int i = 0; i < num; ++i){
        if (days[i] > average){
            neww.push_back(i);
            ++count;
        }
    }

    cout << count << endl;
    for (auto i : neww) cout << i << " ";
    return 0;
}
