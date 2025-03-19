#include <iostream>
#include <vector>
#include <algorithm> // For lower_bound, upper_bound, equal_range

int lowerBound_cORNERcASE(vector<int> arr, int Val) {
    auto it = lower_bound(arr.begin(), arr.end(), Val);

    // Case 1: If `Val` is found in the array, return `Val` itself
    if (it != arr.end() && *it == Val) {
        return Val;
    }

    // Case 2: If `Val` is smaller than the smallest element, return `-1`
    if (it == arr.begin()) {
        return -1;
    }

    // Case 3: Return the largest element smaller than `Val`
    return *(--it);
}

using namespace std;

int main() {
    vector<int> arr = {-1, -1, 2, 3, 5}; // Sorted array
    int x = 4;

    // Finding lower_bound
    auto lower = lower_bound(arr.begin(), arr.end(), x);
    cout << "Lower Bound of " << x << " is at index: " << (lower - arr.begin()) << endl;

    // Finding upper_bound
    auto upper = upper_bound(arr.begin(), arr.end(), x);
    cout << "Upper Bound of " << x << " is at index: " << (upper - arr.begin()) << endl;

    // Finding equal_range
    auto range = equal_range(arr.begin(), arr.end(), x);
    cout << "Equal Range of " << x << " starts at index: " << (range.first - arr.begin())
         << " and ends at index: " << (range.second - arr.begin()) << endl;

    // Count occurrences of x
    int count = upper - lower;
    cout << "Number of occurrences of " << x << ": " << count << endl;

    return 0;
}
