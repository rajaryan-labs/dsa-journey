#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <map>
using namespace std;

int main() {
    multimap<string, int> m;
    
    // square bracket cannot used in multimap
    // m["tv"] = 100;
    // m["macbook"] = 50;
    // m["airbuds"] = 100;

    m.insert({"tv", 25});
    m.emplace("meta glasses", 30);
    m.insert({"tv", 25});
    m.insert({"tv", 25});
    m.insert({"tv", 25});

    //m.erase("tv");  //erases all "tv";
    m.erase(m.find("tv"));  //erases only one "tv";
    

    for(auto p: m) {
        cout << p.first << " " << p.second << endl;
    }

   


    cout << "count = " << m.count("tv") << endl;


    return 0;
  

   

  

    return 0;
}