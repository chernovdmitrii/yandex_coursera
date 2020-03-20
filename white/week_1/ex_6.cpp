//vector: 1 4 9
//map of pairs:
//4 4 4
//7 16 9

#include <iostream>
#include <map>
#include <vector>

using namespace std;

template <typename T>
T Sqr(T x);

template <typename T>
vector<T> Sqr(const vector<T>& x);

template <typename key, typename value>
map<key, value> Sqr(const map<key, value>& x);

template <typename first, typename second>
pair<first, second> Sqr(const pair<first, second>& x);

template <typename T>
T Sqr(T x){
    return x * x;
}

template <typename T>
vector<T> Sqr(const vector<T>& x){
    vector<T> result;
    for (const auto& item : x){
        result.push_back(Sqr(item));
    }
    return result;
}

template <typename key, typename value>
map<key, value> Sqr(const map<key, value>& x){
    map<key, value> result;

    for(const auto& item : x){
        result[item.first] = Sqr(item.second);
    }
    return result;
}

template <typename first, typename second>
pair<first, second> Sqr(const pair<first, second>& x){
    pair<first, second> result = {Sqr(x.first), Sqr(x.second)};
    return result;
}


int main() {
    vector<int> v = {1, 2, 3};
    cout << "vector:";
    for (int x : Sqr(v)) {
        cout << ' ' << x;
    }
    cout << endl;

    map<int, pair<int, int>> map_of_pairs = {
            {4, {2, 2}},
            {7, {4, 3}}
    };
    cout << "map of pairs:" << endl;
    for (const auto& x : Sqr(map_of_pairs)) {
        cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
    }
    return 0;
}