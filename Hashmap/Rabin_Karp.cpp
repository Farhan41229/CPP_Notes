#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define YES cout<<"YES"<<endl;
#define NO cout<<"NO"<<endl;
#define d 10

void rabinKarp(char pattern[], char text[], int q) {
  int m = strlen(pattern);
  int n = strlen(text);
  int i, j;
  int p = 0;
  int t = 0;
  int h = 1;

  for (i = 0; i < m - 1; i++)
    h = (h * d) % q;

  // Calculate hash value for pattern and text
  for (i = 0; i < m; i++) {
    p = (d * p + pattern[i]) % q;
    t = (d * t + text[i]) % q;
  }

  // Find the match
  for (i = 0; i <= n - m; i++) {
    if (p == t) {
      for (j = 0; j < m; j++) {
        if (text[i + j] != pattern[j])
          break;
      }

      if (j == m)
        cout << "Pattern is found at position: " << i + 1 << endl;
    }

    if (i < n - m) {
      t = (d * (t - text[i] * h) + text[i + m]) % q;

      if (t < 0)
        t = (t + q);
    }
  }
}

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