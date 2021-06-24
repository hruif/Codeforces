#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <string>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>

using namespace std;
using ll = long long;
using str = string;

using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vb = vector<bool>;
using vc = vector<char>;
using vstr = vector<string>;
using pii = pair<int, int>;
using vpii = vector<pii>;

#define sz(x) (int)(x.size())
#define rsz resize
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend() 
#define pb push_back
#define eb emplace_back

#define lb lower_bound
#define ub upper_bound

// for loops
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define F0R(i,b) FOR(i, 0, b)
#define F0R2(i, j, a, b) F0R(i, a) F0R(j, b)
#define RFOR(i, a, b) for (int i = a - 1; i >= b; i--)
#define RF0R(i, a) RFOR(i, a, 0)

#define MOD 1

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int n;
vector<str> nums;
map<str, int> m;

int main() {
	cin >> n;
	nums.rsz(n);
	F0R(i, n) {
		cin >> nums[i];
	}
	F0R(i, n) {
		set<str> s;
		F0R(j, 9) {
			FOR(k, 1, 10 - j) s.insert(nums[i].substr(j, k));
		}
		for (auto i : s) {
			m[i]++;
		}
	}
	F0R(i, n) {
		bool found = false;
		FOR(k, 1, 10) {
			F0R(j, 10 - k) {
				if (m[nums[i].substr(j, k)] == 1) {
					cout << nums[i].substr(j, k) << '\n';
					found = true;
					break;
				}
			}
			if (found) break;
		}
		
	}
}