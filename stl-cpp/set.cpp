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
    set<int> s;

    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);   
    s.insert(5);      
    s.insert(1);  // not store duplicate value

    //   *(lower_bound());
    //  if exist then return same no.
    //  if not exist : returns just greater no.
    // if greater no. not exist in set then return set.end(), which is 0;

    cout << "lower_bound: " << *(s.lower_bound(4)) << endl;

    cout << "upper_bound: " << *(s.upper_bound(3)) << endl;

    return 0;
  

   

  

    return 0;
}