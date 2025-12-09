#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vec; // initial size 0

    vec.push_back(1);
    vec.emplace_back(9);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(1);
   
    vec.pop_back(); 
    

    for(int val: vec) {
        cout << val << " " ;
    } 
    cout << endl;

    cout << "val at index 2: " << vec[1] << " or " << vec.at(1) << endl;

    cout <<  "Size: " << vec.size() << endl;
    cout << "capacity: " << vec.capacity() << endl;

     cout <<  "front: " << vec.front() << endl;
     cout <<  "back: " << vec.back() << endl;





    return 0;
}