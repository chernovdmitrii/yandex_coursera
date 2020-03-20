#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

//10
//ALL_BUSES
//BUSES_FOR_STOP Marushkino
//STOPS_FOR_BUS 32K
//NEW_BUS 32 3 Tolstopaltsevo Marushkino Vnukovo
//NEW_BUS 32K 6 Tolstopaltsevo Marushkino Vnukovo Peredelkino Solntsevo Skolkovo
//BUSES_FOR_STOP Vnukovo
//NEW_BUS 950 6 Kokoshkino Marushkino Vnukovo Peredelkino Solntsevo Troparyovo
//NEW_BUS 272 4 Vnukovo Moskovsky Rumyantsevo Troparyovo
//STOPS_FOR_BUS 272
//ALL_BUSES
//--------------------------------------------------------------------------------
//No buses
//No stop
//No bus
//32 32K
//Stop Vnukovo: 32 32K 950
//Stop Moskovsky: no interchange
//Stop Rumyantsevo: no interchange
//Stop Troparyovo: 950
//Bus 272: Vnukovo Moskovsky Rumyantsevo Troparyovo
//Bus 32: Tolstopaltsevo Marushkino Vnukovo
//Bus 32K: Tolstopaltsevo Marushkino Vnukovo Peredelkino Solntsevo Skolkovo
//Bus 950: Kokoshkino Marushkino Vnukovo Peredelkino Solntsevo Troparyovo

void printMap (const map<string, vector<string>> & m){
    for (auto item : m){
        cout << "key: " <<item.first << endl;
        for (auto word : item.second){
            cout << "value: " << word << endl;
        }
    }
    //cout << endl;
}

int main() {
    int q;
    cin >> q;
    
    map <string, vector<string>> route; // bus ; bus stops
    map <string, vector<string>> bus_stop; // bus stop ; buses
    
    for (int i = 0; i < q; ++i){
        string command;
        cin >> command;
        if (command == "NEW_BUS"){
            string bus, stop;
            int stop_count;
            
            cin >> bus >> stop_count;
            for (int j = 0; j < stop_count; ++j){
                cin >> stop;
                route[bus].push_back(stop);// adding stops to the bus
                bus_stop[stop].push_back(bus);
            }
            //printMap(route);
            //printMap(bus_stop);

        } else if (command == "BUSES_FOR_STOP") {
            string stop;
            cin >> stop;
            
            if (bus_stop.count(stop) == 0){
                cout << "No stop" << endl;
            } else {
                for(auto item : bus_stop[stop]){
                    cout << item << " ";
                }
                cout << endl; 
            }
        } else if (command == "STOPS_FOR_BUS") {
            string bus;
            cin >> bus;
            
            if (route.count(bus) == 0) {
                cout << "No bus" << endl;
            } else {
                for (auto stop: route[bus]){
                    cout << "Stop " << stop << ":";
                    for (auto buses : bus_stop[stop]){
                        if (buses != bus){
                            cout << " " << buses;
                        } else if (bus_stop[stop].size() == 1){
                            cout << " no interchange";
                        }
                    }
                    cout << endl;
                }
            }
            
        } else if (command == "ALL_BUSES") {
            if (route.size() == 0){
                cout << "No buses" << endl;
            } else {
                for (auto bus : route){
                    cout << "Bus " << bus.first << ":";
                    for (auto stop : bus.second){
                        cout << " " << stop;
                    }
                    cout << endl;
                }
            }
            
        } else cout << "Error!" << endl;
    }
    
    //printMap(route);
    return 0;
}
