#include <iostream>
#include <vector>
using namespace std;

int main() {

    vector<int> vec = {1, 2, 3, 4, 5};

    //vec.erase(vec.begin());
    //vec.erase(vec.begin() + 2);
   //  vec.erase(vec.begin() + 1 , vec.begin() + 4); //vec.erase(included, notIncluded)
   //vec.insert(vec.begin() + 2, 100);
//    vec.clear();
   
    for(int val: vec) {
        cout << val << " ";
    }
    cout << endl;

     cout <<  "Size: " << vec.size() << endl;
    cout << "capacity: " << vec.capacity() << endl;
    cout << "is empty: " << vec.empty() << endl; // return 0 -> false, 1 -> true

    return 0;
}
