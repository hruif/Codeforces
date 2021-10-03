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
#include <iomanip>
#include <climits>

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
#define F0R(i, b) FOR(i, 0, b)
#define F1R(i, b) FOR(i, 1, b)
#define F0R2(i, j, a, b) F0R(i, a) F0R(j, b)
#define RFOR(i, a, b) for (int i = a - 1; i >= b; i--)
#define RF0R(i, a) RFOR(i, a, 0)

#define MOD 998244353

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int t;
int w[100000];

int main() {
	cin >> t;
	while (t--) {
		int n, W;
		cin >> n >> W;
		F0R(i, n) cin >> w[i];
		vi rect(1, W);
		sort(w, w + n);
		int h = 0;
		vpii nums;
		nums.push_back({ w[n - 1], 1 });
		RF0R(i, n - 1) {
			if (w[i + 1] == w[i]) {
				nums.back().second++;
			}
			else {
				nums.push_back({ w[i], 1 });
			}
		}
		bool done = false;
		while (!done) {
			done = true;
			F0R(i, sz(nums)) {
				if (nums[i].second > 0 && nums[i].first <= rect[0]) {
					done = false;
					int removed = min(nums[i].second, rect[0] / nums[i].first);
					rect[0] -= nums[i].first * removed;
					nums[i].second -= removed;
				}
			}
			rect[0] = W;
			if (!done) h++;
		}
		cout << h << '\n';
	}
}