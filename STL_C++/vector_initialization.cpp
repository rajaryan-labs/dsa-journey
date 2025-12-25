#include <iostream>
#include <vector>
using namespace std;

int main() {

    vector<int> vec = {1, 2, 3, 4, 5};

    vector<int> vec2(3, 10); //dynamic programming - tabulation DP [] []
    vector<int> vec3(4, 11); 
    vector<int> vec4(vec); 




    for(int val: vec2) {
        cout << val << " ";
    }
    cout << endl;


    return 0;
}
