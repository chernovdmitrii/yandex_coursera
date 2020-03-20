#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    int n;
    string command;
    cin >> n;
    map <string, string> handbook; // country, capital
    
    for (int i = 0; i < n; ++i){
        cin >> command;
        if (command == "CHANGE_CAPITAL"){
            
            string country, new_capital;
            cin >> country >> new_capital;
            
            if (handbook.count(country) == 0){
                cout << "Introduce new country " << country << " with capital " << new_capital << endl;
            } else {
                string old_capital = handbook[country];
                if (old_capital == new_capital) {
                    cout << "Country "<< country << " hasn't changed its capital" << endl;
                } else {
                    cout << "Country " << country << " has changed its capital from " << old_capital << " to " << new_capital << endl;
                }
            }
            handbook[country] = new_capital;
            
        } else if (command == "RENAME"){
            
            string old_country_name, new_country_name;
            cin >> old_country_name >> new_country_name;
            
            if ((old_country_name == new_country_name) || (handbook.count(new_country_name) == 1) || (handbook.count(old_country_name) == 0)){
                cout << "Incorrect rename, skip" << endl;
            } else {
                cout << "Country " << old_country_name << " with capital " << handbook[old_country_name] << " has been renamed to " << new_country_name << endl;
                handbook[new_country_name] = handbook[old_country_name]; // capital are beeing equaling
                handbook.erase(old_country_name); //deleting old name of country
            }
        } else if (command =="ABOUT"){
            string country;
            cin >> country;
            
            if (handbook.count(country) == 0) {
                cout << "Country " << country << " doesn't exist" << endl;
            } else {
                cout << "Country " << country << " has capital " << handbook[country] << endl;
            }
        } else if (command == "DUMP"){
            
            if (handbook.size() == 0) {
                cout << "There are no countries in the world" << endl;
            } else {
                for (auto item : handbook){
                    cout << item.first << "/" << item.second << " ";
                }
                cout << endl;
            }
        }
    }
    return 0;
}
