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
#include <algorithm>
using namespace std;

int main() {
    vector<int> vec = {3, 5, 1, 8, 2};

     sort(vec.begin(), vec.end(), greater<int>());
   

    for(auto val: vec) { 
        cout << val << " ";
    }
    cout << endl;

   
    return 0;
}