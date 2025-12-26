#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> vec = {3, 5, 1, 8, 2};

  // sort(vec.begin(), vec.begin() + 5);
  sort(vec.begin(), vec.end());

  for (auto val : vec) {
    cout << val << " ";
  }
  cout << endl;

  return 0;
}