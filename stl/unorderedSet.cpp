#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
using namespace std;

int main() {
    unordered_set<int> s;

    // prints element in any random order

    s.insert(1);
    s.insert(2); 
    s.insert(3);
    s.insert(4);   
    s.insert(5);      
    s.insert(1);  //unordered set not stores duplicate elements
   

    for(auto val: s) {
        cout << val << " ";
    }
    cout << endl;

   
  

   

  

    return 0;
}