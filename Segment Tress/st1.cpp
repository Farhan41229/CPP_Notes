// This is the implementation of the segment Trees based on the Udemy Course Competitive Programming Essentials, Master Algorithms. This code
// contains most of the necessary implementation of the segment tree... */

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
using grid = vector<vi>;
#define YES cout<<"YES"<<endl;
#define NO cout<<"NO"<<endl;
//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, 
                         tree_order_statistics_node_update>; 
#define en "\n"
#define ln " \n"[i==n-1]
#define sz(_O) _O.size()
#define fix(_O) cout<<setprecision(_O)<<fixed
#define fir(_O) for(int i=0, ii=_O-1; i<_O; ++i, --ii)
#define fjr(_O) for(int j=0, jj=_O-1; j<_O; ++j, --jj)
ll const inf = 1e18; //0x3f3f3f3f3f3f;
ll const mod = 1e9+7; //998244353;

struct segmenttree {
	int n;
	vector<int> st;

	void init(int _n) {
		this->n = _n;
		st.resize(4 * n, 0);
	}

	void build(int start, int ending, int node, vector<int> &v) {
		// leaf node base case
		if (start == ending) {
			st[node] = v[start];
			return;
		}

		int mid = (start + ending) / 2;

		// left subtree is (start,mid)
		build(start, mid, 2 * node + 1, v);

		// right subtree is (mid+1,ending)
		build(mid + 1, ending, 2 * node + 2, v);

		st[node] = st[node * 2 + 1] + st[node * 2 + 2];
	}

	int query(int start, int ending, int l, int r, int node) {
		// non overlapping case
		if (start > r || ending < l) {
			return 0;
		}

		// complete overlap
		if (start >= l && ending <= r) {
			return st[node];
		}

		// partial case
		int mid = (start + ending) / 2;

		int q1 = query(start, mid, l, r, 2 * node + 1);
		int q2 = query(mid + 1, ending, l, r, 2 * node + 2);

		return q1 + q2;
	}

	void update(int start, int ending, int node, int index, int value) {
		// base case
		if (start == ending) {
			st[node] = value;
			return;
		}

		int mid = (start + ending) / 2;
		if (index <= mid) {
			// left subtree
			update(start, mid, 2 * node + 1, index, value);
		}
		else {
			// right
			update(mid + 1, ending, 2 * node + 2, index, value);
		}

		st[node] = st[node * 2 + 1] + st[node * 2 + 2];

		return;
	}

	void build(vector<int> &v) {
		build(0, n - 1, 0, v);
	}

	int query(int l, int r) {
		return query(0, n - 1, l, r, 0);
	}

	void update(int x, int y) {
		update(0, n - 1, 0, x, y);
	}
    void print_tree() {
        int level = 0, nodes_in_level = 1, index = 0;
        int max_width = 4 * n;  // Maximum possible nodes in the segment tree

        cout << "Segment Tree Structure:\n";

        while (index < 4 * n) {
            int spaces = max_width / (nodes_in_level + 1);  // Adjust spacing per level

            for (int i = 0; i < nodes_in_level && index < 4 * n; ++i, ++index) {
                cout << string(spaces, ' ');  // Print leading spaces
                if (st[index] != 0) cout << st[index];
                else cout << "_";
            }
            cout << "\n";
            nodes_in_level *= 2;  // Move to the next level
        }
    }


};
 
void process_case() {
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
    segmenttree tree;
    tree.init(v.size());
    tree.build(v);
    tree.print_tree();
   
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


