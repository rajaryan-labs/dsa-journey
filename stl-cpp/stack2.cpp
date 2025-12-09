#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
using namespace std;

int main() {
    stack<int> s;

    stack<int> s2;


    s.push(1);
    s.push(2);
    s.push(3);

    cout << "s size before swap: " << s.size() << endl;
    cout << "s2 size before swap: " << s2.size() << endl;

    s2.swap(s);
  
   cout << "s size after swap: " << s.size() << endl;
   cout << "s2 size after swap: " << s2.size() << endl;
  

  

    return 0;
}