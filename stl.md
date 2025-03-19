<h1 style="text-align:center">STL</h1>

```cpp
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <iterator>
#include <list>
using namespace std;

int main() {
    // Vector (Dynamic Array)
    cout << "===================== Vector =====================\n";
    vector<int> vec = {1, 2, 3, 4, 5};
    vec.push_back(6); // Insert at end
    vec.pop_back();   // Remove from end
    vec[2] = 10;      // Access element by index

    cout << "Vector elements: ";
    for (int i : vec) cout << i << " ";
    cout << endl;

    // Map (Key-Value Pair) - Sorted by Key
    cout << "===================== Map =====================\n";
    map<int, string> mp;
    mp[1] = "One";
    mp[2] = "Two";
    mp[3] = "Three";

    // Iterating through map
    cout << "Map elements: ";
    for (auto &p : mp) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;

    // Set (Unique elements, sorted)
    cout << "===================== Set =====================\n";
    set<int> s = {1, 2, 3, 4, 5, 5}; // Duplicates are ignored
    s.insert(6); // Insert an element
    s.erase(3);  // Erase an element

    cout << "Set elements: ";
    for (int i : s) cout << i << " ";
    cout << endl;

    // Unordered Map (Key-Value Pair, no specific order)
    cout << "===================== Unordered Map =====================\n";
    unordered_map<int, string> umap;
    umap[1] = "Apple";
    umap[2] = "Banana";
    umap[3] = "Mango";

    // Iterating through unordered_map
    cout << "Unordered Map elements: ";
    for (auto &p : umap) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;

    // Unordered Set (Unique elements, no specific order)
    cout << "===================== Unordered Set =====================\n";
    unordered_set<int> uset = {1, 2, 3, 4, 5};
    uset.insert(6); // Insert an element
    uset.erase(2);  // Erase an element

    cout << "Unordered Set elements: ";
    for (int i : uset) cout << i << " ";
    cout << endl;

    // Stack (LIFO)
    cout << "===================== Stack =====================\n";
    stack<int> st;
    st.push(1);  // Insert at top
    st.push(2);
    st.push(3);
    cout << "Top element: " << st.top() << endl;
    st.pop();    // Remove top element
    cout << "Top element after pop: " << st.top() << endl;

    // Queue (FIFO)
    cout << "===================== Queue =====================\n";
    queue<int> q;
    q.push(1);  // Enqueue
    q.push(2);
    q.push(3);
    cout << "Front element: " << q.front() << endl;
    q.pop();    // Dequeue
    cout << "Front element after pop: " << q.front() << endl;

    // Deque (Double-ended Queue)
    cout << "===================== Deque =====================\n";
    deque<int> dq = {1, 2, 3, 4, 5};
    dq.push_back(6); // Insert at back
    dq.push_front(0); // Insert at front
    dq.pop_back();   // Remove from back
    dq.pop_front();  // Remove from front

    cout << "Deque elements: ";
    for (int i : dq) cout << i << " ";
    cout << endl;

    // List (Doubly Linked List)
    cout << "===================== List =====================\n";
    list<int> lst = {1, 2, 3, 4, 5};
    lst.push_back(6);  // Insert at back
    lst.push_front(0); // Insert at front
    lst.pop_back();    // Remove from back
    lst.pop_front();   // Remove from front

    cout << "List elements: ";
    for (int i : lst) cout << i << " ";
    cout << endl;

    // Sorting an Array using STL
    cout << "===================== Sorting =====================\n";
    vector<int> sortVec = {5, 2, 9, 1, 5, 6};
    sort(sortVec.begin(), sortVec.end());  // Sort in ascending order

    cout << "Sorted Vector: ";
    for (int i : sortVec) cout << i << " ";
    cout << endl;

    // Reverse an Array
    cout << "===================== Reverse =====================\n";
    reverse(sortVec.begin(), sortVec.end());  // Reverse the array

    cout << "Reversed Vector: ";
    for (int i : sortVec) cout << i << " ";
    cout << endl;

    // Finding an element using Binary Search
    cout << "===================== Binary Search =====================\n";
    vector<int> bsVec = {1, 2, 3, 4, 5, 6};
    bool found = binary_search(bsVec.begin(), bsVec.end(), 4);  // Search for 4

    cout << "Element 4 found: " << (found ? "Yes" : "No") << endl;

    // Lower Bound and Upper Bound
    cout << "===================== Lower and Upper Bound =====================\n";
    auto lower = lower_bound(bsVec.begin(), bsVec.end(), 4); // First element not less than 4
    auto upper = upper_bound(bsVec.begin(), bsVec.end(), 4); // First element greater than 4

    cout << "Lower Bound for 4: " << *lower << endl;
    cout << "Upper Bound for 4: " << *upper << endl;

    // ForEach (Applying function to each element in a range)
    cout << "===================== ForEach =====================\n";
    for_each(bsVec.begin(), bsVec.end(), [](int n) { cout << n << " "; });
    cout << endl;

    // Fill (Filling an array with a specific value)
    cout << "===================== Fill =====================\n";
    fill(bsVec.begin(), bsVec.end(), 100);  // Fill with 100

    cout << "Filled Vector: ";
    for (int i : bsVec) cout << i << " ";
    cout << endl;

    return 0;
}

```
