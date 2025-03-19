///////////////////////////////////////////////////////////////

// Udemy Course Data Structures & Algorithms Essentials using C++

// // 1. Largest Element
// #include<bits/stdc++.h>
// using namespace std;

// int largestElement(vector<int> arr) {
    
//     int n = arr.size();
//     sort(arr.begin(),arr.end());
//     return arr[n-1];
// }

// // 2. Maximum Subarray Sum
// #include<bits/stdc++.h>
// using namespace std;

// int maxSumSubarray(vector<int> A) {
//     // Compute the prefix sums into a vector
//     int sum = 0;
//     vector<int> prefix;
//     prefix.resize(A.size());
//     prefix[0] = A[0];
//     for (int i = 1; i < A.size(); i++){
//         prefix[i] = prefix[i-1] + A[i];
//     }

//     // Largest sum logic
//     sum = 0;
//     int answer = INT_MIN;
//     for (int i = 0; i<A.size(); i++){
//         for (int j = i; j<A.size(); j++){
//             sum = (i>0)? prefix[j] - prefix[i-1] : prefix[j];
//             answer = max(answer, sum);
//             sum = 0;
//         }
//     }
//     return answer;
// }

// // 3. Lower Bound.. Very Hard..
// #include<bits/stdc++.h>
//  using namespace std;
// int lowerBound(vector<int> A, int Val) {
//     int left = 0, right = A.size() - 1;
//     int answer = -1;
//     while (left <= right) {
//         int mid = (left + right) / 2;       
//         if (A[mid] <= Val){
//              answer = A[mid];
//              left = mid + 1;
//         }
//         else right = mid - 1;
//     }
//     return answer; 
// }


// // 4. Sorted Pair Sum.. Also Very Hard..
// #include<bits/stdc++.h>
// using namespace std;

// pair<int, int> closestSum(vector<int> arr, int x){
//     int sum = 0;
//     int answer =  INT_MAX;
//     pair<int, int> result;
//     for (int i = 0; i<arr.size()-1; i++){
//         for (int j = i+1; j<arr.size(); j++){
//             sum = arr[i]+ arr[j];
//             if (answer > (abs(x-sum)) ){
//                 answer = abs(x-sum);
//                 result = {arr[i], arr[j]};
//             }
//         }
//     }
    
//     return result;
// }

////////////////////////////////////////////////////////////////

// HackerRank

// // 1. Array-DS
// #include <bits/stdc++.h>

// using namespace std;

// string ltrim(const string &);
// string rtrim(const string &);
// vector<string> split(const string &);

// /*
//  * Complete the 'reverseArray' function below.
//  *
//  * The function is expected to return an INTEGER_ARRAY.
//  * The function accepts INTEGER_ARRAY a as parameter.
//  */

// vector<int> reverseArray(vector<int> a) {
//     vector<int> result[];
//     result.resize(a.size());
//     reverse(a.begin(), a.end());
//     for (auto element : a) result.push_back(element);
//     return result;
// }

// int main()
// {
//     ofstream fout(getenv("OUTPUT_PATH"));

//     string arr_count_temp;
//     getline(cin, arr_count_temp);

//     int arr_count = stoi(ltrim(rtrim(arr_count_temp)));

//     string arr_temp_temp;
//     getline(cin, arr_temp_temp);

//     vector<string> arr_temp = split(rtrim(arr_temp_temp));

//     vector<int> arr(arr_count);

//     for (int i = 0; i < arr_count; i++) {
//         int arr_item = stoi(arr_temp[i]);

//         arr[i] = arr_item;
//     }

//     vector<int> res = reverseArray(arr);

//     for (size_t i = 0; i < res.size(); i++) {
//         fout << res[i];

//         if (i != res.size() - 1) {
//             fout << " ";
//         }
//     }

//     fout << "\n";

//     fout.close();

//     return 0;
// }

// string ltrim(const string &str) {
//     string s(str);

//     s.erase(
//         s.begin(),
//         find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
//     );

//     return s;
// }

// string rtrim(const string &str) {
//     string s(str);

//     s.erase(
//         find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
//         s.end()
//     );

//     return s;
// }

// vector<string> split(const string &str) {
//     vector<string> tokens;

//     string::size_type start = 0;
//     string::size_type end = 0;

//     while ((end = str.find(" ", start)) != string::npos) {
//         tokens.push_back(str.substr(start, end - start));

//         start = end + 1;
//     }

//     tokens.push_back(str.substr(start));

//     return tokens;
// }


////////////////////////////////////////////////////////////////

// Geeks for Geeks 
// 1. Min and Max in Array.. DONE!!!!!!!!
// 2. Reverse an Array.. DONE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// 3. Rotate Array by One.DONE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// 4. Sort an Array. Not working atm
// 5. Array Duplicates.. DONE !!!!!
// 6. Sort 0s, 1s and 2s.. DONE!!!!
// 7. Move all negative elements to end.. DONE!!!

// // 7. Solution
// void segregateElements(vector<int>& arr) {
//     int n = arr.size();
//     vector<int> temp(n); // Temporary array of the same size
//     int posIndex = 0;

//     // Step 1: Store positive elements in the same order
//     for (int i = 0; i < n; i++) {
//         if (arr[i] >= 0) {
//             temp[posIndex++] = arr[i];
//         }
//     }

//     // Step 2: Store negative elements in the same order
//     for (int i = 0; i < n; i++) {
//         if (arr[i] < 0) {
//             temp[posIndex++] = arr[i];
//         }
//     }

//     // Step 3: Copy back to the original array
//     for (int i = 0; i < n; i++) {
//         arr[i] = temp[i];
//     }
// }

////////////////////////////////////////////////////////////////