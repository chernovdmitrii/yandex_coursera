#include <iostream>
#include <map>
#include <vector>
#include <tuple>

using namespace std;

//enum class Lang {
//    DE, FR, IT
//};
//
//struct Region {
//    string std_name;
//    string parent_std_name;
//    map<Lang, string> names;
//    int64_t population;
//};
bool operator ==(const Region& one, const Region& two){
    return tie(one.std_name, one.parent_std_name, one.names, one.population) ==
    tie(two.std_name, two.parent_std_name, two.names, two.population);
}

bool operator <(const Region& one, const Region& two){
    return tie(one.std_name, one.parent_std_name, one.names, one.population) <
           tie(two.std_name, two.parent_std_name, two.names, two.population);
}
//int FindMaxRepetitionCount(const vector<Region>& regions){
//    if (regions.size() == 0 ) return 0;
//    if (regions.size() == 1 ) return 1;
//    int count = 0;
//    Region temp = regions[0];
//    for(auto i : regions){
//        if (i == temp){
//           ++count;
//        }
//    }
//    return count;
//}

//void print(map <Region, int> m){
//    for(auto i : m){
//        cout << "Key: " << endl <<
//                i.first.std_name << endl <<
//                i.first.parent_std_name << endl <<
//                i.first.population << endl << "value: " << endl << i.second << endl << endl;
//    }
//}

int FindMaxRepetitionCount(const vector<Region>& regions) {
    int result = 0;
    map<Region, int> repetion_count;
    for (const Region& region : regions) {
        result = max(result, ++repetion_count[region]);
        //print(repetion_count);
    }
    return result;
}

//int main() {
//    cout << FindMaxRepetitionCount({
//                                           {
//                                                   "Moscow",
//                                                   "Russia",
//                                                   {{Lang::DE, "Moskau"},   {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
//                                                   89
//                                           },
//                                           {
//                                                   "Russia",
//                                                   "Eurasia",
//                                                   {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
//                                                   89
//                                           },
//                                           {
//                                                   "Moscow",
//                                                   "Russia",
//                                                   {{Lang::DE, "Moskau"},   {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
//                                                   89
//                                           },
//                                           {
//                                                   "Moscow",
//                                                   "Russia",
//                                                   {{Lang::DE, "Moskau"},   {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
//                                                   89
//                                           },
//                                           {
//                                                   "Russia",
//                                                   "Eurasia",
//                                                   {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
//                                                   89
//                                           },
//                                   }) << endl;
//
////    cout << FindMaxRepetitionCount({
////                                           {
////                                                   "Moscow",
////                                                   "Russia",
////                                                   {{Lang::DE, "Moskau"},   {Lang::FR, "Moscou"},      {Lang::IT, "Mosca"}},
////                                                   89
////                                           },
////                                           {
////                                                   "Russia",
////                                                   "Eurasia",
////                                                   {{Lang::DE, "Russland"}, {Lang::FR, "Russie"},      {Lang::IT, "Russia"}},
////                                                   89
////                                           },
////                                           {
////                                                   "Moscow",
////                                                   "Russia",
////                                                   {{Lang::DE, "Moskau"},   {Lang::FR, "Moscou deux"}, {Lang::IT, "Mosca"}},
////                                                   89
////                                           },
////                                           {
////                                                   "Moscow",
////                                                   "Toulouse",
////                                                   {{Lang::DE, "Moskau"},   {Lang::FR, "Moscou"},      {Lang::IT, "Mosca"}},
////                                                   89
////                                           },
////                                           {
////                                                   "Moscow",
////                                                   "Russia",
////                                                   {{Lang::DE, "Moskau"},   {Lang::FR, "Moscou"},      {Lang::IT, "Mosca"}},
////                                                   31
////                                           },
////                                   }) << endl;
////    cout << FindMaxRepetitionCount({{"", "", {}, 0}}) << endl;
////    cout << FindMaxRepetitionCount({}) << endl;
////    cout << FindMaxRepetitionCount({
////                                           {
////                                                   "Moscow",
////                                                   "Russia",
////                                                   {{Lang::FR, "Moscou"},      {Lang::IT, "Mosca"}},
////                                                   89
////                                           },
////                                           {
////                                                   "Moscow",
////                                                   "Russia",
////                                                   {{Lang::DE, "Moskaus"},   {Lang::FR, "Moscou"},      {Lang::IT, "Mosca"}},
////                                                   31
////                                           },
////                                   }) << endl;
//
//    return 0;
//}
