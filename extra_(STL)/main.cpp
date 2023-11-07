#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>

using namespace std;

void vec(){
    vector<int> ages;
    vector<int>::iterator it;

    ages.push_back(20);
    ages.push_back(13);
    ages.push_back(49);
    ages.push_back(22);
    ages.push_back(2);

    cout << "disordered vector: ";
    for(int i = 0; i < int(ages.size()); i++){
        cout << ages[i] << " ";
    }

    cout << "\nordered vector: ";
    sort(ages.begin(), ages.end());
    for(it = ages.begin(); it != ages.end(); ++it){
        cout << *it << " ";
    }
}

void mp(){
    map<string, int> scores;
    map<string, int>::iterator it;

    scores["Davi"] = 95;
    scores["Nasiasene"] = 100;
    scores["Amorim"] = 90;

    cout << "Score of Nasiasene: " << scores["Nasiasene"] << endl;

    if (scores.find("David") != scores.end()) 
        cout << "Score of David: " << scores["David"] << endl;
    else 
        cout << "David not found in the map." << endl;
    
    for (const auto pair : scores) {
        cout << pair.first << ": " << pair.second << endl;
    }
}

void multimp(){
    multimap<string, int> scores;
    multimap<string, int>::iterator it;
    pair<string, int> pair_("Nasiasene", 98);

    scores.insert(make_pair("Davi", 95));
    scores.insert(pair<string, int>("Nasiasene", 85));
    scores.insert(pair<string, int>("Amorim", 90));
    scores.insert(pair_);  // same key

    cout << "Scores of Davi- " << endl;
    auto range = scores.equal_range("Davi");
    for (auto it = range.first; it != range.second; ++it) {
        cout << it->first << ": " << it->second << endl;
    }

    cout << endl;

    for (const auto& pair : scores) {
        cout << pair.first << ": " << pair.second << endl;
    }
}


int main(){
    vec();
    cout << "\n\n-------------------------------------\n";
    mp();
    cout << "\n-------------------------------------\n";
    multimp();
}