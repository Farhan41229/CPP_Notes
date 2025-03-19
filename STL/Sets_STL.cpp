#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define YES cout<<"YES"<<endl;
#define NO cout<<"NO"<<endl;

void process_case() {
    int n;
    cin >> n;

    if (n % 2 == 0 && n > 2) cout<<"YES"<<endl;
    else cout<<"NO"<<endl; 
   
}

int main() {
    ios::sync_with_stdio(false);
#ifndef FARHAN_TAHSIN
    cin.tie(nullptr);
#endif

    int test_cases = 1;
    // cin >> test_cases;

    while (test_cases-- > 0)
        process_case();
}