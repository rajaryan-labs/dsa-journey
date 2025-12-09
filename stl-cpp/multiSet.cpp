#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
using namespace std;

int main() {
    multiset<int> s;

    //prints_element_in_asending_order.

    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);   
    s.insert(5);      
    s.insert(1);  //multiset stores duplicate element
    s.insert(2);  //multiset stores duplicate element
    s.insert(1);  //multiset stores duplicate element
    s.insert(4);  //multiset stores duplicate element

    for(auto val: s) {
        cout << val << " ";
    }
    cout << endl;

   
  

   

  

    return 0;
}