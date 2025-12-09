#include <iostream>
#include <vector>
#include <list>
#include <deque>

using namespace std;

int main() {
    vector<pair<int, int>> vec = {{1, 2}, {3, 4}, {5, 6}};

    //vec.push_back({7, 8});  insert
    vec.emplace_back(7, 8);  // in-place object create
      vec.emplace_back(9, 0);

 
   

     for(auto p: vec) {
        cout << p.first << " " << p.second << endl;
    }
   
  
  



    return 0;
}