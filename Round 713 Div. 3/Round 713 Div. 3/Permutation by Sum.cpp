#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <string>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vb = vector<bool>;
using vc = vector<char>;
using pii = pair<int, int>;
using vpii = vector<pii>;

#define FORI(i, a, b, p) for (int i = a; i < b; i += p)
#define FOR(i, a, b) FORI(i, a, b, 1)
#define F0R(i,b) FOR(i, 0, b)
#define RFOR(i, a, b) for (int i = a; i >= b; i--)
#define RF0R(i, a) RFOR(i, a, 0)

#define MOD 1

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int t;

int main() {
	cin >> t;
	while (t--) {
		int n, l, r, s;
		cin >> n >> l >> r >> s;
		vector<int> nums;
		vector<bool> visited(n + 1, false);
		for (int i = n; i >= 1; i--) {
			if (i <= s) {
				s -= i;
				visited[i] = true;
				nums.push_back(i);
			}
		}
		while (nums.size() < r - l + 1) {
			s += nums[0];
			for (int i = nums[0] - 1; i >= 1; i--) {
				if (!visited[i] && i <= s) {
					s -= i;
					visited[i] = true;
					nums.push_back(i);
				}
			}
			visited[nums[0]] = false;
			nums.erase(nums.begin());
		}
		while (nums.size() > r - l + 1) {

		}
	}
}