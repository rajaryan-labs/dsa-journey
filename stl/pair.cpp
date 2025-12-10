#include <iostream>
#include <vector>
#include <list>
#include <deque>

using namespace std;

int main() {

    // pair<int, int> p = {1,5};

    //   pair<string, int> p = {"hello", 5};

    //    pair<int, pair<int, int> > p = {5, {2, 6}};

    // cout<< p.first << endl;
    // cout << p.second.first << endl;


    vector<pair<int, int>> vec = {{1, 2}, {3, 4}, {5, 6}};

    // for(pair<int, int> p: vec) {
    //     cout << p.first << "," << p.second << endl;
    // }
   

     for(auto p: vec) {
        cout << p.first << " " << p.second << endl;
    }
   
  
  



    return 0;
}