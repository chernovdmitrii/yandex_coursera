#include <iostream>
using namespace std;

void UpdateIfGreater(int a, int& b) {
    if (a > b) {
        b = a;
    }
}

int main() {
    int first, second;
    
    cin >> first >> second;
    UpdateIfGreater(first, second);
    
    cout << first << second; 
    
    return 0;
}
