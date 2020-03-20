#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int quant;
    int day;
    string command;
    string affair;
    cin >> quant;
    
    vector <int> daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<vector<string>> month (31);
    
    int start = 0;
    
    for (int i = 0; i < quant; ++i){
        cin >> command;
        if (command == "ADD"){
            cin >> day;
            day = day - 1;
            cin >> affair;
            month[day].push_back(affair);
            
        } else if (command == "NEXT"){
            if (start == 11) {
                start = 0;
            } else {
                int diff = daysInMonth[start + 1] - daysInMonth[start];
                if (diff >= 0) {
                    month.resize(daysInMonth[start + 1]);
                } else {
                    for (int j = daysInMonth[start] + diff; j < daysInMonth[start]; j++) {
                        month[daysInMonth[start + 1] - 1].insert(month[daysInMonth[start + 1] - 1].end(), month[j].begin(), month[j].end());
                    }
                    month.resize(daysInMonth[start + 1]);
                }
                ++start;
            }
    } else if (command == "DUMP"){
        cin >> day;
        day = day - 1;
        cout << month[day].size() << ' ';
        for(auto i : month[day]){
            cout << i << ' ';
        }
        cout << endl;
    }
}
return 0;
}
