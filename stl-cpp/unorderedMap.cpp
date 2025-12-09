#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <map>
#include<unordered_map>
using namespace std;

int main() {
    unordered_map<string, int> m;
    

    m.insert({"tv", 25});
    m.emplace("meta glasses", 30);
    m.insert({"tv", 25});
    m.insert({"laptop", 25});
    m.insert({"iphone", 25});
    

    for(auto p: m) {
        cout << p.first << " " << p.second << endl;
    }



    return 0;
  

   

  

    return 0;
}