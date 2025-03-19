#include <bits/stdc++.h>
using namespace std;


int linearSearch(const vector<int>& v, int key) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == key) return i; 
    }
    return -1; 
}
int binarySearch(const vector<int>& v, int key) {
    int left = 0, right = v.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2; 
        if (v[mid] == key) return mid;       
        else if (v[mid] < key) left = mid + 1;
        else right = mid - 1;
    }
    return -1; 
}
void printpairs(const vector<int>&v){
    for (int i = 0; i<v.size()-1; i++){
        for (int j = i+1; j<v.size(); j++){
            cout<<"The pair is : ( "<<v[i]<<" "<<v[j]<<")"<<endl;
        }
    }
}
void printSubarray(const vector<int>&v){
    for (int i = 0; i<v.size(); i++){
        for (int j = i; j<v.size(); j++){
            for (int k = i; k<=j; k++){
                cout<<v[k]<<" ";
            }
            cout<<endl;
        }
    }
}
int largest_subarray1(const vector<int>&v){
    int sum = 0;
    int answer = INT_MIN;
    for (int i = 0; i<v.size(); i++){
        for (int j = i; j<v.size(); j++){
            for (int k = i; k<=j; k++){
                sum += v[k];
                cout<<v[k]<<" ";
            }
            // cout<<endl;
            // cout<<"The sum of this subarray is "<<sum<<endl;
            answer = max(answer, sum);
            sum = 0;
        }
    }
    return answer;
}
int largest_subarray2(const vector<int>&v){
    // Compute the prefix sums into a vector
    int sum = 0;
    vector<int> prefix;
    prefix.resize(v.size());
    prefix[0] = v[0];
    for (int i = 1; i < v.size(); i++){
        prefix[i] = prefix[i-1] + v[i];
    }

    // Largest sum logic
    sum = 0;
    int answer = INT_MIN;
    for (int i = 0; i<v.size(); i++){
        for (int j = i; j<v.size(); j++){
            sum = (i>0)? prefix[j] - prefix[i-1] : prefix[j];
            answer = max(answer, sum);
            sum = 0;
        }
    }
    return answer;
}

int kadaneAlgorithm(const vector<int>& v) {
    int currentSum = 0;
    int maxSum = INT_MIN;
    for (int i = 0; i < v.size(); i++) {
        currentSum += v[i];
        maxSum = max(maxSum, currentSum);
        if (currentSum < 0) currentSum = 0;
    }
    return maxSum;
}

vector<int> subarraySum(vector<int> &v, int target) {
        // code here
        vector<int>res;
            // Compute the prefix sums into a vector
            int sum = 0;
            vector<int> prefix;
            prefix.resize(v.size());
            prefix[0] = v[0];
            for (int i = 1; i < v.size(); i++){
                prefix[i] = prefix[i-1] + v[i];
            }
        
            // Largest sum logic
            sum = 0;
            for (int i = 0; i<v.size(); i++){
                for (int j = i; j<v.size(); j++){
                    sum = (i>0)? prefix[j] - prefix[i-1] : prefix[j];
                    if (sum == target){
                        res.push_back(i+1);
                        res.push_back(j+1);
                        return res;
                    }
                    sum = 0;
                }
            }
            res.push_back(-1);
            return res;
            
}


int main() {
    vector<int> v;
    int n, key;
    cin >> n;  
    v.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i]; 
    cout<<kadaneAlgorithm(v)<<endl;

    return 0;
}
