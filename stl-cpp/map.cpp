#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <map>
using namespace std;

int main() {
    map<string, int> m;
    
    m["tv"] = 100;
    m["macbook"] = 50;
    m["airbuds"] = 100;

    m.insert({"apple vision pro", 25});
    m.emplace("meta glasses", 30);
    m.erase("tv");

    for(auto p: m) {
        cout << p.first << " " << p.second << endl;
    }

    if(m.find("iphone") != m.end()) {
        cout << "Found\n";
    } else {
        cout << "Not found\n";
    }

    cout << "count = " << m.count("tv") << endl;


    return 0;
  

   

  

    return 0;
}