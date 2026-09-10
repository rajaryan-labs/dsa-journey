#include <iostream>
#include <vector>
using namespace std;

int safeMidpoint(int st, int end)
{
    // st + end can overflow when both indices are large.
    return st + (end - st) / 2;
}

int recBinarySearch(const vector<int>& arr, int tar, int st, int end)
{
    if (st <= end)
    {
        int mid = safeMidpoint(st, end);

        if(tar > arr[mid])
        {
            return recBinarySearch(arr, tar, mid + 1, end);
        }
        else if(tar < arr[mid]) {
            return recBinarySearch(arr, tar, st, mid-1);
        } else{
            return mid;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr1 = {-1, 0, 3, 4, 5, 9, 12}; // odd
    int tar1 = 5;

    cout << recBinarySearch(arr1, tar1, 0, static_cast<int>(arr1.size()) - 1) << endl;

    vector<int> arr2 = {-1, 0, 3, 5, 9, 12}; // even
    int tar2 = 0;

    cout << recBinarySearch(arr2, tar2, 0, static_cast<int>(arr2.size()) - 1) << endl;

    return 0;
}