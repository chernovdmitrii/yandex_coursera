set<string> BuildMapValuesSet (const map<int, string> & m ) {
    set<string> quantity;
    
    for (auto item : m){
        quantity.insert(item.second);
    }
    return quantity;
}
