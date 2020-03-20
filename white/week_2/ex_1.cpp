#include <iostream>
using namespace std;

int Factorial(int x){
    int y = x;
    if (x > 1){
        for(int i = 1; i < x; ++i) {
            y = y * i;
        }
    }
    else y = 1;
    
    return y;
}

int main() {
    int x;
    cin >> x;
    cout << Factorial(x);
    return 0;
}
